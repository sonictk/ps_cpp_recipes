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
 * \file PIChannelPortOperations.h
 *
 * \brief This file describes operations Photoshop can perform via the Channel Ports Suite
 *
 * \details
 * Copyright 1986-2000 Adobe Systems Incorporated.
 * All Rights Reserved.
 *
 * Distribution:
 *	PUBLIC
 */

#ifndef __PIChannelPortOperations__
#define __PIChannelPortOperations__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"

#ifdef __cplusplus
extern "C" {
#endif

/** 
* @defgroup ChannelPortOperations Channel Port Operations
* @{
*/

/******************************************************************************/
/// Gaussian blur from the source to the destination.
/// Parameters for the operation are provided by \c PSGaussianBlurParameters.
#define PSChannelPortGaussianBlurFilter "Photoshop Gaussian Blur Filter"

/** Parameters for the Gaussian blur operation. */
struct PSGaussianBlurParameters
	{
	Fixed radius;	/**< Radius in pixels using 16.16 fixed point values. 0 to 250 supported. */
	int32 padding;	/**< Padding, 0-255 for constant padding. -1 for edge replication. */
	};

/******************************************************************************/

/// Minimum filter operation. 
/// Parameters for the operation are provided by \c PSMinMaxMedianParameters.
#define PSChannelPortMinimumFilter "Photoshop Minimum Filter"
/// Maximum filter operation. 
/// Parameters for the operation are provided by \c PSMinMaxMedianParameters.
#define PSChannelPortMaximumFilter "Photoshop Maximum Filter"
/// Median filter operation. 
/// Parameters for the operation are provided by \c PSMinMaxMedianParameters.
#define PSChannelPortMedianFilter  "Photoshop Median Filter"

/** Parameters for min, max, and median filters. */
struct PSMinMaxMedianParameters
	{
	int32 radius;	/**< Radius in pixels. 1-16 supported for median. 1-10 for min and max. */
	int32 padding;	/**< Padding, 0-255 for constant padding. -1 for edge replication. */
	};

/******************************************************************************/

/**
* Copy operation. Copies source to destination. If the \c rect parameter is specified
* for \c PSChannelPortsSuite1::ApplyOperation(), it defines the bounds
* to process. It is restricted to the actual writable bounds. This operation ignores
* the \c maskPort parameter.
*/
#define PSChannelPortCopyPixels "Photoshop Copy Pixels"

/******************************************************************************/

/// Set pixel operation. Sets  pixels to a given value. Only implemented for depth 8.
/// Parameters for the operation are provided by \c PSChannelPortSetPixelsParameters. 
#define PSChannelPortSetPixels "Photoshop Set Pixels"

/** Parameters for the Set Pixel operation. */ 
struct PSChannelPortSetPixelsParameters
	{
	int32 value;	/**< The value to set pixels to, valid range: 0-255 */
	};

/******************************************************************************/


#ifdef __cplusplus
}
#endif
/** @} */

#endif	// PIChannelPortOperations
