// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
/**
* \file PSErrorDefines.h
*
* \brief  Error definitions
*
* Distribution:
*	PUBLIC
*
*/


#ifndef __PS_ERROR_DEFINES_H__
#define __PS_ERROR_DEFINES_H__

#if PRAGMA_ONCE
#pragma once
#endif

/* This file exists so that these values can shared with the Rez compiles */

#define errBadTIFFDefine			-25380
#define errNotTIFFDefine			-25390
#define errCompressedTIFFDefine		-25400
#define errBadTIFFDepthDefine		-25410
#define errBadTIFFSpaceDefine		-25420
#define errBadTIFFCCITTT4Define		-25423	
#define errBadTIFFCCITTT6Define		-25427

/* Actions */

#define errEventNotAvailableDefine	-25920
#define errBatchedActionBusyDefine	-25921
#define errReferenceNotFoundDefine	-25922
#define errEventInvalidParametersDefine	-25923
#define errPlayActionBusyDefine		-25930
#define errActionNotFoundDefine		-25940
#define errDeleteActionBusyDefine	-25950


#define errQuadTooBigDefine			-25960
#define errQuadDegenerateDefine		-25970

#endif  /* #ifndef __PS_ERROR_DEFINES_H__ */
