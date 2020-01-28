// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2002 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//
//	File:
//		PIUActionUtils.cpp
//
//	Description:
//		Utility routines for getting information out of descriptors.
//		This is the heart of the Listener debug version PIUDumpDescriptor.
//
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//	Includes
//-------------------------------------------------------------------------------
#include "PIUActionUtils.h"
#include <sstream>
#include <iomanip>

#ifdef _DEBUG
	#include "PSConstantArray.cpp"
#endif

#if __PIMac__
#define strcpy_s(a,b,c) strlcpy(a,c,b)
#endif

//-------------------------------------------------------------------------------
//	Classes
//-------------------------------------------------------------------------------
// Handy class for the listener debug output
// Keeps track of objects that need to be freed
class FreeZone {
public:
	FreeZone();
	~FreeZone();

	void Add(PIActionReference);
	void Add(PIActionList);
	void Add(PIActionDescriptor);
	void Add(Handle);
	void Add(CFDataRef);
	void Output(ofstream&);
	
private:
	void Add(const char* text, intptr_t value);
	vector<char*> v_array;
};



//-------------------------------------------------------------------------------
//	Locals
//-------------------------------------------------------------------------------
// Local variables so the output file looks nicer
static int16 tabLevel;
const char* ecs = "if (error) goto returnError;\n\n";
// Local variable that keeps track of things I need to free
FreeZone * freeZone = NULL;

#define maxHashStringSize 1024



//-------------------------------------------------------------------------------
//	Local functions
//-------------------------------------------------------------------------------
// Local function definitions
static void DumpInfoFromReference(PIActionReference inputRef, ofstream& fileOut);
static void DumpInfoFromList(const PIActionList inputList, ofstream& fileOut);
static void DumpInfoFromDescriptor(const PIActionDescriptor inputDesc, ofstream& fileOut);
static void TabOver(ofstream & fileOut);
static void LongToStr(int32 inputLong, const char* inputKeyType, char* returnString, int32 maxStringSize);
static unsigned long StrToLong(const char* inputStr);
static void PIUIDToChar(const unsigned long inType, char* outChars);



//-------------------------------------------------------------------------------
//
//	UnitsToPixels
//
//	Given a value, units and resolution. Convert to number of pixels
//
//-------------------------------------------------------------------------------
double UnitsToPixels(double value, int units, double resolution)
{
	double newvalue = value;

	switch (units)
	{
		case unitDistance:
			newvalue = value * resolution / 72.0;
			break;
		case unitPixels:
			newvalue = value;
			break;
		case unitPercent:
		case unitNone:
		case unitAngle:
		case unitDensity:
		default:
			break;
	}
	return newvalue;
}



//-------------------------------------------------------------------------------
//
//	PixelsToUnits
//
//	Given a value, units and resolution. Convert pixels into units.
//
//-------------------------------------------------------------------------------
double PixelsToUnits(double value, int units, double resolution)
{
	double newvalue = 0.0;

	switch (units)
	{
		case unitDistance:
			if (resolution)
				newvalue = value * 72.0 / resolution;
			break;
		case unitPixels:
			newvalue = value;
			break;
		case unitPercent:
		case unitNone:
		case unitAngle:
		case unitDensity:
		default:
			break;
	}
	return newvalue;
}



//-------------------------------------------------------------------------------
//
//	PIUCheckPlayResult
//
//	Check the descriptor and see if it was a good Play(). 
//
//	NOTE:
//	Some Play() commands are not expected to return a valid result desciptor.
//
//-------------------------------------------------------------------------------
SPErr PIUCheckPlayResult(PIActionDescriptor result)
{
	SPErr error = kSPNoError;
	Boolean hasKey = false;

	if (result == NULL)
	{
		error = -1;
	}
	else
	{
		error = sPSActionDescriptor->HasKey(result, keyMessage, &hasKey);
		if (hasKey)
		{
			error = -1;
		}
	}
	return error;
}



//-------------------------------------------------------------------------------
//
//	PIUDumpDescriptor
//
//	Goes through everything in the result descriptor and dumps it and its
//	type. Has recursive functions that can get descriptors out of descriptors,
//	lists out of descriptors, descriptors out of lists, 
//	and all other combinations.
//
//-------------------------------------------------------------------------------
void PIUDumpDescriptor(const DescriptorEventID event,	
					   const PIActionDescriptor result, 
					   const char* fullpathtofile)
{

// You probably don't want the overhead of this routine in your
// non-debug code, so I'll define this and its strings only for
// a debug build:
#ifdef _DEBUG

    // I need all of these and they actually throw if not acquired
    // lets return instead
	if ( ! (sPSActionDescriptor.IsAvailable() &&
	        sPSActionList.IsAvailable() &&
	        sPSActionReference.IsAvailable() &&
	        sPSActionControl.IsAvailable()))
	    return;
	
	freeZone = new FreeZone;
	if (freeZone == NULL)	
		return;

	char* eventIDAsString = new char[maxHashStringSize];// the string name of the event
	if (eventIDAsString == NULL) 
		return;

	tabLevel = 0;    // indentation of the output strings

	// Create the output file and append to whatever is there
	#if __PIMac__
		ofstream fileOut(fullpathtofile, ios_base::app|ios_base::out);
	#else
		// j systems have trouble opening the file with Shift-JIS chars
		// use this trick
		FILE * fd = fopen(fullpathtofile, "a");
		ofstream fileOut(fd);
	#endif
    
    
	// Get the event define name for this event
	LongToStr(event, "event", eventIDAsString, maxHashStringSize);

	// Wrap each event into a function call with the event as the
	// function name
	fileOut << "SPErr Play" << eventIDAsString << "(/*your parameters go here*/void)" << endl;
	fileOut << "{" << endl;

	// Set the tab level over one for clarity
	tabLevel++;
	TabOver(fileOut);

	// Create a variable for the "Play" result
	fileOut << "PIActionDescriptor result = NULL;" << endl;

	// Create variables to hold all of the possible runtime ID(s)
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimeKeyID;" << endl;
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimeTypeID;" << endl;
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimeObjID;" << endl;
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimeEnumID;" << endl;
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimeClassID;" << endl;
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimePropID;" << endl;
	TabOver(fileOut);
	fileOut << "DescriptorTypeID runtimeUnitID;" << endl;
	TabOver(fileOut);
	fileOut << "SPErr error = kSPNoError;" << endl;

	// Main recursive routine for pulling apart a descriptor
	DumpInfoFromDescriptor(result, fileOut);

	// Check to see if this is a 'Hash' type of event or a unique ID 
	// string. If it is a unique ID string then you have to get the 
	// runtime ID for that event and play.
	if (event < SmallestHashValue)
	{
		// Format the output
		TabOver(fileOut);
		fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
				<< eventIDAsString << "\", &runtimeEventID);" << endl;
		TabOver(fileOut);
		fileOut << ecs;

		// Update for the "Play" string
		strcpy_s(eventIDAsString, maxHashStringSize-1, "runtimeEventID");
	}

	// Format the "Play" call to the log file
	TabOver(fileOut);
	if (result)
		fileOut << "error = sPSActionControl->Play(&result, " 
				<< eventIDAsString << ", desc" << result 
				<< ", plugInDialogSilent);" << endl;
	else
		fileOut << "error = sPSActionControl->Play(&result, " 
				<< eventIDAsString << ", NULL, plugInDialogSilent);" << endl;

	TabOver(fileOut);
	fileOut << ecs;

	fileOut << "returnError:" << endl;

	TabOver(fileOut);
	fileOut << "if (result != NULL) sPSActionDescriptor->Free(result);" << endl;

	freeZone->Output(fileOut);

	// Finish off the function call
	TabOver(fileOut);
	fileOut << "return error;" << endl;

	fileOut << "}" << endl << endl;

	delete [] eventIDAsString;
	delete freeZone;

	#if __PIWin__
		if ( NULL != fd )
		{
			fclose( fd );
		}
	#endif

#endif // _DEBUG
} // end DumpDescriptor


	
//-------------------------------------------------------------------------------
//
//	DumpInfoFromReference
//
//	Goes through the reference and dumps it and its	type. The while loop takes
//	care of containers in the reference.
//
//-------------------------------------------------------------------------------
static void DumpInfoFromReference(PIActionReference  inputRef, ofstream & fileOut)
{

	// You probably don't want the overhead of this routine in your
	// non-debug code, so I'll define this and its strings only for
	// a debug build:
	#ifdef _DEBUG

	PIActionReference containerRef = NULL;
	const char* sar = "error = sPSActionReference->";

	// If their is no reference, don't bother.
	if (inputRef == NULL) 
		return;

    std::ostringstream refStream;
    refStream << std::setw(sizeof(void*) * 2) << std::hex << std::setfill('0') << (intptr_t)inputRef;

	// Create a new reference item
	TabOver(fileOut);
	fileOut << "// Move this to the top of the routine!" << endl;

	TabOver(fileOut);
	fileOut << "PIActionReference ref" << refStream.str() << " = NULL;" << endl;

	// The making of this reference
	TabOver(fileOut);
	fileOut << sar << "Make(&ref" << refStream.str() << ");" << endl;
	TabOver(fileOut);
	fileOut << ecs;

	freeZone->Add(inputRef);

	// As long as their is a valid reference keep going.
	// Reference's can have container's which are more pieces to the reference.

	// They look like another reference but are actually part of the same reference.
	// So keep track of the original reference number here and use it always below.
	PIActionReference originalRef = inputRef;

    std::ostringstream originalRefStream;
    originalRefStream << std::setw(sizeof(void*) * 2) << std::hex << std::setfill('0') << (intptr_t)originalRef;

    // Photoshop has an issue. If you have a multilayerd document and do a search
	// via the layers panel for layers with a certain name, and the name you are
	// searching doesn't exist then no layers are selected after you remove the
	// search. This comes in as a reference that is not valid. I'll add error
	// checks!
	OSErr error = 0;

	char * desiredClassStr = NULL;

	while (inputRef && ! error)
	{

		// Get the form type for this reference.
		DescriptorFormID	formType;
		error = sPSActionReference->GetForm(inputRef, &formType);
		if (error) 
		{
			TabOver(fileOut);
			fileOut << "ERROR: DumpInfoFromReferene on GetForm = " 
					<< error << endl;
			continue;
		}

		// What class is in the reference
		DescriptorClassID	desiredClass;
		error = sPSActionReference->GetDesiredClass(inputRef, &desiredClass);
		if (error) 
		{
			TabOver(fileOut);
			fileOut << "ERROR: DumpInfoFromReferene on GetDesiredClass = " 
					<< error << endl;
			continue;
		}

		// Convert the class 'Hash' to the string for output later, "classHash"
		if (desiredClassStr != NULL)
		{
			delete [] desiredClassStr;
			desiredClassStr = NULL;
		}

		desiredClassStr = new char[maxHashStringSize];
		if (desiredClassStr == NULL) 
			return;

		LongToStr(desiredClass, "class", desiredClassStr, maxHashStringSize); 
		
		if (desiredClass < SmallestHashValue)
		{
			// Format the output
			TabOver(fileOut);
			fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
					<< desiredClassStr << "\", &runtimeClassID);" << endl;
			TabOver(fileOut);
			fileOut << ecs;
			
			strcpy_s(desiredClassStr, maxHashStringSize-1, "runtimeClassID");
		}
		
		// Pull the next bit of information out based on the type
		switch(formType)
		{
			case formName:
				// Get some local variables
				uint32 nameLength;
				char* nameString;
				size_t actualLength;

				// See how long this string is
				error = sPSActionReference->GetNameLength(inputRef, &nameLength);
				if (error) 
				{
					TabOver(fileOut);
					fileOut << "ERROR: DumpInfoFromReferene on GetNameLength = " 
							<< error << endl;
					continue;
				}
				
				// Make some room
				actualLength = ++nameLength; // make room for the null termination
				nameString = new char[actualLength];
				if (nameString == NULL) 
					return;

				if ((actualLength == nameLength) && nameString)
				{
					// Pull the name out of the reference
					error = sPSActionReference->GetName(inputRef, nameString, nameLength);
					if (error) 
					{
						TabOver(fileOut);
						fileOut << "ERROR: DumpInfoFromReferene on GetName = " 
							<< error << endl;
						delete [] nameString;
						continue;
					}

					// Format the output
					TabOver(fileOut);
					fileOut << sar << "PutName(ref" << originalRefStream.str() << ", " 
							<< desiredClassStr << ", \"" << nameString 
							<< "\");" << endl;
				}
				else
				{
					// Report the error in the file
					TabOver(fileOut);
					fileOut << "ERROR: " << sar << "PutName" << endl;
				}

				delete [] nameString;
				break;

			case formIndex:
				// Get some local variables
				uint32 indexValue;

				// Pull the index out of the reference
				error = sPSActionReference->GetIndex(inputRef, &indexValue);
				if (error) 
				{
					TabOver(fileOut);
					fileOut << "ERROR: DumpInfoFromReferene on GetIndex = " 
						<< error << endl;
					continue;
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sar << "PutIndex(ref" << originalRefStream.str() << ", " 
						<< desiredClassStr << ", " << indexValue << ");" << endl;
				break;
			
			case formClass:
			{
				// Get some local variable
				DescriptorClassID	classValue;

				// Get the desired class out of the reference
				error = sPSActionReference->GetDesiredClass(inputRef, &classValue);
				if (error) 
				{
					TabOver(fileOut);
					fileOut << "ERROR: DumpInfoFromReferene on GetDesiredClass = " 
						<< error << endl;
					continue;
				}

				char* cvString = new char[maxHashStringSize];
				if (cvString == NULL) 
					return;

				// Convert the 'Hash' to a "hashString"
				LongToStr(classValue, "class", cvString, maxHashStringSize);

				if (classValue < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< cvString << "\", &runtimeClassID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(cvString, maxHashStringSize-1, "runtimeClassID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << sar << "PutClass(ref" << originalRefStream.str() << ", " 
						<< cvString << ");" << endl;

				delete [] cvString;
				break;
			}

			case formEnumerated:
				// Get some local variable
				DescriptorEnumTypeID enumTypeID;
				DescriptorEnumID	 enumID;

				// Get the enumeration and it's type out
				error = sPSActionReference->GetEnumerated(inputRef, &enumTypeID, &enumID);
				if (error) 
				{
					TabOver(fileOut);
					fileOut << "ERROR: DumpInfoFromReferene on GetEnumerated = " 
						<< error << endl;
					continue;
				}

				char* enumTypeIDStr;
				enumTypeIDStr = new char[maxHashStringSize];
				if (enumTypeIDStr == NULL) 
					return;
				char* enumIDStr;
				enumIDStr = new char[maxHashStringSize];
				if (enumIDStr == NULL) 
					return;

				// Convert the 'Hash' to a "hashString"
				LongToStr(enumTypeID, "type", enumTypeIDStr, maxHashStringSize);

				if (enumTypeID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< enumTypeIDStr << "\", &runtimeTypeID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(enumTypeIDStr, maxHashStringSize-1, "runtimeTypeID");
				}
		
				LongToStr(enumID, "enum", enumIDStr, maxHashStringSize);

				if (enumID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< enumIDStr << "\", &runtimeEnumID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(enumIDStr, maxHashStringSize-1, "runtimeEnumID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << sar << "PutEnumerated(ref" << originalRefStream.str() << ", " 
						<< desiredClassStr << ", " << enumTypeIDStr << ", " 
						<< enumIDStr << ");" << endl;
				delete [] enumIDStr;
				delete [] enumTypeIDStr;
				break;
			
			case formProperty:
				// Get some local variable
				DescriptorKeyID	propID;

				// Pull the information
				error = sPSActionReference->GetProperty(inputRef, &propID);
				if (error) 
				{
					TabOver(fileOut);
					fileOut << "ERROR: DumpInfoFromReferene on GetProperty = " 
						<< error << endl;
					continue;
				}

				char* propIDStr;
				propIDStr = new char[maxHashStringSize];
				if (propIDStr == NULL) 
					return;

				LongToStr(propID, "key", propIDStr, maxHashStringSize);
					
				if (propID < SmallestHashValue)
				{
					//Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< propIDStr << "\", &runtimePropID);" << endl;

					TabOver(fileOut);
					fileOut << ecs;

					// Update for the string
					strcpy_s(propIDStr, maxHashStringSize-1, "runtimePropID");					
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sar << "PutProperty(ref" << originalRefStream.str() << ", " 
						<< desiredClassStr << ", " << propIDStr << ");" << endl;

				delete [] propIDStr;
				break;
			
			case formIdentifier:
				// Get some local variable
				uint32 identifierID;

				error = sPSActionReference->GetIdentifier(inputRef, &identifierID);
				if (error) 
				{
					TabOver(fileOut);
					fileOut << "ERROR: DumpInfoFromReferene on GetIdentifier = " 
						<< error << endl;
					continue;
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sar << "PutIdentifier(ref" << originalRefStream.str() << ", " 
						<< desiredClassStr << ", " << identifierID << ");" << endl;
				break;
			
			case formOffset:
				// Get some local variable
				int32 offset;

				// Pull the info
				sPSActionReference->GetOffset(inputRef, &offset);
				
				// Format the output
				TabOver(fileOut);
				fileOut << sar << "PutOffset(ref" << originalRefStream.str() << ", " 
					<< desiredClassStr << ", " << offset << ");" << endl;
				break;
			
			default:
				// Better not ever, never get into here
				// Get some local variable
				char* formTypeStr;
				formTypeStr = new char[maxHashStringSize];
				if (formTypeStr == NULL) 
					return;

				// Convert the 'Hash' to a "hashString"
				LongToStr(formType, "form", formTypeStr, maxHashStringSize);

				if (formType < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< formTypeStr << "\", &runtimeTypeID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(formTypeStr, maxHashStringSize-1, "runtimeTypeID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << "ERROR: DumpInfoFromReferene on formID = " 
					<< formTypeStr << endl;
				delete [] formTypeStr;
				break;
			
		} // end switch on formType
		
		TabOver(fileOut);
		fileOut << ecs;

		// make sure you free the ref value in case this is the second time through the loop
		if (containerRef != NULL)
		{
			sPSActionReference->Free(containerRef);
			containerRef = NULL;
		}

		// see if this reference has a container reference to pull apart
		error = sPSActionReference->GetContainer(inputRef, &containerRef);

		// it could either err or have a refVale of NULL which is like an error
		if ( ! error && containerRef != NULL)
			// Update the inputRef and let the while loop continue
			inputRef = containerRef;
		else
			// Update the inputRef and stop the while loop
			inputRef = NULL;

	} // end while

	if (desiredClassStr != NULL)
	{
		delete [] desiredClassStr;
		desiredClassStr = NULL;
	}

	#endif // _DEBUG

}// end DumpInfoFromReference
	


//-------------------------------------------------------------------------------
//
//	DumpInfoFromList
//
//	Goes through the list and dumps it and its types. Has recursive functions
//  that can get descriptors out of descriptors and other combinations.
//
//-------------------------------------------------------------------------------
static void DumpInfoFromList(const PIActionList inputList,
							 ofstream & fileOut)
{

	// You probably don't want the overhead of this routine in your
	// non-debug code, so I'll define this and its strings only for
	// a debug build:
	#ifdef _DEBUG

	const char* sal = "error = sPSActionList->";
	
	// If no list then no go.
	if (inputList == NULL)
		return;
		
	// Get the number of items in this list, return on error
	uint32 listCount = 0;
	uint32 counter = 0;
	if (sPSActionList->GetCount(inputList, &listCount))
		return;

    std::ostringstream listStream;
    listStream << std::setw(sizeof(void*) * 2) << std::hex << std::setfill('0') << (intptr_t)inputList;
    
	// Format the output
	TabOver(fileOut);
	fileOut << "// Move this to the top of the routine!" << endl;

	TabOver(fileOut);
	fileOut << "PIActionList list" << listStream.str() << " = NULL;" << endl;

	TabOver(fileOut);
	fileOut << sal << "Make(&list" << listStream.str() << ");" << endl;

	TabOver(fileOut);
	fileOut << ecs;

	freeZone->Add(inputList);

	// Loop throught until all the items are pulled out
	while (counter < listCount)
	{
		DescriptorTypeID typeID;

		// Get the type information for this list item
		sPSActionList->GetType(inputList, counter, &typeID);

		// Pull the next bit of information out based on the type
		switch (typeID)
		{
			case typeSInt64:
				int64 int64Value;

				sPSActionList->GetInteger64(inputList, counter, &int64Value);
				
				TabOver(fileOut);
				fileOut << sal << "PutInteger64(list" << listStream.str() << ", "
					<< int64Value << ");" << endl;
				break;
				
			case typeSInt32: /* was typeInteger: */
				// Get some local data
				int32	intValue;

				// Pull the info
				sPSActionList->GetInteger(inputList, counter, &intValue);

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutInteger(list" << listStream.str() << ", " 
					<< intValue << ");" << endl;
				break;

			case typeIEEE64BitFloatingPoint: /* was typeFloat: */
				// Get some local data
				double	doubleValue;

				// Pull the info
				sPSActionList->GetFloat(inputList, counter, &doubleValue);

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutFloat(list" << listStream.str() << ", " 
					<< doubleValue << ");" << endl;
				break;

			case typeUnitFloat:
				// Get some local data
				double	unitDoubleValue;
				DescriptorUnitID unitID;
				char* unitIDStr;
				unitIDStr = new char[maxHashStringSize];
				if (unitIDStr == NULL) 
					return;

				// Pull the info
				sPSActionList->GetUnitFloat(inputList, 
					                        counter, 
											&unitID, 
											&unitDoubleValue);

				// Convert the 'Hash' to a "hashString"
				LongToStr(unitID, "unit", unitIDStr, maxHashStringSize);

				if (unitID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< unitIDStr << "\", &runtimeUnitID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(unitIDStr, maxHashStringSize-1, "runtimeUnitID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutUnitFloat(list" << listStream.str() << ", " 
					<< unitIDStr << ", " << unitDoubleValue << ");" << endl;
				delete [] unitIDStr;
				break;

			case typeChar:
				{
				// Get some local data
				ASZString zString;
				sPSActionList->GetZString(inputList, counter, &zString);
				ASUInt32 unicodeLength = sASZString->LengthAsUnicodeCString(zString);
				ASUnicode * unicodeStr = new ASUnicode[unicodeLength + 1];
				sASZString->AsUnicodeCString(zString, unicodeStr, unicodeLength, false);
				
				char * multiByteStr = NULL;
				int multiByteLength = 0;
				bool conversionOK = false;
					
				#if __PIMac__
					CFStringRef stringRef = CFStringCreateWithCharacters(NULL, unicodeStr, unicodeLength + 1);
					// where is the routine to figure out how long this thing is going to be?
					// make it three times longer than the unicode string ???
					multiByteLength = ( unicodeLength + 1 ) * 3;
					multiByteStr = new char[multiByteLength];
					if ( CFStringGetCString(stringRef, multiByteStr, multiByteLength, kCFStringEncodingUTF8))
					{
						conversionOK = true;
					}

				#else
					multiByteLength = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)unicodeStr, unicodeLength,
														  NULL, 0, NULL, NULL);
					if (multiByteLength > 0)
					{
						multiByteStr = new char[multiByteLength];
						if ( WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)unicodeStr, unicodeLength,
												  multiByteStr, multiByteLength, NULL, NULL) )
						{
							conversionOK = true;
						}
					}
				#endif			
				
				if ( conversionOK )
				{
					TabOver(fileOut);
					fileOut << "// Unicode String as UTF8: " << multiByteStr << endl;
				}
				
				delete [] multiByteStr;
				delete [] unicodeStr;

				uint32 charLen;
				char* charValue;
				size_t actualLength;

				// Pull the info
				sPSActionList->GetStringLength(inputList, counter, &charLen);

				// Make some room
				actualLength = ++charLen; // make room for the null termination
				charValue = new char[actualLength];
				if (charValue == NULL) 
					return;

				if ((actualLength == charLen) && charValue)
				{
					sPSActionList->GetString(inputList, 
										     counter, 
											 charValue, 
											 (uint32)actualLength);

					// Format the output
					TabOver(fileOut);
					fileOut << sal << "PutString(list" << listStream.str() << ", \"" 
						<< charValue << "\");" << endl;
				}
				else
				{
					TabOver(fileOut);
					fileOut << "ERROR: " << sal << "PutString" << endl;
				}

				delete [] charValue;
				break;
				}
			case typeBoolean:
				// Get some local data
				Boolean boolValue;

				// Pull the info
				sPSActionList->GetBoolean(inputList, counter, &boolValue);

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutBoolean(list" << listStream.str() << ", " 
					<< (boolValue ? "true" : "false") << ");" << endl;
				break;

			case typeObject:
				// Get some local data
				DescriptorClassID objClassID;
				char* objClassIDStr;
				objClassIDStr = new char[maxHashStringSize];
				if (objClassIDStr == NULL) 
					return;
				PIActionDescriptor objDesc;
				objDesc = NULL;

				// Pull the info
				sPSActionList->GetObject(inputList, counter, &objClassID, &objDesc);

				// Convert the 'Hash' to a "hashString"
				LongToStr(objClassID, "class", objClassIDStr, maxHashStringSize);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the objDesc
				tabLevel++;
				DumpInfoFromDescriptor(objDesc, fileOut);
				tabLevel--;

				// Check to see if this is a 'Hash' type of event or a unique ID 
				// string. If it is a unique ID string then you have to get the 
				// runtime ID for that event and play.
				if (objClassID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< objClassIDStr << "\", &runtimeClassID);" << endl;

					// Update for the string
					strcpy_s(objClassIDStr, maxHashStringSize-1, "runtimeClassID");

					TabOver(fileOut);
					fileOut << ecs;
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutObject(list" << listStream.str() << ", " 
					<< objClassIDStr << ", desc" << objDesc << ");" << endl;

				if (objDesc != NULL) 
					sPSActionDescriptor->Free(objDesc);

				delete [] objClassIDStr;

				break;

			case typeGlobalObject:
				// Get some local data
				DescriptorClassID globObjClassID;
				char* globObjClassIDStr;
				globObjClassIDStr = new char[maxHashStringSize];
				if (globObjClassIDStr == NULL) 
					return;
				PIActionDescriptor globObjDesc;
				globObjDesc = NULL;

				// Pull the info
				sPSActionList->GetGlobalObject(inputList, 
											   counter, 
											   &globObjClassID, 
											   &globObjDesc);

				// Convert the 'Hash' to a "hashString"
				LongToStr(globObjClassID, "class", globObjClassIDStr, maxHashStringSize);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the globOsbjDesc
				tabLevel++;
				DumpInfoFromDescriptor(globObjDesc, fileOut);
				tabLevel--;

				// Check to see if this is a 'Hash' type of event or a unique ID 
				// string. If it is a unique ID string then you have to get the 
				// runtime ID for that event and play.
				if (globObjClassID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< globObjClassIDStr << "\", &runtimeClassID);" << endl;

					// Update for the string
					strcpy_s(globObjClassIDStr, maxHashStringSize-1, "runtimeClassID");
					
					TabOver(fileOut);
					fileOut << ecs;
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutGlobalObject(list" << listStream.str() << ", " 
					<< globObjClassIDStr << ", desc" << globObjDesc << ");" 
					<< endl;

				if (globObjDesc != NULL) 
					sPSActionDescriptor->Free(globObjDesc);

				delete [] globObjClassIDStr;
				break;

			case 'enum'://typeEnumerated:
				// Get some local data
				DescriptorEnumTypeID	enumType;
				DescriptorEnumID enumValue;
				char* enumTypeStr;
				enumTypeStr = new char[maxHashStringSize];
				if (enumTypeStr == NULL) 
					return;
				char* enumValueStr;
				enumValueStr = new char[maxHashStringSize];
				if (enumValueStr == NULL) 
					return;

				// Pull the info
				sPSActionList->GetEnumerated(
					inputList, 
					counter, 
					&enumType, 
					&enumValue);

				// Convert the 'Hash' to a "hashString"
				LongToStr(enumValue, "enum", enumValueStr, maxHashStringSize);

				if (enumValue < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< enumValueStr << "\", &runtimeEnumID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(enumValueStr, maxHashStringSize-1, "runtimeEnumID");
				}
		
				LongToStr(enumType, "type", enumTypeStr, maxHashStringSize);

				if (enumType < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< enumTypeStr << "\", &runtimeTypeID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(enumTypeStr, maxHashStringSize-1, "runtimeTypeID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutEnumerated(list" << listStream.str() << ", " 
					<< enumTypeStr << ", " << enumValueStr << ");" << endl;

				delete [] enumValueStr;
				delete [] enumTypeStr;
				break;

			case typePath:
			case typeAlias:
				{
				// Get some local data
				Handle aliasValue = NULL;
				char* fullPath = new char[BigStrMaxLen*2];
				if (fullPath == NULL) 
					return;
				
				// Pull the info
				sPSActionList->GetAlias(inputList, counter, &aliasValue);
				
				// Get the information out of the Handle
				// On Windows it's a char**, on Mac it's a mess
				if (fullPath != NULL)
					AliasToFullPath(aliasValue, fullPath, BigStrMaxLen*2);

				// Format the output
				TabOver(fileOut);
				fileOut << "// Move this to the top of the routine!" << endl;
				TabOver(fileOut);
				fileOut << "Handle aliasValue = NULL;" << endl;

				TabOver(fileOut);
				fileOut << "FullPathToAlias(\"" << fullPath << "\", aliasValue);" 
					    << endl;
				TabOver(fileOut);
				fileOut << sal << "PutAlias(list" << listStream.str() 
					<< ", aliasValue);" << endl;

				freeZone->Add(aliasValue);

				sPSHandle->DisposeRegularHandle(aliasValue);

				// use the new bookmark for Mac, should error for Windows
				CFDataRef bookmarkValue;
				OSErr error = sPSActionList->GetBookmark(inputList, counter, &bookmarkValue);

				#if __PIMac__

				// Get the information out of the bookmark
				if (bookmarkValue != NULL && error == noErr)
                {
					BookmarkToFullPath(bookmarkValue, fullPath, BigStrMaxLen*2);

                    // Format the output
                    TabOver(fileOut);
                    fileOut << "// Move this to the top of the routine!" << endl;
                    TabOver(fileOut);
                    fileOut << "CFDataRef bookmarkValue = NULL;" << endl;

                    TabOver(fileOut);
                    fileOut << "FullPathToBookmark(\"" << fullPath << "\", bookmarkValue);"
                            << endl;
                    TabOver(fileOut);
                    fileOut << sal << "PutBookmark(list" << listStream.str()
                            << ", bookmarkValue);" << endl;

                    freeZone->Add(bookmarkValue);
                    
                }
                
                if (bookmarkValue != NULL)
                    CFRelease(bookmarkValue);
				
				#else

				if (error == errPlugInHostInsufficient)
				{
					fileOut << "// No bookmark support." << endl;
				} 
				else 
				{
					fileOut << "ERROR: Unexpected Bookmark support!" << endl;
				}

				#endif

				delete [] fullPath;

				break;
				}
			case typeValueList:
				// Get some local data
				PIActionList actionList;
				actionList = NULL;

				// Pull the info
				sPSActionList->GetList(inputList, counter, &actionList);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the actionList
				tabLevel++;
				DumpInfoFromList(actionList, fileOut);
				tabLevel--;

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutList(list" << listStream.str() << ", list" 
					<< actionList << ");" << endl;

				if (actionList != NULL)
					sPSActionList->Free(actionList);

				break;

			case typeObjectSpecifier:
				// Get some local data
				PIActionReference refValue;
				refValue = NULL;

				// Pull the info
				sPSActionList->GetReference(inputList, counter, &refValue);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the refValue
				tabLevel++;
				DumpInfoFromReference(refValue, fileOut);
				tabLevel--;

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutReference(list" << listStream.str() << ", ref" 
					<< refValue << ");" << endl;
				
				if (refValue != NULL)
					sPSActionReference->Free(refValue);

				break;

			case typeType:
			case typeGlobalClass:
				// Get some local data
				DescriptorClassID globClassID;
				char* globClassIDStr;
				globClassIDStr = new char[maxHashStringSize];
				if (globClassIDStr == NULL) 
					return;

				// Pull the info
				sPSActionList->GetClass(inputList, counter, &globClassID);

				// Convert the 'Hash' to a "hashString"
				LongToStr(globClassID, "class", globClassIDStr, maxHashStringSize);

				if (globClassID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< globClassIDStr << "\", &runtimeClassID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(globClassIDStr, maxHashStringSize-1, "runtimeClassID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutClass(list" << listStream.str() << ", " 
					<< globClassIDStr << ");" << endl;
				delete [] globClassIDStr;
				break;
				
			case typeRawData:
				// Get some local data
				int32	dataLength;

				// Pull the info
				sPSActionList->GetDataLength(inputList, counter, &dataLength);	

				// Format the output
				TabOver(fileOut);
				fileOut << sal << "PutData(list" << listStream.str() << ", " 
						<< ", " << dataLength << ", voidPtrToData);"
						<< endl;
				break;

			case typeBookmark:
				{
				// Get some local data
				CFDataRef bookmarkValue = NULL;
				
				// Pull the info
				OSErr error = sPSActionList->GetBookmark(inputList, counter, &bookmarkValue);
				
				#if __PIMac__

				// Get the information out of the bookmakr
				if (bookmarkValue != NULL && error == noErr)
                {
                    char* fullPath = new char[BigStrMaxLen*2];
                    if (fullPath == NULL)
                        return;
                
					BookmarkToFullPath(bookmarkValue, fullPath, BigStrMaxLen*2);

                    // Format the output
                    TabOver(fileOut);
                    fileOut << "// Move this to the top of the routine!" << endl;
                    TabOver(fileOut);
                    fileOut << "CFDataRef bookmarkValue = NULL;" << endl;

                    TabOver(fileOut);
                    fileOut << "FullPathToBookmark(\"" << fullPath << "\", bookmarkValue);"
					        << endl;
                    TabOver(fileOut);
                    fileOut << sal << "PutBookmark(list" << listStream.str()
                            << ", bookmarkValue);" << endl;

                    freeZone->Add(bookmarkValue);

                    delete [] fullPath;
                }
                
                if (bookmarkValue != NULL)
                    CFRelease(bookmarkValue);

				#else
					
				if (error == errPlugInHostInsufficient)
				{
					fileOut << "// No bookmark support." << endl;
				} 
				else 
				{
					fileOut << "ERROR: Unexpected Bookmark support!" << endl;
				}

				#endif

				break;
				}

			default:
				// Get some local data
				char* typeIDStr;
				typeIDStr = new char[maxHashStringSize];
				if (typeIDStr == NULL) 
					return;

				// Convert the 'Hash' to a "hashString"
				LongToStr(typeID, "type", typeIDStr, maxHashStringSize);

				if (typeID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< typeIDStr << "\", &runtimeTypeID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(typeIDStr, maxHashStringSize-1, "runtimeTypeID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << "ERROR: DumpInfoFromList type: " << typeIDStr 
					<< ", entry: " << counter << ", Total Entry: " << listCount 
					<< endl;
				delete [] typeIDStr;
				break;
		} // end switch on typeID

		counter++; // move to the next item in the list
	
		TabOver(fileOut);
		fileOut << ecs;

	} // end the while loop
	#endif // _DEBUG
} // end DumpInfoFromList
	

	
//-------------------------------------------------------------------------------
//
//	DumpInfoFromDescriptor
//
//	Goes through each property in the result descriptor and dumps it and its
//	type. Has recursive functions that can get descriptors out of descriptors
//	and other combinations.
//
//-------------------------------------------------------------------------------
static void DumpInfoFromDescriptor(const PIActionDescriptor inputDesc,
								   ofstream & fileOut)
{

	// You probably don't want the overhead of this routine in your
	// non-debug code, so I'll define this and its strings only for
	// a debug build:
	#ifdef _DEBUG

	const char* sad = "error = sPSActionDescriptor->";
	
	// If there is no descriptor then don't bother.
	if (inputDesc == NULL)
		return;

	// counters for this descriptor
	uint32 descCount = 0;
	uint32 counter = 0;
	if (sPSActionDescriptor->GetCount(inputDesc, &descCount))
		return;
	
    std::ostringstream descStream;
    descStream << std::setw(sizeof(void*) * 2) << std::hex << std::setfill('0') << (intptr_t)inputDesc;

	// Format the output
	TabOver(fileOut);
	fileOut << "// Move this to the top of the routine!" << endl;

	TabOver(fileOut);
	fileOut << "PIActionDescriptor desc" << descStream.str() << " = NULL;" << endl << endl;

	TabOver(fileOut);
	fileOut << sad << "Make(&desc" << descStream.str() << ");" << endl;

	TabOver(fileOut);
	fileOut << ecs;

	freeZone->Add(inputDesc);

	char* keyIDStr = new char[maxHashStringSize];
	if (keyIDStr == NULL)
		return;

	// loop through all the items in this descriptor pulling apart
	// each one as it comes
	while (counter < descCount)
	{
		// get the key for this item
		DescriptorKeyID thisKeyID;
		sPSActionDescriptor->GetKey(inputDesc, counter, &thisKeyID);

		// get the type for this key
		DescriptorTypeID typeID;
		sPSActionDescriptor->GetType(inputDesc, thisKeyID, &typeID);

		// Convert the 'Hash' to a "hashString"
		LongToStr(thisKeyID, "key", keyIDStr, maxHashStringSize);		
		
		if (thisKeyID < SmallestHashValue)
		{
			if (typeID != typeObject && typeID != typeGlobalObject &&
				typeID != typeValueList && typeID != typeGlobalClass)
			{
				TabOver(fileOut);
				fileOut << "error = sPSActionControl->StringIDToTypeID(\""
						<< keyIDStr << "\", &runtimeKeyID);" << endl;
			
				TabOver(fileOut);
				fileOut << ecs;
			}

			strcpy_s(keyIDStr, maxHashStringSize-1, "runtimeKeyID");
		}

		// pull the next bit of information based on the type
		switch (typeID)
		{
			case typeSInt64:
				int64 int64Value;

				sPSActionDescriptor->GetInteger64(inputDesc, thisKeyID, &int64Value);
				
				TabOver(fileOut);
				fileOut << sad << "PutInteger64(desc"
						<< descStream.str() << ", " << keyIDStr << ", " 
						<< int64Value << ");" << endl;
				break;
				
			case typeSInt32: /* was typeInteger: */
				// Get some local data
				int32 intValue;

				// Pull the info
				sPSActionDescriptor->GetInteger(inputDesc, thisKeyID, &intValue);

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutInteger(desc"
						<< descStream.str() << ", " << keyIDStr << ", " 
						<< intValue << ");" << endl;
				break;

			case typeIEEE64BitFloatingPoint: /* was typeFloat: */
				// Get some local data
				double doubleValue;

				// Pull the info
				sPSActionDescriptor->GetFloat(inputDesc, thisKeyID, &doubleValue);

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutFloat(desc"
						<< descStream.str() << ", " << keyIDStr << ", "
						<< doubleValue << ");" << endl;
				break;

			case typeUnitFloat:
				// Get some local data
				double unitDoubleValue;
				DescriptorUnitID unitID;
				char* unitIDStr;
				unitIDStr = new char[maxHashStringSize];
				if (unitIDStr == NULL) 
					return;

				// Pull the info
				sPSActionDescriptor->GetUnitFloat(
					inputDesc, 
					thisKeyID, 
					&unitID, 
					&unitDoubleValue);

				// Convert the 'Hash' to a "hashString"
				LongToStr(unitID, "unit", unitIDStr, maxHashStringSize);

				if (unitID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
							<< unitIDStr << "\", &runtimeUnitID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;
			
					strcpy_s(unitIDStr, maxHashStringSize-1, "runtimeUnitID");
				}
		
				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutUnitFloat(desc"
						<< descStream.str() << ", " << keyIDStr << ", "
						<< unitIDStr << ", " << unitDoubleValue
						<< ");" << endl;
				delete [] unitIDStr;
				break;

			case typeChar:
			{
				// Get some local data
				ASZString zString;
				sPSActionDescriptor->GetZString(inputDesc, thisKeyID, &zString);
				ASUInt32 unicodeLength = sASZString->LengthAsUnicodeCString(zString);
				ASUnicode * unicodeStr = new ASUnicode[unicodeLength + 1];
				sASZString->AsUnicodeCString(zString, unicodeStr, unicodeLength, false);
				
				char * multiByteStr = NULL;
				int multiByteLength = 0;
				bool conversionOK = false;
					
				#if __PIMac__
					CFStringRef stringRef = CFStringCreateWithCharacters(NULL, unicodeStr, unicodeLength + 1);
					// where is the routine to figure out how long this thing is going to be?
					// make it three times longer than the unicode string ???
					multiByteLength = ( unicodeLength + 1 ) * 3;
					multiByteStr = new char[multiByteLength];
					if ( CFStringGetCString(stringRef, multiByteStr, multiByteLength, kCFStringEncodingUTF8))
					{
						conversionOK = true;
					}

				#else
					multiByteLength = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)unicodeStr, unicodeLength,
														  NULL, 0, NULL, NULL);
					if (multiByteLength > 0)
					{
						multiByteStr = new char[multiByteLength];
						if ( WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)unicodeStr, unicodeLength,
												  multiByteStr, multiByteLength, NULL, NULL) )
						{
							conversionOK = true;
						}
					}
				#endif			
				
				if ( conversionOK )
				{
					TabOver(fileOut);
					fileOut << "// Unicode String as UTF8: " << multiByteStr << endl;
				}
				
				delete [] multiByteStr;
				delete [] unicodeStr;

				uint32 charLen;
				size_t requestLen;
				char* charValue;

				// Pull the info
				sPSActionDescriptor->GetStringLength(inputDesc, thisKeyID, &charLen);
				requestLen = ++charLen; // make room for the null termination

				// Make some room for the data
				charValue = new char[requestLen];
				if (charValue == NULL) 
					return;

				// Check for room availability
				if (requestLen == charLen && charValue)
				{
					sPSActionDescriptor->GetString(
						inputDesc, 
						thisKeyID, 
						charValue, 
						(uint32)requestLen);

					// Format the output
					TabOver(fileOut);
					fileOut << sad << "PutString(desc"
							<< descStream.str() << ", " << keyIDStr << ", \""
							<< charValue << "\");" << endl;
				}
				else
				{
					TabOver(fileOut);
					fileOut << "ERROR: " << sad << "PutString" << endl;
				}

				// Get rid of our local buffer
				delete [] charValue;
				break;
			}
			case typeBoolean:
				// Get some local data
				Boolean boolValue;

				// Pull the info
				sPSActionDescriptor->GetBoolean(inputDesc, thisKeyID, &boolValue);

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutBoolean(desc"
						<< descStream.str() << ", " << keyIDStr << ", "
						<< (boolValue ? "true" : "false") << ");" << endl;
				break;

			case typeObject:
				// Get some local data
				PIActionDescriptor objDesc;
				objDesc = NULL;
				DescriptorClassID objClassID;
				char* objClassIDStr;
				objClassIDStr = new char[maxHashStringSize];
				if (objClassIDStr == NULL) 
					return;

				// Pull the info
				sPSActionDescriptor->GetObject(
					inputDesc, 
					thisKeyID, 
					&objClassID, 
					&objDesc);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the objDesc
				tabLevel++;
				DumpInfoFromDescriptor(objDesc, fileOut);
				tabLevel--;

				LongToStr(objClassID, "class", objClassIDStr, maxHashStringSize);				
				
				// Check to see if this is a 'Hash' type of event or a unique ID 
				// string. If it is a unique ID string then you have to get the 
				// runtime ID for that event and play.
				if (objClassID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< objClassIDStr << "\", &runtimeObjID);" << endl;

					// Update for the string
					strcpy_s(objClassIDStr, maxHashStringSize-1, "runtimeObjID");

					TabOver(fileOut);
					fileOut << ecs;
				}

				// Dump the key out here so it is less confusing in the log file
				if (thisKeyID < SmallestHashValue)
				{
					LongToStr(thisKeyID, "key", keyIDStr, maxHashStringSize);

					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\""
							<< keyIDStr << "\", &runtimeKeyID);" << endl;
			
					TabOver(fileOut);
					fileOut << ecs;
		
					strcpy_s(keyIDStr, maxHashStringSize-1, "runtimeKeyID");
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutObject(desc"
						<< descStream.str() << ", " << keyIDStr << ", "
						<< objClassIDStr << ", desc" << objDesc << ");" << endl;

				if (objDesc != NULL) 
					sPSActionDescriptor->Free(objDesc);
				
				delete [] objClassIDStr;
				break;

			case typeGlobalObject:
				// Get some local data
				PIActionDescriptor globObjDesc;
				globObjDesc = NULL;
				DescriptorClassID globObjClassID;
				char* globObjClassIDStr;
				globObjClassIDStr = new char[maxHashStringSize];
				if (globObjClassIDStr == NULL) 
					return;

				// Pull the info
				sPSActionDescriptor->GetGlobalObject(
					inputDesc, 
					thisKeyID, 
					&globObjClassID, 
					&globObjDesc);


				LongToStr(globObjClassID, "class", globObjClassIDStr, maxHashStringSize);				
				
				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the globObjDesc
				tabLevel++;
				DumpInfoFromDescriptor(globObjDesc, fileOut);
				tabLevel--;

				// Check to see if this is a 'Hash' type of event or a unique ID 
				// string. If it is a unique ID string then you have to get the 
				// runtime ID for that event and play.
				if (globObjClassID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< globObjClassIDStr << "\", &runtimeObjID);" << endl;

					// Update for the string
					strcpy_s(globObjClassIDStr, maxHashStringSize-1, "runtimeObjID");

					TabOver(fileOut);
					fileOut << ecs;
				}

				// Dump the key out here so it is less confusing in the log file
				if (thisKeyID < SmallestHashValue)
				{
					LongToStr(thisKeyID, "key", keyIDStr, maxHashStringSize);

					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\""
							<< keyIDStr << "\", &runtimeKeyID);" << endl;
			
					TabOver(fileOut);
					fileOut << ecs;
		
					strcpy_s(keyIDStr, maxHashStringSize-1, "runtimeKeyID");
				}

				// Format the output
				TabOver(fileOut);

				fileOut << sad << "PutGlobalObject(desc"
						<< descStream.str() << ", " << keyIDStr << ", "
						<< globObjClassIDStr << ", desc" << globObjDesc << ");" 
						<< endl;

				if (globObjDesc != NULL) 
					sPSActionDescriptor->Free(globObjDesc);

				delete [] globObjClassIDStr;
				break;

			case 'enum'://typeEnumerated:
				// Get some local data
				DescriptorEnumTypeID enumTypeID;
				DescriptorEnumID enumID;
				char* enumTypeIDStr;
				enumTypeIDStr = new char[maxHashStringSize];
				if (enumTypeIDStr == NULL) 
					return;
				char* enumIDStr;
				enumIDStr = new char[maxHashStringSize];
				if (enumIDStr == NULL) 
					return;

				// Pull the info
				sPSActionDescriptor->GetEnumerated(
					inputDesc, 
					thisKeyID, 
					&enumTypeID, 
					&enumID);

				LongToStr(enumID, "enum", enumIDStr, maxHashStringSize);

				// Convert the 'Hash' to a "hashString"
				if (enumID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< enumIDStr << "\", &runtimeEnumID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;

					// Update for the string
					strcpy_s(enumIDStr, maxHashStringSize-1, "runtimeEnumID");
				}
				
				LongToStr(enumTypeID, "type", enumTypeIDStr, maxHashStringSize);

				if (enumTypeID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< enumTypeIDStr << "\", &runtimeTypeID);" << endl;
					TabOver(fileOut);
					fileOut << ecs;

					// Update for the string
					strcpy_s(enumTypeIDStr, maxHashStringSize-1, "runtimeTypeID");
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutEnumerated(desc"
						<< descStream.str() << ", " << keyIDStr << ", " 
						<< enumTypeIDStr << ", " << enumIDStr << ");" << endl;

				delete [] enumTypeIDStr;
				delete [] enumIDStr;
				break;

			case typePath:
			case typeAlias:
				{
				// Get some local data
				Handle aliasValue = NULL;
				char* fullPath = new char[BigStrMaxLen*2];
				if (fullPath == NULL) 
					return;

				// Pull the info
				sPSActionDescriptor->GetAlias(inputDesc, thisKeyID, &aliasValue);

				// Get the information out of the Handle
				// On Windows it's a char**, on Mac it's a mess
				if (fullPath != NULL)
					AliasToFullPath(aliasValue, fullPath, BigStrMaxLen*2);

				// Format the output
				TabOver(fileOut);
				fileOut << "// Move this to the top of the routine!" << endl;
				TabOver(fileOut);
				fileOut << "Handle aliasValue = NULL;" << endl;

				TabOver(fileOut);
				fileOut << "FullPathToAlias(\"" << fullPath << "\", aliasValue);" 
					    << endl;
				TabOver(fileOut);
				fileOut << sad << "PutAlias(desc"
						<< descStream.str() << ", " << keyIDStr << ", aliasValue);"
						<< endl;

				freeZone->Add(aliasValue);

				sPSHandle->DisposeRegularHandle(aliasValue);

				// use the new bookmark for Mac, should error for Windows
				CFDataRef bookmarkValue;
				OSErr error = sPSActionDescriptor->GetBookmark(inputDesc, thisKeyID, &bookmarkValue);

				#if __PIMac__

				// Get the information out of the bookmark
				if (bookmarkValue != NULL && error == noErr)
                {
				
                    BookmarkToFullPath(bookmarkValue, fullPath, BigStrMaxLen*2);

                    // Format the output
                    TabOver(fileOut);
                    fileOut << "// Move this to the top of the routine!" << endl;
                    TabOver(fileOut);
                    fileOut << "CFDataRef bookmarkValue = NULL;" << endl;

                    TabOver(fileOut);
                    fileOut << "FullPathToBookmark(\"" << fullPath << "\", bookmarkValue);"
					        << endl;
                    TabOver(fileOut);
                    fileOut << sad << "PutBookmark(desc"
                            << descStream.str() << ", " << keyIDStr << ", bookmarkValue);"
                            << endl;
				
                    freeZone->Add(bookmarkValue);
                }
                
				if (bookmarkValue)
                    CFRelease(bookmarkValue);

				#else

				if (error == errPlugInHostInsufficient)
				{
					fileOut << "// No bookmark support." << endl;
				} 
				else 
				{
					fileOut << "ERROR: Unexpected Bookmark support!" << endl;
				}

				#endif

				delete [] fullPath;

				break;
				}

			case typeValueList:
				// Get some local data
				PIActionList	listValue;
				listValue = NULL;

				// Pull the info
				sPSActionDescriptor->GetList(inputDesc, thisKeyID, &listValue);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the listValue
				tabLevel++;
				DumpInfoFromList(listValue, fileOut);
				tabLevel--;

				LongToStr(thisKeyID, "key", keyIDStr, maxHashStringSize);

				if (thisKeyID < SmallestHashValue)
				{
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\""
							<< keyIDStr << "\", &runtimeKeyID);" << endl;
					strcpy_s(keyIDStr, maxHashStringSize-1, "runtimeKeyID");

					TabOver(fileOut);
					fileOut << ecs;
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutList(desc" << descStream.str() << ", " << keyIDStr 
					<< ", list" << listValue << ");" << endl;

				if (listValue != NULL)
					sPSActionList->Free(listValue);

				break;

			case typeObjectSpecifier:
				// Get some local data
				PIActionReference refValue;
				refValue = NULL;

				// Pull the info
				sPSActionDescriptor->GetReference(inputDesc, thisKeyID, &refValue);

				// change the indentation level for this object in a list
				// this makes it easier to read the output file
				// Recurse into this routine to pull apart the refValue
				tabLevel++;
				DumpInfoFromReference(refValue, fileOut);
				tabLevel--;

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutReference(desc" << descStream.str() << ", " 
					<< keyIDStr << ", ref" << refValue << ");" << endl;

				if (refValue != NULL)
					sPSActionReference->Free(refValue);
				break;

			case typeType:
			case typeGlobalClass:
				// Get some local data
				DescriptorClassID globClassID;
				char* globClassIDStr;
				globClassIDStr = new char[maxHashStringSize];
				if (globClassIDStr == NULL) 
					return;

				// Pull the info
				sPSActionDescriptor->GetClass(inputDesc, thisKeyID, &globClassID);

				LongToStr(globClassID, "class", globClassIDStr, maxHashStringSize);
				
				// Convert the 'Hash' to a "hashString"
				if (globClassID < SmallestHashValue)
				{
					// Format the output
					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\"" 
						<< globClassIDStr << "\", &runtimeClassID);" << endl;

					// Update for the string
					strcpy_s(globClassIDStr, maxHashStringSize-1, "runtimeClassID");

					TabOver(fileOut);
					fileOut << ecs;
				}

				// Dump the key out here so it is less confusing in the log file
				if (thisKeyID < SmallestHashValue)
				{
					LongToStr(thisKeyID, "key", keyIDStr, maxHashStringSize);

					TabOver(fileOut);
					fileOut << "error = sPSActionControl->StringIDToTypeID(\""
							<< keyIDStr << "\", &runtimeKeyID);" << endl;
			
					TabOver(fileOut);
					fileOut << ecs;
		
					strcpy_s(keyIDStr, maxHashStringSize-1, "runtimeKeyID");
				}

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutClass(desc" << descStream.str() << ", " 
					<< keyIDStr << ", " << globClassIDStr << ");" << endl;

				delete [] globClassIDStr;
				break;

			case typeRawData:
				// Get some local data
				int32	dataLength;

				// Pull the info
				sPSActionDescriptor->GetDataLength(inputDesc, thisKeyID, &dataLength);	

				// Format the output
				TabOver(fileOut);
				fileOut << sad << "PutData(desc" << descStream.str() << ", " 
						<< keyIDStr << ", " << dataLength << ", voidPtrToData);"
						<< endl;
				break;

			case typeBookmark:
				{
				// Get some local data
				CFDataRef bookmarkValue = NULL;
				
				// Pull the info
				OSErr error = sPSActionDescriptor->GetBookmark(inputDesc, thisKeyID, &bookmarkValue);
				
				#if __PIMac__

				// Get the information out of the bookmakr
				if (bookmarkValue != NULL && error == noErr)
                {

                    char* fullPath = new char[BigStrMaxLen*2];
                    if (fullPath == NULL)
                        return;
                
					BookmarkToFullPath(bookmarkValue, fullPath, BigStrMaxLen*2);

                    // Format the output
                    TabOver(fileOut);
                    fileOut << "// Move this to the top of the routine!" << endl;
                    TabOver(fileOut);
                    fileOut << "CFDataRef bookmarkValue = NULL;" << endl;

                    TabOver(fileOut);
                    fileOut << "FullPathToBookmark(\"" << fullPath << "\", bookmarkValue);"
					        << endl;
                    TabOver(fileOut);
                    fileOut << sad << "PutBookmark(desc"
						    << descStream.str() << ", " << keyIDStr << ", bookmarkValue);"
                            << endl;
				
                    freeZone->Add(bookmarkValue);
                
                    delete [] fullPath;
                
                }
                
				if (bookmarkValue != NULL)
                    CFRelease(bookmarkValue);

				#else
					
				if (error == errPlugInHostInsufficient)
				{
					fileOut << "// No bookmark support." << endl;
				} 
				else 
				{
					fileOut << "ERROR: Unexpected Bookmark support!" << endl;
				}

				#endif

				break;
				}

			default:
				// Get some local data
				char* typeIDStr;
				typeIDStr = new char[maxHashStringSize];
				if (typeIDStr == NULL) 
					return;

				// Convert the 'Hash' to a "hashString"
				LongToStr(typeID, "xxxx", typeIDStr, maxHashStringSize);

				// Format the output
				TabOver(fileOut);
				fileOut << "ERROR DumpInfoFromDescriptor type: " << typeIDStr 
					<< ", key: " << keyIDStr << ", entry: " << counter << endl;

				delete [] typeIDStr;
				break;
		} // end the switch

		counter++; // go to the next item in the list

		TabOver(fileOut);
		fileOut << ecs;

	}// end the while loop

	delete[] keyIDStr;

	#endif // _DEBUG
}// end DumpInforFromDescriptor



//-------------------------------------------------------------------------------
//
//	TabOver
//
//	Utility function that makes the output file easier to read.
//
//-------------------------------------------------------------------------------
static void TabOver(ofstream & fileOut)
{
	for(int16 numberoftabs = 0; numberoftabs < tabLevel; numberoftabs++)
		fileOut << "     ";
}



//-------------------------------------------------------------------------------
//
//	PIUIDToChar
//
//	Utility function that converts longs to "Hash" strings
//
//-------------------------------------------------------------------------------
static void PIUIDToChar (const unsigned long inType, /* OUT */ char* outChars)
{
	int8 loopType, loopChar;
	
	// Figure out which byte we're dealing with and move it
	// to the highest character, then mask out everything but
	// the lowest byte and assign that as the character:
	for (loopType = 0, loopChar = 3; loopType < 4; loopType++, loopChar--)
		outChars[loopChar] = (char) ((inType >> (loopType<<3)) & 0xFF);
	
	outChars[loopType] = '\0';

} // end PIUIDToChar



//-------------------------------------------------------------------------------
//
//	PIUCharToID
//
//	Utility function that converts "Hash" strings to longs
//
//-------------------------------------------------------------------------------
unsigned long PIUCharToID (const char* inChars)
{
	unsigned short loop;
	ResType outType = 0;
	
	for (loop = 0; loop < 4; loop++)
	{
		outType <<= 8; // bits per char
		outType |= inChars[loop];
	}

	return outType;

} // end PIUCharToID



//-------------------------------------------------------------------------------
// You probably don't want the overhead of this routine in your
// non-debug code, so I'll define this and its strings only for
// a debug build:
#ifdef _DEBUG

//-------------------------------------------------------------------------------
//
//	LongToStr
//
//	Utility that uses the above structure to convert the int32 value from the
//	descriptors, lists, and references to output the string name. If it can't
//	find the constant then it outputs the 'Hash' code.
//-------------------------------------------------------------------------------
static void LongToStr(int32 inputLong, const char* inputKeyType, char* returnString, int32 maxStringSize)
{
	// don't want to recalculate this all the time
	static const int32 ArraySize = sizeof(PSConstA) / sizeof(PSConstantArray);
	bool found = false;

	// blank it out
    *returnString = '\0';
    
    // if the input long is a small number then it's a runtime ID
    // use the control procs to get the string
    if (inputLong < SmallestHashValue)
    {
    	if (!(sPSActionControl->TypeIDToStringID(inputLong, 
    	                                   returnString,
    	                                   maxHashStringSize)))
    	{
    		found = true;
    	}
    }

	// loop through all the above constants looking for the one that matches
	// in an ideal world you wouldn't need the inputKeyType but there are constants
	// that break the hash code creation world so we want to make sure if you are
	// asking for a key you will get a key and not a class or something else
	if (!found)
	{
	    for (int32 counter = 0; counter < ArraySize; counter++)
    	    if (PSConstA[counter].longVal == inputLong)
				if (strstr(PSConstA[counter].strStr, inputKeyType))
				{
					strcpy_s(returnString, maxStringSize-1, PSConstA[counter].strStr);
					counter = ArraySize;// and stop the for loop
					found = true;
				}
	}

	// didn't find a match so convert the number to its 'Hash' code
    if (*returnString == '\0' || !found)
	{
		*returnString++ = '\'';
		PIUIDToChar(inputLong,returnString);
		returnString[4] = '\'';
		returnString[5] = '\0';
	}
}



//-------------------------------------------------------------------------------
//
//	StrToLong
//
//	Utility that uses the above structure to convert the string value from the
//	descriptors, lists, and references to output the long value.
//-------------------------------------------------------------------------------
static unsigned long StrToLong(const char* inputStr)
{
	// don't want to recalculate this all the time
	static const int32 ArraySize = sizeof(PSConstA) / sizeof(PSConstantArray);

	unsigned long returnLong = 0;
	if (inputStr)
		for(int32 counter = 0; counter < ArraySize; counter++)
			if (strcmp(inputStr, PSConstA[counter].strStr) == 0)
			{
				returnLong = PSConstA[counter].longVal;
				break;
			}
	return (returnLong);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::FreeZone
//
//	Constructor for the FreeZone. Doesn't do anything.
//
//-------------------------------------------------------------------------------
FreeZone::FreeZone() {}



//-------------------------------------------------------------------------------
//
//	FreeZone::~FreeZone
//
//	Destructor for the FreeZone class. Deletes all the char []'s in the vector.
//
//-------------------------------------------------------------------------------
FreeZone::~FreeZone()
{
	vector<char*>::iterator array_iter = v_array.begin();
	vector<char*>::iterator array_end = v_array.end();
	while(array_iter != array_end)
	{
		delete [] *array_iter;
		array_iter++;
	}
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Add
//
//	Add a reference to the vector using the generic routine.
//
//-------------------------------------------------------------------------------
void FreeZone::Add(PIActionReference reference)
{
	Add("ref", (intptr_t)reference);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Add
//
//	Add a list to the vector using the generic routine.
//
//-------------------------------------------------------------------------------
void FreeZone::Add(PIActionList list)
{
	Add("list", (intptr_t)list);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Add
//
//	Add a descriptor to the vector using the generic routine.
//
//-------------------------------------------------------------------------------
void FreeZone::Add(PIActionDescriptor descriptor)
{
	Add("desc", (intptr_t)descriptor);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Add
//
//	Add a handle to the vector using a special routine.
//
//-------------------------------------------------------------------------------
void FreeZone::Add(Handle /*aliasValue*/)
{
	const size_t s = strlen("aliasValue") + 1;
	char* ptr = new char[s];
	if (ptr == NULL) 
		return;
	strcpy_s(ptr, s, "aliasValue");
	v_array.push_back(ptr);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Add
//
//	Add a CFDataRef to the vector using a special routine.
//
//-------------------------------------------------------------------------------
void FreeZone::Add(CFDataRef /*dataRef*/)
{
	const size_t s = strlen("bookmarkValue") + 1;
	char* ptr = new char[s];
	if (ptr == NULL) 
		return;
	strcpy_s(ptr, s, "bookmarkValue");
	v_array.push_back(ptr);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Add
//
//	The generic add.
//
//-------------------------------------------------------------------------------
void FreeZone::Add(const char* text, intptr_t value)
{
	const size_t s = strlen(text) + 1;
	const size_t sa = s + 20;
	char* ptr = new char[sa];
	if (ptr == NULL) 
		return;
	std::ostringstream temp;
    temp << text << std::setw(sizeof(void*) * 2) << std::hex << std::setfill('0') << value;
	strncpy(ptr, temp.str().c_str(), sa - 1);
	ptr[sa-1] = '\0';
	v_array.push_back(ptr);
}



//-------------------------------------------------------------------------------
//
//	FreeZone::Output
//
//	Dump the vector to the stream.
//
//-------------------------------------------------------------------------------
void FreeZone::Output(ofstream& fileOut)
{
	vector<char*>::iterator array_iter = v_array.begin();
	vector<char*>::iterator array_end = v_array.end();
	while(array_iter != array_end)
	{
		char freeType = (*array_iter)[0];
		switch (freeType)
		{
			case 'r':
				TabOver(fileOut);
				fileOut << "if (" 
					   << *array_iter 
						<< " != NULL) sPSActionReference->Free(" 
						<< *array_iter << ");" 
						<< endl;
				break;
			case 'l':
				TabOver(fileOut);
				fileOut << "if (" 
					    << *array_iter 
						<< " != NULL) sPSActionList->Free(" 
						<< *array_iter << ");" 
						<< endl;
				break;
			case 'd':
				TabOver(fileOut);
				fileOut << "if (" 
					    << *array_iter 
						<< " != NULL) sPSActionDescriptor->Free(" 
						<< *array_iter << ");" 
						<< endl;
				break;
			case 'a':
				TabOver(fileOut);
				fileOut << "if (" 
					    << *array_iter 
						<< " != NULL) sPSHandle->DisposeRegularHandle(" 
						<< *array_iter << ");" 
						<< endl;
				break;
			case 'b':
				TabOver(fileOut);
				fileOut << "if ("
					    << *array_iter
						<< " != NULL) CFRelease("
						<< *array_iter << ");"
						<< endl;
				break;
		}
		array_iter++;
	}
}

#endif // _DEBUG

// here all all the known dupes 11/4/98, I don't know of a good (easy) way to figure these out
// so if you see a constant that doesn't look like it belongs then check here and figure out
// what it should be.
//enumBlacks                   enumBlocks
//enumFileInfo                 enumFillInverse
//enumLightOmni                enumLightenOnly
//enumMagenta                  enumMagentas
//keyBlackLevel                keyBlackLimit
//keyCenter                    keyContrast
//keyConstant                  keyConstrain
//keyDistortion                keyDistribution
//keyGrain                     keyGreen
//keyInterfaceIconFrameDimmed  keyInterlace
//keyInterfaceIconFrameDimmed  keyInterpolation
//keyInterlace                 keyInterpolation
//keyNumberOfLayers            keyNumberOfLevels
//keySaturation                keyStart
//keyTextClickPoint            keyTextureCoverage

// end PIUActionUtils.cpp
