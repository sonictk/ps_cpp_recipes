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
//		This library contains the sources and routines
//		related to Macintosh dialog manipulation. 
//
//	Use:
//		DialogUtilities is intended to make Macintosh dialog
//		manipulation a little simpler by providing a standard
//		suite of functions.  Use these routines for whatever you
//		need, and feel free to tweak them for your own work.  They
//		expect A4-globals to be set-up already, and for gStuff to
//		be a valid pointer to your global structure's parameter
//		block.
//
//-------------------------------------------------------------------------------

#include "DialogUtilities.h"


//-------------------------------------------------------------------------------

short ShowVersionAlert (void* dp,
						const short alertID, 
						const short stringID,
						unsigned char* versText1,
						unsigned char* versText2)
{
	return 0;
}

void ShowAbout (short dialogID)
{
}

// end DialogUtilitiesMac.cpp

