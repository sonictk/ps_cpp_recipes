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
 *	\file PIProperties.h
 *
 *	\brief This file contains the public definitions and structures
 *		for the properties callback suite.
 *
 *	\details
 *		If you are working with any properties via the properties
 *		or action get mechanisms, this documents what is available
 *		and its basic format.
 *
 *	Distribution:
 *		PUBLIC
 *
 */

#ifndef __PIProperties_h__ // Already defined?
#define __PIProperties_h__

#if PRAGMA_ONCE
#pragma once
#endif

//-------------------------------------------------------------------------------
/** @defgroup PropertyKeys Property Keys Recognized by Property Suite Callbacks
* Properties are either simple (represented by a 32 bit integer) or complex (represented 
* by a handle).  Some properties can be modified by calling @ref SetPropertyProc, others are
* read-only, and can only be used with @ref GetPropertyProc.
*/

///@ingroup PropertyKeys
///@{
/** Number of channels in the document; (Simple, read-only). */  
#define propNumberOfChannels  'nuch'

/** Name of the channel; (Complex, read-only). The channels are indexed from 0 and consist of the 
* composite channels, the transparency mask, the layer mask, and the alpha channels.
*/
#define propChannelName		  'nmch'

/**	Unicode characters for the name of the channel; (Complex, read-only).
*/
#define propUnicodeChannelName 'unch'

/** Lock bits for the target layer; (Simple, read-only). 
* See @ref TargetLayerLockBits "target layer lock bits".
*/
#define propTargetLayerLock	  'tllk'
///@}

/** @defgroup TargetLayerLockBits Target Layer Lock Bits
*/

///These are returned for @ref propTargetLayerLock. 
///@ingroup TargetLayerLockBits
//@{
#define propTargetLayerLockNone					0x0		  /**< No layer lock bit. */
#define	propTargetLayerLockTransparency			0x1 << 0  /**< Transparency layer lock bit. */
#define	propTargetLayerLockComposite			0x1 << 1  /**< Composite layer lock bit. */
#define	propTargetLayerLockPosition				0x1 << 2  /**< Position layer lock bit. */
//@}

///@ingroup PropertyKeys
///@{
/** Mode of the image, returned using the @ref ImageModes "Image Modes" constants; (Simple, read-only).
*/
#define propImageMode		  'mode'

/** Number of paths in the document; (Simple, read-only).
*/
#define propNumberOfPaths	  'nupa'

/** Name of the indexed path; (Complex, read-only). The paths are indexed starting with zero.
* A complex, read-only property.
*/
#define propPathName          'nmpa'

/** Unicode name of the indexed path; (Complex, read-only). 
*/
#define propUnicodePathName	  'unmp'

/// Returns the contents of the indexed path (zero-based). (Complex):
/**	 
* Contents of the indexed path in the format described 
* in the path resources documentation; (Complex, read-only). 
* The paths are indexed starting with zero. The data is stored in big 
* endian form. Refer to chapter 10 for more information on path data.
*/
#define propPathContents      'path'

/**	 
* Contents of the path as Illustrator data; (Complex, read-only).  The paths are indexed
* starting with zero.  
*/
#define propPathContentsAI	  'paAI'

/**  
* Index of the work path; (Simple, read-only).  The value of the property is -1 if no work path.
*/ 
#define propWorkPathIndex     'wkpa'

/**  
* Index of the clipping path; (Simple, read-only).  The value of the property is -1 if no clipping path.
*/ 
#define propClippingPathIndex 'clpa'

/**  
* Index of the target path; (Simple, read-only).  The value of the property is -1 if no target path.
*/ 
#define propTargetPathIndex   'tgpa'

/**  
* File caption information in a IPTC-NAA record; (Complex, modifiable). 
* For more information, see <em> Photoshop File Formats.pdf. </em>
*/ 
#define propCaption			  'capt'

/**  
* File XMP meta information in a IPTC-NAA record; (Complex, modifiable). 
*/ 
#define propXMP			  	  'xmpd'

/**	
* Horizontal component of the nudge distance, represented as a 16.16 value; (Simple, modifiable). 
* This is the value used when moving around using the shift key. 
* The default value is ten pixels. 
*/
#define propBigNudgeH		  'bndH'

/**	
* Vertical component of the nudge distance, represented as a 16.16 value; (Simple, modifiable). 
* This is the value used when moving around using the shift key. 
* The default value is ten pixels. 
*/
#define propBigNudgeV		  'bndV'

/**	 
* Current interpolation method; (Simple, read-only). 
* 1=nearest neighbor, 2=bilinear, 3=bicubic, 
* 4=bicubic smoother, 5=bicubic sharper, 6=bicubic automatic
* 32 bit documents will be nearest neighbor or bilinear only
*/
#define propInterpolationMethod 'intp'

/**	 
* Current ruler units; (Simple, read-only). For values, see @ref RulerUnits.
*/
#define propRulerUnits		    'rulr'
///@}

/** Types of ruler units. */
typedef enum
	{
	kRulerPixels,			   /**< Ruler units in pixels */
	kRulerInches,			   /**< Ruler units in inches */
	kRulerCm,				   /**< Ruler units in centimeters */
	kRulerMillimeters,		   /**< Rule units in millimeters. Type units in Japan (Q/Ha saved for 7) */
	kRulerPoints,			   /**< Ruler units in points */
	kRulerPicas,			   /**< Ruler units in picas */
	kRulerPercent			   /**< Ruler units in percent */
	} RulerUnits;

///@ingroup PropertyKeys
///@{
/**	
* Horizontal component of the current ruler origin, represented as a 16.16 value; (Simple, modifiable).
*/
#define propRulerOriginH		'rorH'
/**	 
* Vertical component of the current ruler origin, represented as a 16.16 value; (Simple, modifiable).
*/
#define propRulerOriginV		'rorV'

/**	
* Current major grid rules, in inches, unless \c propRulerUnits is pixels, and
* then pixels; (Simple, modifiable).  Represented as 16.16 value. 
*/
#define propGridMajor			'grmj'

/**	 The current number of grid subdivisions per major rule; (Simple, modifiable).
*/
#define propGridMinor			'grmn'

/**	
* The serial number string shown to the user; (Complex, read-only).
* \deprecated - Use propSerialString2 below 
*/
#define propSerialString		'sstr'

/**	
* The serial number string shown to the user; (Complex, read-only). 
*/
#define propSerialString2		'sstR'

/**	 
* Hardware gamma table.	Only valid for Windows; (Complex, read-only).
*/
#define propHardwareGammaTable	'hgam'

/**	
* The interface color scheme; (Complex, read-only). Allows a plug-in interface to mimic system colors. 
* The handle returned from \c getPropertyProc can be cast as a \c PIInterfaceColor structure.
* @note Currently, user-selected system colors are supported on Windows; 
* when they are available on MAC OS, they will likely be supported in future 
* versions of Photoshop through this same mechanism.
* 
* The color scheme is indexed, see @ref InterfaceColorIndex 
* "Interface Color Indexes" for index values to pass into \c getPropertyProc.	
* These interface color values map onto Photoshop system colors according to the following diagram:
*
* <DIV> <IMG SRC="./images/InterfaceScheme.gif"></DIV>
*
* Constants are remapped to create the system look. Use the indexed color scheme to draw PICTs.
* <DIV> <IMG SRC="./images/InterfaceSystem.gif"></DIV>
* 
* \deprecated - Use @ref propUIBrightness, @ref propCheckerboardColor1, 
* @ref propCheckerboardColor2, @ref propCheckerboardSize, @ref propUseCheckerboard below.
*/
#define propInterfaceColor		'iclr'

/**
* The watch suspension level; (Simple, modifiable). When non-zero, a plug-in can make callbacks to the host 
* without fear that the watch will start spinning. It is reset to zero at the beginning 
* of each call from the host to the plug-in. 
*/
#define propWatchSuspension		'wtch'

/**
* Whether the current image is considered under copywrite; (Simple, modifiable).
* This property key can only be used to set the flag.
*/
#define propCopyright			'cpyr'

/**
* Whether the current image is considered under copywrite; (Simple, modifiable).
*/
#define propCopyright2			'cpyR'

/**	 
* Indicates whether a digital signature or watermark is present; (Simple, modifiable). 
* The (c) copyright symbol will appear if this is set, or if the user has checked 
* the copyrightproperty in the File Info dialog. Do not turn the copyright flag off, ever. 
* Use to indicate if you have found your digital signature.
*/
#define propWatermark			'watr'

/**	The URL for the current image; (Complex, modifiable). 
*/
#define propURL					'URL '

/**	
* The title of the current document; (Complex, read-only).
*/
#define propTitle				'titl'

/**
* The width of the current document in pixels; (Simple, read-only). 
*/
#define propDocumentWidth		'docW'

/**
* The height of the current document in pixels; (Simple, read-only).
*/
#define propDocumentHeight		'docH'

/**
* The slices for the document; (Complex, modifiable).
* See the Slices resource format documented in <em> Photoshop File Formats.pdf. </em>
*/
#define propSlices				'slcs'

/**
* The currently selected slice ID; (Simple, modifiable).
*/
#define propSelectedSliceID		'slid'

/**
* The currently selected slice ID list; (Complex, modifiable).
*/
#define propSelectedSliceIDList	'slis'

/**
* The currently selected slice index; (Simple, read-only).
*/
#define propSelectedSliceIndex	'slin'

// Whether the slice numers are show (Simple)
/**
* Indicate whether the user has set slice numbers to show; (Simple, read-only). 
*/
#define propShowSliceNumbers	'slsh'

/**
* The color of the slice lines; (Complex, read-only).
*/
#define propSliceLineColor		'sllc'

/**	 
* Tool tip display; (Simple, read-only). The value is 0 if off, 1 if on. 
*/
#define propToolTips			'tltp'

/**	
* Type of paint cursor being used; (Simple, read-only). 1 = standard; 2 = precise; 3 = brush size.
*/
#define propPaintCursorKind		'PCrK'

/**	 
* Cursor options being used; (Simple, read-only). 1 = normal; 2 = full sized.
*/
#define propPaintCursorShape	'PCrS'

/**
* Cursor crosshair visibility; (Simple, read-only). 
* 0 = not visible; 1 = visible.
*/
#define propPaintCursorCrosshair	'PCrC'

/**
* Fetch Preference setting: Zoom with Scroll Wheel; (Simple, read-only).
* 0 = off (use alt key to zoom), 1 = on (mouse scroll wheel does zoom)
*/
#define propZoomWithScrollWheel     'zScW'

/**
* EXIF camera and device data; (Complex, modifiable).
* The EXIF property is controlled by The Japan Electronic Industry Development 
* Association (JEIDA) and Electronic Industries Association of Japan (EIAJ) 
* which merged in November of 2000. The EXIF specification can be downloaded from 
* their web site at the following location:
* http://it.jeita.or.jp/jhistory/document/standard/exif_eng/jeida49eng.htm
*/
#define propEXIFData			'EXIF'

// current version of photoshop Major.Minor.Fix
/**
* Current version of Photoshop.  
* Major.Minor.Fix 
*/
#define propVersion				'vers'

// Is an action play in progress? actions palette or automation plug in(Simple)
/**
* Action play information, for actions palette or automation plug in; (Simple, read-only).
*/
#define propPlayInProgress		'plip'

// Is an action recording in progress? actions palette (Simple)
/**
* Action recording information, for actions palette; (Simple, read-only).
*/
#define propRecordInProgress	'rcip'

// Get the unicode name of the document
/**
* Unicode name of the document; (Complex, read-only).
*/
#define propUnicodeName			'unnm'

// Get the unicode name of the document
/**
* Unicode name of the document; (Complex, read-only).
*/
#define propUniStr255Name		'u25n'

/**
* Unicode name of the document without extension; (Complex, read-only).
*/
#define propUnicodeNameWithoutExtension 'neun'

/**
* Global "Don't show again" counter for dialog boxes; (Simple, read-only).  
* The property value is incremented
* every time these dialogs are reset.  Each dialog that supports this feature
* should maintain its own unsigned32 counter in the preferences file.  It
* should be initialized to zero.  Before showing the dialog, the local counter
* should be compared to the global counter.  If equal, don't show the dialog.
* When the user checks the "Don't show again" check box, the local counter
* should be set to the master counter. 
*/
#define propDontShowAgainCount	'DSAC'

/**
* Number of layers in the document; (Simple, read-only).
*/
#define propNumberOfLayers		'nuly'

/**
* Index of the target layer; (Simple, read-only).
*/
#define propTargetLayerIndex	'tgly'

/**
* Layer name of the layer with a given index; (Complex, read-only).
*/
#define propLayerName			'lynm'

/**
* Layer name as a unicode string of the layer with a given index; (Complex, read-only).
*/
#define propUnicodeLayerName	'lynu'

/**
* Pixel aspect ratio for the document; (Simple, read-only).
*/
#define propPixelScaleFactor	'pxsf'

/**
* Current operation is part of a place command; (Simple, read-only).
* Provided for file formats that need to record descriptors differently when placing.
*/
#define propDoingPlace			'DPlc'

/**
* Current operation is part of rasertizing a smart object; (Simple, read-only).
* Provided for file formats that need to read/obey descriptors differently when rasterizing.
*/
#define propRasterizingSmartObject	'RsSO'

/**
* Use this property to tell if Photoshop is in a modal dialog or a modal tool. (Simple)
*/
#define propAppIsModal			'aism'

/**
* This property can be used to query about the current Undo setting of the host. (Simple, read-only).
* The returned boolean is true if new (multi) Undo is enabled. If the property returns
* false, then legacy Undo has been enabled by the user.
* This setting corresponds to the following UI location:
* Keyboard Shortcuts and Menus > Use Legacy Undo Shortcuts
* (Simple)
*/
#define propUseMultiUndo        'umuu'

/**
* measurement scale pixel length (Simple)
*/
#define propPixelLength				'MSpl'

/**
* measurement scale logical length(Simple)
*/
#define propLogicalLength				'MSll'

/**
* measurement scale units in unicode string (Complex)
*/
#define propMUnits				'MSun'

/**
* tile size in bytes (Simple, read-only)
*/
#define propTileSize		'TSiz'

/**
* Drover library has initialized correctly (Simple, read-only)
*/
#define propDroverIsInitialized	'drov'

/**
* Photoshop scratch disk volumes (Complex, read-only)
* A list of 4-byte volume index that users have picked as preferred scratch volumes. 
* On windows, this index is 1 based, started from "A:", so "C:" drive will be 3, "G:" will be 7, etc. 
*/
#define propScratchVolumeList	'svls'

/**
* The primary updated UX color. 0,0,0 if updated UX is off. (Complex, read-only)
*/
#define propUXPrimaryColor	'Uxpc'

/**
* The secondary updated UX color. 0,0,0 if updated UX is off. (Complex, read-only)
*/
#define propUXSecondaryColor	'Uxsc'

/**
* Flag for whether or not to use updated UX. (Simple, read-only)
*/
#define propUXUseUpdatedUX	'Uxuu'

/**
* The color of a guide line, RGBColor. All guides have the same color. (Complex, read-only)
*/
#define propGuideColor	'Grdc'

/**
* The number of guide lines in the document. (Simple, read-only)
*/
#define propGuideCount	'GrdL'

/**
* Is the guide with the given index horizontal. (Simple, read-only)
*/
#define propGuideDirIsHoriz	'GrdH'

/**
* The horizontal or vertical coordinate (as a double) of the guide by index.  See
* property above for determining if guide is horizontal. (Simple, read-only)
*/
#define propGuideCoordinate	'GClr'

/**
* GPUFlags (Simple, read-only)
* bits are 0000,anbp,egc0,00mm
* a=Advanced mode *could* be selected by the user -- it is allowed
* n=Normal mode *could* be selected by the user -- it is allowed
* b=Basic mode *could* be selected by the user -- it is allowed
* e=GPU is enabled
* g=use OpenGL for computation
* c=use OpenCL for computation
* mm=drawing mode, 0..2
*/
#define propGPUFlags				'GPUF'
#define kGPUFlagsModeMask			0x0003
#define kGPUFlagsModeShift			0
#define kGPUFlagsBasic				0
#define kGPUFlagsNormal				1
#define kGPUFlagsAdvanced			2
#define GPUFlagsGetMode(FLAGS)		(((FLAGS) & kGPUFlagsModeMask) >> kGPUFlagsModeShift)
#define GPUFlagsSetMode(MODE)		(((MODE) << kGPUFlagsModeShift) & kGPUFlagsModeMask)
#define kGPUFlagsCLCompute			0x0020
#define kGPUFlagsGLCompute			0x0040
#define kGPUFlagsGPUEnabled			0x0080	// OpenGL checkbox is checked
#define kGPUFlagsGPUPossible		0x0100	// OpenGL checkbox is not dimmed
#define kGPUFlagsBasicPossible		0x0200	// Basic mode *could* be selected by the user
#define kGPUFlagsNormalPossible		0x0400	// Normal mode *could* be selected by the user
#define kGPUFlagsAdvancedPossible	0x0800	// Advanced mode *could* be selected by the user

/**
* The the available VRAM in units of 1024*1024 bytes. (Simple, read-only)
*/
#define propVRAM_MB					'VRAM'

/**
* Use this property to get current layer bounds. (Complex, read-only).
*/
#define propLayerBounds             'lbnd'

/**
* Use this property to tell if the current layer is a smart object layer. (Simple, read-only)
*/
#define propLayerIsSmart			'liss'

/**
* Use this property to tell if the host application is Hi-DPI aware. (Simple, read-only)
*/
#define propHDPIAware				'HDPI'

/**
* Use this property to tell the current UI brightness. 
* 0 = bright, 1 = light gray, 2 = medium gray, 3 = dark gray. (Simple, read-only)
*/
#define propUIBrightness			'UIBR'

/**
* Use this property to tell the current highlight color.
*/
#define propHighlightColor			'HLCR'

/**
* Use this property to tell if the host application has large tabs on. (Simple, read-only)
*/
#define propLargeTabs				'LGTB'

/**
 * Use this property to tell if the host application is scaling UI to font. (Simple, read-only)
 * 95 = Tiny, 100 = No Scaling, 105 = Small, 110 = Medium, 115 = Large
 */
#define propScaleUIToFontZoom       'SUFZ'

/**
* The color of checkerboard 1, RGBColor. (Complex, read-only).
*/
#define propCheckerboardColor1		'cHK1'

/**
* The color of checkerboard 2, RGBColor. (Complex, read-only).
*/
#define propCheckerboardColor2		'cHK2'

/**
* The size of the checkerboard,
* 0 = no size, 4 = small, 8 = medium, 16 = large. (Simple, read-only).
*/
#define propCheckerboardSize		'cHKz'

/**
* Use checkerboard or default white. (Simple, read-only).
*/
#define propUseCheckerboard         'UcHK'

///@}
//-------------------------------------------------------------------------------

#endif // __PIProperties_h__
