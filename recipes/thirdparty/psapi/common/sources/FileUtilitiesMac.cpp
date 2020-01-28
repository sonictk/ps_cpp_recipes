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
//		FileUtilitiesMac.cpp
//
//	Description:
//		This library contains sources and functions
//		to simplify the use of extremely common file
//		functions for plug-ins. 
//
//	Use:
//		Macintosh routines with common names. 
//
//-------------------------------------------------------------------------------

#include "PIDefines.h"
#include "FileUtilities.h"
#include <Cocoa/Cocoa.h>

// See Also PIUFile.cpp
// Flag for turning off deprecated warnings
// When the File Manager routines go away then set this flag to 0
#ifndef PLUGIN_SUPPORTS_FS_ROUTINES
    #define PLUGIN_SUPPORTS_FS_ROUTINES  1
#endif

/*****************************************************************************/
// On the mac the savePanel opened it up, just check that we have something
// See DoUI for Outbound example on mac
Boolean PIOpenFile (FileHandle fRefNum)
{
    if (fRefNum)
        return  TRUE;
	return FALSE;
}

/*****************************************************************************/

Boolean PICloseFileAndMakeAlias (FileHandle fRefNum, NSString * filename,
					             Boolean *dirty, PIPlatformFileHandle *alias)
{

#if PLUGIN_SUPPORTS_FS_ROUTINES
    
    [fRefNum closeFile];

    fRefNum = nil;

    if (dirty)
        *dirty = FALSE;
    
    if (alias && filename)
    {
        *alias = nil;
        CFURLRef fileURL = (CFURLRef)[[NSURL alloc] initFileURLWithPath:filename isDirectory:FALSE];
        filename = nil;
        if (fileURL)
        {
    
            FSRef	fsRef;
    
            if (CFURLGetFSRef(fileURL, &fsRef))
            {
                AliasHandle	temp;
                OSErr	error = FSNewAliasMinimal(&fsRef, &temp);
                if (error == noErr)
                {
                    *alias = temp;
                    CFRelease(fileURL);
                    return TRUE;
                }
            }
        
            CFRelease(fileURL);
        
        }
    }

#endif

	return FALSE;
    
}

/*****************************************************************************/

OSErr PSSDKWrite(FileHandle refNum, int32 * count, void * buffPtr)
{
    if (count == NULL || buffPtr == NULL || *count <= 0)
        return writErr;
    unsigned long long cPos = [refNum offsetInFile];
    NSData * nsData = [NSData dataWithBytes:buffPtr length:*count];
    [refNum writeData:nsData];
    unsigned long long nPos = [refNum offsetInFile];
    if (*count != (nPos - cPos))
        return writErr;
    return 0;
}

/*****************************************************************************/

OSErr PSSDKWrite(int32 refNum, int32 refFD, int16 usePOSIXIO, int32 * count, void * buffPtr)
{
    if (NULL == count || NULL == buffPtr)
        return writErr;
    
    ByteCount bytes = *count;
    
    ByteCount bCount = *count;
    
    OSErr err = noErr;
    
    if (usePOSIXIO)
    {
        bCount = write(refFD, buffPtr, *count);
    }

#if PLUGIN_SUPPORTS_FS_ROUTINES
    else
    {
        err = FSWriteFork(refNum, fsAtMark | noCacheMask, 0, bytes, buffPtr, &bCount);
    }
#else
    else
    {
        err = controlErr;
    }
#endif
    
    if (bytes != bCount)
        return writErr;

    if (noErr != err)
        return err;
    
    *count = bCount;
    
    return err;
    
}

/*****************************************************************************/

OSErr PSSDKSetFPos(int32 refNum, int32 refFD, int16 usePOSIXIO, short posMode, long posOff)
{
    OSErr err = noErr;
    
    if (usePOSIXIO)
    {
        int whence = SEEK_SET;
        if (posMode == fsFromLEOF)
        {
            whence = SEEK_END;
        }
        off_t result = lseek(refFD, posOff, whence);

        if (result == -1)
        {
            err = controlErr;
        }
    }
    
#if PLUGIN_SUPPORTS_FS_ROUTINES
    else
    {
        err = FSSetForkPosition(refNum, posMode, posOff);
    }
#else
    else
    {
        err = controlErr;
    }
#endif

	return err;
}

/*****************************************************************************/

OSErr PSSDKRead(int32 refNum, int32 refFD, int16 usePOSIXIO, int32 * count, void * buffPtr)
{
	if (NULL == count || NULL == buffPtr)
		return writErr;

	ByteCount bytes = *count;

	ByteCount bCount = *count;

	OSErr err = noErr;
    
    if (usePOSIXIO)
    {
        bCount = read(refFD, buffPtr, *count);
    }
    
#if PLUGIN_SUPPORTS_FS_ROUTINES
    else
    {
        err = FSReadFork(refNum, fsAtMark, 0, bytes, buffPtr, &bCount);
    }
#else
    else
    {
        err = controlErr;
    }
#endif

	if (bytes != bCount)
		return readErr;
		
	*count = bCount;

	return err;
}

// end FileUtilitiesMac.cpp
