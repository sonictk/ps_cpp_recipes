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
//		PIUFile.cpp
//
//	Description:
//		File utilities for alias values acquired from the automation system.
//
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//	Includes
//-------------------------------------------------------------------------------
#include "PIUFile.h"
#if __PIMac__
#include <Cocoa/Cocoa.h>
#endif

// See Also FileUtilitiesMac.cpp
// Flag for turning off deprecated warnings
// When the File Manager routines go away then set this flag to 0
#ifndef PLUGIN_SUPPORTS_FS_ROUTINES
    #define PLUGIN_SUPPORTS_FS_ROUTINES  1
#endif

void AliasToFullPath(Handle aliasValue, char* fullPath, int32 maxPathLength)
{
    if (fullPath != NULL)
        {
        *fullPath = 0;
#ifdef __PIMac__
 #if PLUGIN_SUPPORTS_FS_ROUTINES
        OSErr err;
        Boolean wasChanged = false;
        FSRef fileRef;
        
        err = FSResolveAlias(nil, (AliasHandle)aliasValue, &fileRef, &wasChanged);
        if (err != noErr) return;
        
        err = FSRefMakePath(&fileRef, (unsigned char*)fullPath, maxPathLength);
        if (err != noErr) return;
 #endif
#elif defined(__PIWin__)
        int32 length = sPSHandle->GetSize(aliasValue);
        
        if (length > maxPathLength - 1) return;
        
        Boolean oldLock = FALSE;
        Ptr pointer = NULL;
        
        sPSHandle->SetLock(aliasValue, true, &pointer, &oldLock);
        
        if (pointer != NULL)
            {
            strncpy(fullPath, pointer, maxPathLength-1);
            fullPath[maxPathLength-1] = '\0';
            sPSHandle->SetLock(aliasValue, oldLock, &pointer, &oldLock);
            }
        
        
#endif
        }
}

void FullPathToAlias(char* fullPath, Handle& aliasValue)
{
    aliasValue = NULL;
#if __PIMac__
    AliasHandle aHandle = NULL;
    // this could error with fnfErr, file not found error, ignore
    (void) sPSAlias->MacNewAliasFromCString(fullPath, &aHandle);
    aliasValue = (Handle)aHandle;
#else
    Boolean oldLock = FALSE;
    Ptr address = NULL;
    size_t pathLength = strlen(fullPath)+1;
    aliasValue = sPSHandle->New((int32)pathLength);
    if (aliasValue != NULL)
        {
        sPSHandle->SetLock(aliasValue, true, &address, &oldLock);
        if (address != NULL)
            {
            strncpy(address, fullPath, pathLength - 1);
            address[pathLength-1] = '\0';
            sPSHandle->SetLock(aliasValue, false, &address, &oldLock);
            }
        }
#endif
}


void BookmarkToFullPath(CFDataRef bookmarkValue, char* fullPath, int32 maxPathLength)
{
#ifdef __PIMac__
    if (fullPath != NULL)
        {
        *fullPath = 0;

        CFURLBookmarkResolutionOptions options = kCFBookmarkResolutionWithoutUIMask |
                                                 kCFBookmarkResolutionWithoutMountingMask;
        Boolean		bookmarkIsStale = false;
        CFURLRef	relativeToURL = NULL;	// if security-scoped to a document, this needs to be the doc URL
        CFErrorRef	cfError = 0;
        CFURLRef urlRef = CFURLCreateByResolvingBookmarkData(kCFAllocatorDefault,
                                                             bookmarkValue,
                                                             options,
                                                             relativeToURL,
                                                             NULL,
                                                             &bookmarkIsStale,
                                                             &cfError);
        
        if (urlRef == NULL)
            NSLog(@"Could not resolve bookmark in BookmarkToFullPath");

        bool converted = CFURLGetFileSystemRepresentation(urlRef, true, (UInt8*)fullPath, maxPathLength);
        
        if ( ! converted )
            NSLog(@"Could not convert in BookmarkToFullPath");

        if (urlRef != NULL)
            CFRelease(urlRef);
        }
#else
	UNREFERENCED_PARAMETER(maxPathLength);
	UNREFERENCED_PARAMETER(fullPath);
	UNREFERENCED_PARAMETER(bookmarkValue);
#endif
}

void FullPathToBookmark(char* fullPath, CFDataRef& bookmarkValue)
{
#if __PIMac__

    bookmarkValue = NULL;
    
    CFURLRef urlRef = CFURLCreateFromFileSystemRepresentation(kCFAllocatorDefault,
                                                              (const UInt8*)fullPath,
                                                              strlen(fullPath),
                                                              false); // Boolean isDirectory

    if (urlRef == NULL)
    {
        NSLog(@"Could not create url bookmark in FullPathToBookmark");
        return;
    }
    
    CFURLBookmarkCreationOptions options = 0;
    CFErrorRef	error = 0;
    bookmarkValue = CFURLCreateBookmarkData(kCFAllocatorDefault,
                                            urlRef,
                                            options,
                                            NULL, /* CFArrayRef resourcePropertiesToInclude */
                                            NULL, /* CFURLRef relativeToURL */
                                            &error);
    
    if (urlRef != NULL)
        CFRelease(urlRef);

#else
	UNREFERENCED_PARAMETER(bookmarkValue);
	UNREFERENCED_PARAMETER(fullPath);
#endif
}


int32 GetFullPathToDesktop(char * fullPath, int32 maxPathLength)
{
	int32 error = 0;
	if (fullPath == NULL || maxPathLength < 1) return kSPBadParameterError;
	
	#if __PIMac__

        // Get array with first index being path to desktop
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDesktopDirectory, NSUserDomainMask, YES);

        // Get the first element
        NSString *desktopPath = [paths objectAtIndex:0];

        [desktopPath getCString:fullPath maxLength:maxPathLength encoding:NSUTF8StringEncoding];

		if (PIstrlcat(fullPath, "/", maxPathLength) >= maxPathLength)
			error = kSPBadParameterError;
		fullPath[maxPathLength-1]= '\0';
    
	#else
		
		if (MAX_PATH <= maxPathLength)
		{
			HRESULT hr = SHGetFolderPath( NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, fullPath );
			if (FAILED(hr))
			{
				fullPath[0] = 0;
				error = kSPBadParameterError;
			}
			else
			{
				if (PIstrlcat(fullPath, "\\", maxPathLength) >= (size_t)maxPathLength)
					error = kSPBadParameterError;
				fullPath[maxPathLength-1]= '\0';
			}
		} else {
			error = kSPBadParameterError;
		}

	#endif
	
	return error;
}
// end PIUFile.cpp
