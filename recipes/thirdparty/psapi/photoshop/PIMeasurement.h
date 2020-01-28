// ADOBE SYSTEMS INCORPORATED
// Copyright  2006 - 2007 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 *	\file PIMeasurement.h
 *
 *	\brief This file describes Photoshop's Measurement module interface.
 *
 *	Distribution:
 *		PUBLIC	
 *
 */

#ifndef __PIMeasurement__
#define __PIMeasurement__

#include "PIActions.h"
#include "PIGeneral.h"

#include "SPBasic.h"

/******************************************************************************/

// Operation selectors
#define measurementSelectorAbout						0
#define measurementSelectorRegisterDataPointDataTypes	1
#define measurementSelectorRegisterDataPoints			2
#define measurementSelectorPrepareMeasurements			3
#define measurementSelectorRecordMeasurements			4
#define measurementSelectorExportMeasurement			5

// Feature mask values
#define featureMaskForegroundMask						0x2000
#define featureMaskEdgeTouchingMask						0x1000
#define featureMaskIdentifierMask						0x0FFF

/******************************************************************************/

/*

Extent
======
Class: kmeasurementLogExtentClassStr
Parameters:
	kminimumStr				String/Integer*		Minimum extent of cell for Data Point
	kmaximumStr				String/Integer*		Maximum extent of cell for Data Point
	kcurrentStr				String/Integer*		Initial current extent of cell for Data Point
	
* If type is String then the width or height of the specified string is
calculated using the display font.  If the type is Integer then that exact value
is used for the extent.	
	
Data Point Data Type
===============
Class: kmeasurementLogDataPointDataTypeClassStr
Parameters:
	kIDStr					String	Required	Unique identifier for Data Point Data Type
	kparentIDStr			String	Required	Identifier of existing Data Point Data Type
	kallowUserModifyStr		Boolean Optional	Is Data Point Data Type editable, parent must also be editable, defaults to false
	kheightStr				Object	Optional	See above
	kwidthStr				Object	Optional	See above
	
** The core data point data type IDs are "Integer", "Float", "String", "Boolean", "Generic".
The "Integer", "Float", "String", and "Boolean" core types require that any
associated Data Point Data have a property with key "kvalueStr" of the corresponding
type.

*** Only types with parent type of "String" can have allowUserModify set to true

Data Point
==========
Class: kmeasurementLogDataPointClassStr
Parameters:
	kIDStr					String	Required	Identifier of Data Point
	ktypeIDStr				String	Required	Identifier of existing Data Point Data Type
	kfullNameStr			String	Required	Full name
	kdisplayNameStr			String	Optional	Name displayed in Measurement Log, defaults to value of kfullNameStr
	kabbreviatedNameStr		String	Optional	Short name displayed in Measurement Log, defaults to value of kdisplayNameStr
	kdescriptionStr			String	Optional	Description displayed in Measurement Log, defaults to value of kdisplayNameStr
	kallowUserModifyStr		Boolean Optional	Is Data Point editable, Data Point Data Type must also be editable, defaults to false
	kheightStr				Object	Optional	See above
	kwidthStr				Object	Optional	See above
	
Data Point Data
===============
Class: kmeasurementLogDataPointDataClassStr
Parameters:
	kvalueStr				Integer/Float/String/Boolean/Object or none
	<anything>**
	
** Any data specific to the Data Point Type
*/

// Core Data Point Data Type identifiers
#define kPIM_DataPointDataType_Generic_Identifier	"Generic"
#define kPIM_DataPointDataType_Integer_Identifier	"Integer"
#define kPIM_DataPointDataType_Float_Identifier		"Float"
#define kPIM_DataPointDataType_String_Identifier	"String"
#define kPIM_DataPointDataType_Boolean_Identifier	"Boolean"
#define kPIM_DataPointDataType_Time_Identifier		"Time"
#define kPIM_DataPointDataType_Scaled_Identifier	"Scaled"

/******************************************************************************/

#ifndef RC_INVOKED

/******************************************************************************/

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

#if WIN32
#pragma pack(push,4)
#endif

/******************************************************************************/

typedef struct MeasurementBaseRecord
	{
	// Suites
	SPBasicSuite			*basicSuite;					/* SuitePea basic suite */

	BufferProcs				*bufferProcs;					/* The host buffer procedures */

	HandleProcs				*handleProcs;					/* Platform independent handle manipulation */

	ResourceProcs			*resourceProcs;					/* The host plug-in resource procedures */
	
	PropertyProcs			*propertyProcs;					/* Routines to query and set document and
															   view properties. The plug-in needs to
															   dispose of the handle returned for
															   complex properties (the plug-in also
															   maintains ownership of handles for
															   set properties). */

	// Procs
	TestAbortProc			testAbortProc;					/* The plug-in module may call this no-argument
															   BOOLEAN function (using Pascal calling
															   conventions) several times a second during long
															   operations to allow the user to abort the operation.
															   If it returns TRUE, the operation should be aborted
															   (and a positive error code returned). */

	ProgressProc			progressProc;					/* The plug-in module may call this two-argument
															   procedure periodically to update a progress
															   indicator.  The first parameter is the number
															   of operations completed; the second is the total
															   number of operations. */

	HostProc				hostProc;						/* Host specific callback procedure */

	// Members
	void					*plugInRef;						/* Plugin reference used by SuitePea */
	
	OSType					hostSignature;					/* Creator code for host application */

	void					*platformData;					/* Platform specific information */
	
	char					reserved[256];					/* Reserved.  Set to zero. */
	}
MeasurementBaseRecord, *MeasurementBaseRecordPtr;

/******************************************************************************/

typedef struct MeasurementRegisterRecord
	{
	// Inherited
	MeasurementBaseRecord	*base;
	
	// Members - Register
	PIActionList			registration;					/* Objects to register.  Enclose parameters
															   in an PIActionDescriptor. */
	
	char					reserved[256];					/* Reserved.  Set to zero. */
	}
MeasurementRegisterRecord, *MeasurementRegisterRecordPtr;

/******************************************************************************/

typedef struct MeasurementPrepareRecord
	{
	// Inherited
	MeasurementBaseRecord	*base;
	
	// Procs
	ColorServicesProc		colorServicesProc;				/* Routine to access color services */

	// Members - General - Original
	int32					hostSpaceMaximum;				/* Maximum possible total of data and buffer space */
	
	Boolean					hostSupportsLayouts;
	Boolean					hostSupportsImagePadding;
	Boolean					hostSupportsDummyPlanes;
	int8					hostSamplingSupport;
	
	// Members - Document - Original
	real32					documentScaleFactor;			/* Document measurement scale factor */
	
	// Members - Image - Original
	int16					imageDepth;						/* Bit depth per channel (1, 8, 16) */
	int16					imageMode;						/* Image mode */

	VRect					imageRect;						/* Bounds of image */
	
	int16					imageTotalPlanes;				/* Total planes in image (mode + alpha) */
	int16					imageModePlanes;				/* Planes dependant upon mode */
	int16					imageAlphaPlanes;				/* Alpha planes */
	int16					padding;						/* Ignore */
	PIActionList			imageAlphaPlaneOptions;			/* List of alpha plane option descriptors: */
															/* Each descriptor contains: */
															/* keyName, String, optional name of plane */
															/* keyColorIndicates, typeMaskIndicator, enumMaskedAreas/enumSelectedAreas/enumSpotColor */
															/* keyColor, Descriptor, color information */
															/* keyOpacity, Integer, 0-100 */

	VPoint					imageTileOrigin;				/* Tiling for the input */
	int16					imageTileHeight;
	int16					imageTileWidth;

	ColorTableInfo			*imageColorTable;				/* Color table for indexed and duotone */
	
	Handle					imageICCProfileData;			/* Handle containing the ICC profile for the image. (NULL if none)
															   Photoshop allocates the handle using Photoshop's handle suite.
															   The handle is unlocked while calling the plug-in.
															   The handle will be valid from Start to Finish.
															   Photoshop will free the handle after Finish. */
	
	int32					imageICCProfileDataSize;		/* Size of profile data */

	// Members - Gray - Original
	int16					grayDepth;						/* Bit depth per channel (1, 8, 16) */
	int16					grayMode;						/* Image mode */

	VRect					grayRect;						/* Bounds of image */
	
	VPoint					grayTileOrigin;					/* Tiling for the input */
	int16					grayTileHeight;
	int16					grayTileWidth;

	Handle					grayICCProfileData;				/* Handle containing the ICC profile for the image. (NULL if none)
															   Photoshop allocates the handle using Photoshop's handle suite.
															   The handle is unlocked while calling the plug-in.
															   The handle will be valid from Start to Finish.
															   Photoshop will free the handle after Finish. */
	
	int32					grayICCProfileDataSize;			/* Size of profile data */

	// Members - Mask - Original
	VRect					maskRect;						/* Bounds of mask */
	
	VPoint					maskTileOrigin;					/* Tiling for the mask */
	int16					maskTileHeight;
	int16					maskTileWidth;
	
	int16					maskFeatureCount;				/* Count of identified features in mask */
	int16					padding1;						/* Ignore */
	
	// Members - Output - Original
	PIActionList			dataPointIdentifiers;			/* List of data point identifier strings to record. */

	// Members - General - Request
	int32					requestSpaceReserve;			/* If the plug-in filter needs to allocate
															   large internal buffers, the 
															   measurementSelectorPrepareMeasurements
															   routine should set this field to the number
															   of bytes the measurementSelectorRecordMeasurements 
															   routine is planning to allocate.  Relocatable 
															   blocks should be used if possible. */
	
	char					reserved[256];					/* Reserved.  Set to zero. */
	}
MeasurementPrepareRecord, *MeasurementPrepareRecordPtr;

/******************************************************************************/

typedef struct MeasurementRecordRecord
	{
	// Inherited
	MeasurementPrepareRecord	*prepare;
	
	// Procs
	AdvanceStateProc		advanceStateProc;				/* Advance from start to continue or
															   continue to continue. */

	// Members - Request
	Boolean					requestImage;
	Boolean					requestGray;
	Boolean					requestMask;
	Boolean					padding;						/* Ignore */

	// Members - Image - Request
	VRect					requestImageRect;				/* Requested image rectangle.  Must be a subset of fImageRect. */

	int16					requestImagePlaneLo;			/* First requested image plane */
	int16					requestImagePlaneHi;			/* Last requested image plane */
	
	int16					requestImageLayout;				/* The layout to use for the data.
															   See PIGeneral for the values.  */

	int16					requestImagePadding;			/* Instructions for padding the data. */
	
	/* We allow for extra planes in the input and the output.  These planes
	   will be filled with dummyPlaneValue at those times when we build the
	   buffers.  These features will only be available if supportsDummyPlanes
	   is TRUE. */
	
	int16					requestImageDummyPlanesPre;		/* Extra planes to allocate in the input. */
	int16					requestImageDummyPlanesPost;
	
	int16					requestImageDummyPlanesValue;	/* 0..255 = fill value, -1 = leave undefined
															   All others generate errors. */
	int16					padding1;						/* Ignore */

	Fixed					requestImageSampleRate;			/* Image sample rate */
	
	// Members - Image - Response
	void					*responseImageData;				/* Pointer to image data (read-only, interleaved) */
	int32					responseImageRowBytes;			/* Step between image rows */
	int32					responseImageColumnBytes;		/* Step between image columns */
	int32					responseImagePlaneBytes;		/* Step between image planes */

	// Members - Gray - Request
	VRect					requestGrayRect;				/* Requested image rectangle.  Must be a subset of fImageRect. */

	int16					requestGrayLayout;				/* The layout to use for the data.
															   See PIGeneral for the values.  */
	int16					requestGrayPadding;				/* Instructions for padding the data. */
	
	int16					requestGrayDummyPlanesPre;		/* Extra planes to allocate in the input. */
	int16					requestGrayDummyPlanesPost;
	
	int16					requestGrayDummyPlanesValue;	/* 0..255 = fill value, -1 = leave undefined
															   All others generate errors. */
	int16					padding2;						/* Ignore */

	Fixed					requestGraySampleRate;			/* Image sample rate */
	
	// Members - Gray - Response
	void					*responseGrayData;				/* Pointer to image data (read-only, interleaved) */
	int32					responseGrayRowBytes;			/* Step between image rows */
	int32					responseGrayColumnBytes;		/* Step between image columns */
	int32					responseGrayPlaneBytes;			/* Step between image planes */

	// Members - Mask - Request
	VRect					requestMaskRect;				/* Requested mask rectangle.  Must be a subset of fMaskRect. */
	
	int16					requestMaskPadding;				/* Padding instructions for the mask */
	int16					padding3;						/* Ignore */
	
	Fixed					requestMaskSampleRate;			/* Mask sample rate */
	
	// Members - Mask - Response
	void					*responseMaskData;				/* Pointer to (read only) mask data */
	int32					responseMaskRowBytes;			/* Offset between mask rows */
	int32					responseMaskColumnBytes;		/* Step between mask columns */
	int32					responseMaskPlaneBytes;			/* Step between mask planes */
	
	// Members - Output - Final
	PIActionDescriptor		summaryData;					/* Measurement data about entire image stored here */
	PIActionDescriptor		*featureData;					/* Array of measurement data about individual features.
															   Array size is fMaskFeatureCount. */
	
	char					reserved[256];					/* Reserved.  Set to zero. */
	}
MeasurementRecordRecord, *MeasurementRecordRecordPtr;

/******************************************************************************/

typedef struct MeasurementExportRecord
	{
	// Inherited
	MeasurementBaseRecord	*base;
	
	// Members - General
	SPPlatformFileSpecificationW	dataDirectory;			/* Directory to store files related to export */
	
	// Members - Data
	PIActionDescriptor		dataPointDataType;				/* Type of data point data to export. */
	PIActionDescriptor		dataPointData;					/* Data point data to export. */
	
	// Members - Output
	ASZString				exportString;					/* String to record as output in CSV. */
	Boolean					exportData;						/* Was a file written to the data directory? */
	Boolean					padding[3];						/* Ignore */
	
	char					reserved[256];					/* Reserved.  Set to zero. */
	}
MeasurementExportRecord, *MeasurementExportRecordPtr;

/******************************************************************************/

#if WIN32
#pragma pack(pop)
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

/******************************************************************************/

#endif	/* RC_INVOKED */

#endif	/* __PIMeasurement__ */
