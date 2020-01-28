// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
/**
 * \file PIHandleSuite.h
 *
 * \brief This file describes Photoshop's Handle Suite for plug-ins
 *
 * Distribution:
 *	PUBLIC
 *
 */

/** @defgroup PicaHandleSuite Handle Suite Callbacks
* The following suite of routines is used primarily for cross-platform support. 
* Although you can allocate handles directly using the Mac OS Toolbox, these callbacks 
* are recommended, instead. When you use these callbacks, Photoshop accounts for these 
* handles in its virtual memory space calculations. <br><br>
* The use of the \c Handle structure throughout the API poses a problem under Windows, 
* where a direct equivalent does not exist. To facilitate Windows plug-ins, Photoshop 
* implements a handle model that is very similar to handles under the Mac OS.  
*
* In general, the Buffer suite routines are more effective for memory allocation than 
* the Handle suite. The Buffer suite may have access to memory unavailable to the Handle 
* suite. You should use the Handle suite, however, if the data you are managing is a 
* Mac OS handle. <br><br>
* The PICA Handle Suite uses several of the same procedure definitions as the original 
* Photoshop @ref HandleSuite. <br><br>
* For more information, please see @ref PGUsingSuites "Using Buffer and Handle Suites".
*
* <b> Accessing the Suite </b> \n\n
* The Handle suite is referred to as:
* @code
 #define kPSHandleSuite 	"Photoshop Handle Suite for Plug-ins"
@endcode
* There are two versions of the Handle suite:
* @code
  #define kPSHandleSuiteVersion1		1
  #define kPSHandleSuiteVersion2		2
@endcode
* The suite is acquired as follows:
* @code
  PSHandleSuite2 *sPSHandle;
  // Acquire the most recent version.
  error = sSPBasic->AcquireSuite(kPSHandleSuite,
  								 kPSHandleSuiteVersion2, 	  
  								 &sPSHandle);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/



#ifndef __PIHandleSuite__
#define __PIHandleSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Handle Suite
#define kPSHandleSuite 			"Photoshop Handle Suite for Plug-ins"

//-------------------------------------------------------------------------------
//	Handle suite typedefs
//-------------------------------------------------------------------------------

/** 
* Locks or unlocks the handle, depending on the value of the \c lock flag. 
* @param h The handle to lock or unlock.
* @param lock Indicates whether to lock or unlock the handle.
* @param address  pointer to the handle data
* @param oldLock  status of the old lock
*/
typedef MACPASCAL void (*SetPIHandleLockProc) (Handle h, Boolean lock, Ptr *address, Boolean *oldLock);

//-------------------------------------------------------------------------------
//	Handle suite version 1
//-------------------------------------------------------------------------------

/// Handle suite, version 1.
#define kPSHandleSuiteVersion1		1
/// Handle suite, version 2.
#define kPSHandleSuiteVersion2		2

/** The set of routines available in Pica Handle Suite Version 1. 
* These function definitions are identical to those in the old 
* @ref HandleSuite, with the exception of the new lock/unlock 
* routine \c SetPIHandleLockProc. */
typedef struct
{
	NewPIHandleProc New;			/**< Function pointer for the new handle routine. */
	DisposePIHandleProc Dispose;	/**< Function pointer for the dispose handle routine. */
	SetPIHandleLockProc SetLock;	/**< Function pointer for the set lock  routine. */
	GetPIHandleSizeProc GetSize;	/**< Function pointer for the get handle size routine. */
	SetPIHandleSizeProc SetSize;	/**< Function pointer for the set handle size routine. */
	RecoverSpaceProc RecoverSpace;	/**< Function pointer for the recover routine. */
	
} PSHandleSuite1;

/** The set of routines available in Pica Handle Suite Version 2.  
* Includes additional routine for disposing of a regular handle.
* These function definitions are identical to those in the old 
* @ref HandleSuite, with the exception of the new lock/unlock 
* routine \c SetPIHandleLockProc. */
typedef struct
{
	NewPIHandleProc New;			/**< Function pointer for the new handle routine. */
	DisposePIHandleProc Dispose;	/**< Function pointer for the dispose handle routine */
	DisposeRegularHandlePIHandleProc DisposeRegularHandle; /**< Function pointer for the dispose regular handle routine. */
	SetPIHandleLockProc SetLock;	/**< Function pointer for the set lock  routine. */
	GetPIHandleSizeProc GetSize;	/**< Function pointer for the get handle size routine. */
	SetPIHandleSizeProc SetSize;	/**< Function pointer for the set handle size routine. */
	RecoverSpaceProc RecoverSpace;	/**< Function pointer for the recover routine. */
	
} PSHandleSuite2;

/******************************************************************************/

#ifdef __cplusplus
}
#endif


#endif	// PIHandleSuite
/** @} */
