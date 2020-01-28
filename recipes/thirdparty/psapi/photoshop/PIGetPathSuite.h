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
 * \file PIGetPathSuite.h
 *
 * \brief This file contains all the public definitions and
 *	structures related to user interface elements.
 *
 * \details
 *	Use the GetPath suite to get the path from FSSpec
 *	
 * Distribution:
 *	PUBLIC
 *
 */

/**
* @defgroup PicaGetPathSuite Get Path Suite
* The Get Path suite gets the path from a file specification.
* The Get Path Suite is available in Adobe Photoshop 5.5 and later.
*
* <b> Accessing the Suite </b> \n\n
* The Get Path Suite suite is referred to as:
* @code
  #define kPSGetPathSuite 			"Photoshop GetPath Suite for Plug-ins"
@endcode
* The current version of the Get Path suite:
* @code
  #define kPSGetPathSuiteVersion1		1
@endcode
* The suite is acquired as follows:
* @code
  PSGetPathSuite1 *sPSGetPath;
  error = sSPBasic->AcquireSuite(kPSGetPathSuite,
  								 kPSGetPathSuiteVersion1, 	  
  								 &sPSGetPath);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/


#ifndef __PIGetPathSuite__
#define __PIGetPathSuite__

#if PRAGMA_ONCE
#pragma once
#endif

//-------------------------------------------------------------------------------
//	Includes.
//-------------------------------------------------------------------------------
#include "PIGeneral.h"

//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------
//	UI GetPath suite.
//-------------------------------------------------------------------------------

/// Unique identifier for the Get Path Suite.
#define kPSGetPathSuite 			"Photoshop GetPath Suite for Plug-ins"

//-------------------------------------------------------------------------------
//	
//-------------------------------------------------------------------------------

/** Gets the path name from the file specification.
* @param fileSpec File specification.
* @param path [OUT] Path name, returned.
* @param maxLength Maximum length of the path name.
*/
typedef SPAPI void (*GetPathNameProc) (SPPlatformFileSpecification* fileSpec, char* path, int16 maxLength );
typedef SPAPI void (*GetXPlatPathNameProc) (XPlatFileSpec* fileSpec, char* path, int16 maxLength );

//-------------------------------------------------------------------------------
//	 GetPath suite version 1.
//-------------------------------------------------------------------------------

/// Current version for the Get Path Suite.
#define kPSGetPathSuiteVersion1		1
#define kPSGetPathSuiteVersion2		2

/** The routines available in the Get Path Suite. */
typedef struct 
	{
	GetPathNameProc 		GetPathName;	  /**< Function pointer for the \c GetPathNameProc */
	} PSGetPathSuite1;

/** @} */

/** The routines available in the Get Path Suite. */
typedef struct 
	{
	GetXPlatPathNameProc 		GetPathName;	  /**< Function pointer for the \c GetXPlatPathNameProc */
	} PSGetPathSuite2;

/** @} */

//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

//-------------------------------------------------------------------------------
#endif	// PIGetPathSuite
