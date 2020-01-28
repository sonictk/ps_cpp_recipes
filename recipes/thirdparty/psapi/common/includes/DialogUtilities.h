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
//		DialogUtilities.h
//
//
//	Description:
//		This library contains the prototypes, macros, and defines
//		related to common dialog manipulation. All dialog API's
//		are defined here. The implementation may be OS specific
//		and would be found in DialogUtilitesWin.cpp or
//		DialogUtilitiesMac.cpp
//
//	Use:
//		DialogUtilities is intended to make dialog manipulation a 
//		little simpler by providing a standard suite of functions.
//		Use these routines for whatever you	need, and feel free to
//		tweak them for your own work.  They expect for gStuff to
//		be a valid pointer to your global structure's parameter
//		block.
//
//-------------------------------------------------------------------------------
 
#ifndef __DialogUtilities_H__ 	// Has this not been defined yet?
#define __DialogUtilities_H__ 	// Only include this once by predefining it

#include "PIDefines.h"

#ifdef __PIWin__ // Windows only
	#include <limits.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	#include <windows.h>
	#include <windowsx.h>
	#include <errno.h>

	typedef HWND DialogPtr;
	typedef HWND DialogTHndl;
#else // Macintosh and others
#endif

#include "PITypes.h"			// Photoshop types
#include "PIGeneral.h"			// Photoshop general routines
#include "PIAbout.h"
#include "PIUtilities.h"		// SDK Utility routines
#include "PIUSuites.h"			// AutoSuite definition
#include "PIGetFileListSuite.h" // URL browser function
#include "PIUIHooksSuite.h"		// idle event processing function
#include <stdio.h>

//-------------------------------------------------------------------------------
// C++ wrapper
//-------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//-------------------------------------------------------------------------------
//	Prototypes -- Alerts
//-------------------------------------------------------------------------------

// Display a cross-platform alert with a version number:
#if __LP64__
short ShowVersionAlert (void* dp,
						const short alertID, 
						const short stringID,
						unsigned char* versText1,
						unsigned char* versText2);
    
// pop an about box:
void ShowAbout (const short dialogID);

#else
short ShowVersionAlert (DialogPtr dp,
						const short alertID, 
						const short stringID,
						Str255 versText1,
						Str255 versText2);
#endif

#if __PIWin__
    
// Display a cross-platform caution alert from a string:
// alertType should be PIAlertStop or PIAlertCaution (default)
short ShowAlertType (DialogPtr dp,
				     short alertID, 
				     short stringID, 
				     Str255 minText, 
				     Str255 maxText,
				     const short alertType);

//-------------------------------------------------------------------------------
//	Alert constants and macros
//-------------------------------------------------------------------------------

enum
{ // constants defined for alert routine

	PIAlertCaution,
	PIAlertStop
};

// Macro to pop a cross-platform caution alert:
#define ShowCaution(dp, alertID, stringID, min, max)	\
	ShowAlertType(dp, alertID, stringID, min, max, PIAlertCaution)
	
// Macro to pop a cross-platform stop alert:
#define ShowStop(dp, alertID, stringID, min, max)	\
	ShowAlertType(dp, alertID, stringID, min, max, PIAlertStop)

//-------------------------------------------------------------------------------
//	Prototypes -- About dialogs
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//	Prototypes -- Dialog initialization and handling
//-------------------------------------------------------------------------------

// center a dialog template 1/3 of the way down on the main screen:
void CenterDialog (DialogTHndl dt);

//-------------------------------------------------------------------------------
//	Dialog handling -- Constants and macros
//-------------------------------------------------------------------------------

// Used by MoveableModalDialog, PerformStandardDialogItemHandling:
#define RETURN	0x0D
#define ENTER	0x03
#define PERIOD	'.'
#define ESCAPE	0x1B
#define	TAB		'\t'

// Standard MenuBar height, used by CenterDialog:
#define MenuHeight	20

//-------------------------------------------------------------------------------
//	Prototypes -- Dialog outline buttons and groups
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//	Prototypes -- Text manipulation
//-------------------------------------------------------------------------------

// The following routine selects an edit text item:
void SelectTextItem (DialogPtr dp, const short item);

// The following routine extracts the text of a text item:
void FetchText (DialogPtr dp, const short item, Str255 text);

// The following routine sets the text of a text item:
void StuffText (DialogPtr dp, const short item, Str255 text);

//-------------------------------------------------------------------------------
//	Prototypes -- Number manipulation, range checking and reporting
//-------------------------------------------------------------------------------

// The following routine stuffs a value into a text field:
void StuffNumber (DialogPtr dp, const short item, const int32 value);

// The following routine retrieves the value from a text field.
// It will do range checking and pin the number to bounds.  It
// returns noErr (0) if it gets a valid value in the field:
short FetchNumber (DialogPtr dp,
 					  const short item,
					  const int32 min,
					  const int32 max,
					  int32 *value);

// This corresponding alert routine will pop a dialog telling the user the
// range was not valid:
void AlertNumber (DialogPtr dp,
				  const short item,
				  const int32 min,
				  const int32 max,
				  int32 *value,
				  const short alertID,
				  const short numberErr);
				  				 
// Stuffs a double value into a text field:
void StuffDouble (DialogPtr dp, 
				  const short item,
				  const double value,
				  const short precision);
 
// The following routine retrieves a double value from a text field.
// It will do range checking and pin the number to bounds.  It
// returns noErr (0) if it gets a valid value in the field:
short FetchDouble (DialogPtr dp,
					 const short item,
					 const double min,
					 const double max,
					 double *value);

// This corresponding alert routine will pop a dialog telling the user the
// range was not valid:
void AlertDouble (DialogPtr dp,
				  const short item,
				  const double min,
				  const double max,
				  double *value,
				  const short alertID,
				  const short numberErr);
					 
//-------------------------------------------------------------------------------
//  Number manipulation, range checking and reporting -- constants
//-------------------------------------------------------------------------------

enum
{ // return values for Fetch routines (FetchNumber, FetchDouble, etc.)

	// noErr = 0
	errOutOfRange = 1,
	errNotANumber
};

//-------------------------------------------------------------------------------
//	Prototypes -- Setting check box, radio button, pop-up menu and group states
//-------------------------------------------------------------------------------

// Perform standard handling for check boxes and radio buttons. For radio
// buttons, we assume that the group for the radio button extends forward
// and backward in the DITL as long as the item type is radio button:
void ProcessChecksAndRadios (DialogPtr dp, const short item);
						  
// Set the state of a check box (or radio button):
void SetCheckBoxState (DialogPtr dp, const short item, const bool checkIt);

// Determine the state of a check box (or radio button):
bool GetCheckBoxState (DialogPtr dp, const short item);

// Toggle a check box and return the new state:
bool ToggleCheckBoxState (DialogPtr dp, const short item);

// Set a radio group (from first to last item) to reflect the selection:
void SetRadioGroupState (DialogPtr dp,
						 const short first,
						 const short last,
						 const short item);
						 
// Get the selected button within a radio group:
short GetRadioGroupState (DialogPtr dp,
						  const short first,
						  const short last);

// Set the value for a pop-up menu:
void SetPopUpMenuValue (DialogPtr dp,
						const short item,
						const short newValue);

// Get the value for a pop-up menu:
short GetPopUpMenuValue (DialogPtr dp,
						 const short item);

//-------------------------------------------------------------------------------
//	Prototypes -- Showing, hiding, enabling and disabling items
//-------------------------------------------------------------------------------

// Utility routine to show or hide an item:
void ShowHideItem (DialogPtr dp, const short inItem, const bool inState);

// Utility routine to disable (grey) a control:
void PIDisableControl (DialogPtr dp, const short inItem);

// Utility routine to enable a control:
void PIEnableControl (DialogPtr dp, const short inItem);

// Utility routine to enable (TRUE) or disable (FALSE) a control:
void EnableDisableControl (DialogPtr dp, const short inItem, const bool inState);

//-------------------------------------------------------------------------------
//	Prototypes -- misc
//-------------------------------------------------------------------------------

// Utility routine to invalidate an item:
void InvalItem (DialogPtr dp, short item);

// Little routine to flash a button set off by a keystroke:
void FlashDialogButton (DialogPtr dp, short item);

#if __PIWin__
	//-------------------------------------------------------------------------------
	//	Prototypes -- specific to the Macintosh OS
	//-------------------------------------------------------------------------------
	void ShowAbout(AboutRecordPtr aboutPtr);

	// Sets the default dialog item */
	void SetDialogDefaultItem(DialogPtr dp, const short item);

	// About box control items
	// the ok and cancel buttons are hidden
	const int OK			= 1;
	const int CANCEL		= 2;
	const int MESSAGE		= 3;
	const int ADOBEURL		= 4;
	const int PARTNERSURL	= 5;

	#define SetRadioGroupState(dp, first, last, item)	\
		CheckRadioButton(dp, first, last, item)

	#define SetCheckBoxState(dp, item, state)	\
		CheckDlgButton(dp, item, state)

	#define GetCheckBoxState(dp, item)	\
		IsDlgButtonChecked(dp, item)

	#define StuffNumber(dp, item, value)	\
		SetDlgItemInt(dp, item, value, TRUE)

	#define GETWSTYLE(X)         GetWindowLong((HWND)X, GWL_STYLE)
	#define COMMANDWND(lParam)   (HWND)(UINT)lParam
	#define COMMANDID(X)         LOWORD(X)

	#ifdef WIN32
		#define COMMANDCMD(X, Y)	HIWORD(X)
		#define huge
		#ifndef PDECL
			#define PDECL
		#endif
	#else
		#define COMMANDCMD(X, Y)	HIWORD(Y)
	#endif


#else
	//-------------------------------------------------------------------------------
	//	Prototypes -- specific to the Macintosh OS
	//-------------------------------------------------------------------------------

	// pop an about box:
	void ShowAbout (const short dialogID);

	// Run a moveable modal dialog (use instead of ModalDialog)						 
	// DON'T CALL THIS WITH NON-MOVEABLE MODALS, IT WILL CRASH
	void MoveableModalDialog (DialogPtr dp,
							  ProcessEventProc processEvent,
							  ModalFilterProcPtr filter,
							  short *item);
							  
	// Except within the filter procedure for such moveable modal dialogs, we need
	// to call the following routine to get the window refcon since
	// MoveableModalDialog stomps it.
	int32 GetMoveableWRefCon (DialogPtr dp);

	// Dialog filter proc to handle and dispatch basic events:
	static pascal Boolean DialogFilter (DialogPtr dp,
										EventRecord *event,
										short *item);
										
	// Used in DialogFilter, MoveableModalDialog, GetMoveableWRefCon:
	typedef struct ModalData
	{
		int32 oldRefCon; // old reference value
		
		// ModalFilterProcPtr is defined as: typedef pascal bool
		// (*ModalFilterProcPtr)(DialogPtr theDialog,
		//						 EventRecord *theEvent,
		//						 short *itemHit)
		ModalFilterProcPtr filter;
		
		ProcessEventProc processEvent; // Basic event processor in Events.h
		
	} ModalData;

	extern	UserItemUPP gUserItemOutlineOK;
	extern	UserItemUPP gUserItemOutlineGroup;	
	extern	ModalFilterUPP gFilterProc;

	// Set an item hook so that it will outline the OK button in a dialog:
	void SetOutlineOK (DialogPtr dp, const short item);

	// Dialog proc to outline the OK button:
	static pascal void OutlineOK (DialogPtr dp, const short item);

	// The following routine sets a user item to be a group box.  It expects
	// the next item to be the title for the group box:
	void SetOutlineGroup (DialogPtr dp, const short item);

	// Dialog filter proc to outline a group:
	static pascal void OutlineGroup (DialogPtr dp, const short item);

#endif

#endif
    
//-------------------------------------------------------------------------------
// C++ wrapper
//-------------------------------------------------------------------------------

#ifdef __cplusplus
} // End of extern "C" block.
#endif // __cplusplus

//-------------------------------------------------------------------------------

#endif // __DialogUtilities_H__
