// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2002 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
//-------------------------------------------------------------------------------
//
//	File:
//		PIUGet.cpp
//
//	Description:
//		Utility routines for getting information out of Photoshop.
//		See PIUGet.h for more information.
//
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//	Includes
//-------------------------------------------------------------------------------
#include "PIUGet.h"
#include "PITerminology.h"


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetInfo(DescriptorClassID desiredClass, 
				 DescriptorKeyID desiredKey, 
				 void * returnData,
				 void * returnExtraData)
{
	SPErr error = kSPNoError;
    PIActionReference reference = NULL;
    PIActionDescriptor result = NULL;
	PIActionDescriptor * data;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = sPSActionReference->PutProperty(reference, 
			                                    classProperty, 
												desiredKey);
		if (error) goto returnError;
	}
	
	error = sPSActionReference->PutEnumerated(reference, 
											  desiredClass, 
											  typeOrdinal, 
											  enumTarget);
	if (error) goto returnError;
	
	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = PIUGetSingleItemFromDescriptor(result, 
											   desiredKey, 
											   returnData, 
											   returnExtraData);
		if (error) goto returnError;
	} else {
		data = (PIActionDescriptor *)returnData;
		*data = result;
		result = NULL;
	}

returnError:
	
	if (reference != NULL) sPSActionReference->Free(reference);
	if (result != NULL)	sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetInfoByIndex(uint32 index,
						DescriptorClassID desiredClass,
						DescriptorKeyID desiredKey,
						void * returnData,
						void * returnExtraData)
{
	SPErr error = kSPNoError;
    PIActionReference reference = NULL;
    PIActionDescriptor result = NULL;
	PIActionDescriptor * data;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;
	
	if (desiredKey)
	{
		error = sPSActionReference->PutProperty(reference, 
												classProperty, 
												desiredKey);
		if (error) goto returnError;
	}
	
	error = sPSActionReference->PutIndex(reference, 
										 desiredClass, 
										 index);
	if (error) goto returnError;
	
	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = PIUGetSingleItemFromDescriptor(result, 
			                                   desiredKey, 
											   returnData, 
											   returnExtraData);
		if (error) goto returnError;
	} else {
		data = (PIActionDescriptor *)returnData;
		*data = result;
		result = NULL;
	}

returnError:

	if (reference != NULL) sPSActionReference->Free(reference);
	if (result != NULL) sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetInfoByIndexIndex(uint32 indexChild,
							 uint32 indexParent,
							 DescriptorClassID desiredClassChild,
							 DescriptorClassID desiredClassParent,
							 DescriptorKeyID desiredKey,
							 void * returnData,
							 void * returnExtraData)
{
	SPErr error = kSPNoError;
    PIActionReference reference = NULL;
    PIActionDescriptor result = NULL;
	PIActionDescriptor * data;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;
	
	if (desiredKey)
	{
		error = sPSActionReference->PutProperty(reference, 
												classProperty, 
												desiredKey);
		if (error) goto returnError;
	}
	
	error = sPSActionReference->PutIndex(reference,
										 desiredClassChild,
										 indexChild);
	if (error) goto returnError;

	error = sPSActionReference->PutIndex(reference, 
										 desiredClassParent, 
										 indexParent);
	if (error) goto returnError;
	
	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = PIUGetSingleItemFromDescriptor(result, 
			                                   desiredKey, 
											   returnData, 
											   returnExtraData);
		if (error) goto returnError;
	} else {
		data = (PIActionDescriptor *)returnData;
		*data = result;
		result = NULL;
	}

returnError:

	if (reference != NULL) sPSActionReference->Free(reference);
	if (result != NULL) sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetSingleItemFromDescriptor(PIActionDescriptor result, 
								     DescriptorKeyID desiredKey, 
								     void * returnData,
								     void * returnExtraData)
{
	SPErr error = kSPNoError;
    Boolean hasKey = false;
    DescriptorEnumTypeID typeID;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;
    
    error = sPSActionDescriptor->HasKey(result, 
		                                desiredKey, 
										&hasKey);
	if (error) goto returnError;
        
    if (hasKey)
	{
		error = sPSActionDescriptor->GetType(result, 
			                                 desiredKey, 
											 &typeID);
		if (error) goto returnError;

		switch(typeID)
		{
			case typeSInt64:
				error = sPSActionDescriptor->GetInteger64(result, 
														  desiredKey, 
														  (int64 *)returnData);
				break;

			case typeSInt32: /* was typeInteger: */
				error = sPSActionDescriptor->GetInteger(result, 
														desiredKey, 
														(int32 *)returnData);
				break;
    
			case typeIEEE64BitFloatingPoint: /* was typeFloat: */
				error = sPSActionDescriptor->GetFloat(result, 
													  desiredKey, 
													  (double *)returnData);
				break;
    
			case typeUnitFloat:
				if (returnExtraData == NULL)
					error = kSPBadParameterError;
				if (error) goto returnError;
				
				error = sPSActionDescriptor->GetUnitFloat(result, 
														  desiredKey, 
														  (DescriptorUnitID *)returnExtraData, 
														  (double *)returnData);
				break;
    
			case typeChar:
				if (returnExtraData == NULL)
					error = kSPBadParameterError;
				if (error) goto returnError;
				
				uint32 maxLength;
				maxLength = *((uint32*)returnExtraData);
				error = sPSActionDescriptor->GetStringLength(result, 
															 desiredKey, 
															 (uint32 *)returnExtraData);
				if (error) goto returnError;

				if (maxLength < *((uint32*)returnExtraData))
					error = kSPBadParameterError;
				if (error) goto returnError;
                
				error = sPSActionDescriptor->GetString(result, 
					                                   desiredKey, 
													   (char *)returnData, 
													   (*((int32 *)returnExtraData))+1);
				break;
                
			case typeBoolean:
                error = sPSActionDescriptor->GetBoolean(result, 
					                                    desiredKey, 
														(Boolean *)returnData);
				break;
    
			case typeObject:
				if (returnExtraData == NULL)
					error = kSPBadParameterError;
				if (error) goto returnError;
                
				error = sPSActionDescriptor->GetObject(result, 
					                                   desiredKey, 
													   (DescriptorClassID *)returnExtraData, 
													   (PIActionDescriptor *)returnData);
				break;
    
			case typeGlobalObject:
				if (returnExtraData == NULL)
					error = kSPBadParameterError;
				if (error) goto returnError;
                
				error = sPSActionDescriptor->GetGlobalObject(result, 
															 desiredKey, 
															 (DescriptorClassID *)returnExtraData, 
															 (PIActionDescriptor *)returnData);
				break;
                    
			case typeEnumerated:
				if (returnExtraData == NULL)
					error = kSPBadParameterError;
				if (error) goto returnError;
                
				error = sPSActionDescriptor->GetEnumerated(result, 
														   desiredKey, 
														   (DescriptorEnumTypeID *)returnExtraData, 
														   (DescriptorEnumID *)returnData);
				break;
    
			case typePath:
			case typeAlias:
                error = sPSActionDescriptor->GetAlias(result, 
					                                  desiredKey, 
													  (Handle *)returnData);
				break;
    
			case typeValueList:
				error = sPSActionDescriptor->GetList(result, 
					                                 desiredKey, 
													 (PIActionList *)returnData);
				break;
    
			case typeObjectSpecifier:
                error = sPSActionDescriptor->GetReference(result, 
														  desiredKey, 
														  (PIActionReference *)returnData);
				break;
    
			case typeType:
			case typeGlobalClass:
                error = sPSActionDescriptor->GetClass(result, 
					                                  desiredKey, 
													  (DescriptorClassID *)returnData);
				break;
                    
			default:
				error = kSPUnimplementedError;
		}
	}
returnError:
	return error;
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetErrorStringFromDescriptor(PIActionDescriptor descriptor,
								      char * stringPtr,
									  uint32 maxLength)
{
	SPErr error = kSPNoError;
    Boolean hasString = false;

	if (stringPtr == NULL) error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionDescriptor->HasKey(descriptor, 
										keyMessage, 
										&hasString);

    if (hasString && error == kSPNoError)
	{
		uint32 stringLength;
		error = sPSActionDescriptor->GetStringLength(descriptor, 
			                                         keyMessage, 
													 &stringLength);
		if (error) goto returnError;

		if (maxLength < stringLength)
			error = kSPBadParameterError;
		
		if (stringLength && error == kSPNoError)
		{
			error = sPSActionDescriptor->GetString(descriptor, 
				                                   keyMessage, 
												   stringPtr, 
												   stringLength);
		}
	}
returnError:
	return (error);
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetBackgroundInfo(DescriptorKeyID desiredKey, 
						   void * returnData,
						   void * returnExtraData)
{
	SPErr error = kSPNoError;
    PIActionReference reference = NULL;
    PIActionDescriptor result = NULL;
	PIActionDescriptor * data;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutProperty(reference, 
 	                                        classBackgroundLayer, 
											keyBackground);
	if (error) goto returnError;
	
	error = sPSActionReference->PutEnumerated(reference, 
											  classDocument, 
											  typeOrdinal, 
											  enumTarget);
	if (error) goto returnError;
	
	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = PIUGetSingleItemFromDescriptor(result, 
											   desiredKey, 
											   returnData, 
											   returnExtraData);
		if (error) goto returnError;
	} else {
		data = (PIActionDescriptor *)returnData;
		*data = result;
		result = NULL;
	}

returnError:
	
	if (reference != NULL) sPSActionReference->Free(reference);
	if (result != NULL)	sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetInfoByID(uint32 ID,
					 DescriptorClassID desiredClass,
					 DescriptorKeyID desiredKey,
					 void * returnData,
					 void * returnExtraData)
{
	SPErr error = kSPNoError;
    PIActionReference reference = NULL;
    PIActionDescriptor result = NULL;
	PIActionDescriptor * data;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;
	
	if (desiredKey)
	{
		error = sPSActionReference->PutProperty(reference, 
												classProperty, 
												desiredKey);
		if (error) goto returnError;
	}
	
	error = sPSActionReference->PutIdentifier(reference, 
											  desiredClass, 
											  ID);
	if (error) goto returnError;
	
	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = PIUGetSingleItemFromDescriptor(result, 
			                                   desiredKey, 
											   returnData, 
											   returnExtraData);
		if (error) goto returnError;
	} else {
		data = (PIActionDescriptor *)returnData;
		*data = result;
		result = NULL;
	}

returnError:

	if (reference != NULL) sPSActionReference->Free(reference);
	if (result != NULL) sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
SPErr PIUGetInfoByIDID(uint32 IDChild,
					   uint32 IDParent,
					   DescriptorClassID desiredClassChild,
					   DescriptorClassID desiredClassParent,
					   DescriptorKeyID desiredKey,
					   void * returnData,
					   void * returnExtraData)
{
	SPErr error = kSPNoError;
    PIActionReference reference = NULL;
    PIActionDescriptor result = NULL;
	PIActionDescriptor * data;

	if (returnData == NULL)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;
	
	if (desiredKey)
	{
		error = sPSActionReference->PutProperty(reference, 
												classProperty, 
												desiredKey);
		if (error) goto returnError;
	}
	
	error = sPSActionReference->PutIdentifier(reference,
										      desiredClassChild,
										      IDChild);
	if (error) goto returnError;

	error = sPSActionReference->PutIdentifier(reference, 
										      desiredClassParent, 
										      IDParent);
	if (error) goto returnError;
	
	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	if (desiredKey)
	{
		error = PIUGetSingleItemFromDescriptor(result, 
			                                   desiredKey, 
											   returnData, 
											   returnExtraData);
		if (error) goto returnError;
	} else {
		data = (PIActionDescriptor *)returnData;
		*data = result;
		result = NULL;
	}

returnError:

	if (reference != NULL) sPSActionReference->Free(reference);
	if (result != NULL) sPSActionDescriptor->Free(result);
	
	return error;
}
// end PIUGet.cpp

