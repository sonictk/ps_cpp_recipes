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
 *	\file PISelection.h
 *
 *	\brief This file describes Photoshop's Selection plug-in module interface
 *		interface.
 *
 *	Distribution:
 *		PUBLIC
 *		
 */


/** @defgroup SelectionModule Selection Module  
* Selection modules modify which pixels are chosen in an existing image and
* can return either path or pixel selections. These modules appear under the
* @b Select menu.
*
* The file type for selection  modules for Mac OS is 8BSM, the extension for Windows is .8BS.
*
* Please also see @ref PGSelectionModule "Writing Selection Plug-ins."
*/

#ifndef __PISelection__
#define __PISelection__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"

/********************************************************************************/
///@name Selection Module Selectors 
//@{

/** @ingroup SelectionModule 
* @{
*/

/* Operation selectors */

/** 
* Allows the plug-in to display an about dialog box. For this
* selector, the host does not pass the standard parameter block into the plug-in 
* main routine.  Instead it passes an \c AboutRecord.
*
* See @ref PGAboutBoxes	"About Boxes" for more information.
*/
#define selectionSelectorAbout 	 0
/**
* Allows the plug-in to execute the selection handler.   Unlike most other plug-in modules, 
* a Selection plug-in gets a single call from the host, and it is expected to
* do all the work during that call.  However, it is recommended that it follow this order:
*  -# Prompt for Parameters \n
* If the plug-in has any parameters that the user can set, it should prompt the user 
* and save the values.  For additional information, see
* @ref PGSelectionParameters "Working with Selection Parameters."
*  -# Allocate Memory \n
* Use the buffer and handle suites to allocate any extra memory needed for your 
* computations. Please see @ref PGMemoryMgmtStrategies "Memory Management Strategies".
*  -# Begin the main loop \n
* The host provides the document to read in \c PISelectionParams::documentInfo. Using this
* reference, the plug-in can retrieve the read channels (\c ReadChannelDesc) in the document.
* Since this is a selection plug-in, most likely the plug in needs to read \c documentInfo->selection, 
* which represents the current selection.\n\n
* From this read channel, the plug-in can determine the read port (\c ReadChannelDesc::port)
* associated with the selection.
* The plug-in should use one of the channel ports suites to request an area (or tile) of the
* image to read. \n\n 
* With the @ref PicaChannelPortsSuite use \c PSChannelPortsSuite1::ReadPixelsFromLevel(), or
* \c PSChannelPortsSuite1::ReadScaledPixels(). 
* With the @ref ChannelPortsSuite, use \c ChannelPortProcs::readPixelsProc().
* \n\n
* If at all possible, the plug-in should process the image in pieces (tiles) to minimize memory 
* requirements. Unless there is a lot of startup/shutdown overhead on each call 
* (for example, communicating with an external DSP), tiling the image with rectangles 
* measuring 64x64 to 128x128 seems to work fairly well.
*  -# Modify, write the results, continue until done \n
* Make your adjustments to the image, and write out the pixel data into 
* \c PISelectionParams::newSelection using one of the channel ports suites.  This member
* points to a \c WriteChannelDesc, in which the host provides the write port to write to, in
* \c WriteChannelDesc::port.
* \n\n With the @ref PicaChannelPortsSuite, use \c PSChannelPortsSuite1::WritePixelsToBaseLevel().	 
* With the @ref ChannelPortsSuite, use \c ChannelPortProcs::WriteBasePixelsProc().  
* The plug-in should continue looping until it has implemented the entire selection or path.
*  -# Clean up\n
* Clean up after the operation. Dispose any handles created, etc. \n\n
* For additional information about using selection selectors, 
* see @ref PGSelectionModule "Writing Selection Plug-ins". 
*/
#define selectionSelectorExecute 1

/** @} */
//@}
/********************************************************************************/

/* Error return values. The plug-in module may also return standard Macintosh
   operating system error codes, or report its own errors, in which case it
   can return any positive integer. */

///@name Selection Error Return Values
//@{
/** @ingroup SelectionModule
* @{ 
*/
#define selectionBadParameters -30700	/**< A problem with the selection module interface. */
#define selectionBadMode	   -30701	/**< The selection module does not support \<mode\> images. */
/** @} */
//@}
/********************************************************************************/

/** @ingroup SelectionModule */
/** This structure is passed to the plug-in module through the parameter block.
* See @ref PGPluginEntryPoint "Plug-in Entry Point" for an explanation of how the 
* host calls a plug-in.
*/
typedef struct PISelectionParams
	{
	
	/* We start with the fields that are common to pretty much all of the plug-ins. */
	
	int32		serialNumber;		/**< \deprecated Formerly the host serial number.
									   	 The host now reports
									     zero for the \c serialNumber. Plug-ins should use 
									     the @ref PropertySuite through the @ref PISelectionParams::propertyProcs field
									     and specify \c propSerialString2
									     to get the serial string. */

	TestAbortProc	abortProc;		/**< A pointer to the \c TestAbortProc callback. */

	ProgressProc	progressProc;	/**< A pointer the the \c ProgressProc callback. */


	OSType		hostSig;			/**< The signature of the host, provided by the host.
	                                     The signature for Photoshop is signature is 8BIM. */
	HostProc	hostProc;		   /**< A pointer to a host-defined callback procedure. 
									     May be NULL. */

	BufferProcs *bufferProcs;		/**< A pointer to the Buffer suite 
	                                     if it is supported by the  host, otherwise NULL. 
	                                     See @ref BufferSuite. */

	ResourceProcs *resourceProcs;	/**< A pointer to the Pseudo-Resource suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See @ref ResourceSuite. */
	                                     	
	ProcessEventProc processEvent;	/**< A pointer to the \c ProcessEventProc callback 
	                                     if it is supported by the host, otherwise NULL. */
	
	DisplayPixelsProc displayPixels;/**< A pointer to the \c DisplayPixelsProc callback 
	                                     if it is supported by the host, otherwise NULL.  */

	HandleProcs	*handleProcs;		/**< A pointer to the Handle callback suite 
	                                     if it is supported by the host, otherwise NULL.  
	                                     See @ref HandleSuite. */

	ColorServicesProc colorServices; /**< A pointer to the ColorServices callback 
	                                     if it is supported by the host, otherwise NULL. */
	
	ImageServicesProcs *imageServicesProcs;
									/**< Suite of image processing callbacks. */
												
	PropertyProcs	*propertyProcs;	/**< Property callback suite. The plug-in needs to
									     dispose of the handle returned for	complex properties. The 
									     plug-in also maintains ownership of handles for
										 set properties. */
									
	ChannelPortProcs *channelPortProcs;
									/**< Suite for passing pixels through channel ports. */
			
	PIDescriptorParameters	*descriptorParameters;	/**< Descriptor callback suite.  */
	Str255					*errorString;			/**< An error reporting string to return to Photoshop.
	                                                 If the plug-in returns with result=errReportString then 
	                                                 this string is displayed as: 
	                                                 "Cannot complete operation because " + \c errorString. */
	
	PlugInMonitor	monitor;		/**< Monitor setup information for the host. */

	void 		*platformData;		/**< A pointer to platform specific data. 
	                                     Not used under Mac OS. See PlatformData in PITypes.h. */

	char reserved [4];				/**< Reserved for future use. Set to zero. */
	
	/* We follow this with the fields specific to this type of plug-in. */
	
	ReadImageDocumentDesc *documentInfo;	/**< The document for the selection. This provides 
												 a collection of read channels, each with its own port. */
	
	WriteChannelDesc *newSelection;			/**< Output for the new selection, unless @ref newPath is
										         not NULL. The host provides the write port
										         in \c WriteChannelDesc::port */
	
	Handle newPath;							/**< Output for the new path. The plug-in can return a path 
												 instead of a selection. If non-NULL, any data written into 
												 the @ref newSelection is ignored and the path described
												 by the handle becomes the work path. The
												 handle is disposed of the host. */
											
	/* We can optionally take the mask and use it to build a new layer or floating
	selection filled with the current foreground color. 
	 0 = make selection
	 1 = make path
	 2 = make layer/float */
	
	int32 treatment;		   /**< Treatment for returned pixels or mask. We can optionally 
								   take the mask and use it to build a new layer or floating
								   selection filled with the current foreground color. See @ref
								   TreamentOptions. */
	
	int32 supportedTreatments; /**< Mask indicating what treatments the host supports. See @ref
								    TreamentOptions. */
	
	SPBasicSuite *sSPBasic;		/**< PICA basic suite.  Provides the mechanism to access all PICA suites. */
	void		*plugInRef;		/**< Plug-in reference used by PICA. */
											
	/* And, of course, space for future expansion. */
	
	char reservedBlock [248];  /**< Reserved for future use.  Set to zero. */
			
	}
PISelectionParams, *SelectionRecordPtr;

/********************************************************************************/

/** @defgroup TreamentOptions Options for Treatment and supportedTreatment
* @{
*/
#define piSelMakeMask			0	 /**< Selection treatment. */
#define piSelMakeWorkPath		1	 /**< Path treatment. */
#define piSelMakeLayer			2	 /**< Layer or floating selection treatment. */
/* @} */

/********************************************************************************/

#endif // __PISelection_h__ 
