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
 * \file PIColorSpaceSuite.h
 *
 * \brief This file describes Photoshop's ColorSpace Suite for plug-ins
 *
 * Distribution:
 *	PUBLIC
 *
 */

/**
* @defgroup PicaColorSpaceSuite Color Space Suite 
* The Color Space suite provides callbacks related to color space management.
* <b> Accessing the Suite </b> \n\n
* The Color Space suite is referred to as:
* @code
  #define kPSColorSpaceSuite 	"Photoshop ColorSpace Suite for Plug-ins"
@endcode
* The current version of the Color Space suite:
* @code
  #define kPSColorSpaceSuiteVersion1		1
@endcode
* The suite is acquired as follows:
* @code
  PSColorSpaceSuite1 *sPSColorSpace;
  error = sSPBasic->AcquireSuite(kPSColorSpaceSuite,
  								 kPSColorSpaceSuiteVersion1, 	  
  								 &sPSColorSpace);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/



#ifndef __PIColorSpaceSuite__
#define __PIColorSpaceSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"
#include "PIActions.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Color Space Suite.
#define kPSColorSpaceSuite 			"Photoshop ColorSpace Suite for Plug-ins"

//-------------------------------------------------------------------------
//	ColorSpace suite typedefs 
//-------------------------------------------------------------------------

// These are defined in PIGeneral.h
/*
	Constants for colorSpace fields
	
#define plugIncolorServicesRGBSpace		0
#define plugIncolorServicesHSBSpace		1
#define plugIncolorServicesCMYKSpace	2
#define plugIncolorServicesLabSpace		3
#define plugIncolorServicesGraySpace	4
#define plugIncolorServicesHSLSpace		5
#define plugIncolorServicesXYZSpace		6
*/

typedef struct Color_T *ColorID; /**< Identifier for the Color Space. */

// formatted as 0RGB, CMYK, 0LAB, 0XYZ, 0HSB, 0HSL, 000Gray
/** Representation of 8-bit color.  For each of the color spaces, the
* values are formatted as follows for the 0,1,2,3 array indices:
* 0RGB, CMYK, 0LAB, 0XYZ, 0HSB, 0HSL, 000Gray.
*/
typedef uint8 	Color8[4];	 

/**< Representation of 16-bit color. For each of the color spaces, the
* values are formatted as follows for the 0,1,2,3 array indices:
* 0RGB, CMYK, 0LAB, 0XYZ, 0HSB, 0HSL, 000Gray.
*/

typedef uint16 	Color16[4];	 
/**< Representation of 32-bit color. For each of the color spaces, the
* values are formatted as follows for the 0,1,2,3 array indices:
* 0RGB, CMYK, 0LAB, 0XYZ, 0HSB, 0HSL, 000Gray.
*/
typedef real32			Color32[4];	 


/** Color values for the XYZ color space. */
typedef struct
{
	uint16 x;	 /**< X value for XYZ color space; range is from -0 to 255. */
	uint16 y;	 /**< Y value for XYZ color space; range is from -0 to 255. */
	uint16 z;	 /**< Z value for XYZ color space; range is from -0 to 255. */
} CS_XYZColor;

/** 
* Makes a new color space.
* @param ColorID ID of the color space.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_Make) (ColorID *id);

/** 
* Deletes a color space.
* @param ColorID ID of the color space to delete.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_Delete) (ColorID *id);

/** 
* Puts four color components into a Color Space given a type of color space.
* @param ColorID ID of the color space to stuff components into.
* @param colorSpace The type of color space used.
* See @ref ColorSpace for values.
* @param component0	The value to stuff for component 0.  The values depend on the type of color space.
* @param component1	The value to stuff for component 1. The values depend on the type of color space.
* @param component2	The value to stuff for component 2. The values depend on the type of color space.
* @param component3 The value to stuff for component 3. The values depend on the type of color space.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_StuffComponents) (ColorID id, int16 colorSpace, 
					uint8 component0, uint8 component1, 
					uint8 component2, uint8 component3);

/** 
* Extracts four color components from a Color Space given a type of color space.
* @param ColorID ID of the color space to extract components from.
* @param colorSpace The type of color space used. See @ref ColorSpace for values.
* @param component0	[OUT] The value extracted for component 0.  The values depend on the type 
* of color space.
* @param component1	[OUT] The value extracted for component 1.  The values depend on the type 
* of color space. 
* @param component2	[OUT] The value extracted for component 2.  The values depend on the type 
* of color space. 
* @param component3	[OUT] The value extracted for component 3.  The values depend on the type 
* of color space. 
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_ExtractComponents) (ColorID id, int16 colorSpace,
					uint8 *component0, uint8 *component1, 
					uint8 *component2, uint8 *component3, Boolean *gamutFlag);
					
/** 
* Puts XYZ color components into a Color Space.
* @param ColorID ID of the color space to stuff color into.
* @param xyz XYZ color to put into the color space.	
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_StuffXYZ) (ColorID id, CS_XYZColor xyz);

/** 
* Extracts XYZ color components from a Color Space.
* @param ColorID ID of the color space to extract color from.
* @param xyz [OUT] XYZ color extracted from the color space.	
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_ExtractXYZ) (ColorID id, CS_XYZColor *xyz);

/** 
* Gets the native type of color space from a Color Space.
* @param ColorID ID of the color space check.
* @param colorSpace [OUT] The type of color space, returned. See @ref ColorSpace for values.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_GetNativeSpace) (ColorID id, int16 *colorSpace);

/** 
* Converts between two color spaces, with 8-bit color.
* @param inputCSpace Type of color space to convert from. See @ref ColorSpace for values.
* @param outputCSpace Type of color space to convert into. See @ref ColorSpace for values.
* @param colorArray [IN/OUT] The color array to convert from. Also holds the output of the 
* conversion to the new color space.
* @param count How many items in the colorArray
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_Convert8) (int16 inputCSpace, int16 outputCSpace,
											Color8 *colorArray, int16 count);

/** 
* Converts between two color spaces, with 16-bit color.
* @param inputCSpace Type of color space to convert from. See @ref ColorSpace for values.
* @param outputCSpace Type of color space to convert into. See @ref ColorSpace for values.
* @param colorArray [IN/OUT] The color array to convert from. Also holds the output of the 
* conversion to the new color space.
* @param count How many items in the colorArray
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_Convert16) (int16 inputCSpace, int16 outputCSpace,
											Color16 *colorArray, int16 count);

/**
* Determines whether the color space associated with \c ColorID contains a book color.
* @param ColorID ID of the color space to check.
* @param isBookColor [OUT] Indicates whether the color space contains a book color, TRUE if so.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_IsBookColor) (ColorID id, Boolean *isBookColor);

/**
* Extracts the name of the color in a color space.
* @param ColorID ID of the color space.
* @param colorName [OUT] Name of the color in the color space.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_ExtractColorName) (ColorID id, ASZString *colorName);

/**
* Picks a color using the Color Picker.
* @param ColorID [OUT] ID of the color space with the color returned in it.
* @param promptString String used in the prompt for the color picker.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_PickColor) (ColorID *id, ASZString promptString);


// these use the Photoshop internal 16 bit range of [0..32768]
// data can be single or multiple channels, as long as the count includes all of it

/** 
* Converts 8- to 16-bit color.
* Uses the Photoshop internal 16 bit range of [0..32768]
* The data can be single or multiple channels, as long as the count includes all of it.
* @param input_data	Block of data to convert from 8 bit color.
* @param output_data [OUT] Block of data to receive the conversion into 16 bit color.
* @param count How many items to convert
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr	(*ColorSpace_Convert8to16)( uint8 *input_data,
												uint16 *output_data,
												int16 count );

/** 
* Converts 16- to 18-bit color. Uses the Photoshop internal 16 bit range of [0..32768]
* The data can be single or multiple channels, as long as the count includes all of it.
* @param input_data Block of data to convert from 16 bit color.
* @param output_data [OUT] Block of data to receive the conversion into 18 bit color. 
* @param count How many to convert
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr	(*ColorSpace_Convert16to8)( uint16 *input_data,
												uint8 *output_data,
												int16 count );

/** 
* Converts color from \c inputCSpace to main monitor RGB (does not handle multiple displays!)
* The data can be single or multiple channels, as long as the count includes all of it.
* @param inputCSpace The color space to convert from.  See @ref ColorSpace for values.
* @param input_data Block of data to convert from 8 bit color.
* @param output_data [OUT] Block of data to receive the conversion into monitor RGB color.
* @param count How many to convert
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_ConvertToMonitorRGB)(int16 inputCSpace,
											Color8 *input_data,
										  	Color8 *output_data,
										   	int16 count);

/** 
* Converts 32- to 8-bit color.
* The data can be single or multiple channels, as long as the count includes all of it.
* @param input_data Block of data to convert from 32 bit color.
* @param output_data [OUT] Block of data to receive the conversion into 8 bit color. 
* @param count How many items to convert
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr	(*ColorSpace_Convert32to8)( real32 *input_data,
												uint8 *output_data,
												int16 count );

/** 
* Converts color to monitor RGB for a given display area (whichever display covers most of it)
* @param source_data The input data to be converted.
* @param output_data [OUT] Block of data to receive the conversion into 8 bit monitor RGB color.
* @param output_rowBytes rowbytes for output_data.
* @param display_area display rectangle that this data will be displayed in.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_ConvertForDisplay) (PSPixelMap *source_data,
									  Color8 *output_data,
									  int32 output_rowBytes,
									  const VRect *display_area);

/** 
* Get the ICC profile for a given display area (whichever display covers most of it)
* @param display_area display rectangle that this data will be displayed in.
* @param profile_data [OUT] HandleSuite handle with ICC profile in it. Caller is responsible for disposing of data.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*ColorSpace_GetDisplayProfile) (const VRect *display_area, Handle *profile_data);

//-------------------------------------------------------------------------
//	ColorSpace suite version 2
//-------------------------------------------------------------------------

/// Color Space Suite, Version 2.
#define kPSColorSpaceSuiteVersion2		2

/// Latest version
#define kPSColorSpaceSuiteVersion	kPSColorSpaceSuiteVersion2

/** The set of routines available in the Color Space suite. */
typedef struct 
{
	ColorSpace_Make					Make;				 /**< Function pointer to \c ColorSpace_Make. */
	ColorSpace_Delete				Delete;				 /**< Function pointer to \c ColorSpace_Delete. */
	ColorSpace_StuffComponents		StuffComponents;	 /**< Function pointer to \c ColorSpace_StuffComponents. */
	ColorSpace_ExtractComponents	ExtractComponents;	 /**< Function pointer to \c ColorSpace_ExtractComponents. */
	ColorSpace_StuffXYZ				StuffXYZ;			 /**< Function pointer to \c ColorSpace_StuffXYZ. */
	ColorSpace_ExtractXYZ			ExtractXYZ;			 /**< Function pointer to \c ColorSpace_ExtractXYZ. */
	ColorSpace_Convert8 			Convert8;			 /**< Function pointer to \c ColorSpace_Convert8. */
	ColorSpace_Convert16			Convert16;			 /**< Function pointer to \c ColorSpace_Convert16. */
	ColorSpace_GetNativeSpace		GetNativeSpace;		 /**< Function pointer to \c ColorSpace_GetNativeSpace. */
	ColorSpace_IsBookColor			IsBookColor;		 /**< Function pointer to \c ColorSpace_IsBookColor. */
	ColorSpace_ExtractColorName		ExtractColorName;	 /**< Function pointer to \c ColorSpace_ExtractColorName. */
	ColorSpace_PickColor			PickColor;			 /**< Function pointer to \c ColorSpace_PickColor. */
	ColorSpace_Convert8to16			Convert8to16;		 /**< Function pointer to \c ColorSpace_Convert8to16. */
	ColorSpace_Convert16to8			Convert16to8;		 /**< Function pointer to \c ColorSpace_Convert16to8. */
	ColorSpace_ConvertToMonitorRGB	ConvertToMonitorRGB; /**< Function pointer to \c ColorSpace_ConvertToMonitorRGB. */
	ColorSpace_Convert32to8			Convert32to8;		 /**< Function pointer to \c ColorSpace_Convert32to8. */
	ColorSpace_ConvertForDisplay	ConvertForDisplay;	 /**< Function pointer to \c ConvertForDisplay. */
	ColorSpace_GetDisplayProfile	GetDisplayProfile;	 /**< Function pointer to \c GetDisplayProfile. */
	
} PSColorSpaceSuite2;

//-------------------------------------------------------------------------
//	ColorSpace suite version 1
//-------------------------------------------------------------------------

/// Color Space Suite, Version 1.
#define kPSColorSpaceSuiteVersion1		1

/** The set of routines available in the Color Space suite. */
typedef struct 
{
	ColorSpace_Make					Make;				 /**< Function pointer to \c ColorSpace_Make. */
	ColorSpace_Delete				Delete;				 /**< Function pointer to \c ColorSpace_Delete. */
	ColorSpace_StuffComponents		StuffComponents;	 /**< Function pointer to \c ColorSpace_StuffComponents. */
	ColorSpace_ExtractComponents	ExtractComponents;	 /**< Function pointer to \c ColorSpace_ExtractComponents. */
	ColorSpace_StuffXYZ				StuffXYZ;			 /**< Function pointer to \c ColorSpace_StuffXYZ. */
	ColorSpace_ExtractXYZ			ExtractXYZ;			 /**< Function pointer to \c ColorSpace_ExtractXYZ. */
	ColorSpace_Convert8 			Convert8;			 /**< Function pointer to \c ColorSpace_Convert8. */
	ColorSpace_Convert16			Convert16;			 /**< Function pointer to \c ColorSpace_Convert16. */
	ColorSpace_GetNativeSpace		GetNativeSpace;		 /**< Function pointer to \c ColorSpace_GetNativeSpace. */
	ColorSpace_IsBookColor			IsBookColor;		 /**< Function pointer to \c ColorSpace_IsBookColor. */
	ColorSpace_ExtractColorName		ExtractColorName;	 /**< Function pointer to \c ColorSpace_ExtractColorName. */
	ColorSpace_PickColor			PickColor;			 /**< Function pointer to \c ColorSpace_PickColor. */
	ColorSpace_Convert8to16			Convert8to16;		 /**< Function pointer to \c ColorSpace_Convert8to16. */
	ColorSpace_Convert16to8			Convert16to8;		 /**< Function pointer to \c ColorSpace_Convert16to8. */
	ColorSpace_ConvertToMonitorRGB	ConvertToMonitorRGB; /**< Function pointer to \c ColorSpace_ConvertToMonitorRGB. */
	ColorSpace_Convert32to8			Convert32to8;		 /**< Function pointer to \c ColorSpace_Convert32to8. */
	
} PSColorSpaceSuite1;

/******************************************************************************/

#ifdef __cplusplus
}
#endif

/** @} */
#endif	// PIColorSpaceSuite
