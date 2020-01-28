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
//		PIUtilities.cpp
//
//	Description:
//		This library contains sources and functions
//		to simplify the use of suites and also some helpful   
//		common plug-in functions. 
//
//	Use:
//		PIUtilities is intended to group common functions
//		into higher-level macros and routines to simplify
//		plug-in programming.
//
//-------------------------------------------------------------------------------


#include "PIUtilities.h"
#include "DialogUtilities.h"
#if __PIMac__
#include <sys/types.h>
#include <sys/sysctl.h>
#endif


//-------------------------------------------------------------------------------

void PIResetString(unsigned char *string)
{
	if (string != NULL)
	{
		string[0] = '\0';
		string[1] = '\0';
	}
}

//-------------------------------------------------------------------------------

Boolean PISetRect(Rect* pRect, short nLeft, short nTop, short nRight, short nBottom)
{
	if (!pRect)
		return false;
    
	pRect->left = nLeft;
	pRect->top = nTop;
	pRect->right = nRight;
	pRect->bottom = nBottom;
    
	return true;
}

//-------------------------------------------------------------------------------

Boolean PIOffsetRect(Rect* pRect, short xAmt, short yAmt)
{
	if (!pRect)
		return false;
    
	pRect->left = (short)(pRect->left + xAmt);
	pRect->top  = (short)(pRect->top + yAmt);
	pRect->right = (short)(pRect->right + xAmt);
	pRect->bottom = (short)(pRect->bottom + yAmt);
    
	return true;
}

//-------------------------------------------------------------------------------

Handle HostGetPlatformWindowPtr (AboutRecordPtr aboutPtr )
{
	#ifdef __PIWin__
	
		PlatformData * platform = (PlatformData *) (aboutPtr->platformData);
		return (Handle)platform->hwnd;

	#else // Macintosh
	
		// turn off compiler warnings
		aboutPtr = aboutPtr;
		
		return NULL;

	#endif
	
} // end HostGetPlatformWindowPtr

//-------------------------------------------------------------------------------

Boolean HostDisplayPixelsAvailable (DisplayPixelsProc proc)
{
	Boolean	available = TRUE;
	
	if (proc == NULL)
		available = FALSE;
	
	return available;

} // end HostDisplayPixelsAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostDisplayPixelsAvailable (DisplayPixelsProc proc)
{
	Boolean available = HostDisplayPixelsAvailable(proc);
	
	if (!available)
	{
		Str255 minVersion = "";
		
		// Converts a double/float value to a string, with 3 digits of
		// decimal precision:
		DoubleToString(minVersion, 2.502, 3);
		minVersion[ minVersion[0]-1 ] = '.'; // replace the 0 with a "." to make 2.5.2
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created:
		ShowVersionAlert (NULL,
						  AlertID,
						  kNeedVers,
						  minVersion,
						  NULL);
	}
	
	return available;

} // end WarnHostDisplayPixelsAvailable
	
//-------------------------------------------------------------------------------

Boolean HostAdvanceStateAvailable (AdvanceStateProc proc)
{
	Boolean	available = TRUE;
	
	if (proc == NULL)
		available = FALSE;
	
	return available;
	
} // end HostAdvanceStateAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostAdvanceStateAvailable (AdvanceStateProc proc)
{
	Boolean available = HostAdvanceStateAvailable(proc);
	
	if (!available)
	{
		Str255	minVersion = "";
		
		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 3.0, 1);
	
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created:
		ShowVersionAlert (NULL,
						  AlertID,
						  kNeedVers,
						  minVersion,
						  NULL);
	}
	
	return available;

} // end WarnHostAdvanceStateAvailable

//-------------------------------------------------------------------------------

Boolean HostColorServicesAvailable (ColorServicesProc proc)
{
	Boolean	available = TRUE;
	
	if (proc == NULL)
		available = FALSE;
	
	return available;
	
} // end HostColorServicesAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostColorServicesAvailable (ColorServicesProc proc)
{
	Boolean available = HostColorServicesAvailable(proc);
	
	if (!available)
	{
		Str255 minVersion = "";
		
		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 2.5, 1);
	
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created:
		ShowVersionAlert (NULL,
						  AlertID,
						  kNeedVers,
						  minVersion,
						  NULL);
	}

	return available;

} // end WarnHostColorServicesAvailable

//-------------------------------------------------------------------------------

OSErr CSSetColor (int16 *outColor,
	 			  const int16 inColor1,
				  const int16 inColor2,
				  const int16 inColor3,
				  const int16 inColor4)
{
	OSErr err = noErr;
	
	if (outColor != NULL)
	{
		outColor[0] = inColor1;
		outColor[1] = inColor2;
		outColor[2] = inColor3;
		outColor[3] = inColor4;
	}
	else
	{
		err = errMissingParameter;
	}
	
	return err;
	
} // end CSSetColor

//-------------------------------------------------------------------------------

OSErr CSCopyColor (int16 *outColor, const int16 *inColor)
{
	short loop;
	OSErr err = noErr;
	
	if (outColor != NULL && inColor != NULL)
	{
		for (loop = 0; loop < 4; loop++)
		{
			outColor[loop] = inColor[loop];
		}
	}
	else
	{
		err = errMissingParameter;
	}

	return err;

} // end CSCopyColor

//-------------------------------------------------------------------------------

OSErr CSToPicker (unsigned16 *outColor, const int16 *inColor)
{
	short loop;
	OSErr err = noErr;
	
	if (outColor != NULL && inColor != NULL)
	{
		for (loop = 0; loop < 4; loop++)
		{
			outColor[loop] = (unsigned16)(inColor[loop] << 8);
		}
	}
	else
	{
		err = errMissingParameter;
	}

	return err;

} // end CSToPicker

//-------------------------------------------------------------------------------

OSErr CSFromPicker (int16 *outColor, const unsigned16 *inColor)
{
	short loop;
	OSErr err = noErr;
	
	if (outColor != NULL && inColor != NULL)
	{
		for (loop = 0; loop < 4; loop++)
		{
			outColor[loop] = (int16)(inColor[loop] >> 8);
		}
	}
	else
	{
		err = errMissingParameter;
	}

	return err;

} // end CSToPicker

//-------------------------------------------------------------------------------

OSErr HostCSConvertColor (ColorServicesProc proc,
						 const int16 sourceSpace,
						 const int16 resultSpace,
						 int16 *ioColor)
{
	OSErr err = noErr;
	
	if (HostColorServicesAvailable(proc))
	{ // now populate color services info with stuff
		if (ioColor != NULL)
		{ // Parameter good.

			ColorServicesInfo	csinfo;
	
			// Initialize our info structure with default
			// values:
			err = CSInitInfo(&csinfo);
			
			if (err == noErr)
			{ // Init'ed okay.				
			
				// Now override default values with our own.
				
				// (1) Copy original to colorComponents space then
				// set up space to convert from source to result:
				err = CSCopyColor(&csinfo.colorComponents[0], ioColor);
		
				if (err == noErr)
				{ // Copied okay.
					// (2) Set the source and result space:
					csinfo.sourceSpace = sourceSpace;
					csinfo.resultSpace = resultSpace;
					
					// (3) Call the convert routine with this info:
					err = (*proc)(&csinfo);
			
					// (4) If no error, copy the converted colors:
					if (err == noErr)
						CSCopyColor (ioColor, csinfo.colorComponents);
			
				} // copy
				
			} // initinfo

		} // ioColor

		else
		{ // ioColor pointer bad.
			err = errMissingParameter;
		}
	}
	else
	{ // color services suite was not available
		err = errPlugInHostInsufficient;
	}
	
	return err;

} // end HostCSConvertColor

//-------------------------------------------------------------------------------

OSErr HostCSPickColor (ColorServicesProc proc,
					   const Str255 inPrompt,
					   int16 *ioSpace,
					   int16 *ioColor)
{
	OSErr err = noErr;
	
	if (HostColorServicesAvailable(proc))
	{ // now populate color services info with stuff
		if (ioColor != NULL && ioSpace != NULL)
		{ // Parameters good.

			ColorServicesInfo	csinfo;
	
			// Initialize our info structure with default
			// values:
			err = CSInitInfo(&csinfo);
			
			if (err == noErr)
			{ // Init'ed okay.				
			
				// Now override default values with our own.
				
				// (1) Set the selector to choose color:
				csinfo.selector = plugIncolorServicesChooseColor;
				
				// (2) Set the prompt string:
				csinfo.selectorParameter.pickerPrompt = (Str255 *)inPrompt;
				
				// (3) Set the source components:
				csinfo.sourceSpace = *ioSpace;
				CSCopyColor (csinfo.colorComponents, ioColor);
				
				// (4) Call the convert routine with this info:
				err = (*proc)(&csinfo);
			
				// (5) If no error, copy the converted colors
				// and user-picked result space:
				if (err == noErr)
				{
					CSCopyColor (ioColor, csinfo.colorComponents);
					*ioSpace = csinfo.resultSpace;
				} // copy
				
			} // initinfo

		} // outColor and outSpace

		else
		{ // outColor or outSpace pointer bad.
			err = errMissingParameter;
		}
	}
	else
	{ // color services suite was not available
		err = errPlugInHostInsufficient;
	}
	
	return err;

} // end HostCSPickColor

//-------------------------------------------------------------------------------

OSErr CSInitInfo (ColorServicesInfo *ioCSinfo)
{
	OSErr err = noErr;
	
	if (ioCSinfo != NULL)
	{
		CSSetColor(ioCSinfo->colorComponents, 0, 0, 0, 0);
	
		ioCSinfo->selector = plugIncolorServicesConvertColor;
		ioCSinfo->sourceSpace = plugIncolorServicesRGBSpace;
		ioCSinfo->resultSpace = plugIncolorServicesChosenSpace;
		ioCSinfo->reservedSourceSpaceInfo = NULL; // must be null
		ioCSinfo->reservedResultSpaceInfo = NULL; // must be null
		ioCSinfo->reserved = NULL; // must be null
		ioCSinfo->selectorParameter.pickerPrompt = NULL;
		ioCSinfo->infoSize = sizeof(*ioCSinfo);
	}
	else
	{
		err = errMissingParameter;
	}
	
	return err;

} // end CSInitInfo

//-------------------------------------------------------------------------------

Boolean HostBufferProcsAvailable (BufferProcs *procs, Boolean *outNewerVersion)
{
	
	Boolean available = TRUE;		// assume procs are available
	Boolean newerVersion = FALSE;	// assume we're running under correct version
	
	
	// We want to check for this stuff in a logical order, going from things
	// that should always be present to things that "may" be present.  It's
	// always a danger checking things that "may" be present because some
	// hosts may not leave them NULL if unavailable, instead pointing to
	// other structures to save space.  So first we'll check the main
	// proc pointer, then the version, the number of routines, then some
	// of the actual routines:
	
	if (procs == NULL)
	{
		available = FALSE;
	}	
	else if (procs->bufferProcsVersion < kCurrentBufferProcsVersion)
	{
		available = FALSE;
	}	
	else if (procs->bufferProcsVersion > kCurrentBufferProcsVersion)
	{	
		available = FALSE;
		newerVersion = TRUE;	
	}	
	else if (procs->numBufferProcs < kCurrentBufferProcsCount)
	{
		available = FALSE;
	}
	else if (procs->allocateProc == NULL ||
			 procs->lockProc == NULL ||
			 procs->unlockProc == NULL ||
			 procs->freeProc == NULL ||
			 procs->spaceProc == NULL ||
			 procs->reserveProc == NULL ||
			 procs->allocateProc64 == NULL ||
			 procs->spaceProc64 == NULL)
	{
		available = FALSE;
	}
		
	if (newerVersion && (outNewerVersion != NULL))
		*outNewerVersion = newerVersion;
		
	return available;
	
} // end HostBufferProcsAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostBufferProcsAvailable (BufferProcs *procs)
{
	
	Boolean newerVersion = FALSE;
	Boolean available = HostBufferProcsAvailable (procs, &newerVersion);
	
	if (!available)
	{
		Str255 	minVersion = "";
		short	errStringID = kNeedVers;
		
		// If we need a later version of the suite, pop a dialog
		// saying we have the wrong host (who *knows* what version):
		if (newerVersion)
			errStringID = kWrongHost;

		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 2.5, 1);
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created, or one saying "This is the
		// wrong host":
		ShowVersionAlert (NULL,
						  AlertID,
						  errStringID,
						  minVersion,
						  NULL);
	}
			
	return available;
	
} // end WarnHostBufferProcsAvailable

//-------------------------------------------------------------------------------

int32 HostBufferSpace (BufferProcs *procs)
{
	
	if (HostBufferProcsAvailable (procs, NULL))
		return (*procs->spaceProc) ();	
	else
		return 0;
	
} // end HostBufferSpace

//-------------------------------------------------------------------------------

int64 HostBufferSpace64 (BufferProcs *procs)
{
	
	if (HostBufferProcsAvailable (procs, NULL))
		return (*procs->spaceProc64) ();	
	else
		return 0;
	
} // end HostBufferSpace

//-------------------------------------------------------------------------------

OSErr HostAllocateBuffer (BufferProcs *procs, const int32 inSize, BufferID *outBufferID)
{
	
	*outBufferID = 0;
	
	if (HostBufferProcsAvailable (procs, NULL))
		return (*procs->allocateProc) (inSize, outBufferID);
	else
		return memFullErr;
	
} // end HostAllocateBuffer

//-------------------------------------------------------------------------------

OSErr HostAllocateBuffer64 (BufferProcs *procs, const int64 inSize, BufferID *outBufferID)
{
	
	*outBufferID = 0;
	
	if (HostBufferProcsAvailable (procs, NULL))
		return (*procs->allocateProc64) (inSize, outBufferID);
	else
		return memFullErr;
	
} // end HostAllocateBuffer64

//-------------------------------------------------------------------------------

void HostFreeBuffer (BufferProcs *procs, const BufferID inBufferID)
{
	
	if (HostBufferProcsAvailable (procs, NULL))
		(*procs->freeProc) (inBufferID);
	
} // end HostFreeBuffer

//-------------------------------------------------------------------------------

Ptr HostLockBuffer (BufferProcs *procs, 
					const BufferID inBufferID, 
					Boolean inMoveHigh)
{
	
	if (HostBufferProcsAvailable (procs, NULL))
		return (*procs->lockProc) (inBufferID, inMoveHigh);
	else
		return NULL;
	
} // end HostLockBuffer

//-------------------------------------------------------------------------------

void HostUnlockBuffer (BufferProcs *procs,
					   const BufferID inBufferID)
{
	
	if (HostBufferProcsAvailable (procs, NULL))
		(*procs->unlockProc) (inBufferID);
	
} // end HostUnlockBuffer

//-------------------------------------------------------------------------------

OSErr HostAllocateStripBuffer (BufferProcs *procs,
							   const int32 inRowBytes,
							   const int16 inMinHeight,
							   const int16 inMaxHeight,
							   const int16 inNumBuffers,
							   int16 *outActualHeight,
							   BufferID *outBufferID)
{

	//---------------------------------------------------------------------------
	//	(1) Allocate and set-up our parameters
	//---------------------------------------------------------------------------

	OSErr err = noErr;

	int32 size;

	const int32 availableSpace = HostBufferSpace (procs) / inNumBuffers;	
	const int32 availableHeight = availableSpace / inRowBytes;
	
	int32 height = (int32)inMaxHeight;
	
	// If we don't have enough space for the maximum height,
	// use what is available:
	if (availableHeight < inMaxHeight)
		height = availableHeight;
		
	height++; // we'll need one extra iteration
	
	*outBufferID = NULL;

	size = inRowBytes * height;
	
	
	//---------------------------------------------------------------------------
	//	(2) Iterate down from maximum height to minimum height,
	//		attempting to allocate a buffer each time until successful.
	//		(Hopefully should happen on the very first iteration.)
	//---------------------------------------------------------------------------
	
	while (!*outBufferID && height > inMinHeight)
	{
		
		height--;
		size -= inRowBytes;
		
		err = HostAllocateBuffer (procs, size, outBufferID);
		
	}
		
	if (*outBufferID != NULL)
		*outActualHeight = (int16)height; // report height we ended up with
		
	return err;
	
} // end HostAllocateStripBuffer

//-------------------------------------------------------------------------------

Boolean HostResourceProcsAvailable (ResourceProcs *procs, Boolean *outNewerVersion)
{
	
	Boolean available = TRUE;		// assume procs are available
	Boolean newerVersion = FALSE;	// assume we're running under correct version
	
	// We want to check for this stuff in a logical order, going from things
	// that should always be present to things that "may" be present.  It's
	// always a danger checking things that "may" be present because some
	// hosts may not leave them NULL if unavailable, instead pointing to
	// other structures to save space.  So first we'll check the main
	// proc pointer, then the version, the number of routines, then some
	// of the actual routines:

	if (procs == NULL)
	{
		available = FALSE;
	}	
	else if (procs->resourceProcsVersion < kCurrentResourceProcsVersion)
	{
		available = FALSE;
	}	
	else if (procs->resourceProcsVersion > kCurrentResourceProcsVersion)
	{	
		available = FALSE;	
		newerVersion = TRUE;
	}
	else if (procs->numResourceProcs < kCurrentResourceProcsCount)
	{
		available = FALSE;
	}	
	else if (procs->countProc == NULL ||
			 procs->getProc == NULL ||
			 procs->deleteProc == NULL ||
			 procs->addProc == NULL)
	{
		available = FALSE;
	}
		
	if (newerVersion && (outNewerVersion != NULL))
		*outNewerVersion = newerVersion;
		
	return available;
	
} // end HostResourceProcsAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostResourceProcsAvailable (ResourceProcs *procs)
{
	
	Boolean newerVersion = FALSE;
	Boolean available = HostResourceProcsAvailable (procs, &newerVersion);
	
	if (!available)
	{
		Str255 	minVersion = "";
		short	errStringID = kNeedVers;
		
		// If we need a later version of the suite, pop a dialog
		// saying we have the wrong host (who *knows* what version):
		if (newerVersion)
			errStringID = kWrongHost;

		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 3.0, 1);
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created, or one saying "This is the
		// wrong host":
		ShowVersionAlert (NULL,
						  AlertID,
						  errStringID,
						  minVersion,
						  NULL);
	}
			
	return available;
	
} // end WarnHostResourceProcsAvailable

//-------------------------------------------------------------------------------

int16 HostCountPIResources (ResourceProcs *procs,
							const ResType inType)
{
	if (HostResourceProcsAvailable (procs, NULL))
		return (*procs->countProc) (inType);
	else
		return 0;
	
} // end HostCountPIResources
	
//-------------------------------------------------------------------------------

Handle HostGetPIResource (ResourceProcs *procs,
						  const ResType inType,
						  const int16 inIndex)
{
	if (HostResourceProcsAvailable (procs, NULL))
		return (*procs->getProc) (inType, inIndex);		
	else
		return NULL;

} // end HostGetPIResource

//-------------------------------------------------------------------------------

void HostDeletePIResource (ResourceProcs *procs,
						   const ResType inType,
						   const int16 inIndex)
{	
	if (HostResourceProcsAvailable (procs, NULL))
		(*procs->deleteProc) (inType, inIndex);

} // end HostDeletePIResource

//-------------------------------------------------------------------------------

OSErr HostAddPIResource (ResourceProcs *procs,
						 const ResType inType,
						 const Handle inDataHandle)
{
	
	if (HostResourceProcsAvailable (procs, NULL))
		return (*procs->addProc) (inType, inDataHandle);
	else
		return memFullErr;
			
} // end HostAddPIResource

//-------------------------------------------------------------------------------

Boolean WarnHostHandleProcsAvailable (HandleProcs *procs)
{
	Boolean newerVersion = FALSE;
	Boolean available = HostHandleProcsAvailable (procs, &newerVersion);
	
	if (!available)
	{
		Str255 	minVersion = "";
		short	errStringID = kNeedVers;
		
		// If we need a later version of the suite, pop a dialog
		// saying we have the wrong host (who *knows* what version):
		if (newerVersion)
			errStringID = kWrongHost;

		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 3.0, 1);
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created, or one saying "This is the
		// wrong host":
		ShowVersionAlert (NULL,
						  AlertID,
						  errStringID,
						  minVersion,
						  NULL);
	}
			
	return available;
	
} // end WarnHostHandleProcsAvailable

//-------------------------------------------------------------------------------

size_t HostGetHandleSize (HandleProcs *procs, Handle h)
{
	
	if (HostHandleProcsAvailable (procs, NULL))
		return (*procs->getSizeProc) (h);
	else
        return 0;
	
} // end HostGetHandleSize

//-------------------------------------------------------------------------------

OSErr HostSetHandleSize (HandleProcs *procs,
						 Handle h,
						 const size_t inNewSize)
{
	
	if (HostHandleProcsAvailable (procs, NULL))
		return (*procs->setSizeProc) (h, Convert_size_t_to_int32(inNewSize));
	else
        return errPlugInHostInsufficient;
	
} // end HostSetHandleSize

//-------------------------------------------------------------------------------

void HostHandle2CString(HandleProcs *procs,
					   Handle inDataHandle, 
					   char *outString,
					   const size_t outMaxSize)
{
	PIResetString((unsigned char *)outString); // macro to clear a string. See header file.
	
	if (inDataHandle != NULL)
	{ // inDataHandle is valid.
	
		Ptr p = HostLockHandle(procs, inDataHandle, FALSE);
		
		if (p != NULL)
		{ // Got a valid pointer.
		
			size_t size = HostGetHandleSize(procs, inDataHandle);
			
			if (size >= outMaxSize-1)
				size = outMaxSize-1; // Have to pin to maximum string length.
			
			// Append handle to string:
			PICopy(outString, p, size);
			outString[size+1] = '\0';

		} // p
		
		HostUnlockHandle(procs, inDataHandle); // Done copying.  Let it move.
		
	} // inDataHandle
	
} // end HostHandle2CString

//-------------------------------------------------------------------------------

void HostHandle2PString(HandleProcs *procs,
					    Handle inDataHandle, 
					    Str255 outString)
{
	PIResetString(outString); // macro to clear a string. See header file.
	
	if (inDataHandle != NULL)
	{ // inDataHandle is valid.
	
		Ptr p = HostLockHandle(procs, inDataHandle, FALSE);
		
		if (p != NULL)
		{ // Got a valid pointer.
		
			size_t size = HostGetHandleSize(procs, inDataHandle);
			
			if (size > 254)
				size = 254; // Have to pin to maximum string length.
			
			// Append handle to string:
			AppendString(outString, (unsigned char *)p, 0, (short)size);
		
		} // p
		
		HostUnlockHandle(procs, inDataHandle); // Done copying.  Let it move.
		
	} // inDataHandle
	
} // end HostHandle2PString
	
//-------------------------------------------------------------------------------

Handle HostCString2Handle(HandleProcs *procs, const char *inString)
{
	const size_t len = PIstrlen(inString);
	Handle	h = HostNewHandle(procs, len);
	
	if (h != NULL)
	{ // Succeeded in creating the handle.  Now copy the data:

		Ptr p = HostLockHandle(procs, h, FALSE);

		// If we created a valid pointer, use our copy routine
		// to transfer data of a specified length (s[0]):
		if (p != NULL)
		{
			HostCopy(p, inString, len);
			
			HostUnlockHandle(procs, h); // Release so it can move.
		}
	}

	return h; // Handle we created or NULL

} // end HostCString2Handle

//-------------------------------------------------------------------------------

Handle HostPString2Handle(HandleProcs *procs, const Str255 inString)
{
	Handle	h = HostNewHandle(procs, inString[0]); // [0] is length
	
	if (h != NULL)
	{ // Succeeded in creating the handle.  Now copy the data:

		Ptr p = HostLockHandle(procs, h, FALSE);

		// If we created a valid pointer, use our copy routine
		// to transfer data of a specified length (s[0]):
		if (p != NULL)
		{
			HostCopy(p, &inString[1], inString[0]);
			
			HostUnlockHandle(procs, h); // Release so it can move.
		}
	}

	return h; // Handle we created or NULL

} // end HostPString2Handle

//-------------------------------------------------------------------------------

void HostHandle2VersionString(HandleProcs *procs,
					          Handle inDataHandle, 
					          Str255 outString)
{
    int32 major = 0;
    int32 minor = 0;
    int32 fix = 0;

	Str255 temp;
    
    temp[0] = 0;
    temp[1] = 0;
    
	Str255 dot;
	
	dot[0] = 1;
	dot[1] = '.';

	PIResetString(outString); // macro to clear a string. See header file.

	HostHandle2Version(procs, inDataHandle, &major, &minor, &fix);

	// apple recommends CFStringCreateWithFormat
	NumToString(major, temp);
	AppendString(outString, temp, 1, temp[0]); 
	AppendString(outString, dot, 1, dot[0]); 
	
	// apple recommends CFStringCreateWithFormat
	NumToString(minor, temp);
	AppendString(outString, temp, 1, temp[0]); 
	AppendString(outString, dot, 1, dot[0]); 

	// apple recommends CFStringCreateWithFormat
	NumToString(fix, temp);
	AppendString(outString, temp, 1, temp[0]); 
	
} // end HostHandle2VersionString
	
//-------------------------------------------------------------------------------

void HostHandle2Version (HandleProcs *procs,
						 Handle inDataHandle,
						 int32 *major,
						 int32 *minor,
						 int32 *fix)
{
	if (inDataHandle != NULL && major != NULL && minor != NULL && fix != NULL)
	{ // all params are valid.
	
		*major = *minor = *fix = 0;
		
		Ptr p = HostLockHandle(procs, inDataHandle, FALSE);
		
		if (p != NULL)
		{ // Got a valid pointer.
		
			size_t size = HostGetHandleSize(procs, inDataHandle);
			
			// this should be 3 int32's for 12 bytes
			if (size < 12)
                return;
			
			int32 * pData = (int32*)p;
			*major = *pData;
			pData++;
			*minor = *pData;
			pData++;
			*fix = *pData;		
			#ifdef __PIWin__
				Swap(*major);
				Swap(*minor);
				Swap(*fix);
			#endif
		}
		
		HostUnlockHandle(procs, inDataHandle); // Done copying.  Let it move.
		
	} // all params are valid.
	
} // end HostHandle2Version

//-------------------------------------------------------------------------------

OSErr HostHandleCat(HandleProcs *procs,
					 Handle *outHandle,
					 const Handle inHandle)
{
	OSErr err = noErr;
	
	const size_t inHandleSize = HostGetHandleSize(procs, inHandle);
	
	if (inHandleSize > 0)
	{ // Don't bother doing this if there's no data in there.
		size_t outHandleSize = 0;
	
		if (outHandle == NULL)
		{ // We're expecting a valid handle, and we didn't even get
		  // that.  Return an error.
		  err = paramErr;
		}
		else
		{
			if (*outHandle == NULL)
			{ // outHandle needs to be created:
				*outHandle = HostNewHandle(procs, inHandleSize);
			}
			else
			{ // outHandle exists.  Grow handle:
				outHandleSize = HostGetHandleSize(procs, *outHandle);
				HostSetHandleSize(procs, *outHandle, outHandleSize + inHandleSize);
			}
		
			if (*outHandle != NULL)
			{ // We either just created a valid handle or already had one:
					
				Ptr outHandlePtr = HostLockHandle(procs, *outHandle, true);
				const Ptr inHandlePtr = HostLockHandle(procs, inHandle, true);
				
				if (outHandlePtr != NULL && inHandlePtr != NULL)
				{ // Have valid pointers.  Copy to end:
					HostCopy(&outHandlePtr[outHandleSize],
							 inHandlePtr,
							 inHandleSize);
				}
				
				// Unlock the handles so they can move:
				HostUnlockHandle(procs, *outHandle);
				HostUnlockHandle(procs, inHandle);

			} // *outHandle

		} // outHandle

	} // inHandleSize

	return err;

} // end HostHandleCat

//-------------------------------------------------------------------------------

OSErr HostHandleCopy(HandleProcs *procs,
					 Handle *outHandle,
					 const Handle inHandle)
{
	OSErr err = noErr;
	
	// We're expecting outHandle to point to a valid Handle variable.
	if (outHandle == NULL)
	{
		err = paramErr;
	}	
	else
	{
		// We're expecting a NULL outHandle that we can fill.  If it's not null,
		// there's a danger in leaking memory so we'll just return an error:
		if (*outHandle != NULL)
		{
			err = paramErr;
		}
		else
		{
			err = HostHandleCat(procs, outHandle, inHandle);
		}
	}
	
	return err;
	
} // end HostHandleCopy

//-------------------------------------------------------------------------------

void PIType2Char (const ResType inType, char *outChars)
{
	int8 loopType, loopChar;
	
	// Figure out which byte we're dealing with and move it
	// to the highest character, then mask out everything but
	// the lowest byte and assign that as the character:
	for (loopType = 0, loopChar = 3; loopType < 4; loopType++, loopChar--)
		outChars[loopChar] = (char) ( (inType >> (8*loopType)) & 0xFF );
	
	outChars[loopType] = '\0';

} // end PIType2Char

//-------------------------------------------------------------------------------

ResType PIChar2Type (const char *inChars)
{
	unsigned short loop;
	ResType outType = 0;
	
	for (loop = 0; loop < 4; loop++)
	{
		outType <<= 8; // bits per char
		outType |= inChars[loop];
	}

	return outType;

} // end PIChar2Type

//-------------------------------------------------------------------------------

Boolean HostPropertyAvailable (PropertyProcs *procs, Boolean *outNewerVersion)
{
	
	Boolean available = TRUE;		// assume procs are available
	Boolean newerVersion = FALSE;	// assume we're running under correct version
	
	// We want to check for this stuff in a logical order, going from things
	// that should always be present to things that "may" be present.  It's
	// always a danger checking things that "may" be present because some
	// hosts may not leave them NULL if unavailable, instead pointing to
	// other structures to save space.  So first we'll check the main
	// proc pointer, then the version, the number of routines, then some
	// of the actual routines:
	
	if (procs == NULL)
	{
		available = FALSE;
	}	
	else if (procs->propertyProcsVersion < kCurrentPropertyProcsVersion)
	{
		available = FALSE;
	}	
	else if (procs->propertyProcsVersion > kCurrentPropertyProcsVersion)
	{
		available = FALSE;
		newerVersion = TRUE;
	}
	else if (procs->numPropertyProcs < kCurrentPropertyProcsCount)
	{
		available = FALSE;
	}	
	else if (procs->getPropertyProc == NULL ||
			 procs->setPropertyProc == NULL)
	{
		available = FALSE;
	}
		
	if (newerVersion && (outNewerVersion != NULL))
		*outNewerVersion = newerVersion;
		
	return available;
	
} // end HostPropertyAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostPropertyAvailable (PropertyProcs *procs)
{
	Boolean newerVersion = FALSE;
	Boolean available = HostPropertyAvailable (procs, &newerVersion);
	
	if (!available)
	{
		Str255 	minVersion = "";
		short	errStringID = kNeedVers;
		
		// If we need a later version of the suite, pop a dialog
		// saying we have the wrong host (who *knows* what version):
		if (newerVersion)
			errStringID = kWrongHost;

		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 2.5, 1);
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created, or one saying "This is the
		// wrong host":
		ShowVersionAlert (NULL,
						  AlertID,
						  errStringID,
						  minVersion,
						  NULL);
	}
			
	return available;
	
} // end WarnHostPropertyProcsAvailable

//-------------------------------------------------------------------------------

Boolean HostChannelPortAvailable (ChannelPortProcs *procs, Boolean *outNewerVersion)
{
	
	Boolean available = TRUE;		// assume procs are available
	Boolean newerVersion = FALSE;	// assume we're running under correct version
	
	// We want to check for this stuff in a logical order, going from things
	// that should always be present to things that "may" be present.  It's
	// always a danger checking things that "may" be present because some
	// hosts may not leave them NULL if unavailable, instead pointing to
	// other structures to save space.  So first we'll check the main
	// proc pointer, then the version, the number of routines, then some
	// of the actual routines:

	if (procs == NULL)
	{
		available = FALSE;
	}	
	else if (procs->channelPortProcsVersion < kCurrentChannelPortProcsVersion)
	{
		available = FALSE;
	}	
	else if (procs->channelPortProcsVersion > kCurrentChannelPortProcsVersion)
	{	
		available = FALSE;	
		newerVersion = TRUE;
	}
		
	else if (procs->numChannelPortProcs < kCurrentChannelPortProcsCount)
	{
		available = FALSE;
	}
	else if (procs->readPixelsProc == NULL ||
			 procs->writeBasePixelsProc == NULL ||
			 procs->readPortForWritePortProc == NULL)
	{
		available = FALSE;
	}	
	
	if (newerVersion && outNewerVersion != NULL)
		*outNewerVersion = newerVersion;
		
	return available;
	
} // end HostChannelPortAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostChannelPortAvailable (ChannelPortProcs *procs)
{
	
	Boolean newerVersion = FALSE;
	Boolean available = HostChannelPortAvailable (procs, &newerVersion);
	
	if (!available)
	{
		Str255 	minVersion = "";
		short	errStringID = kNeedVers;
		
		// If we need a later version of the suite, pop a dialog
		// saying we have the wrong host (who *knows* what version):
		if (newerVersion)
			errStringID = kWrongHost;

		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 4.0, 1);
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created, or one saying "This is the
		// wrong host":
		ShowVersionAlert (NULL,
						  AlertID,
						  errStringID,
						  minVersion,
						  NULL);
	}
			
	return available;
	
} // end WarnHostChannelPortAvailable

//-------------------------------------------------------------------------------

Boolean WarnHostDescriptorAvailable (PIDescriptorParameters *procs)
{
	Boolean newerVersion = FALSE;
	Boolean available = HostDescriptorAvailable (procs, &newerVersion);
	
	if (!available)
	{
		Str255 	minVersion = "";
		short	errStringID = kNeedVers;
		
		// If we need a later version of the suite, pop a dialog
		// saying we have the wrong host (who *knows* what version):
		if (newerVersion)
			errStringID = kWrongHost;

		// Converts a double/float value to a string, with 1 digit of
		// decimal precision:
		DoubleToString(minVersion, 4.0, 1);
		
		// Use our routine to pop a dialog saying "Sorry, need host
		// version ^0 or better" where ^0 will be replaced by the
		// string we just created, or one saying "This is the
		// wrong host":
		ShowVersionAlert (NULL,
						  AlertID,
						  errStringID,
						  minVersion,
						  NULL);
	}
			
	return available;
	
} // end WarnHostDescriptorAvailable

//-------------------------------------------------------------------------------

OSErr HostPutObj (PIDescriptorParameters *procs,
				  HandleProcs *hProcs, 
				  PIWriteDescriptor token,
				  DescriptorKeyID key,
				  DescriptorTypeID type,
				  PIDescriptorHandle *h)
{
	OSErr		err = noErr;
	
	err = procs->writeDescriptorProcs->putObjectProc(token, key, type, *h);

	if (err == noErr)
	{
		HostDisposeHandle(hProcs, *h);
		*h = NULL;
	}
	
	return err;
	
} // end HostPutObj

//-------------------------------------------------------------------------------

void DivideAtDecimal(Str255 ioWhole, Str255 outDecimal)
{ 
	short	loop = ioWhole[0];
	
	do
	{
		// Some countries use ',' as decimal, so check for either:
		
		if (ioWhole[loop] == '.' || ioWhole[loop] == ',')
		{ // found the decimal point.  Now right side data to out string:
		
			AppendString(outDecimal,
						 ioWhole, 
						 (short)(loop+1), 
						 (short)(ioWhole[0] - loop));

			if ( outDecimal[0] >= kStr255MaxLen ) 
				outDecimal[0]--;

			outDecimal[ 1+outDecimal[0] ] = 0; // null terminate
			
			ioWhole[0] = (unsigned char)(loop-1); // shorten string
			ioWhole[ loop ] = 0; // null terminate
			
			loop = 1; // exit loop
		
		} // ioWhole
		
		loop--;
	
	} while (loop > 0);
	
} // end DivideAtDecimal
	
//-------------------------------------------------------------------------------

void AppendString (Str255 outTarget,
				   const Str255 inSource,
				   short inSourceStart,
				   short inLength)
{
	
	// If we're going to go over our 255 pascal string length, then
	// back up inLength bytes and start there:
	if ( (outTarget[0] + (inLength - inSourceStart)) > kStr255MaxLen)
		inLength = (short)((kStr255MaxLen + inSourceStart) - outTarget[0]);

	for ( ; inLength > 0; inLength--)
		outTarget[ ++outTarget[0] ] = inSource[inSourceStart++];

	if (outTarget[0] >= kStr255MaxLen)
		outTarget[0]--; // Back off one char for null:

	outTarget[ (outTarget[0]+1) ] = 0; // null terminate

} // end AppendString

//-------------------------------------------------------------------------------

void AppendCharToString (Str255 outString, const unsigned char c)
{
	if (outString[0] < kStr255MaxLen)
		outString[ ++outString[0] ] = c;

	if (outString[0] >= kStr255MaxLen)
		outString[0]--;	// Blast over last character

	outString[ 1+outString[0] ] = 0; // null terminate

} // end AppendCharToString

//-------------------------------------------------------------------------------

void HostBlockMove (Ptr outTarget,
					const Ptr inSource,
					const size_t inLength)
{
	size_t loop;
	
	if (outTarget != NULL && inSource != NULL)
	{
		for (loop = 0; loop < inLength; loop++)
			*(outTarget++) = *(inSource+loop);
	}
	
} // end HostBlockMove

//-------------------------------------------------------------------------------

void HostCopy (void *outTarget, const void *inSource, const size_t inLength)
{
	// Recast and use the existing block move routine:
	HostBlockMove((Ptr)outTarget, (Ptr)inSource, inLength);

} // end HostCopy

//-------------------------------------------------------------------------------

int16 PIstrlen (const char *inString)
{
		int16	outLength = 0;
		
		while (inString[outLength] != 0 && outLength < SHRT_MAX)
			outLength++;
		
		return outLength;
		
} // end PIstrlen

//-------------------------------------------------------------------------------

size_t PIstrlcat(char *inDest, const char *inSrc, size_t inDestLen)
{
	char *dPtr = inDest;
	const char *sPtr = inSrc;
	size_t nLen = inDestLen;
	size_t dlen;

	while (nLen-- != 0 && *dPtr != '\0') 
		dPtr++;
	dlen = dPtr - inDest;
	nLen = inDestLen - dlen;

	if (nLen == 0) 
		return(dlen + strlen(sPtr));
	while (*sPtr != '\0') {
		if (nLen != 1) {
			*dPtr++ = *sPtr;
			nLen--;
		}
		sPtr++;
	}
	*dPtr = '\0';

	return(dlen + (sPtr - inSrc));
}

//-------------------------------------------------------------------------------

int16 HostStringCat (char *outTarget, const char *inSource)
{
	int16	outLength = PIstrlen(outTarget);
	int16	loop = 0;
	
	while (outLength < SHRT_MAX && inSource[loop] != 0)
		outTarget[outLength++] = inSource[loop++];
		
	outTarget[outLength] = 0; // null terminate
	
	return outLength;
	
} // end HostStringCat

//-------------------------------------------------------------------------------

char UpperToLower(const char inChar)
{
	char	outChar = inChar;
	
	if (inChar >= 'A' && inChar <= 'Z')
		outChar = (char)((inChar - 'A') + 'a');

	return outChar;
	
} // end UpperToLower
	
//-------------------------------------------------------------------------------

int16 HostMatch(const char *inSearch,
				const char *inTarget,
				const Boolean ignoreCase,
				const int16 inLength)
{
	const int16	targetSize = PIstrlen(inTarget);
	
	int16			loop = 0;
	int16			start = 0;

	
	int16	outMatch = noMatch;

	Boolean	done = false;

	while (!done)
	{
		if (inSearch[loop] == inTarget[start] || 
		   (ignoreCase &&
		   (UpperToLower(inSearch[loop]) == UpperToLower(inTarget[start]))))
		{ // we found a match, this is the character it started at:
			if (outMatch < 0)
				outMatch = loop;

			start++;
		}
		else
		{ // reset:
		
			outMatch = noMatch;
			start = 0;
		}

		loop++;

		// we're done if we've hit a null and we've found a match,
		// or if we've hit a null and we're under 256 chars (standard)
		// or we're over the length:
		done = (inSearch[loop] == 0 && start >= targetSize) ||
			   (inSearch[loop] == 0 && inLength <= kStr255MaxLen) ||
			   (loop > inLength);

	} // while !done

	if (inSearch[loop] > 0)
		outMatch = noMatch; // didn't match exactly because the NULL
							// terminator would have matched up, too.

	return outMatch;
	
} // end HostMatch	

//-------------------------------------------------------------------------------

int16 HostStringMatch(Str255 inSearch, 
					  const char *inTarget,
					  const Boolean ignoreCase)
{
	if (inSearch[0] >= kStr255MaxLen)
		inSearch[0]--; // Blast over last character

	inSearch[ inSearch[0]+1 ] = 0;

	return HostMatch((char *)&inSearch[1], inTarget, ignoreCase, inSearch[0]);

} // end HostStringMatch

//-------------------------------------------------------------------------------

double power (const uint32 inBase, const uint16 inRaise)
{
	double outPower = 1;
	short loop;
	
	for (loop = 0; loop < inRaise; loop++)
		outPower *= inBase;

	return outPower;
}

//-------------------------------------------------------------------------------

void DoubleToString (Str255 outString,
					 double inValue,
					 short inPrecision)
{
	unsigned32	x = 0;
	double		y = 0;
	Boolean		negative = (inValue < 0);
	
	PIResetString(outString);
	
	if (negative)
		inValue = -inValue; // get rid of negative number
	
	// determine if we need to round:
	y = inValue * power(10, inPrecision);
	
	x = (unsigned32)y; // whole portion;
	y -= x; // subtract whole portion
	y *= 10; // move over one more place
	
	// Round:
	if (y >= 5)
		inValue += (5.0 / (double)power(10, (short)(inPrecision+1)));
	
	if (inPrecision > 1)
	{ // now check to see if we can lose a decimal place

		y = inValue * power(10, (short)(inPrecision-1));

		x = (unsigned32)y; // whole portion
		y -= x; // subtract whole portion
		y *= 10; // number of interest

		// our number of interest is zero, so lose a point of precision:
		if (y < 1)
			inPrecision--;
			
	} // inPrecision
	
	if (negative)
		x = (unsigned long)-inValue; // whole number portion
	else
		x = (unsigned long)inValue;

	// Convert basic number:
	
	NumToString((int32)x, outString);
	
	outString[++outString[0]] = '.'; // add decimal point
	
	inValue -= (unsigned32)inValue; // get rid of whole-number portion

	do
	{ // add each character for the decimal values:
	
		inValue *= 10;
		x = (unsigned32)inValue; // whole number
		outString[++outString[0]] = (unsigned char)('0' + (char)(x));
		inValue -= x;

	} while (inValue > 0 && --inPrecision > 0);

} // end DoubleToString

//-------------------------------------------------------------------------------

StringToNumberResult_t StringToNumber (Str255 s, int32* value)
{

    short i = 1;
    short j = 0;
	int32 x = 0;
	Boolean negative = FALSE;
	Boolean isNumber = TRUE;
	Boolean trailingBlanks = FALSE;
	StringToNumberResult_t result = kStringToNumberInvalid;
	
	for (i = 1, j = 0; i <= s[0] && isNumber; ++i)
	{
		
		if (j == 0 && s [i] == ' ')
			; /* Do nothing: Leading blanks */
			
		else if (j > 0 && s [i] == ' ')
			trailingBlanks = TRUE;
			
		else if (trailingBlanks && s [i] != ' ')
			isNumber = FALSE;
			
		else if (j == 0 && !negative && s [i] == '-')
			negative = TRUE;
			
		else if (s [i] < '0' || s [i] > '9')
			isNumber = FALSE;
			
		else
			s [++j] = s [i];
		
	} // for i
		
	if (j == 0 && !negative)
		isNumber = FALSE;
	else
		s[ (s[0] = (char) j)+1] = 0;
	
	if (isNumber)
	{
		
		if (j <= 9)
		{
			#ifdef __PIWin__
			
				x = atol((const char *)&s[1]);
			
			#else // Mac
			// Recommended function is now CFStringGetIntValue
				StringToNum (s, &x);
			
			#endif
		}
		else
		{ // j > 9
		
			x = 0x7FFFFFFF;
		}
		
		if (negative)
			x = -x;
			
		*value = x; // return value found
			
	} // isNumber
		
	if (isNumber)
		{
		if (negative)
			result = kStringToNumberNegative;
		else
			result = kStringToNumberValid;
		}
	
	return result;
	
} // end StringToNumber
	
//-------------------------------------------------------------------------------

StringToNumberResult_t StringToDouble (Str255 s1, double *value)
	{
	Str255 s2 = ""; 		// string to receive decimal number portion
		
	int32 x1 = 0;			// initial whole number
	int32 x2 = 0;			// initial decimal portion
	
	StringToNumberResult_t result = kStringToNumberInvalid;

	// A flag set to track whether whole, decimal, or all of the
	// text returned was a number or not:
	StringToNumberResult_t wholeNumberResult = kStringToNumberInvalid;
	StringToNumberResult_t decimalNumberResult = kStringToNumberInvalid;
	Boolean isANumber = false;
		
	// Our routine to find the decimal point (period ".") and divide
	// from that on into a separate string (truncating string1):
	DivideAtDecimal(s1, s2);

	// Convert the whole portion. Will return TRUE if successful:
	wholeNumberResult = StringToNumber (s1, &x1);
	
	// Convert the decimal portion. Will return TRUE if successful:
	decimalNumberResult = StringToNumber (s2, &x2);
	
	// Only if both error flags are set to do we need to
	// return that no valid number was found:
	isANumber = 
		(
		wholeNumberResult != kStringToNumberInvalid || 
		decimalNumberResult != kStringToNumberInvalid
		);
	
	
	if (isANumber)
	{	// We did get a valid number (or part of one).  Continue.
		// Here we do a little bit of swanky math to turn the decimal
		// portion into its decimal representation (by dividing it
		// by a power of ten equal to its length) and then add
		// that to the whole portion.  If x1 is less than zero,
		// subtract from the whole portion:
		
		if (
			x1 < 0 || 
			wholeNumberResult == kStringToNumberNegative ||
			decimalNumberResult == kStringToNumberNegative
			)
			{
			result = kStringToNumberNegative;
			*value = (double)x1 - ((double)x2 / (double)power(10, s2[0]));
			}
		else
			{
			result = kStringToNumberValid;
			*value = (double)x1 + ((double)x2 / (double)power(10, s2[0]));
			}

		return result;
	}
	else
	{ // wasn't a number, don't set value!

		return result;
	} // end notANumber
}

//-------------------------------------------------------------------------------

void PIParamText(unsigned char *s,
				 unsigned char *r0,
				 unsigned char *r1, 
				 unsigned char *r2)
{
	short	loop = 0;
	Boolean	flag = false;
	Str255 s1 = "";
	Str255 rx = "";
	
	while (loop < s[0])
	{
		loop++;
		
		if (s[loop] == '^') flag = true;
		else if (s[loop] >= '0' && s[loop] <= '2' && flag)
		{
			flag = false;
			switch (s[loop])
			{
				case '0':	// Replace occurrences of "^0":
					if (r0[0] > 0) // If provided, copy to rx:
						AppendString(rx, r0, 1, (short)(r0[0]));
					else 
						PIResetString(rx); // Nope, reset rx.
					break;
				case '1':	// Replace occurrences of "^1":
					if (r1[0] > 0) // If provided, copy to rx:
						AppendString(rx, r1, 1, (short)(r1[0]));
					else 
						PIResetString(rx); // Nope, reset rx.
					break;
				case '2':	// Replace occurrences of "^2":
					if (r2[0] > 0) // If provided, copy to rx:
						AppendString(rx, r2, 1, (short)(r2[0]));
					else 
						PIResetString(rx); // Nope, reset rx.
					break;
			
			} // switch
			
			// Make a copy of everything before the "^n":
			AppendString(s1, s, 1, (short)(loop-2));
			
			if (rx[0] > 0) // We do have to replace, so copy that:
				AppendString(s1, rx, 1, (short)rx[0]);
			
			// Now copy the remainder of the string to the end:
			AppendString(s1, s, (short)(loop+1), (short)(s[0]-loop));
			
			// Reset then copy to the original string:
			PIResetString(s);
			AppendString(s, s1, 1, s1[0]);
			
			// Now reset our work strings:
			PIResetString(s1);
			PIResetString(rx);
			
			loop--; // stay here to check for other ^N's.
		
		} // else if
		
		else flag = false;
		
	} // end while
	
} // end PIParamText

//-------------------------------------------------------------------------------

short HostReportError(Str255 inSource, Str255 inTarget)
{
	const short outError = errReportString;
	
	if (inSource)
	{ // have to clear and copy:
	
		PIResetString(inSource);
		AppendString(inSource, inTarget, 1, inTarget[0]);
	}

	return outError;
	
} // end HostReportError

//-------------------------------------------------------------------------------
#if __PIMac__

void NumToString(int32 theNum, Str255 theString) 
{
    if (theString)
    {
        snprintf((char*)&theString[1], 255, "%d", theNum);
        theString[0] = strlen((char*)&theString[1]);
    }
}

//-------------------------------------------------------------------------------

void StringToNum(ConstStr255Param   theString, int32* theNum)
{
}

#endif  // #if __PIMac__

//-------------------------------------------------------------------------------

Ptr HostLockHandle (HandleProcs *procs, Handle h, const Boolean inMoveHigh)
{
	if (HostHandleProcsAvailable (procs, NULL))
	{
		return (*procs->lockProc) (h, inMoveHigh);	
	}		
	else
	{
        return NULL;
	}

} // end HostLockHandle

//-------------------------------------------------------------------------------

Handle HostNewHandle (HandleProcs *procs, const size_t inSize)
{
	
	if (HostHandleProcsAvailable (procs, NULL))
		return (*procs->newProc) (Convert_size_t_to_int32(inSize));
	else
        return NULL;

} // end HostNewHandle

//-------------------------------------------------------------------------------

Boolean	HostPlayDialog(PIDescriptorParameters *procs)
{
	return procs->playInfo == plugInDialogDisplay;

	// Other valid values for playInfo:
	// plugInDialogDontDisplay = display only if necessary,
	// plugInDialogDisplay = display your dialog,
	// plugInDialogSilent = never display your dialog

} // end HostPlayDialog


//-------------------------------------------------------------------------------

Ptr AllocateGlobals(void * resultAddr,
					void * paramBlockAddr,
					const size_t size,
					intptr_t *data, 
					FProcP InitGlobals)

{
	Ptr globalPtr = NULL; // initial no error return value
	
	if (!*data)
	{ // Data is empty, so initialize our globals
		
		// Create a chunk of memory to put our globals.
		// No need for Handles just get a pointer.
		globalPtr = (Ptr)malloc(size);
		
		if (globalPtr != NULL)
		{ // was able to create global pointer.
			
			// the result is always the first two bytes of
			// the global structure, always followed by a
			// pointer to the param block.  Set result
			// to zero and set the pointer to the
			// param block:
			uintptr_t result = (uintptr_t)globalPtr;
			uintptr_t *address = (uintptr_t *)((uintptr_t)globalPtr + sizeof(short *));
				
			*((void **)result) = resultAddr;
			*((short *)resultAddr) = noErr;
				
			*address = (uintptr_t)paramBlockAddr;
				
			// now initialize any globals that need starting values:
			InitGlobals (globalPtr);
				
			// store the pointer in the passed in intptr_t *data:
			*data = (intptr_t)globalPtr;
			
		}
	}
	else
	{
		// we've already got a valid structure pointed to by *data
		// cast the pointer to a global pointer
		globalPtr = (Ptr)*data;

		if (globalPtr != NULL)
		{ // able to create global pointer.
		
			// the result is always the first two bytes of
			// the global structure, always followed by a
			// pointer to the param block.  Set result
			// to zero and set the pointer to the
			// param block:
			uintptr_t result = (uintptr_t)globalPtr;
			uintptr_t *address = (uintptr_t *)((uintptr_t)globalPtr + sizeof(short *));
			
			*((void **)result) = resultAddr;
			*((short *)resultAddr) = noErr;
			
			*address = (uintptr_t)paramBlockAddr;
		}
	}
	
	return globalPtr;
}

//-------------------------------------------------------------------------------

int16 CSPlanesFromMode (const int16 imageMode,
						const int16 currPlanes)
{
	int16 planes = currPlanes;
	// Default to current planes if we can't find right set.
	
	// If we're in multichannel mode, the planes value is
	// dynamic, so we'll just return the current number of
	// planes for that.  (What else can we do?)
	
	if (imageMode >= plugInModeBitmap && imageMode <= plugInModeGray32 &&
		imageMode != plugInModeMultichannel && imageMode != plugInModeDeepMultichannel)
	{ // are we within bounds?
	
		/* static */ const int16 planesPerMode [] =
		{ // Set up a small little array to return the values
		  // we need.  If you have A4-globals set up
		  // (Macintosh) you can make this static to
		  // make its access faster on subsequent
		  // lookups.  If you don't have A4-globals set up
		  // and you need them (Macintosh 68k) then you
		  // will have garbage next time it's used:
		  
			/* plugInModeBitmap */			1,
			/* plugInModeGrayScale */		1,
			/* plugInModeIndexedColor */	3,
			/* plugInModeRGBColor */		3,
			/* plugInModeCMYKColor */		4,
			/* plugInModeHSLColor */		3,
			/* plugInModeHSBColor */		3,
			/* plugInModeMultichannel */	0, // special case
			/* plugInModeDuotone */			1,
			/* plugInModeLabColor */		3,
			/* plugInModeGray16 */			1,
			/* plugInModeRGB48 */			3,
			/* plugInModeLab48 */			3,
			/* plugInModeCMYK64 */			4,
			/* plugInModeDeepMultichannel */0, // special case
			/* plugInModeDuotone16 */		1,
			/* plugInModeRGB96 */			3,
			/* plugInModeGray32 */			1
		};
		
		planes = planesPerMode[imageMode];
	}
	
	return planes;

} // end CSPlanesFromMode


//-------------------------------------------------------------------------------

int16 CSModeToSpace (const int16 imageMode)
{
	int16 space = plugIncolorServicesChosenSpace;
	// Default to same space.

	if (imageMode >= plugInModeBitmap && imageMode <= plugInModeGray32)
	{
		/* static */ const int16 modePerSpace [] =
		{ // little array to map modes to color space
		  // values.  Make this static if you have
		  // A4-global space set up (Macintosh 68k) and this
		  // will run faster.  If you need A4-space and
		  // don't have it set up, and this is made
		  // static, you'll have garbage next time
		  // it's used:
		  
			/* plugInModeBitmap */			plugIncolorServicesChosenSpace,
			/* plugInModeGrayScale */		plugIncolorServicesGraySpace,
			/* plugInModeIndexedColor */	plugIncolorServicesChosenSpace,
			/* plugInModeRGBColor */		plugIncolorServicesRGBSpace,
			/* plugInModeCMYKColor */		plugIncolorServicesCMYKSpace,
			/* plugInModeHSLColor */		plugIncolorServicesHSLSpace,
			/* plugInModeHSBColor */		plugIncolorServicesHSBSpace,
			/* plugInModeMultichannel */	plugIncolorServicesChosenSpace,
			/* plugInModeDuotone */			plugIncolorServicesGraySpace,
			/* plugInModeLabColor */		plugIncolorServicesLabSpace,
			/* plugInModeGray16 */			plugIncolorServicesGraySpace,
			/* plugInModeRGB48 */			plugIncolorServicesRGBSpace,
			/* plugInModeLab48 */			plugIncolorServicesLabSpace,
			/* plugInModeCMYK64 */			plugIncolorServicesCMYKSpace,
			/* plugInModeDeepMultichannel */plugIncolorServicesChosenSpace,
			/* plugInModeDuotone16 */		plugIncolorServicesGraySpace,
			/* plugInModeRGB96 */			plugIncolorServicesRGBSpace,
			/* plugInModeGray32 */			plugIncolorServicesGraySpace

		};
		
		space = modePerSpace[imageMode];
	
	} // If unsupported mode, will return current space.
	
	return space;
	
} // end CSModeToSpace

//-------------------------------------------------------------------------------

OSErr HostCloseReader (PIDescriptorParameters *procs,
					   HandleProcs *hProcs,
					   PIReadDescriptor *token)
{
	// Close token:
	OSErr		err = procs->readDescriptorProcs->closeReadDescriptorProc(*token);
	
	// Dispose the parameter block descriptor:
	HostDisposeHandle(hProcs, procs->descriptor);
	
	// Set the descriptor and the read token to NULL:
	procs->descriptor = NULL;
	*token = NULL;
	
	return err;

} // end HostCloseReader

//-------------------------------------------------------------------------------

void HostDisposeHandle (HandleProcs *procs, Handle h)
{
	
	if (HostHandleProcsAvailable (procs, NULL))
		(*procs->disposeProc) (h);
	
}

//-------------------------------------------------------------------------------

void HostUnlockHandle (HandleProcs *procs, Handle h)
{

    if (HostHandleProcsAvailable (procs, NULL))
	{
		(*procs->unlockProc) (h);	
	}		
	
} // end HostUnlockHandle

//-------------------------------------------------------------------------------

Boolean HostDescriptorAvailable (PIDescriptorParameters *procs,
								 Boolean *outNewerVersion)
{
	
	Boolean available = TRUE;		// assume procs are available
	Boolean newerVersion = FALSE;	// assume we're running under correct version
	
	// We want to check for this stuff in a logical order, going from things
	// that should always be present to things that "may" be present.  It's
	// always a danger checking things that "may" be present because some
	// hosts may not leave them NULL if unavailable, instead pointing to
	// other structures to save space.  So first we'll check the main
	// proc pointer, then the version, the number of routines, then some
	// of the actual routines:
		
	if (procs == NULL)
	{
		available = FALSE;
	}	
	else if (procs->descriptorParametersVersion < 
			 kCurrentDescriptorParametersVersion)
	{
		available = FALSE;
	}	
	else if (procs->descriptorParametersVersion >
			 kCurrentDescriptorParametersVersion)
	{	
		available = FALSE;	
		newerVersion = TRUE;
	}	
	else if (procs->readDescriptorProcs == NULL || 
			 procs->writeDescriptorProcs == NULL)
	{
		available = FALSE;
	}
	else if (procs->readDescriptorProcs->readDescriptorProcsVersion
			 < kCurrentReadDescriptorProcsVersion)
	{
		available = FALSE;
	}
	else if (procs->readDescriptorProcs->readDescriptorProcsVersion
			 > kCurrentReadDescriptorProcsVersion)
	{
		available = FALSE;
		newerVersion = TRUE;
	}
	else if (procs->readDescriptorProcs->numReadDescriptorProcs
			 < kCurrentReadDescriptorProcsCount)
	{
		available = FALSE;
	}
	else if (procs->writeDescriptorProcs->writeDescriptorProcsVersion
			 < kCurrentWriteDescriptorProcsVersion)
	{
		available = FALSE;
	}
	else if (procs->writeDescriptorProcs->writeDescriptorProcsVersion
			 > kCurrentWriteDescriptorProcsVersion)
	{
		available = FALSE;
		newerVersion = TRUE;
	}
	else if (procs->writeDescriptorProcs->numWriteDescriptorProcs
			 < kCurrentWriteDescriptorProcsCount)
	{
		available = FALSE;
	}
	else if (procs->readDescriptorProcs->openReadDescriptorProc == NULL ||
			 procs->readDescriptorProcs->closeReadDescriptorProc == NULL ||
			 procs->readDescriptorProcs->getKeyProc == NULL ||
			 procs->readDescriptorProcs->getIntegerProc == NULL ||
			 procs->readDescriptorProcs->getFloatProc == NULL ||
			 procs->readDescriptorProcs->getUnitFloatProc == NULL ||
			 procs->readDescriptorProcs->getBooleanProc == NULL ||
			 procs->readDescriptorProcs->getTextProc == NULL ||
			 procs->readDescriptorProcs->getAliasProc == NULL ||
			 procs->readDescriptorProcs->getEnumeratedProc == NULL ||
			 procs->readDescriptorProcs->getClassProc == NULL ||
			 procs->readDescriptorProcs->getSimpleReferenceProc == NULL ||	
			 procs->readDescriptorProcs->getObjectProc == NULL ||
			 procs->readDescriptorProcs->getCountProc == NULL ||
			 procs->readDescriptorProcs->getStringProc == NULL ||
			 procs->readDescriptorProcs->getPinnedIntegerProc == NULL ||
			 procs->readDescriptorProcs->getPinnedFloatProc == NULL ||
			 procs->readDescriptorProcs->getPinnedUnitFloatProc == NULL)
	{
		available = FALSE;
	}	
	else if (procs->writeDescriptorProcs->openWriteDescriptorProc == NULL ||
			 procs->writeDescriptorProcs->closeWriteDescriptorProc == NULL ||
			 procs->writeDescriptorProcs->putIntegerProc == NULL ||
			 procs->writeDescriptorProcs->putFloatProc == NULL ||
			 procs->writeDescriptorProcs->putUnitFloatProc == NULL ||
			 procs->writeDescriptorProcs->putBooleanProc == NULL ||
			 procs->writeDescriptorProcs->putTextProc == NULL ||
			 procs->writeDescriptorProcs->putAliasProc == NULL ||
			 procs->writeDescriptorProcs->putEnumeratedProc == NULL ||
			 procs->writeDescriptorProcs->putClassProc == NULL ||
			 procs->writeDescriptorProcs->putSimpleReferenceProc == NULL ||	
			 procs->writeDescriptorProcs->putObjectProc == NULL ||
			 procs->writeDescriptorProcs->putCountProc == NULL ||
			 procs->writeDescriptorProcs->putStringProc == NULL ||
			 procs->writeDescriptorProcs->putScopedClassProc == NULL ||
			 procs->writeDescriptorProcs->putScopedObjectProc == NULL)
	{
		available = FALSE;
	}	

	if (newerVersion && (outNewerVersion != NULL))
		*outNewerVersion = newerVersion;
		
	return available;
	
} // end HostDescriptorAvailable

//-------------------------------------------------------------------------------

OSErr	HostCloseWriter(PIDescriptorParameters *procs,
						HandleProcs *hProcs,
						PIWriteDescriptor *token)
{
	OSErr				err = noErr; // assume no error
	PIDescriptorHandle	h = NULL;
	
	if (procs->descriptor != NULL) // don't need descriptor passed to us
		HostDisposeHandle(hProcs, procs->descriptor); // dispose.
	procs->writeDescriptorProcs->closeWriteDescriptorProc(*token, &h);
	procs->descriptor = h;
	
	// Set recordInfo to default.  Options are: plugInDialogOptional,
	// plugInDialogRequire, plugInDialogNone:
	procs->recordInfo = plugInDialogOptional;

	*token = NULL;
	
	return err;
	
} // end HostCloseWriter

//-------------------------------------------------------------------------------

Boolean HostHandleProcsAvailable (HandleProcs *procs,
								  Boolean *outNewerVersion)

{ // We only require the new, dispose, set size and get size procs.  You can
  // use the OS lock and unlock routines, if necessary.  Even with that,
  // however, lets just check for everything.
	
	Boolean available = TRUE;		// assume procs are available
	Boolean newerVersion = FALSE;	// assume we're running under correct version
	
	if (procs == NULL)
	{
		available = FALSE;
	}	
	else if (procs->handleProcsVersion < kCurrentHandleProcsVersion)
	{
		available = FALSE;
	}	
	else if (procs->handleProcsVersion > kCurrentHandleProcsVersion)
	{	
		available = FALSE;	
		newerVersion = TRUE;
	}	
	else if (procs->numHandleProcs < kCurrentHandleProcsCount)
	{
		available = FALSE;
	}
	else if (procs->newProc == NULL ||
			 procs->disposeProc == NULL ||
			 procs->getSizeProc == NULL ||
			 procs->setSizeProc == NULL)
	{
		available = FALSE;
	}
		
	if (newerVersion && (outNewerVersion != NULL))
		*outNewerVersion = newerVersion;
		
	return available;
	
} // end HostHandleProcsAvailable

// end PIUtilities.cpp
