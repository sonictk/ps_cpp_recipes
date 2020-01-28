// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 *	\file PIResDefines.h
 *
 *	\brief This file contains the public definitions
 *		used to create PiPL resources with the
 *		PiPL master template, PIGeneral.r and PIGeneral.h.
 *
 *  \details
 *		NOTE:  Because this is included in both a header
 *		and a resource template, there are strict rules
 *		as to how elements can be defined.\n\n
 *	Use:
 *		This file must be included to correctly compile any
 *		resource (.r) files using the specific flags contained
 *		here.  It is automatically included in PIGeneral.r and
 *		PIGeneral.h.
 *
 */

#ifndef __PIResDefines_h__		// Only include this once.
#define __PIResDefines_h__	

#if PRAGMA_ONCE
#pragma once
#endif


//-------------------------------------------------------------------------------
//	Definitions -- Latest versions of Photoshop plug-in types
//-------------------------------------------------------------------------------

#define latestAcquireVersion			4
#define latestAcquireSubVersion			0
#define latestExportVersion				4
#define latestExportSubVersion			0
#define latestExtensionVersion			2
#define latestExtensionSubVersion		0
#define latestFilterVersion				4
#define latestFilterSubVersion			0
#define latestFormatVersion				1
#define latestFormatSubVersion			0
#define latestParserVersion				2
#define latestParserSubVersion			0
#define latestSelectionVersion			1
#define latestSelectionSubVersion		0
#define latestPickerVersion				1
#define latestPickerSubVersion			0
#define latestActionsPlugInVersion		1
#define latestActionsPlugInSubVersion	0

//-------------------------------------------------------------------------------
//	Definitions -- PIMI property
//-------------------------------------------------------------------------------

#define supportsBitmap 			1
#define supportsGrayScale		2
#define supportsIndexedColor	4
#define supportsRGBColor		8
#define supportsCMYKColor	   16
#define supportsHSLColor	   32
#define supportsHSBColor	   64
#define supportsMultichannel  128
#define supportsDuotone		  256
#define supportsLABColor	  512

#define flagSupportsBitmap	 	 128
#define flagSupportsGrayScale	  64
#define flagSupportsIndexedColor  32
#define flagSupportsRGBColor	  16
#define flagSupportsCMYKColor	   8
#define flagSupportsHSLColor	   4
#define flagSupportsHSBColor	   2
#define flagSupportsMultichannel   1
#define flagSupportsDuotone		 128
#define flagSupportsLABColor	  64

//-------------------------------------------------------------------------------
//	Definitions -- Premiere corner bits
//-------------------------------------------------------------------------------

#define bitNone					(0)
#define bitTop					(1<<0)
#define bitRight				(1<<1)
#define bitBottom				(1<<2)
#define bitLeft					(1<<3)
#define bitUpperRight			(1<<4)
#define bitLowerRight			(1<<5)
#define bitLowerLeft			(1<<6)
#define bitUpperLeft			(1<<7)

//-------------------------------------------------------------------------------

#endif // __PIResDefines_h__
