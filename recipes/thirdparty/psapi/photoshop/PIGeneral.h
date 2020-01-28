// ADOBE SYSTEMS INCORPORATED
// (c) Copyright  1991 - 2007 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 *	\file PIGeneral.h
 *
 *	\brief This file contains the public definitions and structures
 *		used by all plug-ins.
 *
 *	Distribution:
 *		PUBLIC
 *
 *	\details
 *		This file must be included to correctly compile resources
 *		on Windows; it is included by all the plug-in headers.
 *
 */

/**
 * @page BuildInfo Details of tools used to build Photoshop and the SDK examples
 * It is recommended that third party developers use the same tools
 * that we use to build Photoshop. Below is the information regarding the
 * Windows and Macintosh platforms. This is also noted in the What's New section
 * of the Photoshop SDK HTML documentation
 *
 * \section Photoshop20 Photoshop 20.0 - CC 2019
 *
 * Windows was built on a Windows 7 64 bit SP 1 machine
 * using the 64 bit tool chain and the following version:
 * Microsoft Visual Studio 2017 
 * Version 15.6.2
 * Windows 10 SDK version 10.0.16299.0
 *
 * OS X was built on an OS X 10.13.3 machine
 * Using Xcode 9.2 (9C40b), Base SDK 10.13, OS X Deployment Target of 10.12
 *
 *
 * \section Photoshop19 Photoshop 19.0 - CC 2018
 *
 * Windows was built on a Windows 7 64 bit SP 1 machine
 * using the 64 bit tool chain and the following version:
 * Microsoft Visual Studio 2015 
 * Version 14.0.25420.1 Update 3
 * Windows 10 SDK version 10.0.15063.0
 *
 * OS X was built on an OS X 10.11.6 machine
 * Using Xcode 8.2.1 (8C1002), Base SDK 10.12, OS X Deployment Target of 10.11
 *
 *
 * \section Photoshop18 Photoshop 18.0 - CC 2017
 *
 * Windows was built on a Windows 7 64 bit SP 1 machine
 * using the 64 bit tool chain and the following version:
 * Microsoft Visual Studio 2015
 * Version 14.0.24720.0. Update 3
 *
 * OS X was built on an OS X 10.10.5 machine
 * Using Xcode 7.2.1 (7C1002), Base SDK 10.11, OS X Deployment Target of 10.10
 *
 *
 * \section Photoshop17 Photoshop 17.0 - CC 2015.5
 * 
 * Windows was built on a Windows 7 64 bit SP 1 machine 
 * using the 64 bit tool chain and the following version:
 * Microsoft Visual Studio 2015 
 * Version 14.0.25123.0. Update 2
 * 
 * OS X was built on an OS X 10.10.5 machine 
 * Using Xcode 7.2.1 (7C1002), Base SDK 10.11, OS X Deployment Target of 10.9
 * 
 * 
 * \section Photoshop16 Photoshop 16.0 - CC 2015
 * 
 * Windows was built on a Windows 7 64 bit SP 1 machine 
 * using the 64 bit tool chain and the following version:
 * Microsoft Visual Studio Ultimate 2013
 * Version 12.0.31101.00 Update 4
 * 
 * OS X was built on an OS X 10.8.5 machine 
 * Using Xcode 5.0.2, SDK 10.9, min target of 10.9
 * OS X 10.10.3 and Xcode 6.1.1 can also be used as an alternative
 * 
 * 
 * \section Photoshop15 Photoshop 15.0 - CC 2014
 * 
 * Microsoft Visual Studio 2012, Update 4, 32 and 64 bit builds.
 * 
 * Xcode Version 4.6, Base SDK 10.7, Apple LLVM compiler 4.2, 
 * OS X Deployment Target 10.6, 64 bit only builds.
 * 
 * 
 * \section Photoshop14 Photoshop 14.0 - CC
 * 
 * Microsoft Visual Studio 2010 with Service Pack 1, 32 and 64 bit builds.
 * 
 * Xcode Version 4.6, Base SDK 10.7, Apple LLVM compiler 4.2, 
 * OS X Deployment Target 10.6, 64 bit only builds.
 * 
 *
 * \section Photoshop13 Photoshop 13.0 - CS6
 * 
 * Microsoft Visual Studio 2010 with Service Pack 1, 32 and 64 bit builds.
 * 
 *  Xcode Version 3.2.5, GCC 4.2, SDK 10.6, 64 bit only builds
 *
 */

#ifndef __PIGeneral_h__
#define __PIGeneral_h__

#pragma once

// application specific
#include "PITypes.h"
#include "PIResDefines.h"
#include "SPFiles.h"	// SPPlatformFileSpecificationW and XPlatFileSpec

#ifdef __PSWorld__
#include "UGeometry.h"
#include "PSWorldEnums.h"
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

//-------------------------------------------------------------------------------
//	Defines -- Photoshop signature -- '8BIM'
//-------------------------------------------------------------------------------

/** The Photoshop signature, '8BIM' */
#define kPhotoshopSignature		0x3842494d

//-------------------------------------------------------------------------------
//	Defines -- General plug-in error codes.
//-------------------------------------------------------------------------------

///@name General Error Codes
//@{

/** Indicates that the plug-in requires services not provided by this host. */
#define errPlugInHostInsufficient			-30900

/** Indicates that a requested property could not be found. */
#define errPlugInPropertyUndefined			-30901

/**
* Indicates that an image processing operation does not support colBytes values
* other than 1. Message is "The plug-in requires services not provided by this host."
*/
#define errHostDoesNotSupportColStep		-30902

/**
* For the Color Services callback, during the operation plugIncolorServicesSamplePoint,
* indicates that the is not in the image window.
*/
#define errInvalidSamplePoint				-30903
		 
/**	
* When a plug-in returns with \c result=errReportString, the
* host reports the \c errorString value from the plug-in's parameter block.
*/
#define errReportString						-30904

/* New in 8.0 */

/**	
* Indicates that the plug-in is not compatible with this version of Photoshop.
* (Version 8.0+)
*/
#define errHostVersionIncompatible			-30905
//@}

//-------------------------------------------------------------------------------
//	Defines -- Channel Port error codes.
//-------------------------------------------------------------------------------

///@name Channel Port Error Codes
//@{
#define errUnknownPort						-30910	  /**< Unknown Channel Port. */

#define errUnsupportedRowBits				-30911	  /**< Host does not support value provided in 
										                   @ref PixelMemoryDesc::rowBits. */

#define errUnsupportedColBits				-30912	  /**< Host does not support value provided in 
										                   @ref PixelMemoryDesc::colBits. */

#define errUnsupportedBitOffset				-30913	  /**< Host does not support value provided in 
										                   @ref PixelMemoryDesc::bitOffset. */

#define errUnsupportedDepth					-30914	  /**< Host does not support value provided in 
										                   @ref PixelMemoryDesc::depth. */

#define errUnsupportedDepthConversion 		-30915	  /**< Host does not provide conversion for the depth
														   provided in @ref PixelMemoryDesc::depth. */

//@}
//-------------------------------------------------------------------------------
//	Defines -- Scripting system error codes.
//-------------------------------------------------------------------------------

///@name Scripting System Error Code
//@{

#define errWrongPlatformFilePath	 		-30916	/**< Alias Handle is invalid */

#define errIllegalCharInID					-30917	/**< Non-alphanum in key, class, etc. */

#define errMissingParameter					-1715	/**< A requierd parameter is missing, same as errAEParamMissed */

//@}
//-------------------------------------------------------------------------------
//
//	General PiPL Properties
//
//  These properties are also defined by Suite Pea, so we must bracket their
//	definition to make sure they are only defined once.
//
//-------------------------------------------------------------------------------


#ifndef kGeneralPiPLPropertiesDefined
#define kGeneralPiPLPropertiesDefined  /**< Only define general PiPL properties once. */

/** @defgroup PiPLResources Plug-in Property List Resources
* A Plug-In Property List, called a 'PiPL' (pronounced "pipple") is a flexible, extensible 
* data structure for representing metadata for a plug-in module.
* PiPLs contain all the information Photoshop needs to identify and load plug-in modules, 
* as well as flags and other static properties that control the operation of each plug-in. 
* This information includes indicators about the types and locations of available code,
* versions, and other dependencies of the plug-in.	\n\n
* If a plug-in needs to examine the elements of another plug-in�s PiPL for some reason or 
* find a particular property, it should use the functions in PICA Property Suite,
* \c SPPropertiesSuite, rather than repeatedly parsing the plug-ins property resource. 
* Use  \c SPPropertiesSuite::FindProperty() to
* determine whether a PiPL contains a particular property, and return a reference to
* it if it does. Use  \c SPPropertiesSuite::GetPropertyPIProperty() to return the property's
* \c PIProperty structure, which contains the data for the property.
* See the <a href="../PICA.pdf">Adobe PICA API</a> for further information about the 
* PICA Property Suite.	\n\n
* Your plug-in module should contain one or more 'PiPL' structures.	\n\n
* See also @ref PiPLKeys "PiPL Keys", and @ref PiPLSyntax "Photoshop PiPL Syntax".
*/


typedef uint32 PIType; 	/**< A property type signature or key. This original came from OSType on the Mac. */

//-------------------------------------------------------------------------------
//	Defines -- Current PiPL version and code descriptor properties.
//-------------------------------------------------------------------------------

/// Current Plug-in Property List version
#define kCurrentPiPLVersion 	0


/** 
* @page PiPLKeys Property Keys for PiPL Resources 
* The PiPL keys are used in conjunction with the @ref PIProperty data structure.
* The keys are separated into categories depending on which type of plug-ins can 
* use them.
* - @ref PiPLGeneralKeys
* - @ref PiPLCodeDescriptorKeys
* - @ref PiPLColorPickerKeys
* - @ref PiPLExportKeys
* - @ref PiPLFilterKeys
* - @ref PiPLFormatKeys
* - @ref PiPLScriptingKeys
* - @ref PiPLActionKeys
* - @ref PiPLStackRendererKeys
*/

/** @defgroup PiPLGeneralKeys General PiPL Properties
* These PiPL properties are common to all types of plug-in modules.
* 
* @defgroup PiPLCodeDescriptorKeys Code Descriptor PiPL Properties
* Code descriptors tell Photoshop the type and location of a plug-in�s code. More 
* than one code descriptor may be included to build a "fat" plug-in which will run 
* on different types of machines. Photoshop selects the best performing option. 
* Photoshop makes sure that the callback structure is filled in with appropriate 
* functions for the type of code that is loaded. So for PowerPC code, native function 
* pointers will be provided and routine descriptor operations are not required either 
* in calling the plug-in or for the plug-in to invoke Photoshop callback functions.
* @note In Windows, the CNVTPIPL.EXE utility only recognizes Windows specific properties.
* It ignores all MAC OS specific properties described in this section.
*
* @defgroup PiPLColorPickerKeys Color Picker PiPL Properties
* For more information, see @ref PiPLKeys "Property Keys for PiPL Resources".
*
* @defgroup PiPLExportKeys Export Module PiPL Properties
* This PiPL property is only applicable to Export plug-in modules. 
*
* @defgroup PiPLFilterKeys Filter Modules PiPL Properties
* This PiPL property is only applicable to Filter plug-in modules. 
* For more information, see @ref PiPLKeys "Property Keys for PiPL Resources".
*
* @defgroup PiPLActionKeys Automation Module PiPl Properties
* These PiPL properties are applicable for Automation plug-ins.
*/

///@ingroup PiPLGeneralKeys
/** Type or kind of plug-in; key value is 'kind'. 
* This property key reflects the \c Kind property in the PiPL resource file.
* The property data has type @ref PIType, with expected values as follows:
* - 'ARPI'=Adobe Illustrator
* - 'SPEA'=Adobe Suite Pea
* - '8BXM'=Accelerator extension
* - '8BAM'=Import module
* - '8BEM'=Export module
* - '8BFM'=Filter module
* - '8BIF'=Format module
* - '8BSM'=Selection module
* '- 8BYM'=Parser module
*/
#define PIKindProperty			0x6b696e64L

// \deprecated
// 'm68k' \<PI68KCodeDesc\> 68k code descriptor. See struct below.
// #define PI68KCodeProperty		0x6d36386bL


// \deprecated
// This property key reflects the \c CodePowerPC property in the PiPL resource file. 
// See PIPowerPCMachOCodeProperty, PICodeMacIntel32Property, PICodeMacIntel64Property
#define PIPowerPCCodeProperty	0x70777063L

// \deprecated
// This property key reflects the \c CodeCarbonPowerPC property in the PiPL resource file. 
#define PIPowerPCCarbonCodeProperty	'ppcb'

///@ingroup PiPLCodeDescriptorKeys
// 'mach' \<PIMachOCodeDesc\> PowerPC Mach-O code descriptor. 
/**	PowerPC Mach-O code descriptor. Key is 'mach'. 
* This property key reflects the \c CodeMachOPowerPC property in the PiPL resource file. 
* The property data has type @ref PIMachOCodeDesc.
*/
#define PIPowerPCMachOCodeProperty	'mach'

// 'mi32' <PIMacIntelCodeDesc> Intel 32 Mach-O code descriptor. See struct below.
#define PICodeMacIntel32Property	'mi32'

// 'mi64' <PIMacIntelCodeDesc> Intel 64 Mach-O code descriptor. See struct below.
#define PICodeMacIntel64Property	'mi64'

///@ingroup PiPLCodeDescriptorKeys
// 'frag' \<PIFragmentCodeDesc\> PowerPC fragment descriptor.
/**	PowerPC fragment descriptor. Key is 'frag'. 
* This property key reflects the \c CodeFragmentPPC property in the PiPL resource file. 
* The property data has type @ref PIFragmentCodeDesc.
*/
#define PICodeFragmentProperty	'frag'

///@ingroup PiPLCodeDescriptorKeys
// 'frgc' \<PIFragmentCodeDesc\> PowerPC CARBON fragment descriptor. 
/**	PowerPC CARBON fragment descriptor. Key is 'frgc'. 
* This property key reflects the \c CodeFragmentCarbonPPC property in the PiPL resource file. 
* The property data has type @ref PIFragmentCodeDesc.
*/
#define PICarbonCodeFragmentProperty	'frgc'

// '8664' <PIWin64X86CodeDesc> Win32 Intel code descriptor. See struct below.
#define PIWin64X86CodeProperty  0x38363634L

// 'wx86' <PIWin32X86CodeDesc> Win32 Intel code descriptor. See struct below.
#define PIWin32X86CodeProperty  0x77783836L

// \deprecated 'fx86' <PIWin16X86CodeDesc> Win16 Intel code descriptor. See struct below.
#define PIWin16X86CodeProperty  0x66783836L

//-------------------------------------------------------------------------------
//	Structures -- PiPL entry definition.
//-------------------------------------------------------------------------------
///@ingroup PiPLResources
/** Definition of a PiPL property. Plug-in property structures (or properties) are 
* the basic units of information stored in a property list. Properties are variable 
* length data structures, which are uniquely identified by a vendor code, property key, 
* and ID number. PiPL properties are stored in a list.  See \c PIPropertyList.
*/ 
typedef struct PIProperty
{
	/** The vendor defining this property type. This allows vendors to define
	* their own properties in a way that does not conflict with either Adobe or other 
	* vendors. It is recommended that a registered application creator code be used 
	* for the vendorID to ensure uniqueness. All Photoshop properties use the vendorID 
	* '8BIM'.
	*/
	PIType vendorID;
	
	/// Identification key for this property type. See @ref PiPLKeys "Property Keys".
	PIType propertyKey;
	
	/// Index within this property type. Must be unique for properties of
	/// a given type in a PiPL.
	int32  propertyID;
	
	/// Length of propertyData. Does not include any padding bytes 
	/// to achieve four byte alignment. May be zero. 
	int32  propertyLength;
	
	/// Variable length field containing contents of this property. 
	/// Any values may be contained. Must be padded to achieve four 
	/// byte alignment.
	char   propertyData [1];

} PIProperty;

///@ingroup PiPLResources
/** The plug-in property list structure has a version number 
* and a count followed by one or more property structures. 
* A \c PIPropertyList is accessed using the PICA Property 
* Suite: \c SPPropertiesSuite, described in
* <a href="../PICA.pdf">The Adobe PICA API</a>.
*/
typedef struct PIPropertyList
{
	/// Properties data structure version number.
	int32 version;

	/// Number of properties in this property list.
	int32 count;

	/// A variable length array of property data structures.	
	PIProperty properties[1];

} PIPropertyList;

//-------------------------------------------------------------------------------
//
//	Structures -- PiPL types.
//
//	Below are structures describing types used in plug-in property lists.
//	These structures obey Macintosh 68k alignment and padding rules though
//	generally they are laid out so fields have natural alignment and any
//	needed padding is explicit in the structure.
//
//	In addition to these structure types, simple types such as int32, int16,
//	etc. are used. Two other examples are PString and FlagSet.
//
//	PString is like a rez pstring or a Str255 except that storage may not
//  be present for all 255 characters.  The initial length byte is present
//  in the property.
//
//	FlagSet is a variable length bitstring in which the first member is
//	represented by the most significant bit of the first byte, the eighth
//	member is in the least significant bit of the first byte, etc.
//  The length of the set is in the property's length field.
//
//	Arrays are also used in places with bounds either taken from the
//	property length or explicitly represented within the property.
//
//-------------------------------------------------------------------------------

/// Structure for 'm68k' PI68kCodeProperty \deprecated
typedef struct PI68KCodeDesc
{
	/// Location of the 68k executable code. A 4-character OSType, usually
	/// the plug-in type.  For instance, a Filter module's 68k code is
	/// usually compiled into its '8BFM' resource.
	PIType fType;

	/// Resource number where the code can be found.
	int16 fID;

} PI68KCodeDesc;

/// Structure for 'pwpc' @ref PIPowerPCCodeProperty, and 'ppcb' @ref PIPowerPCCarbonCodeProperty.
typedef struct PICFMCodeDesc
{
	/// Data fork offset to the code fragment start. This allows more than 
	///one code fragment based plug-in per file.	
	int32 fContainerOffset;
	
	/// Length of the code fragment. If the fragment 
	/// extends to the end of the file or is the only fragment, 
	/// the container length may be 0.
	int32 fContainerLength;
	
	/** Name of entry point. Pascal string used to lookup the address of the function 
	* to call within the fragment. For example, "main", "ENTRYPOINT", "", etc.
	* In order for the Code Fragment Manager to find an 
	* entry point by name, that name must be an exported symbol of the code fragment. 
	* If NULL, the default entry point is used. fEntryName allows a single code 
	* fragment to contain more than one plug-in. 
	*/
	unsigned char fEntryName[1];

} PICFMCodeDesc;

/// Structure for 'mach' @ref PIPowerPCMachOCodeProperty.
typedef struct PIMachOCodeDesc
{
	/// Data fork offset to the code fragment start. This allows more than 
	///one code fragment based plug-in per file.	
	int32 fContainerOffset;
	
	/// Length of the code fragment. If the fragment 
	/// extends to the end of the file or is the only fragment, 
	/// the container length may be 0.
	int32 fContainerLength;
	
	/** Name of entry point. Pascal string used to lookup the address of the function 
	* to call within the fragment. For example, "main", "ENTRYPOINT", "", etc.
	* In order for the Code Fragment Manager to find an 
	* entry point by name, that name must be an exported symbol of the code fragment. 
	* If NULL, the default entry point is used. fEntryName allows a single code 
	* fragment to contain more than one plug-in. 
	*/
	unsigned char fEntryName[1];

} PIMachOCodeDesc;

// For 'mi32' PICodeMacIntel32Property:
// For 'mi64' PICodeMacIntel64Property:
typedef struct PIMacIntelCodeDesc
{

	// Name of entrypoint ("main", "ENTRYPOINT", "", etc.):
	unsigned char fEntryName[1];

} PIMacIntelCodeDesc;

/// Structure for 'frag' @ref PICodeFragmentProperty and 'frgc' @ref PICarbonCodeFragmentProperty.
/// takes precedence over PIPowerPCCodeProperty
typedef struct PIFragmentCodeDesc
{
	/// Resource ID.
	int32 fFragmentResource;
	
	/// Number of the fragment within the resource.
	int32 fFragmentNumber;
	
	/// Name of entry point; for example, "main", "ENTRYPOINT", "", and so forth.
	/// If blank (""), the first entry point in the fragment is used.
	unsigned char fEntryName[1];

} PIFragmentCodeDesc;

/** The entry point name for 64 bit windows, used to lookup the function 
which is called to invoke the plug-in. A \c NULL terminated string, padded 
with additional \ NULL charcters if needed to satisfy the 4-byte alignment
requirement. See @ref PIWin64X86CodeProperty above. */
typedef struct PIWin64X86CodeDesc
{
	char fEntryName[1];
} PIWin64X86CodeDesc;

/** The entry point name for 32 bit windows, used to lookup the function 
which is called to invoke the plug-in. A \c NULL terminated string, padded 
with additional \ NULL charcters if needed to satisfy the 4-byte alignment
requirement. See @ref PIWin32X86CodeProperty above. */
typedef struct PIWin32X86CodeDesc {
	char fEntryName[1];
} PIWin32X86CodeDesc;

/** \deprecated Win16 Intel code descriptor. 
See @ref PIWin16X86CodeProperty above. */
typedef struct PIWin16X86CodeDesc {
	char fEntryName[1];
} PIWin16X86CodeDesc;

#endif // kGeneralPiPLPropertiesDefined

//-------------------------------------------------------------------------------
//
//	Additional General PiPL Properties
//
//	These are properties that don't conflict with Suite Pea and are
//	defined for Photoshop specifically.
//
//-------------------------------------------------------------------------------

///@ingroup PiPLGeneralKeys
// 'vers' \<int32\> Major\<int16\>.Minor\<int16\> version number:
/**
* Major and minor version number indicating which revision of the plug-in interface 
* this plug-in was written for; key value is 'vers'. 
* This property key reflects the \c Version property in the PiPL resource file.
* The major version number indicates incompatible changes while the minor version number 
* indicates incremental enhancements. <br><br>
* The data for the property has type \c int32.
* The major version number is encoded in the most 
* significant 16 bits of the 32 bit version number, the minor version number is encoded 
* in the least significant 16 bits. <br><br>
* There are separate version numbers for each kind of plug-in. The current version for 
* a given kind of plug-in is defined by a preprocessor macro in the header file defining
* the interface for that plug-in type.
*/
#define PIVersionProperty		0x76657273L

///@ingroup PiPLGeneralKeys
// 'prty' \<int32\> Load order priority:
/**
* Plug-in load order; key value is 'prty'. 
* This property key reflects the \c Priority property in the PiPL resource file.
* The data for the property has type \c int32.
* Also used to control the order in which items with the same name 
* show up in menus. Lower numbers (including negative ones) load first. 
* If NULL, the default is zero.
*/
#define PIPriorityProperty		0x70727479L

///@ingroup PiPLGeneralKeys
// 'cmpt' Component/Version ids:
/**
* Component and Version ids; key value is 'cmpt'.
* This property key reflects the \c Component property in the PiPL resource file.
*/
#define PIComponentProperty		0x636d7074L

///@ingroup PiPLGeneralKeys
// 'mode' \<FlagSet\> Image modes supported flags. (bitmask):
/**
* Image modes that the plug-in supports; key value is 'mode'. 
* This property key reflects the \c SupportedModes property in the PiPL resource file.
* The data for the property has type \c FlagSet; a variable length bitstring 
* in which the first member is represented by the most significant bit of the 
* first byte, the eighth member is in the least significant bit of the first byte, etc.
* The length of the set is in the property's length field. <br><br>
* Adobe Photoshop, has 18 modes, see @ref ImageModes. <br><br>
* This property determines whether your plug-in will be active (black) or inactive (gray) 
* in Photoshop�s menus based on the current document�s image mode.
*/
#define PIImageModesProperty	0x6d6f6465L

///@ingroup PiPLGeneralKeys
// 'enbl' \<CString\> Enabling expression:
/**
* A string of modula-like expressions that, upon evaluation, 
* must all be true for the plug-in to be enabled in the menu; key value is 'enbl'. 
* This property key reflects the \c EnableInfo property in the PiPL resource file.
* It is a superset of the \c SupportedModes PiPL property. (See @ref PIImageModesProperty). One set 
* of modes required in \c SupportedModes and a different set required in \c EnableInfo, 
* produces unknown results. \c EnableInfo and \c SupportedModes should always match, 
* in regards to mode requests.  <br><br>
* See @ref EnableInfoGrammar "EnableInfo Property Grammar".
*/
#define PIEnableInfoProperty	0x656e626cL

///@ingroup PiPLGeneralKeys
// 'wnsc' plug in wants scrap
/**
* The plug-in wants the host to export image scrap; key value is 'wnsc'. 
* This property key reflects the \c WantsScrap property in the PiPL resource file.
*/
#define PIWantsScrapProperty	0x776E7363L

///@ingroup PiPLGeneralKeys
// 'coco' plug in has Cocoa, Objective-C code and should never be unloaded
/**
* The plug-in wants the host to keep it loaded as unloading Cocoa plug-ins
* could result in objective-c messages going to no where
* This property key reflects the \c Cocoa property in the PiPL resource file.
*/
#define PICocoaProperty		0x636F636FL

///@ingroup PiPLGeneralKeys
// 'fbaw' plug in wants in the File Browser menu
/**
* The plug-in wants in the File Browser menu; key value is 'fbaw'. 
* This property key reflects the \c FileBrowserAware property in the PiPL resource file.
*/
#define PIFileBrowserAwareProperty	0x66626177L

///@ingroup PiPLGeneralKeys
// 'nabo' plug in does not want an about box menu entry
/**
* The plug-in does not want an about box menu entry; key value is 'nabo'.
* This property key reflects the \c NoAboutBox property in the PiPL resource file.
*/
#define PINoAboutBoxProperty	0x6E61626FL

///@ingroup PiPLGeneralKeys
// 'lFGm' plug in should be hidden/shown by the Preference for legacy Filter Gallery menu entries 
/**
* The plug-in is a Filter Gallery plugin and its menu should be hidden by the preference.
* key value is 'lFGm'. This property relfects the \c LegacyFilterGalleryMenuItem property in the PiPL resource file.
*/
#define PILegacyFilterGalleryMenuItemProperty	0x6C46476DL

///@ingroup PiPLGeneralKeys
// 'flly' plug in filter layer properties
/**
* Plug-in filter layer properties; key value is 'flly'.
* This property key reflects the \c FilterLayerSupport property in the PiPL resource file.
* ]
*/
#define PIFilterLayerSupport	0x666c6c79L

///@ingroup PiPLGeneralKeys
// 'host' \<PIType\> giving host required if any:
/**
* Creator code of required host; key value is 'host'.
* This property key reflects the \c RequiredHost property in the PiPL resource file.
* The data for the property has type @ref PIType, with a value such as '8BIM'
* for Adobe Photoshop.
*/
#define PIRequiredHostProperty	0x686f7374L

///@ingroup PiPLGeneralKeys
// 'catg' \<PString\> Category name that appears on top level menu:
/** 
* In the \b Filter menu, what sub-menu to list this plug-in; key value is 'catg'.
* This property key reflects the \c Category property in the PiPL resource file.
* The data for the property has type \c PString; a \c Str255 except that storage may not
* be present for all 255 characters.  The initial length byte is present
* in the property.. 
*/
#define PICategoryProperty		0x63617467L

///@ingroup PiPLGeneralKeys
// 'zcat' \<PString\> Category name that appears on top level menu:
/** 
* In the \b Filter menu, what sub-menu to list this plug-in; key value is 'zcat'.
* This property key reflects the \c ZStringCategory property in the PiPL resource file.
* The data for the property has type \c ZString; a \c Str255 except that storage may not
* be present for all 255 characters.  The initial length byte is present
* in the property.. 
*/
#define PIZCategoryProperty		0x7A636174L

///@ingroup PiPLGeneralKeys
// 'name' \<PString\> Menu name:
/**
* Plug-in menu name for module in @ref PICategoryProperty sub-menu; key value is 'name'.
* This property key reflects the \c Name property in the PiPL resource file.
* The data for the property has type \c PString; a \c Str255 except that storage may not
* be present for all 255 characters.  The initial length byte is present
* in the property. 
*/
#define PINameProperty			0x6e616d65L

///@ingroup PiPLGeneralKeys
// 'znam' \<PString\> Menu name:
/**
* Plug-in menu name for module in @ref PICategoryProperty sub-menu; key value is 'znam'.
* This property key reflects the \c ZStringName property in the PiPL resource file.
* The data for the property has type \c PString; a \c Str255 except that storage may not
* be present for all 255 characters.  The initial length byte is present
* in the property. 
*/
#define PIZNameProperty			0x7A6E616DL

///@ingroup PiPLGeneralKeys
// 'prog' \<PString\> Progress text:
/**
* Plug-in handles all progress bar updates. **No-progress**
* Key value is 'prog'.
* This property key reflects the \c ProgressText property in the PiPL resource file.
* The data for the property has type \c PString; a \c Str255 except that storage may not
* be present for all 255 characters.  The initial length byte is present
* in the property. 
*/
#define PIProgressTextProperty	0x70726f67

///@ingroup PiPLGeneralKeys
// 'zpro' \<PString\> Progress text:
/**
* Plug-in handles all progress bar updates. **No-progress**
* Key value is 'zpro'. 
* This property key reflects the \c ZStringProgressText property in the PiPL resource file.
* The data for the property has type \c PString; a \c Str255 except that storage may not
* be present for all 255 characters.  The initial length byte is present
* in the property. 
*/
#define PIZProgressTextProperty	0x7A70726F

///@ingroup PiPLColorPickerKeys
// 'pnme' \<CString\> picker ID:
/**	 
*A unique string (UUID or your own TM/� string) that differentiates one 
* color picker from another; key value is 'pnme'.
* This property key reflects the \c PickerID property in the PiPL resource file.
* The data for the property has type CString.
* All color pickers must have a unique ID so that they may be accessed correctly 
* by the host. Menu entries are not sufficient to differentiate color pickers.
* @note If a color picker does not have a unique ID, or two loaded color 
* pickers have the same ID, then the first color picker in is always  
* executed, despite what appears in the pop-up menu.
*/ 
#define PIPickerIDProperty		0x706e6d65L

///@ingroup PiPLCodeDescriptorKeys
// '68fp' \<PI68KCodeDesc\> 68k w/FPU code descriptor. See struct below.
/**	A 68k code resource with FPU. Key is '68fp'. 
* This property key reflects the \c Code68kFPU property in the PiPL resource file.
* The data for the property has type @ref PI68KCodeDesc.
*/
#define PI68KFPUCodeProperty	0x36386670L

///@ingroup PiPLCodeDescriptorKeys
// 'usp7' SPARC version 7:
/**	A SPARC version 7 code descriptor. Key is 'usp7'. 
*/
#define PIUnixSPARCV7CodeProperty	0x75737037

///@ingroup PiPLCodeDescriptorKeys
// 'usp8' SPARC version 8:
/**	A SPARC version 8 code descriptor. Key is 'usp8. 
*/
#define PIUnixSPARCV8CodeProperty	0x75737038

///@ingroup PiPLCodeDescriptorKeys
// 'usp9' SPARC version 9:
/**	A SPARC version 9 code descriptor. Key is 'usp9'. 
*/
#define PIUnixSPARCV9CodeProperty	0x75737039

///@ingroup PiPLCodeDescriptorKeys
/**	A SPARC version 7 code descriptor. Key is 'usp7'. 
*/
#define PIUnixSPARCCodeProperty	PIUnixSPARCV7CodeProperty

///@ingroup PiPLCodeDescriptorKeys
// 'umr3' MIPS R3000:
/**	A MIPS R3000 code descriptor. Key is 'umr3'. 
*/
#define PIUnixMIPSR3000CodeProperty	0x756d7233

///@ingroup PiPLCodeDescriptorKeys
// 'umr4' MIPS R4000:
/**	A MIPS R4000 code descriptor. Key is 'umr4'. 
*/
#define PIUnixMIPSR4000CodeProperty	0x756d7234

///@ingroup PiPLCodeDescriptorKeys
// 'um4w' MIPS R4000 (can be 64 bit):
/**	A MIPS R4000 code descriptor, can be 64 bit. Key is 'um4w'. 
*/
#define PIUnixMIPSR400064BitCodeProperty	0x756d3477

///@ingroup PiPLCodeDescriptorKeys
// 'umr8' MIPS R8000 (always 64 bit):
/**	A MIPS R8000 code descriptor, always 64 bit. Key is 'umr8'. 
*/
#define PIUnixMIPSR8000CodeProperty	0x756d7238

///@ingroup PiPLCodeDescriptorKeys
/**	A MIPS R3000 code descriptor. Key is 'umr3'. 
*/
#define PIUnixMIPSCodeProperty	PIUnixMIPSR3000CodeProperty

///@ingroup PiPLGeneralKeys
// 'piLU' plug-in supports load/unload selectors:
/**	Plug-in supports load/unload selectors; key is 'piLU'. 	 
* This property key reflects the \c LoadUnload property in the PiPL resource file.
*/
#define PILoadUnloadProperty		0x70694c55

///@ingroup PiPLGeneralKeys
// 'piPF' plug-in supports preferences dialog selectors:
/**	Plug-in supports preferences dialog selectors; key is 'piPF'. 
* This property key reflects the \c Preferences property in the PiPL resource file.
*/
#define PIPreferencesProperty		0x70695046

// 'feen' plug-in is not loaded unless this feature is enabled
#define PIFeatureEnabledProperty	0x6665656e

// 'posd' plug-in is position dependent
#define PIPositionDependentProperty	0x706f7364

// 'pmsa' plug-in is UI scaling aware for each monitor
#define PIPerMonitorScalingAware	0x706d7361

//-------------------------------------------------------------------------------
//
//	Additional Structures -- PiPL types.
//
//	Below are structures describing types used in plug-in property lists.
//	These structures obey Macintosh 68k alignment and padding rules though
//	generally they are laid out so fields have natural alignment and any
//	needed padding is explicit in the structure.
//
//	In addition to these structure types, simple types such as int32, int16,
//	etc. are used. Two other examples are PString and FlagSet.
//
//	PString is like a rez pstring or a Str255 except that storage may not
//  be present for all 255 characters.  The initial length byte is present
//  in the property.
//
//	FlagSet is a variable length bitstring in which the first member is
//	represented by the most significant bit of the first byte, the eighth
//	member is in the least significant bit of the first byte, etc.
//  The length of the set is in the property's length field.
//
//	Arrays are also used in places with bounds either taken from the
//	property length or explicitly represented within the property.
//
//-------------------------------------------------------------------------------

/// Even though PICA may define PIPropertyList, it does
/// not define the handle form of it.
typedef PIPropertyList **PIPropertyListHandle;

/// Mac OS structure for file formats comprised of { 'type', 'crea' }.
typedef struct TypeCreatorPair
{
	PIType type;     /**< Four character file type. */
	PIType creator;	 /**< Four character creator type. */

} TypeCreatorPair;


/** 
* Information about the Plug-in.
*/
typedef struct PlugInInfo
{

	/// Version number of the interface supported.
	int16	version;

	 /// Subversion number.
	int16	subVersion;

	/// Priority for the plug-in.
	int16	priority;

	/// Size of the general info:
	int16	generalInfoSize;

	/// Size of the type specific info:
	int16	typeInfoSize;

	/// Bit mask indicating supported image modes.
	int16	supportsMode;

	/// Required host, if any.
	PIType	requireHost;

} PlugInInfo;

#if PRAGMA_STRUCT_ALIGN
	#pragma options align=reset
#endif

typedef struct PSBuffer *BufferID;

#define kPIGeneralInfoSize 16		   

//-------------------------------------------------------------------------------
//	Defines -- Image modes.
//-------------------------------------------------------------------------------

/** @defgroup ImageModes Image Modes 
*/
///@name Image Modes 
//@{
/** @ingroup ImageModes
* @{
*/
#define plugInModeBitmap			0
#define plugInModeGrayScale			1
#define plugInModeIndexedColor		2
#define plugInModeRGBColor			3
#define plugInModeCMYKColor			4
#define plugInModeHSLColor			5
#define plugInModeHSBColor			6
#define plugInModeMultichannel		7
#define plugInModeDuotone			8
#define plugInModeLabColor			9
#define plugInModeGray16			10
#define plugInModeRGB48				11
#define plugInModeLab48				12
#define plugInModeCMYK64			13
#define plugInModeDeepMultichannel	14
#define plugInModeDuotone16			15
#define plugInModeRGB96   			16
#define plugInModeGray32   			17
/** @} */ //end ingroup
//@}
//-------------------------------------------------------------------------------
//	Defines -- Blend modes.
//-------------------------------------------------------------------------------

/* Key for host supplied layer blend modes */
#define	kPIHostBlendModeSignature	'8BIM'

///@name Blend Modes
//@{
#define	PIBlendNormal			'norm'
#define	PIBlendDarken			'dark'
#define	PIBlendLighten			'lite'
#define	PIBlendHue				'hue '
#define	PIBlendSaturation		'sat '
#define	PIBlendColor			'colr'
#define	PIBlendLuminosity		'lum '
#define	PIBlendMultiply			'mul '
#define	PIBlendScreen			'scrn'
#define	PIBlendDissolve			'diss'
#define	PIBlendOverlay			'over'
#define	PIBlendHardLight		'hLit'
#define	PIBlendSoftLight		'sLit'
#define	PIBlendDifference		'diff'
#define	PIBlendExclusion		'smud'
#define	PIBlendColorDodge		'div '
#define	PIBlendColorBurn		'idiv'
#define	PIBlendLinearDodge		'lddg'
#define	PIBlendLinearBurn		'lbrn'
#define	PIBlendLinearLight		'lLit'
#define	PIBlendVividLight		'vLit'
#define	PIBlendPinLight			'pLit'
#define	PIBlendHardMix			'hMix'
//@}

//-------------------------------------------------------------------------------
//	Structures -- PiPL types.
//-------------------------------------------------------------------------------

/** 
* Blend Mode Information.
*/
typedef struct PIBlendMode
	{
	PIType signature;  /* kPIHostBlendModeSignature for built-in blend modes */
	PIType key;
	} PIBlendMode;
	
//-------------------------------------------------------------------------------
//
//	Defines -- Moveable Modal Dialog Window.
//
//	This is the Window procID for a Moveable Modal dialog window that can be
//	used for Mac OS System 6.  WDEF(128) is part of Photoshop.
//
//-------------------------------------------------------------------------------
//#define PSmovableDBoxProc	(128*16+5)
// We don't support System 6 any longer

//-------------------------------------------------------------------------------
//	Structures -- General.
//-------------------------------------------------------------------------------

/// For transposing one plane location to another on pre- or
/// post-processing.
typedef int16 PlaneMap [16];

/** Monitor setup information. A number of the plug-in module types get passed monitor descriptions through
* the this structure. These descriptions  detail the information recorded in the Photoshop 
* "Monitor Setup" dialog.
*/
typedef struct PlugInMonitor
{
	Fixed gamma;	  /**< The monitor�s gamma value or zero if the whole record is invalid. */
	Fixed redX;		  /**< The chromaticity coordinates of the monitor�s phosphors */
	Fixed redY;		  /**< The chromaticity coordinates of the monitor�s phosphors */
	Fixed greenX;	  /**< The chromaticity coordinates of the monitor�s phosphors */
	Fixed greenY;	  /**< The chromaticity coordinates of the monitor�s phosphors */
	Fixed blueX;	  /**< The chromaticity coordinates of the monitor�s phosphors */
	Fixed blueY;	  /**< The chromaticity coordinates of the monitor�s phosphors */
	Fixed whiteX;	  /**< The chromaticity coordinates of the monitor�s white point. */
	Fixed whiteY;	  /**< The chromaticity coordinates of the monitor�s white point. */
	Fixed ambient;	  /**< The relative amount of ambient light in the room. 
						   Zero means a relatively dark room, 0.5 means an average room, 
						   and 1.0 means a bright room. */

} PlugInMonitor;

//-------------------------------------------------------------------------------
//	Structures -- PSPixelMap
//-------------------------------------------------------------------------------
/** Pixel mask Information. 
	Note that the depth of the mask data must match the depth of the color data in the PSPixelMap
*/
typedef struct PSPixelMask
{
	struct PSPixelMask *next;	/**< A pointer to the next mask in the chain. */
	void *maskData;				/**< A pointer to the mask data. */
	int32 rowBytes;				/**< The row step for the mask. */
	int32 colBytes;				/**< The column step for the mask.*/
	int32 maskDescription;		/**< The mask description value.
								     See @ref MaskDescription "Mask Description Constants" for values.	  
								     */

} PSPixelMask;

// Defines for maskDescription field:
///@anchor MaskDescription
///@name Mask Description Constants
//@{
#define kSimplePSMask   0
#define kBlackMatPSMask 1
#define kGrayMatPSMask  2
#define kWhiteMatPSMask 3
#define kInvertPSMask   4
//@}

/** Pixel Overlay Information. 
	Note that the depth of the overlay data must match the depth of the color data in the PSPixelMap
*/
typedef struct PSPixelOverlay
	{
	struct PSPixelOverlay *next;
	void *data;
	int32 rowBytes;
	int32 colBytes;
	unsigned8 r, g, b, opacity;
	int32 overlayAlgorithm;	/**<  Indicates type of overlay algorithm.  See @ref OverlayAlgorithms 
								  "Overlay Algorithms." */
	} PSPixelOverlay;

// Overlay algorithms.
///@anchor OverlayAlgorithms
///@name Overlay Algorithms
//@{
#define kStandardAlphaOverlay	0	/**< Alpha overlay algorithm. */
#define kInvertedAlphaOverlay	1	/**< Inverted alpha overlay algorithm. */
//@}

// Color management options:
///@anchor ColorManagementOptions
///@name Color Management Options
//@{
#define kViewAsMask				0xF	/**< Low 4 bits are only used. */
#define kViewAsStandardRGB		0	/**< View with the Photoshop default color handling. */
#define kViewAsMacRGB			1	/**< View as if using AppleRGB.	*/
#define kViewAsWindowsRGB		2	/**< View as if using sRGB. */
#define kViewAsUncompensated	3	/**< Perform no compensation. */
//@}

/** Describes a block of pixels for display purposes.  Used in @ref DisplayPixelsProc. 
* Version 1 10/14/1997
* Version 2 03/22/1999
* Version 3 05/2012
*/
typedef struct PSPixelMap
{
	int32 version;		/**< Set to 1. Future versions of Photoshop may support additional 
						* parameters and will support higher version numbers for \c PSPixelMap. */
	VRect bounds;		/**< The bounds for the pixel map. */
	int32 imageMode;	/**< The mode for the image data. The supported modes are grayscale, 
						* RGB, CMYK, and Lab. See @ref ImageModes "Image Modes" for values. Additionally, if the 
						* mode of the document being 
						* processed is DuotoneMode or IndexedMode, you can pass \c plugInModeDuotone 
						* or \c plugInModeIndexedColor. */
	int32 rowBytes;		/**< The offset from one row to the next of pixels. */
	int32 colBytes;		/**< The offset from one column to the next of pixels. */
	int32 planeBytes;	/**< The offset from one plane of pixels to the next. In RGB, the planes are 
						* ordered red, green, blue; in CMYK, the planes are ordered cyan, magenta, 
						* yellow, black; in Lab, the planes are ordered L, a, b. */
	void *baseAddr;		/**< The address of the byte value for the first plane of the top left pixel. */
	
	//---------------------------------------------------------------------------
	// Fields new in version 1:
	//---------------------------------------------------------------------------	
	///@name New in version 1 
	//@{
	PSPixelMask *mat;	/**< A pixel mask to use for matting correction. Can be specified in 
	                    * all modes except indexed color. For example, if you have white matted 
						* data to display, you can specify a mask in this field  
						* to remove the white fringe. This field points to a \c PSPixelMask structure 
						* with a \c maskDescription that indicates what type of matting needs 
						* to be compensated for. If this field is NULL, Photoshop performs no matting 
						* compensation. If the masks are chained, only the first mask in the chain is used. 
						Depth of data in the mask must match the depth in the color channels */
	PSPixelMask *masks;	/**< A pointer to a chain of \c PSPixelMasks that are multiplied together 
						(with the possibility of inversion) to establish which areas of the image are 
						transparent and should have the checkerboard displayed. /c kSimplePSMask, /c kBlackMatPSMask, 
						/c kWhiteMatPSMask, and /c kGrayMatPSMask all operate such that 255=opaque and 0=transparent. 
						/c kInvertPSMask has 255=transparent and 0=opaque. 
						Depth of data in the mask must match the depth in the color channels */
	
	// Use to set the phase of the checkerboard:
	int32 maskPhaseRow; /**< The phase of the checkerboard with respect to the top left corner of the /c PSPixelMap */
	int32 maskPhaseCol; /**< The phase of the checkerboard with respect to the top left corner of the /c PSPixelMap */
	//@}
	//---------------------------------------------------------------------------
	// Fields new in version 2:
	//---------------------------------------------------------------------------	
	///@name New in version 2 
	//@{
	
	PSPixelOverlay *pixelOverlays;		/* Depth of data in the overlay must match the depth in the color channels */
	unsigned32 colorManagementOptions; /**< Options for color management.  See @ref ColorManagement */
	
	//@}
	//---------------------------------------------------------------------------
	// Fields new in version 3:
	//---------------------------------------------------------------------------	
	///@name New in version 3
	//@{
	
	int16	depth;		/**< Bit depth of each image channel */

	//@}
} PSPixelMap;

/** Describes the platformContext used in DisplayPixeldProc.  Used in @ref DisplayPixelsProc. 
 * Version 1 02/26/2009 - new for Photoshop CS5
 * On Mac Cocoa systems, platFormContext parameter is a pointer to the following structure
 * On 32bit Mac Cocoa platrorm, if platForm context is not NULL, Photoshop will
 * cast platformContext to *PSPlatformContext. On 64 bit Mac systems, platformContext
 * cannot be NULL, since QuickDraw is not supported on 64bit Mac systems.
 * On 32 bit Mac systems (Photoshop CS5 and above), if platformContext is NULL,
 * Photoshop will draw to the global QuickDraw port (as in earlier versions).
 * On Carbon systems (photoshop CS4 and earlier), platFormContext parameter is ignored
 * On Windows systems, platFormContext is an HDC. Photoshop will figure out the global rectangle
 * through WindowFromDC ( ) and GetWindowRect ( ) on that HWND. If a memory DC is passed in platformContext,
 * since Photoshop cannot determine the screen bounds through HDC, primary monitor's color profile
 * will be used for color management.
 */

typedef struct PSPlatformContext
{
	void *fCGContextRef;	// fCGContextRef is CoreGraphics' CGContextRef
	VRect fScreenRect;		// screen bounds that this DisplayPixels is targeted - for color management across monitors
} PSPlatformContext;

//-------------------------------------------------------------------------------
//	Structures -- ColorServicesInfo.
//-------------------------------------------------------------------------------

///This data structure is used in the @ref ColorServicesProc callback function.
typedef struct ColorServicesInfo
{
	int32 infoSize;		 			/**< Size of the ColorServicesInfo record in bytes. 
	                          		  *	 The value is used as a version identifier in case this 
	                          		  *	 record is expanded in the future. It can be filled in as follows:
									  *	 \code
									  *	 ColorServicesInfo requestInfo;
									  *	 requestInfo.infoSize = sizeof(requestInfo); \endcode 
									  */
	int16 selector;					 /**< Operation performed by the ColorServices callback.
									  * See @ref ColorServiceSelectors.
									  */ 	
	int16 sourceSpace;				 /**< Indicates the color space of the input color contained in 
	                                  * @ref colorComponents.
									  * For \c plugIncolorServicesChooseColor the input color is used 
									  * as an initial value for the picker.
									  * For plugIncolorServicesConvertColor the input color is converted 
									  * from the color space indicated by \c sourceSpace to the one indicated by 
									  * @ref resultSpace.  See @ref ColorSpace for values.
									  */
	int16 resultSpace;				 /**<
								 	  * Desired color space of the result color. The result is contained in the 
								 	  * @ref colorComponents field.	For the \c plugIncolorServicesChooseColor selector, 
								 	  * \c resultSpace can be set to \c -1=plugIncolorServicesChosenSpace to return the 
								 	  * color in whichever color space the user chose. In that case, \c resultSpace 
								 	  * contains the chosen color space on output.	See @ref ColorSpace for values.
									  */
	Boolean resultGamutInfoValid;	 /**< This output only field indicates whether the @ref resultInGamut field has 
									  * been set. In Photoshop 3.0 and later, this is only  true for colors returned 
									  * in the \c plugIncolorServicesCMYKSpace color space. 
									  */
	Boolean resultInGamut;			/**< Indicates whether the returned color is in gamut for the currently selected 
									 * printing setup. Only meaningful if @ref resultGamutInfoValid=TRUE.
									 */
	
	/// Both voids must be NULL or will return paramErr:
	void *reservedSourceSpaceInfo;	/**< Must be NULL, otherwise returns parameter error. */
	void *reservedResultSpaceInfo;	/**< Must be NULL, otherwise returns parameter error. */

   /** Actual color components of the input or output color. The values of the array
	* depend on the color space.
    * <TABLE border="1"
    *      summary="colorComponents array structure.">
    * <CAPTION><EM>colorComponents array structure</EM></CAPTION>
    * <TR><TH>Color Space<TH>[0]<TH>[1]<TH>[2]<TH>[3]
    * <TR><TH>RGB<TD>red from 0...255<TD>green from 0...255<TD>blue from 0...255<TD>undefined
    * <TR><TH>HSB<TD>hue from 0...359 degrees<TD>saturation from 0...359 degrees (representing 0%...100%)<TD>brightness from 0...359 degrees(representing 0%...100%)<TD>undefined
    * <TR><TH>CMYK<TD>cyan from 0...255 (representing 100%...0%)<TD>magenta from 0...255(representing 100%...0%)<TD>yellow from 0...255(representing 100%...0%)<TD>black from 0...255(representing 100%...0%) 
    * <TR><TH>HSL<TD>hue from 0...359 degrees<TD>saturation from 0...359 degrees(representing 0%...100%)<TD>luminance from 0...359 degrees(representing 0%...100%)<TD>undefined
    * <TR><TH>Lab<TD>Luminance from 0...255(representing 0...100)<TD>a. chromanance from 0...255 degrees(representing -128...127)<TD>b. chromanance from 0...255 degrees(representing -128...127)<TD>undefined
    * <TR><TH>Gray Scale<TD>gray value from 0...255<TD>undefined<TD>undefined<TD>undefined
    * <TR><TH>XYZ<TD>x value from 0...255<TD>Y value from 0...255<TD>Z value from 0...255<TD>undefined
    * </TABLE> 
   */
	int16 colorComponents[4];		
	/// Reserved must be NULL or will return paramErr:
	void *reserved;				  /**< Must be NULL, otherwise returns parameter error. */

	union
	{
		Str255 *pickerPrompt;	  /**< Contains a pointer to a Pascal string which is  
								   * used as a prompt in the color picker for the \c plugIncolorServicesChooseColor call. 
								   * NULL can be passed to indicate no prompt. */
		Point *globalSamplePoint; /**< Points to a \c Point record that is the current sample point. */
		int32 specialColorID;	  /**< should be either: \c 0=plugIncolorServicesForegroundColor or 
								   * \c 1=plugIncolorServicesBackgroundColor. */
	} selectorParameter;		  /**< This union is used for providing different information based on the 
	                               * selector field.
								   */

} ColorServicesInfo;


/** @defgroup ColorServiceSelectors Color Service Selectors
* Color Services Selectors indicate the operation for the Color Services 
* callback, @ref ColorServicesProc 
*/
///@name Color Service Selectors
//@{
///@ingroup ColorServiceSelectors
///@{
#define plugIncolorServicesChooseColor		0	 /**< Choose a color using the user's preferred color picker. */
#define plugIncolorServicesConvertColor		1	 /**< Convert color values fro one color space to another. */	
#define plugIncolorServicesSamplePoint		2	 /**< Return the current sample point. */
#define plugIncolorServicesGetSpecialColor	3	 /**< Return either the foreground or background color. To select
								                      foreground color, set \c specialColorID in \c selectorParameter
								                      to \c 0=plugIncolorServicesForegroundColor. To select
								                      background color, set \c specialColorID in \c selectorParameter
								                      to \c 1=plugIncolorServicesBackgroundColor. */
///@}
//@}

///@name Color Space Constants
//@{
// Constants for resultSpace and sourceSpace fields:
/** @defgroup ColorSpace Color Space
* Constants for the ColorServicesInfo::resultSpace and ColorServicesInfo::sourceSpace fields. 
*/
///@ingroup ColorSpace
///@{
#define plugIncolorServicesRGBSpace		0	 /**< RGB color space. */
#define plugIncolorServicesHSBSpace		1	 /**< HSB color space. */
#define plugIncolorServicesCMYKSpace	2	 /**< CMYK color space. */
#define plugIncolorServicesLabSpace		3	 /**< Lab color space. */
#define plugIncolorServicesGraySpace	4	 /**< Gray color space. */
#define plugIncolorServicesHSLSpace		5	 /**< HSL color space. */
#define plugIncolorServicesXYZSpace		6	 /**< XYZ color space. */
#define plugIncolorServicesChosenSpace	-1	 /**< Leaves the 
                                                  color in the space the user chose, returning \c resultSpace 
                                                  as the user chosen space. Only valid in the \c resultSpace field.   */
///@}
//@}

/// Selects foreground color when ColorServices operation is \c	plugIncolorServicesGetSpecialColor
#define plugIncolorServicesForegroundColor 0   
/// Selects background color when ColorServices operation is \c	plugIncolorServicesGetSpecialColor
#define plugIncolorServicesBackgroundColor 1

//-------------------------------------------------------------------------------
//	Structures -- Resampling callbacks.
//-------------------------------------------------------------------------------

/** Describes the 8-bit plane of pixel data used by the image services callback functions.
* You can calculate the address of a pixel by using the following algorithm:
@code
	unsigned8 * GetPixelAddress(PSImagePlane * plane, Point pt)
	{
		// should do some bounds checking here!
		return (unsigned8 *)	(((int32) plane->data +
			(pt.v - plane->bounds.top ) * plane->rowBytes +
			(pt.h - plane->bounds.left) * plane->colBytes);
	}
@endcode
*/
typedef struct PSImagePlane
{
	void *data;		 /**< Pointer to the byte containing the value of the top left pixel. */
	Rect bounds;	 /**< Coordinate systems for the pixels. */
	int32 rowBytes;	 /**< Step values to access individual pixels in a row. */
	int32 colBytes;	 /**< Step values to access individual pixels in a column. */

} PSImagePlane;

/** Describes multiple 8-bit planes of pixel data used by the image services callback functions. 
* Using a Rect to define the bounds.
*/
typedef struct PSImageMultiPlane
{
	void *data;		 /**< Pointer to the byte containing the value of the top left pixel. */
	Rect bounds;	 /**< Coordinate systems for the pixels. */
	int32 rowBytes;	 /**< Step values to access individual pixels in a row. */
	int32 colBytes;	 /**< Step values to access individual pixels in a column. */
	int16 activeChannels;	/**< Number of active channels/planes. */

} PSImageMultiPlane;

/** Describes multiple planes of pixel data used by the image services callback functions.
* Using a VRect to define the bounds.
*/
typedef struct PSImageMultiPlane32
{
	void *data;			   /**< Pointer to the byte containing the value of the top left pixel. */
	VRect bounds;		   /**< Coordinate systems for the pixels. */
	int32 rowBytes;		   /**< Step values to access individual pixels in a row. */
	int32 colBytes;		   /**< Step values to access individual pixels in a column. */
	int16 activeChannels;  /**< Number of active channels/planes. */
	int16 depth;		   /**< Only 8, 16, 32 bit values are valid. */

} PSImageMultiPlane32;

//-------------------------------------------------------------------------------
//	Structures -- Filter Layer Index -- Filter Layer support property indexes
//-------------------------------------------------------------------------------
#define PIFilteryLayersSupported	 	0


//-------------------------------------------------------------------------------
//	Structures -- Channel Ports.
//-------------------------------------------------------------------------------
/** @defgroup ChannelPortsSuite Channel Ports Suite Callbacks (\deprecated Standard Suite)
* The standard Channel Ports Suite has been deprecated, please use the  
* @ref PicaChannelPortsSuite See PIChannelPortsSuite.h
*
* Channel Ports are access points for reading and writing data from Photoshop
* internal selection data structures. There are two types of ports: read ports 
* and write ports. You can retrieve a read port corresponding to a write port, 
* but you cannot retrieve a write port from a read port. The API does allow for 
* write-only ports, although none exist as of this version of the suite.
* These structures are used to get at merged pixel information, such as iterating 
* through the merged data of the current layer or entire document, to be able to 
* return a selection or use for a preview proxy. <br><br>
* For more information, please see @ref SelectionModule, especially see 
* @ref selectionSelectorExecute.
*
* The standard Channel Ports Suite is found as a pointer in the parameter blocks of
* the plug-in modules. You can access the routines within the Channel Ports Suite in 
* the following manner:	
* @code
	DLLExport MACPASCAL void PluginMain (const int16 selector,
							             ExportRecordPtr exportParamBlock,
							             intptr_t* data,
							             int16* result)
	{
			...

			// Get the Channel Ports Suite from the parameter block
			ChannelPortProcs *channelPortsSuite = 
					exportParamBlock->channelPortProcs;

			// Call the readPixelsProc routine.  
			channelPortsSuite->readPixelsProc(...);
			...
	}
@endcode
*/

/** @ingroup ChannelPortsSuite */
/**
* Describes an area of memory as pixels.  
*/
typedef struct PixelMemoryDesc
{
	void *data;			/**< Coordinate of the first byte of the first pixel. */
	int32 rowBits;		/**< Number of bits per row.  Should be multiple of depth, and 
						     is generally a multiple of 8, since this reflects bits rather
						     than bytes. */
	int32 colBits;		/**< Number of bits per column.  Should be a multiple of depth. If \c depth=1,
						 	 then set \c colBits=1.  */
	int32 bitOffset;	/**< Bit offset from the data pointer value. */
	int32 depth;		/**< Pixel depth. */

} PixelMemoryDesc;

/** @ingroup ChannelPortsSuite */
/** Provide a scaling through a rectangle in source space and a corresponding rectangle 
* in destination space. Equal rectangles result in a direct, unscaled, mapping.  
* Unequal rectangles can be used to up- or down-sample. \n\n
* For example, if \c sourceRect is a 100-pixel square in source space: 
@code 
sourceRect.top = 0;  sourceRect.left = 0;
sourceRect.bottom = 100;  sourceRect.right = 100;
@endcode
* and destinationRect is a 50-pixel square in destination space:
@code
destinationRect.top = 0;  destinationRect.left = 0;
destinationRect.bottom = 50;  destinationRect.right = 50;
@endcode
* the scaling indicates to down-sample the image by half.
*/
typedef struct PSScaling
{
	VRect sourceRect;		/**< The source rectangle for scaling. */	  
	VRect destinationRect;	/**< The destination rectangle for scaling. */

} PSScaling;

/** @ingroup ChannelPortsSuite 	*/
// We provide access to internal channels via the following abstract types:
/** Access to internal channels though abstract types. */
typedef struct _PIChannelPortDesc *PIChannelPort;

// Old declarations. (4.0)
/** @ingroup ChannelPortsSuite 	*/
typedef PIChannelPort ChannelReadPort;	 /**< Channel read port. */
/** @ingroup ChannelPortsSuite 	*/
typedef PIChannelPort ChannelWritePort;	 /**< Channel write port. */

//-------------------------------------------------------------------------------
//	Structures -- Channel Ports -- Channel Types
//-------------------------------------------------------------------------------

///@anchor ChannelTypes
///@name Channel Types 
//@{
#define ctUnspecified		 0		 /**< Unspecified channel. */
#define ctRed				 1		 /**< Red of RGB. */
#define ctGreen				 2		 /**< Green of RGB. */
#define ctBlue				 3		 /**< Blue of RGB. */
#define ctCyan				 4		 /**< Cyan of CMYK. */
#define ctMagenta			 5		 /**< Magenta of CMYK. */
#define ctYellow			 6		 /**< Yellow of CMYK. */
#define ctBlack				 7		 /**< Black of CMYK. */
#define ctL					 8		 /**< L of LAB. */
#define ctA					 9		 /**< A of LAB. */
#define ctB					10		 /**< B of LAB. */
#define ctDuotone			11		 /**< Duotone. */
#define ctIndex				12		 /**< Index. */
#define ctBitmap			13		 /**< Bitmap. */
#define ctColorSelected		14		 /**< Selected color. */
#define ctColorProtected	15		 /**< Protected color. */
#define ctTransparency      16		 /**< Transparent color. */
#define ctLayerMask         17		 /**< Layer mask (alpha channel). White = transparent, Black = mask. */
#define ctInvertedLayerMask 18		 /**< Inverted layer mask (inverted alpha channel). */
#define ctSelectionMask     19		 /**< Mask/alpha for selection. */
#define ctSpotColor			20		 /**< Spot Color. */
#define ctVectorMask		21
#define ctSmartFilterMask	22
//@}

//-------------------------------------------------------------------------------
//	Structures -- Channel Ports -- WriteChannelDesc
//-------------------------------------------------------------------------------

/** @ingroup ChannelPortsSuite 	*/
#define kCurrentMinVersWriteChannelDesc	0	 /**< Current minimum version of \c WriteChannelDesc. */
/** @ingroup ChannelPortsSuite 	*/
#define kCurrentMaxVersWriteChannelDesc	1	 /**< Current maximum version of \c WriteChannelDesc. */

/** @ingroup ChannelPortsSuite 	*/
/** The channel to write a selection to. 
*/
typedef struct WriteChannelDesc
{
	
	int32 minVersion;	/**< Informs the host of the minimum version needed to interpret this record. */
	int32 maxVersion;	/**< The maximum version allowable to interpret this record. */
	
	//---------------------------------------------------------------------------
	//	Version 0 fields:
	//---------------------------------------------------------------------------
	
	struct WriteChannelDesc *next;	 /**< Next descriptor in the list.	*/

	
	ChannelWritePort port;	/**< Port to write to. Provided by the host. */
	
	VRect bounds;			/**< Channel data bounds. */
	int32 depth;			/**< Depth of the data. Horizontal and vertical resolution. */
	
	VPoint tileSize;		/**< Size of the tiles. */
	VPoint tileOrigin;		/**< Origin of the tiles. */
	
	int16 channelType;		/**< Channel type. See @ref ChannelTypes. */ 
	
	int16 padding;			/**< Reserved. Defaults to zero. */
	
	void *contextInfo;		/**< Pointer to additional information dependent on context. */
	
	const char *name;		/**< Name of the channel. */

	//---------------------------------------------------------------------------
	//	Version 1 fields:
	//---------------------------------------------------------------------------
	///@name New in version 1 
	//@{
	const uint16 *unicodeName;		/**< Name of the channel as a Unicode string. 
									 * (Platform endianess). For Version 1. */
	//@}

  #ifdef __cplusplus
	WriteChannelDesc()
		: minVersion(0), maxVersion(0), next(NULL), port(NULL), depth(0),
		channelType(0), padding(0), contextInfo(NULL), name(NULL), unicodeName(NULL) {}	  /**< WriteChannelDesc constructor */
  #endif // __cplusplus				
} WriteChannelDesc;
/** @} */

//-------------------------------------------------------------------------------
//	Structures -- Channel Ports -- ReadChannelDesc
//-------------------------------------------------------------------------------
/** @ingroup ChannelPortsSuite */
#define kCurrentMinVersReadChannelDesc	0  /**< Current minimum version of \c ReadChannelDesc. */
/** @ingroup ChannelPortsSuite 	*/
#define kCurrentMaxVersReadChannelDesc	5  /**< Current maximum version of \c ReadChannelDesc. */

/** @ingroup ChannelPortsSuite */
/** A channel to read from.  
*/
typedef struct ReadChannelDesc
{
	
	int32 minVersion;	  /**< The minimum version needed to interpret this record. */
	int32 maxVersion;	  /**< The maximum version allowable to interpret this record. */

	//---------------------------------------------------------------------------
	//	Version 0 fields:
	//---------------------------------------------------------------------------
		
	struct ReadChannelDesc *next;	/**< Next descriptor in the list. */
	
	PIChannelPort port;		/**< Port to use for reading. Provided by host. */
	
	VRect bounds;			/**< Bounds of the channel data. */
	int32 depth;			/**< Depth of the data; horizontal and vertical resolution. */
	
	VPoint tileSize;		/**< Size of the tiles, set by the host. The plug-in should use
								 this size if possible to optimize and match the host memory
								 scheme. */
	VPoint tileOrigin;		/**< Origin for the tiles, set by host. */
	
	Boolean target;			/**< Indicates if this a target channel. TRUE if so. */
	Boolean shown;			/**< Indicates if this channel is visible.  TRUE if so. */
								 
	int16 channelType;		/**< Channel type. See @ref ChannelTypes. */
	
	void *contextInfo;		/**< Pointer to additional information dependent on context. */
	
	const char *name;		/**< Name of the channel as a C string. */

	//---------------------------------------------------------------------------
	//	Version 1 fields:
	//---------------------------------------------------------------------------
	///@name New in version 1 
	//@{
	PIChannelPort writePort; /**< Port to use for writing if writing is allowed.
								  This generally does not point back to the same collection
								  of pixels. */
	 //@}
	//---------------------------------------------------------------------------
	//	Version 2 fields:
	//---------------------------------------------------------------------------
	///@name New in version 2 
	//@{
	unsigned32 alphaID;		/**< Persistent ID for the channel. Only set for alpha
							     channels. */
	//@}

	///@name New in version 3 
	//@{
	const uint16 *unicodeName;		/**< Name of the channel as a Unicode string. (platform endianess) */
	//@}

	//---------------------------------------------------------------------------
	//	Version 4 fields: (added in Photoshop CS3/10)
	//---------------------------------------------------------------------------

	///@name New in version 4 
	//@{
	Boolean isEnabled;			/**< Indicates if the read channel is enabled.  Used for layer 
									 masks and vector masks that can be disabled. */
	//@}

	//---------------------------------------------------------------------------
	//	Version 5 fields:
	//---------------------------------------------------------------------------
	///@name New in version 5 
	//@{
	VRect limitBounds;			/**< Bounds trimmed to transparency. */
	//@}


  #ifdef __cplusplus
	ReadChannelDesc() 
		: minVersion(0), maxVersion(0), next(NULL), port(NULL), depth(0),
		target(false), shown(false), channelType(0), contextInfo(NULL),
		name(NULL), writePort(NULL), alphaID(0), unicodeName(NULL), isEnabled(true) {}
  #endif // __cplusplus				/**< ReadChannelDesc constructor. */
					
} ReadChannelDesc;
/** @} */
//-------------------------------------------------------------------------------
//
//	Structures -- Channel Ports -- ReadLayerDesc
//
//	We describe a layer as a collection of lists of read channels.
//
//-------------------------------------------------------------------------------
/** @ingroup ChannelPortsSuite */
#define kCurrentMinVersReadLayerDesc	0	 /**< Current minimum version of \c ReadLayerDesc. */
/** @ingroup ChannelPortsSuite */
#define kCurrentMaxVersReadLayerDesc	3	 /**< Current maximum version of \c ReadLayerDesc. */

/** @ingroup ChannelPortsSuite */
/** A layer to read.  A layer is a collection of lists of read channels. */
typedef struct ReadLayerDesc
{
	
	int32 minVersion;	  /**< The minimum version needed to interpret this record. */
	int32 maxVersion;	  /**< The maximum version allowable to interpret this record. */
	
	//---------------------------------------------------------------------------
	//	Version 0 fields:
	//---------------------------------------------------------------------------
	struct ReadLayerDesc *next;		/**< The next descriptor in the list. */
	
	ReadChannelDesc *compositeChannelsList;	 /**< Composite channels in this layer. */

	ReadChannelDesc *transparency;	/**< Transparency channel for this layer. */

	ReadChannelDesc *layerMask;	    /**< Layer mask for this layer. */					
	
	unsigned32 sheetID;		        /**< *unique ID for the sheet. */
	
	const char *name;		        /**< Name of the layer as a C string. */

	Boolean isPixelBased;	        /**< Indicates if this layer is pixel based, TRUE if so. */

	//---------------------------------------------------------------------------
	//	Version 1 fields:
	//---------------------------------------------------------------------------
	
	///@name New in version 1 
	//@{
	const uint16 *unicodeName;		/**< Name of the channel as a Unicode string. (platform endianess) */
	//@}

	//---------------------------------------------------------------------------
	//	Version 2 fields (added in Photoshop CS3/10)
	//---------------------------------------------------------------------------

	///@name New in version 2 
	//@{
	Boolean isVisible;		/**< Indicates if this layer is currently visible. */
	
	Boolean isAdjustor;		/**< Indicates if this is an adjustment layer. */
	
	Boolean isContentGenerator;	/**< Indicates if this is a content generator layer. */
	
	Boolean	isRendered;		/**< Indicates if this is a rendered layer */
	
	unsigned8 opacity;		/**< Layer opacity; range from 0 to 255, where opaque = 255. */
	
	unsigned8 fillOpacity;	/**< Layer fill opacity; range from 0 to 255, where opqaue = 255. */
	
	PIType	blendMode;		/**< Layer blend mode, as 4 character keys. */
	
	ReadChannelDesc *vectorMask; /**< Vector mask for the layer. */
	//@}

	//---------------------------------------------------------------------------
	//	Version 3 fields (added in Photoshop CS3/10)
	//---------------------------------------------------------------------------
	
	ReadChannelDesc *smartFilterMask; /**< Mask for smart filters */

	//@}

  #ifdef __cplusplus
	ReadLayerDesc()
		: minVersion(0), maxVersion(0), next(NULL), compositeChannelsList(NULL),
		transparency(NULL), layerMask(NULL), sheetID(0), name(NULL), 
		isPixelBased(true), unicodeName(NULL), isVisible(true), 
		isAdjustor(false), isContentGenerator(false), isRendered(false), 
		opacity(255), fillOpacity(255), blendMode(PIBlendNormal), 
		vectorMask(NULL), smartFilterMask(NULL) {}
  #endif // __cplusplus			   /**< ReadLayerDesc constructor */

	} ReadLayerDesc;
/** @} */
//-------------------------------------------------------------------------------
//	Structures -- Channel Ports -- Document Types
//-------------------------------------------------------------------------------
///@anchor DocumentTypes
///@name Document Types
// @{ 
#define dtImageDocument	 	0	   /**< Standard image document. */
#define dtImageScrap		1	   /**< Scrap or clipboard document. */
// @}
//-------------------------------------------------------------------------------
//
//	Structures -- Channel Ports -- ImageDocumentDesc
//
//	We describe a document as a collection of lists of read channels.
//
//-------------------------------------------------------------------------------
/** @ingroup ChannelPortsSuite */
#define kCurrentMinVersReadImageDocDesc	0  /**< Current minimum version of the \c ReadImageDocumentDesc */
/** @ingroup ChannelPortsSuite */
#define kCurrentMaxVersReadImageDocDesc	6  /**< Current maximum version of the \c ReadImageDocumentDesc */

/** @ingroup ChannelPortsSuite */
/** The document information, used by 
* the Export, Filter, and Selection module parameter blocks.  Describes the document
* as a collection of channels and layers.  The host provides a read port for each
* channel, so the pixel data can be read by using @ref ReadPixelsProc in the
* @ref ChannelPortsSuite.
*/
typedef struct ReadImageDocumentDesc
{
	
	int32 minVersion;	   /**< The minimum version needed to interpret this record. */
	int32 maxVersion;	   /**< The maximum version allowable to interpret this record. */
	
	//---------------------------------------------------------------------------
	//	Version 0 fields:
	//---------------------------------------------------------------------------
	
	int32 imageMode;		/**< Color mode for the document. See @ref ImageModes for supported modes. */
	int32 depth;			/**< Default bit depth for the document. */
	VRect bounds;			/**< Document bounds. */
	
	Fixed hResolution;		/**< Horizontal resolution for the document. */
	Fixed vResolution;		/**< Vertical resolution for the document. */
	
	LookUpTable redLUT;		/**< Red color table, applicable when \c imageMode is indexed color or duotone. */
	LookUpTable greenLUT;	/**< Green color table, applicable when \c imageMode is indexed color or duotone. */
	LookUpTable blueLUT;	/**< Blue color table, applicable when \c imageMode is indexed color or duotone. */
	
	
	ReadChannelDesc *targetCompositeChannels;	/**< Composite channels in the target layer. */
	
	ReadChannelDesc *targetTransparency;	   /**< Transparency channel for the target layer. */
							
   	ReadChannelDesc *targetLayerMask;		   /**< Layer mask for the target channel. */
							
	ReadChannelDesc *mergedCompositeChannels;  /**< Composite channels in the merged data. Merged 
												   data is either merged layer data or merged 
												   document data. */
							
	ReadChannelDesc *mergedTransparency;	   /**< Transparency channel for the merged data. */
							
	ReadChannelDesc *alphaChannels;			   /**< Alpha channels for masks */
							
	ReadChannelDesc *selection;				   /**< Selection mask, if any. */

	// New with version 1.
	//---------------------------------------------------------------------------
	//	Version 1 fields
	//---------------------------------------------------------------------------
	///@name New in version 1 
	//@{
	struct SPPlatformFileSpecification_t *fileSpec;	 /**<  The file specification, if any. */
	//@}
	
	///@name New in version 2
	//@{
	ReadLayerDesc *layersDescriptor;		   /**< Descriptor for a linked list of layers, if any. */
	
	int32 documentType;						   /**< Document type.  See @ref DocumentTypes "Document Types." */

	struct ReadImageDocumentDesc *next;		   /**< The next descriptor in the list. */
	//@}

	//---------------------------------------------------------------------------
	//	Version 3 fields (added in Photoshop CS3/10)
	//---------------------------------------------------------------------------

	///@name New in version 3
	//@{
	void *	iCCprofileData;		/**< ICC Profile Data. NULL if there is no profile  */
	
	int32	iCCprofileSize;		/**< Size of the ICC profile; zero if there is no profile. */

	int32	compositeChannelCount;	/**< Number of composite color channels in this document. */
	
	int32	layerCount;			/**< Total number of layers in this document; 
	                                 ignores visbility, adjustments, etc.	*/
	
	int32	alphaChannelCount;	/**< Number of alpha channels in this document. */
	//@}

	//---------------------------------------------------------------------------
	//	Version 4 fields (added in Photoshop CS3/10)
	//---------------------------------------------------------------------------
	
	// Layer mask for the target layer:
	ReadChannelDesc *targetSmartFilterMask;
				
	//---------------------------------------------------------------------------
	//	Version 5 fields (added in Photoshop CS6/13)
	//---------------------------------------------------------------------------
	
	// The Unicode file specification, if any.
	struct SPPlatformFileSpecificationW *fileSpecW;

	//---------------------------------------------------------------------------
	//	Version 6 fields (added in Photoshop CC 2015.5 (17.0))
	//---------------------------------------------------------------------------
	// The file specification, if any.
	struct XPlatFileSpec *fileSpecX;


  #ifdef __cplusplus
	ReadImageDocumentDesc()
		: minVersion(0), maxVersion(0), imageMode(0), depth(0), 
		  hResolution(0), vResolution(0), 
		  targetCompositeChannels(NULL), targetTransparency(NULL), targetLayerMask(NULL),
		  mergedCompositeChannels(NULL), mergedTransparency(NULL), alphaChannels(NULL),
		  selection(NULL), fileSpec(NULL), layersDescriptor(NULL), documentType(0),
		  next(NULL), iCCprofileData(NULL), iCCprofileSize(0), compositeChannelCount(0),
		  layerCount(0), alphaChannelCount(0), targetSmartFilterMask(NULL), fileSpecW(NULL),
		  fileSpecX(0)
		  	{
		  	}
  #endif // __cplusplus

} ReadImageDocumentDesc;
/** @} */
//-------------------------------------------------------------------------------
//	Defines -- Prototypes -- Callbacks.
//-------------------------------------------------------------------------------
#ifdef __cplusplus

extern "C"
{
#endif

	// Direct callbacks:
///@name Non-Suite Callbacks 
//@{

/** @defgroup DirectCallbacks Non-Suite Callbacks
* These callbacks are found directly in the various plug-in parameter block structures.
* For more information, see @ref PGDirectCallbacks "Using Non-Suite Callbacks."
*
* @{
*/
	
	
	/**
	* Provides a mechanism to allow the user to abort the operation of the plug-in. 
	* A plug-in should call this function several times a second during long 
	* operations. If the user has requested
	* to abort the operation, the plug-in should return a positive error code.
	* As a side effect, this changes the cursor to 
	* a watch and moves the watch hands periodically.
	* @returns TRUE if the user has requested to abort the operation. 
	*/
	typedef MACPASCAL Boolean (*TestAbortProc) (void);
	
	
	/**
	* Provides a mechanism for the plug-in to update progress indicators. The plug-in can call 
	* this procedure periodically to update a progress indicator.
	* This procedure should only be called in the actual main operation of the plug-in,
	* not while long operations are executing during the preliminary user interface.
	* Photoshop automatically suppresses display of the progress bar during short 
	* operations.
	* @param done The number of operations completed.
	* @param total The total number of operations.
 	*/
	typedef MACPASCAL void (*ProgressProc) (int32 done, int32 total);
	
	
	/**
	* Contains a pointer to a host-defined function. A plug-in should 
	* verify the host signature (in the parameter block�s \c hostSig field) before 
	* calling this procedure. This provides a mechanism for hosts 
	* to extend the plug-in interface to support application-specific features.
	* @param selector The operation to perform.
	* @param data Data provided for the operation.
	* @note Adobe Photoshop versions 3.0.4 and later do not perform any tasks 
	* in this callback. Earlier versions of Photoshop used Host for private communication 
	* between Photoshop and some plug-in modules.
	*/
	typedef MACPASCAL void (*HostProc) (int16 selector, intptr_t *data);


	/**
	* Examines \c imageMode, \c imageSize, \c depth, and \c planes and determines
	* the number of bytes required to hold the image.
	* @returns The number of bytes of scratch disk space required to hold the image, or -1 if 
	* the values are not valid.
	* @note This callback is only available to Acquire (Import) plug-in modules. 
	*/
	typedef MACPASCAL int32 (*SpaceProc) (void);


	/**
	* Allows Mac OS plug-in modules to pass standard \c EventRecord pointers to Photoshop. 
	* For example, when a plug-in receives a deactivate event for one of the Photoshop windows, 
	* it should pass this event on to Photoshop. This routine can also be used to force Photoshop 
	* to update its own windows by passing relevant update and NULL events.
	* @note This callback is only useful on Mac OS; a call to \c ProcessEventProc in the 
	* Adobe Photoshop for Windows does nothing. 
	*/
	typedef MACPASCAL void (*ProcessEventProc) (void *event);


	/**
	* Displays pixels in various image modes given a block of pixels to display. 
	* The routine does the appropriate color space
	* conversion and copies the results to the screen with dithering. It leaves the original 
	* data intact. To suppress the watch cursor during updates, see @ref propWatchSuspension 
	* in the Properties suite.
	* @param source Describes a block of pixels to display. 
	* @param srcRect Indicates the rectangle of the source pixel map to display.
	* @param dstRow Provides the coordinates of the top-most destination pixel in 
	                the current port (i.e., the destination pixel defined by 
	                \c dstRow and \c dstCol corresponds to the top-left pixel in 
	                srcRect). The display routines do not scale the pixels, so specifying 
	                the top left corner is sufficient to specify the destination.
	* @param dstCol Provides the coordinates of the left-most destination pixel in 
	                the current port. 
	* @param platformContext On Windows, should be the target \c hDC, cast to an unsigned32.
	                Not used on Mac OS (Carbon) since the display routines simply assume 
	                that the target is the current port. 
					Cast to PSPlatformContext * on Cocoa systems. See description
					for PSPlatformContext
	* @returns If successful, returns \c noErr. Non-success is generally due to 
	* unsupported color modes.
	*/
	typedef MACPASCAL OSErr (*DisplayPixelsProc) (const PSPixelMap *source,
												  const VRect *srcRect,
												  int32 dstRow,
												  int32 dstCol,
												  void *platformContext);


	/**
	* Allows the plug-in to ask the host to update, i.e., "advance the state of", the various data structures 
	* used for communicating between the host and the plug-in.
	* Use \c AdvanceStateProc where you expect a plug-in to be called repeatedly. 
	* For example, a scanner module that scans and delivers images in chunks. When working with 
	* large images (larger than available RAM), plug-ins should process the image in pieces.
	* Without \c AdvanceStateProc, a plug-in is called from, and returns to, the host for each chunk of data. 
	* Each repeated call must go through your plug-in�s \c main() entry point. With \c AdvanceStateProc, a plug-in 
	* can complete its general operation within a single call from the plug-in host. This does not include setup
	* interaction with the user, or normal cleanup. <br><br>
	* The precise behavior of this callback varies depending on what type of plug-in module is executing. 
	* Refer to specific plug-in modules for information on how to use this callback.
	* @returns \c noErr if successful; a non-zero error code if unsuccessful. \n
	* If the user cancels by pressing \e Escape in Windows, or \e Command-period in Mac OS, \c AdvanceStateProc
	* returns \c userCanceledErr (-128). 
	* @note If an error is returned, the plug-in should not call \c AdvanceStateProc again, but instead return the error code 
	* to the plug-in host back through \c main().
	*
	* <b>AdvanceState, Buffers, Proxies, and DisplayPixels</b> \n
	* Proxies really put \c AdvanceState to work, because if the plug-in allows the user to drag around an image, 
	* the plug-in is constantly updating and asking for more image data. To keep the lag time down, and the 
	* update watch from appearing often in \c DisplayPixels, keep these items in mind:
	* - \c AdvanceState buffers as much of the image as it can, so make the first call for  \c inRect as large 
	* as possible. In subsequent calls, as long as the request falls within \c inRect, the image data comes 
	* right out of the buffer.
	* - As soon as the plug-in sets <tt>inRect=0,0,0,0</tt> or it calls for one pixel outside of the buffer area 
	* (the first calling rect it passed) \c AdvanceState flushes the buffer and loads new image data from 
	* the VM system.
	*/
	typedef MACPASCAL OSErr (*AdvanceStateProc) (void);


	/**
	* Provides a plug-in module with access to common color services within Photoshop. 
	* It can be used to perform one of four operations:
	* -	choose a color using the user�s preferred color picker 
	*   (the Photoshop color picker, the Systems, or any Color Picker plug-in module),
	* -	convert color values from one color space to another,
	* -	return the current sample point,
	* -	return either the foreground or background color.
	*
	* See @ref ColorPickerModule for information about the Color Picker plug-in module type.
	* @param info The structure passed to color services to define the type of access.
	* @note  \c ColorServicesProc has a bug in versions of Photoshop prior to 3.0.4. 
	* When converting from one color space to another they return \c error paramErr=-50 
	* and convert the requested color to RGB, regardless of the target color space.
	* ColorServices also may have errors converting between any color space and Lab, 
	* XYZ, or HSL. RGB, CMYK, and HSB have been proven and are correct, but
	* check the numbers on the others before relying on them.
	*/
	typedef MACPASCAL OSErr (*ColorServicesProc) (ColorServicesInfo *info);
/**
*@}
*/
//@}

	// Handle procs:
///@name Handle Suite Callbacks 
//@{

/** @defgroup HandleSuite Handle Suite Callbacks (\deprecated Standard Suite)
* The standard Handle Suite is deprecated, please use the @ref PicaHandleSuite defined
* with the Adobe Plug-in Component Architecture (PICA).

*
* The following suite of routines is used primarily for cross-platform support. 
* Although you can allocate handles directly using the Mac OS Toolbox, these callbacks 
* are recommended, instead. When you use these callbacks, Photoshop accounts for these 
* handles in its virtual memory space calculations. <br><br>
* The use of the \c Handle structure throughout the API poses a problem under Windows, 
* where a direct equivalent does not exist. To facilitate Windows plug-ins, Photoshop 
* implements a handle model that is very similar to handles under the Mac OS.  
*
* In general, the Buffer suite routines are more effective for memory allocation than 
* the Handle suite. The Buffer suite may have access to memory unavailable to the Handle 
* suite. You should use the Handle suite, however, if the data you are managing is a 
* Mac OS handle. <br><br>
* For more information, please see @ref PGUsingSuites "Using Buffer and Handle Suites".
*
* The standard Handle Suite is found as a pointer in the parameter blocks of
* the plug-in modules.  You can access the routines within the Buffer Suite in 
* the following manner:
* @code
	// The structure to hold the data, we'll create a handle for this.
	typedef struct Data
	{
		FilterColor color;
		FilterColor colorArray[4];
		Boolean queryForParameters;
		BufferID dissolveBufferID;
		Ptr dissolveBuffer;
		VRect proxyRect;
		real32 scaleFactor;
		BufferID proxyBufferID;
		Ptr proxyBuffer;
		int32 proxyWidth;
		int32 proxyHeight;
		int32 proxyPlaneSize;
	} Data;

	FilterRecord *gFilterRecord = NULL;	

	DLLExport MACPASCAL void PluginMain(const int16 selector,
								    	FilterRecordPtr filterRecord,
								    	intptr_t* data,
								    	int16* result)
	{
	  // The parameter block that contains the suite is found in filterRecord. 
	  gFilterRecord = filterRecord;
	  ...
	}

	// This function uses one of the Handle Suite routines
	void CreateDataHandle(void)
	{
		// Get the Handle Suite, and call the
		// newProc routine to allocate the memory for the handle.
		Handle h = gFilterRecord->handleProcs->newProc(sizeof(Data));
		...
	}
@endcode
* @{
*/

	/**
	* Allocates a handle of the indicated size. 
	* @param size The size of the handle to allocate
	* @returns  The new handle; NULL if the handle could not be allocated.
	*/
	typedef MACPASCAL Handle (*NewPIHandleProc) (int32 size);

	/**
	* Disposes of the indicated handle.
	* @param h The handle to dispose of.
	*/
	typedef MACPASCAL void (*DisposePIHandleProc) (Handle h);

	/**
	* Disposes of the indicated handle.
	* @param h The handle to dispose of.
	*/
	typedef MACPASCAL void (*DisposeRegularHandlePIHandleProc) (Handle h);

	/**
	* Gets the size of the indicated handle.
	* @param h The handle to get the size of.
	* @returns The size of the handle.
	*/
	typedef MACPASCAL int32 (*GetPIHandleSizeProc) (Handle h);

	/**
	* Attempts to resize the indicated handle. 
	* @param h The handle to resize.
	* @param newSize The new size for the handle. 
	* @returns \c noErr if successful; an error code if unsuccessful.
	*/
	typedef MACPASCAL OSErr (*SetPIHandleSizeProc) (Handle h, int32 newSize);

	/**
	* Locks and dereferences the handle. 
	* @param h The handle to lock.
	* @param moveHigh Flag to indicate whether to move the handle 
	* to the high end of memory before locking it.
	* @returns a pointer to the containing data
	*/
	typedef MACPASCAL Ptr (*LockPIHandleProc) (Handle h, Boolean moveHigh);

	/**
	* Unlocks the handle. Unlike the routines for buffers, the lock and 
	* unlock calls for handles are not reference counted. A single unlock call unlocks the handle no 
	* matter how many times it has been locked.
	* @param h The handle to unlock.
	*/
	typedef MACPASCAL void (*UnlockPIHandleProc) (Handle h);

	/**
	* Recovers space from disposed handles not disposed of by invoking the 
	* @ref DisposePIHandleProc callback. 
	* All handles allocated through the Handle suite have their space accounted for in 
	* estimates by Photoshop of how much image data it can make resident at one time. <br><br>
	* If you obtain a handle through the Handle suite or some other mechanism in Photoshop, you 
	* should dispose of it using the \c DisposePIHandleProc callback. If you dispose of it in some other 
	* way (e.g., use the handle as the parameter to \c AddResource and then close the resource file),
	* then you can use this call to tell Photoshop to decrease its handle memory pool estimate.
	* @param size Amount of space to recover.
	*/
	typedef MACPASCAL void (*RecoverSpaceProc) (int32 size);

/**
* @}  //end defgroup
*/
//@}  //end name

///@name Buffer Suite Callbacks 
//@{
/** @defgroup BufferSuite Buffer Suite Callbacks (\deprecated Standard Suite)
* The standard Buffer Suite is deprecated, please use the @ref PicaBufferSuite defined
* with the Adobe Plug-in Component Architecture (PICA).
*
* The Buffer suite provides an alternative to the memory management functions 
* available in previous versions of the Photoshop plug-in specification. 
* It provides a set of routines to request that the host allocate and dispose of 
* memory out of a pool which it manages. <br><br>
* For most types of plug-ins, buffer allocations can be delayed until they are 
* actually needed. Unfortunately, Export modules must track the buffer for the data 
* requested from the host even though the host allocates the buffer. This means that 
* the Buffer suite routines do not provide much help for Export modules. <br><br>
* For more information, please see @ref PGMemoryMgmtStrategies "Memory Management Strategies".
*
* The standard Buffer Suite is found as a pointer in the parameter blocks of
* the plug-in modules.  You can access the routines within the Buffer Suite in 
* the following manner:
* @code
	FilterRecord *gFilterRecord = NULL;	

	DLLExport MACPASCAL void PluginMain(const int16 selector,
								    	FilterRecordPtr filterRecord,
								    	intptr_t* data,
								    	int16* result)
	{
	  // The parameter block that contains the suite is found in filterRecord. 
	  gFilterRecord = filterRecord;
	  ...
	}

	// This function uses two of the Buffer Suite routines
	void CreateDissolveBuffer(const int32 width, const int32 height)
	{
		// Get the Buffer Suite from the parameter block
		BufferProcs *bufferProcs = gFilterRecord->bufferProcs;

		// Call the allocateProc routine from the Buffer Suite to allocate
		// the space needed for the buffer (gdata->dissolveBufferID)
		bufferProcs->allocateProc(width * height, &gData->dissolveBufferID);

		// Call the lockProc routine to lock the memory
		gData->dissolveBuffer = bufferProcs->lockProc(gData->dissolveBufferID, true);
	}
@endcode
*/

/** @ingroup BufferSuite 
* @{
*/
	/** Sets \c bufferID to be the ID for a buffer of the requested size. 
	* @param size The size of the buffer to allocate.
	* @param bufferID [OUT] The allocated buffer.
	* @returns \c noErr if allocation is successful;  an error code if allocation is unsuccessful.
	* @note Buffers are identified by pointers to an opaque type called BufferID. Buffer allocation is 
	* more likely to fail during phases where other blocks of memory are locked 
	* down for the plug-in�s benefit, such as the continue calls to Filter and Export plug-ins.
	*/
	typedef MACPASCAL OSErr (*AllocateBufferProc) (int32 size, BufferID *bufferID);

	/** Sets \c bufferID to be the ID for a buffer of the requested size. 
	* @param size The size of the buffer to allocate.
	* @param bufferID [OUT] The allocated buffer.
	* @returns \c noErr if allocation is successful;  an error code if allocation is unsuccessful.
	* @note Buffers are identified by pointers to an opaque type called BufferID. Buffer allocation is 
	* more likely to fail during phases where other blocks of memory are locked 
	* down for the plug-in's benefit, such as the continue calls to Filter and Export plug-ins.
	*/
	typedef MACPASCAL OSErr (*AllocateBufferProc64) (int64 size, BufferID *bufferID);

	/**
	* Returns a pointer to the beginning of the buffer. 
	* @param bufferID The ID of the buffer to lock.
	* @param moveHigh Has no effect.
	*/
	typedef MACPASCAL Ptr (*LockBufferProc) (BufferID bufferID, Boolean moveHigh);

	/**
	* Has no effect
	*/
	typedef MACPASCAL void (*UnlockBufferProc) (BufferID bufferID);

	/**
	* Releases the storage associated with a buffer. Using \c bufferID after 
	* calling \c FreeBufferProc may cause Photoshop to crash.
	* @param bufferID The buffer to free.
	*/
	typedef MACPASCAL void (*FreeBufferProc) (BufferID bufferID);

	/** Returns the amount of space available for buffers. This space may be fragmented, so 
	* an attempt to allocate all of the space as a single buffer may fail.
	* @returns Available buffer space.
	*/
	typedef MACPASCAL int32 (*BufferSpaceProc) (void);
	
	/** Returns the amount of space available for buffers. This space may be fragmented, so 
	* an attempt to allocate all of the space as a single buffer may fail.
	* @returns Available buffer space.
	*/
	typedef MACPASCAL int64 (*BufferSpaceProc64) (void);
	
	/** Attempts to insure that the requested amount of space is available as a single
	* contiguous block in the address space. The very first allocation of any
	* kind after calling this routine can cut the available contiguous space by an
	* arbitrary amount, and it's hard to guarantee that nothing else does any allocations
	* until you do. THIS IS A NOP WHEN CALLED IN THE 64 BIT VERSION because there's always
	* contiguous address space available
	*/
	typedef MACPASCAL OSErr (*ReserveSpaceProc) (int32 size);

/**
* @}
*/  // end ingroup
//@}
///@name Pseudo-Resource Suite Callbacks 
//@{
/** @defgroup ResourceSuite Resource Suite Callbacks
* This suite of callback routines provides support for storing and retrieving data from a 
* document. These routines provide pseudo-resources which plug-in modules can attach to 
* documents and use to communicate with each other.	<br><br>
* Each resource is a \c Handle of data and is identified by a 4 character code \c ResType and 
* a one-based index. The maximum number of pseudo-resources in a document for Photoshop is 
* 1000. Use the @ref PicaHandleSuite to manage the \c Handle data structure.
*
* The standard Resource Suite is found as a pointer in the parameter blocks of
* the plug-in modules.  You can access the routines within the Resource Suite in 
* the following manner:
* @code
	// FormatRecord global pointer.
	FormatRecord * gFormatRecord = NULL;

	DLLExport MACPASCAL void PluginMain (const int16 selector,
							             FormatRecordPtr formatParamBlock,
							             intptr_t* data,
							             int16* result)
	{
		// The Resource Suite is contained in the parameter block passed
		// in formatParamBlock.
		gFormatRecord = formatParamBlock;
		...

		// Get the Resource Suite from the parameter block, and call
		// countProc to count the number of "histResource" resources.
		int16 resourceCount = gFormatRecord->resourceProcs->countProc(histResource);
	    
		...
	}
@endcode
*/
/** @ingroup ResourceSuite 
* @{
*/

    /**	Counts the number of resources of a given type.
	* @param type The type of resource to count.
	* @returns The number of resources of the given type.
    */
	typedef MACPASCAL int16 (*CountPIResourcesProc) (ResType type);
    
    /**	 Gets the indicated resource for the current document. 
    * The plug-in host owns the returned handle. 
    * The handle should be treated as read-only.
	* @param type  The type of resource to get.
	* @param index The index of the resource to get.
	* @returns A handle to the resource for the current document;  NULL if no resource exists with the given type and index.
    */
	typedef MACPASCAL Handle (*GetPIResourceProc) (ResType type, int16 index);
    
    /**	Deletes the indicated resource in the current document. 
    * Note that since resources are identified by index rather than ID, 
    * this causes subsequent resources to be renumbered.
	* @param type  The type of resource to delete.
	* @param index The index of the resource to delete.
    */
	typedef MACPASCAL void (*DeletePIResourceProc) (ResType type, int16 index);
    
    /**	Adds a resource of the given type at the end of the list for that type. 
    * The contents of \c data are duplicated so that the plug-in retains control 
    * over the original handle. The maximum number of resources in a Photoshop document is 1000. 
	* @param type  The type of resource to add.
	* @param data The resource data to add.
    * @returns \c memFullErr if there is not enough memory or the document already has too many plug-in resources. 
    */
	typedef MACPASCAL OSErr (*AddPIResourceProc) (ResType type, Handle data);
/**
* @}
*/  // end ingroup
//@}
	// Property suite:

///@name Property Suite Callbacks 
//@{

/** @defgroup PropertySuite Property Suite Callbacks
* The Property suite allows a plug-in module to get and set certain values in 
* the plug-in host.  Properties are defined as either a 32 bit integer, \c simpleProperty, 
* or a handle, \c complexProperty. 
* Properties are identified by a signature and key, which form a pair to identify 
* the property of interest. Some properties, like channel names and path names, are 
* also indexed; you must supply the signature, key, and index (zero-based) to access
* or update these properties. For a list of keys,  See @ref PropertyKeys.
* The property suite is available to all plug-ins.
* @note The term property is used with two different meanings in this toolkit. Besides its 
* use in the Property suite, the term is also a part of the PiPL data structure, 
* documented in 
*<a href="../Plug-in Resource Guide.pdf">Cross Application Plug-in Development Resource Guide</a>. There is no connection between PiPL properties
* and the Property suite.
*
* The standard Property Suite is found as a pointer in the parameter blocks of
* the plug-in modules.  You can access the routines within the Property Suite in 
* the following manner:
* @code
	PropertyProcs *propSuite;

	DLLExport MACPASCAL void PluginMain (const int16 selector,
							             ExportRecordPtr exportParamBlock,
							             intptr_t* data,
							             int16* result)
	{
		...

		// Get the Property Suite from the parameter block
		propSuite = exportParamBlock->propertyProcs;

		// Get the value for the simple property propNumberOfPaths from Photoshop, 
		// return value goes in count.
		int32 *count;
		propSuite->getPropertyProc('8BIM', propNumberOfPaths, 0, count, nil);
		...
	}
@endcode
* @{
*/

	/** Gets information about the document currently being processed.	 
	* Properties are returned as a intptr_t, \c simpleProperty, or a handle, \c complexProperty.
    * In the case of a complex, handle based property, your plug-in is responsible for disposing the handle. 
	* Use the @ref DisposePIHandleProc callback defined in the Handle suite. \n\n
	* Properties involving strings, such as channel names and path names, are returned in a 
	* Photoshop handle. The length of the handle and size of the string are obtained with 
	* @ref GetPIHandleSizeProc.  There is no length byte, nor is the string zero terminated.
	* @note This callback replaces the non-suite callback, which has been renamed 
	* \c getPropertyObsolete in the plug-in parameter blocks. The obsolete callback 
	* pointer is still correct, and is maintained for backwards compatibility.
	* @param signature The host signature.  The signature for Photoshop is '8BIM' (0x3842494D).
	* @param key The key for the property you wish to get. See @ref PropertyKeys.
	* @param index The index for the property you wish to get.
	* @param simpleProperty	 [OUT] The returned value when the property is simple.
	* @param complexProperty [OUT] The returned value when the property is complex.
	*/
	typedef MACPASCAL OSErr (*GetPropertyProc) (PIType signature,
												PIType key,
												int32 index,
												intptr_t *simpleProperty,
												Handle *complexProperty);

	/**	Updates information in the plug-in host about the document currently being processed.
	* @param signature The host signature.  The signature for Photoshop is '8BIM' (0x3842494D).
	* @param key The key for the property you wish to update. The plug-in can only set certain, modifiable properties See @ref PropertyKeys.
	* @param index The index for the property you wish to update.
	* @param simpleProperty	 The value to set if the property is simple.
	* @param complexProperty  The value to set if the property is complex.
	*/
	typedef MACPASCAL OSErr (*SetPropertyProc) (PIType signature,
												PIType key,
												int32 index,
												intptr_t simpleProperty,
												Handle complexProperty);

/**
* @}
*/  // end defgroup
//@}


///@name Image Services Suite Callbacks 
//@{
/** @defgroup ImageServicesSuite Image Services Suite Callbacks
* The Image Services Suite provides access to some image procession routines inside Photoshop. 
* The Image Services Suite provides 1D and 2D versions for each of the defined callbacks. See
* the \c ImageServicesProcs data structure. \n\n
* The Image Services suite is available in Adobe Photoshop version 3.0.4 and later.
* These routines are used in the distortion filters that ship with Adobe Photoshop 5.0.
*
* The standard Image Services Suite is found as a pointer in the parameter blocks of
* the plug-in modules.  You can access the routines within the Image Services Suite in 
* the following manner:
* @code
	ImageServicesProc *imageServicesSuite;

	DLLExport MACPASCAL void PluginMain (const int16 selector,
							             ExportRecordPtr exportParamBlock,
							             intptr_t* data,
							             int16* result)
	{
			...

			// Get the Image Services Suite from the parameter block
			imageServicesSuite = exportParamBlock->imageServicesProc;

			// Call the interpolate1DProc, which uses PIResampleProc.
			imageServicesSuite->interpolate1DProc(...);
			...
		}
@endcode
* @{
*/
	/**	Provides 1D or 2D image interpolation, depending on the value passed in the \c coords parameter.
	* For a source coordinate <fv, fh>, Photoshop writes to the destination plane if and only if:
	* \code source->bounds.top <= fv <= source.bounds.bottom - 1
	* \endcode and
	* \code
	* source->bounds.left <= fh <= source.bounds.right - 1
	* \endcode
	* The two \c PIResampleProc callback functions differ in how they generate 
	* the sample coordinates for each pixel in the target area. \n \n
	* When calling this function through the \c interpolate1DProc() callback, 
	* use an array that contains one fixed point number for each pixel. This callback 
	* forms a sample coordinate by taking the vertical coordinate of the destination pixel 
	* and the horizontal coordinate from the list. Thus
	\verbatim
	SampleLoc1D(v, h) = <v, coords[(h - area->left) +
		(v - area->top) * (area->right - area->left)]>
	\endverbatim
	*	
	* When calling through the \c interpolate2DProc() callback,
	* use an array that contains two fixed point numbers for each pixel. The sample
	* coordinate is formed as follows:
	\verbatim
	SampleLoc2D(v, h) = 
		<coords[2*((h - area->left) +
			(v - area->top) * (area->right - area->left))],
	 	coords[2*((h - area->left) +
			(v - area->top) * (area->right - area->left)) + 1]>
	\endverbatim
	*
	* You can build a destination image using relatively small input buffers
	* by passing in a series of input buffers, since these callbacks leave any pixels 
	* whose sample coordinates are out of bounds untouched.\n\n
	* Make sure that you have appropriate overlap between the \c source buffers so that sample 
	* coordinates don�t "fall through the cracks." 
	* This matters even when point sampling, since the coordinate test is applied without 
	* regard to the method parameter. This allows you to get consistent results when 
	* switching between point sampling and linear interpolation. If Photoshop didn�t do this, 
	* a plug-in could end up modifying pixels using point sampling that wouldn�t get modified 
	* when using linear interpolation.	\n\n
	* You also want to pin coordinates to the overall source bounds so that you manage 
	* to write everything in the destination.
	* @note To determine whether you should use point sampling or linear interpolation, you 
	* might want to check what the user has set in their Photoshop preferences. This is set 
	* in the General Preferences dialog, under the Interpolation pop-up menu. You can 
	* retrieve this value using the @ref PropertySuite @ref GetPropertyProc function with the 
	* @ref propInterpolationMethod key.
	*	
	* @param source	 A pointer to the source image.
	* @param destination  [OUT] A pointer to the destination image.
	* @param area A pointer to an area in the destination image plane 
	* that you wish to modify. The \c area rectangle must be contained within 
	* \c destination->bounds.
	* @param coords	A pointer to an array you create that controls the image resampling. 
	* When calling \c interpolate1DPRoc(), the array contains one fixed point number 
	* for each pixel in the area rectangle, in top to bottom, left to right order. 
	* When calling \c interpolate2DPRoc(), the array contains two fixed point numbers 
	* for each pixel in the area containing the vertical and horizontal sample coordinate. 
	* @param method	 The sampling method to use. If 0, uses point sampling. If 1, uses 
	* linear interpolation. If source coordinates are not integers, Photoshop rounds to 
	* the nearest integer for the point sampling method. The linear interpolation method 
	* performs the appropriate bilinear interpolation using up to four source pixels.
	* The bicubic interpolation method is not currently supported.
	* @returns Non-zero error upon failure.
	*/
	typedef MACPASCAL OSErr (*PIResampleProc) (PSImagePlane *source,
											   PSImagePlane *destination,
											   Rect *area,
											   Fixed *coords,
											   int16 method);

	typedef MACPASCAL OSErr (*PIResampleMultiProc) (PSImageMultiPlane *source,
												   PSImageMultiPlane *destination,
												   Rect *area,
												   Fixed *coords,
												   int16 method);

	typedef MACPASCAL OSErr (*PIResampleMulti32Proc) (PSImageMultiPlane32 *source,
												   PSImageMultiPlane32 *destination,
												   VRect *area,
												   int64 *coords,	// s47.16 numbers
												   int16 method);
	
/**
* @}
*/  // end defgroup
//@}	
	
// Channel ports suite:
///@name Channel Ports Suite Callbacks 
//@{
/** @ingroup ChannelPortsSuite 
* @{
*/
	/**
	* Reads a rectangular area (tile) of pixels from a read port, and writes them to a destination buffer, 
	* based on a scaling and a description of the memory to write. 
	* First, the destination space rectangle, provided in \c scaling, is projected back to the source 
	* space. Then the overlap with the channel read port is copied to a specified memory buffer.
	* @param port The channel port to read from.
	* @param scaling  A scaling between source and destination rectangles.
	* @param writeRect The rectangular area (or tile) of the port to read. Usually this is the
	* same as the rectangle specified in \c scaling.sourceRect.
	* @param destination A description of the memory to write.  The pixels read from the port are 
	* written into the memory buffer provided by \c destination.data
	* @param wroteRect [OUT] The rectangular area (tile) in the destination space that was actually 
	* written. If the plug-in reads an area that fits entirely within the channel, this matches the 
	* \c scaling.destinationRect.
	* If the plug-in reads an area that doesn't fit entirely within the channel,
	* the destination pixels without corresponding source pixels won't be written to 
	* the \c destination.data buffer, and \c wroteRect reflects the actual area written.
	* @returns An error upon failure.
	*/
	typedef MACPASCAL OSErr (*ReadPixelsProc) (ChannelReadPort port,
											   const PSScaling *scaling,
											   const VRect *writeRect,
											   		/* Rectangle in destination coordinates. */
											   const PixelMemoryDesc *destination,
											   VRect *wroteRect);

	/**
	* Writes a rectangular area (tile) of pixels to a given port based on a memory description.
	* This callback does not support scaling. If the rectangle maps to any pixels beyond 
	* the bounds of the port, they won�t be written.
	* @param port The channel write port.
	* @param writeRect [IN/OUT] As input, provides the rectangular area (tile) of \c source.data the pixels 
	* are written from. As output, reflects the area of the port actually written.
	* If the input rectangle maps to pixels beyond the bounds of the port, the output rectangle reflects
	* the area actually written.
	* @param source A description of the memory to write. The actual pixels that are written to the port 
	* are provided in \c source.data.
	* @returns An error upon failure.
	*/
	typedef MACPASCAL OSErr (*WriteBasePixelsProc) (ChannelWritePort port,
													const VRect *writeRect,
													const PixelMemoryDesc *source);

	/**
	* Returns the read port corresponding to a write port.
	* @param readPort [OUT] The read port.
	* @param writePort The write port for which to retrieve the corresponding read port.
	* @returns An error upon failure.
	*/
	typedef MACPASCAL OSErr (*ReadPortForWritePortProc) (ChannelReadPort *readPort,
														 ChannelWritePort writePort);
	
//@}	
#ifdef __cplusplus
}
#endif

//-------------------------------------------------------------------------------
//	Structures -- Buffer procs.
//-------------------------------------------------------------------------------

/** @ingroup BufferProcs */
#define kCurrentBufferProcsVersion 2   /**< Current version of the Buffer Procs */

/// Unique identifier for the buffer procs.
#define kPIBufferSuite 			"Photoshop Buffer Procs for Plug-ins"
/// The version of the Buffer Procs.
#define kPIBufferSuiteVersion	kCurrentBufferProcsVersion


/** @ingroup BufferProcs */
/** The set of routines available in the Buffer Procs */
typedef struct BufferProcs
{

	int16 bufferProcsVersion;		/**< The version number for the Buffer Procs. */
	
	int16 numBufferProcs;			/**< The number of routines in this structure. */

	AllocateBufferProc allocateProc;	/**< Function pointer for the allocate routine. */

	LockBufferProc lockProc;		/**< Function pointer for the lock routine. */

	UnlockBufferProc unlockProc;	/**< Function pointer for the unlock routine. */

	FreeBufferProc freeProc;		/**< Function pointer for the free routine. */
	
	BufferSpaceProc spaceProc;		/**< Function pointer for the space routine. */
	
	ReserveSpaceProc reserveProc;	/**< Function pointer for space reservation */

	AllocateBufferProc64 allocateProc64;	/**< Function pointer for the allocate routine. */

	BufferSpaceProc64 spaceProc64;		/**< Function pointer for the space routine. */
} BufferProcs;

/** @ingroup BufferProcs 
* Current number of routines in the Buffer Procs.
*/
#define kCurrentBufferProcsCount \
	((sizeof(BufferProcs) - offsetof(BufferProcs, allocateProc)) / sizeof(void *)) 

//-------------------------------------------------------------------------------
//	Structures -- Resource Procs.
//-------------------------------------------------------------------------------

/** @ingroup ResourceSuite */
#define kCurrentResourceProcsVersion 3	/**< The current version of the resource suite.*/

/// Unique identifier for the Resource suite
#define kPIResourceSuite 			"Photoshop Resource Suite for Plug-ins"
/// Version number for the Resource suite.
#define kPIResourceSuiteVersion		kCurrentResourceProcsVersion

/** @ingroup ResourceSuite */
/** The set of routines available in the Resource suite. */
typedef struct ResourceProcs
{
	
	int16 resourceProcsVersion;	     /**< The current version of the resource suite. */
	
	int16 numResourceProcs;		     /**< The number of routines in the resource suite. */
	
	CountPIResourcesProc countProc;	 /**< Function pointer to count the number of resources of a given type. */
	
	GetPIResourceProc getProc;		 /**< Function pointer to get an indicated resource. */
	
	DeletePIResourceProc deleteProc; /**< Function pointer to delete a resource. */
	
	AddPIResourceProc addProc;		 /**< Function pointer to add a resource of a given type. */
	
} ResourceProcs;

/** @ingroup ResourceSuite 
* Current number of routines in the Resource Suite.
*/
#define kCurrentResourceProcsCount \
	((sizeof(ResourceProcs) - offsetof(ResourceProcs, countProc)) / sizeof(void *)) 

// Reserved resource types:

#define kDayStarColorMatchingResource 'DCSR'
#define kPhotoDeluxeResource 'PHUT'

//-------------------------------------------------------------------------------
//	Structures -- Handle Procs.
//-------------------------------------------------------------------------------

/** @ingroup HandleSuite */
#define kCurrentHandleProcsVersion 1   /**< The current version of the handle suite */

/// Unique identifier for the Handle suite.
#define kPIHandleSuite 				"Photoshop Handle Suite for Plug-ins"
/// The version of the Handle suite.
#define kPIHandleSuiteVersion		kCurrentHandleProcsVersion

/** @ingroup HandleSuite */
/// The set of routines available in the Handle suite.
typedef struct HandleProcs
{
	
	int16 handleProcsVersion;	/**< The version number for the Handle Suite. */
	
	int16 numHandleProcs;		/**< The number of routines in the Handle Suite. */
	
	NewPIHandleProc newProc;	/**< Function pointer for the new handle routine */
	
	DisposePIHandleProc disposeProc;	/**< Function pointer for the dispose routine. */

	GetPIHandleSizeProc getSizeProc;	/**< Function pointer for the get size routine. */
	
	SetPIHandleSizeProc setSizeProc;	/**< Function pointer for the set size routine. */
	
	LockPIHandleProc lockProc;			/**< Function pointer for the lock routine. */
	
	UnlockPIHandleProc unlockProc;		/**< Function pointer for the unlock routine. */
	
	RecoverSpaceProc recoverSpaceProc;	/**< Function pointer for the recover space routine. */
	
	DisposeRegularHandlePIHandleProc disposeRegularHandleProc; /**< Function pointer for the dispose regular handle routine. */
	
} HandleProcs;

/** @ingroup HandleSuite 
* Current number of routines in the Handle Suite.
*/
#define kCurrentHandleProcsCount \
	((sizeof(HandleProcs) - offsetof(HandleProcs, newProc)) / sizeof(void *)) 

//-------------------------------------------------------------------------------
//	Structures -- Image Services suite.
//-------------------------------------------------------------------------------

/** @ingroup ImageServicesSuite */
#define kCurrentImageServicesProcsVersion 1	  /**< Current version for the Image Services Suite */

/// Unique identifier for the Image Services suite.
#define kPIImageServicesSuite 				"Photoshop Image Services Suite for Plug-ins"
///  Version of the Image Services suite.
#define kPIImageServicesSuiteVersion		kCurrentImageServicesProcsVersion
	
/** @ingroup ImageServicesSuite */
/** The set of routines available in the Image Services suite. */
typedef struct ImageServicesProcs
{
	
	int16 imageServicesProcsVersion;		/**< The version number for the Image Services Suite. */
	int16 numImageServicesProcs;			/**< The version number for the Image Services Suite. */
		
	PIResampleProc interpolate1DProc;		/**< Function pointer for the 1D interpolate routine. */
	PIResampleProc interpolate2DProc;		/**< Function pointer for the 2D interpolate routine. */
	
	PIResampleMultiProc interpolate1DMultiProc;	 /**< Function pointer for the 1D multi interpolate routine. */
	PIResampleMultiProc interpolate2DMultiProc;	 /**< Function pointer for the 2D multi interpolate routine. */
	
	PIResampleMulti32Proc interpolate1DMulti32Proc;	 /**< Function pointer for the 1D multi interpolate 32-bit routine. */
	PIResampleMulti32Proc interpolate2DMulti32Proc;	 /**< Function pointer for the 1D multi interpolate 32-bit routine. */
	
} ImageServicesProcs;

/** 
* @ingroup ImageServicesSuite 
* Current number of routines in the Images Services Suite */
#define kCurrentImageServicesProcsCount \
	((sizeof(ImageServicesProcs) - offsetof(ImageServicesProcs, interpolate1DProc)) / sizeof(void *)) 
	
//-------------------------------------------------------------------------------
//	Structures -- Property procs.
//-------------------------------------------------------------------------------

/** @ingroup PropertySuite */
#define kCurrentPropertyProcsVersion 1	 /**< Current version of the Property Suite */

/** @ingroup PropertySuite */
/// Unique identifier for the Property Suite.
#define kPIPropertySuite 				"Photoshop Property Suite for Plug-ins"
/** @ingroup PropertySuite */
/// Version number for the Property Suite.
#define kPIPropertySuiteVersion			kCurrentPropertyProcsVersion

/** @ingroup PropertySuite */
/** The set of routines available in the Property Suite. */
typedef struct PropertyProcs
{
	
	int16 propertyProcsVersion;		   /**< The version number for the Property Suite. */
	int16 numPropertyProcs;			   /**< The number of routines in  the Property Suite. */
	
	GetPropertyProc	getPropertyProc;   /**< Function pointer to get a property. */
	SetPropertyProc setPropertyProc;   /**<	Function pointer to set a property. */
	
} PropertyProcs;

/** @ingroup PropertySuite 
* Current number of routines in the Property Suite. */
#define kCurrentPropertyProcsCount \
	((sizeof(PropertyProcs) - offsetof(PropertyProcs, getPropertyProc)) / sizeof(void *))

//-------------------------------------------------------------------------------
//	Structures -- Channel Ports.
//-------------------------------------------------------------------------------

/** @ingroup ChannelPortsSuite */
#define kCurrentChannelPortProcsVersion 1	/**< Current version of the Channel Ports Suite */

/** @ingroup ChannelPortsSuite */
/// Unique identifier for the Channel Ports Suite.
#define kPIChannelPortSuite 			"Photoshop Channel Ports Suite for Plug-ins"
/** @ingroup ChannelPortsSuite */
/// Version number for the Channel Ports Suite.
#define kPIChannelPortSuiteVersion		kCurrentChannelPortProcsVersion

/** @ingroup ChannelPortsSuite */
/** The set of routines available for teh Channel Ports Suite. */	
typedef struct ChannelPortProcs
{
	
	int16 channelPortProcsVersion;		/**< The version number for the Channel Ports Suite. */
	int16 numChannelPortProcs;			/**< The number of routines in the Channel Ports Suite. */
	
	ReadPixelsProc readPixelsProc;		/**< Function pointer to the read pixels routine. */
	WriteBasePixelsProc writeBasePixelsProc;  /**< Function pointer to the write pixels routine. */
	ReadPortForWritePortProc readPortForWritePortProc;	/**< Function pointer to routine that gets a write port. */
	
} ChannelPortProcs;

/** @ingroup ChannelPortsSuite 
* Current number of routines in the Channel Ports Suite. */
#define kCurrentChannelPortProcsCount \
	((sizeof(ChannelPortProcs) - offsetof(ChannelPortProcs, readPixelsProc)) / sizeof(void *)) 
	
//-------------------------------------------------------------------------------
//	Suite - Matrix Math
//-------------------------------------------------------------------------------

/** @defgroup MatrixMathSuite Matrix Math Suite Callbacks
* The Matrix Math Suite provides callbacks to perform matrix math operations on 3x3 matrices.
*
* <b> Accessing the Suite </b> \n\n
* The Matrix Math suite is referred to as:
* @code
  #define kPSMatrixMathSuite	"9cfaa249-e6f1-11d2-b8eb-0060b0c1f95d"
@endcode
* The current version of the Matrix Math suite:
* @code
  #define	kPSMatrixMathSuiteVersion	1 
@endcode
* The suite is acquired as follows:
* @code
  PSMatrixMathProcs *sPSMatrixMath;
  error = sSPBasic->AcquireSuite(kPSMatrixMathSuite,
  								 kPSMatrixMathSuiteVersion, 	  
  								 &sPSErrors);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/

/// Unique identifier for the Matrix Math suite.
#define kPSMatrixMathSuite			"9cfaa249-e6f1-11d2-b8eb-0060b0c1f95d"
#define	kPSMatrixMathSuiteVersion	1  /**< Current version of the Matrix Math Suite. */

/** The set of routines available for the Matrix Math Suite. */
typedef struct PSMatrixMathProcs
	{
	/* kPSMatrixMathSuiteVersion == 1 functions */
	
	/**	Performs an inverse operation on the matrix \c m.	If result == NULL, 
	* the solution is put in \c m.
	* @param m The 3x3 matrix to invert.
	* @param result [OUT] A 3x3 matrix with the result of the inversion.
	* @return 
	*/
	// if result == NULL solution is put in m 
	SPAPI Boolean (*Inverse) (PIAffineMatrix *m,
								PIAffineMatrix *result);
	
	/**	Checks if the two matrices passed in are equal.
	* @param m1 A 3x3 matrix.
	* @param m2 A 3x3 matrix.
	* @return True if \c m1 and \c m2 are equal; False if they are not equal.
	* 
	*/
	SPAPI Boolean (*Equals) (const PIAffineMatrix *m1,
								const PIAffineMatrix *m2);

	/**	 Multiplies the matrix \c m by \c scalar. Works in-place if result == NULL.
	* @param scalar The scalar by which to multiply \c m.
	* @param m The 3x3 matrix.
	* @param result [OUT] A 3x3 matrix with the result of the scalar multiply.
	*/
	// works in-place if result == NULL
	SPAPI void (*ScalarMultiply) (const real64 scalar,
										PIAffineMatrix *m,
											PIAffineMatrix *result);

	/**	Multiplies the two matrices \c m1 and \c m2. 
	* If result == NULL the solution is put in \c m2.
	* @param m1 A 3x3 matrix.
	* @param m2 A 3x3 matrix.
	* @param result [OUT] A 3x3 matrix with the result of the matrix multiplication.
	*/
	// if result == NULL solution is put in m2 
	SPAPI void (*MatrixMultiply) (const PIAffineMatrix *m1,
										PIAffineMatrix *m2,
											PIAffineMatrix *result);
	
	/**	 Multiplies the point \c p by matrix \c m. 
	* If result == NULL the solution is put in \c m.
	* @param p The point to multiply by \c m.
	* @param m The 3x3 matrix.
	* @param result [OUT] A point with the result of the point multiply.
	*/
	// if result == NULL solution is put in m 
	SPAPI void (*PointMultiply) (PIFloatPoint *p,
										const PIAffineMatrix *m,
											PIFloatPoint *result);
	
	
	// if result == NULL solution is put in p 
	SPAPI void (*PointsMultiply) (PIFloatPoint *p,
											int32 count,
												const PIAffineMatrix *m,
													PIFloatPoint *result);

	} PSMatrixMathProcs;

/** @} */

//-------------------------------------------------------------------------------
//
//	Defines -- Filter padding.
//
//	The following constants indicate what sort of padding to use.  Values 0
// 	through 255 specify a constant value.  Negative values imply special
// 	operations.
//
// 	If the plug-in does not want padding and does not want errors, then
// 	exterior areas will contain arbitrary values.
//
//-------------------------------------------------------------------------------

///@anchor FilterPadding
///@name Filter Padding Constants 
//@{
#define plugInWantsEdgeReplication			-1
#define plugInDoesNotWantPadding			-2	 /**< Data should be left random. */
#define plugInWantsErrorOnBoundsException	-3	 /**< Error should be signaled for out-of-bounds request. */
//@}

//-------------------------------------------------------------------------------
//	Defines -- Sampling flag
//-------------------------------------------------------------------------------

///@name Sampling Flag Constants 
//@{
#define hostDoesNotSupportSampling		0	 /**< Host does not support sampling */
#define hostSupportsIntegralSampling	1	 /**< Host supports integral sampling */
#define hostSupportsFractionalSampling	2	 /**< Host supports non-integral sampling steps. */
//@}

//-------------------------------------------------------------------------------
//	Defines -- Layout values for filters and export modules.
//-------------------------------------------------------------------------------

// Traditional = Rows, columns, planes with colbytes = # planes:

///@anchor LayoutConstants 
///@name Layout Constants for filters and export modules 
//@{
#define piLayoutTraditional				0
#define piLayoutRowsColumnsPlanes		1
#define piLayoutRowsPlanesColumns		2
#define piLayoutColumnsRowsPlanes		3
#define piLayoutColumnsPlanesRows		4
#define piLayoutPlanesRowsColumns		5
#define piLayoutPlanesColumnsRows		6
//@}

//-------------------------------------------------------------------------------
//	Defines -- Property suite -- PIInterface color property.
//-------------------------------------------------------------------------------
/** 
* Interface color definition used with Property Suite property @ref propInterfaceColor.
*/
typedef struct PIInterfaceColor
{
	RGBtuple color32;	 /**< Interface color in RGB for full color depth. */
	RGBtuple color2;	 /**< Interface color in RGB for B/W display. */

} PIInterfaceColor;

// Interface color selectors:
///@anchor InterfaceColorIndex
///@name Interface Color Index for propInterfaceColor 
//@{
#define kPIInterfaceButtonUpFill		1
#define kPIInterfaceBevelShadow 		2
#define kPIInterfaceIconFillActive		3
#define	kPIInterfaceIconFillDimmed  	4
#define	kPIInterfacePaletteFill 		5
#define	kPIInterfaceIconFrameDimmed 	6
#define	kPIInterfaceIconFrameActive 	7
#define	kPIInterfaceBevelHighlight  	8
#define	kPIInterfaceButtonDownFill  	9
#define	kPIInterfaceIconFillSelected	10
#define kPIInterfaceBorder				11
#define	kPIInterfaceButtonDarkShadow 	12
#define	kPIInterfaceIconFrameSelected 	13
#define	kPIInterfaceRed					14
//@}
//-------------------------------------------------------------------------------
//	Defines -- Photoshop -- SuitePEA caller and selector strings for Photoshop.
//-------------------------------------------------------------------------------
///@name Automation Module Caller and Selector
//@{
/** @ingroup AutomationModule */
#define kPSPhotoshopCaller			"PS Photoshop" /**< Caller portion of message action 
														sent to an Automation plug-in  
														entry point. */
/** @ingroup AutomationModule */
#define kPSDoIt						"Do It"		  /**< Selector portion of message action
													   sent to an Automation plug-in 
													   entry point.  When the plug-in receives
													   this message, it should execute
													   its core functionality. */
//@}

//-------------------------------------------------------------------------------
//	Action plug-in specific PiPL properties
//-------------------------------------------------------------------------------

///@ingroup PiPLActionKeys
// 'prst' -- Always stay loaded property:
/** 
* Indicates whether the plug-in should always stay loaded; key value is 'prst'.
* This property key reflects the \c Persistent property in the PiPL resource file.
* The data for the property has type
*/
#define PIPersistentProperty		0x70727374L

///@ingroup PiPLActionKeys
// 'reen' -- Allow reentrant:
/** 
* Indicates whether the plug-in can be reentrant; key value is 'reen'.
* This property key reflects the \c Reentrant property in the PiPL resource file.
* The data for the property has type
*/
#define PIReentrantProperty			0x7265656EL

///@ingroup PiPLActionKeys
// 'adll' -- use altered search path when loading the plug-in (Windows only):
/** 
* Indicates whether the plug-in loader should use the altered search path when loading the
* plug-in.
* This property key reflects the \c LoadWithAlteredSearchPath property in the PiPL resource file.
* The data for the property has type bool
*/
#define PILoadWithAlteredSearchPath		0x61646C6CL

//-------------------------------------------------------------------------------
//	Defines -- Image Resources for Annotation.
//-------------------------------------------------------------------------------

/* Major & Minor version number */
#define	kPIAnnotMajorVersion	0x0002
#define kPIAnnotMinorVersion	0x0001

/* keys */
#define	PIAnnotTextPopup	'txtA' /* text with popup annotation */
#define	PIAnnotSound		'sndA' /* sound annotation */
#define	PIAnnotTextContent	'txtC' /* text as content */
#define	PIAnnotSoundFile	'sndF' /* content as a sound file */
#define	PIAnnotSoundMem		'sndM' /* content as a sound in memory */
#define	PIFilterFlate		'fltD' /* default parameters */
#define	PIFilterLZW			'lzwD' /* default parameters */
#define PIFilterNone		'none' /* no compression */
#define PIFilterUndef		'    ' /* treated as 'none' */

#define PIMaxSize32Property	 'ms32' 	/* \<VPoint\> Max rows and cols supported by this plug-in. 	*/
#define PIMinSize32Property  'mn32'     /* \<VPoint\> Min rows and cols supported by this plug-in.     */


//-------------------------------------------------------------------------------
//	stack renderer plug-in specific PiPL properties
//-------------------------------------------------------------------------------
/** @defgroup PiPLStackRendererKeys Stack Renderer PiPL Properties
* These PiPL properties are used for Stack Renderer plug-in modules.
* Stack Renderer plug-in modules are defined on Import (Acquire) plug-in modules,
* so these keys can only be used when the plug-in Kind is defined as \c Acquire.
*/

///@ingroup PiPLStackRendererKeys
/**
* Identifies the plug-in as a Stack Renderer.  
* This property key reflects the \c StackRenderer property in the PiPL resource file,
* which can only be used with Import (Acquire) plug-in modules. This key
* informs Photoshop that what initially appears to be an Import plug-in is a Stack
* Renderer plug-in. The existence of this property key means that it is enabled.
*/
#define PIStackRendererProperty		'sRnd'

//-------------------------------------------------------------------------------
//	stack renderer and file format plug-in specific PiPL properties
//-------------------------------------------------------------------------------

///@ingroup PiPLStackRendererKeys
/**
* Indicates whether the plug-in edits files or stacks. 
* Applies to file formats, smart objects and image stacks.
* This property key reflects the \c EditinPlugin property in the PiPL resource file.
* The existence of this property key means it is enabled. <br><br>
* If this property is present, then the plugin is called to edit the file or stack,
* rather than opening it in Photoshop.
*/
#define PIEditInPluginProperty				'ediP'

/// @ingroup PiPLFormatKeys
/**
* Indicates whether the plug-in launches an editor. 
* This property key reflects the \c PluginLaunchesEditor property in the PiPL resource file.
* The existence of this property key means it is enabled. <br><br>
* If this property is present, then the plug-in is called with a file reference so
* it can launch an external editor. This property key applies to file formats and 
* smart objects.  When this property is present, the Format plug-in is called with selector
* formatSelectorLaunchExternalEditor.
*/
#define PIPluginLaunchesEditorProperty		'piLe'

//-------------------------------------------------------------------------------

#endif // __PIGeneral_h__
