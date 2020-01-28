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
//		PIDefines.h
//
//	Description:
//		This file contains the prototypes and definitions
//		generic for plug-ins.
//
//	Use:
//		This particular file will define the flags for
//		generic values needed by every plug-in.
//
//-------------------------------------------------------------------------------

#ifndef __PIDefines_H__	// Has this not been defined yet?
#define __PIDefines_H__	// Only include this once by predefining it

/// Create a definition if we're on a Windows machine
#ifndef __PIWin__
	#if MSWindows
		#define __PIWin__			1
	#elif (defined(MSDOS) || defined(WIN32) || defined(_WIN32) || (defined(__INTEL__) && !defined(__MACH__)) || defined(_MSC_VER))
		#define __PIWin__			1
	#endif
#endif

/// Create a definition if we're on a Macintosh
#ifndef __PIMac__
	#if (defined(macintosh) || defined(__POWERPC__) || defined(__powerc)) || defined(__APPLE_CC__)
		#define __PIMac__			1
	#endif
#endif

/// Create a definition for exported functions
#ifdef __APPLE_CC__
	#if __APPLE_CC__
		#define DLLExport extern "C"
	#endif
#endif
#ifndef DLLExport
	#define DLLExport extern "C" __declspec(dllexport)
#endif


// make sure things look good
#if !defined(__PIWin__) && !defined(__PIMac__)
#error "Need one of these defined!"
#endif

#if defined(__PIWin__) && defined(__PIMac__)
#error "Need only one defined!"
#endif

//-------------------------------------------------------------------------------

#endif // __PIDefines_H__
// end PIDefines.h
