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
/*
	File: DialogUtilitiesWin.cpp

	C++ source file for MS-Windows specific dialog code
*/

#include "DialogUtilities.h"

BOOL WINAPI AboutDlgProc(HWND hDlg, UINT wMsg, WPARAM wParam, LPARAM lParam);
int LoadLocalString(UINT uID, LPTSTR lpBuffer, int nBufferMax);

/*****************************************************************************/

void  ShowAbout (AboutRecordPtr aboutPtr)
{
	PlatformData * platform = (PlatformData *) (aboutPtr->platformData);
	
	HWND h = (HWND)platform->hwnd;

    DialogBoxParam(GetDLLInstance(), 
		           MAKEINTRESOURCE( AboutID ),
	               h, 
				   (DLGPROC)AboutDlgProc, 
				   0);
}

/*****************************************************************************/

short ShowVersionAlert (HWND hDlg,
						short alertID, 
						short stringID,
						Str255 versText1,
						Str255 versText2)
{
	short 	result = 0;
	Str255	ds = "";
	char	message[kStr255InitLen];
		
	if (alertID)
	{		
		if (stringID > 0)
		{
			LoadLocalString(stringID, message, kStr255MaxLen);
			AppendString(ds, (const unsigned char*)&message, 0, (short)strlen(message));
		} else {
			message[0] = 0;
		}
		
		PIParamText(ds, NULL, versText1, versText2);
		ds [ ++ds[0] ] = 0;
		strncpy(message, (const char *)&ds[1], kStr255MaxLen);

		result = (short)( MessageBox(hDlg, message, NULL, 
									 MB_OK | MB_ICONEXCLAMATION));
	}
	return result;
}

/*****************************************************************************/

short ShowAlertType (HWND hDlg,
					 short alertID, 
					 short stringID, 
					 Str255 minText, 
					 Str255 maxText,
					 short alertType)
{
	short 	result = 0;
	Str255	ds = "";
	char	message[kStr255InitLen];
		
	if (alertID)
	{		
		if (stringID > 0)
		{
			LoadLocalString(stringID, message, kStr255MaxLen);
			AppendString(ds, (const unsigned char*)&message, 0, (short)strlen(message));
		} else {
			message[0] = 0;
		}
		
		PIParamText(ds, NULL, minText, maxText);
		ds [ ++ds[0] ] = 0;
		strncpy(message, (const char *)&ds[1], kStr255MaxLen);

		switch (alertType)
		{
			case PIAlertStop:
				result = (short)(MessageBox(hDlg, message, NULL, MB_OK | MB_ICONSTOP));
				break;
			default:
			case PIAlertCaution:
				result = (short)(MessageBox(hDlg, message, NULL, MB_OK | MB_ICONEXCLAMATION));
				break;
		}
	}
	return result;
}

/*****************************************************************************/

/*******************************************************************************/

/* Centers a dialog template 1/3 of the way down on the main screen */
// This is the same as PIWinUI.cpp version
void CenterDialog(HWND hDlg)
{
	int  nHeight;
    int  nWidth;
    int  nTitleBits;
    RECT rcDialog;
    RECT rcParent;
    int  xOrigin;
    int  yOrigin;
    int  xScreen;
    int  yScreen;
    HWND hParent = GetParent(hDlg);

    if  (hParent == NULL)
        hParent = GetDesktopWindow();

    GetClientRect(hParent, &rcParent);
    ClientToScreen(hParent, (LPPOINT)&rcParent.left);  // point(left,  top)
    ClientToScreen(hParent, (LPPOINT)&rcParent.right); // point(right, bottom)

    // Center on Title: title bar has system menu, minimize,  maximize bitmaps
    // Width of title bar bitmaps - assumes 3 of them and dialog has a sysmenu
    nTitleBits = GetSystemMetrics(SM_CXSIZE);

    // If dialog has no sys menu compensate for odd# bitmaps by sub 1 bitwidth
    if  ( ! (GetWindowLong(hDlg, GWL_STYLE) & WS_SYSMENU))
        nTitleBits -= nTitleBits / 3;

    GetWindowRect(hDlg, &rcDialog);
    nWidth  = rcDialog.right  - rcDialog.left;
    nHeight = rcDialog.bottom - rcDialog.top;

    xOrigin = max(rcParent.right - rcParent.left - nWidth, 0) / 2
            + rcParent.left - nTitleBits;
    xScreen = GetSystemMetrics(SM_CXSCREEN);
    if  (xOrigin + nWidth > xScreen)
        xOrigin = max (0, xScreen - nWidth);

	yOrigin = max(rcParent.bottom - rcParent.top - nHeight, 0) / 3
            + rcParent.top;
    yScreen = GetSystemMetrics(SM_CYSCREEN);
    if  (yOrigin + nHeight > yScreen)
        yOrigin = max(0 , yScreen - nHeight);

    SetWindowPos(hDlg, NULL, xOrigin, yOrigin, nWidth, nHeight, SWP_NOZORDER);
}

/************************************************************************/
/* Utility function to return which item of a group of radio buttons is */
/* checked.																*/

short GetRadioGroupState (HWND hDlg, short first, short last)
{
	short	item = 0;
	while (first <= last)
	{
		if (IsDlgButtonChecked(hDlg, first))
		{
			item = first;
			first = last;
		}
		first++;
	}
	return item;
}

/**********************************************************/
/* Sets the default item */

void SetDialogDefaultItem(HWND hDlg, short item)
{
	SendDlgItemMessage(hDlg, item, BM_SETSTYLE,
					   (WPARAM)BS_DEFPUSHBUTTON,
					   (LPARAM)TRUE);
	SetFocus(GetDlgItem(hDlg, item));
}

/**********************************************************/
/* Selects a text item */

void SelectTextItem(HWND hDlg, short item)
{
	SendDlgItemMessage(hDlg, item, EM_SETSEL, 0, (LPARAM)-1);
	SetFocus(GetDlgItem(hDlg, item));
}
/**********************************************************/
/* Shows a dialog item */

void ShowDialogItem(HWND hDlg, short item)
{
	ShowWindow(GetDlgItem(hDlg, item),SW_SHOW);
}

/**********************************************************/
/* Hides a dialog item */

void HideDialogItem(HWND hDlg, short item)
{
	ShowWindow(GetDlgItem(hDlg, item),SW_HIDE);
}

/**********************************************************/
/* Hides or shows a dialog item */

void ShowHideItem(HWND hDlg, short item, bool state)
{
	if (state)
		ShowWindow(GetDlgItem(hDlg, item), SW_SHOW);
	else
		ShowWindow(GetDlgItem(hDlg, item), SW_HIDE);
}

/**********************************************************/
/* Shows a dialog item */

void PIEnableControl(HWND hDlg, short item)
{
	EnableWindow(GetDlgItem(hDlg, item),TRUE);
}

/**********************************************************/
/* Hides a dialog item */

void PIDisableControl(HWND hDlg, short item)
{
	EnableWindow(GetDlgItem(hDlg, item),FALSE);
}

/**********************************************************/
/* Hides or shows a dialog item */

void EnableDisableControl(HWND hDlg, short item, bool state)
{
	EnableWindow(GetDlgItem(hDlg, item), state);
}

/**********************************************************/
/* Toggles and returns the value of a dialog item */

bool ToggleCheckBoxState(HWND hDlg, short item)
{
	bool	x;

	x = !GetCheckBoxState(hDlg, item);
	SetCheckBoxState(hDlg, item, x);
	return x;
}

/*****************************************************************************/
/* The following routine retrieves a pascal text string from a text field. */

void FetchText (HWND hDlg, short item, Str255 s)
{
	char c[kStr255InitLen] = "";
	GetDlgItemText(hDlg, item, c, kStr255MaxLen - 1);
	AppendString(s, (const unsigned char*)&c, 0, (short)strlen(c));
}

/*****************************************************************************/
/* The following routine stuffs a text into a text field. */

void StuffText (HWND dp, short item, Str255 s)
{
	if (s[0] >= kStr255MaxLen) s[0]--; // subtract one
	s[ s[0]+1 ] = 0; // null terminate pascal string
	SetDlgItemText(dp, item, (const char *)&s[1]); // stuff string
}

/**********************************************************/
/* Retrieves a number from a dialog item */

short FetchNumber(HWND hDlg, 
				short item, 
				int32 min, 
				int32 max, 
				int32 *value)
{
	Str255		s = "";
	int32		x = 0;
	short		retn = noErr;


	FetchText(hDlg, item, s);
	if (!StringToNumber(s, &x))
	{
		x = 0;
		retn = errNotANumber;
	}
	else if (x < min || x > max) retn = errOutOfRange;

	*value = x; // return something to work with
	return retn;
}

/*****************************************************************************/

/* Display corresponding alert for number */

void AlertNumber(HWND hDlg, 
				short item, 
				int32 min, 
				int32 max, 
				int32 *value,
				short alertID, 
				short /*numberErr*/)
{
	Str255		minText = "";
	Str255		maxText = "";
	int32		x = *value;

	x = ((x < min) ? min : max);
	*value = x;
	StuffNumber(hDlg, item, x);

	_itoa (min, (Ptr)&minText[1], 10);
	minText[0] = (char)strlen((const char *)&minText[1]);

	_itoa (max, (Ptr)&maxText[1], 10);
	maxText[0] = (char)strlen((const char *)&maxText[1]);

	MessageBeep (MB_ICONEXCLAMATION);

	(void) ShowCaution (hDlg,
						alertID,
					  	kBadNumberID,			// could use notANumber
						minText,			   // to display a "Type a number"
						maxText);			   // alert.

	SelectTextItem(hDlg, item);
	SetFocus(GetDlgItem(hDlg, item));
}

/*****************************************************************************/
/* The following routine stuffs a double into a text field. */

void StuffDouble (HWND dp, short item, double value, short precision)
{
	Str255 	s = "";
	DoubleToString(s, value, precision);
	StuffText(dp, item, s);
}

/*****************************************************************************/

/* 
   Here is the corresponding routine to retrieve the floating value from a text
   field.  It will do range checking and validate that it has been
   handed a number.
   
   It returns noErr if it gets a valid value. */
   
short FetchDouble (HWND hDlg,
					short item,
					double min,
					double max,
					double *value)
{
	Str255 s1 = "";
	Str255 s2 = "";
		
	int32 x1 = 0;
	int32 x2 = 0;
	short precision = 0;
	bool notAWholeNumber = false;
	bool notADecimalNumber = false;
	bool notANumber = false;
	double x = 0;
	short retn = noErr;
	
	FetchText(hDlg, item, s1);
	
	DivideAtDecimal(s1, s2);
	
	notAWholeNumber = !StringToNumber (s1, &x1);
	
	notADecimalNumber = !StringToNumber (s2, &x2);
	
	precision = s2[0]; //length
	
	notANumber = (notAWholeNumber && notADecimalNumber);
	
	x = (double)x1 + ((double)x2 / (double)power(10, s2[0]));
	
	if (notANumber)
	{
		x = 0;
		retn = errNotANumber;
	}
	else if (x < min || x > max) retn = errOutOfRange;
	
	*value = x;
	return retn;
}


/*****************************************************************************/
/*
 	If it has not been handed a number, it brings up
	an appropriate error dialog, inserts an appropriately pinned value,
	and selects the item. */
  
void AlertDouble (HWND hDlg,
				 short item,
				 double min,
				 double max,
				 double *value,
				 short alertID,
				 short /*numberErr*/)
{ 
	Str255 minText = "";
	Str255 maxText = "";
	short precision = 0;
	double x = *value;
	
	// Figure out precision
	FetchText(hDlg, item, minText);
	DivideAtDecimal(minText, maxText);
	precision = maxText[0]; // no more than number of digits in decimal
	
	x = (x < min ? min : max);
	*value = x;		
	StuffDouble (hDlg, item, x, precision);


	DoubleToString (minText, min, precision);
	DoubleToString (maxText, max, precision);
	
	MessageBeep (MB_ICONEXCLAMATION);

	(void) ShowCaution (hDlg,
						alertID,
				  	    kBadDoubleID, // could use numberErr==errNotANumber
						minText,	  // to pop a "that's not a number"
						maxText);	  // alert.	

	SelectTextItem (hDlg, item);
	SetFocus(GetDlgItem(hDlg, item));
}


BOOL WINAPI AboutDlgProc(HWND hDlg, UINT wMsg, WPARAM wParam, LPARAM /*lParam*/)
{
	switch  (wMsg) 
	{
		case WM_INITDIALOG:
			{
            CenterDialog(hDlg);

			char message[kStr255InitLen] = "";

			LoadString((HINSTANCE)GetDLLInstance(), AboutID, message, kStr255MaxLen);
			SetDlgItemText(hDlg, MESSAGE, message);
			}
            break;

		case WM_CHAR:
			{
			TCHAR chCharCode = (TCHAR) wParam;
			if (chCharCode == VK_ESCAPE || chCharCode == VK_RETURN)
				EndDialog(hDlg, 0);
			}
			break;
 
		case WM_LBUTTONDOWN:
            EndDialog(hDlg, 0);
            break;

		case WM_COMMAND:
			switch  (COMMANDID(wParam)) 
			{
				case OK:
					EndDialog(hDlg, 0);
                    break;

				case CANCEL:
					EndDialog(hDlg, 0);
					break;

				case ADOBEURL:
				case PARTNERSURL:
				{
					char message[kStr255InitLen] = "http://";
					char url[kStr255InitLen] = "";
					GetDlgItemText(hDlg, COMMANDID(wParam), url, kStr255InitLen - 1);
					(void)PIstrlcat(message, url, kStr255InitLen - 1);
					sPSFileList->BrowseUrl(message);
				}
				break;

				default:
                    return FALSE;
            }
            break;

      default:
		  return  FALSE;
	
	} // switch (wMsg)

    return  TRUE;
}


int LoadLocalString(UINT uID, LPTSTR lpBuffer, int nBufferMax)
{
	int len = 0;
	if (lpBuffer)
	{
		switch (uID) 
		{
			case kBadNumberID:
				strcpy_s(lpBuffer, nBufferMax, "An integer is required between ^1 and ^2.");
				break;
			
			case kBadDoubleID:
				strcpy_s(lpBuffer, nBufferMax, "A decimal number is required between ^1 and ^2.");
				break;

			case kNeedVers:
				strcpy_s(lpBuffer, nBufferMax, "This plug-in requires Adobe Photoshop¨ ^1 or later functionality.");
				break;

			case kWrongHost:
				strcpy_s(lpBuffer, nBufferMax, "This plug-in is incompatible with this version of the host program.");
				break;
			
			case kSuiteMissing:
				strcpy_s(lpBuffer, nBufferMax, "the required suite \"^0\" is unavailable"); /* period is added by host */
				break;

			default:
				break;
		}
		len = (int)strlen(lpBuffer);
	}
	return len;
}

// end DialogUtilitiesWin.cpp