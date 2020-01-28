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
 *	\file PIPicker.h	
 *
 *	\brief This file describes Photoshop's Color Picker plug-in module
 *		interface.
 *
 *	Distribution:
 *		PUBLIC
 *
 */		

#ifndef __PIPicker__
#define __PIPicker__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"

/** 
* @defgroup ColorPickerModule Color Picker Module
* Color Picker modules provide a plug-in interface for implementation of different color pickers 
* in addition to the Photoshop and system color pickers. They appear whenever the user requests
* a unique or custom color (such as clicking on the foreground or background colors in the tools
* palette) and are selected in the \b Preferences General dialog. 
*
* The file type for color picker modules for Mac OS is 8BCM, the extension for Windows is .8BC.

* For additional information about writing color picker plug-ins, see @ref PGColorPickerModule
* "Writing Color Picker Plug-ins". 
*/

/********************************************************************************/
///@name Color Picker Module Selectors 
//@{

/** @ingroup ColorPickerModule 
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
#define pickerSelectorAbout 	 0
/**
* Allows the plug-in to execute the color picker.   Unlike other plug-in modules, 
* a Color Picker plug-in gets a single call from the host, and it is expected to
* do all the work during that call.  However, it is recommended that it follow this order:
* -# Prompt for Parameters \n
* If the plug-in has any parameters that the user can set, it should prompt the user 
* and save the values through the recording parameters for the scriptable handle accessed 
* through the parameters structure. Photoshop initializes the parameters field to NULL 
* when starting up.	\n
* See @ref PGColorPickerScripting "Color Pickers and Scripting" for more information about 
* Scripting and Color Pickers.
* -# Allocate Memory \n
* Use the buffer and handle suites to allocate any extra memory needed for your 
* computations. Please see @ref PGMemoryMgmtStrategies "Memory Management Strategies".
* -# Compute color space based on user input \n
* Compute whatever color conversions are required to return the user input to 
* the host in the proper form.
* -# Clean up and hand back results	\n
* Clean up after your operation. Dispose any handles you created, etc., then hand 
* back your color to the host for use. \n\n
*/
#define pickerSelectorPick		 1
/** @} */
//@}
/********************************************************************************/

/* Error return values. The plug-in module may also return standard Macintosh
   operating system error codes, or report its own errors, in which case it
   can return any positive integer. */

/** @defgroup ColorPickerErrors Color Picker Error Return Values
* The plug-in module can return standard operating system
* error codes, or report its own errors, in which case it
* can return any positive integer. 
*/

///@name Color Picker Error Return Values
//@{
/** @ingroup ColorPickerModule
* @{ 
*/
#define pickerBadParameters -30800	/**< A problem with the interface. */
/** @} */
//@}
/********************************************************************************/
/** @ingroup ColorPickerModule */
/** Structure used to return the color selected by the user. */
typedef struct PickParms
	{
	int16 sourceSpace;				/**< The color space the original color is in.
										 See @ref ColorSpace for values. */
	int16 resultSpace;				/**< The color space of the returned result.
										 See @ref ColorSpace for values.
										 Can be \c plugIncolorServicesChosenSpace */
	unsigned16 colorComponents[4];	/**< Contains the original color when the
										 plug-in is called with \c selectorPick.  
										 The plug-in should write the returned color 
										 here as well. \n\n
 										 The values of the array
										 depend on the color space.
										 <TABLE border="1"
										      summary="colorComponents array structure.">
 										 <CAPTION><EM>colorComponents array structure</EM></CAPTION>
										 <TR><TH>Color Space<TH>[0]<TH>[1]<TH>[2]<TH>[3]
										 <TR><TH>RGB<TD>red from 0...255<TD>green from 0...255<TD>blue from 0...255<TD>undefined
										 <TR><TH>HSB<TD>hue from 0...359 degrees<TD>saturation from 0...359 degrees (representing 0%...100%)<TD>brightness from 0...359 degrees(representing 0%...100%)<TD>undefined
 										 <TR><TH>CMYK<TD>cyan from 0...255 (representing 100%...0%)<TD>magenta from 0...255(representing 100%...0%)<TD>yellow from 0...255(representing 100%...0%)<TD>black from 0...255(representing 100%...0%) 
										 <TR><TH>HSL<TD>hue from 0...359 degrees<TD>saturation from 0...359 degrees(representing 0%...100%)<TD>luminance from 0...359 degrees(representing 0%...100%)<TD>undefined
										 <TR><TH>Lab<TD>Luminance from 0...255(representing 0...100)<TD>a. chromanance from 0...255 degrees(representing -128...127)<TD>b. chromanance from 0...255 degrees(representing -128...127)<TD>undefined
										 <TR><TH>Gray Scale<TD>gray value from 0...255<TD>undefined<TD>undefined<TD>undefined
 										 <TR><TH>XYZ<TD>x value from 0...255<TD>Y value from 0...255<TD>Z value from 0...255<TD>undefined
										 </TABLE>  */
	
	Str255 *pickerPrompt;			/**< Prompt string. */

	}
PickParms;

/********************************************************************************/
/** @ingroup ColorPickerModule */

/** This structure is passed to the plug-in module through the parameter block.
* See @ref PGPluginEntryPoint "Plug-in Entry Point" for an explanation of how the 
* host calls a plug-in.
*/
typedef struct PIPickerParams
	{
	
	/* We start with the fields that are common to pretty much all of the plug-ins. */
	
	int32		serialNumber;		/**< \deprecated Formerly the host serial number.
									   	 The host now reports
									     zero for the \c serialNumber. Plug-ins should use 
									     the @ref PropertySuite through the @ref PIPickerParams::propertyProcs field
									     and specify \c propSerialString2
									     to get the serial string. */

	TestAbortProc	abortProc;	   /**< A pointer to the \c TestAbortProc callback. */

	ProgressProc	progressProc;	/**< A pointer the the \c ProgressProc callback. */

	OSType		hostSig;			/**< The signature of the host, provided by the host.
	                                     The signature for Photoshop is signature is 8BIM. */
	HostProc	hostProc;			/**< A pointer to a host-defined callback procedure. 
									     May be NULL. */

	BufferProcs *bufferProcs;		/**< A pointer to the Buffer suite 
	                                     if it is supported by the host, otherwise NULL. 
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
			
	PropertyProcs	*propertyProcs;/**< Property callback suite. The plug-in needs to
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

	PickParms pickParms;			/**< Picker parameters used to pass the original color in to the
										 plug-in suite, and the returned color back to the host. */
	
	SPBasicSuite 	*sSPBasic;		/**< PICA basic suite.  Provides the mechanism to access all PICA suites. */
	void			*plugInRef;		/**< Plug-in reference used by PICA. */
	
	/* And, of course, space for future expansion. */
	
	char reservedBlock [252];	   /**< Reserved for future use.  Set to zero. */
			
	}
PIPickerParams, *PickerRecordPtr;

/********************************************************************************/


#endif // __PIPicker_h__
