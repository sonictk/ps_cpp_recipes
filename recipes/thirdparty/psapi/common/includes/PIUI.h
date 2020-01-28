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
//		PIUI.h
//
//	Description:
//		Simple class's for a common interface to UI elements
//		The class routine definitions are actually in PIWinUI.cpp and PIMacUI.cpp
//
//-------------------------------------------------------------------------------
#ifndef __PIUI_H__		// Has this not been defined yet?
#define __PIUI_H__		// Only include this once by predefining it

#include "PIDefines.h"
#include "PITypes.h"
#include "SPPlugs.h"
#include "SPAccess.h"
#include "PIUSuites.h"
#include "PIUtilities.h"
#include "DialogUtilities.h"
#include <string>

using namespace std;

// redefine Mac and Win UI variables to generic types
#if __PIMac__

	typedef Handle		PIItem;
	typedef void*	PIDialogPtr;
	typedef void*	PIMenu;
	typedef void*	PIControl;

	#include <string.h>

#else
	#include <windows.h>
	#include "PIDLLInstance.h"

	typedef HWND PIItem;
	typedef HWND PIDialogPtr;
	typedef HWND PIMenu;

#endif


/*** A dialog class for cross platform dialogs.
	 No Cocoa implementation yet.
*/
class PIDialog {
	int dialogID;
	PIDialogPtr dialog;
	SPPluginRef pluginRef;
public:
	PIDialog() : dialogID(0), dialog(NULL), pluginRef(NULL)  {}
	PIDialog(PIDialogPtr in) : dialog(in), dialogID(0), pluginRef(NULL) {}
	virtual ~PIDialog() {}

	void SetDialog(PIDialogPtr in) { dialog = in; }
	PIDialogPtr GetDialog(void) { return dialog; }

	PIItem GetItem(int32 index);

	void SetID(int ID) { dialogID = ID; }
	int GetID(void) { return dialogID; }

	void SetPluginRef(SPPluginRef plugin) { pluginRef = plugin; }
	SPPluginRef GetPluginRef(void) { return pluginRef; }

	virtual void Init(void) {}
	virtual void Notify(int32) {}

#if __PIWin__
	virtual void Message(UINT wMsg, WPARAM wParam, LPARAM lParam) {}
#endif

	virtual int Modal(SPPluginRef plugin, const char * name, int ID);
};


/** A drop down combo box.
	The entries are zero based.
*/
class PIComboBox {
	PIItem item;
public:
	PIComboBox() : item(NULL) {}
	PIComboBox(PIItem in) : item(in) {}
	~PIComboBox() {}

	void SetItem(PIItem in) { item = in; }
	PIItem GetItem(void) { return item; }

	/// Clear all items in the list
	void Clear(void);
	
	/// Create a new item with this text at the end of the list
	void AppendItem(const string & in);
	
	/// Set this index, zero based, as the current selection
	void SetCurrentSelection(int16 in);
	
	/// Get the text of the current selection, you must delete
	void GetCurrentSelection(string & out);
};

/** A list box
    The entries are zero based.
*/
class PIListBox { 
	#if __PIMac__
		PIComboBox combo; // I cheat on the mac and make a combo box instead
		int32 Init(void);
	#endif
	PIItem item;
public:
	PIListBox();
	PIListBox(PIItem in);
	~PIListBox();

	void SetItem(PIItem in) { item = in; }
	PIItem GetItem(void) { return item; }

	/// Clear all items in the list
	void Clear(void);

	/// Create a new item with this text, items are auto sorted, return value is item location
	int32 AppendItem(const string & in);

	/// Set this index, zero based, as the current selection
	void SetCurrentSelection(int32 in);

	/// Get the text of the current selection, you must delete
	void GetCurrentSelectionText(string & out);
	
	/// Get the index of the current selection
	int32 GetCurrentSelectionIndex(void);

	/// Get the user data from the current selection
	int32 GetUserData(int32 index);

	/// Set the user data on this item
	void SetUserData(int32 index, int32 data);
};

/** A check box
*/
class PICheckBox {
	PIItem item;
public:
	PICheckBox() : item(NULL) {}
	PICheckBox(PIItem in) : item(in) {}
	~PICheckBox() {}

	void SetItem(PIItem in) { item = in; }
	PIItem GetItem(void) { return item; }

	/// Set the text
	void SetText(const string & in);

	// Set the check box state
	void SetChecked(bool state);

	// Get the check box state
	bool GetChecked(void);
};


/**  A text item for static text or edit text boxes
*/
class PIText {
	PIItem item;
public:
	PIText() : item(NULL) {}
	PIText(PIItem in) : item(in) {}
	~PIText() {}

	/// Set the internal item
	void SetItem(PIItem in) { item = in; }

	/// Get the internal item
	PIItem GetItem(void) { return item; }

	/// Set the text
	void SetText(const string & in);

	/// Get the text, you must delete
	void GetText(string & out);
};


/** A grouping of radio buttons.
	All items are based on the ID of the dialog item
*/
class PIRadioGroup {
	int32 firstItem;
	int32 lastItem;
	PIDialogPtr dialog;
public:
	/// Default create with invalid item ids
	PIRadioGroup() : firstItem(-1), lastItem(-1), dialog(NULL) {}
	~PIRadioGroup() {}

	/// Set the dialog item ids of the grouping
	void SetGroupRange(int32 first, int32 last);

	/// Set the dialog reference
	void SetDialog(PIDialogPtr d) { dialog = d; }

	/// Set the current dialog item id in the group
	void SetSelected(int32 s);

	/// Return the current item id in the group
	int32 GetSelected(void);
};


PIItem PIGetDialogItem(PIDialogPtr dialog, int16 itemNumber);
void DoAbout(SPPluginRef plugin, int dialogID);

/// Makes a copy of the c string and converts to pascal string
void CToPStringCopy(StringPtr dst, const string & src);

/// Makes a copy of the pascal string and converts to a c string
void PToCStringCopy(string & dst, const StringPtr src);


#if __PIMac__
	/// Mac only, Get the menu handle from this item handle
	PIMenu PIGetMenuHandleFromItemHandle(PIItem itemHandle);
	
/** Mac only to fix up the resource chain.
*/	
class ResContext {
	short oldContext;
public:
	ResContext(SPPluginRef pluginRef);
	~ResContext();
};


#endif // end __PIMac__ 
#endif // end __PIUI_H__
// end PIUI.h