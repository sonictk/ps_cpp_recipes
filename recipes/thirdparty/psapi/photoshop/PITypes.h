// ADOBE SYSTEMS INCORPORATED
// (c) Copyright  1993 - 2005, 2009 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
*
*	\file PITypes.h
*
*	\brief
*      	This file describes the type definitions used in Photoshop's interface files.
*
*      Distribution:
*      	PUBLIC
*
*/

#ifndef __PITypes__
#define __PITypes__

#pragma once

#include "PSPlatform.h" // For Macintosh, MSWindows, etc
#include "SPTypes.h"

/******************************************************************************/

/* Set up the preprocessor flags to indicate the target platform.	*/

#if MSWindows
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x601 // minimal deployment is Windows 7
#endif
#include <sdkddkver.h> // for WINVER
#endif

#if !MSWindows

#if defined(__APPLE_CC__)
#define Macintosh 1
#endif

#ifndef Macintosh
#if (defined(macintosh) || defined(__MC68K__) || defined(__MACH__) || defined (__POWERPC__) || defined(THINK_C)) && !MSWindows
#define Macintosh 1
#else
#define Macintosh 0
#endif
#endif /* #ifndef Macintosh */

#ifndef MacintoshOS
#define	MacintoshOS	(Macintosh)
#endif

#ifndef Macintosh68K
#define	Macintosh68K	(MacintoshOS && m68k)
#endif

#ifndef MacintoshPPC
#define	MacintoshPPC	(MacintoshOS && defined(__POWERPC__)) // DRSWAT
#endif

#endif // #if !MSWindows

/******************************************************************************/

/* Set up the flags for the Adobe Graphics Manager.	*/

#ifdef MAC_ENV
#undef MAC_ENV
#endif

#ifdef WIN_ENV
#undef WIN_ENV
#endif

#if Macintosh
#define MAC_ENV	1
#endif

#if MSWindows
#define WIN_ENV	1
#if WIN32
#define WINNT_ENV   1
#endif
#endif

/******************************************************************************/

/* Some utility defines for C/C++ compatiblity. */

#ifndef START_C_INCLUDE
#ifdef __cplusplus
#define START_C_INCLUDE extern "C" {
#define END_C_INCLUDE }
#else
#define START_C_INCLUDE
#define END_C_INCLUDE
#endif
#endif

#ifndef START_C_CODE
#ifdef __cplusplus
#define START_C_CODE extern "C" {
#define END_C_CODE }
#else
#define START_C_CODE
#define END_C_CODE
#endif
#endif

/******************************************************************************/

#if Macintosh

#ifndef __PSWorld__
#include <CoreFoundation/CoreFoundation.h>
#endif

#ifndef TRUE
#define TRUE	true
#endif

#ifndef FALSE
#define FALSE	false
#endif

#ifndef MACPASCAL
#define MACPASCAL pascal
#endif

#ifndef __MWERKS__
#ifndef far
#define far
#endif
#endif

#ifndef huge
#define huge
#endif

#ifndef __PSWorld__

#include "PSIntTypes.h"

#ifndef PSHALFFLOAT
#define PSHALFFLOAT 1
typedef uint16 PSHalfFloat;
#endif

#ifndef	OTHER_AGM_BASIC_H
#define OTHER_AGM_BASIC_H "PITypes.h"
#endif

#endif /* __PSWorld__ */

typedef struct PlatformData {

	int16 dummy;                    /* dummy variable required for some compilers. */

	} PlatformData;

#endif /* Macintosh */

/******************************************************************************/

/* Native floating point type. */

#ifndef nativeFloat		// DRSWAT - get rid of redefined warning in GCC
#define nativeFloat real64
#endif

/******************************************************************************/

#if MSWindows

#define MACPASCAL

#ifndef __PSWorld__
#include <windows.h>

/* Error codes. */
#define noErr 0

#define userCanceledErr (-128)
#define coercedParamErr 2

#define readErr			(-19)
#define writErr			(-20)
#define openErr			(-23)
#define dskFulErr			(-34)
#define ioErr				(-36)
#define eofErr				(-39)		// Also - end of descriptor error.
#define fnfErr				(-43)
#define vLckdErr			(-46)
#define fLckdErr			(-45)
#define paramErr			(-50)
#define memFullErr		(-108)
#define nilHandleErr		(-109)
#define memWZErr			(-111)


#define nil		   NULL

#ifndef TRUE
#define TRUE 1
#endif // TRUE

#ifndef FALSE
#define FALSE 0
#endif // FALSE

#ifndef __cplusplus
	#ifndef true
		#define true	1
	#endif
	#ifndef false
		#define false	0
	#endif
#endif // __cplusplus

#include "PSIntTypes.h"

typedef int32 Fixed;
typedef int32 Fract;
typedef int32 (*ProcPtr)();

#ifndef __TYPES__
#ifndef __GEOMETRY__
typedef struct Point
   {
	  int16 v;
	  int16 h;
   } Point;

typedef struct Rect
   {
	  int16 top;
	  int16 left;
	  int16 bottom;
	  int16 right;
   } Rect;
#endif // __GEOMETRY__
#endif // __TYPES__

#ifndef __QUICKDRAW__
typedef struct
   {
	  WORD red;        /* Magnitude of red   component, 16 bit significant.*/
	  WORD green;      /* Magnitude of green component, 16 bit significant.*/
	  WORD blue;       /* Magnitude of blue  component, 16 bit significant.*/
   } RGBColor;
#endif	// __QUICKDRAW__

#ifndef __OCE__
typedef uint32 DescType;
#endif // __OCE__

typedef LPSTR Ptr;
typedef LPSTR *Handle;
typedef BYTE  Boolean;
typedef uint32 OSType; // Must match FourCharCode from MacTypes.h
typedef int16 OSErr;
typedef uint32 ResType;

typedef unsigned char Str255[256];  /*  first byte length of string. The string is zero terminated. */
typedef const unsigned char *ConstStr255Param;

// NOTE !!! It is VERY IMPORTANT that this structure stay consistent.
// Photoshop on Windows has always had this structure set up so that the
// parID is longword aligned.  Double check that the version that gets picked
// up from Files.h in whatever Universal Headers are being used at the moment
// also agrees.

#ifndef _FSSPEC_
#define _FSSPEC_	1

typedef struct
	{
	int16 unused;	// FSSpecs are dead, but this field is REALLY DEAD
	int16 padding;	// Make the padding explicit.
	int32 parID;
	Str255 name;	/* Pascal String, for Windows files. */
	} FSSpec;

#endif //_FSSPEC_
#endif // __PSWorld__

typedef struct PlatformData {			//64bits - API struct

	intptr_t hwnd;        /* window to own dialogs. */

	} PlatformData;

int16 ShowAlert (int16 stringID); /* Developer implements this  */

#endif    /* Windows */

/******************************************************************************/

// Unicode character type.
typedef uint16 Character;

/******************************************************************************/

// HACK (SRP): The definition of LookUpTable is done this way because PITypes.h
// is included in PSWorld.h prior to LookUpTable being declared.

typedef unsigned8 PILookUpTable [256];

#ifndef __PSWorld__

#ifndef __PSWorldEnums__

/* Common datatypes defined in PSWorld */

typedef PILookUpTable LookUpTable;

typedef unsigned16 LookUpTable8x16 [256];

/** Look up table for RGB. */
typedef struct
	{
	LookUpTable R;
	LookUpTable G;
	LookUpTable B;
	} RGBLookUpTable;

/** Color table information. */
typedef struct
	{
	RGBLookUpTable clut;
	int32 count;
	int32 transparentIndex;
	} ColorTableInfo;

#endif // __PSWorldEnums__

/* Structures to hold colors in various spaces. */

#ifndef __GEOMETRY__

#ifndef USING_MFC

typedef Rect CRect;

#endif

#endif

#ifndef __UGEOMETRY__
/** Rectangle definition defined with integers. */
typedef struct
	{
	int32 top;
	int32 left;
	int32 bottom;
	int32 right;
	} VRect;

/** Point definition defined with integers. */
typedef struct VPoint
	{
	int32 v;
	int32 h;
	} VPoint;

#endif /* __UGEOMETRY__ */

#ifndef __UMath__

/** Floating point Point definition, defined in terms of \c nativeFloat. */
typedef struct FloatPoint
	{
	nativeFloat y, x;
	} FloatPoint;

/** Rectangle definition defined with \c nativeFloat. */
typedef struct FloatRect
	{
	nativeFloat top, left, bottom, right;
	} FloatRect;

#endif /* __UMath__ */

/******************************************************************************/

/*
 * Display Ordering Values.  Passed to certain bottlenecks to tell them what
 * the data looks like, and used (on non-Macs) in the pmReserved field of a
 * pixmap to tag that data.  For compatibility, the values are designed to
 * match up with some Latitude defined values we created for the Unix 3.0.
 */

enum DisplayByteOrder {			/* Data is... */
	displayOrderIndexed = 0,	/* 8-bit, or otherwise unspecified. */
	displayOrderURGB = 1,		/* 32-bit, high 8 unused, Mac uses this. */
	displayOrderUBGR = 2,		/* 32-bit, high 8 unused, Sun, SGI like this. */
	displayOrderRGBU = 3,		/* 32-bit, low 8 unused, for completeness. */
	displayOrderBGRU = 4,		/* 32-bit, good for little-endian (PC). */
	displayOrderRGBPacked = 5,	/* 24-bit, unaligned, currently unsupported!! */
	displayOrderBGRPacked = 6	/* 24-bit, unaligned, currently unsupported!! */
};

#endif	/* __PSWorld__ */

/******************************************************************************/

/** Color defined for CMYK space. */
typedef struct
	{
    unsigned8   c;
    unsigned8   m;
    unsigned8   y;
    unsigned8   k;
	} CMYKtuple;

/** Color defined for RGB space. */
 typedef struct
	{
    unsigned8   alpha;
    unsigned8   r;
    unsigned8   g;
    unsigned8   b;
	} RGBtuple;

/** Color defined for HSL space. */
typedef struct
	{
    unsigned8   alpha;
    unsigned8   h;
    unsigned8   s;
    unsigned8   l;
	} HSLtuple;

/** Color defined for HSB space. */
typedef struct
	{
    unsigned8   alpha;
    unsigned8   h;
    unsigned8   s;
    unsigned8   b;
	} HSBtuple;

/** Color defined for LAB space. */
typedef struct
	{
    unsigned8   alpha;
    unsigned8   L;
    unsigned8   a;
    unsigned8   b;
	} LABtuple;

/** Color defined for RGB 16 bit space. */
typedef struct
	{
    unsigned16   alpha;
    unsigned16   r;
    unsigned16   g;
    unsigned16   b;
	} RGB16tuple;

/** Color defined for CMYK 16 bit space. */
typedef struct
	{
    unsigned16   c;
    unsigned16   m;
    unsigned16   y;
    unsigned16   k;
	} CMYK16tuple;

/** Color defined for LAB 16 bit space. */
typedef struct
	{
    unsigned16   alpha;
    unsigned16   L;
    unsigned16   a;
    unsigned16   b;
	} LAB16tuple;

/** Color defined for XYZ 16 bit space. */
typedef struct
	{
	unsigned8	alpha;
	unsigned8	padding;
	unsigned16	X;
	unsigned16	Y;
	unsigned16	Z;
	} XYZ16tuple;

typedef unsigned8   inverseCLUT [32][32][32];
typedef unsigned32  histogram3 [][32][32];

typedef int16            HueSatTable [1536];
typedef PILookUpTable    HueSatMaps[4];     /* general form of RGBLookUpTable */

/* hack for BNTLocal.c et al */
#ifndef __UMonitor__
typedef int16 Short3by3 [3] [3];
#endif /* __UMonitor__ */

/** Point x,y defined with \c real64 */
typedef struct PIFloatPoint
	{
	real64		y;
	real64		x;
	} PIFloatPoint;

/** Rectangle defined with \c real64. */
typedef struct PIFloatRect
	{
	real64		top;
	real64		left;
	real64		bottom;
	real64		right;
	} PIFloatRect;


/*
PIAffineMatrix represents 3x3 matrix that has the following structure:

|	xx		xy		0	|
|	yx		yy		0	|
|	tx		ty		1	|

*/

/**
* Affine matrix defined with \c real64. This is a 3x3 matrix with the following
* structure:
@verbatim
|	xx		xy		0	|
|	yx		yy		0	|
|	tx		ty		1	|
@endverbatim
*/
typedef struct PIAffineMatrix
	{
	real64 xx, xy, yx, yy, tx, ty;
	} PIAffineMatrix;

#endif /* __PITypes_h__ */
