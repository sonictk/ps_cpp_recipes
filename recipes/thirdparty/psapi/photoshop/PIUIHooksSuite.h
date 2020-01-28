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
 * \file PIUIHooksSuite.h
 *
 * \brief This file contains all the public definitions and
 *	structures related to user interface elements.
 *
 * \details
 *	Use the UIHooks suite to get the main application
 *	window (on Windows), access a handful of Photoshop
 *	cursors, and similar utilities.
 *
 * Distribution:
 *	PUBLIC
 *
 */


/**
* @defgroup PicaUIHooksSuite UI Hooks Suite
* The UI Hooks suite is a set of utilities that 
* allows a plug-in module to get and set certain values in the Photoshop.
* The UI Hooks suite is available in Adobe Photoshop 5.0 and later.
*
* <b> Accessing the Suite </b> \n\n
* The UI Hooks suite is referred to as:
* @code
  #define kPSUIHooksSuite 			"Photoshop UIHooks Suite for Plug-ins"
@endcode
* There are three versions of the UI Hooks Suite suite:
* @code
  #define kPSUIHooksSuiteVersion1		1 
  #define kPSUIHooksSuiteVersion2		2 
  #define kPSUIHooksSuiteVersion3		3 
@endcode
* The suite is acquired as follows:
* @code
  PSUIHooksSuite3 *sPSUIHooks;

  // Get the most recent version.
  error = sSPBasic->AcquireSuite(kPSUIHooksSuite,
  								 kPSUIHooksSuiteVersion3, 	  
  								 &sPSUIHooks);

  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/

#ifndef __PIUIHooksSuite__
#define __PIUIHooksSuite__

#if PRAGMA_ONCE
#pragma once
#endif

//-------------------------------------------------------------------------------
//	Includes.
//-------------------------------------------------------------------------------
#include "PIGeneral.h"
#include "PIActions.h"
#include "SPTypes.h"

//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------
//	UI hooks suite.
//-------------------------------------------------------------------------------

///Unique identifier for the UI Hooks Suite.
#define kPSUIHooksSuite 			"Photoshop UIHooks Suite for Plug-ins"

//-------------------------------------------------------------------------------
//	Error codes.
//-------------------------------------------------------------------------------
/** @name UI Hooks Error Codes */
//@{
#define kPSCursorError				'!cur'	   /**< Invalid cursor ID. */
#define kPSNoLocalizedNameError		'!LoC'	   /**< Localized name not found. */
//@}
/** @} */	  // close defgroup, because I don't want CursorIDs to appear in it.

//-------------------------------------------------------------------------------
//	SetCursor.  Sets cursor to some popular Photoshop cursors.  Mac and Win.
//-------------------------------------------------------------------------------

/** @defgroup CursorIDs Photoshop Cursor IDs
* @{
*/
// Cursor IDs:
#define kPICursorNone				NULL
#define kPICursorArrow				"Photoshop Cursor Arrow"
#define kPICursorWatch				"Photoshop Cursor Watch"
#define kPICursorWatchContinue		"Photoshop Cursor Watch Continue"
#define kPICursorMove				"Photoshop Cursor Move"
#define kPICursorHand				"Photoshop Cursor Hand"
#define kPICursorGrab				"Photoshop Cursor Grab"
#define kPICursorZoomIn				"Photoshop Cursor Zoom In"
#define kPICursorZoomOut			"Photoshop Cursor Zoom Out"
#define kPICursorZoomLimit			"Photoshop Cursor Zoom Limit"
#define kPICursorPencil				"Photoshop Cursor Pencil"
#define kPICursorEyedropper			"Photoshop Cursor Eyedropper"
#define kPICursorEyedropperPlus		"Photoshop Cursor Eyedropper Plus"
#define kPICursorEyedropperMinus	"Photoshop Cursor Eyedropper Minus"
#define kPICursorBucket				"Photoshop Cursor Bucket"
#define kPICursorCrosshair			"Photoshop Cursor Crosshair"
#define kPICursorType				"Photoshop Cursor Type"
#define kPICursorPathArrow			"Photoshop Cursor Path Arrow"
/** @} */

/** @ingroup PicaUIHooksSuite */
typedef const char* PICursor_t;	   /**< Cursor ID. Used with @ref CursorIDs. */


/** @ingroup PicaUIHooksSuite */
/** 
* Sets the host cursor.
* @param cursorID The ID of the cursor to set.  See @ref CursorIDs.
* @returns \c kPSCursorError if invalid cursor. 
*/	
typedef SPAPI SPErr (*HostSetCursorProc) (const PICursor_t cursorID);
	
//-------------------------------------------------------------------------------
//	MainAppWindow.  Returns Windows parent window HWND, NULL on Mac.
//-------------------------------------------------------------------------------
/** @ingroup PicaUIHooksSuite */
/**
* Gets a handle to the main application window for Windows.  This is
* the front-most window.
* @returns Windows parent window \c HWND, NULL on Mac OS.
*/
typedef SPAPI intptr_t (*MainAppWindowProc) (void);		//64bits - API

//-------------------------------------------------------------------------------
//	TickCount.  Gets the tick count as 60 ticks per second.  Mac and Win.
//-------------------------------------------------------------------------------
/** @ingroup PicaUIHooksSuite */
/**
* Gets the tick count as 60 ticks per second.
* @returns The tick count.
*/
typedef SPAPI uint32 (*HostTickCountProc) (void);		//64bits - API

//-------------------------------------------------------------------------------
//	GetPluginName.  Returns the name of the plugins specified by pluginRef.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
/**
*  Gets the name of the plug-in as specified in \c pluginRef.
* @param pluginRef A reference to a plug-in.  A plug-in reference is
* passed to the plug-in by the host through the plug-in parameter
* block, or through the message data for an automation plug-in.
* @param pluginName [OUT] The name of the plug-in.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*PluginNameProc) (SPPluginRef pluginRef, ASZString *pluginName);

//-------------------------------------------------------------------------------
//	UI hooks suite version 1.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
#define kPSUIHooksSuiteVersion1		1  /**< UI Hooks Suite, version 1. */

/** @ingroup PicaUIHooksSuite */
/** The set of routines available in Version 1 of the UI Hooks Suite. */
typedef struct 
	{
	ProcessEventProc 				processEvent;	/**< Function pointer to \c ProcessEventProc. */
	DisplayPixelsProc				displayPixels;	/**< Function pointer to \c DisplayPixelsProc. */
	ProgressProc					progressBar;	/**< Function pointer to \c ProgressProc. */
	TestAbortProc					testAbort;		/**< Function pointer to \c TestAbortProc. */
	MainAppWindowProc				MainAppWindow;	/**< Function pointer to \c MainAppWindowProc. */
	HostSetCursorProc				SetCursor;		/**< Function pointer to \c HostSetCursorProc. */
	HostTickCountProc				TickCount;		/**< Function pointer to \c HostTickCountProc. */
	PluginNameProc					GetPluginName;	/**< Function pointer to \c PluginNameProc. */

	} PSUIHooksSuite1;

//-------------------------------------------------------------------------------
//	SetPluginMenuEntry.  Sets the menu entry for the Last Filter, Undo, Redo, and
//	History state for only the last filter event.  (Have to set it again on each
//	invocation, if you want it to persist.)  Pass the SPPluginRef to the current
//	plug-in only.
//
//  New in version 2.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
/**
* Sets the menu entry for the Last Filter, Undo, Redo, and
* History state for only the last filter event.  This entry must be set it on each
* invocation, if you want it to persist. 
* @param self Reference to calling (active) filter plug-in.	Must refer to the
* current plug-in only. A plug-in reference is
* passed to the plug-in by the host through the plug-in parameter
* block, or through the message data for an automation plug-in.
* @param menuEntry	Menu string to display in Undo, Redo, Last Filter, and History.
* @param eventID  Event ID to use for any descriptor returned.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*SetPluginMenuEntryProc)
	(
	const SPPluginRef self,			/* Reference to calling (active) filter plug-in. */
	const ASZString menuEntry,		/* String to display in Undo, Redo, Last Filter, and History. */
	const DescriptorEventID eventID	/* Event ID to use for any descriptor returned. */
	);

//-------------------------------------------------------------------------------
//	UI hooks suite version 2.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
#define kPSUIHooksSuiteVersion2		2  /**< UI Hooks Suite, version 2. */

/** @ingroup PicaUIHooksSuite */
/** The set of routines available in Version 2 of the UI Hooks Suite. */
typedef struct 
	{
	ProcessEventProc 				processEvent;		 /**< Function pointer to \c ProcessEventProc. */
	DisplayPixelsProc				displayPixels;		 /**< Function pointer to \c DisplayPixelsProc. */
	ProgressProc					progressBar;		 /**< Function pointer to \c ProgressProc. */
	TestAbortProc					testAbort;			 /**< Function pointer to \c TestAbortProc. */
	MainAppWindowProc				MainAppWindow;		 /**< Function pointer to \c MainAppWindowProc. */
	HostSetCursorProc				SetCursor;			 /**< Function pointer to \c HostSetCursorProc. */
	HostTickCountProc				TickCount;			 /**< Function pointer to \c HostTickCountProc. */
	PluginNameProc					GetPluginName;		 /**< Function pointer to \c PluginNameProc. */
	SetPluginMenuEntryProc			SetPluginMenuEntry;	 /**< Function pointer to \c SetPluginMenuEntryProc. */

	} PSUIHooksSuite2;
	
//-------------------------------------------------------------------------------
//	GetLocalizedFileName.  Given a ZString, returns the "localized" version of
//  the string using the run-time filename localization support added for Elements 3.
//  If no localized name is found, kPSNoLocalizedNameError is returned. Photoshop always
//  returns kSPUnimplementedError
//
//  New in version 3.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
/**
* Gets the "localized" version of
* the string using the runtime filename localization support; added for <b> Elements 3 </b>.
* @param inOriginalString String for which a localized version is requested. 
* @param outLocalizedString [OUT] Returned localized string.
* @returns 
* - \c kPSNoLocalizedNameError, if no localized name is found. 
* - \c kSPUnimplementedError if the host does not support this function. 
* Photoshop always returns \c kSPUnimplementedError.
*/
typedef SPAPI SPErr (*GetLocalizedFileNameProc)
	(
	const ASZString inOriginalString,		/* String for which a localized version is requested. */
	ASZString *outLocalizedString			/* Returned localized string. */
	);
	
//-------------------------------------------------------------------------------
//	UI hooks suite version 3.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
#define kPSUIHooksSuiteVersion3		3	  /**< UI Hooks Suite, version 3 */

/** @ingroup PicaUIHooksSuite */
/** The set of routines available in Version 3 of the UI Hooks Suite. */
typedef struct 
	{
	ProcessEventProc 				processEvent;			  /**< Function pointer to \c ProcessEventProc. */
	DisplayPixelsProc				displayPixels;			  /**< Function pointer to \c DisplayPixelsProc. */
	ProgressProc					progressBar;			  /**< Function pointer to \c ProgressProc. */
	TestAbortProc					testAbort;				  /**< Function pointer to \c TestAbortProc. */
	MainAppWindowProc				MainAppWindow;			  /**< Function pointer to \c MainAppWindowProc. */
	HostSetCursorProc				SetCursor;				  /**< Function pointer to \c HostSetCursorProc. */
	HostTickCountProc				TickCount;				  /**< Function pointer to \c HostTickCountProc. */
	PluginNameProc					GetPluginName;			  /**< Function pointer to \c PluginNameProc. */
	SetPluginMenuEntryProc			SetPluginMenuEntry;		  /**< Function pointer to \c SetPluginMenuEntryProc. */
	GetLocalizedFileNameProc		GetLocalizedFileName;	  /**< Function pointer to \c GetLocalizedFileNameProc. */

	} PSUIHooksSuite3;

//-------------------------------------------------------------------------------
//	MainAppRootWindow.  Returns Windows application frame HWND, NULL on Mac.
//-------------------------------------------------------------------------------
/** @ingroup PicaUIHooksSuite */
/**
* Gets a handle to the Photoshop application frame window for Windows,
* regardless of what the actual front document window is.  New in version 4.
* @returns Windows parent window \c HWND, NULL on Mac OS.
*/
typedef SPAPI intptr_t (*MainAppRootWindowProc) (void);		//64bits - API


//-------------------------------------------------------------------------------
//	UI hooks suite version 4.
//-------------------------------------------------------------------------------

/** @ingroup PicaUIHooksSuite */
#define kPSUIHooksSuiteVersion4		4	  /**< UI Hooks Suite, version 3 */

/** @ingroup PicaUIHooksSuite */
/** The set of routines available in Version 3 of the UI Hooks Suite. */
typedef struct 
	{
	ProcessEventProc 				processEvent;			  /**< Function pointer to \c ProcessEventProc. */
	DisplayPixelsProc				displayPixels;			  /**< Function pointer to \c DisplayPixelsProc. */
	ProgressProc					progressBar;			  /**< Function pointer to \c ProgressProc. */
	TestAbortProc					testAbort;				  /**< Function pointer to \c TestAbortProc. */
	MainAppWindowProc				MainAppWindow;			  /**< Function pointer to \c MainAppWindowProc. */
	HostSetCursorProc				SetCursor;				  /**< Function pointer to \c HostSetCursorProc. */
	HostTickCountProc				TickCount;				  /**< Function pointer to \c HostTickCountProc. */
	PluginNameProc					GetPluginName;			  /**< Function pointer to \c PluginNameProc. */
	SetPluginMenuEntryProc			SetPluginMenuEntry;		  /**< Function pointer to \c SetPluginMenuEntryProc. */
	GetLocalizedFileNameProc		GetLocalizedFileName;	  /**< Function pointer to \c GetLocalizedFileNameProc. */
	MainAppRootWindowProc			MainAppRootWindow;		  /**< Function pointer to \c MainAppRootWindowProc. */

	} PSUIHooksSuite4;

//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

//-------------------------------------------------------------------------------
#endif	// PIUIHooksSuite
