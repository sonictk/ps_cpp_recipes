// ADOBE SYSTEMS INCORPORATED
// Copyright  2003 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 * \file PIAliasSuite.h
 *
 * \brief This file describes Photoshop's Alias Suite for plug-ins.
 *
 * Distribution:
 *	PUBLIC
 *
 */

/**
* @defgroup PicaAliasSuite Allias Suite 
* Allows plug-ins to create aliases. 
*
* <b> Accessing the Suite </b> \n\n
* The Alias suite is referred to as:
* @code
  #define kPSAliasSuite				"Photoshop Alias Utility Suite"
@endcode
* The current version of the Alias suite:
* @code
  #define kPSAliasSuiteVersion1		1
@endcode
* The suite is acquired as follows:
* @code
  PSAliasSuite *sPSAlias;
  error = sSPBasic->AcquireSuite(kPSAliasSuite,
  								 kPSAliasSuiteVersion1, 	  
  								 &sPSAlias);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/


#pragma once

#ifndef __PIAliasSuite__
#define __PIAliasSuite__

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
//	UI Alias suite.
//-------------------------------------------------------------------------------
/// Unique identifier for the Alias Suite.
#define kPSAliasSuite				"Photoshop Alias Utility Suite"


//-------------------------------------------------------------------------------
//	
//-------------------------------------------------------------------------------

/**
* NOTE that on the Mac, this suite should be considered deprecated as of
* Photoshop 17.0. Please use bookmarks instead. See GetBookmark and
* PutBookmark function documentation in the ActionDescriptor and ActionList
* suites.
*/

/** 
* Makes a new Mac OS alias from a C String.
* @deprecated Please use NSURL functions to create bookmarks instead
* @param cStringPathToFile The C string from which to make an alias.
* @param alias [OUT] The alias, returned.
* @returns Non-zero error if failure.
*/
typedef	SPAPI SPErr			(*MacNewAliasFromCStringProc) (const char *cStringPathToFile, AliasHandle *alias  );

/** 
* Makes a new Mac OS alias from a file specification reference.
* @deprecated Please use NSURL functions to create bookmarks instead
* @param fsRefToFile The file specification reference from which to make an alias.
* @param alias [OUT] The alias, returned.
* @returns Non-zero error if failure.
*/
typedef	SPAPI SPErr			(*MacNewAliasFromFSRefProc)( const void *fsRefToFile, AliasHandle *alias  );
	
/** 
* Makes a new Mac OS alias from a file specification directory reference and a C String.
* @deprecated Please use NSURL functions to create bookmarks instead
* @param cStringPathToFile The C string from which to make an alias.  This is the file name.
* @param fsRefToParentDir The file specification directory reference from which to make an alias. This is the path to the file.
* @param alias [OUT] The alias, returned.
* @returns Non-zero error if failure.
*/
typedef	SPAPI SPErr			(*MacNewAliasFromNameAndFSRefProc)( const void *cfStringFilename, const void *fsRefToParentDir, AliasHandle *alias );
	
/** 
* Makes a new Windows alias from a Unicode string path.
* @param filePathAsUTF16 The file path encoded in UTF16.
* @param alias [OUT] The alias, returned.
* @returns Non-zero error if failure.
*/
typedef	SPAPI SPErr			(*WinNewAliasFromWidePathProc)( const uint16 *filePathAsUTF16, AliasHandle *alias );

/** 
* Makes a new Windows alias from a PIDL.
* @param pidlToFile
* @param alias [OUT] The alias, returned.
* @returns Non-zero error if failure.
*/
typedef	SPAPI SPErr			(*WinNewAliasFromPIDLProc)( const void *pidlToFile, AliasHandle *alias );


//-------------------------------------------------------------------------------
//	 Alias suite version 1.
//-------------------------------------------------------------------------------

/// Current version of the Alias Suite
#define kPSAliasSuiteVersion1		1

/** The set of routines available in the Alias Suite*/
typedef struct 
	{
		MacNewAliasFromCStringProc MacNewAliasFromCString;			 /**< Function pointer to \c MacNewAliasFromCStringProc. */
		MacNewAliasFromFSRefProc MacNewAliasFromFSRef;				 /**< Function pointer to \c MacNewAliasFromFSRefProc. */
		MacNewAliasFromNameAndFSRefProc MacNewAliasFromNameAndFSRef; /**< Function pointer to \c MacNewAliasFromNameAndFSRefProc. */
		WinNewAliasFromWidePathProc WinNewAliasFromWidePath;		 /**< Function pointer to \c WinNewAliasFromWidePathProc. */
		WinNewAliasFromPIDLProc WinNewAliasFromPIDL;				 /**< Function pointer to \c WinNewAliasFromPIDLProc. */
	} PSAliasSuite;


//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

/** @} */
#endif // __PIAliasSuite__

