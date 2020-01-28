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
 *	\file PIExport.h
 *
 *	\brief This file describes Photoshop's Export plug-in module interface
 *
 *	Distribution:
 *		PUBLIC
 *
 */		

/** @defgroup ExportModule Export Module
* Export plug-in modules are used to output an image from an open Photoshop document.  
* Export modules can be used to print to printers that do not have Mac OS 
* Chooser-level driver support.	\n\n
* They can also be used to save images in unsupported or compressed file formats, 
* although File Format modules often are better suited for this purpose. File Format 
* modules are accessed directly from the \b Save and \b Save \b As commands, whereas 
* Export modules use the \b Export sub-menu. <br><br>
* The file type for export modules for Mac OS is 8BEM, the extension for Windows is .8BE.  \n\n
* Please also see @ref PGExportModule "Writing Export Plug-ins".
*/


#ifndef __PIExport__
#define __PIExport__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"

/* Operation selectors */
///@name Export Module Selectors 
//@{

/** @ingroup ExportModule 
* @{
*/
/**  Allows the plug-in to display an about box for the Export Module. For this
* selector, the host does not pass the standard parameter block into the plug-in 
* main routine.  Instead it passes an \c AboutRecord. 
*
* See @ref PGAboutBoxes	"About Boxes" for more information.
*/
#define exportSelectorAbout    0

/**  
* Allows the plug-in to open a dialog box and set up the initial image rectangle
* to process. 
* During this call, the plug-in module should set \c theRect or \c ExportRecord::theRect32, 
* \c loPlane and \c hiPlane to let Photoshop know what area of the image it wishes to process.
* The total number of bytes requested should be less than \c maxData. If the image is larger 
* than \c maxData, the plug-in must process the image in pieces. 
* There are no restrictions on how the pieces tile the image: horizontal strips, 
* vertical strips, or a grid of tiles. 	\n\n
* The plug-in can call \c AdvanceStateProc during \c exportSelectorStart.  See 
* @ref PGExportAdvanceState "Advance State and Export Modules" for more information.
*/
#define exportSelectorStart    1

/** 
* Allows the plug-in module to process the image data pointed to 
* by \c data, and then indicate what area of the image it will process next.
* To indicate the next area of the image to process, adjust \c ExportRecord::theRect or \c ExportRecord::theRect32, 
* \c loPlane and \c hiPlane. If the entire image has been processed, set \c ExportRecord::theRect or 
* \c ExportRecord::theRect32 to an empty rectangle. \n\n
* The requested image data is pointed to by \c data. If more than one plane has been 
* requested (see \c loPlane and \c hiPlane), the data is interleaved. The offset from one row to the 
* next is indicated by \c rowBytes. This is not necessarily equal to the width of \c theRect or 
* \c ExportRecord::theRect32; there may be additional pad bytes at the end of each row.  \n\n
* The plug-in can call \c AdvanceStateProc during \c exportSelectorContinue.  See 
* @ref PGExportAdvanceState "Advance State and Export Modules" for more information.
* @note Be careful processing user-cancel events during \c exportSelectorContinue. 
* Normally your plug-in would be expecting another \c exportSelectorContinue call. 
* If the user cancels, the next call is \c exportSelectorFinish, not \c exportSelectorContinue!
*/
#define exportSelectorContinue 2

/** 
* Allows the plug-in module to clean up after an image export. 
* This call is made if and only if the \c exportSelectorStart routine returns without error, 
* even if the \c exportSelectorContinue routine returns an error. If \c exportSelectorStart
* succeeds, Photoshop guarantees that \c exportSelectorFinish is called. \n\n
* If Photoshop detects Command-period in the Mac OS or \e Escape in Windows between calls to 
* the \c exportSelectorContinue routine, it calls the \c exportSelectorFinish routine. \n\n
* See @ref PGExportScripting "Export Modules and Scripting" for information about scripting
* at the \c exportSelectorFinish selector.
* @note Photoshop may call \c exportSelectorFinish instead of \c exportSelectorContinue if it detects
* a need to terminate while building the requested buffer. \n\n
*/

#define exportSelectorFinish   3
/** Allows the plug-in module to adjust the Photoshop memory allocation algorithm. 
* Photoshop sets \c maxData to the maximum number of bytes it can allocate to your 
* plug-in. You may want to reduce \c maxData for increased efficiency. 
* See @ref PGMemoryMgmtStrategies "Memory Management Strategies" for more information.
*/
#define exportSelectorPrepare  4

/**
* @}
*/  // end ingroup

//@}



///@name Export Module Error Codes 
//@{

/** @ingroup ExportModule 
* @{
*/

/* Error return values. The plug-in module may also return standard Macintosh
   operating system error codes, or report its own errors, in which case it
   can return any positive integer. */

#define exportBadParameters -30200	/**< Indicates a problem with the export module interface. */
#define exportBadMode		-30201	/**< Indicates that the export module does not support \<mode\> images. */

/**
* @}
*/  // end ingroup

//@}

/******************************************************************************/

///@ingroup PiPLExportKeys
/**
* Indicates that the plug-in can see transparency data; key value is 'expf'. 
* This property key reflects the \c ExportFlags property in the PiPL resource file.
* The value of the property has type \c FlagSet; a variable length bitstring 
* in which the first member is represented by the most significant bit of the 
* first byte, the eighth member is in the least significant bit of the first byte, etc.
* The length of the set is in the property's length field.
* Use @ref PIExpSupportsTransparency to set the transparency flag.
* @note Currenty only the transparency flag is supported.	
*/
#define PIExpFlagsProperty		0x65787066 /* 'expf' <Set> Export flags */

/******************************************************************************/

/* Export flag indices. */

#define PIExpSupportsTransparency 0	  /**< Flag index for @ref PIExpFlagsProperty; 
                                           indicates that the plug-in can see transparency data. */ 

/******************************************************************************/

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/** @ingroup ExportModule 
*/
/** This structure is passed to the Export plug-in module \c main() through the \c pluginParamBlock.
* See @ref PGPluginEntryPoint "Plug-in Entry Point" for an explanation of how the 
* host calls a plug-in.
*/
typedef struct ExportRecord
	{

	int32			serialNumber;	/**< @deprecated  - Formerly the host serial number.
									   The host now reports
									   zero for the \c serialNumber. Plug-ins should use 
									   the @ref PropertySuite through the @ref ExportRecord::propertyProcs callback
									   and specify the property 'propSerialString2' to get the 
									   serial string. */

	TestAbortProc	abortProc;		/**< A pointer to the \c TestAbortProc callback. */

	ProgressProc	progressProc;	/**< A pointer the the \c ProgressProc callback. */

	int32			maxData;		/**< The maximum number of bytes Photoshop can free up for a plug-in
								         to use. You can reduce this 
										 value during in your \c exportSelectorPrepare handler. 
										 The \c exportSelectorContinue handler should process 
										 the image in pieces no larger than \c maxData, less 
										 the size of any large tables or scratch areas it 
										 has allocated. */

	int16			imageMode;		/**< The mode of the image being exported (grayscale, 
									     RGB Color, etc.). See @ref ImageModes "Image Modes" for values. Your 
									     \c exportSelectorStart handler should return an 
									     \c exportBadMode error if it is unable to process this 
									     mode of image. */
	Point			imageSize;		/**< @deprecated Use \c ExportRecord::imageSize32. The width and height
										 of the image in pixels. See @ref ExportRecord::imageSize32 for large document 
										 support. */
	int16			depth;			/**< The resolution of the image in bits per pixel per plane. 
							             The only possible settings are 1, 8, 16, and 32. */ 
	int16			planes; 		/**< The number of channels in the image. For example, if an 
										 RGB image without alpha channels is being processed, 
										 this field is set to 3. */

	Fixed			imageHRes;		/**< The horizontal resolution of the image in terms of pixels 
										 per inch. These are fixed point 16-binary digit numbers. */
	Fixed			imageVRes;		/**< The vertical resolution of the image in terms of pixels 
										 per inch. These are fixed point 16-binary digit numbers. */

	LookUpTable		redLUT; 		/**< The red color table, user only when an indexed color or 
	                                     duotone mode image is being processed. */
	LookUpTable		greenLUT;		/**< The green color table, user only when an indexed color or 
	                                     duotone mode image is being processed. */
	LookUpTable		blueLUT;		/**< The blue color table, user only when an indexed color or 
	                                     duotone mode image is being processed. */

	Rect			theRect;		/**< @deprecated Use \c ExportRecord::theRect32. The \c exportSelectorStart and
										 \c exportSelectorContinue handlers 
										 should set this field to request a piece of the image for 
										 processing. It should be set to an empty rectangle when 
										 complete.  See @ref ExportRecord::theRect32 for large document support. */
	
	int16			loPlane;		/**< The \c exportSelectorStart and \c exportSelectorContinue 
										 handlers should set these fields to the first plane to process 
										 next. */
	int16			hiPlane;		/**< The \c exportSelectorStart and \c exportSelectorContinue 
										 handlers should set these fields to the last plane to process 
										 next. */

	void *			data;			/**< A pointer to the requested image data. If more than one plane 
										 has been requested (see \c loPlane and \c hiPlane), the data is 
										 interleaved. */
	int32			rowBytes;		/**< The offset between rows for the requested image data. */

	Str255 			filename;		/**< The name of the file the image was read from. File-exporting 
										 modules should use this field as the default name for saving. */

	int16			vRefNum;		/**< @deprecated , do not use */

	Boolean 		dirty;			/**< If the plug-in is used to save an image into a file, it should 
										 set this field to TRUE to prompt the user to save any unsaved 
										 changes when the image is eventually closed. If the plug-in module 
										 outputs to a printer or other hardware device, it should 
										 set this to FALSE. This is initialized as TRUE. It does not 
										 reflect whether other unsaved changes have been made. */

	Rect			selectBBox; 	/**< \deprecated , use \c ExportRecord::selectBBox32. The bounding box of the current selection. If there is no
										 current selection, this is an empty rectangle. 
										 See @ref ExportRecord::selectBBox32 below for large document support.	*/

	OSType			hostSig;		/**< The signature of the host, provided by the plug-in host.
	                                     The Photoshop signature is 8BIM.	*/
	HostProc		hostProc;		/**< If not NULL, a pointer to a host-defined callback procedure. */

	Handle			duotoneInfo;	/**< When exporting a duotone mode image, the host allocates a 
										 handle and fills it with the duotone information. The format 
										 of the information is the same as that required by Import 
										 modules, and should be treated as a black box by plug-ins. */

	int16			thePlane;		/**< The currently selected channel; <br> or -1 if a composite 
										 color channel; <br> or -2 if some other combination of channels. */

	PlugInMonitor	monitor;		/**< The monitor setup information for the host.  */

	void *			platformData;	/**< A pointer to platform specific data. Not used under the 
									     Mac OS. See PlatformData in PITypes.h. */

	BufferProcs *	bufferProcs;	/**< Buffer callback suite.  */
	
	ResourceProcs *	resourceProcs;	/**< Pseudo-Resource callback suite. */
	
	ProcessEventProc processEvent;	/**< ProcessEvent callback. */
	
	DisplayPixelsProc displayPixels;/**< DisplayPixels callback. */

	HandleProcs		*handleProcs;	/**< Handle callback suite. */

	///@name New in 3.0
	//@{
	ColorServicesProc colorServices; /**< ColorServices callback suite.  */
	
	GetPropertyProc	getPropertyObsolete; /**< @deprecated  Property suite. This direct callback
											  has been replaced by @ref ExportRecord::propertyProcs, but is 
											  maintained here for backwards compatibility. */
									   
	AdvanceStateProc advanceState;		/**<  Allows the plug-in to drive the interaction through the inner 
											  \c ExportSelectorContinue loop 
	                                          without actually returning from the plug-in. 
										      The \c advanceState callback can be called from either 
										      \c exportSelectorStart or \c exportSelectorContinue. \n\n
										      If it returns an error, then the plug-in generally should treat this as a 
										      continue error and pass it on when it returns. */
	int16			layerPlanes;		  /**< For documents with transparency, contains the number of planes of 
											   data possibly governed by a transparency mask for the current 
											   target layer. */
	int16			transparencyMask;	  /**< For documents with transparency, contains 1 or 0 indicating whether 
											   the data is governed by a transparency mask.  */
	int16			layerMasks;			  /**< For documents with transparency, contains the number of layer masks 
											   (currently 1 or 0) for which 255 = fully opaque. In 
											   Photoshop 3.0.4+, layer masks are not visible to Export 
											   modules (i.e. the value is 0) since they are layer properties 
											   rather than document properties. */
 	int16			invertedLayerMasks;	  /**< For documents with transparency, contains the number of layer masks 
 											   (currently 1 or 0) for which 255 = fully transparent. 
 											   In Photoshop 3.0.4+, layer masks are not visible to 
 											   Export modules (i.e. the value is 0) since they are layer
 											   properties rather than document properties. */
	int16			nonLayerPlanes;		  /**< For documents with transparency, contains the number of planes 
											   of non-layer data, e.g., flat data or alpha channels. The planes are 
											   arranged in that order. Thus, an RGB image with an alpha 
											   channel and a layer mask on the current target layer 
											   would appear as: red, green, blue, transparency, layer 
											   mask, alpha channel. */
									   
	/* Note that the layer mask fields are necessarily zero in 3.0.4 since
	   the export module receives the merged data and the merged data doesn't
	   really have a layer mask associated with it. */
	//@}
	///@name New in 3.0.4
	//@{
	ImageServicesProcs *imageServicesProcs;
										/**< Image Services callback suite. */
	
	int16				tileWidth;		/**< The width of the tiles. The host sets 
											 the width and height of the tiles. This is the best size 
											 for the plug-in to work with, if possible.  If zero, assume the host
											 has not set the value. */

	int16				tileHeight;		/**< The height of the tiles. The host sets 
											 the width and height of the tiles. This is the best size 
											 for the plug-in to work with, if possible. If zero, assume the host
											 has not set the value. */
	
	Point				tileOrigin;		/**< The origin point of the tiling system. */

	PropertyProcs	*propertyProcs;	    /**< Property callback suite.  The plug-in needs to
									         dispose of the handle returned for	complex properties (the 
									         plug-in also maintains ownership of handles for
										    set properties.	*/
	//@}
	///@name New in 4.0 
	//@{
	PIDescriptorParameters	*descriptorParameters;	/**< Descriptor suite. */
	Str255					*errorString;			/**< An error reporting string the plug-in can return to the host.
	                                                     If the plug-in returns with result=errReportString then 
	                                                     the string stored here is be displayed as: 
	                                                     "Cannot complete operation because " + \c errorString */

	ChannelPortProcs *channelPortProcs;	 	/**< Channel Ports callback suite. */
			
	ReadImageDocumentDesc *documentInfo;	/**< The Channel Ports document information
												 for the document being filtered. */
	//@}
	///@name New in 5.0 
	//@{
	SPBasicSuite	*sSPBasic; 		/**< PICA basic suite.  The method by which all PICA suites are accessed. */
	void			*plugInRef;		/**< Plug-in reference used by PICA. */
	
	int32			transparentIndex;	/**< If IndexedColor, and < 256, this is the index of the 
											 transparent color (for GIF).] */
	
	Handle			iCCprofileData;		/**< Handle containing the ICC profile for the image. (NULL if none.)
											Photoshop allocates the handle using the Photoshop handle suite.
											The handle is unlocked while calling the plug-in.
											The handle is valid from  \c ExportSelectorStart to \c ExportSelectorFinish
											Photoshop frees the handle after \c ExportSelectorFinish. */

	int32			iCCprofileSize;		/**< Size of profile. */
	
	int32			canUseICCProfiles;	/**< Non-zero if the host can accept or export ICC profiles .
											If this is zero, the plug-in should not set or dereference
											\c iCCprofileData.
										*/
	//@}
	///@name New in 5.5 
	//@{
	int32			lutCount;			/**< Number of entries in the indexed color table.
										     This should include the transparent index if any. Plug-ins should 
										     pad out the color table with black for backward compatibility. */
	//@{
	///@name New in 8.0 
	//@{
	int32		HostSupports32BitCoordinates;	/**< Set by the host if the host supports 32 bit plug-in API. */
	
	int32		PluginUsing32BitCoordinates;	/**< Set to nonzero by the plug-in if it is
													 using the 32 bit fields. */
	
	VPoint		imageSize32;					/**< Size of image in 32 bit coordinates. 
													 Replaces \c ExportRecord::imageSize */
	
	VRect		theRect32;						/**< Rectangle being returned in 32 bit coordinates. 
													 Replaces \c ExportRecord::theRect */
	
	VRect		selectBBox32;					/**< The bounding box of the current selection
													 returned in 32 bit coordinates. If there is no 
										 			 current selection, this is an empty rectangle.
										 			 Replaces \c ExportRecord::selectBBox. */
	//@}
	/* Reserved Space for Expansion -- decrement when you add stuff */
	
	///@name Reserved Space for Expansion
	//@{
	char			reserved [106]; /**< Reserved for future use. Set to zero */
	//@}

	}
ExportRecord, *ExportRecordPtr;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

/******************************************************************************/

#endif // __PIExport_h__
