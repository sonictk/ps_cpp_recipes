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
//		FileUtilities.cpp
//
//	Description:
//		This library contains sources and functions
//		to simplify the use of extremely common file
//		functions for plug-ins. 
//
//	Use:
//		FileUtilities is intended to group common functions
//		into higher-level macros and routines to simplify
//		plug-in programming.
//
//-------------------------------------------------------------------------------

#include "FileUtilities.h"


/*****************************************************************************/

Boolean TestAndStoreResult (short *res, OSErr result)
{
	if (result != noErr)
		{
		if (*res == noErr)
			*res = result;
		return FALSE;
		}
	else
		return TRUE;	
}
	
/*****************************************************************************/

Boolean TestAndStoreCancel (short *res, Boolean tocancel)
{	
	if (tocancel)
		{
		if (*res == noErr)
			*res = userCanceledErr;
		return FALSE;
		}
	else
		return TRUE;	
}


// end FileUtilities.cpp
