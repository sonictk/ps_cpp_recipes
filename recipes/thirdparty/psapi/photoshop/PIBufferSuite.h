// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 * \file PIBufferSuite.h
 *
 * \brief This file describes Photoshop's Buffer Suite for plug-ins
 *
 * Distribution:
 *	PUBLIC
 *
 */


/** @defgroup PicaBufferSuite Buffer Suite Callbacks 
* The Buffer suite provides an alternative to the memory management functions 
* available in previous versions of the Photoshop plug-in specification. It provides 
* a set of routines to request that the host allocate and dispose of memory out of 
* a pool which it manages. <br><br>
* For most types of plug-ins, buffer allocations can be delayed until they are 
* actually needed. Unfortunately, Export modules must track the buffer for the data 
* requested from the host even though the host allocates the buffer. This means that 
* the Buffer suite routines do not provide much help for Export modules.	<br><br>
* For more information, please see @ref PGMemoryMgmtStrategies "Memory Management Strategies".
*
* <b> Accessing the Suite </b> \n\n
* The Buffer suite is referred to as:
* @code
  #define kPSBufferSuite 			"Photoshop Buffer Suite for Plug-ins"
@endcode
* The current version of the Buffer suite:
* @code
  #define kPSBufferSuiteVersion1		1
@endcode
* The suite is acquired as follows:
* @code
  PSBufferSuite1 *sPSBuffer;
  error = sSPBasic->AcquireSuite(kPSBufferSuite,
  								 kPSBufferSuiteVersion1, 	  
  								 &sPSBuffer);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/

#ifndef __PIBufferSuite__
#define __PIBufferSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "SPTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Buffer Suite.
#define kPSBufferSuite 			"Photoshop Buffer Suite for Plug-ins"

//-------------------------------------------------------------------------
//	Buffer suite typedefs 
//-------------------------------------------------------------------------

/**
* Attempts to allocate the number of bytes specified with the
* variable pointed to by the \c pRequestedSize parameter. If
* this many bytes cannot be allocated, then the largest possible
* number (greater than \c minimumSize) is allocated.  Returns the
* number of bytes actually allocated in the
* \c pRequestedSize parameter.  
* @param pRequestedSize [IN/OUT] The requested size for the new buffer. If NULL, 
* \c minimumSize bytes are allocated.  The actual buffer size allocated is also 
* returned in this parameter. 
* @param minimumSize The minimum size allowable for the buffer.
* @returns A pointer to the new buffer; or NULL if \c minimumSize of bytes cannot 
* be allocated.
*/
typedef SPAPI Ptr (*BufferNewProc) (unsigned32 *pRequestedSize,	/* IN/OUT: Actual size returned here. */
							  unsigned32 minimumSize);	
							  				
    
/**
* Attempts to allocate the number of bytes specified with the
* variable pointed to by the \c pRequestedSize parameter. If
* this many bytes cannot be allocated, then the largest possible
* number (greater than \c minimumSize) is allocated.  Returns the
* number of bytes actually allocated in the
* \c pRequestedSize parameter.  
* @param pRequestedSize [IN/OUT] The requested size for the new buffer. If NULL, 
* \c minimumSize bytes are allocated.  The actual buffer size allocated is also 
* returned in this parameter. 
* @param minimumSize The minimum size allowable for the buffer.
* @returns A pointer to the new buffer; or NULL if \c minimumSize of bytes cannot 
* be allocated.
*/
typedef SPAPI Ptr (*BufferNewProc64) (unsigned64 *pRequestedSize,	/* IN/OUT: Actual size returned here. */
							  unsigned64 minimumSize);	
							  				
    
/** 
* Disposes of the buffer and sets the variable that refers to it
* to NULL. Does nothing if the buffer pointer is already NULL. 
* @param ppBuffer The buffer to dispose of.
*/
typedef SPAPI void (*BufferDisposeProc)	(Ptr *ppBuffer);	
										  
/** 
* Gets the size of the buffer.
* @param pBuffer The buffer to get the size of.
* @returns The size of the buffer; or zero if the buffer pointer
* is invalid. 
*/
typedef SPAPI unsigned32 (*BufferGetSizeProc) (Ptr pBuffer);

    
/** 
* Gets the size of the buffer.
* @param pBuffer The buffer to get the size of.
* @returns The size of the buffer; or zero if the buffer pointer
* is invalid. 
*/
typedef SPAPI unsigned64 (*BufferGetSizeProc64) (Ptr pBuffer);

    
/** 
* Gets the amount of space available.  This space may not be contiguous.
* @returns The amount of remaining space available. 
*/
typedef SPAPI unsigned32 (*BufferGetSpaceProc) (void);
	

/** 
* Gets the amount of space available.  This space may not be contiguous.
* @returns The amount of remaining space available. 
*/
typedef SPAPI unsigned64 (*BufferGetSpaceProc64) (void);


//-------------------------------------------------------------------------
//	Buffer suite version 1 
//-------------------------------------------------------------------------

/// Current version of the buffer suite.
#define kPSBufferSuiteVersion1		1

/** The set of routines available in Pica Buffer Suite Version 1. */
typedef struct 
{
    BufferNewProc		New;		/**< Function pointer to the new buffer routine. */	
    BufferDisposeProc	Dispose;	/**< Function pointer to the dispose buffer routine. */
    BufferGetSizeProc	GetSize;	/**< Function pointer to the get size routine. */
    BufferGetSpaceProc	GetSpace;	/**< Function pointer to the get space routine. */

} PSBufferSuite1;


/// 64 bit version of the buffer suite.
#define kPSBufferSuiteVersion2		2

/// current version of the buffer suite.
#define kPSBufferSuiteVersion		kPSBufferSuiteVersion2

/** The set of routines available in Pica Buffer Suite Version 1. */
typedef struct 
{
    BufferNewProc			New;		/**< Function pointer to the new buffer routine. */	
    BufferDisposeProc		Dispose;	/**< Function pointer to the dispose buffer routine. */
    BufferGetSizeProc		GetSize;	/**< Function pointer to the get size routine. */
    BufferGetSpaceProc		GetSpace;	/**< Function pointer to the get space routine. */
    BufferNewProc64			New64;		/**< Function pointer to the 64 bit new buffer routine. */	
    BufferGetSizeProc64		GetSize64;	/**< Function pointer to the 64 bit get size routine. */
    BufferGetSpaceProc64	GetSpace64;	/**< Function pointer to the 64 bit get space routine. */

} PSBufferSuite2;

/******************************************************************************/

#ifdef __cplusplus
}
#endif


#endif	// PIBufferSuite
/** @} */
