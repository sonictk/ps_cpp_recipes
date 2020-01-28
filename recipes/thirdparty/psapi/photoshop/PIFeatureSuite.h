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
 * \file PIFeatureSuite.h
 *
 * \brief This file describes Photoshop's Feature Suite for plug-ins
 *
 * \details
 * Copyright 1993-2007 Adobe Systems Incorporated.
 * All Rights Reserved.
 *
 * Distribution:
 *	PUBLIC
 *
 */

#ifndef __PIFeatureSuite__
#define __PIFeatureSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"
#include "PIActions.h"
#include "SPFiles.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Feature Suite.
#define kPSFeatureSuite 			"Photoshop Feature Suite for Plug-ins"

//-------------------------------------------------------------------------
//	Useful feature query strings
//-------------------------------------------------------------------------

#define kPSExtendedEdition			"photoshop/extended"
#define kPSStandardEdition			"photoshop/standard"
#define kPSTrialEdition				"photoshop/trial"

//-------------------------------------------------------------------------
//	Feature suite typedefs 
//-------------------------------------------------------------------------

/** Determines if the feature is enabled given the string
* @param id string to use for feature check
* @returns true if the feature is enabled
*/
typedef SPAPI SPBoolean  (*Feature_IsActive) (const char *id);

//-------------------------------------------------------------------------
//	Feature suite version 1
//-------------------------------------------------------------------------

#define kPSFeatureSuiteVersion1		1

typedef struct
{
	Feature_IsActive					IsFeatureActive;		/**< Function pointer to check if a feature is enabled. */
} PSFeatureSuite1;


/******************************************************************************/

#ifdef __cplusplus
}
#endif


#endif	// __PIFeatureSuite__
