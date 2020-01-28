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
//		PIDebugCarbon.h
//
//	Description:
//		This file contains the prototypes and utilities
//		for Carbon plug-in debugging.
//
//	Use:
//		This particular file will define the debug flags to
//		build a Carbon debug version of the plug-in.
//
//-------------------------------------------------------------------------------

#ifndef __PIDebugCarbon_H__	// Has this not been defined yet?
#define __PIDebugCarbon_H__	// Only include this once by predefining it

#ifndef _DEBUG
#define _DEBUG	1
#endif

#ifndef ACCESSOR_CALLS_ARE_FUNCTIONS
#define ACCESSOR_CALLS_ARE_FUNCTIONS 1
#endif

#ifndef OPAQUE_TOOLBOX_STRUCTS
#define OPAQUE_TOOLBOX_STRUCTS 1
#endif

#ifndef TARGET_API_MAC_CARBON
#define TARGET_API_MAC_CARBON 1
#endif

#ifndef TARGET_CARBON
#define TARGET_CARBON 1
#endif

#endif // __PIDebugCarbon_H__
// end PIDebugCarbon.h
