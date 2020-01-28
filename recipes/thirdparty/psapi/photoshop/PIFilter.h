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
 *	\file PIFilter.h
 *
 *	\brief This file describes Photoshop's Filter module interface
 *
 *	Distribution:
 *		PUBLIC	
 *
 */

/** @defgroup FilterModule Filter Module  
* Filter plug-in modules modify a selected area of an image, and are accessed 
* under the \b Filter menu. 
*
* The file type for filter modules for Mac OS is 8BFM, the extension for Windows is .8BF.

* Please also see @ref PGFilterModule "Writing Filter Plug-ins.
*/


#ifndef __PIFilter__
#define __PIFilter__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "PSGraphicTypes.h"

#include "SPBasic.h"

/* Operation selectors */



///@name Filter Module Selectors 
//@{

/** @ingroup FilterModule 
* @{
*/
/**  Allows the plug-in to display an about box for the Export Module. For this
* selector, the host does not pass the standard parameter block into the plug-in 
* main routine.  Instead it passes an \c AboutRecord. 
*
* See @ref PGAboutBoxes	"About Boxes" for more information.
*/
#define filterSelectorAbout 	 0

/**
* Provides a means for the plug-in to prompt the user for any user-settable parameters. 
* The plug-in should save the parameter values provided by the user in a relocatable 
* memory block whose handle is stored in \c FilterRecord::parameters.
*
* For further information, see @ref PGFilterParameters "Working with Filter Parameters."
*/
#define filterSelectorParameters 1

/** 
* Allows your plug-in module to adjust the Photoshop memory allocation algorithm.
* The <b>Last Filter</b> command initially executes this selector call first. \n\n
* Photoshop sets \c maxSpace64 to the maximum number of bytes it can allocate to your plug-in. 
* You may want to reduce \c maxSpace64 for increased efficiency.\n\n 
* If your plug-in filter module plans on allocating any large buffers or tables over 32k, 
* it should set the \c bufferSpace64 field to the number of bytes it plans to allocate. 
* Photoshop then tries to free up that amount of memory before calling the plug-in’s 
* \c filterSelectorStart handler. \n\n
* Alternatively, the plug-in can set this field to zero and use the 
* @ref PicaBufferSuite and @ref PicaHandleSuite 
* if they are available. See @ref PGMemoryMgmtStrategies "Memory Management Strategies"
* for a discussion on \c maxSpace64 and \c bufferSpace64.	\n\n
* The fields \c BigDocumentStruct::imageSize32, \c FilterRecord::planes, and 
* \c BigDocumentStruct::filterRect32  can be used in computing your buffer size requirements. 
*/
#define filterSelectorPrepare	 2

/**
* Provides a means for your plug-in to validate the parameters block, update the parameters 
* based on the passed scripting parameters, show its user interface, if requested, and
* then drop into its processing routine.
* The plug-in should set \c BigDocumentStruct::inRect32 and \c BigDocumentStruct::outRect32
* to request the first areas of the image to work on. It should also set \c BigDocumentStruct::maskRect32
* if it is using the selection mask. See @ref PGFilterProcessingImage "Processing the Image" for 
* information about tiling the image. \n\n
* If the plug-in does not use \c AdvanceStateProc, then it should initialize processing and set-up 
* the first chunk of image to be manipulated in \c filterSelectorContinue. See 
* @ref PGFilterAdvanceState "Advance State and Filter Modules" for further information.
*/
#define filterSelectorStart 	 3

/**
* Continually processes plug-in data as long as it is available. The plug-in is called 
* repeatedly with this selector as long as at least one of the \c FilterRecord::inRect,
* \c BigDocumentStruct::inRect32, \c FilterRecord::outRect, \c BigDocumentStruct::outRect32, 
* \c FilterRecord::maskRect, or \c BigDocumentStruct::maskRect32 fields is not empty.  
* The handler should process the data and then update the fields to request the next area 
* of the image to process. \n\n
* @note Photoshop might call \c filterSelectorFinish instead of \c filterSelectorContinue is it detects a
* need to terminate while fulfilling a request.
* @note Be careful processing user-cancel events during \c filterSelectorContinue. Normally the 
* plug-in would be expecting another \c filterSelectorContinue call. If the user cancels, the next call 
* is \c filterSelectorFinish, not \c filterSelectorContinue!
*/
#define filterSelectorContinue	 4

/**
* Allows the plug-in to clean up after a filtering operation. This call is made 
* if and only if the \c filterSelectorStart handler returns without error, even if the 
* \c filterSelectorContinue routine returns an error.  If \c filterSelectorStart
* succeeds, Photoshop guarantees that \c filterSelectorFinish is called.\n\n
* If Photoshop detects \e Command-period in the Mac OS or \e Escape in Windows between 
* calls to the \c filterSelectorContinue routine, it calls the plug-in with \c filterSelectorFinish.	
*/
#define filterSelectorFinish	 5

/**
* @}
*/  // end ingroup

//@}

/********************************************************************************/

/** 
* @defgroup FilterCaseIdentifiers Filter Case Identifiers
* These cases are used to index
* the behavior properties and are passed to the filter in the @ref FilterRecord::filterCase field.
* of the parameter block.
*/

///@name Filter Case Identifiers: passed in filterCase field 
//@{
/** @ingroup FilterCaseIdentifiers 
* @{
*/
#define filterCaseUnsupported			 		   		   -1	 /**< Host does not support this case. */
#define filterCaseFlatImageNoSelection						1	 /**< A background layer or a flat image. There is no transparency data or selection. */
#define filterCaseFlatImageWithSelection					2	 /**< No transparency data, but a selection may be present. The selection will be presented as mask data. */
#define filterCaseFloatingSelection							3	 /**< Image data with an accompanying mask. */
#define filterCaseEditableTransparencyNoSelection			4	 /**< Layer with transparency editing enabled and no selection. 
																	  If the editable transparency cases are unsupported, then 
																	  Photoshop tries the corresponding protected transparency
																	  cases. This governs whether the filter is expected 
																	  to filter the transparency data with the color data. */
#define filterCaseEditableTransparencyWithSelection			5	 /**< Layer with transparency editing enabled and a selection. 
																	  If the editable transparency cases are unsupported, then 
																	  Photoshop tries the corresponding protected transparency 
																	  cases. This governs whether the filter is expected 
																	  to filter the transparency data with the color data.*/
#define filterCaseProtectedTransparencyNoSelection			6	 /**< Layer with transparency editing disabled and no selection. 
																	  If the protected transparency case without a selection is 
																	  disabled, the layer data is treated as a floating selection. 
																	  Transparency data will be presented via the mask portion of 
																	  the interface rather than with the input data.*/
#define filterCaseProtectedTransparencyWithSelection		7	 /**< Layer with transparency editing disabled and a selection. 
																	  If the protected transparency case without a selection is 
																	  disabled, the layer data is treated as a floating selection. 
																	  Transparency data will be presented via the mask portion of 
																	  the interface rather than with the input data.*/
/* @} */
//@}
/********************************************************************************/

/** 
* @defgroup FilterCaseInfoHandlingModes FilterCaseInfo Handling Modes
* Modes for input and output handling. These specify the preprocessing and postprocessing actions on the image data.
* Used with @ref FilterCaseInfo::inputHandling and 
* @ref FilterCaseInfo::outputHandling fields.
*/

///@name FilterCaseInfo Handling Modes 
//@{
/** @ingroup FilterCaseInfoHandlingModes 
* @{
*/
#define filterDataHandlingCantFilter		 0		/**< Indicates that this case is not supported by the plug-in filter. 
														 Used for both input and output modes. */
#define filterDataHandlingNone				 1		/**< Indicates that the plug-in filter does not expect the plug-in host 
														 to do anything to the image data. Used for both input and output modes.*/
#define filterDataHandlingBlackMat			 2		/**< Matte the image data with black (=0) values based on 
														 the transparency on input; dematte the image data using black 
														 values on output. */
#define filterDataHandlingGrayMat			 3		/**< Matte the image data with gray (=128) values based on the 
                                                         transparency on input; dematte the image data using gray values 
                                                         on output. */
#define filterDataHandlingWhiteMat			 4		/**< Matte the image data with white (=255) values based on the 
														 transparency on input; dematte the image data using white values 
														 on output. */

/* The following modes are only useful for input. */

#define filterDataHandlingDefringe			 5		/**< Defringe transparent areas filling with the nearest defined pixels 
													     using taxicab distance. This only applies to fully 
													     transparent pixels.  Input-only mode.*/
#define filterDataHandlingBlackZap			 6		/**< Set color component of totally transparent pixels to black. 
                                                         Input-only mode.*/
#define filterDataHandlingGrayZap			 7		/**< Set color component of totally transparent pixels to gray. 
                                                         Input-only mode. */
#define filterDataHandlingWhiteZap			 8		/**< Set color component of totally transparent pixels to white. 
                                                         Input-only mode. */

/* The following mode is only useful for output. */
													
#define filterDataHandlingFillMask			 9	   /**< Automatically fills the transparency mask   
														with full opacity in the area affected by the filter. 
														This is only valid for the editable transparency cases. This option
														is provided to make it easy to write a plug-in similar to 
														the Photoshop Clouds plug-in, which fills an area with a value. 
														Output-only mode. */

/* More modes for input... */

#define filterDataHandlingBackgroundZap		10		/**< Set color component of totally transparent pixels to the current 
                                                         background color. Input-only mode. */
#define filterDataHandlingForegroundZap		11		/**< Set color component of totally transparent pixels to the current 
                                                         foreground color. Input-only mode. */

/* @} */
//@}
/********************************************************************************/

/* For FilterCaseInfo (defined below) used with PIFilterCaseInfoProperty */

/* Here are the bits in flag1. */

///@name Filter Case Info Flag Bits 
//@{

/** @defgroup FilterCaseInfoFlag1Bits Filter Case Information Flag Bits 
* See @ref FilterCaseInfo.
*/

/** @ingroup FilterCaseInfoFlag1Bits 
* @{
*/

/** Determines whether source data is copied to the destination before filtering.
* This degrades performance for filters that write all the output pixels. 
* Setting this bit inhibits that behavior. 
* @note This first bit is the least-significant bit of the flag byte.
*/
#define PIFilterDontCopyToDestinationBit	0
	
/**
* Determines whether the filter will work on "blank" areas that are completely 
* transparent. This bit is set when the filter works with blank data. 
* If not, an error message is given
* when the filter is invoked on a blank area. This is only valid for the 
* editable transparency case because that is the only case where you could 
* create opacity; in the protected transparency case, you would be left with 
* what you started with: completely blank data.
*/
#define PIFilterWorksWithBlankDataBit	1
	
/**
* In cases where transparency is editable, this flag determines if Layer Masks are filtered. 
* See the "Add Layer Mask" item in the Layers palette menu to create a layer mask.\n\n
* Setting this bit adds the layer mask to the set of target channels if: 
* - transparency for the layer is editable (i.e., this is one of the editable transparency cases), 
* - the bit is set, and
* - the layer mask is specified as being positioned relative to the layer rather 
* than the image in Layer Mask Options. 
*
* The distinction based on position is based on the 
* assumption that layer relative masks are distorted with the layer; image relative masks 
* are independent of the layer.
*/
#define PIFilterFiltersLayerMaskBit		2
	
/** 
* In the image with selection and layer with selection cases, does the
* filter want to write beyond the confines of the selection? (This is
* generally rude but in some cases its better than the alternatives. If
* you use this, be sure you also think about supporting layer transparency
* data as an alternate mask.)
*/
#define PIFilterWritesOutsideSelectionBit 3
/* @} */
//@}

/********************************************************************************/

///@ingroup PiPLFilterKeys
/** 
* Filter Case information. Key value is 'fici'.
* This property key reflects the \c %FilterCaseInfo property in the PiPL resource file.
* The case properties are an array of seven four byte entries (the \c FilterCaseInfo struct), 
* one for each case identified in @ref FilterCaseIdentifiers.
* Photoshop supports dynamically composited layers of image data.
* A layer consists of color and transparency information for each pixel it contains. 
* Completely transparent pixels have an undefined color. Filters will likely affect 
* transparency data as well as color data. This is especially true for filters 
* which produce spatial distortions. <br><br>
* Photoshop offers flexibility in how transparency data is presented to filters. 
* The filter case info property controls the filtering process and presentation of 
* data to the plug-in. This property provides information to Photoshop about what
* image data cases the plug-in supports. Photoshop then compares the current filtering 
* situation to the supported cases and chooses the best fitting case. The image data 
* is then presented in that case. If none of the supported cases are usable, the 
* filter will be disabled.
*/
#define PIFilterCaseInfoProperty 0x66696369L
	

/********************************************************************************/

/* Error return values. The plug-in module may also return standard Macintosh
   operating system error codes, or report its own errors, in which case it
   can return any positive integer. */
///@name Error Return Values 
//@{
/** @ingroup FilterModule 
* @{
*/
#define filterBadParameters -30100	/**< The filter module had a problem with the filter module interface. */
#define filterBadMode		-30101	/**< The filter module does not support \<mode\> images. */
/* @} */
//@}

#ifndef RC_INVOKED

/********************************************************************************/
/* Packing for Microsoft compiler */
#if WIN32
#pragma pack(push,1)
#endif

/********************************************************************************/

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/********************************************************************************/

/** Data for the filter case information property 'fici' @ref PIFilterCaseInfoProperty. */
typedef struct FilterCaseInfo
	{
	char inputHandling;		/**< Preprocessing actions on the image data. See @ref FilterCaseInfoHandlingModes "FilterCaseInfo handling modes." */
	char outputHandling;	/**< Postprocessing actions on the image data. See @ref FilterCaseInfoHandlingModes "FilterCaseInfo handling modes."*/
	char flags1;			/**< Flags for how the filter case information should be treated.  
						         See @ref FilterCaseInfoFlag1Bits "filter case information flag bits". */
	char flags2;			/**< Reserved. Should be 0 */
	}
FilterCaseInfo;

#if WIN32
#pragma pack(pop)
#endif

/*********************************************************************************/

/** Background or foreground color, in the color space native to the image. */
typedef unsigned char FilterColor [4];

#if WIN32
#pragma warning(push)
#pragma warning(disable: 4121)
#pragma pack(push,4)
#endif


/********************************************************************************/


/** Allows editing of documents beyond the 30,000 by 30,000 pixel limit	mandated 
* in earlier versions, a feature added in Photoshop CS (8.0).  
* \c BigDocumentStruct was added to the @ref FilterRecord to support this new feature.
* This structure deprecates  \c imageSize, \c filterRect, \c inRect, \c outRect,  \c maskRect, 
* \c floatCoord, and \c wholeSize.
*/
typedef struct BigDocumentStruct 
	{
	
	int32		PluginUsing32BitCoordinates;	/**< Set to nonzero by the plug-in if it is
													using the 32 bit fields. */
	
	VPoint		imageSize32;					/**< Size of image in 32 bit coordinates. 
													Replaces \c FilterRecord::imageSize. */
	
	VRect		filterRect32;					/**< Rectangle to filter in 32 bit coordinates. 
													Replaces \c FilterRecord::filterRect. */
													
	VRect		inRect32;						/**< Requested input rectangle in 32 bit coordinates. 
													Replaces \c FilterRecord::inRect. */
	
	VRect		outRect32;						/**< Requested output rectangle in 32 bit coordinates. 
													Replaces \c FilterRecord::outRect. */
	
	VRect		maskRect32;						/**< Requested mask rectangle in 32 bit coordinates. 
													Replaces \c FilterRecord::maskRect. */
	
	VPoint		floatCoord32;					/**< Top left coordinate of selection in 32 bit coordinates. 
													Replaces \c FilterRecord::floatCoord. */
	
	VPoint		wholeSize32;					/**< Size of image the selection is over in 32 bit coordinates. 
													Replaces \c FilterRecord::wholeSize. */
	
	} BigDocumentStruct;

/********************************************************************************/

/** @ingroup FilterModule 
*/
/** This structure is passed to the plug-in module through the parameter block.
* See @ref PGPluginEntryPoint "Plug-in Entry Point" for an explanation of how the 
* host calls a plug-in.
*/
typedef struct FilterRecord 
	{

	int32		serialNumber;		/**< \deprecated Formerly the host serial number.
									   The host now reports
									   zero for the \c serialNumber. Plug-ins should use 
									   the @ref PropertySuite by using the @ref FilterRecord::propertyProcs callback, specifying 
									   the property \c propSerialString2 to get the serial string. */

	TestAbortProc	abortProc;		/**< A pointer to the \c TestAbortProc callback. */

	ProgressProc	progressProc;	/**< A pointer the the \c ProgressProc callback. */

	Handle		parameters; 		/**< Parameters the plug-in can request from a user.
									     Photoshop initializes this handle to NULL at startup. 
							  			 If the plug-in filter has any parameters that the user can 
							  			 set, it should allocate a relocatable block in the 
							  			 \c filterSelectorParameters handler, store the parameters 
							  			 in the block, and store the block’s handle in this field. */

	Point		imageSize;			/**< \deprecated Use \c BigDocumentStruct::imageSize32. The width and height
										 of the image in pixels. If the selection is floating, this field instead 
										 holds the size of the floating selection.  */
	int16		planes; 			/**< The number of planes in the image. For version 4+ filters, this 
	                                     field contains the total number 
										 of active planes in the image, including alpha channels. The 
						   				 image mode should be determined by looking at \c imageMode. 
						   				 For version 0-3 filters, this field is equal to 3 if 
						   				 filtering the RGB channel of an RGB color image, or 4 if 
						   				 filtering the CMYK channel of a CMYK color image. 
						   				 Otherwise it is equal to 1. */
	Rect		filterRect; 		/**< \deprecated Use \c BigDocumentStruct::filterRect32.
										 The area of the image to be filtered. This is the bounding 
	                                     box of the selection, or if there is no selection, the 
	                                     bounding box of the image. If the selection is not a perfect 
	                                     rectangle, Photoshop automatically masks the changes to the
	                                     area actually selected (unless the plug-in turns off this 
	                                     feature using autoMask). This allows most filters to ignore 
	                                     the selection mask, and still operate correctly. */
	PSRGBColor	background; 		/**< \deprecated Use @ref FilterRecord::backColor. */
	PSRGBColor	foreground; 		/**< \deprecated Use @ref FilterRecord::foreColor. */
	int32		maxSpace;			/**< \deprecated Use @ref FilterRecord::maxSpace64. */
	int32		bufferSpace;		/**< \deprecated Use @ref FilterRecord::bufferSpace64. */
	Rect		inRect; 			/**< \deprecated Use \c BigDocumentStruct::inRect32. 
	                                     The area of the input image to access. The plug-in should set 
										 this field in the \c filterSelectorStart and 
	                                     \c filterSelectorContinue handlers to request access to an 
	                                     area of the input image. The area requested must be a subset 
	                                     of the image’s bounding rectangle. After the entire 
	                                     \c filterRect has been filtered, this field should be set to 
	                                     an empty rectangle.  */
	int16		inLoPlane;			/**< The first input plane to process next. The \c filterSelectorStart and 
										 \c filterSelectorContinue handlers should set this field. */
	int16		inHiPlane;			/**< The last input plane to process next. The \c filterSelectorStart and 
	                                     \c filterSelectorContinue handlers should set this field.  */
	Rect		outRect;			/**< \deprecated Use \c BigDocumentStruct::outRect32.
	                                     The area of the output image to access. The plug-in should set 
	                                     this field in its \c filterSelectorStart and \c filterSelectorContinue 
	                                     handlers to request access to an area of the output image. 
	                                     The area requested must be a subset of \c filterRect. After 
	                                     the entire \c filterRect has been filtered, this field 
	                                     should be set to an empty rectangle.  */
	int16		outLoPlane; 		/**< The first output plane to process next. The \c filterSelectorStart 
	                                     and \c filterSelectorContinue handlers should set this field.  */
	int16		outHiPlane; 		/**< The last output plane to process next. The \c filterSelectorStart and 
	                                     \c filterSelectorContinue handlers should set this field. */

	void *		inData; 			/**< A pointer to the requested input image data. If more than 
	                                     one plane has been requested (see \c inLoPlane and \c inHiPlane), the 
	                                     data is interleaved. */
	int32		inRowBytes; 		/**< The offset between rows of the input image data. 
										 The end of each row may or may not include pad bytes. */
	void *		outData;			/**< A pointer to the requested output image 
	                                     data. If more than one plane has been requested 
	                                     (see \c outLoPlane and \c outHiPlane), the data is interleaved. */
	int32		outRowBytes;		/**< The offset between rows of the output image data. 
	                                     The end of each row may or may not include pad bytes. */

	Boolean 	isFloating; 		/**< Indicates if the selection is floating. Set to TRUE if and only if 
	                                     the selection is floating. */
	Boolean 	haveMask;			/**< Indicates if the selection has a mask. Set to true if and only if  
	                                     non-rectangular area has been selected. */
	Boolean 	autoMask;			/**< Enables or disables auto-masking. By default, Photoshop 
	                                     automatically masks any changes to the area actually selected.
	                                     If \c isFloating=FALSE, and \c haveMask=TRUE, the plug-in can 
	                                     turn off this feature by setting this field to FALSE. It can 
	                                     then perform its own masking. <br><br>
										 If the plug-in has set the PiPL bit \c writesOutsideSelection, this 
										 will always be FALSE and the plug-in must supply its own mask, if 
										 needed. */

	Rect		maskRect;			/**< \deprecated Use \c BigDocumentStruct::maskRect32.
	                                     Provides a mask rectangle. If \c haveMask=TRUE, and the 
	                                     plug-in needs access to the selection mask, the plug-in
	                                     should set this field in your \c filterSelectorStart and 
	                                     \c filterSelectorContinue handlers to request access to an 
	                                     area of the selection mask. The requested area must be a 
	                                     subset of \c filterRect. This field is ignored if there is 
	                                     no selection mask.  */
	void *		maskData;			/**< A pointer to the requested mask data. The data is in the 
	                                     form of an array of bytes, one byte per pixel of the selected 
	                                     area. The bytes range from (0...255), where 0=no mask 
	                                     (selected) and 255=masked (not selected). 
	                                     Use \c maskRowBytes to iterate over the scan lines of the 
	                                     mask. */
	int32		maskRowBytes;		/**< The offset between rows of the mask data. */

	FilterColor backColor;			/**< The current background color, in the 
	                                     color space native to the image.*/
	FilterColor foreColor;			/**< The current foreground color, in the 
	                                     color space native to the image.*/
	OSType		hostSig;			/**< The signature of the host, provided by the host.
	                                     The signature for Photoshop is signature is 8BIM. */
	HostProc	hostProc;			/**< A pointer to a host-defined callback procedure. May be NULL. */

	int16		imageMode;			/**< The mode of the image being filtered, for example, Gray Scale, RGB Color, 
	                                     and so forth. See @ref ImageModes "Image Modes" for values. The \c filterSelectorStart 
	                                     handler should return \c filterBadMode if it is unable to 
	                                     process this mode of image. */
	Fixed		imageHRes;			/**< The  horizontal resolution of the image in terms of 
	                                     pixels per inch. These are fixed point numbers (16.16). */
	Fixed		imageVRes;			/**< The vertical resolution of the image in terms of 
	                                     pixels per inch. These are fixed point numbers (16.16). */
	Point		floatCoord; 		/**< \deprecated Use \c BigDocumentStruct::floatCoord32.
	                                     The coordinate of the top-left corner of the selection 
	                                     in the main image’s coordinate space. */
	Point		wholeSize;			/**< \deprecated Use \c BigDocumentStruct::wholeSize32.
	                                     The size in pixels of the entire main image. 
										 */
	PlugInMonitor	monitor;		/**< Monitor setup information for the host. */

	void 		*platformData;		/**< A pointer to platform specific data. 
	                                     Not used under Mac OS. See PlatformData in PITypes.h. */
	BufferProcs *bufferProcs;		/**< A pointer to the Buffer suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See @ref BufferSuite. */
	ResourceProcs *resourceProcs;	/**< A pointer to the Pseudo-Resource suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See chapter @ref ResourceSuite. */
	ProcessEventProc processEvent;	/**< A pointer to the \c ProcessEventProc callback 
	                                     if it is supported by the host, otherwise NULL. */
	DisplayPixelsProc displayPixels;/**< A pointer to the \c DisplayPixelsProc callback 
	                                     if it is supported by the host, otherwise NULL.  */
	HandleProcs	*handleProcs;		/**< A pointer to the Handle callback suite 
	                                     if it is supported by the host, otherwise NULL.  
	                                     See @ref HandleSuite. */

	///@name New in 3.0. 
	//@{
	Boolean		supportsDummyChannels;	/**< Indicates whether the host supports the plug-in 
	                                         requesting nonexistent planes. (See 
	                                         @ref dummyPlaneValue, @ref inPreDummyPlanes, 
	                                         @ref inPostDummyPlanes, @ref outPreDummyPlanes, 
	                                         @ref outPostDummyPlanes.) */
	Boolean 	supportsAlternateLayouts;	/**< Indicates whether the host support data layouts 
	                                             other than rows of columns of planes. This field 
	                                             is set by the plug-in host to indicate whether 
	                                             it respects the \c wantLayout field. */
	int16		wantLayout;			/**< The desired layout for the data. 
	                                     The plug-in host only looks at this field if it has also set 
	                                     \c supportsAlternateLayouts. See @ref LayoutConstants "Layout Constants"
										 for values. */
	int16		filterCase;			/**< The type of data being filtered. Flat, floating, layer 
	                                     with editable transparency, layer with preserved transparency, 
	                                     with and without a selection. A zero indicates that the host 
	                                     did not set this field, and the plug-in should look at 
	                                     \c haveMask and \c isFloating. See @ref FilterCaseIdentifiers for values. */
	int16		dummyPlaneValue;	/**< The value to store into any dummy planes. Values from 0 to 
	                                     255 indicates a specific value. A value of -1 indicates 
	                                     to leave undefined. All other values generate an error. */
	
	void *		premiereHook;		/**< \deprecated */
									   
	AdvanceStateProc advanceState;	/**< \c AdvanceState callback. */
									   
	Boolean		supportsAbsolute;	/**< Indicates whether the host supports absolute channel 
	                                     indexing. Absolute channel indexing ignores visibility 
	                                     concerns and numbers the channels from zero starting with 
	                                     the first composite channel. If existing, transparency 
	                                     follows, followed by any layer masks, then alpha channels. */
									   
	Boolean		wantsAbsolute;		/**< Enables absolute channel indexing for the input. This is 
									     only useful if supportsAbsolute=TRUE. Absolute indexing 
									     is useful for things like accessing alpha channels.  */
	GetPropertyProc	getPropertyObsolete;	/**< The \c GetProperty callback. This direct callback 
											     pointer has been superceded by the Property callback 
											     suite, but is maintained here for backwards compatibility. 
											     See @ref PropertySuite. */
	Boolean		cannotUndo;			/**< Indicates whether a filter plug-in makes changes that the user cannot undo.
	                                     If the filter makes a change that cannot be undone, then setting 
										 this field to TRUE prevents Photoshop from offering undo 
										 for the filter. This is rarely needed and usually frustrates 
										 users.	 */
	Boolean		supportsPadding;	/**< Indicates whether the host supports requests outside the image 
	                                     area. If so, see padding fields below. */
	
	int16		inputPadding;		/**< Instructions for padding the input. 
										 The input can be padded when loaded. See @ref FilterPadding 
										 "Filter Padding Constants." \n\n
										 The options for padding include specifying a specific value 
										 (0...255), specifying \c plugInWantsEdgeReplication, specifying 
										 that the data be left random (\c plugInDoesNotWantPadding), or 
										 requesting that an error be signaled for an out of bounds 
										 request (\c plugInWantsErrorOnBoundsException). Default value: 
										 \c plugInWantsErrorOnBoundsException. */
	int16		outputPadding;		/**< Instructions for padding the output. 
	                                     The output can be padded when loaded. See @ref FilterPadding 
	                                     "Filter Padding Constants." \n\n
										 The options for padding include specifying a specific value 
										 (0...255), specifying \c plugInWantsEdgeReplication, specifying 
										 that the data be left random (\c plugInDoesNotWantPadding), or 
										 requesting that an error be signaled for an out of bounds 
										 request (\c plugInWantsErrorOnBoundsException). Default value: 
										 \c plugInWantsErrorOnBoundsException. */
	int16		maskPadding;		/**< Padding instructions for the mask. 
	                                     The mask can be padded when loaded. See @ref FilterPadding 
	                                     "Filter Padding Constants." \n\n
										 The options for padding include specifying a specific value 
										 (0...255), specifying \c plugInWantsEdgeReplication, specifying 
										 that the data be left random (\c plugInDoesNotWantPadding), or 
										 requesting that an error be signaled for an out of bounds 
										 request (\c plugInWantsErrorOnBoundsException). Default value: 
										 \c plugInWantsErrorOnBoundsException. */
	char	 	samplingSupport;	/**< Indicates whether the host support non- 1:1 sampling 
	                                     of the input and mask. Photoshop 3.0.1+ supports 
	                                     integral sampling steps (it will round up to get there). 
	                                     This is indicated by the value #hostSupportsIntegralSampling. 
	                                     Future versions may support non-integral sampling steps. 
	                                     This will be indicated with #hostSupportsFractionalSampling. */
	char		reservedByte;		/**< For alignment. */
	
	Fixed		inputRate;			/**< The sampling rate for the input. The effective input 
	                                     rectangle in normal sampling coordinates is 
	                                     <code> inRect * inputRate. </code> For example, 
	                                     <code> (inRect.top * inputRate, 
	                                     inRect.left * inputRate, inRect.bottom * inputRate, 
	                                     inRect.right * inputRate). </code> The value for
	                                     \c inputRate is rounded to the 
	                                     nearest integer in Photoshop 3.0.1+. Since the scaled 
	                                     rectangle may exceed the real source data, it is a good 
	                                     idea to set some sort of padding for the input as well. */
	Fixed		maskRate;			/**< Like \c inputRate, but as applied to the mask data. */

	ColorServicesProc colorServices; /**< Function pointer to access color services routine. */
	
	/* Photoshop structures its data as follows for plug-ins when processing
	   layer data:
			target layer channels
			transparency mask for target layer
			layer mask channels for target layer
			inverted layer mask channels for target layer
			non-layer channels
		When processing non-layer data (including running a filter on the
		layer mask alone), Photoshop structures the data as consisting only
		of non-layer channels.  It indicates this structure through a series
		of short counts.  The transparency count must be either 0 or 1. */
		
	int16		inLayerPlanes;		  /**< The number of target layer planes for the input data.  
	                                       If all the input plane values are zero, 
	                                       then the plug-in should assume the host has not set them.
	                                       <br><br>
	                                       @note When processing layer data, Photoshop structures 
	                                       its input and output data for plug-ins as follows:
	                                       - target layer channels
	                                       - transparency mask for target layer
	                                       - layer mask channels for target layer
	                                       - inverted layer mask channels for target layer
	                                       - non-layer channels	

	                                       The output planes are a prefix of the input planes. 
	                                       For example, in the protected transparency case, the input 
	                                       can contain a transparency mask and a layer mask while the 
	                                       output can contain just the layerPlanes.
										   <br><br>
										   When processing non-layer data (including running a filter 
										   on the layer mask alone), Photoshop structures the data 
										   as consisting only of non-layer channels.  It indicates 
										   this structure through a series of short counts.  The 
										   transparency count must be either 0 or 1.  
										   */
	int16		inTransparencyMask;	  /**< The number of transparency masks for the input target 
	                                       layer data.  
	                                       See @ref inLayerPlanes for additional information. */
	int16		inLayerMasks;		  /**< The number of layer mask channels for the input 
	                                       target layer.  
	                                       See @ref inLayerPlanes for additional information.*/
	int16		inInvertedLayerMasks; /**< The number of inverted layer mask channels for the 
	                                       input target layer. <br> 
	                                       With the inverted layer masks, 0 = fully visible 
	                                       and 255 = completely hidden.  See @ref inLayerPlanes for 
	                                       additional information.*/
	int16		inNonLayerPlanes;	  /**< The number of non-layer channels for the input data.  
	                                       See @ref inLayerPlanes for additional information. */
			
	int16		outLayerPlanes;		  /**< The number of target layer planes for the output data.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the output data. */
	int16		outTransparencyMask;  /**< The number of transparency masks for the output data.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the output data. */
	int16		outLayerMasks;		  /**< The number of layer mask channels for the output data.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the output data. */
	int16		outInvertedLayerMasks; /**< The number of inverted layer mask channels for the output data.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the output data. */
	int16		outNonLayerPlanes;	   /**< The number of non-layer channels for the output data.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the output data. */
			
	int16		absLayerPlanes;		  /**< The number of target layer planes for the input data,
										   used for the structure of the input data when
										   \c wantsAbsolute is TRUE.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the input data. */
	int16		absTransparencyMask;  /**< The number of transparency masks for the input data,
										   used for the structure of the input data when
										   \c wantsAbsolute is TRUE.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the input data. */
	int16		absLayerMasks;		 /**< The number of layer mask channels for the input data,
										   used for the structure of the input data when
										   \c wantsAbsolute is TRUE.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the input data. */
	int16		absInvertedLayerMasks; /**< The number of inverted layer mask channels for the input 
										   data, used for the structure of the input data when
										   \c wantsAbsolute is TRUE.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the input data. */
	int16		absNonLayerPlanes;	 /**< The number of target layer planes for the input data,
										   used for the structure of the input data when
										   \c wantsAbsolute is TRUE.
										   See @ref inLayerPlanes for additional information about 
										   the structure of the input data. */
	
	/* We allow for extra planes in the input and the output.  These planes
	   will be filled with dummyPlaneValue at those times when we build the
	   buffers.  These features will only be available if supportsDummyPlanes
	   is TRUE. */
	
	int16		inPreDummyPlanes;	/**< The number of extra planes before  
									     the input data. Only available if 
									     \c supportsDummyChannels=TRUE. Used for 
									     things like forcing RGB data to appear as RGBA.  */
	int16		inPostDummyPlanes;	/**< The number of extra planes after 
									     the input data. Only available if 
									     \c supportsDummyChannels=TRUE. Used for 
									     things like forcing RGB data to appear as RGBA.  */
	
	int16		outPreDummyPlanes;	/**< The number of extra planes before  
									     the output data. Only available if 
									     \c supportsDummyChannels=TRUE. */
	int16		outPostDummyPlanes;	/**< The number of extra planes after  
									     the output data. Only available if 
									     \c supportsDummyChannels=TRUE. */
	
	/* If the plug-in makes use of the layout options, then the following
	   fields should be obeyed for identifying the steps between components.
	   The last component in the list will always have a step of one. */
	
	int32		inColumnBytes;		/**< The step from column to column in the input. 
										 If using the layout options, this value may change 
										 from being equal to the number of planes. If zero, 
										 assume the host has not set it. */
	int32		inPlaneBytes;		/**< The step from plane to plane in the input. Normally 1, 
										 but this changes if the plug-in uses the layout options. 
										 If zero, assume the host has not set it. */
			
	int32		outColumnBytes;		/**< The output equivalent of @ref inColumnBytes. */
	int32		outPlaneBytes;		/**< The output equivalent of @ref inPlaneBytes. */
	//@}
	///@name New in 3.0.4 
	//@{
	ImageServicesProcs *imageServicesProcs;
									/**< Image Services callback suite. */
			
	PropertyProcs	*propertyProcs;	/**< Property callback suite.  The plug-in needs to
									     dispose of the handle returned for	complex properties (the 
									     plug-in also maintains ownership of handles for
										 set properties. */
			
	int16		inTileHeight;		/**< Tiling height for the input, set by host. Zero if not set. 
	                                     The plug-in should work at this size, if possible. */
	int16		inTileWidth;		/**< Tiling width for the input, set by host. Zero if not set. 
	                                     Best to work at this size, if possible. */
	Point		inTileOrigin;		/**< Tiling origin for the input, set by host. Zero if not set. */
	
	int16		absTileHeight;		/**< Tiling height the absolute data, set by host. 
	                                     The plug-in should work at this size, if possible.*/
	int16		absTileWidth;		/**< Tiling width the absolute data, set by host. 
	                                     The plug-in should work at this size, if possible.*/
	Point		absTileOrigin;		/**< Tiling origin the absolute data, set by host. */
	
	int16		outTileHeight;	    /**< Tiling height for the output, set by host. 
	                                     The plug-in should work at this size, if possible. */
	int16		outTileWidth;	    /**< Tiling width for the output, set by host. 
	                                     The plug-in should work at this size, if possible. */
	Point		outTileOrigin;	    /**< Tiling origin for the output, set by host.  */
	
	int16		maskTileHeight;		/**< Tiling height for the mask, set by host. 
	                                     The plug-in should work at this size, if possible. */
	int16		maskTileWidth;		/**< Tiling width for the mask, set by host. 
	                                     The plug-in should work at this size, if possible. */
	Point		maskTileOrigin;		/**< Tiling origin for the mask, set by host. */
	//@}
	///@name New in 4.0 
	//@{
	PIDescriptorParameters	*descriptorParameters;	/**< Descriptor callback suite.  */
	Str255					*errorString;	/**< An error reporting string to return to Photoshop.
	                                             If the plug-in returns with result=errReportString then 
	                                             this string is displayed as: 
	                                             "Cannot complete operation because " + \c errorString. */
			
	ChannelPortProcs *channelPortProcs;
									/**< Channel Ports callback suite. */
			
	ReadImageDocumentDesc *documentInfo;	/**< The Channel Ports document information
												 for the document being filtered. */
	//@}
	///@name New in 5.0 
	//@{
	SPBasicSuite	*sSPBasic;		/**< PICA basic suite.  Provides the mechanism to access all PICA suites. */
	void			*plugInRef;		/**< Plug-in reference used by PICA. */
	
	int32			depth;			/**< Bit depth per channel (1,8,16,32). */
	//@}
	///@name New in 6.0 
	//@{
	Handle			iCCprofileData;	/**< Handle containing the ICC profile for the image. (NULL if none)
										Photoshop allocates the handle using its handle suite
										The handle is unlocked while calling the plug-in.
										The handle is valid from  \c FilterSelectorStart to \c FilterSelectorFinish
										Photoshop will free the handle after \c FilterSelectorFinish. */
	
	int32			iCCprofileSize;		/**< Size of profile. */
	
	int32			canUseICCProfiles;	/**< Indicates if the host uses ICC Profiles. Non-zero if the host can 
	                                         accept or export ICC profiles .
											 If this is zero, don't set or dereference \c iCCprofileData.
										*/
		
	//@}
	///@name New in 7.0 
	//@{
	int32			hasImageScrap;		/**< Indicates if Photoshop has image scrap; non-zero if it does. 
	                                         The plug-in can ask for the 
	                                         exporting of image scrap by setting the PiPL resource, 
	                                         @ref PIWantsScrapProperty. The document info for the image scrap is 
	                                         chained right behind the targeted document pointed by the 
	                                         @ref documentInfo field. Photoshop sets \c hasImageScrap to indicate 
	                                         that an image scrap is available. A plug-in can use it to tell whether 
	                                         Photoshop failed to export the scrap because some unknown 
	                                         reasons or there is no scrap at all. */
	//@}
	///@name New in 8.0 
	//@{
	BigDocumentStruct	*bigDocumentData;	/**< Support for documents larger than 30,000 pixels. 
												NULL if host does not support big documents.*/

	
	//@}
	///@name New in 10.0 
	//@{
	PIDescriptorParameters	*input3DScene;	/**< support for 3d scene data to be sent into the plug-in */

	PIDescriptorParameters	*output3DScene;	/**< support for 3d scene to come out of the plug-in */
	
	Boolean					createNewLayer; /**< set by plug-in this only works for 3D layers */

	//@}
	///@name New in 13.0 
	//@{
	Handle			iCCWorkingProfileData;	/**< Handle containing the ICC profile for the working
											profile set via color settings dialog. (NULL if none)
											Photoshop allocates the handle using its handle suite
											The handle is unlocked while calling the plug-in.
											The handle is valid from  \c FilterSelectorStart to \c FilterSelectorFinish
											Photoshop will free the handle after \c FilterSelectorFinish. */
	
	int32			iCCWorkingProfileSize;	/**< Size of working profile. */

	//@}
	///@name New in 18.0 
	//@{
	int64			bufferSpace64;          /**< Allows the plug-in to specify how much buffer space it needs.
											If the plug-in is planning on allocating any large internal
											buffers or tables, it should set this field during the
											\c filterSelectorPrepare call to the number of bytes it
											plans to allocate.Photoshop then tries to free up the
											requested amount of space before calling the
											\c filterSelectorStart routine.Relocatable blocks should
											be used if possible. */

	int64			maxSpace64;				/**< The maximum number of bytes of information the plug-in can 
											expect to be able to access at once (input area size + output area 
											size + mask area size + bufferSpace). Set by Photoshop. */

	//@}
	///@name Reserved Space for Expansion
	//@{
	char		reserved [46]; 	/**< Reserved for future use. Set to zero. */
	//@}

	}
FilterRecord, *FilterRecordPtr;

#if WIN32
#pragma pack(pop)
#pragma warning(pop)
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

/*********************************************************************************/

// ifdef RC_INVOKED
#endif

#endif	// __PIFilter_h__
