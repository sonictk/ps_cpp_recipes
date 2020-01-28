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
//		PSConstantArray.h
//
//-------------------------------------------------------------------------------

#ifndef __PSConstantArray_H__		// Has this not been defined yet?
#define __PSConstantArray_H__		// Only include this once by predefining it

#include "PITypes.h"

struct PSConstantArray {
	int32	longVal;
	const char*	strStr;//[HashStrMaxLen];
};

#endif // __PSConstantArray_H__
// end PSConstantArray.h
