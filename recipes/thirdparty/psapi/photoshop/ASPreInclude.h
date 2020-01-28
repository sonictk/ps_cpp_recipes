/***********************************************************************/
/*                                                                     */
/* ASPreInclude.h                                                          */
/* Makes #defines for #pragmas to eliminate compiler dependencies      */
/*                                                                     */
/* Copyright 1996-1999 Adobe Systems Incorporated.                     */
/* All Rights Reserved.                                                */
/*                                                                     */
/* Patents Pending                                                     */
/*                                                                     */
/* NOTICE: All information contained herein is the property of Adobe   */
/* Systems Incorporated. Many of the intellectual and technical        */
/* concepts contained herein are proprietary to Adobe, are protected   */
/* as trade secrets, and are made available only to Adobe licensees    */
/* for their internal use. Any reproduction or dissemination of this   */
/* software is strictly forbidden unless prior written permission is   */
/* obtained from Adobe.                                                */
/*                                                                     */
/* Started by Dave Lazarony, 01/26/1996                                */
/*                                                                     */
/***********************************************************************/

#ifndef __ASPREINCLUDE__
#define __ASPREINCLUDE__

#if PRAGMA_ONCE
#pragma once
#endif

/******************************************************************************/

#if (!defined(AS_OS) || !defined(AS_ISP))

// Patch for the lame Proximity spelling/hyphenation headers.
#if !defined (EXPORT)
#define EXPORT 2
#endif

#if !defined(USE_STDARG)
#define USE_STDARG	1
#endif

#define PROTOTYPES	1

#if !defined(ENABLE_ZIP)
#define ENABLE_ZIP	1
#endif

#if MacintoshOS

#if defined(__GNUC__)

	#define AS_OS		asos_macgcc
	#if __POWERPC__
		#define AS_ISP		asisp_ppc603
	#elif __i386__
		#define AS_ISP		asisp_pentium
	#elif __LP64__
		#define AS_ISP		asisp_pentium
	#elif defined(__arm__)
		#define AS_ISP		asisp_arm
	#else
		#error "Unknown processor"
	#endif

#else

	#error "Unknown compiler"

#endif

#define MAC_PLATFORM 1

#endif	// MacintoshOS

#if PS_OS_ANDROID
    #if defined(__GNUC__)
        #define AS_OS		asos_macgcc
        #if __POWERPC__
            #define AS_ISP		asisp_ppc603
        #elif __i386__
            #define AS_ISP		asisp_pentium
        #elif __LP64__
            #define AS_ISP		asisp_pentium
        #elif defined(__arm__)
            #define AS_ISP		asisp_arm
        #else
            #error "Unknown processor"
        #endif
    #else
        #error "Unknown compiler"
    #endif
#endif
// end REVISIT

#if	MSWindows || defined(__INTEL__) || defined (WIN32)
#define AS_OS		asos_windowsNT
#define AS_ISP		asisp_pentium
#define WIN_PLATFORM 1
#endif

#define WITHIN_PS		0
#define NOT_USE_NATIVE_UTIL_LIBS	0

#if !defined(WITHIN_STM)
#define WITHIN_STM		1
#endif

#endif // (!defined(AS_OS) || !defined(AS_ISP))

/******************************************************************************/

// Patch around an old ZStrings suite header for the transition to ADM3.
// SLB 3/26/04
#ifndef kNoErr
#define kNoErr					0
#define kOutOfMemoryErr			'!MEM'
#define kBadParameterErr		'PARM'
#define kNotImplementedErr		'!IMP'
#define kCantHappenErr			'CANT'
#endif

/******************************************************************************/

#endif  /* __ASPREINLUDE__ */
