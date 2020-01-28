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
/**
 * \file PIProgressSuite.h
 *
 * \brief This file describes Photoshop's Progress Suite for plug-ins
 *
 * \details
 * Copyright 1986-2000 Adobe Systems Incorporated.
 * All Rights Reserved.
 *
 * Distribution:
 *	PUBLIC
 *
 * Version history:
 *	1.0.0 4/1/1998	Ace	First Version.
 *		Created by Andy Coven.
 */

/**
* @defgroup PicaProgressSuite Progress Suite
* The Progress Suite provides a set of routines that allows the plug-in
* control over the display of the progress bar.
* The Progress Suite is available in Adobe Photoshop 5.0 and later.
*
* <b> Accessing the Suite </b> \n\n
* The Progress suite is referred to as:
* @code
  #define kPSProgressSuite 			"Photoshop Progress Suite for Plug-ins"
@endcode
* The current version of the Progress suite:
* @code
  #define kPSProgressSuiteVersion2		2
@endcode
* The suite is acquired as follows:
* @code
  PSProgressSuite1 *sPSProgress;
  error = sSPBasic->AcquireSuite(kPSProgressSuite,
  								 kPSProgressSuiteVersion2,
  								 &sPSProgress);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/


#ifndef __PIProgressSuite__
#define __PIProgressSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"

#include "ASPreInclude.h"
#include "ASZStringSuite.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Progress Suite.
#define kPSProgressSuite 			"Photoshop Progress Suite for Plug-ins"


//-------------------------------------------------------------------------
//	Progress suite typedefs 
//-------------------------------------------------------------------------

/** Performs the task defined by \c proc within a new progress scope. Call the task
* APIs to control progression of the progress bar.
* @param proc The procedure to execute as a task.
* @param refCon This data pointer gets passed through to \c proc
* @returns The error code returned from \c proc. 
*/
typedef SPErr (*Progress_DoProgress) (const ASZString zs, SPErr (*proc) (void *), void *refCon);

/** Performs the task defined by \c proc within a new progress scope. Forces the progress
* bar to display always and immediately, ignoring the normal heuristics that keep it from
* showing unnecessarily (e.g. during very short tasks). Call the task APIs to control
* progression of the progress bar.
* @param proc The procedure to execute as a task.
* @param refCon This data pointer gets passed through to \c proc
* @returns The error code returned from \c proc. 
*/
typedef SPErr (*Progress_DoForcedProgress) (const ASZString zs, SPErr (*proc) (void *), void *refCon);

/** Sections off a portion of the unused progress bar for execution of the subtask defined by
* \c proc.
* @param taskLength The length of the progress bar to section off. Should be between 0.0 and 1.0. 
* @param proc The procedure to execute as a subtask.
* @param refCon This data pointer gets passed through to \c proc
* @returns The error code returned from \c proc. 
*/
typedef SPErr (*Progress_DoTask) (real64 taskLength, SPErr (*proc) (void *), void *refCon);


/** 
* Limits progress to a section of the progress bar based on executing
* \c segmentLength out of \c total steps.
* @param segmentLength
* @param done [OUT] A counter of how much has been accomplished so far. 
* This is incremented by \c segmentLength if the task
* succeeds. (We need \c done because, as with \c DoTask, we care about 
* the percentage of the remaining progress bar.)
* @param total The total number of steps.
* @param proc The procedure to execute as a segment of a task.
* @param refCon This data pointer gets passed through to \c proc
* @returns The error code returned from \c proc.
*/
typedef SPErr (*Progress_DoSegmentTask) (int32 segmentLength,
										 int32 *done,
										 int32 total,
										 SPErr (*proc) (void *),
										 void *refCon);


/**
* Changes the current text in the progress bar.
* @param zs The text to display in the progress bar.
*/
typedef void (*Progress_ChangeProgressText) (const ASZString zs);


/**
* Performs a task using the preview sniffing logic. This aborts if 
* Photoshop encounters an event that meets the conditions indicated by \c selector. 
* @param selector The conditions that indicate when to abort the procedure.
* Should be one of the following:
* - "up"	 Continue processing while mouse is up. Abort when mouse down or key stroke.
* - "down"	 Continue processing while mouse is down. Abort when mouse is released.
* - "paused" Continue processing while mouse is still. Abort when mouse is moved or released.
* - NULL Causes the code to choose between "up" and "paused"
* dependent on the current mouse state.
* @param proc The procedure to execute..
* @param refCon This data pointer gets passed through to \c proc
* @returns The error code returned from \c proc, or an error resulting from
* an invalid \c selector value.
*/
typedef SPErr (*Progress_DoPreviewTask) (const char *selector,
										SPErr (*proc) (void *),
					 					void *refCon);


/** Runs a task with the watch cursor up.
* @param proc The procedure to execute.
* @param refCon
* @returns The error code returned from \c proc.
*/
typedef SPErr (*Progress_DoWatchTask) (SPErr (*proc) (void *), void *refCon);


/** Runs a task without the watch cursor. This doesn't actually take the watch
* cursor down, but it does keep the watch from spinning.
* @param proc The procedure to execute.
* @param refCon This data pointer gets passed through to \c proc
* @returns The error code returned from \c proc.
*/
typedef SPErr (*Progress_DoSuspendedWatchTask) (SPErr (*proc) (void *), void *refCon);

typedef void (*Progress_ContinueWatchCursor) (void);


//-------------------------------------------------------------------------
//	Progress suite version 1
//-------------------------------------------------------------------------

/// Progress suite, version 1.
#define kPSProgressSuiteVersion1		1

/** The set of routines available in the Progress Suite. */
typedef struct 
{
	Progress_DoProgress					DoProgress;			  /**< Function pointer to \c Progress_DoProgress. */
	Progress_DoTask						DoTask;			      /**< Function pointer to \c Progress_DoTask. */
	Progress_DoSegmentTask				DoSegmentTask;		  /**< Function pointer to \c Progress_DoSegmentTask. */
	Progress_ChangeProgressText			ChangeProgressText;	  /**< Function pointer to \c Progress_ChangeProgressText. */
	Progress_DoPreviewTask				DoPreviewTask;		  /**< Function pointer to \c Progress_DoPreviewTask. */
	Progress_DoWatchTask				DoWatchTask;		  /**< Function pointer to \c Progress_DoWatchTask. */
	Progress_DoSuspendedWatchTask		DoSuspendedWatchTask; /**< Function pointer to \c Progress_DoSuspendedWatchTask. */
	Progress_ContinueWatchCursor		ContinueWatchCursor;  /**< Function pointer to \c Progress_ContinueWatchCursor. */

//	The following are taken from from the parameter block and are defined in PIGeneral.h:
	TestAbortProc						TestAbort;			 /**< Function pointer to \c TestAbortProc. */
	ProgressProc						UpdateProgress;		 /**< Function pointer to \c ProgressProc. */
		
} PSProgressSuite1;

//-------------------------------------------------------------------------
//	Progress suite version 2
//-------------------------------------------------------------------------

/// Progress suite, version 2.
#define kPSProgressSuiteVersion2		2

/** The set of routines available in the Progress Suite. */
typedef struct 
{
	Progress_DoProgress					DoProgress;			  /**< Function pointer to \c Progress_DoProgress. */
	Progress_DoForcedProgress			DoForcedProgress;	  /**< Function pointer to \c Progress_DoForcedProgress. */
	Progress_DoTask						DoTask;			      /**< Function pointer to \c Progress_DoTask. */
	Progress_DoSegmentTask				DoSegmentTask;		  /**< Function pointer to \c Progress_DoSegmentTask. */
	Progress_ChangeProgressText			ChangeProgressText;	  /**< Function pointer to \c Progress_ChangeProgressText. */
	Progress_DoPreviewTask				DoPreviewTask;		  /**< Function pointer to \c Progress_DoPreviewTask. */
	Progress_DoWatchTask				DoWatchTask;		  /**< Function pointer to \c Progress_DoWatchTask. */
	Progress_DoSuspendedWatchTask		DoSuspendedWatchTask; /**< Function pointer to \c Progress_DoSuspendedWatchTask. */
	Progress_ContinueWatchCursor		ContinueWatchCursor;  /**< Function pointer to \c Progress_ContinueWatchCursor. */

//	The following are taken from from the parameter block and are defined in PIGeneral.h:
	TestAbortProc						TestAbort;			 /**< Function pointer to \c TestAbortProc. */
	ProgressProc						UpdateProgress;		 /**< Function pointer to \c ProgressProc. */
		
} PSProgressSuite2;

/******************************************************************************/

#ifdef __cplusplus
}
#endif


/** @} */
#endif	// PIProgressSuite
