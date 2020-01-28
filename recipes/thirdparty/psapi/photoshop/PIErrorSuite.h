// ADOBE SYSTEMS INCORPORATED
// (c) Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
//-------------------------------------------------------------------------------
/**
 *	\file PIErrorSuite.h
 *
  *	\brief This file contains the public definitions and structures
 *		used by plug-ins to manage asserts, debugging, and returning
 *		errors to the host.
 *
 *	Distribution:
 *		PUBLIC
 *
 */
//-------------------------------------------------------------------------------

/**
* @defgroup PicaErrorSuite Error Suite 
* The Error Suite provides a way to display error strings to the user in any format. 
* Photoshop always makes a copy of the string passed in.  The Error Suite is available in
* Adobe Photoshop 5.0 and later.
*
* <b> Accessing the Suite </b> \n\n
* The Error suite is referred to as:
* @code
  #define kPSErrorSuite			"Photoshop Error Suite for Plug-ins"
@endcode
* The current version of the error suite:
* @code
  #define kPSErrorSuiteVersion1	1
@endcode
* The suite is acquired as follows:
* @code
  PSErrorSuite1 *sPSErrors;
  error = sSPBasic->AcquireSuite(kPSErrorSuite,
  								 kPSErrorSuiteVersion1, 	  
  								 &sPSErrors);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/

#ifndef __PIErrorSuite_h__ // Already defined?
#define __PIErrorSuite_h__

//-------------------------------------------------------------------------------
//	Includes and alignment.
//-------------------------------------------------------------------------------

#ifndef __ASPREINCLUDE__
#include "ASPreInclude.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------
//	Error suite version 1.
//-------------------------------------------------------------------------------

/// Unique identifier for the Error Suite.
#define kPSErrorSuite			"Photoshop Error Suite for Plug-ins"
/// Current version of the Error Suite.
#define kPSErrorSuiteVersion1	1

//-------------------------------------------------------------------------------
//	Error suite typedefs.
//-------------------------------------------------------------------------------

/** Hands the host a Pascal string containing the error string to display to the user.
* @param errorString The Pascal string to display to the user.
* The host makes a copy.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*SetErrorFromPStringProc) (/* IN */ const Str255 errorString);

/// Hand the host a C string containing the error string to display to the user.
/// The host will make a copy:
/** Hands the host a C string containing the error string to display to the user.
* @param errorString The C string to display to the user.
* The host makes a copy.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*SetErrorFromCStringProc) (/* IN */ const char* errorString);

/** Hands the host a ZString containing the error string to display to the user.
* @param zString The ZString to display to the user.
* The host makes a copy.
* @returns Non-zero error if failure.
*/

#ifndef ASZString_defined
#define ASZString_defined
struct ASZByteRun;
typedef struct ASZByteRun *ASZString;
#endif

typedef SPAPI SPErr (*SetErrorFromZStringProc) (/* IN */ const ASZString zString);

/** The set of routines available in the Error Suite. */
typedef struct PSErrorSuite1
	{
	SetErrorFromPStringProc	SetErrorFromPString;  /**< Function pointer for \c SetErrorFromPStringProc. */
	SetErrorFromCStringProc SetErrorFromCString;  /**< Function pointer for \c SetErrorFromCStringProc. */
	SetErrorFromZStringProc SetErrorFromZString;  /**< Function pointer for \c SetErrorFromZStringProc. */
	} PSErrorSuite1;
	
//-------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif
/** @} */

#endif // PIErrorSuite.h
