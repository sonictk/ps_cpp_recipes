// ADOBE SYSTEMS INCORPORATED
// Copyright  2016 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 *	\file PSPlatform.h
 *
 *	\brief Figure out what tool chain is building.
 *
 *	Distribution:
 *		PUBLIC
 *
 */		


#ifndef PSPlatform_h
#define PSPlatform_h

#ifndef qPSIsWin
#if defined(_WIN32) || defined(__INTEL__)
#define qPSIsWin 1
#else
#define qPSIsWin 0
#endif // #if defined(_WIN32) || defined(__INTEL__)
#endif

#if (qPSIsWin) != 0 && (qPSIsWin) != 1
#error qPSIsWin must be 0 or 1.
#endif

#ifndef qPSIsMac
#if qPSIsWin
#define qPSIsMac 0
#else
#define qPSIsMac 1
#endif // #if qPSIsWin
#endif

#if (qPSIsMac) != 0 && (qPSIsMac) != 1
#error qPSIsMac must be 0 or 1.
#endif

#if qPSIsWin == qPSIsMac
#error Must have either qPSIsWin or qPSIsMac, but not both.
#endif

#ifndef MSWindows // Deprecated
#define MSWindows qPSIsWin // Deprecated
#endif

#ifndef Macintosh // Deprecated
#if !MSWindows
#define Macintosh 1 // Deprecated
#endif
#endif  // #ifndef Macintosh

#if qPSIsWin && defined(Macintosh)
#error Macintosh must not be defined for Windows builds because boost uses #ifdef Macintosh
#endif

#endif // #ifndef PSPlatform_h
