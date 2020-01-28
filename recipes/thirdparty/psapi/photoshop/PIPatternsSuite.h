// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2007 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 * \file PIPatternsSuite.h
 *
 * \brief This file describes Photoshop's Patterns Suite for plug-ins
 *
 * \details
 * Copyright 1993-2007 Adobe Systems Incorporated.
 * All Rights Reserved.
 *
 * Distribution:
 *	PUBLIC
 *
 */

#ifndef __PIPatternsSuite__
#define __PIPatternsSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"
#include "PIActions.h"
#include "PIChannelPortsSuite.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Pattern Suite.
#define kPSPatternsSuite 			"Photoshop Patterns Suite for Plug-ins"

/******************************************************************************/

#define kPSPatternsSuiteVersion1			1

/******************************************************************************/

typedef struct PatternSpec
{
	PIChannelPort colorData[ 4 ];	/**< color data */
	
	PIChannelPort transparency;		/**< transparency data */
	
	int32 imageMode;				/**< Color mode for the pattern preset */
	
	VRect bounds;					/**< bounds for the pattern preset */
	
	int32 depth;					/**< only 8 bit patterns are currently supported */
	
	const char *name;				/**< name of the pattern preset */

} PatternSpec;

/******************************************************************************/

typedef struct PSPatternsSuite1
	{
	
	/// create a new pattern preset from channel ports
	SPAPI SPErr (*CreateNewPatternPreset) ( const PatternSpec *newPatternSpec );
	
	/// returns pattern preset count, valid indices are zero to count-1
	SPAPI SPErr (*GetPatternCount) ( int32 *count );
	
	/// return name from index
	SPAPI SPErr (*GetPatternName) ( int32 index, ASZString *patternName );
	
	/// return ZUID string (for actions), from index maxStringLength must be at least 37
	SPAPI SPErr (*GetPatternID) ( int32 index, char *patUIDstr, int32 maxStringLength );
	
	} PSPatternsSuite1;


#ifdef __cplusplus
}
#endif


#endif	// __PIPatternsSuite__
