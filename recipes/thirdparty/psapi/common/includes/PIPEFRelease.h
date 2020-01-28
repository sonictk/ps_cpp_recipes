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
//		PICarbon.h
//
//	Description:
//		This file contains the prototypes and utilities
//		for Carbon plug-in.
//
//	Use:
//		This particular file will define the flags to
//		build a Carbon version of the plug-in.
//
//-------------------------------------------------------------------------------

#ifndef __PICarbon_H__	// Has this not been defined yet?
#define __PICarbon_H__	// Only include this once by predefining it

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

#endif // __PICarbon_H__
// end PICarbon.h
