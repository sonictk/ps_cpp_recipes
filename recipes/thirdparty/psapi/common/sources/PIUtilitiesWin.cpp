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
//		PIUtilitiesWin.h
//	Description:
//		Utility routines for Windows SDK plug-ins.
//
//-------------------------------------------------------------------------------

#include "PIUtilities.h"

void NumToString (const int32 x, Str255 s)
{
	char c[33] = "";

	s [ (s[0]=0)+1 ] = 0;
	_ltoa(x, c, 10);
	AppendString(s, (const unsigned char*)&c, 0, (short)strlen(c));
}

Fixed FixRatio(short numer, short denom)
{
	if (denom == 0)
	{
		if (numer >=0)
			return   LONG_MAX;

		else
			return -(LONG_MAX);
	}
	else
			return ((long)numer << 16) / denom;
}

/******************************************************************/
