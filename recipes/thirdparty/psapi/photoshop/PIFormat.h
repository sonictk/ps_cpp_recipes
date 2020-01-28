// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2014 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 *	\file PIFormat.h
 *
 *	\brief This file describes Photoshop's Image Format plug-in module interface
 *
 *	Distribution:
 *		PUBLIC
 *
 */		

/** 
* @defgroup FormatModule Format Module
* Format plug-in modules, sometimes referred to as Image Format, or File Format modules,
* are used to add new file types to the \b Open, \b Save, and \b Save \b As commands. Adobe 
* Photoshop ships with several file format modules including GIF, MacPaint, and BMP. \n\n
* The file type for format modules for Mac OS is 8BIF, the extension for Windows is .8BI.  \n\n
* Please also see @ref PGFormatModule "Writing Format Plug-ins."
* */

#ifndef __PIFormat__
#define __PIFormat__

#if PRAGMA_ONCE
#pragma once
#endif

#include <stdio.h>

#if MSWindows
#ifndef __PSWorld__
#include "PITypes.h"	// contains FSSpec
#else
#include <Files.h>		// contains betterer FSSpec
#endif
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"
#include "SPFiles.h"

/* Operation selectors */
///@name Format Module Selectors 
//@{

/** @ingroup FormatModule 
* @{
*/
/**  Allows the plug-in to display an about box for the Format Module. For this
* selector, the host does not pass the standard parameter block into the plug-in 
* main routine.  Instead it passes an \c AboutRecord.
*
* See @ref PGAboutBoxes	"About Boxes" for more information.
*/
#define formatSelectorAbout 			 	0

/**
* Allows a plug-in module to adjust the Photoshop memory allocation 
* algorithm. Photoshop sets \c FormatRecord::maxData to the maximum number of bytes it can allocate 
* to the plug-in. You may want to reduce \c maxData for increased efficiency. Please see 
* @ref PGMemoryMgmtStrategies "Memory Management Strategies".
*/
#define formatSelectorReadPrepare		 	1
/**
* Allows the plug-in module to begin its interaction with the host.
* If the plug-in supports scripting, it should read any scripting parameters to override 
* any default parameters. The scripting system also returns whether to show the 
* plug-in dialog or not.\n\n
* The plug-in should initialize \c FormatRecord::imageMode, \c FormatRecord::imageSize32, 
* \c FormatRecord::depth, \c FormatRecord::planes, \c FormatRecord::imageHRes and 
* \c FormatRecord::imageVRes. \n\n
* If an indexed color image is being opened, the plug-in should also set \c FormatRecord::redLUT, 
* \c FormatRecord::greenLUT and \c FormatRecord::blueLUT. \n\n
* If the plug-in has a block of image resources to process, it should read the image resources
* in from the file and set \c FormatRecord::imageRsrcData to be a handle to the resource data. 
* For more information about Photoshop image resources, see 
* <a href="../Photoshop File Formats.pdf">Photoshop File Formats</a>.	\n\n
* The plug-in should allocate and read the first pixel image data buffer as appropriate. 
* The area of the image being returned to the plug-in host is specified by \c FormatRecord::theRect32, 
* \c FormatRecord::loPlane, and \c FormatRecord::hiPlane.\n\n
* The actual pixel data is pointed by \c  FormatRecord::data. The \c FormatRecord::colBytes, 
* \c FormatRecord::rowBytes, \c FormatRecord::planeBytes, and \c FormatRecord::planeMap 
* fields must specify the organization of the data.\n\n
* Photoshop is very flexible about the format in which image data can be read. 
* For example, to read just the red plane of an RGB color image, use the following parameter values:
* 	<TABLE border="1"
* 	     summary="Read red plane of RGB.">
* 	<CAPTION><EM>Read red plane of RGB</EM></CAPTION>
* 	<TR><TH>Parameter<TH>Value
* 	<TR><TH>loPlane<TD>0
* 	<TR><TH>hiPlane<TD>0
* 	<TR><TH>colBytes<TD>1
* 	<TR><TH>rowBytes<TD>width of the area being read
* 	<TR><TH>planeBytes<TD>ignored, since loPlane=hiPlane
* 	</TABLE> \n\n
* If you wish to read the RGB data in interleaved form (RGBRGB...), use the following values:
* 	<TABLE border="1"
* 	     summary="Read RGB values in interleaved form.">
* 	<CAPTION><EM>Read RGB values in interleaved form</EM></CAPTION>
* 	<TR><TH>Parameter<TH>Value
* 	<TR><TH>loPlane<TD>0
* 	<TR><TH>hiPlane<TD>2
* 	<TR><TH>colBytes<TD>3
* 	<TR><TH>rowBytes<TD>3 * width of the area being read
* 	<TR><TH>planeBytes<TD>1
* 	</TABLE> 
*/
#define formatSelectorReadStart 		 	2
/**
* Processes a sequence of areas within the image. The plug-in handler for this 
* selector should process any incoming data and then, just as with the start call, set up 
* \c FormatRecord::theRect32, \c FormatRecord::loPlane, \c FormatRecord::hiPlane, \c FormatRecord::planeMap, 
* \c FormatRecord::data, \c FormatRecord::colBytes, \c FormatRecord::rowBytes, and 
* \c FormatRecord::planeBytes to describe the next chunk of the image being returned.  \n\n
* The host continues calling the plug-in with 
* \c formatSelectorReadContinue until the plug-in sets \c data=NULL.
* @note Be careful processing user-cancel events during \c formatSelectorReadContinue. 
* Normally your plug-in would be expecting another \c formatSelectorReadContinue call. 
* If the user cancels, the next call will be \c formatSelectorReadFinish, not 
* \c formatSelectorReadContinue!
*/
#define formatSelectorReadContinue		 	3
/**
* Allows the plug-in to cleanup from the read operation just performed. 
* This call is made by the plug-in host if and only if \c formatSelectorReadStart returned 
* without error, even if one of the \c formatSelectorReadContinue calls results in an error.\n\n
* Most plug-ins will at least need to free the buffer used to return pixel data if this has 
* not been done previously.  \n\n
* If Photoshop detects \e Command-period in the Mac OS or \e Escape in Windows while processing 
* the results of a \c formatSelectorReadContinue call, it calls \c formatSelectorReadFinish. \n\n
* If your plug-in is scripting-aware and you have changed any initial parameters, you should 
* pass a complete descriptor back to the scripting system in the \c PIDescriptorParameters structure.
*/
#define formatSelectorReadFinish		 	4

/**
* Allows a plug-in module to adjust the Photoshop memory allocation 
* algorithm. Photoshop sets \c FormatRecord::maxData to the maximum number of bytes it can allocate 
* to the plug-in. You may want to reduce \c maxData for increased efficiency. Please see 
* @ref PGMemoryMgmtStrategies "Memory Management Strategies".
*/

#define formatSelectorOptionsPrepare	 	5
/**
* Allows a plug-in to determine whether the current document can be saved in the 
* required file format, and if necessary, get any file options from the user.
* If the plug-in supports scripting, read any scripting parameters at this point,
* to override any default parameters. The scripting system  also returns whether 
* to show the plug-in dialog or not.\n\n
* If the plug-in needs to examine the image to compute the file size, it can iterate 
* through the image data in \c formatSelectorOptionsContinue in the same fashion as 
* is done when writing the file to request sections of the image.
*/
#define formatSelectorOptionsStart		 	6
/**
* Allows a plug-in to request parts of the image, from which it determines whether 
* it can store the file. Refer to @ref formatSelectorWriteStart and 
* @ref formatSelectorWriteContinue for details. You can also use the @ref AdvanceStateProc 
* to iterate through the image.
* @note If the \c FormatRecord::data is set to NULL in the @ref formatSelectorOptionsStart call, 
* this selector will not be called at all. 
*/
#define formatSelectorOptionsContinue	 	7
/**
* Allows the plug-in to perform any necessary clean up.
*/
#define formatSelectorOptionsFinish 	 	8

/**
* Allows a plug-in module to adjust the Photoshop memory allocation 
* algorithm. Photoshop sets \c FormatRecord::maxData to the maximum number of bytes it can allocate 
* to the plug-in. You may want to reduce \c maxData for increased efficiency. Please see 
* @ref PGMemoryMgmtStrategies "Memory Management Strategies". */
#define formatSelectorEstimatePrepare	 	9

/**
* Allows a plug-in to calculate the disk space needed to save the file. If the plug-in can 
* calculate the file size without examining the image data, you can set the 
* \c FormatRecord::minDataBytes and \c FormatRecord::maxDataBytes fields 
* to the approximate size of your file (due to compression, you may 
* not be able to exactly calculate the final size), and set \c FormatRecord::data=NULL.\n\n
* If the plug-in needs to examine the image to compute the file size, it can iterate through 
* the image data in \c formatSelectorEstimateContinue in the same fashion as is done when 
* writing the file to request sections of the image. */
#define formatSelectorEstimateStart 		10

/**
* Allows a plug-in to request parts of the image from which it can compute the 
* minimum and maximum bytes to store the file. Refer to @ref formatSelectorWriteStart 
* and @ref formatSelectorWriteContinue for details. \n\n
* You can also use the @ref AdvanceStateProc to iterate through the image.
* @note If \c FormatRecord::data field is set to NULL in the \c formatSelectorEstimateStart call, 
* this selector is not be called at all. 
*/
#define formatSelectorEstimateContinue		11
/**
* Allows the plug-in to perform any necessary clean up.
*/
#define formatSelectorEstimateFinish		12

/**
* Allows a plug-in module to adjust the Photoshop memory allocation 
* algorithm. Photoshop sets \c FormatRecord::maxData to the maximum number of bytes it can allocate 
* to the plug-in. You may want to reduce \c maxData for increased efficiency. Please see 
* @ref PGMemoryMgmtStrategies "Memory Management Strategies".
*/

#define formatSelectorWritePrepare			13
/**
* Allows a plug-in module to begin writing the file. On entry, the file 
* to be written is open, and the file pointer is positioned at the start of 
* the file. The plug-in should write any file header information, such as image 
* resources, to the file.\n\n	
* The plug-in should then indicate which portion of the image data to 
* provide for the first @ref formatSelectorWriteContinue call.\n\n
* The area of the image requested from the plug-in host is specified 
* by \c FormatRecord::theRect32, \c FormatRecord::loPlane, and \c FormatRecord::hiPlane.
* The actual pixel data is pointed to by \c FormatRecord::data.
* The plug-in must also specify the organization of the data to be 
* returned by the plug-in host in the \c FormatRecord::colBytes, \c FormatRecord::rowBytes, 
* \c FormatRecord::planeBytes, and \c FormatRecord::planeMap fields.
* \n\n
* Photoshop is very flexible in the format in which image data can be 
* delivered to the plug-in. 
* For example, to return just the red plane of an RGB color image, 
* use the following parameter values:
* 	<TABLE border="1"
* 	     summary="Return red plane of RGB.">
* 	<CAPTION><EM>Return red plane of RGB</EM></CAPTION>
* 	<TR><TH>Parameter<TH>Value
* 	<TR><TH>loPlane<TD>0
* 	<TR><TH>hiPlane<TD>0
* 	<TR><TH>colBytes<TD>1
* 	<TR><TH>rowBytes<TD>width of the area being returned
* 	<TR><TH>planeBytes<TD>ignored, since loPlane=hiPlane
* 	</TABLE> \n\n
If you wish to return the RGB data in interleaved form (RGBRGB...), 
use the following values:.
Return RGB data in interleaved form
* 	<TABLE border="1"
* 	     summary="Return RGB values in interleaved form.">
* 	<CAPTION><EM>Return RGB values in interleaved form</EM></CAPTION>
* 	<TR><TH>Parameter<TH>Value
* 	<TR><TH>loPlane<TD>0
* 	<TR><TH>hiPlane<TD>2
* 	<TR><TH>colBytes<TD>3
* 	<TR><TH>rowBytes<TD>3 * width of the area being returned
* 	<TR><TH>planeBytes<TD>1
* 	</TABLE> 
*/
#define formatSelectorWriteStart			14
/**
* Provides the plug-in module some or all of the image data; the plug-in 
* module should write this data to file. 
* If successful, set up \c FormatRecord::theRect32, \c FormatRecord::loPlane, 
* \c FormatRecord::hiPlane, \c FormatRecord::planeMap, \c FormatRecord::data, 
* \c FormatRecord::colBytes, \c FormatRecord::rowBytes, and \c FormatRecord::planeBytes 
* to describe the next chunk of the image being requested.
* The host keeps calling your \c formatSelectorReadContinue handler until the plug-in sets 
* \c FormatRecord::theRect32 to an empty rectangle. Before returning after the last image data has
* been written, write any file trailer information to the file.
* @note Be careful processing user-cancel events during \c formatSelectorWriteContinue. 
* Normally your plug-in would be expecting another \c formatSelectorWriteContinue call. 
* If the user cancels, the next call will be \c formatSelectorWriteFinish, not 
* \c formatSelectorWriteContinue.
*/
#define formatSelectorWriteContinue 		15
/**
* Allows the plug-in to cleanup from the write operation just performed. 
* This call is made by the plug-in host if and only if \c formatSelectorWriteStart 
* returned without error, even if one of the \c formatSelectorWriteContinue calls 
* results in an error. \n\n
* Most plug-ins at least need to free the buffer used to hold pixel data 
* if this has not been done previously.	\n\n
* If Photoshop detects \e Command-period in the Mac OS or \e Escape in Windows while 
* processing the results of a \c formatSelectorWriteContinue call, it calls the 
* \c formatSelectorWriteFinish routine.
* If the  plug-in is scripting-aware and has changed any initial parameters, it 
* should pass a complete descriptor back to the scripting system in the 
* @ref PIDescriptorParameters structure. */
#define formatSelectorWriteFinish			16

/**
* Determines whether a plug-in can process a given file type. 
* The plug-in module should examine 
* the file to determine whether the file is one that it can process, and indicate this 
* in its result parameter:
* @code
* if (module can read this file)
* 	*result = noErr;
* else
* 	*result = formatCannotRead;
* @endcode
* See @ref PGFileFiltering "File Filtering Sequence" for additional information.
*/

#define formatSelectorFilterFile			17

#define formatSelectorGetFilePropertyValue	18	/**< Gets a file property value from the format plug-in. */

#define formatSelectorLosslessRotate		19	/**< Requests the format plug-in to rotate a file losslessly. */

#define formatSelectorBulkSettings			20	/**< Sets parameters for multiple files. */

#define formatSelectorXMPRead				21  /**< Reads the XMP data from your file. */
#define formatSelectorXMPWrite				22  /**< Writes the XMP data to your file. */

#define	formatSelectorBulkOpen				23

#define formatSelectorLoad					24
#define formatSelectorUnload				25

#define formatSelectorPreferences			26

#define formatSelectorSettingsCopy			27
#define formatSelectorSettingsPaste			28
#define formatSelectorSettingsClear			29
#define formatSelectorSettingsDefault		30
#define formatSelectorSettingsPrevious		31
#define formatSelectorSettingsPresetList	32
#define formatSelectorSettingsChecksum		33

#define formatSelectorXMPAppend				34

#define formatSelectorReadLayerStart		35
#define formatSelectorReadLayerContinue		36
#define formatSelectorReadLayerFinish		37

#define formatSelectorWriteLayerStart		38
#define formatSelectorWriteLayerContinue	39
#define formatSelectorWriteLayerFinish		40

/** @} */ // end ingroup
///@}
  
// called when the plugin is used to launch an external editor (that Photoshop may not know about)
// fileSpec and fileSpec2 will be the only valid fields in the format record
#define formatSelectorLaunchExternalEditor	41

/*	We keep various pieces of information about the file format in the PiMI resource.
	Here is the structure of that resource. */

/******************************************************************************/

/**
* @defgroup PiPLFormatKeys Format Module PiPL Properties
* These PiPL properties are only applicable to Format plug-in modules. 
*/
///@name PiPL Format Keys 
//@{
/**
* @ingroup PiPLFormatKeys
* @{
*/
/**
* Default type and creator code used for files newly created with this format plug-in; 
* key value is 'fmTC'. 
* This property key reflects the \c FmtFileType property in the PiPL resource file. 
* The data for the property has type @ref TypeCreatorPair.
* Under Windows, files do not store \c TypeCreator information, except internally, so this 
* property is not required; they are always interpreted as of type 'BINA' and creator 'mdos'.\n\n
* All the info regarding what files can be read and written is obtained from the 
* @ref PIReadExtProperty or the @ref PIFilteredExtProperty.
* Under Windows, PiMI extensions are converted to @ref PIReadExtProperty, so use of 
* @ref PIFilteredExtProperty requires additional coding if you are porting a 16-bit 
* plug-in format module to 32-bit.
*/
#define PIFmtFileTypeProperty    		0x666d5443 	/* 'fmTC' \<TypeCreatorPair\> Default file type for file format. */

/**
* List of type and creator pairs that the format plug-in can read; key value is 'RdTy'. 
* This property key reflects the \c ReadTypes property in the PiPL resource file. 
* The data for the property is an array of @ref TypeCreatorPair.
* Specifying a value of four spaces (0x20202020L) matches any type or creator.
*/
#define PIReadTypesProperty		 		0x52645479 	/* 'RdTy' \<TypeCreatorPair []\> File type info for file format plug-ins */

/**
* List of type and creator pairs for which the file format plug-in should be called to 
* determine if the file can be read; key value is 'fftT'. 
* This property key reflects the \c FilteredTypes property in the PiPL resource file. 
* The data for the property is an array of
* @ref TypeCreatorPair. Specifying a value of four spaces (0x20202020L) 
* matches any type or creator.
*/
#define PIFilteredTypesProperty	 		0x66667454 	/* 'fftT' \<TypeCreatorPair []\> File types to filter for file format plug-ins */

/**
* List of extensions which the format plug-in can read; key value is 'RdEx'. 
* This property key reflects the \c ReadExtensions property in the PiPL resource file. 
* The data for the property has type \c OSType; the extension is stored in the 
* first three characters of the OSType. The fourth character must be a space.
*/
#define PIReadExtProperty		 		0x52644578 	/**'RdEx' \<OSType []\> File type info for file format plug-ins */

/**
* List of extensions for which the file format plug-in should be called to determine if 
* the file can be read; key value is 'fftE'.
* This property key reflects the \c FilteredExtensions property in the PiPL resource file. 
* The data for the property has type \c OSType; the extension is stored in the 
* first three characters of the OSType. The fourth character must be a space. 
*/
#define PIFilteredExtProperty	 		0x66667445 	/* 'fftE' \<OSType []\> File types to filter for file format plug-ins */

/**
* A set of flags which control the operation of file format plug-ins; key value is 'fmtf'. 
* This property key reflects the \c FormatFlags property in the PiPL resource file. 
* The data for the property has type \c FlagSet. The default value for any flag is FALSE. 
* See @ref FmtFlags "Format Flags".
*/
#define PIFmtFlagsProperty		 		0x666d7466 	/* 'fmtf' \<Set\> Format flags */

/**
* Hidden read/write flags; key value is 'fmhi'. 
* This property key reflects the \c FormatHiddenFlags property in the PiPL resource file. 
* The data for the property has type \c FlagSet. See @ref FmtHiddenFlags. \n\n
*/
#define PIFmtHiddenFlagsProperty 		0x666D6869 	/* 'fmhi' Hidden read/write flags  */

/**
* ICC profile flags; key value is 'fmip'. 
* This property key reflects the \c FormatICCFlags property in the PiPL resource file. 
* The data for the property has type \c FlagSet. See @ref FmtICCFlags. \n\n
*/
#define PIFmtICCFlagsProperty    		0x666D6970 	/* 'fmip' ICC profile flags. */

/**
* ICC required profile flags; key value is 'fmir'. 
* This property key reflects the \c FormatICCRequiredFlags property in the PiPL resource file. 
* The data for the property has type \c FlagSet. See @ref FmtICCReqdFlags. \n\n
*/
#define PIFmtICCRequiredFlagsProperty   0x666D6972 	/* 'fmir' ICC required profile flags.*/

/**
* The maximum number of rows and columns that can be in an image saved in this format; 
* key value is 'mxsz'. 
* This property key reflects the \c FormatMaxSize property in the PiPL resource file. 
* The data for the property has type \c Point. 
* Photoshop uses this field to screen out ineligible formats.
*/
#define PIFmtMaxSizeProperty	 		0x6d78737a 	/* 'mxsz' \<Point\> Max rows and cols supported by this format. 	*/

/**
* An array of counts of the maximum number of channels which can/will be saved for a 
* given image mode; key value is 'mxch'.
* This property key reflects the \c FormatMaxChannels property in the PiPL resource file. 
* This array is indexed by the plug-in mode constants. For example, if your format 
* plug-in supports a single alpha channel in RGB mode, you should set 
* \c maxChannels[plugInModeRGBColor]=4.
* A plug-in might be asked to save more channels than it reports it can support. 
* This field exists primarily so that Photoshop can warn the user that alpha channels 
* will be discarded.
*/
#define PIFmtMaxChannelsProperty 		0x6d786368 	/* 'mxch' \<int16 []\> Max channels per mode for this format. */

/**
* Supports formatSelectorGetFilePropertyValue selector; key value is 'ffps'.
* This property key reflects the \c FileProperties property in the PiPL resource file. 
*/
#define PIFmtFilePropertiesProperty		0x66667073	/* 'ffps' Supports formatSelectorGetFilePropertyValue selector. */

/**
* Supports formatSelectorLosslessRotate selector; key value is 'fllr'.
* This property key reflects the \c LosslessRotate property in the PiPL resource file. 
*/
#define PIFmtLosslessRotateProperty		0x666C6C72	/* 'fllr' Supports formatSelectorLosslessRotate selector. */

/**
* Supports formatSelectorBulkSettings selector; key value is 'ffbs'.
* This property key reflects the \c BulkSettings property in the PiPL resource file. 
*/
#define PIFmtBulkSettingsProperty		0x66666273	/* 'ffbs' Supports formatSelectorBulkSettings selector.*/

/**
* File format is primary metadata source; key value is 'ffpm'.
* This property key reflects the \c PrimaryMetadataSource property in the PiPL resource file. 
*/
#define PIFmtPrimaryMetadataProperty	0x6666706d	/* 'ffpm' File format is primary metadata source.*/

/**
* File format is primary thumbnail source; key value is 'ffpt'.
* This property key reflects the \c PrimaryThumbnailSource property in the PiPL resource file. 
*/
#define PIFmtPrimaryThumbnailProperty	0x66667074	/* 'ffpt' File format is primary thumbnail source. */

/**
* Supports formatSelectorXMPRead selector; key value is 'xmpr'.
* This property key reflects the \c XMPRead property in the PiPL resource file. 
*/
#define PIFmtXMPReadProperty			0x786D7072	/* 'xmpr' Supports formatSelectorXMPRead selector.*/

/**
* Supports formatSelectorXMPWrite selector; key value is 'xmpw'.
* This property key reflects the \c XMPWrite property in the PiPL resource file. 
*/
#define PIFmtXMPWriteProperty			0x786D7077	/* 'xmpw' Supports formatSelectorXMPWrite selector. */

/**
* Supports extractQuickThumbnail field; key value is 'qthm'.
* This property key reflects the \c QuickExtractThumbnail property in the PiPL resource file. 
*/
#define PIFmtQuickThumbExtractProperty	0x7174686D	/* 'qthm' Supports extractQuickThumbnail field. */

/**
* Supports formatSelectorBulkOpen selector; key value is 'ffbo'.
* This property key reflects the \c BulkOpen property in the PiPL resource file. 
*/
#define PIFmtBulkOpenProperty			'ffbo'		/* 'ffbo' Supports formatSelectorBulkOpen selector. */

/**
* Supports settings copy/paste/etc selector; key value is 'rscp'.
* This property key reflects the \c RawSettings property in the PiPL resource file. 
*/
#define PIFmtRawSettingsProperty		'rscp'		/* 'rscp' Supports settings copy/paste/etc selectors.*/

/**
* Plug-in prefers write access when opening; key value is 'fowa'.
* This property key reflects the \c OpenWriteAccess property in the PiPL resource file. 
*/
#define PIFmtOpenWriteAccessProperty	'fowa'		/* 'fowa' Plug-in prefers write access when opening.*/

/**
* Warning if this plug-in is override by another; key value is 'fwio'.
* This property key reflects the \c WarnIfOverridden property in the PiPL resource file. 
*/
#define PIFmtWarnIfOverriddenProperty	'fwio'		/* 'fwio' Warning if this plug-in is override by another. */

/**
* Plug-in is resource fork thread safe; key value is 'frts'.
* This property key reflects the \c ResourceThreadSafe property in the PiPL resource file. 
*/
#define PIFmtResourceThreadSafeProperty	'frts'		/* 'ft' Plug-in is resource fork thread safe. */

#define PIFmtSupportsLayersProperty		'fmsl'		/* 'fmsl' plug-in supports layers */

#define PIFmtSupportsLayersReadOnlyProperty	'slRO'	/* 'slRO' plug-in layer support is read-only */

/** Plug-in can save a file out on a separate background thread. 
* This property key reflects the \c SupportsBackgroundSave property in the PiPL resource file. 
* Formats that rely on Globals, Mac resource manager, or show UI after the formatSelectorWriteStart
* entry should not allow background save. A format plugin could be called to read a file on main thread
* while a file is being saved in the background thread. 
*/
#define PIFmtSupportsBackgroundSaveProperty	'fbgs'	/* 'fbgs' plug-in supports background save */

/** Plug-in can read and write files using POSIX API calls.
* This property key reflects the \c SupportsPOSIXIO property in the PiPL resource file.
* The FSRef API is deprecated and Photoshop will require plug-ins to have this key present
* if and when the FSRef API is missing from the OS. See \c hostSupportsPOSIXIO, \c pluginUsingPOSIXIO
* and \c posixFileDescriptor in the \c FilterRecord for more information.
*/
#define PIFmtSupportsPOSIXIOProperty 'fxio'     /* 'fxio' plug-in supports POSIX API for read and write */

/**
* The maximum size on disk the format can read or write. Photoshop defaults to 2 gigabytes. If
* your format can read and write files larger then set this property accordingly.
* key value is 'fslm'. 
* This property key reflects the \c FormatFileSizeLimit property in the PiPL resource file. 
* The data for the property has type \c int32 and is number of gigabytes.
* Photoshop uses this field to allow file sizes larger than 2 gigabytes.
*/
#define PIFmtFileSizeLimitProperty	 		0x66736c6d 	/* 'fslm' \<int32 \> Max size on disk your format can read and write. In gigabytes. */


/**
* @}
*/
//@}

/******************************************************************************/

/* properties that can be requested through formatSelectorGetFilePropertyValue */

/** Indicates how the file can be rotated in this format; key value is 'fro'.
* The \c FormatRecord::browserRotation field needs to be filled out. */
#define PIFmtPRotate				0x66726F74	
/******************************************************************************/

/* property values that should be returned by formatSelectorGetFilePropertyValue */

#define PIFmtPVNotSupported					0	/**< The requested property is not supported by this format plug-in. */

/* values for kFFPRotate */
#define PIFmtPVRotateNo						2	/**< This file should not be rotated */
#define PIFmtPVRotateIsLossy				3	/**< This file can be rotated, but it will be loss */
#define PIFmtPVRotateIsLossless				4	/**< This file can be rotated and it will be losses */
#define PIFmtPVRotateIsLosslessWithCallback	5	/**< This file can be only be rotated losses by using the callback, otherwise it will be loss */

	/* add values for other format file properties here */

/******************************************************************************/

/* Format Hidden Flags Indices. */
/** @defgroup FmtHiddenFlags Format Hidden Flags for PIFmtHiddenFlagsProperty
* @{
*/
///@name Format Hidden Flags for PIFmtHiddenFlagsProperty
//@{
/** @ingroup FmtHiddenFlags
* @{ 
*/
#define PIFmtShowReadFlag 		0
#define PIFmtShowWriteFlag		1
/** @} */
//@}

/******************************************************************************/

/* Format flags indices. */
/** @defgroup FmtFlags Format Flags for PIFmtFlagsProperty
* A set of flags that controls the operation of the file format plug-in.
* @{
*/
///@name Format Flags for PIFmtFlagsProperty
//@{
/** @ingroup FmtFlags
* @{ 
*/

/**
* \deprecated
*/
#define PIFmtReadsAllTypesFlag 0

/**
* Controls whether Photoshop adds the image resources to the Mac OS resource fork.
* If FALSE, Photoshop adds the image resources to the Mac OS resource fork but 
* this is not be portable to other platforms. \n\n
* Resources besides image data, such as printing information, pen tool paths, and so on, 
* are known as image resources. The plug-in format has the option of taking responsibility 
* for these resources by reading and writing a block of data containing the image resources. 
*/
#define PIFmtSavesImageResourcesFlag 1

/**
* Indicates that the plug-in can read files, when the flag is TRUE. 
*/
#define PIFmtCanReadFlag 2

/**
* Indicates that the plug-in can write files, when the flag is TRUE. 
*/
#define PIFmtCanWriteFlag 3

/**
* Indicates that plug-in can write the file if the plug-in originally read the file, when the
* flag is TRUE.
*/
#define PIFmtCanWriteIfReadFlag 4

/**
* Indicates that the plug-in supports saving the transparency index of indexed color image
* or saving transparency as a first alpha channel for
* other color modes, when the flag is TRUE.
* See also FormatRecord::transparencyMatting and FormatRecord::transparencyPlane.
*/
#define PIFmtCanWriteTransparency 5

/**
* Indicates that the plug-in can create a Thumbnail, when the flag is TRUE.
* Set the flag only when the plug-in does not need to query for open parameters./n/n 
*/
#define PIFmtCanCreateThumbnail 6

/**
* Indicates that the plug-in can save spot channels when the flag is TRUE.
*/
#define PIFmtCanWriteSpotChannel 7

/** @} */
//@}
/******************************************************************************/

/* Format ICC Profile Flags Indices. */
/** @defgroup FmtICCFlags Format ICC Profile Flags  for PIFmtICCFlagsProperty
*/
///@name Format Flags ICC Profile Flags for PIFmtICCFlagsProperty
//@{
/** @ingroup FmtICCFlags
* @{ 
*/
#define PIFmtICCEmbedGrayFlag 		0    /**< Can embed profiles in gray scale images, when bit is set. */
#define PIFmtICCEmbedIndexedFlag 	1    /**< Can embed profiles in indexed color images, when bit is set. */
#define PIFmtICCEmbedRGBFlag 		2    /**< Can embed profiles in RGB images, when bit is set. */
#define PIFmtICCEmbedCMYKFlag 		3    /**< Can embed profiles in CMYK images, when bit is set. */
/** @} */
//@}

/******************************************************************************/

/* Required Format ICC Profile Flags Indices. */
/** @defgroup FmtICCReqdFlags Required Format ICC Profile Flags for PIFmtICCRequiredFlagsProperty
*/
///@name Required Format ICC Profile Flags for PIFmtICCRequiredFlagsProperty
//@{
/** @ingroup FmtICCReqdFlags
* @{ 
*/
#define PIFmtICCRequireGrayFlag 		0    /**< Requires embedding profiles in gray scale images, when bit is set. */
#define PIFmtICCRequireIndexedFlag 		1    /**< Requires embedding profiles in indexed color images, when bit is set. */
#define PIFmtICCRequireRGBFlag 			2    /**< Requires embedding profiles in RGB images, when bit is set. */
#define PIFmtICCRequireCMYKFlag 		3    /**< Requires embedding profiles in CMYK images, when bit is set. */
/** @} */
//@}

/******************************************************************************/

/* Bit masks for the browserRotation field */
/** @defgroup BrowserRotationFlags Bit masks for the browserRotation field 
*/
///@name Bit masks for the browserRotation field
//@{
/** @ingroup BrowserRotationFlags
* @{ 
*/
#define PIFmtBrowserRotationFlipFlag		2	/**< Flip horizontal. */
#define	PIFmtBrowserRotationDisableFlag		3	/**< The @ref FormatRecord::browserRotation field is disabled. */
#define PIFmtBrowserRotationEnableFlag		4	/**< The @ref FormatRecord::browserRotation field is enabled, and is read-write. */
/** @} */
//@}

/******************************************************************************/

/* Bit masks for bulkMask and bulkFlags fields */
/** @defgroup BulkFlags Bit masks for bulkMask and bulkFlags fields 
*/
///@name Bit masks for bulkMask and bulkFlags fields
//@{
/** @ingroup BulkFlags
* @{ 
*/
#define PIFmtBulkOpenMask				1
#define PIFmtBulkInvalPreviewMask		2
#define PIFmtBulkInvalMetaMask			4
#define PIFmtBulkDeleteMask				8
#define PIFmtBulkModifyListMask        16
/** @} */
//@}

/******************************************************************************/

/* Pragma to byte align structures; for Microsoft C */
#if WIN32
#pragma pack(push,1)
#endif

/******************************************************************************/

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/** 
* Information about this Format Plug-in.
*/
typedef struct FormatInfo
	{

	PlugInInfo	plugInInfo; 			/**< The information common to all plug-ins.		*/
	int16		typeCount;				/**< The number of types in the type list.			*/
	int16		extensionCount; 		/**< The number of extensions in the type list.		*/
	Boolean 	canRead;				/**< Can we read using this format?					*/
	Boolean 	readsAllTypes;			/**< Can this plug-in read from all files?			*/
	Boolean 	canWrite;				/**< Can we write using this format?				*/
	Boolean		canWriteIfRead;			/**< Can we write if we read using this format? 	*/
	Boolean 	savesImageResources;	/**< Does this file format save the resource data.	*/
	Boolean		padFlag;				/**< Padding. */
	int16		maxChannels [16];		/**< Maximum # of channels with each plug-in mode.	*/
	int16		maxRows;				/**< Maximum rows allowed in document.				*/
	int16		maxCols;				/**< Maximum columns allowed in document. 			*/
	OSType		fileType;				/**< The file type if we create a file.				*/
	OSType		creatorType;			/**< The creator type if we create a file.			*/
	OSType		typeList [1];			/**< The types and extensions supported.			*/

	}
FormatInfo;

/* Pragma to turn off align structures for Microsoft C */
#if WIN32
#pragma pack(pop)
#endif
/******************************************************************************/

/** @defgroup FormatErrors Format Error Return Values
* The plug-in module can return standard operating system
* error codes, or report its own errors, in which case it
* can return any positive integer. 
* 
* @note When writing a file, if your plug-in module sets \c result to any non-zero value, 
* then no subsequent selector calls are made by Photoshop. For example, if the 
* @ref formatSelectorOptionsStart handler determines that the file cannot be saved, then 
* none of the remaining selectors are called: options, estimate, nor write.
*/
///@name Format Error Return Values
//@{
/** @ingroup FormatModule
* @{ 
*/
#define formatBadParameters 	-30500	/**< An error with the interface. See @ref PGFormatErrorHandling
										     "Error Handling for Writing with Format Plug-ins." */
#define formatCannotRead		-30501	/**< No scanner installed.  See @ref PGFormatErrorHandling
										     "Error Handling for Writing with Format Plug-ins." */
#define formatSkipFile			-30502	/**< The host should skip processing this file. 
											 Used with bulk selectors. */
#define formatPasswordProtected -30503	/**< For PDF files. */
#define formatUnsupportedRaw    -30504	/**< The file appears to be a raw file from a camera model which is
											 not supported by the installed version of Camera Raw. */
#define formatUnsupportedDNG    -30505	/**< The DNG file is not supported by the installed
											 version of Camera Raw. */
/** @} */
//@}

#if WIN32
#pragma pack(push,4)
#endif

/** @ingroup FormatModule 
*/
/** This structure is passed to the plug-in module through the parameter block.
* See @ref PGPluginEntryPoint "Plug-in Entry Point" for an explanation of how the 
* host calls a plug-in.
*/

typedef struct FormatRecord
	{

	int32				serialNumber;	/**< \deprecated - Formerly the host serial number.
									   	 The host now reports
									     zero for the \c serialNumber. Plug-ins should use 
									     the @ref PropertySuite through the @ref FormatRecord::propertyProcs field
									     and specify \c propSerialString2
									     to get the serial string. */

	TestAbortProc		abortProc;		/**< A pointer to the \c TestAbortProc callback. */

	ProgressProc		progressProc;	/**< A pointer the the \c ProgressProc callback. */

	int32				maxData;		/**< The maximum number of bytes Photoshop can free up for a plug-in
								         to use. The plug-in can reduce this 
										 value during in the handlers for the Format prepare selectors.  
										 The \c continue handlers should process 
										 the image in pieces no larger than \c maxData, less 
										 the size of any large tables or scratch areas it 
										 has allocated. */
	
	int32				minDataBytes;	/**< The minimum bytes needed in 
										 the data fork space to write the file. The plug-in should 
										 set this during the estimate sequence of selector calls. 
										 See @ref formatSelectorEstimateStart. */
	int32				maxDataBytes;	/**< The maximum bytes allocated in 
										 the data fork space to write the file. The plug-in should 
										 set this during the estimate sequence of selector calls. 
										 See @ref formatSelectorEstimateStart. */

	int32				minRsrcBytes;	/**< The minimum bytes needed in resource fork space 
										 to write the file. The plug-in should set this during the 
										 estimate sequence of selector calls. */
	int32				maxRsrcBytes;	/**< The maximum bytes allocated in resource fork space 
										 to write the file. The plug-in should set this during the 
										 estimate sequence of selector calls. */

	intptr_t			dataFork;		/**< \deprecated Use \c posixFileDescriptor below.
                                         The reference number for the data fork of the file
										 to be read during the read sequence or written during the 
										 write sequence. During the options and estimate selector
										 sequences, this field is undefined. In Windows, this is the 
										 file handle of the file returned by \c OpenFile(). */
	intptr_t			rsrcFork;		/**< \deprecated The reference number for the resource fork of the file
										 to be read during the read sequence or written during the 
										 write sequence. During the options and estimate selector
										 sequences, this field is undefined. In Windows, this 
										 field is undefined. */
#if __LP64__
	FSSpec *			unusedFileSpec;	
#else
	FSSpec *			fileSpec;		/**< Full file specification.  This is an array when
										 using the @ref formatSelectorBulkSettings. 
										 See @ref fileSpec2.*/
										/** This is nil under Mac 64, since FSSpecs are not supported.
											use fileSpec2 instead, which is supported on all platforms */
#endif

	int16				imageMode;		/**< The mode of the image being imported (grayscale, 
										 RGB Color, and so on). The plug-in should set this field 
										 during the @ref formatSelectorReadStart handler. 
										 Photoshop sets this field before it calls
										 @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart,
										 or @ref formatSelectorWriteStart. \n\n
										 See @ref ImageModes for possible values. */
	Point				imageSize;		/**< \deprecated Use \c FormatRecord::imageSize32.
	                                     The size of the image.  */
	int16				depth;			/**< The resolution of the image in bits per pixel per plane. 
										 The plug-in should set this field in the 
										 @ref formatSelectorReadStart handler. Valid 
										 settings are 1, 8, 16, and 32. */
	int16				planes; 		/**< The number of channels in the image. 
										 For example, if an RGB image without alpha channels 
										 is being returned, this field should be set to 3. 
										 The plug-in should set this field in the 
										 @ref formatSelectorReadStart handler. Photoshop sets this field 
										 before it calls @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. \n\n
										 Because of the implementation of the plane map, Format and 
										 Import modules should never try to work with more than 16 
										 planes at a time. Doing so yields unpredictable results. */

	Fixed				imageHRes;		/**< The horizontal resolution of the image in terms
										 of pixels per inch. This is a fixed point 
										 number (16 binary digits). Photoshop initializes this field 
										 to 72 pixels per inch. The plug-in should set this field 
										 in the @ref formatSelectorReadStart handler. Photoshop sets 
										 this field before it calls @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. */
	Fixed				imageVRes;		/**< The vertical resolution of the image in terms
										 of pixels per inch. This is a fixed point 
										 number (16 binary digits). Photoshop initializes this field 
										 to 72 pixels per inch. The plug-in should set this field 
										 in the @ref formatSelectorReadStart handler. Photoshop sets 
										 this field before it calls @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. \n\n 
										 @note The current version of Photoshop only supports square pixels, 
										 so it ignores the \c imageVRes field. Plug-ins should set both 
										 \c imageHRes and \c imageVRes anyway in case future versions 
										 of Photoshop support non-square pixels. */

	LookUpTable			redLUT; 		/**< The image's red color table. If an indexed color mode 
										 image is being returned, the plug-in should set this field
										 in the @ref formatSelectorReadStart handler. If an indexed 
										 color document is being written, Photoshop sets these fields 
										 before it calls @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. */
	LookUpTable			greenLUT;		/**< The image's green color table. If an indexed color mode 
										 image is being returned, the plug-in should set this field
										 in the @ref formatSelectorReadStart handler. If an indexed 
										 color document is being written, Photoshop sets these fields 
										 before it calls @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. */
	LookUpTable			blueLUT;		/**< The image's blue color table. If an indexed color mode 
										 image is being returned, the plug-in should set this field
										 in the @ref formatSelectorReadStart handler. If an indexed 
										 color document is being written, Photoshop sets these fields 
										 before it calls @ref formatSelectorOptionsStart, 
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. */

	void *				data;			/**< The buffer where image data is or will be stored.
										 The plug-in should return a pointer to this buffer in the
										 start and continue handlers. After the entire image has 
										 been processed, the continue selector handlers should set 
										 this field to NULL. \n\n The plug-in is responsible for 
										 freeing any memory pointed to by this field. */

	Rect				theRect;		/**< \deprecated Use \c FormatRecord::theRect32.
	                                     */
	int16				loPlane;		/**< The first plane covered by the buffer specified 
										 in @ref data.
										 The start and continue selector handlers should set this 
										 field. For example, if interleaved RGB data is being 
										 used, it should be set to 0. */
	int16				hiPlane;		/**< The first and last planes covered by the buffer specified 
										 in \c FormatRecord::data.
										 The start and continue selector handlers should set this 
										 field. For example, if interleaved RGB data is being 
										 used, it should be set to 2. */
	int16				colBytes;		/**< The offset in bytes between columns of data in the buffer.
										 The start and continue selector handlers should set this field. 
										 This is usually 1 for non-interleaved data, or 
										 \c hiPlane-loPlane+1 for interleaved data.*/
	int32				rowBytes;		/**< The offset in bytes between rows of data in the buffer.
										 The start and continue selector handlers should set this field. */
	int32				planeBytes; 	/**< The offset in bytes between planes of data in the buffers.
										 The start and continue selector handlers should set this field. 
										 This field is ignored if \c loPlane=hiPlane. It should be set to 
										 1 for interleaved data. */	 

	PlaneMap			planeMap;		/**< Maps plug-in plane (channel) numbers to host plane numbers.
										 The host initializes it to a linear map:  
									     \c planeMap[i]=i. The plug-in may change this mapping if
										 it sees the data in a different order. 
										 \n\n For example, Photoshop stores RGB images with an 
										 alpha channel in the order RGBA,  whereas most frame buffers 
										 store the data in ARGB order. To  work with the data in this 
										 order, the plug-in should set \c planeMap[0]=3, 
										 \c  planeMap[1]=0, \c planeMap[2]=1, 
									     and \c planeMap[3]=2.  */

	Boolean 			canTranspose;	/**< Indicates whether the host supports transposing images 
										 during or after reading or before or during writing. When
										 TRUE, the host supports transposing. Photoshop always sets 
										 this field to TRUE. */
	Boolean 			needTranspose;	/**< Indicates whether the plug-in needs the image transposed.
									     Initialized by the host to FALSE. If the plug-in wishes 
										 to transpose the image, and \c canTranspose=TRUE, it should 
										 set this field to TRUE in the start selector handlers. */

	OSType				hostSig;		/**< The signature of the host, provided by the host.
	                                     The signature for Photoshop is signature is 8BIM. */
	HostProc			hostProc;		/**< A pointer to a host-defined callback procedure. 
									     May be NULL. */

   

	int16				hostModes;		/**< The image modes supported by the host. 
										 If the corresponding bit is 1, (where LSB = bit 0), 
										 the mode is supported. This field can be used by plug-ins to 
										 disable reading unsupported file formats. 
										 See @ref ImageModes for supported current modes. */

	Handle				revertInfo; 	/**< Information kept with the document for reverting or
										 saving; where possible this handle should be used to
										 avoid bringing up an options dialog.
										 Photoshop sets this field  to NULL when a format 
										 for a file is first created. If this field is defined on a 
										 @ref formatSelectorReadStart call, then treat the call as a 
										 revert and do not query the user. If it is NULL on the 
										 \c formatSelectorReadStart call, then query the user as 
										 appropriate and set up this field to store a handle 
										 containing the information necessary to read the file 
										 without querying the user for additional parameters 
										 (essential for reverting the file) and if possible to 
										 write the file without querying the user. The contents of 
										 this field are sticky to a document and are duplicated 
										 when we duplicate the image format information for a document. 
										 On all options selector calls, make sure 
										 \c revertInfo contains enough information to revert the 
										 document.\n\n
										 Photoshop disposes of this field when it disposes of the 
										 document, hence, the plug-in must call on Photoshop to 
										 allocate the data as well using the \c FormatRecord::hostNewHdl and 
										 \c FormatRecord::hostDisposeHdl callbacks or 
										 the callbacks provided in the @ref PicaHandleSuite.*/

	NewPIHandleProc		hostNewHdl; 	/**< A pointer to the \c NewPIHandleProc callback. */
	DisposePIHandleProc	hostDisposeHdl;	/**< A pointer to the \c DisposePIHandleProc callback. */
	
	Handle				imageRsrcData;	/**< A handle to a block of data to be stored in the file as 
										 image resource data.  
										 Photoshop documents can have other properties associated with 
										 them besides pixel data. For example, documents typically 
										 contain page setup information and pen tool paths. \n\n
										 Photoshop supports this through a block of data known as the 
										 image resources for a file. Format plug-in modules can store 
										 and retrieve this information if the file format definition 
										 allows for a place to put such an arbitrary block of data 
										 (e.g., a TIFF tag or a PicComment).\n\n
										 Since this handle is allocated before 
										 the write sequence of selector calls begins, plug-ins must 
										 add any resources they want saved to the document during 
										 the options or estimate sequences. Since Photoshop does not
										 always call the @ref PGWriteOptionsSequence "options sequence",
										 the best time to add resources is during the 
										 @ref PGWriteEstimateSequence "estimate  sequence". This field 
										 is checked after each call to formatSelectorRead and 
										 formatSelectorContinue.
										 As soon as this field is not NULL, Photoshop parses the handle as a 
										 block of image resource data for the current document.	 */
	int32				imageRsrcSize;	/**< The size of the handle \c imageRsrcData. It is 
										 only relevant during the estimate sequence when 
										 it is provided instead of the actual resource data. */

	PlugInMonitor		monitor;		/**< Monitor setup information for the host. */

	void *				platformData;	/**< A pointer to platform specific data. 
	                                     Not used under Mac OS. See PlatformData in PITypes.h. */

	BufferProcs *		bufferProcs;	/**< A pointer to the Buffer suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See @ref BufferSuite. */

										
	ResourceProcs *		resourceProcs;	/**< A pointer to the Pseudo-Resource suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See @ref ResourceSuite. */

	ProcessEventProc	processEvent;	/**< A pointer to the \c ProcessEventProc callback 
	                                     if it is supported by the host, otherwise NULL. */
	
	DisplayPixelsProc	displayPixels;	/**< A pointer to the \c DisplayPixelsProc callback 
	                                     if it is supported by the host, otherwise NULL.  */

	HandleProcs			*handleProcs;	/**< A pointer to the Handle callback suite 
	                                     if it is supported by the host, otherwise NULL.  
	                                     See @ref HandleSuite. */
	
	///@name New in 3.0
	//@{
	OSType				fileType;		/**< file type for filtering */
	
	ColorServicesProc	colorServices;  /**< A pointer to the ColorServices callback 
	                                     if it is supported by the host, otherwise NULL. */
	
	AdvanceStateProc	advanceState;	/**< A pointer to the \c AdvanceState callback. 
										 Valid from continue selector handlers. The \c advanceState 
										 callback allows you to drive the interaction through the inner 
										 @ref formatSelectorOptionsContinue loop without actually returning 
										 from the plug-in. If it returns an error, then the plug-in 
										 generally should treat this as an error 
										 @ref formatSelectorOptionsContinue and pass it on when 
										 it returns. */
	//@}
	///@name New in 3.0.4
	//@{
	PropertyProcs		*propertyProcs; /**< Property callback suite. The plug-in needs to
									     dispose of the handle returned for	complex properties. The 
									     plug-in also maintains ownership of handles for
										 set properties. */
	
	ImageServicesProcs	*imageServicesProcs;
										/**< Image Services callback suite. */
	
	int16				tileWidth;		/**< The width of the tiles provided by the host. This
										 is the best unit to work with, if possible. Zero if not set. */
	int16				tileHeight;		/**< The height of the tiles provided by the host. This
										 is the best unit to work with, if possible. Zero if not set. */
	
	Point				tileOrigin;		/**< The origin point of the tiling system. */
	//@}
	///@name New in 4.0 
	//@{
	PIDescriptorParameters	*descriptorParameters;	/**< Descriptor callback suite.  */
	Str255					*errorString;			/**< An error reporting string to return to Photoshop.
	                                                 If the plug-in returns with result=errReportString then 
	                                                 this string is displayed as: 
	                                                 "Cannot complete operation because " + \c errorString. */
	//@}
	///@name New in 5.0 
	//@{
	int32				maxValue;		/**< Used for read with 16-bit depth only. */
	SPBasicSuite		*sSPBasic;		/**< PICA basic suite.  Provides the mechanism to access 
										 all PICA suites. */
	void				*plugInRef;		/**< Plug-in reference used by PICA. */
	
	int32				transparentIndex;	/**< If IndexedColor, and < 256, this is the index of the 
											 transparent color (for GIF). */
	
	Handle				iCCprofileData;	/**< Handle containing the ICC profile for the image;  
										 NULL if none. \n
										 For reads: \n
										 The handle must be allocated using the Photoshop handle suite.
										 Photoshop uses the data after the Finish call
										 and then frees the handle.\n
										 For writes: \n
										 Photoshop allocates the handle using Photoshop's handle suite
										 The handle is unlocked while calling the plug-in
										 The handle is valid from Start to Finish
										 Photoshop frees the handle after Finish. */

	int32				iCCprofileSize;		/**< Size of \c iCCprofileData. */
	
	int32				canUseICCProfiles; /**< Indicates if the host uses ICC Profiles. Non-zero if 
											the host can accept or export ICC profiles.
											If this is zero, don't set or dereference 
											\c iCCprofileData. */

	//@}
	///@name New in 5.5 
	//@{
	int32			lutCount;			/**< Number of entries in the indexed color table. This 
									     should include the transparent index if any. Plug-ins 
									     should pad out the color table with black for backward 
									     compatibility.	*/
	//@}
	///@name New in 6.0 
	//@{
	/* The following fields are only relevant when reading. */
	
	int32			preferredColorModes;/**< A bitmask indicating which color modes are preferred by the host
										 This will be zero if not set. The plug-in is free to ignore the
										 hint (though it is wise to obey the @ref hostModes information).
										 This is an int32 rather than an int16 to allow for
										 future expansion. */
										   
	int32			convertMode;		/**< Indicates whether the host supports conversion after reading; 
										 0 if it does not, -1 if it does. The plug-in can set this field
										 to the index of a color mode and this is treated by the host
										 as a request to automatically convert to that mode. Hosts can
										 ignore this request but they will make the host+plug-in combination
										 appear broken. */

	VPoint			preferredSize;		/**< The preferred size for the image; 0,0 if not set. 
										 This is a hint about how big an image the wants. 
										 This field uses 32-bit coordinates rather than
										 16-bit coordinates, to allow for future expansion. */

	int32			imageIndex;			/**< The index of the image; 0 if not set. One indicates the 
										 first image, etc. Currently only used for PDF Image extractor. */
										   
	int32			transparencyPlane;	/**< Index of the plane containing transparency information.
										 When writing files: \n
										 Set to zero by hosts that do not support transparency or there 
										 is no transparency. Set to the index of the plane containing
										 transparency information if the host does support transparency.
										 Any alpha channels after this index are pushed down by one.
										 The interpretation of zero is chosen for compatibility
										 with old hosts, but it also means that the transparency plane
										 is never the first plane. \n
										 When reading files:\n
										 This is set to zero by hosts that do not support transparency.
										 This is set to -1 by hosts that support transparency. The
										 plug-in should set it to the index of the plane containing
										 transparency information if there is one. */
										  	
	int32			transparencyMatting;/**< Transparency matting information; 0: no matte, 1: black matte, 
										 2: gray matte, 3: white matte	
										 When reading files, indicates how the transparency data should 
										 be interpreted	with respect to color matting.\n 
										 When writing, set by the plug-in to indicate whether 
										 the host should be premultiplied with a chosen color. The default 
										 value is no matting (unassociated). */
	//@}
	///@name New in 7.0 
	//@{
	ChannelPortProcs *channelPortProcs;	/**< Suite for passing pixels through channel ports. */
			
	ReadImageDocumentDesc *documentInfo;/**< The document info for the document being written. */


	Boolean			openForPreview;		/**< Indicates whether the document is open for preview.  Set by 
										 the host, the plug-in should make the smallest previewable 
										 size if it can. */

	//@}
	///@name New in 8.0 
	//@{
	int32			browserRotation;	/**< Rotation or flip applied to the image.
										 When reading files, this field lets the plug-in know what
										 rotation and/or flip is applied to the image after
										 opening. This lets the plug-in display any preview images
										 correctly.  Lowest two bits are number of 90 degree CW
										 rotations.  See @ref BrowserRotationFlags for other flags.
										 This field is also used when requesting a value for the 
										 @ref PIFmtPRotate property and when
										 calling the @ref formatSelectorLosslessRotate selector. */
	
	int32		HostSupports32BitCoordinates;	/**< Indicates whether the host supports 32 bit plug-in 
												 API. */
	
	int32		PluginUsing32BitCoordinates;	/**< Indicates whether the plug-in is using the 32-bit fields;
											     set to nonzero by the plug-in if it is. */
	
	VPoint		imageSize32;			/**< Size of image in 32 bit coordinates, 
										 replaces \c FormatRecord::imageSize.
										 The plug-in should 
										 should set this field in the @ref formatSelectorReadStart 
										 handler to inform Photoshop of the width and height of the image in pixels. 
										 Photoshop sets this field before it calls 
										 @ref formatSelectorOptionsStart,
										 @ref formatSelectorEstimateStart, or 
										 @ref formatSelectorWriteStart. */
	
	VRect		theRect32;				/**< Rectangle being returned in 32 bit coordinates, 
										 replaces \c FormatRecord::theRect. 
										 The area of the image covered by the buffer specified 
										 in \c FormatRecord::data. The plug-in should set this field. */
											
	uint32		requestedFileProperty;	/**< Set to a valid format file property to request 
										 the value for that property. */

	uint32		filePropertyValue;		/**< The requested property value is returned in this field. 
		 									 See @ref requestedFileProperty. */
	
	uint32		fileCount;				/**< Count of files for bulk settings selector.
                                             If the bulkMask has the PIFmtBulkModifyListMask
                                             bit set, then this field is read/write.  Otherwise
                                             it is read only. */

	Handle		xmp;					/**< XMP handle for read and write, only valid when using 
										 @ref formatSelectorXMPRead and @ref formatSelectorXMPWrite.
										 @note Use the @ref FormatRecord::propertyProcs and @ref propXMP to read
										 and write the XMP data during normal reads and writes. \n 
										 For reads: \n
										 The handle must be allocated using Photoshop's handle suite.
										 Photoshop uses the data after the call and then
										 frees the handle.
										 For writes: \n
										 Photoshop allocates the handle using its handle suite.
										 The handle is unlocked while calling the plug-in
										 The handle is valid only during \c formatSelectorXMPWrite
										 Photoshop frees the handle. */
												
	int32		supportsSkipFile;		/**< Indicates whether the \c formatSkipFile error code is
									     supported. This error code tells the host to skip this 
									     file when processing multiple files. */

	//@}
	///@name New in 9.0 
	//@{
	Boolean		extractQuickThumbnail;	/**< When this flag is set, Read protocol should return 
										 an extracted thumbnail without reading the entire file. */
										   
	Boolean		hostInSecondaryThread;	/**< Indicates if the host calling this from a non-UI thread.
										 Set to TRUE, if so. */
										
	uint32		bulkMask;				/**< Tells the plug-in which features of the bulkFlags array
										 are supported. See @ref BulkFlags. */
	
	uint32 *	bulkFlags;				/**< Pointer to an array of fileCount 32-bit flags, used 
										 for two way information transfer when using the bulk settings 
										 and bulk open APIs. See @ref BulkFlags. */
										   
	uint32		presetCount;			/**< Number of settings presets found. */
										   
	Handle		presetNames;			/**< Handle holding array of UTF-8 encoded preset 
									     name handles. */
										   
	Handle		presetData;				/**< Handle holding array of XMP preset data handles. */
	
	uint32		settingsChecksum;		/**< Checksum of raw conversion settings. */
	
	SPPlatformFileSpecificationW *fileSpec2;	/**< Unicode/FSRef replacement for @ref fileSpec. */

	//@}
	///@name New in 10.0 
	//@{
	uint32			layerData;			/**< On read:
												Set by plugin in Start to tell host how many layers are in the document.
												Set by the host prior to calling ReadLayerStart to tell the plugin which layer it is requesting data for. 
												   
												On write:
												Set by host prior to calling Start to tell plugin how many layers are in the document.
												Set by the host prior to calling WriteLayerStart to tell the plugin which layer it is sending data for. 
										*/
												
	uint16			*layerName;			/**< A utf16 encoded string that contains the name of the layer 
											 On read, this should be set by the plugin before leaving ReadLayerFinish
										     On write, this will be set by the host before calling WriteLayerStart
										*/
	
	void			*renderRecord;		/**< Data for Plugin Rendered Layers */
	
	Handle *		bulkParams;			/**< Pointer to an array of handles used to pass parameter blocks
											 between the bulk settings and bulk open calls and the
											 corresponding open calls.
												   
											 Before calling the bulk settings or bulk open call, the host
											 should initialize this field to a pointer to a list of
											 "fileCount" NULL Handles.
												   
											 During the bulk settings or bulk open call, if the plug-in
											 decides to request that a file be opened it may allocate a
											 handle to hold some parameters for that file, and
											 set the bulkParams array entry to that handle.
												   
											 When the host then opens the requested files using open calls,
											 it should pass back the parameter block in this same file.
											 (Since only open file is being opened at a time, this is just
											 a pointer to a single handle during this phase).
										
											 The host is required to free all the parameter block handles.
										*/
										
	Boolean openAsSmartObject;			/**<  Set this to true and the new document will be placed as a smart object */
										
	//@}
	///@name New in 11.0 
	//@{

	PIDescriptorParameters	*layerMetaData;		/**<  For per-layer meta data */
											   
	uint16 *finalSpec;					/**< A utf16 encoded string that contains the location of the final file. Use this for reference only. 
											 This will give you the parent folder and the name of the final file. 
											 Read and write via the @ref fileSpec2 only and not this value. */

	Boolean isTextLayer;				/**< On read: Set by plug-in to indiate that this layer is a text layer, plug-in must also set @ref textDescriptor
											 On write: Set by host to indiate that this layer is a text layer, host must also set @ref textDescriptor */

	PIDescriptorHandle	*textDescriptor; /**< On read: Set by plug-in to describe the text, only valid if @ref isTextLayer is true
											  On write: Set by host to describe the text, only valid if @ref isTextLayer is true*/

	Boolean isGroupDivider;				/**< On read: Set by plug-in to tell that this is a divider
											 On write: Set by host to indicate that this is a group divider
											 If true the type is either start or end, see @ref isGroupStart */

	Boolean	isGroupStart;				/**< On read: Set by plug-in to tell that this is a group start layer (true) or end (false)
											 On write: Set by host to indicate that this is a group start layer (true) or end (false)
											 Only valid if isGroupDivider is true */ 

	Boolean	isVisible;				/**< On read: Set by plug-in to tell that this is a visible layer
											 On write: Set by host to indicate that this is a visible layer */ 

	Boolean	isLocked;				/**< On read: Set by plug-in to tell that this is a locked layer
											 On write: Set by host to indicate that this is a locked layer */ 

	PIType	blendMode;					/**< Layer blend mode, as 4 character keys. */

	unsigned8 opacity;					/**< Layer opacity; range from 0 to 255, where opaque = 255. */
    
	//@}
	///@name New in 15.0
	//@{

    Handle bulkExtraData;               /**< Handle that may be allocated by bulkSettings/blukOpen call.  Should be
                                             freed by host after processing the bulk results. */

	//@}
	///@name New in 17.0
	//@{
	XPlatFileSpec*	fileSpecX;			/**< Unicode, cross-platform-friendly file specification
											This is an array when using the @ref formatSelectorBulkSettings. */

	//@}
	///@name New in 20.0
	//@{
	int16		hostSupportsPOSIXIO;	/**< Indicates whether the host supports POSIX file IO plug-in API. */

	int16		pluginUsingPOSIXIO;     /**< Indicates whether the plug-in is using the POSIX file IO fields;
	                                         set to nonzero by the plug-in if it is. */
 
	int32		posixFileDescriptor;    /**< POSIX file descriptor from an open call by Photoshop;
	                                         for reading and writing. */
 
	//@}
	///@name Reserved Space for Expansion
	//@{

	char		reserved [50]; 					/**< Reserved for future use. Set to zero. */

	//@}

	}
FormatRecord, *FormatRecordPtr;

#if WIN32
#pragma pack(pop)
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

#endif  // __PIFormat_h__
