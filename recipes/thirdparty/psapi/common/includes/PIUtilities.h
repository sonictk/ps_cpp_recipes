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
//		PIUtilities.h
//
//	Description:
//		This library contains the headers for the macros, and
//		routines to simplify the use of suites and also some
//		helpful common plug-in functions. 
//
//	Use:
//		PIUtilities is intended to group common functions
//		into higher-level macros and routines to simplify
//		plug-in programming.
//
//-------------------------------------------------------------------------------
 
#ifndef __PIUtilities_H__
#define __PIUtilities_H__

#include <stddef.h>				// Standard definitions.

#include "PITypes.h"			// Photoshop types.
#include "PIGeneral.h"			// Photoshop general routines.
#include "PIActions.h"			// Photoshop scripting.
#include "PIAbout.h"			// AboutRecord structure.
#include "PIDefines.h"			// Plug-in definitions.

//-------------------------------------------------------------------------------
//	Includes
//-------------------------------------------------------------------------------

#ifdef __PIWin__
	#include <limits.h>
	#include <stdlib.h>
	#include <winver.h>
	#include <windowsx.h>
	#include "PIDLLInstance.h"

	typedef char * StringPtr;
	
#else // Macintosh or other.

	#define HANDLE Handle

	#include "DialogUtilities.h"

#endif // Mac/Win

#ifndef ResourceID
	#define ResourceID		16000
#endif

#ifndef AboutID
	#define AboutID			ResourceID
#endif

#ifndef uiID
	#define uiID			ResourceID+1
#endif

#ifndef AlertID
	#define AlertID			16990
#endif

#ifndef kBadNumberID
	#define kBadNumberID	AlertID
#endif

#ifndef kBadDoubleID
	#define kBadDoubleID	kBadNumberID+1
#endif

#ifndef kNeedVers
	#define kNeedVers		kBadDoubleID+1
#endif

#ifndef kWrongHost
	#define kWrongHost		kNeedVers+1
#endif

#ifndef kSuiteMissing
    #define kSuiteMissing	kWrongHost+1
#endif

#ifndef kCantCreatePath
    #define kCantCreatePath	kSuiteMissing+1
#endif

#ifndef kStr255MaxLen
	#define kStr255MaxLen	255
#endif

#ifndef kStr255InitLen
	#define kStr255InitLen	kStr255MaxLen+1
#endif

//-------------------------------------------------------------------------------
// C++ wrapper
//-------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

    
typedef enum
{
    kUnknown = -1,
    kFalse = 0,
    kTrue = 1
} TryState;

//-------------------------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------------------------

/**	Returns the window pointer from an AboutRecord.  Windows only.
    Returns NULL on Macintosh (AboutRecord is not provided on Mac platform.)

	@param aboutPtr Pointer to AboutRecord.
	@return Handle on Windows or NULL if Macintosh
	@see PIPlatform
*/
Handle HostGetPlatformWindowPtr (AboutRecordPtr aboutPtr);


/**	BufferProcs -- Prototypes

	The following routines provide shells around the buffer procs routines.
	These routines allow us to allocate buffers from Photoshop's memory
	without first telling Photoshop about it in the bufferSpace or maxSpace
	parameter in the interface record.  This can be useful when we need
	different sized buffers at different times.


	Are the buffer procs even available?  If not, the plug-in will have to
	put up a warning dialog to indicate that it requires Photoshop 2.5 or
	will have to work around this using the old memory management techniques
	documented in earlier versions of the plug-in kit.  outNewerVersion is set if the
	procs version is newer than the plug-in.  The buffer procs version number
	is unlikely to change, but it is wise to test it anyway.  If outNewerVersion is
	null, it will be ignored
*/

/**	Determines whether the BufferProcs callback is available.

	@param
		BufferProcs *proc			Pointer to BufferProcs callback.

	@return
		Boolean *outNewerVersion	TRUE if the host has a newer version
									of the procs than the plug-in.
									FALSE if the host has the same version
									of the procs as the plug-in.

	@return
		returns TRUE				If the BufferProcs callback is available.
	@return
		returns FALSE				If the BufferProcs callback is absent.
*/
Boolean HostBufferProcsAvailable (BufferProcs *procs, Boolean *outNewerVersion);

/** The following routine takes care of putting up the warning if the appropriate
    version of the buffer procs is not available.
	Shows an alert if the BufferProcs callback is not available.
	Pops a dialog with the warning "Need at least version 2.5" or
	the warning "This is the wrong host" if the proc is not available
	and/or the needed version is newer than the host's version.

		AlertID						#define with the ID of the "Need host"
									alert.  See header file.

		kNeedVers					#define with the ID of the "Need host ^0"
									string.  See header file.

		kWrongHost					#define with the ID of the "Wrong host"
									string.  See header file.

	@param
		BufferProcs *procs			Pointer to BufferProcs callback.


	@return
		returns TRUE				If the BufferProcs callback is available.
	@return
		returns FALSE				If the BufferProcs callback is absent.
*/
Boolean WarnHostBufferProcsAvailable (BufferProcs *procs);

/**	Returns the amount of space available in the host buffer.
	@param
		BufferProcs *procs			Pointer to ColorServicesProc.

	@return
		returns int32				Number of bytes free in buffer or 0 if
									none free or no procs available.
*/
int32 HostBufferSpace (BufferProcs *procs); 

/**	Returns the amount of space available in the host buffer.
	@param
		BufferProcs *procs			Pointer to ColorServicesProc.

	@return
		returns int64				Number of bytes free in buffer or 0 if
									none free or no procs available.
*/
int64 HostBufferSpace64 (BufferProcs *procs); 

/** Allocates a buffer of a specified amount.
    Allocate a buffer of the appropriate size setting bufferID to the ID
    for the buffer.  If an error occurs, the error code will be returned
    and bufferID will be set to zero.

	@param
		BufferProcs *procs			Pointer to BufferProcs callback.
	@param
		const int32 inSize			Size of requested buffer.

	@return
		returns OSErr				noErr if successful, or error code.
	@return
		BufferID *outBufferID		Will be a valid ID to a buffer if noErr,
									0 if an error occurred.
*/
OSErr HostAllocateBuffer (BufferProcs *procs,
						  const int32 inSize, 
						  BufferID *outBufferID);

/** Allocates a buffer of a specified amount.
    Allocate a buffer of the appropriate size setting bufferID to the ID
    for the buffer.  If an error occurs, the error code will be returned
    and bufferID will be set to zero.

	@param
		BufferProcs *procs			Pointer to BufferProcs callback.
	@param
		const int64 inSize			Size of requested buffer.

	@return
		returns OSErr				noErr if successful, or error code.
	@return
		BufferID *outBufferID		Will be a valid ID to a buffer if noErr,
									0 if an error occurred.
*/
OSErr HostAllocateBuffer64 (BufferProcs *procs,
						  const int64 inSize, 
						  BufferID *outBufferID);

/** Free the buffer with the given ID.
	
	@param
		BufferProcs *procs			Pointer to BufferProcs callback.
	@param
		const BufferID inBufferID	ID of buffer to release.

	@return
		returns OSErr				noErr if successful, or error code.
	@return
		BufferID *outBufferID		Will be a valid ID to a buffer if noErr,
									0 if an error occurred.
*/
void HostFreeBuffer (BufferProcs *procs,
					 const BufferID inBufferID);

/**	Locks a buffer and returns a pointer to it.
	Lock and unlock calls manipulate a counter, so they must match exactly.

	@param
		BufferProcs *procs			Pointer to BufferProcs callback.
	@param
		const BufferID inBufferID	ID of buffer to lock.
	@param
		Boolean inMoveHigh			Move the buffer high in memory?

	@return
		returns Ptr					Locks the buffer and returns a pointer to
									it, if successful; NULL if not.
*/
Ptr HostLockBuffer (BufferProcs *procs, 
					const BufferID inBufferID,
					Boolean inMoveHigh);

/** Unlock the buffer.  Lock and unlock calls manipulate a counter, so they
    must balance perfectly.
	Lock and unlock calls manipulate a counter, so they must match exactly.

	@param
		BufferProcs *procs			Pointer to BufferProcs callback.
	@param
		const BufferID inBufferID	ID of buffer to lock.
	@param
		Boolean inMoveHigh			Move the buffer high in memory?

	@return
		returns Ptr					Locks the buffer and returns a pointer to
									it, if successful; NULL if not.
*/
void HostUnlockBuffer (BufferProcs *procs,
					   const BufferID inBufferID);

/**	Allocates a buffer which is as tall as possible.  It sets the actual
	height and bufferID parameters if successful. The following routine 
    allocates a buffer which is as tall as possible.  It
    takes as parameters, the desired rowBytes, the minimum height, the
    maximum height, and the fraction of the available buffer space to use
    expressed as 1/numBuffers.  It sets the actual height and bufferID
    parameters if successful.

	@param
		BufferProcs *procs			Pointer to BufferProcs callback.
	@param
		const int32 inRowBytes		The desired rowBytes.
	@param
		const int16 inMinHeight		The minimum height.
	@param
		const int16 inMaxHeight		The maximum height.
	@param
		const int16 inNumBuffers	The fraction of the available buffer
                                    space to use expressed as 1/inNumBuffers.

	@return
		returns OSErr				noErr and actual height and bufferID
									if successful, error if not.
	@return
		int16 *outActualHeight		Actual height of buffer allocated,
									if successful.
	@return
		BufferID *outBufferID		ID of buffer allocated, if successful.
*/
OSErr HostAllocateStripBuffer (BufferProcs *procs,
							   const int32 inRowBytes,
							   const int16 inMinHeight,
							   const int16 inMaxHeight,
							   const int16 inNumBuffers,
							   int16 *outActualHeight,
							   BufferID *outBufferID);

/** Determines whether the AdvanceState callback is available.
    Check for the advance state procedure and warn if not present.			 
	The macros assume that gStuff is defined somewhere as a pointer
	to the current interface record.

    @param AdvanceStateProc proc		Pointer to AdvanceStateProc.
	@return	TRUE				If the AdvanceState callback is available.
            FALSE				If the AdvanceState callback is absent.
*/
Boolean HostAdvanceStateAvailable (AdvanceStateProc proc);

/**	Shows an alert if the AdvanceState callback is not available.
	AlertID #define with the ID of the "Need host" alert.  See header file.
    kNeedVers #define with the ID of the "Need host ^0" string.  See header file.
	Pops a dialog with the warning "Need host version 3.0" if the 
	proc is not available.
	
	@param AdvanceStateProc proc		Pointer to AdvanceStateProc.
	@return TRUE				If the AdvanceState callback is available.
			FALSE				If the AdvanceState callback is absent.
*/
Boolean WarnHostAdvanceStateAvailable (AdvanceStateProc proc);
   
/** Determines whether the ResourceProcs (Pseudo-Resources) callback is available.

	A pseudo-resource is a cross-platform resource that is stored as
	an Image Resource block in the data fork of the document with the
	other document information.

	@param
		ResourceProcs *proc			Pointer to ResourceProcs callback.

	@return
		Boolean *outNewerVersion	TRUE if the host has a newer version
									of the procs than the plug-in.
									FALSE if the host has the same version
									of the procs as the plug-in.

	@return
		returns TRUE				If the ResourceProcs callback is available.
	@return
		returns FALSE				If the ResourceProcs callback is absent.
*/
Boolean HostResourceProcsAvailable (ResourceProcs *procs, Boolean *outNewerVersion);

/** Shows an alert if the ResourceProcs (Pseudo-Resources) callback
	is not available.

	A pseudo-resource is a cross-platform resource that is stored as
	an Image Resource block in the data fork of the document with the
	other document information.

	Pops a dialog with the warning "Need at least version 2.5" or
	the warning "This is the wrong host" if the proc is not available
	and/or the needed version is newer than the host's version.

		AlertID						#define with the ID of the "Need host"
									alert.  See header file.

		kNeedVers					#define with the ID of the "Need host ^0"
									string.  See header file.

		kWrongHost					#define with the ID of the "Wrong host"
									string.  See header file.

	@param
		ResourceProcs *procs		Pointer to ResourceProcs callback.

    @return
		returns TRUE				If the ResourceProcs callback is available.
		returns FALSE				If the ResourceProcs callback is absent.
*/
Boolean WarnHostResourceProcsAvailable (ResourceProcs *procs);

/** Returns the number of pseudo-resources in a document.

	A pseudo-resource is a cross-platform resource that is stored as
	an Image Resource block in the data fork of the document with the
	other document information.

	@param
		ResourceProcs *proc			Pointer to ResourceProcs callback.
	@param
		const ResType inType		Resource type to count.  You can have
									multiple resources in a document of
									different types; this routine will
									only count one specific type at a time.

	@return
		returns int16				Number of resources found, 0 if none or
									ResourceProcs not present.
*/
int16 HostCountPIResources (ResourceProcs *procs,
							const ResType inType);

/** Returns a handle to a specific pseudo-resource.

	WARNING: This handle is NOT a copy of the resource, but a master handle
			 right to the resource.  If you dispose it, you will dispose the
			 the resource from the document and it will no longer be available.
			 Use DeletePIResource to delete resources.

	A pseudo-resource is a cross-platform resource that is stored as
	an Image Resource block in the data fork of the document with the
	other document information.

	@param
		ResourceProcs *proc			Pointer to ResourceProcs callback.
	@param
		const ResType inType		Resource type.
	@param
		const int16 inIndex			Index of resource to retrieve.

	@return
		returns Handle				Handle to resource found, or
									NULL if not found or procs unavailable.
*/
Handle HostGetPIResource (ResourceProcs *procs,
						  const ResType inType,
						  const int16 inIndex);

/** Deletes a specific pseudo-resource.

	A pseudo-resource is a cross-platform resource that is stored as
	an Image Resource block in the data fork of the document with the
	other document information.

	Subsequent Resource counts and indexes will be -1.
	If you're working with a record AFTER the one you
	deleted, everything will have moved up by one index.

	@param
		ResourceProcs *proc			Pointer to ResourceProcs callback.
	@param
		const ResType inType		Resource type.
	@param
		const int16 inIndex			Index of resource to delete.

	@return
		Deletes resource of type inType of index inIndex.
		The resource will no longer be in the document.
*/
void HostDeletePIResource (ResourceProcs *procs,
						   const ResType inType,
						   const int16 inIndex);

/** Adds a pseudo-resource to the current document.

	A pseudo-resource is a cross-platform resource that is stored as
	an Image Resource block in the data fork of the document with the
	other document information.

	Subsequent Resource counts and indexes will be +1.
	It will always add to the end of the list.

	@param
		ResourceProcs *proc			Pointer to ResourceProcs callback.
	@param
		const ResType inType		Resource type.
	@param
		const Handle inDataHandle	Handle to data to store.

	@return
		Adds the passed resource to the document pseudo-resources.
*/
OSErr HostAddPIResource (ResourceProcs *procs,
						 const ResType inType,
						 const Handle inDataHandle);

/** Determines whether the HandleProcs callback is available.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.

	@return
		Boolean *outNewerVersion	TRUE if the host has a newer version
									of the procs than the plug-in.
									FALSE if the host has the same version
									of the procs as the plug-in.
	@return
		returns TRUE				If the HandleProcs callback is available.
	@return
		returns FALSE				If the HandleProcs callback is absent.
*/
Boolean HostHandleProcsAvailable (HandleProcs *procs, 
								  Boolean *outNewerVersion);

/** Determines whether the HandleProcs callback is available.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	Pops a dialog with the warning "Need at least version 2.5" or
	the warning "This is the wrong host" if the proc is not available
	and/or the needed version is newer than the host's version.

		AlertID						#define with the ID of the "Need host"
									alert.  See header file.

		kNeedVers					#define with the ID of the "Need host ^0"
									string.  See header file.

		kWrongHost					#define with the ID of the "Wrong host"
									string.  See header file.

    WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *procs			Pointer to HandleProcs callback.

	@return
		returns TRUE				If the HandleProcs callback is available.
	@return
		returns FALSE				If the HandleProcs callback is absent.
*/
Boolean WarnHostHandleProcsAvailable (HandleProcs *procs);

/** Creates a new handle and returns its address.  If the HandleProcs are
	unavailable, it will try the OS call to create the handle.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		const size_t inSize			Size of handle to allocate.

	@return
		returns Handle				The handle will be valid if it was
									able to create it, or NULL if not or
									the HandleProcs were unavailable.
*/
Handle HostNewHandle (HandleProcs *procs, const size_t inSize);

/** Disposes a handle allocated via the Handle suite. 

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle h					Handle to dispose.

	@return
		Disposes the handle.  If the HandleProcs are unavailable,
		it will try the OS routine.

*/
void HostDisposeHandle (HandleProcs *procs, Handle h);

/** Returns the size of a handle. 

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle h					Handle to query.

	@return
		returns int32				Size of handle.  If procs are not
									available, will try to return it
									with OS routine.
*/
size_t HostGetHandleSize (HandleProcs *procs, Handle h);

/** Resizes a handle. 

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle h					Handle to resize.
	@param
		const size_t inNewSize		New size of handle.

	@return
		returns OSErr				noErr if able to resize, otherwise
									whatever error occurred (if any).
*/
OSErr HostSetHandleSize (HandleProcs *procs, 
						 Handle h, 
						 const size_t inNewSize);

/** Locks a handle, returning a pointer to the data. 

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle h					Handle to lock.
	@param
		const Boolean inMoveHigh	Move high in memory before locking?

	@return
		returns Ptr					Locks handle and returns a pointer
									to its data, or NULL if unsuccessful.
									It will drop to OS routines if
									procs are unavailable.
*/
Ptr HostLockHandle (HandleProcs *procs,
					Handle h, 
					const Boolean inMoveHigh);

/** Unlocks a handle.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	WARNING:  Do not mix operating system handle creation, deletion,
			  and sizing routines with these callback routines.  They
			  operate differently, allocate memory differently, and,
			  while you won't crash, you can cause memory to be
			  allocated on the global heap and never deallocated.

			  You probably can use the OS calls HLock and HUnlock
			  with HandleProcs handles without a problem, but try
			  not to if you can help it.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle h					Handle to unlock.

	@return
		Unlocks the handle so it will be moved at next compaction.
*/
void HostUnlockHandle (HandleProcs *procs, Handle h);

/** Concatinates two handles, creating a copy, if necessary.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle *outHandle			Handle to concatenate inHandle
									to.  If this is NULL, the routine
									will create a new handle.

	@param
		const Handle inHandle		Data to concatenate onto outHandle.
		
	@return
		returns OSErr				Error checking is pretty loose
									on this one, since it will create
									the handle, if necessary.
*/
OSErr HostHandleCat (HandleProcs *procs,
					  Handle *outHandle,
					  const Handle inHandle);

/** Copies a handle.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle *outHandle			Handle to copy inHandle
									to.  If this is NULL, the routine
									will create a new handle.
	@param
		const Handle inHandle		Data to concatenate onto outHandle.
		
	@return
		returns OSErr				Error checking is pretty loose
									on this one, since it will create
									the handle, if necessary.
*/
OSErr HostHandleCopy (HandleProcs *procs,
					  Handle *outHandle,
					  const Handle inHandle);
					  
/** Reads a resource from a Windows or Macintosh plug-in.

	@param
		const ResType inType		4-character resource type.
	@param
		const int32 inRezID			ID of resource.

	@return
		size_t *outSize				Set to size of resource read,
									0 if not found or empty.
	@return
		returns Ptr					Returns a pointer to the locked memory.
*/
Handle HostGetResource (HandleProcs *procs,
					    const ResType inType,
					    const int32 inRezID,
					    size_t *outSize);

/** Uses the generic PIGetResource to grab a resource and stuff it
    into a pascal string.  The resource will be truncated if over
    255 characters.  Cross-platform as long as the same String
 	resource exists with the same Resource ID on both platforms'
	versions.

	@param
		inResourceID	String resource ID to grab data from.
	@param
		inResourceID	#define for resource type 'STR '.

	@return
		outString		Pascal string copy.
*/
void HostGetString (HandleProcs *procs,
					const int32 inResourceID,
					Str255 outString);

/** Copies a handle's contents to a C string.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle inDataHandle			Handle to copy.
	@param
		const size_t outMaxSize		Maximum size of buffer.

	@return
		char *outString				Null terminated C string
									with copy of handle.
*/
void HostHandle2CString (HandleProcs *procs,
						Handle inDataHandle,
						char *outString,
						const size_t outMaxSize);

/** Copies a null-terminated C string's contents to a new handle.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		const char *inString		C string with source data.

	@return
		returns Handle 				New handle with copy of string,
									NULL if unable to create.
*/
Handle HostCString2Handle (HandleProcs *procs,
						  const char *inString);


/** Copies a handle's contents to a pascal string with a maximum length of 255.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle inDataHandle			Handle to copy.

	@return
		Str255 outString			Pascal string to receive data.
*/
void HostHandle2PString (HandleProcs *procs,
						Handle inDataHandle,
						Str255 outString);

/** Copies a pascal string's contents to a new handle.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		const Str255 inString		Pascal string with source data.

	@return
		returns Handle 				New handle with copy of string,
									NULL if unable to create.
*/
Handle HostPString2Handle (HandleProcs *procs,
						  const Str255 inString);
						  
/** Copies a handle's contents to a pascal string with a maximum length of 255.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle inDataHandle			Handle to copy.

	@return
		Str255 outString			Pascal string to receive data.
*/
void HostHandle2VersionString (HandleProcs *procs,
						       Handle inDataHandle,
						       Str255 outString);

/** Copies a handle's contents to a 3 int32s.

	The HandleProcs are cross-platform master pointers that point to
	pointers that point to data that is allocated in the Photoshop
	virtual memory structure.  They're reference counted and
	managed more efficiently than the operating system calls.

	@param
		HandleProcs *proc			Pointer to HandleProcs callback.
	@param
		Handle inDataHandle			Handle to copy.
	@param
		int32 * major				Major version info
	@param
		int32 * mintor				Minor version info
	@param
		int32 * fix					Fix version info

	@return
		int32 * major				Major version info
	@return
		int32 * mintor				Minor version info
	@return
		int32 * fix					Fix version info
*/
void HostHandle2Version (HandleProcs *procs,
						 Handle inDataHandle,
						 int32 *major,
						 int32 *minor,
						 int32 *fix);

/**	Determines whether the DisplayPixels callback is available.
	@param DisplayPixelsProc proc Pointer to DisplayPixelsProc.
	@return TRUE If the DisplayPixels callback is available.
	        FALSE If the DisplayPixels callback is absent.
*/
Boolean HostDisplayPixelsAvailable (DisplayPixelsProc proc);

/**	Shows an alert if the DisplayPixels callback is not available.
	Pops a dialog with the warning "Need host version 2.5.2." if the
	proc is not available. 
	AlertID #define with the ID of the "Need host" alert.  See header file.
	kNeedVers #define with the ID of the "Need host ^0" string.  See header file.

	@param DisplayPixelsProc proc		Pointer to DisplayPixelsProc.
	
	@return TRUE If the DisplayPixels callback is available.
	        FALSE If the DisplayPixels callback is absent.
*/
Boolean WarnHostDisplayPixelsAvailable (DisplayPixelsProc proc);

/** Determines whether the Property suite of callbacks is available.

	The Property suite callbacks are two callbacks, GetProperty and
	SetProperty, that manage a list of different data elements.  See
	PIProperties.h.

	@param
		PropertyProcs *procs		Pointer to Property suite callbacks.

	@return
		Boolean *outNewerVersion	TRUE if the host has a newer version
									of the procs than the plug-in.
									FALSE if the host has the same version
									of the procs as the plug-in.
	@return
		returns TRUE				If the Property suite is available.
	@return
		returns FALSE				If the Property suite is absent.
*/
Boolean HostPropertyAvailable (PropertyProcs *procs, Boolean *outNewerVersion);

/** Shows an alert if the PropertyProcs callback is not available.

	The Property suite callbacks are two callbacks, GetProperty and
	SetProperty, that manage a list of different data elements.  See
	PIProperties.h.

	Pops a dialog with the warning "Need at least version 2.5" or
	the warning "This is the wrong host" if the proc is not available
	and/or the needed version is newer than the host's version.

	AlertID						#define with the ID of the "Need host"
								alert.  See header file.
	
	kNeedVers					#define with the ID of the "Need host ^0"
								string.  See header file.

	kWrongHost					#define with the ID of the "Wrong host"
								string.  See header file.
	
	PropertyProcs *procs		Pointer to PropertyProcs callback.

	@return
		returns TRUE				If the PropertyProcs callback is available.
	@return
		returns FALSE				If the PropertyProcs callback is absent.
*/
Boolean WarnHostPropertyAvailable (PropertyProcs *procs);

/** Determines whether the ChannelPortProcs callback is available.

	The Channel Port Procs are callbacks designed to simplify
	merged image and target access, with built in scaling.
	They're used extensively by Selection modules.

	@param
		ChannelPortProcs *procs		Pointer to ChannelPort callbacks.

	@return
		Boolean *outNewerVersion	TRUE if the host has a newer version
									of the procs than the plug-in.
									FALSE if the host has the same version
									of the procs as the plug-in.
	@return
		returns TRUE				If ChannelPortProcs is available.
	@return
		returns FALSE				If ChannelPortProcs is absent.
*/
Boolean HostChannelPortAvailable (ChannelPortProcs *procs, Boolean *outNewerVersion);

/** Shows an alert if the ChannelPortProcs callback
	is not available.

	The Channel Port Procs are callbacks designed to simplify
	merged image and target access, with built in scaling.
	They're used extensively by Selection modules.

  	Pops a dialog with the warning "Need at least version 2.5" or
	the warning "This is the wrong host" if the proc is not available
	and/or the needed version is newer than the host's version.

		AlertID						#define with the ID of the "Need host"
									alert.  See header file.

		kNeedVers					#define with the ID of the "Need host ^0"
									string.  See header file.

		kWrongHost					#define with the ID of the "Wrong host"
									string.  See header file.
	@param
		ChannelPortProcs *procs		Pointer to ChannelPort callback.
	@param

	@return
		returns TRUE				If the ResourceProcs callback is available.
	@return
		returns FALSE				If the ResourceProcs callback is absent.
*/
Boolean WarnHostChannelPortAvailable (ChannelPortProcs *procs);

/** Returns an error string and the error code required to tell the
	host to display that string.

	The most useful way to use this routine is to point inSource at
	the host errString (gStuff->errString), and inTarget at your
	string that describes the error.  Then set the global return
	result (gResult) to the result of this routine (errReportString).

	For example:
		gResult = HostReportError(gStuff->errString, "this plug-in crashed");

	Once you return to the host, will display the error dialog:
		"Could not complete your request because this plug-in crashed."

	@param
		Str255 inSource					Pascal source string.
	@param

		Str255 inTarget					Pascal target string.

	@return
		Str255 inSource					Will be a copy of inTarget.
	@return
		returns short errReportString	Host error code to display a string.
*/
short HostReportError(Str255 inSource, Str255 inTarget);

/** Determines whether the PIDescriptorParameters callback is available.

	The Descriptor Parameters suite are callbacks designed for
	scripting and automation.  See PIActions.h.

	@param
		PIDescriptorParameters *procs	Pointer to Descriptor Parameters suite.

	@return
		Boolean *outNewerVersion		TRUE if the host has a newer version
										of the procs than the plug-in.
										FALSE if the host has the same version
										of the procs as the plug-in.
	@return
		returns TRUE					If PIDescriptorParameters is available.
	@return
		returns FALSE					If PIDescriptorParameters is absent.
*/
Boolean HostDescriptorAvailable (PIDescriptorParameters *procs,
								 Boolean *outNewerVersion);

/** Shows an alert if the PIDescriptorParameters callback
	is not available.

	The Descriptor Parameters suite are callbacks designed for
	scripting and automation.  See PIActions.h.

	Pops a dialog with the warning "Need at least version 2.5" or
	the warning "This is the wrong host" if the proc is not available
	and/or the needed version is newer than the host's version.

		AlertID							#define with the ID of the "Need host"
										alert.  See header file.

		kNeedVers						#define with the ID of the "Need host ^0"
										string.  See header file.

		kWrongHost						#define with the ID of the "Wrong host"
										string.  See header file.

	@param
		PIDescriptorParameters *procs	Pointer to Descriptor Parameters suite.

	@return
		returns TRUE					If PIDescriptorParameters is available.
	@return
		returns FALSE					If PIDescriptorParameters is absent.
*/
Boolean WarnHostDescriptorAvailable (PIDescriptorParameters *procs);

/** Closes a read token, disposes its handle, sets the token to NULL, and
	sets the parameter blocks' descriptor to NULL.

	The Descriptor Parameters suite are callbacks designed for
	scripting and automation.  See PIActions.h.

	@param
		PIDescriptorParameters *procs	Pointer to Descriptor Parameters suite.
	@param
		HandleProcs *hProcs				Pointer to HandleProcs callback.
	@param
		PIReadDescriptor *token			Pointer to token to close.
	@param
		procs->descriptor				Pointer to original read handle.

	@return
		PIReadDescriptor *token			Set to NULL.
	@return
		procs->descriptor				Disposed then set to NULL.
	@return
		returns OSErr					noErr or error if one occurred.
*/
OSErr	HostCloseReader (PIDescriptorParameters *procs, HandleProcs *hProcs, PIReadDescriptor *token);

/** Closes a write token, stores its handle in the global parameter block for
	the host to use, sets the token to NULL, and sets the recordInfo to 
	plugInDialogOptional (the default).

	The Descriptor Parameters suite are callbacks designed for
	scripting and automation.  See PIActions.h.

	@param
		PIDescriptorParameters *procs	Pointer to Descriptor Parameters suite.
	@param
		HandleProcs *hProcs				Pointer to HandleProcs callback.
	@param
		PIWriteDescriptor *token		Pointer to token to close and pass on.
	@param
		procs->descriptor				Should be NULL.  If not, its contents
										will be disposed and replaced.

	@return
		PIWriteDescriptor *token		Set to NULL.
	@return
		procs->descriptor				Set to descriptor handle.
	@return
		returns OSErr					noErr or error if one occurred.
*/
OSErr	HostCloseWriter (PIDescriptorParameters *procs,
						 HandleProcs *hProcs,
						 PIWriteDescriptor *token);

/** Adds an object into an open descriptor, disposes its handle and sets the
	handle to NULL.

	The Descriptor Parameters suite are callbacks designed for
	scripting and automation.  See PIActions.h.

	@param
		PIDescriptorParameters *procs	Pointer to Descriptor Parameters suite.
	@param
		HandleProcs *hProcs				Pointer to HandleProcs callback.
	@param
		PIWriteDescriptor token			Pointer to token to write object to.
	@param
		DescriptorKeyID	key				Unsigned int32 key for object.
	@param
		DescriptorTypeID type			Unsigned int32 type for object.
	@param
		PIDescriptorHandle *h			Handle to descriptor object that
										will be writen into the open token.

	@return
		PIWriteDescriptor *token		Has the object *h added to it.
	@return
		PIDescriptorHandle *h			Written, then, if noErr,
										disposed and set to NULL.
	@return
		returns OSErr					noErr or error if one occurred.
*/
OSErr HostPutObj (PIDescriptorParameters *procs,
				  HandleProcs *hProcs, 
				  PIWriteDescriptor token,
				  DescriptorKeyID key,
				  DescriptorTypeID type,
				  PIDescriptorHandle *h);
				  
/** Interrogates playInfo and returns whether host has told plug-in to pop
	its dialog.

	Returns whether playInfo is plugInDialogDisplay, meaning to absolutely
    pop your dialog.  NOTE: This does not check for plugInDialogSilent,
    which means to absolutely NOT pop your dialog.
	The Descriptor Parameters suite are callbacks designed for
	scripting and automation.  See PIActions.h.

	@param
		PIDescriptorParameters *procs	Pointer to Descriptor Parameters suite.

	@result
		returns Boolean					TRUE if you should pop your dialog.
										FALSE if not.
*/
Boolean HostPlayDialog (PIDescriptorParameters *procs);

/** Determines whether the ColorServices callback is available.
	@param 
	    ColorServicesProc proc		Pointer to ColorServicesProc.

	@return
		returns TRUE				If the ColorServices callback is available.
		returns FALSE				If the ColorServices callback is absent.

*/
Boolean HostColorServicesAvailable (ColorServicesProc proc);

/** Shows an alert if the ColorServices callback is not available.
	Pops a dialog with the warning "Need host 2.5" if the proc is not available.

		AlertID						#define with the ID of the "Need host"
									alert.  See header file.

		kNeedVers					#define with the ID of the "Need host ^0"
									string.  See header file.
	@param
		ColorServicesProc proc		Pointer to ColorServicesProc.
	
	@return
		returns TRUE				If the ColorServices callback is available.
		returns FALSE				If the ColorServices callback is absent.
*/
Boolean WarnHostColorServicesAvailable (ColorServicesProc proc);

/** Sets an array of 4 int16 colors to individual color values.
	@param
		int16 *outColor				Pointer to array of 4 int16s to set.
	@param
		const int16 inColor1		Colors to set array to.
	@param
		const int16 inColor2
	@param
		const int16 inColor3
	@param
		const int16 inColor4

	@return
		returns noErr				if copy went okay.
	@return
		returns OSErr				Probably missing a parameter (such
									as a bad pointer.)
	@return
		int16 *outColor				Array of 4 int16s set to inColors.
*/
OSErr CSSetColor (int16 *outColor,
				  const int16 inColor1, 
				  const int16 inColor2,
				  const int16 inColor3,
				  const int16 inColor4);

/**	Copys an array of 4 int16 colors to another array.
	@param
		int16 *outColor				Pointer to array of 4 int16s to set.
	@param
		const int16 *inColor		Pointer to source array of 4 int16s.

	@return
		returns noErr				If copy went okay.
	@return
		returns OSErr				Probably missing a parameter (such
									as a bad pointer.)
	@return
		int16 *outColor				Array of 4 int16s set to inColor.
*/
OSErr CSCopyColor (int16 *outColor, const int16 *inColor);

/** Return number of expected color planes for imageMode. This does
    not include any expected mask or alpha planes.

	@param
		const int16 imageMode		Any valid image mode.  See PIGeneral.h.
	@param
		const int16 currPlanes		Number of current planes.
	@return
		returns int16				Number of expected planes for that
									color mode, or currPlanes if in
									multiChannel or an unsupported mode.
*/

int16 CSPlanesFromMode (const int16 imageMode,
						const int16 currPlanes);

/** Returns the number of expected planes for any valid image mode.

	@param
		const int16 imageMode		Any valid image mode.  See PIGeneral.h.

	@return
		returns int16				plugIncolorServices space, or
									plugIncolorServicesChosenSpace, if
									invalid/out of range.
*/
int16 CSModeToSpace (const int16 imageMode);


/** Converts colors from ColorServices space to Color Picker components space.
	Color Services space is basically an unsigned8 space in an int16.
	Color Picker space is an 8.8 fixed integer space.

	@param
		const int16 *inColor		Pointer to ColorServices source array of 4 int16s.

	@return
		unsigned16 *outColor		Pointer to PickParms array of 4 uint16s to set.
	@return
		returns noErr				If copy went okay.
	@return
		returns OSErr				Probably missing a parameter (such
									as a bad pointer.)

*/
OSErr CSToPicker (unsigned16 *outColor, const int16 *inColor);

/**	Converts colors from Color Picker components space to ColorServices space.
	Color Services space is basically an unsigned8 space in an int16.
	Color Picker space is an 8.8 fixed integer space.

	WARNING: You lose precision with this routine because 8.8 space is
	labotomized into unsigned8 space, discarding the lower bits.  If
	you want that resolution, convert each unit separately to a double
	or use them as 8.8 fixed numbers and/or do not use ColorServices.

	@param
		unsigned16 *outColor		Pointer to PickParms array of 4 uint16s.

	@return
		const int16 *inColor		Pointer to ColorServices source array of 4 int16s.
	@return
		returns noErr				If copy went okay.
	@return
		returns OSErr				Probably missing a parameter (such

*/
OSErr CSFromPicker (int16 *outColor, const unsigned16 *inColor);

/** Convert one color from one space to another. Return the color in
    the same passed components, and any error.

	@param
		ColorServicesProc proc		Pointer to the Color Services callback.

    @param
		const int16 sourceSpace		Any valid color services color space.
									See PIGeneral.h.

  	@param

		const int16 resultSpace		Any valid color services target space.
									See PIGeneral.h.

    @param
		int16 *ioColor				Four int16s for input and converted color.

	@return
		returns OSErr				Returns noErr and converts the color,
									or an error (if one occurs) and leaves the
									original color.
	@return
									Returns plugInHostInsufficient if
									the suite was unavailable.
	@return
									You should call WarnColorServicesAvailable()
									before you use this routine, anyway.
	@return
		int16 *ioColor				Original color components converted
									to target space.
*/
OSErr HostCSConvertColor (ColorServicesProc proc,
						 const int16 sourceSpace,
						 const int16 resultSpace,
						 int16 *ioColor);


/** Show the user-chosen color picker and return the space and
    colors picked.

	@param
		ColorServicesProc proc		Pointer to the Color Services callback.
	@param
		const Str255 inPrompt		Prompt string.
	@param
		int16 *ioSpace				Source (initial) space.
	@param
		int16 *ioColor				Source (initial) color.

	@return
		returns OSErr				Returns noErr and converts the color,
									or an error (if one occurs) and leaves the
									original color.
	@return
									Returns plugInHostInsufficient if
									the suite was unavailable.
	@return
									You should call WarnColorServicesAvailable()
									before you use this routine, anyway.
	@return
		int16 *ioSpace				Target space of picked color.
	@return
		int16 *ioColor				Color components converted
									to target space.
*/
OSErr HostCSPickColor (ColorServicesProc proc,
					   const Str255 inPrompt,
					   int16 *ioSpace,
					   int16 *ioColor);

/**	Initializes a ColorServicesInfo space with default parameters.

    @param
		ColorServicesInfo *ioCSinfo	ColorServicesInfo block to reset.

	@return
		returns noErr				If reset and cleared successfully.
	@return
		returns OSErr				Any errors.
	@return
		ColorServicesInfo *ioCSinfo	Set to default parameters.
*/
OSErr CSInitInfo (ColorServicesInfo *ioCSinfo);

/**	String and number functions -- Prototypes

    Here are the routines and macros for a set of utility functions that
	do basic string and number conversion and manipulation.
*/
typedef enum StringToNumberResult_t
	{
	kStringToNumberInvalid,		// Didn't find a valid number.
	kStringToNumberValid,		// Found a valid number.
	kStringToNumberNegative		// Reports valid negative just in case this was negative zero.
	} StringToNumberResult_t;

/** Converts a pascal string to a numeric (long) value, returning whether
	it found a valid number or not.

	@param
		Str255 s					Source string to parse.

	@return
		int32 *value					The value found in the string.  If no
									value is found, this is left untouched.
	@return
		returns Boolean				TRUE if a valid number was found,
									FALSE if no number could be parsed.
*/
StringToNumberResult_t StringToNumber (Str255 s, int32 *value);

/** Converts a pascal string to a numeric (double) value, returning whether
	it found a valid number or not.

	@param
		Str255 s					Source string to parse.

	@return
		double *value				The value found in the string.  If no
									value is found, this is left untouched.
	@return
		returns Boolean				TRUE if a valid number was found,
									FALSE if no number could be parsed.
*/
StringToNumberResult_t StringToDouble (Str255 s, double *value);

/** Appends one pascal string to another.

	@param
		Str255 outTarget				Pascal string to concatinate onto.
	@param
		const Str255 inSource			Pascal source string.
	@param
		short inSourceStart				First char to start copying from
										source string.
	@param
		short inLength					Number of chars to copy.

	@return
		Str255 outTarget				Has inSource from char
										inSourceStart to
										inSourceStart+inLength appended.
*/
void AppendString (Str255 outTarget,
				   const Str255 inSource,
				   short inSourceStart,
				   short inLength);

/** Appends one character to the end of a pascal string.

	@param
		Str255 outString				Pascal string to concatinate char onto.
	@param
		const unsigned char c			Character to add.

	@return
		Str255 outString				If under 256 characters, has char
										appended and is null terminated.
*/
void AppendCharToString (Str255 outString, const unsigned char c);

/** Takes a double value and creates a string with the number in it, rounding
	for a given precision.

	@param
		double inValue				Floating point value to convert.
	@param
		short inPrecision			Number of decimal points of precision.

	@return
		Str255 outString			Pascal string representing number.
*/
void DoubleToString (Str255 outString,
					 double inValue,
					 short inPrecision);

/** Finds the '.' or ',' in a string and catinates it at that point,
	puts all the data after the mark in a second string.

	@param
		Str255 ioWhole					Pascal string to parse.
	@param
		Str255 outDecimal				Pascal string to receive decimal
										portion.

	@return
		Str255 ioWhole					Length set to whole portion
										(left side of decimal).
	@return
		Str255 outDecimal				Decimal portion of string
										(right side of decimal).
*/
void DivideAtDecimal(Str255 ioWhole, Str255 outDecimal);

/** Replaces occurrences of "^0", "^1", and "^2" in a source string with
	subsequent strings.

	@param
		unsigned char *s			Source search string.
	@param
		unsigned char *r0			Replacement string for "^0".
	@param
		unsigned char *r1			Replacement string for "^1".
	@param
		unsigned char *r2			Replacement string for "^2".

	@return
		unsigned char *s			Has replacement strings in place of
									"^0", "^1", and/or "^2".
*/
void PIParamText(unsigned char *s,
				 unsigned char *r0, 
				 unsigned char *r1, 
				 unsigned char *r2);

/** Raises a given base to a certain power.

	@param
		const uint32 inBase			Base to multiply.
	@param
		const uint16 inRaise		Exponent to raise base to.

	@return
		double outPower				Result of doing base^raise.
*/
double power (const uint32 inBase, const uint16 inRaise);

/** Returns the length of a null-terminated string.  There are many functions
	like this one present that are duplicates of the ANSI string library so that
	most basic functionality is present without including the library.

	@param
		const char *inString			Pointer to string to check length.

	@return
		int16							Length of string up to NULL byte.
*/
int16 PIstrlen (const char *inString);


/** Concatinates a source string to the end of a target string.

	@param
		char *inDest					C string to append to.
	@param
		const char *inSrc				C string to append to other string.
	@param
		 size_t inDestLen				Max length of inDest C buffer.

	@return
		char *inDest					Original string with new string.
	@return
		size_t							Length of new string.

	Truncation can be detected in this manner:
	
	if (PIstrlcat(pname, file, sizeof(pname)) >= sizeof(pname))
		goto toolong;

*/
size_t PIstrlcat(char *inDest, const char *inSrc, size_t inDestLen);

/** Concatinates a source string to the end of a target string.

	@param
		char *outTarget					C string to append to.
	@param
		const char *inSource			C string to append to other string.

	@return
		char *outTarget					Original string with new string.
	@return
		int16							Length of new string.
*/
int16 HostStringCat(char *outTarget, const char *inSource);

/** Changes an uppercase character to lowercase.

	@param
		const char inChar			Character to convert.

	@return
		char						If between A and Z, the lowercase
									equivalent.  Otherwise, the original
									character.
*/
char UpperToLower(const char inChar);

/** Finds an occurrence of a target string in a source string.  Note that
	the target has to match exactly with the source string.  If the target
	starts in the middle of the source string, HostMatch will return the
	character position.  Otherwise it will return the constant noMatch
	or gotMatch.

	@param
		const char *inSearch		Source C-string to search.
	@param
		const char *inTarget		Target C-string to search for.
	@param
		const Boolean ignoreCase	TRUE if you want a case-insensitive
									search; FALSE if you want exact.
	@param
		const int16 inLength		Maximum number of chars to check.
									Should not be over 256.

	@return
		returns noMatch				If could not find exact match.
	@return
		returns gotMatch			If an exact match was found.
	@return
		returns int16				Exact match was found, from char
									outMatch to end of string.
*/
int16 HostMatch(const char *inSearch, 
				const char *inTarget, 
				const Boolean ignoreCase, 
				const int16 inLength);

/** Finds an occurrence of a target string in a source string.  Note that
	the target has to match exactly with the source string.  If the target
	starts in the middle of the source string, HostMatch will return the
	character position.  Otherwise it will return the constant noMatch
	or gotMatch.

	This routine is the same as HostMatch, except the search is done
	on a pascal string.  The pascal string must have a char free so
	it can be NULL terminated, otherwise this routine will always
	return noMatch.

	@param
		const char *inSearch		Source pascal string to search.
	@param
		const char *inTarget		Target C-string to search for.
	@param
		const Boolean ignoreCase	TRUE if you want a case-insensitive
									search; FALSE if you want exact.

	@result
		returns noMatch				If could not find exact match.
	@result
		returns gotMatch			If an exact match was found.
	@result
		returns itn16				Exact match was found, from char
									outMatch to end of string.
*/
int16 HostStringMatch(Str255 s1, 
					  const char *s2,
					  const Boolean ignoreCase);

/** Converts an uint32 ResType to its corresponding 4 characters.

	@param
		const ResType inType		uint32 ResType to convert.

	@return
		char *outChars				4 characters representing the ResType.
									Make sure your pointer points to
									an array of at least 4 characters or
									this will stomp a little memory (4 bytes).
*/
void PIType2Char (const ResType inType, char *outChars);

/** Convert 4 characters to a corresponding uint32 ResType.

	Inputs:
		const char *inChars			Pointer to 4 characters to convert.

	Outputs:
		returns ResType				Unsigned int32 corresponding
									to the 4 characters.
*/
ResType PIChar2Type (const char *inChars);

/** Copies a chunk of memory. This is by no means the most effective way
	to do this, but it's simple and its cross-platform and can be bound
	and error checked in a later version.

	@param
		Ptr outTarget					Pointer to target memory.
	@param
		const Ptr inSource				Pointer to source block.
	@param
		const size_t inLength			Number of bytes to copy.

	@return
		Ptr outTarget					Points to the copy of the
										chunk of memory.  Only
										valid if both pointers were
										valid.
*/
void HostBlockMove (Ptr outTarget, 
					const Ptr inSource, 
					const size_t inLength);

/** Copies a chunk of memory. This is by no means the most effective way
	to do this, but it's simple and its cross-platform and can be bound
	and error checked in a later version.

	@param
		void *outTarget					Pointer to target memory.
	@param
		const void *inSource			Pointer to source block.
	@param
		const size_t inLength			Number of bytes to copy.

	@return
		void *outTarget					Points to the copy of the
										chunk of memory.  Only
										valid if both pointers were
										valid.
*/
void HostCopy (void *outTarget, 
			   const void *inSource,
			   const size_t inLength);
			   
/**	Clears a string by zeroing its first two bytes. Takes care of Pascal and C strings.
	Note: This will automatically get inlined on non-debug builds.
	@param unsigned char *string Any string, at least two bytes.
	@return unsigned char *string String reset to 0.
*/
void PIResetString(unsigned char *string);

//-------------------------------------------------------------------------------
//	String and number functions -- Macro definitions
//-------------------------------------------------------------------------------

#define PIMatch(inSearch, inTarget) \
	HostMatch(inSearch, inTarget, true, PIstrlen(inSearch))
	
#define PISMatch(inSearch, inTarget) \
	HostStringMatch(inSearch, inTarget, true)

/// Return values for match function.
enum
{
	gotMatch = 0,
	noMatch = -1
}; // any other number is exact match at offset #

#define PIStringCat(outTarget, inSource) \
	HostStringCat(outTarget, inSource)

#define PIBlockMove(p1, p2, size) \
	HostBlockMove (p1, p2, size)

#define PICopy(s1, s2, size) \
	HostCopy(s1, s2, size)

/// Multipliers to move long to fixed.
#define kHard16				(1L << 16) /* 16.16 */
#define kSoft16				kHard16 // use for "other" number systems

/// 16.16 (or other) -> double and double -> 16.16 (or other).
#define PIFixedToDouble(x, shift)	(x / (double) shift)
#define PIDoubleToFixed(x, shift)	((int32)(x * shift))
#define Fixed16ToDouble(x) 	(x / (double) 65536.0)
#define DoubleToFixed16(x) 	((int32)(x * 65536))

/// 16.16 -> long and long -> 16.16
#define long2fixed(value)	(value << 16)
#define fixed2long(value)	(value >> 16)

/* From stdlib, finds offset of member */
#ifndef offsetof
#define offsetof(T, member)	((_Sizet)&(((T *)0)->member))
#endif

//-------------------------------------------------------------------------------
//
//	Plug-in Entrypoint -- Definitions
//
//	Routines to help set up globals for every type of plug-in and make for
//	easy dispatch to the routines.
//
//-------------------------------------------------------------------------------

/** The routines that are dispatched to from the jump list should all be
    defined as
	void RoutineName (GPtr globals);
    And this typedef will be used as the type to create a jump list.
*/
typedef void (* FProcP)(Ptr globals);


/** Allocates globals using the handle suite, calls the Initialization routine
	if necessary, and locks and returns a pointer for their use.

	This is the first routine you'll want to use coming in and out of your
	plug-in.  It was designed to make plug-in setup and reentry more
	bulletproof and simpler.

	@param
		void * resultAddr				The address of the gResult variable.
	@param
		void * paramBlockAddr			The address of the gStuff paramBlock.
	@param
		const size_t size				Size of the entire global structure,
										including the parameter block.
	@param
		int32 *data						Pointer to the *data which is
										passed in and stored by the host.
	@param
		FProcP InitGlobals				Function pointer to your InitGlobals
										routine to be called if we're
										allocating them for the first time.
										The declaration of the routine must
										be:
											void InitGlobals(Ptr globalPtr);

	@return
		uintptr_t *data						Will be set to the handle to the
										global memory for reentry.  The host
										automatically holds this data and
										passes it back on subsequent iterations
										(unless the plug-in had been unloaded).
	@return
		returns Ptr						NULL if unsuccessful allocating memory,
										otherwise a pointer to the locked
										global structure.
*/
Ptr AllocateGlobals(void * resultAddr,
					void * paramBlockAddr,
					const size_t size,
					intptr_t *data, 
					FProcP InitGlobals);

//-------------------------------------------------------------------------------
//	Macro wrappers for Function Prototypes
//-------------------------------------------------------------------------------

/// Macro for HostGetPlatformWindowPtr, gStuff must be defined in globals
#define PIPlatform()	\
	HostGetPlatformWindowPtr((AboutRecordPtr)gStuff)

/// Macro for parameter block abortProc function, gStuff must be defined
#define TestAbort() ((*gStuff->abortProc) ())

/// Macro for parameter block progressProc function, gStuff must be defined
#define PIUpdateProgress(done,total) ((*gStuff->progressProc) (done, total))

//-------------------------------------------------------------------------------
//	BufferProcs -- Macro definitions
//-------------------------------------------------------------------------------

#define BufferProcsAvailable(outNewerVersion) \
	HostBufferProcsAvailable (gStuff->bufferProcs, outNewerVersion)

#define WarnBufferProcsAvailable() \
	WarnHostBufferProcsAvailable (gStuff->bufferProcs)

#define BufferSpace() \
	HostBufferSpace (gStuff->bufferProcs)

#define AllocateBuffer(inSize, inBufferID) \
	HostAllocateBuffer (gStuff->bufferProcs, inSize, inBufferID)

#define FreeBuffer(inBufferID) \
	HostFreeBuffer (gStuff->bufferProcs, inBufferID)

#define LockBuffer(inBufferID, inMoveHigh) \
	HostLockBuffer (gStuff->bufferProcs, inBufferID, inMoveHigh)

#define UnlockBuffer(inBufferID) \
	HostUnlockBuffer (gStuff->bufferProcs, inBufferID)

#define AllocateStripBuffer(inRowBytes,inMinHeight,inMaxHeight,inNumBuffers,outActualHeight,outBufferID) \
	HostAllocateStripBuffer (gStuff->bufferProcs, \
							 inRowBytes, \
							 inMinHeight, \
							 inMaxHeight, \
							 inNumBuffers, \
							 outActualHeight, \
							 outBufferID)

//-------------------------------------------------------------------------------
//	AdvanceState -- Macro definitions
//-------------------------------------------------------------------------------

#define AdvanceStateAvailable() \
	HostAdvanceStateAvailable (gStuff->advanceState)

#define WarnAdvanceStateAvailable() \
	WarnHostAdvanceStateAvailable (gStuff->advanceState)
	
#define AdvanceState() \
	(*(gStuff->advanceState)) ()

//-------------------------------------------------------------------------------
//	PseudoResourceProcs -- Macro definitions
//-------------------------------------------------------------------------------

#define ResourceProcsAvailable(outNewerVersion) \
	HostResourceProcsAvailable (gStuff->resourceProcs, outNewerVersion)
	
#define WarnResourceProcsAvailable() \
	WarnHostResourceProcsAvailable (gStuff->resourceProcs)
	
#define CountPIResources(type) \
	HostCountPIResources (gStuff->resourceProcs, type)
	
#define GetPIResource(type,index) \
	HostGetPIResource (gStuff->resourceProcs, type, index)
	
#define DeletePIResource(type,index) \
	HostDeletePIResource (gStuff->resourceProcs, type, index)
	
#define AddPIResource(type,data) \
	HostAddPIResource (gStuff->resourceProcs, type, data)

//-------------------------------------------------------------------------------
//	HandleProcs -- Macro definitions
//-------------------------------------------------------------------------------

#define HandleProcsAvailable(outNewerVersion) \
	HostHandleProcsAvailable (gStuff->handleProcs, outNewerVersion)
	
#define WarnHandleProcsAvailable() \
	WarnHostHandleProcsAvailable (gStuff->handleProcs)
	
#define PINewHandle(size) \
	HostNewHandle (gStuff->handleProcs, size)
	
#define PIDisposeHandle(h) \
	HostDisposeHandle (gStuff->handleProcs, h)
	
#define PIGetHandleSize(h) \
	HostGetHandleSize (gStuff->handleProcs, h)
	
#define PISetHandleSize(h,size) \
	HostSetHandleSize (gStuff->handleProcs, h, size)
	
#define PILockHandle(h,moveHigh) \
	HostLockHandle (gStuff->handleProcs, h, moveHigh)
	
#define PIUnlockHandle(h) \
	HostUnlockHandle (gStuff->handleProcs, h)

#define PIHandleCat(h1, h2)	\
	HostHandleCat(gStuff->handleProcs, h1, h2)
	
#define PIHandleCopy(h1, h2) \
	HostHandleCopy(gStuff->handleProcs, h1, h2)

#define PICString2Handle(s) \
	HostCString2Handle (gStuff->handleProcs, s)
	
#define PIHandle2CString(h, s, max) \
	HostHandle2CString (gStuff->handleProcs, h, s, max)

#define PIPString2Handle(s) \
	HostPString2Handle (gStuff->handleProcs, s)
	
#define PIHandle2PString(h, s) \
	HostHandle2PString (gStuff->handleProcs, h, s)
	
#define PIHandle2VersionString(h, s) \
	HostHandle2VersionString (gStuff->handleProcs, h, s)
	
#define PIHandle2Version(h, major, minor, fix) \
	HostHandle2Version (gStuff->handlProcs, major, minor, fix)

//-------------------------------------------------------------------------------
//	DisplayPixelsProc -- Macro definitions
//-------------------------------------------------------------------------------

#define DisplayPixelsAvailable() \
	HostDisplayPixelsAvailable (gStuff->displayPixels)

#define	WarnDisplayPixelsAvailable() \
	WarnHostDisplayPixelsAvailable (gStuff->displayPixels)

//-------------------------------------------------------------------------------
//	PropertyProcs -- Macro definitions
//-------------------------------------------------------------------------------

#define PropertyAvailable(outNewerVersion) \
	HostPropertyAvailable (gStuff->propertyProcs, outNewerVersion)

#define WarnPropertyAvailable()	\
	WarnHostPropertyAvailable (gStuff->propertyProcs)

#define PIGetProp		gStuff->propertyProcs->getPropertyProc
#define PISetProp		gStuff->propertyProcs->setPropertyProc

#define GetSimple(key, simple)	\
	PIGetProp('8BIM', key, 0, simple, nil)

#define PutSimple(key, simple)  \
	PISetProp('8BIM', key, 0, simple, nil)
	
#define GetComplex(key, index, complex)	\
	PIGetProp('8BIM', key, index, 0, complex)
	
#define PutComplex(key, index, complex)	\
	PISetProp('8BIM', key, index, 0, complex)
	
//-------------------------------------------------------------------------------
//	ChannelPortProcs -- Macro definitions
//-------------------------------------------------------------------------------

#define ChannelPort \
	(gStuff->channelPortProcs)
	
#define ReadPixels \
	(ChannelPort->readPixelsProc)

#define WritePixels \
    (ChannelPort->writeBasePixelsProc)

#define ReadFromWritePort \
	(ChannelPort->readPortForWritePortProc)

#define ChannelPortAvailable(outNewerVersion) \
	HostChannelPortAvailable (ChannelPort, outNewerVersion)

#define WarnChannelPortAvailable() \
	WarnHostChannelPortAvailable (ChannelPort)
	
//-------------------------------------------------------------------------------
//	Error reporting function -- Macro definitions
//-------------------------------------------------------------------------------

#define PIReportError(errString) \
	HostReportError(*(gStuff->errorString), errString)

//-------------------------------------------------------------------------------
//	PIDescriptorParameters -- Macro definitions
//-------------------------------------------------------------------------------

#define NULLID		0 // for ID routines needing null terminator

#define DescParams 	gStuff->descriptorParameters

#define Reader 		DescParams->readDescriptorProcs

#define Writer 		DescParams->writeDescriptorProcs

#define PlayInfo	DescParams->playInfo

#define RecordInfo	DescParams->recordInfo

#define	PlayDialog() \
	HostPlayDialog (DescParams)

#define DescriptorAvailable(outNewerVersion) \
	HostDescriptorAvailable(DescParams, outNewerVersion)

#define WarnDescriptorAvailable() \
	WarnHostDescriptorAvailable(DescParams)

#define OpenReadDesc(desc, array) \
	Reader->openReadDescriptorProc(desc, array)

#define	OpenReader(array) \
	OpenReadDesc(DescParams->descriptor, array)
	
#define CloseReadDesc(token) \
	Reader->closeReadDescriptorProc(token)

#define CloseReader(token) \
	HostCloseReader(DescParams, gStuff->handleProcs, token)
	
#define OpenWriter() \
	Writer->openWriteDescriptorProc()

#define CloseWriteDesc(token, handle) \
	Writer->closeWriteDescriptorProc(token, handle)

#define CloseWriter(token) \
	HostCloseWriter(DescParams, gStuff->handleProcs, token)

// These Macros simplify access to all the basic Get and Put routines.

#define PIGetKey(token, key, type, flags) \
	Reader->getKeyProc(token, key, type, flags)
	
#define PIGetEnum(token, value)	\
	Reader->getEnumeratedProc(token, value)
				
#define PIPutEnum(token, key, type, value) \
	Writer->putEnumeratedProc(token, key, type, value)
	
#define PIGetInt(token, value) \
	Reader->getIntegerProc(token, value)

#define PIGetPinInt(token, min, max, value) \
	Reader->getPinnedIntegerProc(token, min, max, value)

#define PIPutInt(token, key, value) \
	Writer->putIntegerProc(token, key, value)
	
#define PIGetFloat(token, value) \
	Reader->getFloatProc(token, value)
	
#define PIGetPinFloat(token, min, max, value) \
	Reader->getPinnedFloatProc(token, min, max, value)

#define PIPutFloat(token, key, value) \
	Writer->putFloatProc(token, key, value)
	
#define PIGetUnitFloat(token, unit, value) \
	Reader->getUnitFloatProc(token, unit, value)

#define PIGetPinUnitFloat(token, min, max, unit, value) \
	Reader->getPinnedUnitFloatProc(token, min, max, unit, value)

#define PIPutUnitFloat(token, key, unit, value) \
	Writer->putUnitFloatProc(token, key, unit, value)
	
#define PIGetBool(token, value) \
	Reader->getBooleanProc(token, value)

#define PIPutBool(token, key, value) \
	Writer->putBooleanProc(token, key, value)

#define PIGetText(token, value) \
	Reader->getTextProc(token, value)
	
#define PIPutText(token, key, value) \
	Writer->putTextProc(token, key, value)
	
#define PIGetAlias(token, value) \
	Reader->getAliasProc(token, value)
	
#define PIPutAlias(token, key, value) \
	Writer->putAliasProc(token, key, value)

#define PIGetEnum(token, value) \
	Reader->getEnumeratedProc(token, value)

#define PIPutEnum(token, key, type, value) \
	Writer->putEnumeratedProc(token, key, type, value)

#define PIGetClass(token, value) \
	Reader->getClassProc(token, value)
	
#define PIPutClass(token, key, value) \
	Writer->putClassProc(token, key, value)
	
#define PIGetRef(token, value) \
	Reader->getSimpleReferenceProc(token,value)
	
#define PIPutRef(token, key, value) \
	Writer->putSimpleReferenceProc(token, key, value)
	
#define PIGetObj(token, type, value) \
	Reader->getObjectProc(token, type, value)

#define PIPutObj(token, key, type, value) \
	HostPutObj(DescParams, gStuff->handleProcs, token, key, type, value)

#define PIPutObjProc(token, key, type, value) \
	Writer->putObjectProc(token, key, type, value)
	
#define PIGetCount(token, value) \
	Reader->getCountProc(token, value)
	
#define PIPutCount(token, key, value) \
	Writer->putCountProc(token, key, value)
	
#define PIGetStr(token, value) \
	Reader->getStringProc(token, value)
	
#define PIPutStr(token, key, value) \
	Writer->putStringProc(token, key, value)

//-------------------------------------------------------------------------------
//	Color Services -- Macro definitions
//-------------------------------------------------------------------------------

#define ColorServicesAvailable() \
	HostColorServicesAvailable (gStuff->colorServices)

#define WarnColorServicesAvailable() \
	WarnHostColorServicesAvailable (gStuff->colorServices)
	
#define ColorServices(info) \
	(*(gStuff->colorServices)) (info)

#define CSConvertColor(source, result, color) \
	HostCSConvertColor (gStuff->colorServices, source, result, color)

#define CSPickColor(promptString, ioSpace, ioColor) \
	HostCSPickColor (gStuff->colorServices, promptString, ioSpace, ioColor)

//-------------------------------------------------------------------------------
//	C++ wrapper
//-------------------------------------------------------------------------------

#ifdef __cplusplus
} // End of extern "C" block.
#endif // __cplusplus

/// Swap from big endian to little endian
template <class Type>
void Swap(Type & in)
{
	size_t s = sizeof(in);
	if (s <= 1) return;
	char * front = reinterpret_cast<char *>(&in);
	char * back = front + s - 1;
	char temp;
	while (front < back)
	{
		temp = *front;
		*front = *back;
		*back = temp;
		front++;
		back--;
	}
}

Boolean PISetRect(Rect* pRect, short nLeft, short nTop, short nRight, short nBottom);
Boolean PIOffsetRect(Rect* pRect, short xAmt, short yAmt);


#ifdef __PIWin__ // Windows only definitions for utilites

	void NumToString (const int32 x, Str255 s);
	Fixed FixRatio(short numer, short denom);

#else // Macintosh or other definitions for utilies

    void NumToString(int32 theNum, Str255 theString);
    void StringToNum(ConstStr255Param   theString, int32* theNum);

#endif // OS specific definitions
//-------------------------------------------------------------------------------

// size_t and int32 conversion functions with safety

#if _WIN64

// convert a 64 bit size_t to an int32, with safety checking. you should only use
// this function when values > 0xffffffff (32bits) are clearly illegal. Otherwise,
// make your code handle 64 bits.

inline int32 Convert_size_t_to_int32(size_t x)
	{
	return static_cast<int32> (x);
	}

inline uint32 Convert_size_t_to_uint32(size_t x)
	{
	return static_cast<uint32> (x);
	}

inline int Convert_size_t_to_int(size_t x)
	{
	return static_cast<int> (x);
	}

inline unsigned int Convert_size_t_to_uint(size_t x)
	{
	return static_cast<unsigned int> (x);
	}

#else

#define Convert_size_t_to_int32(x)	(static_cast<int32> (x))			// no need to safety check on 32 bit compile. simply silence warnings
#define Convert_size_t_to_uint32(x)	(static_cast<uint32> (x))			// no need to safety check on 32 bit compile. simply silence warnings

#define Convert_size_t_to_int(x)	(static_cast<int> (x))				// no need to safety check on 32 bit compile. simply silence warnings
#define Convert_size_t_to_uint(x)	(static_cast<unsigned int> (x))		// no need to safety check on 32 bit compile. simply silence warnings
	
#endif

// 16 bits

inline int16 Convert_size_t_to_int16(size_t x)
	{
	return static_cast<int16> (x);
	}

inline uint16 Convert_size_t_to_uint16(size_t x)
	{
	return static_cast<uint16> (x);
	}

inline char Convert_size_t_to_char(size_t x)
	{
	return static_cast<char> (x);
	}

inline unsigned char Convert_size_t_to_uchar(size_t x)
	{
	return static_cast<unsigned char> (x);
	}

/******************************************************************************/
#endif // __PIUtilities__
