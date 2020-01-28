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
*	\file PSGraphicTypes.h
*
*	\brief 
*      	This file describes the type definitions used in Photoshop's interface files.
*
*      Distribution:
*      	PUBLIC
*      
*/     	

#ifndef __PSGraphicTypes__
#define __PSGraphicTypes__

#pragma once

#include "PSIntTypes.h"

/******************************************************************************/
//Platform neutral types to replace Quickdraw types

typedef struct PSRGBColor
{
	uint16 red;
	uint16 green;
	uint16 blue;
} PSRGBColor;

typedef struct PSPoint
{
	int16               v;
	int16               h;
} PSPoint;

typedef struct PSRect
{
	int16               top;
	int16               left;
	int16               bottom;
	int16               right;
} PSRect;

typedef struct PSPattern
{
	uint8               pat[8];
} PSPattern;


#endif /* __PITypes_h__ */
