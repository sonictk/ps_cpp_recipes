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
//		PICA2PSErrorMap.h
//
//
//	Distribution:
//		PUBLIC
//
//	Description:
//		This file contains all the API error codes for Photoshop and
//		PICA (Sweet Pea).  It maps all the PICA error codes to their
//		Photoshop equivalents.
//
//-------------------------------------------------------------------------------

#ifndef __PICA2PSErrorMap_h__ // Already defined?
#define __PICA2PSErrorMap_h__

//-------------------------------------------------------------------------------
//	PICA headers.
//-------------------------------------------------------------------------------
#include "SPAccess.h"
#include "SPAdapts.h"
#include "SPBckDbg.h"
#include "SPBlocks.h"
#include "SPFiles.h"
#include "SPHost.h"
#include "SPInterf.h"
#include "SPPlugs.h"
#include "SPProps.h"
#include "SPSuites.h"
#include "ASTypes.h"

//-------------------------------------------------------------------------------
//	Photoshop headers.
//-------------------------------------------------------------------------------
#include "PISelection.h"
#include "PIPicker.h"
#include "PIGeneral.h"
#include "PIExport.h"
#include "PIActions.h"

#define noMap -1

typedef struct 
	{
	
	OSType	suitePeaErrorCode;
	OSErr	photoshopErrorCode;
	
	}SPErrorMapEntry;
	
static SPErrorMapEntry spErrorMap [] =
	{
		kSPCantAcquirePluginError	/* SPAccess.h: '!Acq' */,
			noMap	/* -12345 */,
		kSPCantReleasePluginError	/* SPAccess.h: '!Rel' */,
			noMap	/* -12345 */,
		kSPPluginAlreadyReleasedError	/* SPAccess.h: 'AlRl' */,
			noMap	/* -12345 */,
		kSPAdapterAlreadyExistsError	/* SPAdapts.h: 'AdEx' */,
			noMap	/* -12345 */,
		kSPBadAdapterListIteratorError	/* SPAdapts.h: 'BdAL' */,
			noMap	/* -12345 */,
		kSPCantChangeBlockDebugNowError	/* SPBlckDbg.h: '!Now' */,
			noMap	/* -12345 */,		
		kSPBlockDebugNotEnabledError	/* SPBlckDbg.h: '!Nbl' */,
			noMap	/* -12345 */,
		kSPOutOfMemoryError	/* SPBlocks.h: 0xFFFFFF6cL (-108) */,
			noMap	/* -12345 */,
		kSPBlockSizeOutOfRangeError	/* SPBlocks.h: 'BkRg' */,
			noMap	/* -12345 */,
		kSPTroubleAddingFilesError	/* SPFiles.h: 'TAdd' */,
			noMap	/* -12345 */,
		kSPBadFileListIteratorError	/* SPFiles.h: 'BFIt' */,
			noMap	/* -12345 */,
		kSPTroubleInitializingError	/* SPHost.h: 'TIni' */,
			noMap	/* -12345 */,
		kHostCanceledStartupPluginsError	/* SPHost.h: 'H!St' */,
			noMap	/* -12345 */,
		kSPNotASweetPeaPluginError	/* SPInterf.h: 'NSPP' */,
			noMap	/* -12345 */,
		kSPAlreadyInSPCallerError	/* SPInterf.h: 'AISC' */,
			noMap	/* -12345 */,
		kSPUnknownAdapterError	/* SPPlugs.h: '?Adp' */,
			noMap	/* -12345 */,
		kSPBadPluginListIteratorError	/* SPPlugs.h: 'PiLI' */,
			noMap	/* -12345 */,
		kSPBadPluginHost	/* SPPlugs.h: 'PiH0' */,
			errPlugInHostInsufficient	/* PIGeneral.h: -30900 */,
		kSPCantAddHostPluginError	/* SPPlugs.h: 'AdHo' */,
			noMap	/* -12345 */,
		kSPPluginNotFound	/* SPPlugs.h: 'P!Fd' */,
			errPlugInHostInsufficient	/* PIGeneral.h: -30900 */,
		kSPCorruptPiPLError	/* SPPlugs.h: 'CPPL' */,
			noMap	/* -12345 */,
		kSPBadPropertyListIteratorError	/* SPPlugs.h: 'BPrI' */,
			noMap	/* -12345 */,
		kSPSuiteNotFoundError	/* SPSuites.h: 'S!Fd' */,
			errPlugInHostInsufficient	/* PIGeneral.h: -30900 */,
		kSPSuiteAlreadyExistsError	/* SPSuites.h: 'SExi' */,
			noMap	/* -12345 */,
		kSPSuiteAlreadyReleasedError	/* SPSuites.h: 'SRel' */,
			noMap	/* -12345 */,
		kSPBadSuiteListIteratorError	/* SPSuites.h: 'SLIt' */,
			noMap	/* -12345 */,
		kSPBadSuiteInternalVersionError	/* SPSuites.h: 'SIVs' */,
			noMap	/* -12345 */,
		'!Hlp' /* ASHelp.h: kHelpError '!Hlp' */,
			noMap	/* -12345 */,
		kOutOfMemoryErr	/* ASTypes.h: '!MEM' */,
			memFullErr	/* PITypes.h: -108 */,
		kBadParameterErr	/* ASTypes.h: 'PARM' */,
			paramErr	/* PITypes.h: -50 */,
		kNotImplementedErr	/* ASTypes.h: '!IMP' */,
			errPlugInHostInsufficient	/* PIGeneral.h: -30900 */,
		kCantHappenErr	/* ASTypes.h: 'CANT' */,
			errPlugInPropertyUndefined	/* PIGeneral.h: -30901 */,
		'STOP',
			userCanceledErr,

		// this must be last
		kSPNoError,
			noErr

	};
	
#undef noMap

//-------------------------------------------------------------------------------

#endif // __PICA2PSErrorMap.h__
