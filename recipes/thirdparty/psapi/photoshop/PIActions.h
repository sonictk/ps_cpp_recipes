// ADOBE SYSTEMS INCORPORATED
// (c) Copyright  1993 - 2015 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 *	\file PIActions.h
 *
 *	\brief This file contains the public definitions and structures
 *		used by all plug-ins for scripting control and access.
 *
 *	Distribution:
 *		PUBLIC
 *
 *	\details
 *		This file must be included to correctly compile.
 *		It is included by all the plug-in headers.
 *
 */

#ifndef __PIActions__ // Already defined?
#define __PIActions__

#if PRAGMA_ONCE
#pragma once
#endif

#ifndef MSWindows
#define MSWindows (MSDOS || WIN32)
#endif

#ifndef INSIDE_PHOTOSHOP
#define INSIDE_PHOTOSHOP 0
#endif

#ifndef qiOS
#define qiOS 0
#endif

#ifdef Rez

#if !MSWindows && !qiOS
#include <CoreServices/CoreServices.r>
#endif

#else	// Rez

#if !MSWindows && !qiOS && !PS_OS_ANDROID
#include <CoreServices/CoreServices.h>
#endif

#if PS_OS_ANDROID
#include <MacTypes.h>
#endif // PS_OS_ANDROID

#include "PITypes.h"
#include "SPTypes.h"
#include "SPPlugs.h"

#endif // Rez

/// The following are new with Photoshop 17.0
#define  typeBookmark                  'bkmk'	/// eventual replacement for typeAlias
#define  typeXPlatFileSpec             'xpfs'	/// eventual replacement for typeFSRef

//-------------------------------------------------------------------------------
//	Flags for dictionary parameters.
//-------------------------------------------------------------------------------

/**
* @defgroup AETEResourceDefines Definitions for the aete Terminology Resource
* The following defines provide useful short cuts for creating \c aete Terminology
* Resources.
*/
///@anchor ResourceParameterFlags
///@name Parameter Flags used in the Terminology Resource.

/** Flags to describe a parameter with a single value. */
#define flagsSingleParameter					\
	required,			singleItem,		notEnumerated,	reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe a parameter with a list value. */
#define flagsListParameter						\
	required,			listOfItems,	notEnumerated,	reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe a parameter with a value taken from an enumeration. */
#define flagsEnumeratedParameter				\
	required,			singleItem,		enumerated,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe a parameter with a list value,
* where values are taken from an enumeration. */
#define flagsEnumeratedListParameter			\
	required,			listOfItems,	enumerated,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe an optional parameter with a single value. */
#define flagsOptionalSingleParameter			\
	optional,			singleItem,		notEnumerated,	reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe an optional parameter with a list value. */
#define flagsOptionalListParameter				\
	optional,			listOfItems,	notEnumerated,	reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe an optional parameter with a value taken from an enumeration. */
#define flagsOptionalEnumeratedParameter		\
	optional,			singleItem,		enumerated,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

/** Flags to describe an optional parameter with a list value,
* where values are taken from an enumeration. */
#define flagsOptionalEnumeratedListParameter	\
	optional,			listOfItems,	enumerated,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	prepositionParam,	notFeminine,	notMasculine,	singular

// Flags for object properties:
///@anchor ResourcePropertyFlags
///@name Property Flags used in the Terminology Resource.

/** Flags to describe a property with a single value. */
#define flagsSingleProperty						\
	reserved,			singleItem,		notEnumerated,	readWrite,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	noApostrophe,		notFeminine,	notMasculine,	singular

/** Flags to describe a property with a value that is a list. */
#define flagsListProperty						\
	reserved,			listOfItems,	notEnumerated,	readWrite,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	noApostrophe,		notFeminine,	notMasculine,	singular

/** Flags to describe a property with a single value taken from an enumeration. */
#define flagsEnumeratedProperty					\
	reserved,			singleItem,		enumerated,		readWrite,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	noApostrophe,		notFeminine,	notMasculine,	singular

/** Flags to describe a property with a value that is a list, where values are
taken from an enumeration. */
#define flagsEnumeratedListProperty				\
	reserved,			listOfItems,	enumerated,		readWrite,	\
	reserved,			reserved,		reserved,		reserved,	\
	reserved,			reserved,		reserved,		reserved,	\
	noApostrophe,		notFeminine,	notMasculine,	singular

// Flags for direct dictionary parameters:

///@name Direct Dictionary Flags used in the Terminology Resource

/** Flags to describe an optional direct dictionary parameter that takes
a single value from an enumeration, and has the possibility of changing state. */
#define flagsOptionalEnumeratedChangesDirect	\
	directParamOptional,	singleItem,	enumerated,	changesState,	\
	reserved,				reserved,	reserved,	reserved,		\
	reserved,				reserved,	reserved,	reserved,		\
	reserved,				reserved,	reserved,	reserved

/** Flags to describe a direct dictionary parameter that takes
a single value from an enumeration, and has the possibility of changing state. */
#define flagsEnumeratedChangesDirect	\
	directParamRequired,	singleItem,	enumerated,	changesState,	\
	reserved,				reserved,	reserved,	reserved,		\
	reserved,				reserved,	reserved,	reserved,		\
	reserved,				reserved,	reserved,	reserved

/** Flags to describe a direct dictionary parameter that takes
a single value from an enumeration, and does not change state. */
#define flagsEnumeratedDirect	\
	directParamRequired,	singleItem,	enumerated,	doesntChangeState,	\
	reserved,				reserved,	reserved,	reserved,			\
	reserved,				reserved,	reserved,	reserved,			\
	reserved,				reserved,	reserved,	reserved

/** Flags to describe a direct dictionary parameter that takes
a single value, and has the possibility of changing state. */
#define flagsChangesDirect	\
	directParamRequired,	singleItem,	notEnumerated,	changesState,	\
	reserved,				reserved,	reserved,		reserved,		\
	reserved,				reserved,	reserved,		reserved,		\
	reserved,				reserved,	reserved,		reserved

/** Flags to describe a direct dictionary parameter that takes
a list value, and has the possibility of changing state. */
#define flagsListChangesDirect	\
	directParamRequired,	listOfItems,	notEnumerated,	changesState,	\
	reserved,				reserved,		reserved,		reserved,		\
	reserved,				reserved,		reserved,		reserved,		\
	reserved,				reserved,		reserved,		reserved

//-------------------------------------------------------------------------------
//	Handy short cuts.
//-------------------------------------------------------------------------------

///@name Short Cuts	for the Terminology Resource

/** */
//@{
/** Short cut to define that a plug-in does not require a reply.
*/
#define NO_REPLY		\
	noReply,			\
	"",					\
	replyRequired,	singleItem,	notEnumerated,	notTightBindingFunction,	\
	reserved,		reserved,	reserved,		reserved,					\
	reserved,		reserved,	reserved,		reserved,					\
	verbEvent,		reserved,	reserved,		reserved

/** Short cut to define an image direct parameter used by Photoshop. This
is required for most filter, selection and color picker plug-in resources.
*/
#define IMAGE_DIRECT_PARAMETER	\
	typeImageReference,			\
	"",							\
	flagsOptionalEnumeratedChangesDirect

//@}

/** @} */	// end defgroup
//-------------------------------------------------------------------------------

// NOTE: 1/21/98 (Ace) I'm going to leave these conditional defines in this
// file to keep PITerminology devoid of conditionals:

/* Normalize the AppleScript terminology */

#if MSWindows	// These items come from AppleScript

#define CFDataRef void*

#ifndef AE_DESC_ENUMS
#define AE_DESC_ENUMS


#define  typeBoolean                   'bool'
#define  typeChar                      'TEXT'
#define  typeText                      'TEXT'


/* Preferred numeric Apple event descriptor types */
#define  typeSInt16                    'shor'
#define  typeSInt32                    'long'
#define  typeUInt32                    'magn'
#define  typeSInt64                    'comp'
#define  typeIEEE32BitFloatingPoint    'sing'
#define  typeIEEE64BitFloatingPoint    'doub'
#define  type128BitFloatingPoint       'ldbl'
#define  typeDecimalStruct             'decm'

/* Non-preferred Apple event descriptor types */
#define  typeSMInt                     typeSInt16
#define  typeShortInteger              typeSInt16
#ifndef typeInteger
#define  typeInteger                   typeSInt32
#else
#if (typeInteger != 'long')
	this_is_integer_trouble
#endif
#endif
#define  typeLongInteger               typeSInt32
#define  typeMagnitude                 typeUInt32
#define  typeComp                      typeSInt64
#define  typeSMFloat                   typeIEEE32BitFloatingPoint
#define  typeShortFloat                typeIEEE32BitFloatingPoint
#ifndef typeFloat
#define  typeFloat                     typeIEEE64BitFloatingPoint
#else
#if (typeFloat != 'doub')
	this_is_float_trouble
#endif
#endif
#define  typeLongFloat                 typeIEEE64BitFloatingPoint
#define  typeExtended                  'exte'

/* More Apple event descriptor types */
#define  typeAEList                    'list'
#define  typeAERecord                  'reco'
#define  typeAppleEvent                'aevt'
#define  typeEventRecord               'evrc'
#define  typeTrue                      'true'
#define  typeFalse                     'fals'
#define  typeAlias                     'alis'	/// \deprecated Please use typeBookmark instead
#define  typeEnumerated                'enum'
#define  typeType                      'type'
#define  typeAppParameters             'appa'
#define  typeProperty                  'prop'
#define  typeFSS                       'fss '
#define  typeFSRef                     'fsrf'	/// \deprecated Please use typeXPlatFileSpec
#define  typeKeyword                   'keyw'
#define  typeSectionH                  'sect'
#define  typeWildCard                  '****'
#define  typeApplSignature             'sign'
#define  typeQDRectangle               'qdrt'
#define  typeFixed                     'fixd'
#define  typeProcessSerialNumber       'psn '
#define  typeApplicationURL            'aprl'
#define  typeNull                      'null'

#endif // AE_DESC_ENUMS
/** @} */

#define	roman					0		 /**< Language specifier for the \c aete resource. */
#define english					0		 /**< Language specifier for the \c aete resource. */
#define japanese				11		 /**< Language specifier for the \c aete resource. */

#ifndef noReply
#define noReply					'null'
#endif

#ifndef __APPLEEVENTS__

#define typeObjectSpecifier		'obj '	 /**< A reference or object specifier type. See @ref PicaActionReferenceSuite */
/** @} */

#endif /* __APPLEEVENTS __ */

#if !INSIDE_PHOTOSHOP

// The plug-ins need this stuff, but don't use the Universal Headers, so
// we must provide it for them.

#define formName				'name'

#ifndef __AEOBJECTS__
#define formAbsolutePosition	'indx'
#define formPropertyID			'prop'
#define formRelativePosition	'rele'
#endif /* __AEOBJECTS__ */

#endif	// !INSIDE_PHOTOSHOP

#endif /* MSWindows */

#if INSIDE_PHOTOSHOP || !defined(keySelection)
#define keySelection			'fsel'	/**< Property key for Selection. */
#endif

#define typePath				'Pth '	/**< Path type for a descriptor key. */

#if MSWindows
#define typePlatformFilePath	typePath
#else
#define typePlatformFilePath	typeAlias
#endif


//-------------------------------------------------------------------------------

#ifndef Rez

//-------------------------------------------------------------------------------

/**
* @defgroup PiPLScriptingKeys Scripting-specific PiPL Properties
* These PiPL properties are only applicable for any plug-in modules that use scripting.
*/
///@name PiPL Scripting Keys
//@{
/**
* @ingroup PiPLScriptingKeys
* @{
*/


/**
* Indicates whether an 'aete' resource is present, and whether a plug-in is
* scripting-aware for Photoshop and AppleScript; key value is 'hstm'.
* This property key reflects the \c HasTerminology property in the PiPL resource
* file; any plug-in that contains a terminology resource must have the
* HasTerminology property in its PiPL resource file. The data type for the
* property is PITerminology. For any plug-in that contains a terminology
* resource, the PiPL resource file must have the HasTerminology property.
*/
#define PIHasTerminologyProperty	0x6873746DL	/* 'hstm' <PITerminology> Has <aete, 0> resource:
														version number
														classID:		Object or event class
														eventID:		For events (typeNull otherwise)
														terminologyID:	'aete' resource ID (ignored if PITerminologyProperty)
														scopeString:	Unique string present if
																		AppleScript not supported
												*/
/**
* Used internally as terminology cache; key value is 'trmn'. If present, it is used instead of an
* aete resource.
* The data type for the property is PITerminology.
*/
#define PITerminologyProperty		0x74726D6EL	/* 'trmn' <aete> Used internally as terminology cache.
													If present it is used instead of an aete resource.
												*/
/**
* @}
*/
//@}

///@defgroup RecordPlayInfoFlags Flags for recordInfo and playInfo

///@ingroup RecordPlayInfoFlags
///@{

/// Dialog options for Record.  See associated enum for @ref dialogRecordEnum "dialog record."
typedef int32 PIDialogRecordOptions;

/// These are the flags are associated  with @ref PIDialogRecordOptions,
/// and are used for \c PIDescriptorParameters::recordInfo, and \c PIActionParameters::recordInfo.
///@anchor dialogRecordEnum
enum
	{
	plugInDialogOptional,		/**< Display dialog only if necessary or requested by user. */
	plugInDialogRequired,		/**< Always display dialog. */
	plugInDialogNone			/**< No dialog to display. */
	};

/// Dialog options for playback. See associated enum for @ref dialogPlayEnum "dialog play."
typedef int32 PIDialogPlayOptions;

/// These flags are associated  with @ref PIDialogPlayOptions,
/// and are used for \c PIDescriptorParameters::playInfo, and \c PIActionParameters::playInfo.
///@anchor dialogPlayEnum
enum
	{
	plugInDialogDontDisplay,	/**< Display dialog only if necessary due to missing parameters or error. */
	plugInDialogDisplay,		/**< Present the plug-in dialog using descriptor information. */
	plugInDialogSilent			/**< Never present a dialog; use only descriptor information; if the information
									 is insufficient to run the plug-in, the plug-in should return an
									 error in the \c errorString field of the plug-ins parameter block. */
	};
///@}
//-------------------------------------------------------------------------------
//	Flags returned by GetKey. Low order word corresponds to AppleEvent flags.
//-------------------------------------------------------------------------------

/**
* @defgroup GetKeyFlags Flags returned by GetKeyProc
* These flags are returned in the flags parameter of \c GetKeyProc.
*/
///@name Flags returned by GetKeyProc
//@{
/**
* @ingroup GetKeyFlags
* @{
*/
#define actionSimpleParameter		0x00000000L
#define actionEnumeratedParameter	0x00002000L
#define actionListParameter			0x00004000L
#define actionOptionalParameter		0x00008000L

#define actionObjectParameter		0x80000000L
#define actionScopedParameter		0x40000000L
#define actionStringIDParameter		0x20000000L
/**
* @}
*/
//@}

//-------------------------------------------------------------------------------

typedef Handle PIDescriptorHandle;	  /**< Descriptor Handle used in the @ref DescriptorSuite. */

typedef struct PIOpaqueWriteDescriptor*	PIWriteDescriptor;	/**< Write descriptor used by @ref WriteDescriptorProcs. */
typedef struct PIOpaqueReadDescriptor*	PIReadDescriptor;	/**< Read descriptor used by @ref ReadDescriptorProcs. */

typedef uint32	DescriptorEventID;	 /**< Event ID. See @ref PicaActionControlSuite */
typedef uint32	DescriptorClassID;	 /**< Class type ID, used in the PICA Automation Suites. */

typedef uint32	DescriptorKeyID;	/**< Key ID, used in the Automation Suites. */
typedef uint32	DescriptorTypeID;	/**< ID for the type of a class or object. Used in the Automation Suites. */
typedef uint32	DescriptorUnitID;	/**< ID for the type of unit associated when getting and putting unit numbers. */
typedef uint32	DescriptorEnumID;	/**< Enumeration ID from a given enumeration type. Used when getting or putting an enumerated
											 * value in the Automation Suites. */
typedef uint32	DescriptorEnumTypeID; /**< Enumeration Type ID. Used when getting or putting an enumerated
											   * value in the Automation Suites. */

typedef uint32	DescriptorFormID;	/**< Form ID, used with \c PSActionReferenceProcs::GetForm. */

typedef DescriptorKeyID	DescriptorKeyIDArray[];	/**< Array to track which keys have been returned
									             * in the Descriptor Suite.	See @ref OpenReadDescriptorProc
												 * for additional information. */


#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

#if MSWindows
#pragma pack(push,1)
#endif

/** Maps Photoshop "key" information into human readable text and provides additional
* type information for values.
* This structure is used for two PiPL scripting properties: @ref PIHasTerminologyProperty and
* @ref PITerminologyProperty.
*
* The "HasTerminology" property indicates whether an 'aete' resource is present and whether your
* plug-in is scripting-aware for Photoshop and AppleScript. All scripting-aware plug-ins
* must have an 'aete' dictionary resource. \c terminologyID should be the resource number
* for that dictionary. Multiple dictionaries are usually provided when a file contains
* more than one plug-in.
*
* Scripting-aware Filters, Selection, and Color Picker modules must provide both a
* classID and an eventID. All other types of plug-ins must provide a classID and pass \c typeNull="null"
* for the eventID.
* @note If a non-filter module does not pass \c typeNull="null" for eventID, then errors will occur,
* as the existence of an eventID triggers the host to parse the dictionary as if it
* was for a Filter, Selection, or Color Picker module.
*/
typedef struct PITerminology
	{
	int32	version;		   /**< Version number. */
	OSType	classID;		   /**< Object or event class. */
	OSType	eventID;		   /**< Event ID, should be \c typeNull="null"  if not an event. */
	int16	terminologyID;	   /**< 'aete' resource ID. Ignored if the property
							         is \c PITerminologyProperty */
	char	scopeString[1];	   /**< A unique C string that indicates AppleScript is not supported.
									This string can be a UUID, or you own trademark or
									copyright.
									@note Supplying this string automatically makes
									the scripting scope for a plug-in apply only to the host.
									Any external AppleScript or similar calls to the plug-in are ignored.
									See @ref PGScriptingIgnoringAppleScript for more information.*/
	} PITerminology;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

#if MSWindows
#pragma pack(pop)
#endif

#define PITerminologyMinSize 15

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/**
*  Refers to an external object, such as a channel or a layer.
*  See also @ref PGScriptingObjectRef.
*/
typedef struct PIDescriptorSimpleReference
	{
	DescriptorTypeID	desiredClass;  /**< The type or class for the key. */
	DescriptorKeyID		keyForm;	   /**< The key type. */

	struct _keyData
		{
		Str255				name;	  /**< */
		int32				index;	  /**< The index of the key, if \c keyForm=formIndex. */
		DescriptorTypeID	type;	  /**< */
		DescriptorEnumID	value;	  /**< */
		}				keyData;
	} PIDescriptorSimpleReference;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

//-------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
	{
#endif

/** @defgroup DescriptorSuite Descriptor Suite Callbacks (\deprecated Standard Suite)
* The standard Descriptor Suite has been deprecated, please use the @ref PicaActionDescriptorSuite
* Suite defined with the Adobe Plug-in Component Architecture (PICA).
*
* The Descriptor suite provides all the callbacks related to scripting. It is divided into
* two sub-suites, \c WriteDescriptorProcs and \c ReadDescriptorProcs, located
* in \c PIDescriptorParameters.
*
* The standard Descriptor Suite is found as a pointer in the parameter blocks of
* the plug-in modules. Since the Descriptor Suite is composed of two sub-suites,
* you must reference the routines through one of these.
* You can access the routines within the Descriptor Suite in
* the following manner:
*
*@code
	DLLExport MACPASCAL void PluginMain (const int16 selector,
							             void *exportParamBlock,
							             int32 *data,
							             int16 *result)
	{
		...

		// Get the Descriptor Suite from the parameter block
		PIDescriptorParameters *descParams =
					((ExportRecordPtr)exportParamBlock)->descriptorParameters;

		// Verify we found the suite.
		if (descParams == NULL) return err;

		// Get the Write Descriptor Suite
		WriteDescriptorProcs* writeProcs = descParams->writeDescriptorProcs;

		// Verify we found that too.
		if (writeProcs == NULL) return err;

		// Call the routine to open a write descriptor.
		token = writeProcs->openWriteDescriptorProc();
	}
@endcode
*
*/
/**	@ingroup DescriptorSuite
*/
/** @{
*/
//-------------------------------------------------------------------------------
///@name	WriteDescriptor callbacks
//@{

/**
* Opens a \c PIWriteDescriptor handle for access to its descriptor array.
* @returns NULL if unable to allocate the memory for the handle.
* If an error occurs at any time after \c OpenWriteDescriptorProc,
* the \c PIDescriptor \c writeToken and the new \c PIDescriptor handle should be be disposed of
* using @ref DisposePIHandleProc from the Handle Suite.
*/
typedef MACPASCAL PIWriteDescriptor (*OpenWriteDescriptorProc)(void);

/**
* Creates a new \c PIDescriptorHandle containing the key/value pairs that have
* been written to the write descriptor, and closes the \c PIWriteDescriptor handle.
* Return the new \c PIDescriptorHandle to the host in \c PIDescriptorParameters::descriptor.
* @param PIWriteDescriptor The write descriptor to close.
* @param PIDescriptorHandle [OUT] Newly created \c PIDescriptorHandle.
* @returns NULL if unable to allocate the memory for the new handle.
*/
typedef MACPASCAL OSErr (*CloseWriteDescriptorProc)(PIWriteDescriptor, PIDescriptorHandle*);

/**
* Stores an ID and corresponding integer (\c typeInteger) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param int32 The integer to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutIntegerProc)(PIWriteDescriptor, DescriptorKeyID, int32);

/**
* Stores an ID and corresponding floating point number (\c typeFloat) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param real64 The floating point number to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutFloatProc)(PIWriteDescriptor, DescriptorKeyID, const real64*);

/**
* Stores an ID and corresponding unit-based floating point number (\c typeUnitFloat) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param DescriptorUnitID The units to write.
* @param real64 The floating point number to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutUnitFloatProc)(PIWriteDescriptor, DescriptorKeyID, DescriptorUnitID, const real64*);

/**
* Stores an ID and corresponding boolean (\c typeBoolean) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param Boolean The boolean to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutBooleanProc)(PIWriteDescriptor, DescriptorKeyID, Boolean);

/**
* Stores an ID and corresponding text (\c typeChar) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param Handle A pointer to the text to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutTextProc)(PIWriteDescriptor, DescriptorKeyID, Handle);

/**
* Stores an ID and corresponding alias (\c typeAlias) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param Handle A pointer to the alias to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutAliasProc)(PIWriteDescriptor, DescriptorKeyID, Handle);

/**
* Stores an ID and corresponding value from an enumeration (\c typeEnumerated)
* into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param key The key to write.
* @param type The enumeration type.
* @param value The value from the enumeration to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutEnumeratedProc)(PIWriteDescriptor, DescriptorKeyID key, DescriptorTypeID type, DescriptorEnumID value);

/**
* Stores an ID and corresponding class description type (\c typeClass) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param DescriptorTypeID The class type.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutClassProc)(PIWriteDescriptor, DescriptorKeyID, DescriptorTypeID);

/**
* Stores an ID and corresponding basic class, type, name and index (\c typeObjectReference)
* into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param PIDescriptorSimpleReference The basic reference to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutSimpleReferenceProc)(PIWriteDescriptor, DescriptorKeyID, const PIDescriptorSimpleReference*);

/**
* Stores an ID and corresponding object (\c typeObject) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param DescriptorTypeID The type of object to write.
* @param PIDescriptorHandle The object to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutObjectProc)(PIWriteDescriptor, DescriptorKeyID, DescriptorTypeID, PIDescriptorHandle);

/**
* Stores an ID and corresponding integer into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param uint32 The integer to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr	(*PutCountProc)(PIWriteDescriptor, DescriptorKeyID, uint32 count);

/**
* Stores an ID and corresponding string (\c typeChar) into a descriptor structure.
* @param PIWriteDescriptor The descriptor to write into
* @param DescriptorKeyID The key to write.
* @param ConstStr255Param The string to write.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*PutStringProc)(PIWriteDescriptor, DescriptorKeyID, ConstStr255Param);

// Scoped classes are not for use by plug-ins in Photoshop 4.0:
typedef MACPASCAL OSErr (*PutScopedClassProc)(PIWriteDescriptor, DescriptorKeyID, DescriptorTypeID);
typedef MACPASCAL OSErr (*PutScopedObjectProc)(PIWriteDescriptor, DescriptorKeyID, DescriptorTypeID, PIDescriptorHandle);

//-------------------------------------------------------------------------------
///@name ReadDescriptor callbacks
//@{
/**
* Creates a new read descriptor.
* @param PIDescriptorHandle Pointer to a list of key/value pairs, usually passed through
* \c PIDescriptorParameters::descriptor.
* @param DescriptorKeyIDArray  NULL-terminated array you can provide to automatically track
* which keys have been returned. This array is updated in @ref GetKeyProc. As each key is returned,
* it is changed to the null string ("\0") in the array.
* @note This \c DescriptorKeyIDArray must be NULL-terminated, or the automatic array processor will read and write
* beyond the end of the array, which will likely crash the host.
* @returns The newly created read descriptor; or NULL, if unable to allocate the memory for the new handle.
*/
typedef MACPASCAL PIReadDescriptor (*OpenReadDescriptorProc)(PIDescriptorHandle, DescriptorKeyIDArray);

/**
* Closes the PIReadDescriptor handle.
* @param PIReadDescriptor The read descriptor to close.
* @returns The most major error that occurred during reading, if any.
* @note Errors that occur in \c Get routines and \c GetKeyProc are sticky, meaning an
* error keeps getting returned until another more drastic error supercedes it.
* This way a plug-in can check for any major errors after it has read all the data.\n\n
*/
typedef MACPASCAL OSErr (*CloseReadDescriptorProc)(PIReadDescriptor);

/**
* Returns the next key in the read descriptor; returns key ID, description type, and
* flags. During this call, the \c DescriptorKeyIDArray, which was passed into \c OpenReadDescriptorProc,
* is updated.  As each key is returned \c GetKeyProc changes it value to the null string ("\0") in the
* \c DescriptorKeyIDArray.
* If the plug-in gets to @ref CloseReadDescriptorProc and this array is not empty,
* it indicates any key the plug-in expected but was not given. You can subsequently coerce missing
* information or request it in a dialog from the user (as long as playInfo | plugInDialogSilent).
* @param PIReadDescriptor The descriptor to read from.
* @param key [OUT] Returned key.
* @param type [OUT]	Type of the key, based on the routine used to put the key into the descriptor.
* See the various \c Get and \c Put routines for their types.
* @param flags [OUT]  See @ref GetKeyFlags.
* @returns TRUE if there are keys remaining; FALSE if there are no more keys.
*/
typedef MACPASCAL Boolean (*GetKeyProc)(PIReadDescriptor, DescriptorKeyID* key, DescriptorTypeID* type, int32* flags);

/**
* Returns the next value in the read descriptor as a integer (\c typeInteger).
* @param PIReadDescriptor The descriptor to read from.
* @param int32 [OUT] Returned integer value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetIntegerProc)(PIReadDescriptor, int32*);

/**
* Returns the next value in the read descriptor as a float (\c typeFloat).
* @param PIReadDescriptor The descriptor to read from.
* @param real64 [OUT] Returned float value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetFloatProc)(PIReadDescriptor, real64*);

/**
* Returns the next value in the read descriptor as a unit-based floating point number (\c typeUnitFloat).
* @param PIReadDescriptor The descriptor to read from.
* @param DescriptorUnitID [OUT]	Returned unit type.
* @param real64 [OUT] Returned float value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetUnitFloatProc)(PIReadDescriptor, DescriptorUnitID*, real64*);

/**
* Returns the next value in the read descriptor as a boolean (\c typeBoolean).
* @param PIReadDescriptor The descriptor to read from.
* @param Boolean [OUT] Returned boolean value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetBooleanProc)(PIReadDescriptor, Boolean*);

/**
* Returns the next value in the read descriptor as a pointer to text (\c typeChar).
* @param PIReadDescriptor The descriptor to read from.
* @param Handle [OUT] Returned pointer to text.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetTextProc)(PIReadDescriptor, Handle*);

/**
* Returns the next value in the read descriptor as an alias (\c typeAlias).
* @param PIReadDescriptor The descriptor to read from.
* @param Handle [OUT] Handle to the alias returned.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetAliasProc)(PIReadDescriptor, Handle*);

/**
* Returns the next value in the read descriptor as an enumerated description type (\c typeEnumerated).
* @param PIReadDescriptor The descriptor to read from.
* @param DescriptorEnumID [OUT] Returned enumerated description type.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetEnumeratedProc)(PIReadDescriptor, DescriptorEnumID*);

/**
* Returns the next value in the read descriptor as an class description type (\c typeClass).
* @param PIReadDescriptor The descriptor to read from.
* @param DescriptorTypeID [OUT] Returned class description type.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetClassProc)(PIReadDescriptor, DescriptorTypeID*);

/**
* Returns the next value in the read descriptor as a basic reference (\c typeObjectReference).
* @param PIReadDescriptor The descriptor to read from.
* @param PIDescriptorSimpleReference [OUT] Returned basic reference.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetSimpleReferenceProc)(PIReadDescriptor, PIDescriptorSimpleReference*);

/**
* Returns the next value in the read descriptor as an object, defined by a descriptor type and
* a handle to the corresponding object (\c typeObject).
* @param PIReadDescriptor The descriptor to read from.
* @param DescriptorTypeID [OUT] The type of the object.
* @param PIDescriptorHandle [OUT] Handle to the object.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetObjectProc)(PIReadDescriptor, DescriptorTypeID*, PIDescriptorHandle*);

/**
* Returns the number of descriptors in a read descriptor structure.
* @param PIReadDescriptor The descriptor to get the count from.
* @param uint32 [OUT] The number of descriptors found.
* @returns Non-zero error if failure.
*/
typedef MACPASCAL OSErr (*GetCountProc)(PIReadDescriptor, uint32*);

/**
* Returns the next value in the read descriptor as a string (\c typeChar).
* @param PIReadDescriptor The descriptor to read from.
* @param Str255 [OUT] Returned string value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type.
*/
typedef MACPASCAL OSErr (*GetStringProc)(PIReadDescriptor, Str255*);

/**
* Returns the next value in the read descriptor as a pinned integer (\c typeInteger).
* This routine returns a int32 from a descriptor structure. If the value
* is out of the range provide by \c min and \c max, it returns \c coercedParamErr and
* stores either the minimum or maximum value in the returned integer parameter,
* whichever is closer.
* @param PIReadDescriptor The descriptor to read from.
* @param min The minimum value to pin the integer to.
* @param max The maximum value to pin the integer to.
* @param int32 [OUT] Returned integer value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type, or if the integer was
* out of range.
*/
typedef MACPASCAL OSErr (*GetPinnedIntegerProc)(PIReadDescriptor, int32 min, int32 max, int32*);

/**
* Returns the next value in the read descriptor as a pinned float (\c typeFloat).
* This routine returns a floating point number from a descriptor structure. If the value
* is out of the range provide by \c min and \c max, it returns \c coercedParamErr and
* stores either the minimum or maximum value in the returned float parameter,
* whichever is closer.
* @param PIReadDescriptor The descriptor to read from.
* @param min The minimum value to pin the integer to.
* @param max The maximum value to pin the integer to.
* @param real64 [OUT] Returned float value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type, or if the floating point number was
* out of range.
*/
typedef MACPASCAL OSErr (*GetPinnedFloatProc)(PIReadDescriptor, const real64* min, const real64* max, real64*);

/**
* Returns the next value in the read descriptor as a pinned unit float (\c typeUnitFloat).
* This routine returns a floating point number from a descriptor structure. If the value
* is out of the range provide by \c min and \c max, it returns \c coercedParamErr and
* stores either the minimum or maximum value in the returned float parameter,
* whichever is closer.
* @param PIReadDescriptor The descriptor to read from.
* @param min The minimum value to pin the integer to.
* @param max The maximum value to pin the integer to.
* @param DescriptorUnitID The unit for the floating point returned.
* @param real64 [OUT] Returned float value.
* @returns
* - \c paramErr if the call is made for the wrong type, unless the parameter can be coerced;
* - \c coercedParamErr if the parameter could be coerced to this type, or if the floating point number was
* out of range.
*/
typedef MACPASCAL OSErr (*GetPinnedUnitFloatProc)(PIReadDescriptor, const real64* min, const real64* max, DescriptorUnitID*, real64*);
//@}
//-------------------------------------------------------------------------------

#ifdef __cplusplus
	}
#endif

//-------------------------------------------------------------------------------
//	WriteDescriptorProcs structure.
//-------------------------------------------------------------------------------

// Version:
#define kCurrentWriteDescriptorProcsVersion 0

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/**
* The Write Descriptor Suite, handles all the \c Put functionality for scripting.
* Make sure to check its version number and number of routines for compatibility
* before using its callbacks.
*/
typedef struct WriteDescriptorProcs
	{
	int16 writeDescriptorProcsVersion;	  /**< Version of the Write Descriptor Suite. */
	int16 numWriteDescriptorProcs;		  /**< Number of routines in the Write Descriptor Suite. */

	OpenWriteDescriptorProc		openWriteDescriptorProc;  /**< Function pointer to open a write descriptor. */
	CloseWriteDescriptorProc	closeWriteDescriptorProc; /**< Function pointer to close a write descriptor. */

	PutIntegerProc				putIntegerProc;	   /**< Function pointer to put an integer value into a descriptor. */
	PutFloatProc				putFloatProc;	   /**< Function pointer to put a float value into a descriptor. */
	PutUnitFloatProc			putUnitFloatProc;  /**< Function pointer to put a unit float value into a descriptor. */
	PutBooleanProc				putBooleanProc;	   /**< Function pointer to put a boolean value into a descriptor. */
	PutTextProc					putTextProc;	   /**< Function pointer to put a text value into a descriptor. */
	PutAliasProc				putAliasProc;	   /**< Function pointer to put an alias value into a descriptor. */

	PutEnumeratedProc			putEnumeratedProc;	/**< Function pointer to put an enumeration into a descriptor. */
	PutClassProc				putClassProc;		/**< Function pointer to put a class description type into a descriptor. */
	PutSimpleReferenceProc		putSimpleReferenceProc;	 /**< Function pointer to put a basic reference into a descriptor. */
	PutObjectProc				putObjectProc;	    /**< Function pointer to put an object into a descriptor. */

	PutCountProc				putCountProc;	    /**< Function pointer to put a count into a descriptor. */

	PutStringProc				putStringProc;	    /**< Function pointer to put an string value into a descriptor. */

	/** Scoped classes are not for use by plug-ins in Photoshop 4.0 */
	PutScopedClassProc			putScopedClassProc;	 /**<  */
	/** Scoped classes are not for use by plug-ins in Photoshop 4.0 */
	PutScopedObjectProc			putScopedObjectProc; /**<  */

	} WriteDescriptorProcs;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

// Count:
#define kCurrentWriteDescriptorProcsCount \
	((sizeof(WriteDescriptorProcs) - offsetof(WriteDescriptorProcs, openWriteDescriptorProc)) / sizeof(void*))

//-------------------------------------------------------------------------------
//	ReadDescriptorProcs structure.
//-------------------------------------------------------------------------------

// Version:
#define kCurrentReadDescriptorProcsVersion 0

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/**
* The Read Descriptor Suite, handles all the \c Get functionality for scripting.
* Make sure to check its version number and number of routines for compatibility
* before using its callbacks.
*/
typedef struct ReadDescriptorProcs
	{
	int16 readDescriptorProcsVersion;	 /**< Version of the Read Descriptor Suite.*/
	int16 numReadDescriptorProcs;		 /**< Number of routines in the Read Descriptor Suite. */

	OpenReadDescriptorProc		openReadDescriptorProc;	   /**< Function pointer to open a read descriptor. */
	CloseReadDescriptorProc		closeReadDescriptorProc;   /**< Function pointer to close a read descriptor. */
	GetKeyProc					getKeyProc;			/**< Function pointer to get a key from a descriptor */

	GetIntegerProc				getIntegerProc;		/**< Function pointer to get an integer value from a descriptor. */
	GetFloatProc				getFloatProc;		/**< Function pointer to get a float value from a descriptor. */
	GetUnitFloatProc			getUnitFloatProc;	/**< Function pointer to get a unit float value from a descriptor. */
	GetBooleanProc				getBooleanProc;		/**< Function pointer to get a boolean value from a descriptor. */
	GetTextProc					getTextProc;		/**< Function pointer to get a text value from a descriptor. */
	GetAliasProc				getAliasProc;		/**< \deprecated Function pointer to get an alias value from a descriptor. */

	GetEnumeratedProc			getEnumeratedProc;	/**< Function pointer to get an enumeration from a descriptor. */
	GetClassProc				getClassProc;		/**< Function pointer to get a class description type from a descriptor. */
	GetSimpleReferenceProc		getSimpleReferenceProc;	 /**< Function pointer to get a basic reference from a descriptor. */
	GetObjectProc				getObjectProc;		/**< Function pointer to get an object from a descriptor. */

	GetCountProc				getCountProc;		/**< Function pointer to get a count from a descriptor. */

	GetStringProc				getStringProc;		/**< Function pointer to get an string value from a descriptor. */
	GetPinnedIntegerProc		getPinnedIntegerProc;	/**< Function pointer to get a pinned integer value from a descriptor */
	GetPinnedFloatProc			getPinnedFloatProc;		/**< Function pointer to get a pinned float value from a descriptor */
	GetPinnedUnitFloatProc		getPinnedUnitFloatProc;	/**< Function pointer to get a pinned unit float value from a descriptor */

	} ReadDescriptorProcs;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

// Count:
#define kCurrentReadDescriptorProcsCount \
	((sizeof(ReadDescriptorProcs) - offsetof(ReadDescriptorProcs, openReadDescriptorProc)) / sizeof(void*))

//-------------------------------------------------------------------------------
//	PIDescriptorParameters structure.
//-------------------------------------------------------------------------------

// Version of the Descriptor Parameters structure.
#define kCurrentDescriptorParametersVersion 0

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/**
* Descriptor suite callbacks. The suite is divided into two
* sub-suites, one for read, one for write, that define the set of available
* routines for the Descriptor Suite. */
typedef struct PIDescriptorParameters
	{
	int16					descriptorParametersVersion;  /**< Minimum version required to process structure. */
	int16					playInfo;					  /**< Flags for playback.
	                                                           See @ref RecordPlayInfoFlags "flags for record and playback." */
	int16					recordInfo;					  /**< Flags for recording.
															   See @ref RecordPlayInfoFlags "flags for record and playback." */

	PIDescriptorHandle		descriptor;					  /**< Handle to actual descriptor key/value pairs. */

	WriteDescriptorProcs*	writeDescriptorProcs;		  /**< WriteDescriptorProcs sub-suite. */
	ReadDescriptorProcs*	readDescriptorProcs;		  /**< ReadDescriptorProcs sub-suite.  Handles all the \c Get functionality for scripting. */
	} PIDescriptorParameters;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif
/** @}
*/ // end ingroup DescriptorSuite

//-------------------------------------------------------------------------------
//	Window notify suite.
//-------------------------------------------------------------------------------

/**
* @defgroup PicaWindowNotifySuite Window Notify Suite
* The window notify suite is used on Mac OS to receive event notification
* during play.
*
* <b> Accessing the Suite </b> \n\n
* The Window Notify suite is referred to as:
* @code
  #define kPSWindowNotifySuite	"482963f4-3ea1-11d1-8da3-00c04fd5f7ee"
@endcode
* with the version constant:
* @code
  #define kPSWindowNotifySuiteVersion 1
@endcode
* The suite is acquired as follows:
* @code
  PSWindowNotifyProcs *sPSWindowNofify;
  error = sSPBasic->AcquireSuite(kPSWindowNotifySuite,
  								 kPSWindowNotifySuiteVersion,
  								 &sPSWindowNofify);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/

#if !MSWindows


/// Unique identifier for the Window Notify suite.
#define kPSWindowNotifySuite	"482963f4-3ea1-11d1-8da3-00c04fd5f7ee"
/// Current version of the Window Notify Suite.
#define kPSWindowNotifySuiteVersion 1

#ifdef __cplusplus
extern "C"
	{
#endif
	/**
	* The prototype for a plug-in routine that receives event
	* notification for Mac OS. See @ref PSWindowNotifyProcs::AddNotify.
	* @param eventID Event that occurred.
	* @param data Plug-in data.
	*/

	struct EventRecord;

	typedef void (*PIWindowNotifier)(const struct EventRecord* event, void* data);

#ifdef __cplusplus
	}
#endif

/**
*  The set of routines available in the Window Notify suite.
*/
typedef struct PSWindowNotifyProcs
	{
	/**
	* Allows the plug-in to provide a notification routine for Mac OS.
	* @param window
	* @param notifier Routine to evoke when an event occurs.
	* @param data Any local data; passed through to the event notification routine.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*AddNotify)(void* window, PIWindowNotifier notifier, void* data);

	/**
	* Removes the notification routine for Mac OS.
	* @param window
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*RemoveNotify)(void* window);

} PSWindowNotifyProcs;

#endif

/** @} */

//-------------------------------------------------------------------------------

/**
* An action descriptor. Created and accessed through the @ref PicaActionDescriptorSuite.
*/
typedef struct _ADsc*	PIActionDescriptor;

/**
* An action list. Created and accessed through the @ref PicaActionListSuite.
*/
typedef struct _ALst*	PIActionList;

/**
* An action reference. Created and accessed through the @ref PicaActionReferenceSuite.
*/
typedef struct _ARef*	PIActionReference;

// other define for this is in ASZStringSuite.h;  placed here for SuspendHistory
#ifndef ASZString_defined
#define ASZString_defined
struct ASZByteRun;
typedef struct ASZByteRun *ASZString;
#endif

//-------------------------------------------------------------------------------
//	ActionControl suite.  Available only in Automation plug-ins.
//-------------------------------------------------------------------------------

/**
* @defgroup PicaActionControlSuite Action Control Suite
* Allows automation plug-ins to control playback and actions taken on events.
* Available only in Automation plug-ins.
*
* <b> Accessing the Suite </b> \n\n
* The Action Control suite is referred to as:
* @code
  #define kPSActionControlSuite			"bc1e4d70-f953-11d0-8d9f-00c04fd5f7ee"
@endcode
* with the version constant:
* @code
  #define kPSActionControlSuiteVersion	 	3
@endcode
* The suite is acquired as follows:
* @code
  PSActionControlProcs *sPSActionControl;
  error = sSPBasic->AcquireSuite(kPSActionControlSuite,
  								 kPSActionControlSuiteVersion,
  								 &sPSActionControl);
  if (error) goto . . . //handle error
@endcode
* Or, alternatively, use the global variable \c sPSActionControl, by including the
* header file \c sampleCode\\common\\includes\\PIUSuites.h.  \n\n
* For PICA errors, see SPErrorCodes.h.
* @{
*/

///Unique identifier for the Action Control Suite.
#define kPSActionControlSuite			"bc1e4d70-f953-11d0-8d9f-00c04fd5f7ee"

///Current version of the Action Control Suite, compatible with version 2.
#define kPSActionControlSuiteVersion	 	6	// Current version
#define kPSActionControlSuiteVersion5       5	// CC 2015 release, Version 16.0
#define kPSActionControlSuiteVersion4       4	// CC 2015 release, Version 16.0
#define kPSActionControlSuiteVersion3       3   // CS5 release, Version 12.0
#define kPSActionControlSuiteVersion2       2	// Original suite

#ifdef __cplusplus
extern "C"
	{
#endif

	/**
	* The prototype for a plug-in routine that receives action event
	* notification. See @ref PSActionControlProcs::AddNotify.
	* @param eventID Event that occurred.
	* @param descriptor	Copy of result descriptor.
	* @param options Options passed from event.
	* @param data Plug-in data.
	*/
	typedef void (*PIEventNotifier)(DescriptorEventID eventID, PIActionDescriptor descriptor, PIDialogRecordOptions options, void* data);

	/**
	* The prototype for a plug-in routine that receives a command completion
	* notification associated with a PostCommand call.
    * @param commandID Command ID matching the ID that was returned from PostCommand
	* @param result The result from executing the event.
	* @param eventID Event that occurred.
	* @param descriptor	Copy of result descriptor.
	* @param options Options passed from event.
	* @param data Plug-in data.
	*/
	typedef void (*PICommandNotifier)(uint32 commandID, OSErr result, DescriptorEventID eventID, PIActionDescriptor descriptor, PIDialogRecordOptions options, void* data);

	/**
	* The prototype for a plug-in routine that plays actions that are not
	* recorded to the Actions Palette. See @ref PSActionControlProcs::SuspendHistory.
	* @param data Plug-in data.
	* @returns Non-zero error if failure.
	*/
	typedef SPErr (*PISuspendProc)(void *data);

#ifdef __cplusplus
	}
#endif

/**
* The set of routines available in the Action Control Suite.
*/
typedef struct PSActionControlProcs
	{

	/**
	* Dispatches an event into the actions mechanism.
	* @param result [OUT] Descriptor containing the result of the event. If \c Play returns an error,
	* this may contain \c keyMessage, a string with the error message. Caller needs to free this descriptor if not NULL.
	* @param event	Event to play.
	* @param descriptor Descriptor describing any specific parameters for that event (if any),
	* @param options Dialog play options. See @ref dialogPlayEnum.
	* @result Non-zero error if failure.
	*/
	SPAPI OSErr (*Play)(PIActionDescriptor* result, DescriptorEventID event, PIActionDescriptor descriptor, PIDialogPlayOptions options);

	/**
	* Gets a property from the host. The actions system also serves as a database for
	* properties; use the \c Get routine as a quick way to get properties from the host.
	* @param reference The property to get. The reference provides the class from which
	* the properties are retrieved, and may also provide a specific key, enumeration, index, etc.
	* to pull. The plug-in must build this reference
	* to the object and the property by using the @ref PicaActionReferenceSuite.
	* @param result [OUT] A descriptor with the pertinent information.  The plug-in is responsible
	* for freeing this memory, when it has finished using \c result.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Get)(PIActionDescriptor* result, PIActionReference reference);

	/**
	* Returns the runtime ID for a string
	* @param stringID string value to convert
	* @param typeID [OUT] Four character runtime ID.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*StringIDToTypeID)(const char* stringID, DescriptorTypeID* typeID);

	/**
	* Returns the string for an ID
	* @param typeID ID value to convert
	* @param stringID {OUT} string value representing ID
	* @param stringLength Maximum string length.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*TypeIDToStringID)(DescriptorTypeID typeID, char* stringID, uint32 stringLength);

	/**
	* Allows the plug-in to provide a notification routine for specific events.
	* Any one event can only dispatch to one notifier routine per plug-in, but
	* one notifier routine can receive multiple events.  Use \c eventAll to dispatch
	* all events to a single notifier routine.
	* @note The plug-in is responsible for removing any notifiers it adds. See @ref RemoveNotify.
	* @param ref Plug-in reference to calling plug-in. The host passes this reference
	* to the plug-in through the message data.  See the <a href="../PICA.pdf">Adobe PICA API</a>.
	* @param event Any event. Use \c eventAll for all events.
	* @param notifier Routine to evoke when the event occurs.
	* @param data Any local data; passed through to the event notification routine.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*AddNotify)(SPPluginRef ref, DescriptorEventID event, PIEventNotifier notifier, void* data);

	/**
	* Removes a notifier for an event. Use \c eventAll to remove notifiers for all events.
	* @param ref Plug-in reference to calling plug-in. The host passes this reference
	* to the plug-in through the message data.  See the PICA Reference Manual.
	* @param event The event to remove notifier for.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*RemoveNotify)(SPPluginRef ref, DescriptorEventID event);

	/**
	* Suspends recording of events to the History Palette for a given document, then invokes
	* a plug-in callback function. Once the callback function returns, history recording is
	* re-enabled, and a final state is added to the History Palette with the label provided
	* in \c operationName.
	* @param reference Reference to a document, or something contained in one. The plug-in must build
	* the reference by using the @ref PicaActionReferenceSuite.
	* @param proc The plug-in callback function, which plays actions that are not recorded.
	* @param procData Data passed through to \c proc.
	* @param operationName Final state added to the History Palette once \c proc completes, and
	* history recording is resumed.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*SuspendHistory)(PIActionReference reference, PISuspendProc proc, void* procData, ASZString operationName);

	/**
	* Creates a new string with the same runtime ID as an existing
	* string. This is useful when the original string contains characters that
	* aren't legal in C identifiers and thus can't be used in the various string-
	* based descriptor calls.
	* @param newStringID The new string to create.
	* @param existingStringID The string whose runtime ID the new string will share.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*MakeStringAlias)(const char*	newStringID, const char* existingStringID);

	/**
	* Allows the plug-in to provide a notification routine for specific events at playLevel 1.
	* Notifications requested with AddNotify are delivered only when they occur at the same
	* playLevel at which the notification was requested.
	* Notifications requested with AddNotifyLevel1 are delivered only when they occur at
	* playLevel 1, no matter which playLevel they were requested at.
	* Any one event can only dispatch to one notifier routine per plug-in, but
	* one notifier routine can receive multiple events.  Use \c eventAll to dispatch
	* all events to a single notifier routine.
	* @note The plug-in is responsible for removing any notifiers it adds. See @ref RemoveNotify.
	* @param ref Plug-in reference to calling plug-in. The host passes this reference
	* to the plug-in through the message data.  See the <a href="../PICA.pdf">Adobe PICA API</a>.
	* @param event Any event. Use \c eventAll for all events.
	* @param notifier Routine to evoke when the event occurs.
	* @param data Any local data; passed through to the event notification routine.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*AddNotifyLevel1)(SPPluginRef ref, DescriptorEventID event, PIEventNotifier notifier, void* data);

    /**
    * Post a command for processing at a later time.
    * The command notifier is invoked when the command completes. The notifier is invoked
    * at the playlevel that the command was executed at.
    * @param ref        The plug-in that is posting the event. May not be NULL.
    * @param event      Event to post. If the event is classNull, then the class of the provided
    *                   descriptor is used as the event identifier.
    * @param descriptor Descriptor describing any specific parameters for the event (if any),
    * @param options    Dialog play options. See @ref dialogPlayEnum.
    * @param notifier   Optional notifier to invoke with result.
    *                   May be NULL if no notification is desired.
    *                   Only persistent plug-ins may specify a notifier.
    * @param data       data to pass to notifier. Ignored if the notifier is NULL.
    * @param commandID  [OUT] an identifier for the command.
    * @result           Non-zero error if failure.
    */
    SPAPI OSErr (*PostCommand)(SPPluginRef ref, DescriptorEventID event, PIActionDescriptor descriptor, PIDialogPlayOptions options, PICommandNotifier notifier, void* data, uint32* commandID);

    /**
    * Cancel a command that was scheduled for execution via PostCommand.
    * If the command is still pending, then it will be dropped without being executed.
    * You cannot cancel commands that are executing. If the command is in the process of
    * being executed, then it will be completed normally.
    * A command notifier is *not* invoked on a cancelled command regardless of its
    * state when cancel is called.
    * @param ref        The plug-in that posted the event. May not be NULL.
    * @param commandID  The command that should be cancelled. If this argument is 0, then all
    *                   pending commands for the provided plug-in are cancelled.
    * @result           Non-zero error if failure.
    */
    SPAPI OSErr (*CancelCommand)(SPPluginRef ref, uint32 commandID);

    /**
    * Utility routine to convert an AliasHandle to a Bookmark for Macintosh only.
    * @param aliasHandle    The aliasHandle to use in the conversion.
    * @param bookmark       The pointer to a bookmark for the converted AliasHandle
    * @result               Non-zero error if failure.
    */
    SPAPI OSErr (*ConvertAliasHandleToBookmark)(Handle aliasHandle, CFDataRef* bookmark);

    /**
     * Utility routine to convert a Bookmark to an AliasHandle for Macintosh only.
     * @param bookmark       The bookmark to use in the conversion.
     * @param aliasHandle    The pointer to the AliasHandle for the converted bookmark.
     * @result               Non-zero error if failure.
     */
    SPAPI OSErr (*ConvertBookmarkToAliasHandle)(CFDataRef bookmark, Handle* aliasHandle);

	/**
	* Allows the plug-in to provide a notification routine for specific events at any playLevel.
	* Any one event can only dispatch to one universal notifier routine per plug-in, but
	* one notifier routine can receive multiple events.  Use \c eventAll to dispatch
	* all events to a single notifier routine.
    * Universal notifiers are distinct from other notifiers and they must be removed
    * by calling RemoveUniversalNotifier.
	* @note The plug-in is responsible for removing any notifiers it adds.
    * See @ref RemoveUniversalNotifier.
	* @param ref Plug-in reference to calling plug-in. The host passes this reference
	* to the plug-in through the message data.  See the <a href="../PICA.pdf">Adobe PICA API</a>.
	* @param event Any event. Use \c eventAll for all events.
	* @param notifier Routine to evoke when the event occurs.
	* @param data Any local data; passed through to the event notification routine.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*AddUniversalNotifier)(SPPluginRef ref, DescriptorEventID event, PIEventNotifier notifier, void* data, uint32 options);

	/**
	* Removes a universal notifier for an event. Use \c eventAll to remove notifiers for all events.
	* @param ref Plug-in reference to calling plug-in. The host passes this reference
	* to the plug-in through the message data.  See the PICA Reference Manual.
	* @param event The event to remove notifier for.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*RemoveUniversalNotifier)(SPPluginRef ref, DescriptorEventID event);

    } PSActionControlProcs;
/* @} */

/**
 * The set of routines available in the Action Control Suite version 4. See above for documentation.
 */
typedef struct PSActionControlProcs4
{
    SPAPI OSErr (*Play)(PIActionDescriptor* result, DescriptorEventID event, PIActionDescriptor descriptor, PIDialogPlayOptions options);
    SPAPI OSErr (*Get)(PIActionDescriptor* result, PIActionReference reference);
    SPAPI OSErr (*StringIDToTypeID)(const char* stringID, DescriptorTypeID* typeID);
    SPAPI OSErr (*TypeIDToStringID)(DescriptorTypeID typeID, char* stringID, uint32 stringLength);
    SPAPI OSErr (*AddNotify)(SPPluginRef ref, DescriptorEventID event, PIEventNotifier notifier, void* data);
    SPAPI OSErr (*RemoveNotify)(SPPluginRef ref, DescriptorEventID event);
    SPAPI OSErr (*SuspendHistory)(PIActionReference reference, PISuspendProc proc, void* procData, ASZString operationName);
    SPAPI OSErr (*MakeStringAlias)(const char*	newStringID, const char* existingStringID);
    SPAPI OSErr (*AddNotifyLevel1)(SPPluginRef ref, DescriptorEventID event, PIEventNotifier notifier, void* data);
} PSActionControlProcs4;
/* @} */

/**
 * The set of routines available in the Action Control Suite version 3 and 2. See above for documentation.
 */
typedef struct PSActionControlProcsOld
{
    SPAPI OSErr (*Play)(PIActionDescriptor* result, DescriptorEventID event, PIActionDescriptor descriptor, PIDialogPlayOptions options);
    SPAPI OSErr (*Get)(PIActionDescriptor* result, PIActionReference reference);
    SPAPI OSErr (*StringIDToTypeID)(const char* stringID, DescriptorTypeID* typeID);
    SPAPI OSErr (*TypeIDToStringID)(DescriptorTypeID typeID, char* stringID, uint32 stringLength);
    SPAPI OSErr (*AddNotify)(SPPluginRef ref, DescriptorEventID event, PIEventNotifier notifier, void* data);
    SPAPI OSErr (*RemoveNotify)(SPPluginRef ref, DescriptorEventID event);
    SPAPI OSErr (*SuspendHistory)(PIActionReference reference, PISuspendProc proc, void* procData, ASZString operationName);
    SPAPI OSErr (*MakeStringAlias)(const char*	newStringID, const char* existingStringID);
} PSActionControlProcsOld;
/* @} */

//-------------------------------------------------------------------------------
//	Basic Action control suite.  Available to non-Automation plug-ins.
//-------------------------------------------------------------------------------

/**
* @defgroup PicaBasicControlSuite Basic Action Control Suite
* Allows non-automation plug-ins access to some of the routines available in the
* Action Control Suite.
*
* <b> Accessing the Suite </b> \n\n
* The Basic Action Control suite is referred to as:
* @code
  #define kPSBasicActionControlSuite			"3eb7c480-8797-11d1-8da7-00c04fd5f7ee"
@endcode
* with the version constant:
* @code
  #define kPSBasicActionControlSuiteVersion		2
@endcode
* The suite is acquired as follows:
* @code
  PSBasicActionControlProcs *sPSBasicActionControl;
  error = sSPBasic->AcquireSuite(kPSBasicActionControlSuite,
  								 kPSBasicActionControlSuiteVersion,
  								 &sPSBasicActionControl);
  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/


/// Unique identifier for the Basic Action Control Suite.
#define kPSBasicActionControlSuite			"3eb7c480-8797-11d1-8da7-00c04fd5f7ee"
/// Current version of the Basic Action Control Suite; released with CC 2015.5, Version 17.0
#define kPSBasicActionControlSuiteVersion		3
/// CC 2015 release, Version 16.0
#define kPSBasicActionControlSuiteVersion2		2
/// Previous version of the Basic Action Control Suite.
#define kPSBasicActionControlSuitePrevVersion	1

/**
* The set of routines available in the Basic Action Control Suite.
*/
typedef struct PSBasicActionControlProcs
	{

	/**
	* Gets a property from the host. The actions system also serves as a database for
	* properties; use the \c Get routine as a quick way to get properties from the host.
	* @param result [OUT] A descriptor with the pertinent information.  The plug-in is responsible
	* for freeing this descriptor, when it has finished using \c result.
	* @param reference The property to get. The plug-in must build this reference
	* to the object and the property by using the @ref PicaActionReferenceSuite.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Get)(PIActionDescriptor* result, PIActionReference reference);

	/**
	* Returns the runtime ID for a string
	* @param stringID string value to convert
	* @param typeID [OUT] Four character runtime ID.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*StringIDToTypeID)(const char* stringID,	DescriptorTypeID* typeID);

	/**
	* Returns the string for an ID
	* @param typeID ID value to convert
	* @param stringID {OUT} string value representing ID
	* @param stringLength Maximum string length.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*TypeIDToStringID)(DescriptorTypeID typeID, char* stringID, uint32 stringLength);

	/**
	* Creates a new string with the same runtime ID as an existing
	* string. This is useful when the original string contains characters that
	* aren't legal in C identifiers and thus can't be used in the various string-
	* based descriptor calls.
	* @param newStringID The new string to create.
	* @param existingStringID The string whose runtime ID the new string will share.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*MakeStringAlias)(const char* newStringID,	const char*	existingStringID);

    /**
     * Utility routine to convert an AliasHandle to a Bookmark for Macintosh only.
     * @param aliasHandle    The aliasHandle to use in the conversion.
     * @param bookmark       The pointer to a bookmark for the converted AliasHandle
     * @result               Non-zero error if failure.
     */
    SPAPI OSErr (*ConvertAliasHandleToBookmark)(Handle aliasHandle, CFDataRef* bookmark);

    /**
     * Utility routine to convert a Bookmark to an AliasHandle for Macintosh only.
     * @param bookmark       The bookmark to use in the conversion.
     * @param aliasHandle    The pointer to the AliasHandle for the converted bookmark.
     * @result               Non-zero error if failure.
     */
    SPAPI OSErr (*ConvertBookmarkToAliasHandle)(CFDataRef bookmark, Handle* aliasHandle);

    } PSBasicActionControlProcs;

/**
 * The set of routines available in the Basic Action Control Suite. Versions 2 and 1
 */
typedef struct PSBasicActionControlProcsOld
{
    SPAPI OSErr (*Get)(PIActionDescriptor* result, PIActionReference reference);
    SPAPI OSErr (*StringIDToTypeID)(const char* stringID,	DescriptorTypeID* typeID);
    SPAPI OSErr (*TypeIDToStringID)(DescriptorTypeID typeID, char* stringID, uint32 stringLength);
    SPAPI OSErr (*MakeStringAlias)(const char* newStringID,	const char*	existingStringID);
} PSBasicActionControlProcsOld;

/**
* @}
*/
//-------------------------------------------------------------------------------
//	DescriptorRegistry suite.  Use to pass descriptors between plug-ins or
//	save parameters between invocations.
//-------------------------------------------------------------------------------

/**
* @defgroup PicaDescriptorRegistrySuite Descriptor Registry Suite
* Used to pass descriptors between plug-ins or save parameters between invocations.
* Descriptors must be created through the @ref PicaActionDescriptorSuite.
*
* <b> Accessing the Suite </b> \n\n
* The Descriptor Registry suite is referred to as:
* @code
  #define kPSDescriptorRegistrySuite	"61e608b0-40fd-11d1-8da3-00c04fd5f7ee"
@endcode
* with the version constant:
* @code
  #define	kPSDescriptorRegistrySuiteVersion	1
@endcode
* The suite is acquired as follows:
* @code
  PSDescriptorRegistryProcs *sPSDescriptorRegistry;
  error = sSPBasic->AcquireSuite(kPSDescriptorRegistrySuite,
  								 kPSDescriptorRegistrySuiteVersion,
  								 &sPSDescriptorRegistry);
  if (error) goto . . . //handle error
@endcode
* Or, alternatively, use the global variable \c sPSRegistry, by including the
* header file \c sampleCode\\common\\includes\\PIUSuites.h.  \n\n
* For PICA errors, see SPErrorCodes.h.
* @{
*/

/// Unique identifier for the Descriptor Registry Suite.
#define kPSDescriptorRegistrySuite			"61e608b0-40fd-11d1-8da3-00c04fd5f7ee"
/// Current version of the Descriptor Registry Suite
#define	kPSDescriptorRegistrySuiteVersion	1

/**
* The set of routines available in the Descriptor Registry Suite.
*/
typedef struct PSDescriptorRegistryProcs
	{

	/**
	* Adds a descriptor to the registry.
	* @param key Unique string or ID.
	* @param descriptor	Descriptor with pertinent keys. See @ref PicaActionDescriptorSuite.
	* @param isPersistent Indicates whether the descriptor is able to be saved and
	* restored across invocations of the application. Useful for things like preferences.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Register)(const char* key, PIActionDescriptor descriptor, Boolean isPersistent);

	/**
	* Removes a descriptor from the registry.
	* @param key Key to remove.
	* @returns Non-zero error if failure. [???list of error types? invalid key?  Key not present?]
	*/
	SPAPI OSErr (*Erase)(const char* key);

	/**
	* Returns a descriptor from the registry.
	* @param key The unique string ID for the descriptor to return.
	* @param descriptor The descriptor returned.  This is a copy, the plug-in must free the
	* memory when it is done. See @ref PicaActionDescriptorSuite.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Get)(const char* key, PIActionDescriptor* descriptor);

	} PSDescriptorRegistryProcs;

/* @} */

//-------------------------------------------------------------------------------
//	ActionDescriptor suite.  Use for putting keys and objects into descriptors,
//	getting them out of descriptors, and other descriptor management.
//-------------------------------------------------------------------------------
/**
* @defgroup PicaActionDescriptorSuite Action Descriptor Suite
* Allows a plug-in to put keys and objects into descriptors,
* get them out of descriptors, and perform other descriptor management.
*
* <b> Accessing the Suite </b> \n\n
* The Action Descriptor suite is referred to as:
* @code
  #define kPSActionDescriptorSuite	"df135115-c769-11d0-8079-00c04fd7ec47"
@endcode
* with the version constant:
* @code
  #define	kPSActionDescriptorSuiteVersion		5
@endcode
* The suite is acquired as follows:
* @code
  PSActionDescriptorProcs *sPSActionDescriptor;
  error = sSPBasic->AcquireSuite(kPSActionDescriptorSuite,
  								 kPSActionDescriptorSuiteVersion,
  								 &sPSActionDescriptor);
  if (error) goto . . . //handle error
@endcode
* Or, alternatively, use the global variable \c sPSActionDescriptor, by including the
* header file \c sampleCode\\common\\includes\\PIUSuites.h.  \n\n
* For PICA errors, see SPErrorCodes.h.
* @{
*/

/// Unique identifier for the Action Descriptor Suite.
#define kPSActionDescriptorSuite			"df135115-c769-11d0-8079-00c04fd7ec47"
/// Current version of the Action Descriptor Suite. First release, CC 2015.5 version 17.0
#define	kPSActionDescriptorSuiteVersion		5
/// intermediate version do not use
// #define kPSActionDescriptorSuiteVersion4	4
/// CS3 version 10.0
#define kPSActionDescriptorSuiteVersion3	3
/// Original version
#define kPSActionDescriptorSuiteVersion2	2

/**
* The set of routines available in the Action Descriptor Suite.
*/
typedef struct PSActionDescriptorProcs
	{
	/**
	* Make a new descriptor.
	* @param descriptor [OUT] The new descriptor.
	* @returns Non-zero error if unable
	*/
	SPAPI OSErr (*Make)(PIActionDescriptor* descriptor);

	/**
	* Frees a descriptor
	* @param descriptor The descriptor to free.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Free)(PIActionDescriptor descriptor);

	/**
	* Gets the type for a key. 	See @ref GetKey for an example.
	* @param descriptor	 Descriptor to read from.
	* @param key  Key to get the type of.
	* @param type [OUT] Type for the key.
	* put routines for possible values.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetType)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorTypeID* type);

	/**
	* Gets a key from a descriptor based on an index. The index is zero-based.
	* This routine is often used with @ref GetCount, to iterate through the descriptor,
	* retrieving keys and values from it.
	* @param descriptor The descriptor from which to read.
	* @param index The index of the descriptor to get.
	* @param key [OUT] The key returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetKey)(PIActionDescriptor descriptor, uint32 index, DescriptorKeyID* key);

	/**
	* Checks if a descriptor has a given key. Often used to verify a key exists before attempting
	* to retrieve it.
	* @param descriptor The descriptor to check.
	* @param key The key to find in the descriptor.
	* @param hasKey [OUT] TRUE if the key exists in the descriptor; FALSE otherwise.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*HasKey)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean* hasKey);

	/**
	* Returns the number of keys in the descriptor. See @ref GetKey for an example.
	* @param descriptor The descriptor from which to get the count.
	* @param count [OUT] The number of keys in the descriptor.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetCount)(PIActionDescriptor descriptor, uint32* count);

	/**
	* Checks if two descriptors are equal.
	* @param descriptor First descriptor.
	* @param other Second descriptor.
	* @param isEqual [OUT] TRUE if the descriptors are equal; FALSE otherwise.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*IsEqual)(PIActionDescriptor descriptor, PIActionDescriptor other, Boolean* isEqual);

	/**
	* Removes a given key from a descriptor.
	* @param descriptor The descriptor from which to remove a key.
	* @param DescriptorKeyID The key to remove.
	* @returns Non-zero error if failure
	*/
  	SPAPI OSErr (*Erase)(PIActionDescriptor descriptor, DescriptorKeyID );

	/**
	* Removes all keys from a descriptor.
	* @param descriptor The descriptor to clear.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*Clear)(PIActionDescriptor descriptor);

	/**
	* Puts an integer value (\c typeInteger) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The integer value to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutInteger)(PIActionDescriptor descriptor, DescriptorKeyID key, int32 value);

	/**
	* Puts a floating point number (\c typeFloat) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The floating point number to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, real64 value);

	/**
	* Puts a floating point number (\c typeUnitFloat) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param unit The unit of the floating point number to write.
	* @param value The floating point number to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutUnitFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorUnitID unit, real64 value);

	/**
	* Puts a string value (\c typeChar) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The string to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutString)(PIActionDescriptor descriptor, DescriptorKeyID key,  const char* cstrValue);

	/**
	* Puts a boolean value (\c typeBoolean) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The boolean to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutBoolean)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean value);

	/**
	* Puts a list (\c typeValueList) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The list to write. See @ref PicaActionListSuite.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutList)(PIActionDescriptor descriptor, DescriptorKeyID key,  PIActionList value);

	/**
	* Puts an object (\c typeObject) of a specified type into a descriptor for a given key.
	* @note Using @ref GetType for a key that contains an object returns \c typeObject, rather than
	* the \c type stored with the object.  This allows the code to easily determine which \c Get routine
	* to use to retrieve the object.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param type The type of object to write.
	* @param value The object to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID type,  PIActionDescriptor value);

	/**
	* Puts a global object (\c typeGlobalObject) of a specified type into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param type The type of object to write.
	* @param value The object to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutGlobalObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID type,  PIActionDescriptor value);

	/**
	* Puts an enumeration id for a specified enumeration (\c typeEnumerated) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param type The type of enumeration.
	* @param value The enumeration id to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutEnumerated)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorEnumTypeID type, DescriptorEnumID value);

	/**
	* Puts a reference (\c typeObjectReference into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The reference to write. See @ref PicaActionReferenceSuite.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutReference)(PIActionDescriptor descriptor, DescriptorKeyID key,  PIActionReference value);

	/**
	* Puts a class (\c typeClass) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The class to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID value);

	/**
	* Puts a global class (\c typeGlobalClass) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The class to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutGlobalClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID value);

	/**
	* Puts an alias (\c typeAlias) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The alias to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutAlias)(PIActionDescriptor descriptor, DescriptorKeyID key, Handle value);

	/**
	* Gets an integer value (\c typeInteger) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The integer value returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetInteger)(PIActionDescriptor descriptor, DescriptorKeyID key, int32* value);

	/**
	* Gets a floating point number (\c typeFloat) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The floating point number returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, real64* value);

	/**
	* Gets a unit floating point number (\c typeUnitFloat) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param unit The [OUT] The unit of the floating point number.
	* @param value [OUT] The floating point number returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetUnitFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorUnitID* unit, real64* value);

	/**
	* Gets the length of a string from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param stringLength [OUT] The length of the string associated with \c key.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetStringLength)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32* stringLength);

	/**
	* Gets a string (\c typeChar) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param cstrValue [OUT] The string returned.
	* @param maxLength The maximum number of characters to return.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetString)(PIActionDescriptor descriptor, DescriptorKeyID key, char* cstrValue, uint32 maxLength);

	/**
	* Gets a boolean value (\c typeBoolean) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The boolean value returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetBoolean)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean* value);

	/**
	* Gets a list (\c typeValueList) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The list returned.	 See @ref PicaActionListSuite.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetList)(PIActionDescriptor descriptor, DescriptorKeyID key, PIActionList* value);

	/**
	* Gets an object (\c  typeObject) from a descriptor for a given key.
	* @note Using @ref GetType for a key that contains an object returns \c typeObject, rather than
	* the \c type stored with the object.  This allows the code to easily determine which \c Get routine
	* to use to retrieve the object.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param type [OUT] The type of object returned.
	* @param value [OUT] The object returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* type, PIActionDescriptor* value);

	/**
	* Gets a global object (\c typeGlobalObject) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param type [OUT] The type of object returned.
	* @param value [OUT] The object returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetGlobalObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* type, PIActionDescriptor* value);

	/**
	* Gets an enumeration value (\c typeEnumerated) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param type [OUT] The type of enumeration returned.
	* @param value [OUT] The enumeration id returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetEnumerated)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorEnumTypeID* type, DescriptorEnumID* value);

	/**
	* Gets a reference (\c typeObjectReference, typeObjectSpecifier) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The reference returned. See @ref PicaActionReferenceSuite.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetReference)(PIActionDescriptor descriptor, DescriptorKeyID key, PIActionReference* value);

	/**
	* Gets a class (\c typeClass) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The class returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* value);

	/**
	* Gets a global class (\c typeGlobalClass) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The class returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetGlobalClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* value);

	/**
	* Gets an alias (\c typeAlias) from a descriptor for a given key.
	* Use DisposeRegularHandle from the Handle suite to dispose of the handle.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The alias returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetAlias)(PIActionDescriptor descriptor, DescriptorKeyID key, Handle* value);

	/**
	* Checks if a descriptor has a list of given keys.
	* @param descriptor The descriptor to check.
	* @param requiredKeys The keys to find in the descriptor.
	* @param hasKeys [OUT] TRUE if all the keys exist in the descriptor; FALSE otherwise.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*HasKeys)(PIActionDescriptor descriptor, DescriptorKeyIDArray requiredKeys, Boolean* hasKeys);

	/**
	* Puts an array of integers into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param count The number of integers in the array.
	* @param value The array of integers.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*PutIntegers)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32 count,  int32* );

	/**
	* Gets an array of integers from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param count The number of integers to return in the array.
	* @param value [OUT] The array of integers returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetIntegers)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32 count, int32* value);

	/**
	* Returns the descriptor as a handle.
	* Allows a plug-in to convert a PICA Action Descriptor to a descriptor used in the
	* non-PICA @ref DescriptorSuite.  This is typically done after writing out a descriptor
	* using the PICA Descriptor Suite, before sending the descriptor back to the host
	* through the parameter block's \c descriptorParameters->descriptor field.
	* @param descriptor	The descriptor.
	* @param value [OUT] The handle returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*AsHandle)(PIActionDescriptor descriptor, PIDescriptorHandle* value);

	/**
	* Returns a handle as a descriptor.
	* Allows a plug-in to convert a descriptor used in the non-PICA @ref DescriptorSuite into a
	* PICA Action Descriptor. This is typically done after reading the descriptor from the
	* parameter block's \c descriptorParameters->descriptor field, so the plug-in can
	* use the PICA Descriptor Suite to access the descriptor.
	* @param value The handle.
	* @param descriptor	[OUT] The descriptor returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*HandleToDescriptor)(PIDescriptorHandle value, PIActionDescriptor* descriptor);

	/**
	* Puts a zstring  (\c typeChar) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param zstring The zstring to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutZString)(PIActionDescriptor descriptor, DescriptorKeyID key, ASZString zstring);

	/**
	* Gets a zstring  (\c typeChar) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param zstring [OUT] The zstring returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetZString)(PIActionDescriptor descriptor, DescriptorKeyID key, ASZString* zstring);

	/**
	* Puts a data block  (\c typeRawData) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param length The length of the data block
	* @param value The data block to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutData)(PIActionDescriptor descriptor, DescriptorKeyID key, int32 length, void* value);

	/**
	* Gets the length of a data block from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The length of the data block
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetDataLength)(PIActionDescriptor descriptor, DescriptorKeyID key, int32* value);

	/**
	* Gets a data block (\c typeRawData) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The data block returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetData)(PIActionDescriptor descriptor, DescriptorKeyID key, void* value);

	/**
	* Puts a 64 bit integer value (\c typeComp (typeSInt64)) into a descriptor for a given key.
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param value The 64 bit integer value to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutInteger64)(PIActionDescriptor descriptor, DescriptorKeyID key, int64 value);

	/**
	* Gets a 64 bit integer value (\c typeComp (typeSInt64)) from a descriptor for a given key.
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The 64 bit integer value returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetInteger64)(PIActionDescriptor descriptor, DescriptorKeyID key, int64* value);

	/**
	* Make a new descriptor with a specific class
    * @param value the desired class for the new descriptor
	* @param descriptor [OUT] The new descriptor.
	* @returns Non-zero error if unable
	*/
	SPAPI OSErr (*MakeWithClass)(DescriptorClassID value, PIActionDescriptor* descriptor);

	/**
	* Returns the class for the provided descriptor.
	* @param descriptor The descriptor from which to read.
	* @param type [OUT] The descriptor class returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetDescriptorClass)(PIActionDescriptor descriptor, DescriptorClassID* value);

	/**
	* Returns a copy of the provided descriptor.
    * This is useful in cases where a descriptor which originates from Photoshop needs to be
    * retained past the current scope.
    * An example is a notification based descriptor. This descriptor is released when the
    * notifier function returns to Photoshop. If the receiver wants to retain the descriptor
    * it can create a copy.
	* @param descriptor The descriptor to copy. May not be NULL.
	* @param copy [OUT] Will hold a copy of the descriptor after the call returns. The caller
    *                   is responsible for calling Free on this descriptor
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*Copy)(PIActionDescriptor descriptor, PIActionDescriptor* copy);

	/**
	* Macintosh only, converts a bookmark into an alias (\c typeAlias) and puts it into a descriptor for a given key.
	* Will switch to typeBookmark when Photoshop quits using the Alias Manager for aliases and switches to bookmarks
	* @param descriptor The descriptor in which to write.
	* @param key The key to write.
	* @param bookmark The bookmark to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutBookmark)(PIActionDescriptor descriptor, DescriptorKeyID key, CFDataRef value);

	/**
	* Macintosh only, gets an alias (\c typeAlias) from a descriptor for a given key, converts to a bookmark, and returns it
	* Will switch to typeBookmark when Photoshop quits using the Alias Manager for aliases and switches to bookmarks
	* @param descriptor The descriptor from which to read.
	* @param key The key to read.
	* @param value [OUT] The bookmark returned. Caller must call CFRelease on the bookmark.
	* The bookmark will be NULL if the alias points to something which is not currently accessible.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetBookmark)(PIActionDescriptor descriptor, DescriptorKeyID key, CFDataRef* value);

	} PSActionDescriptorProcs;
/* @} */

/**
 * The set of routines available in the Action Descriptor Suite. Version 3. See above for documentation.
 */
typedef struct PSActionDescriptorProcs3
{
    SPAPI OSErr (*Make)(PIActionDescriptor* descriptor);
    SPAPI OSErr (*Free)(PIActionDescriptor descriptor);
    SPAPI OSErr (*GetType)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorTypeID* type);
    SPAPI OSErr (*GetKey)(PIActionDescriptor descriptor, uint32 index, DescriptorKeyID* key);
    SPAPI OSErr (*HasKey)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean* hasKey);
    SPAPI OSErr (*GetCount)(PIActionDescriptor descriptor, uint32* count);
    SPAPI OSErr (*IsEqual)(PIActionDescriptor descriptor, PIActionDescriptor other, Boolean* isEqual);
    SPAPI OSErr (*Erase)(PIActionDescriptor descriptor, DescriptorKeyID );
    SPAPI OSErr (*Clear)(PIActionDescriptor descriptor);
    SPAPI OSErr (*PutInteger)(PIActionDescriptor descriptor, DescriptorKeyID key, int32 value);
    SPAPI OSErr (*PutFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, real64 value);
    SPAPI OSErr (*PutUnitFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorUnitID unit, real64 value);
    SPAPI OSErr (*PutString)(PIActionDescriptor descriptor, DescriptorKeyID key,  const char* cstrValue);
    SPAPI OSErr (*PutBoolean)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean value);
    SPAPI OSErr (*PutList)(PIActionDescriptor descriptor, DescriptorKeyID key,  PIActionList value);
    SPAPI OSErr (*PutObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID type,  PIActionDescriptor value);
    SPAPI OSErr (*PutGlobalObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID type,  PIActionDescriptor value);
    SPAPI OSErr (*PutEnumerated)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorEnumTypeID type, DescriptorEnumID value);
    SPAPI OSErr (*PutReference)(PIActionDescriptor descriptor, DescriptorKeyID key,  PIActionReference value);
    SPAPI OSErr (*PutClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID value);
    SPAPI OSErr (*PutGlobalClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID value);
    SPAPI OSErr (*PutAlias)(PIActionDescriptor descriptor, DescriptorKeyID key, Handle value);
    SPAPI OSErr (*GetInteger)(PIActionDescriptor descriptor, DescriptorKeyID key, int32* value);
    SPAPI OSErr (*GetFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, real64* value);
    SPAPI OSErr (*GetUnitFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorUnitID* unit, real64* value);
    SPAPI OSErr (*GetStringLength)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32* stringLength);
    SPAPI OSErr (*GetString)(PIActionDescriptor descriptor, DescriptorKeyID key, char* cstrValue, uint32 maxLength);
    SPAPI OSErr (*GetBoolean)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean* value);
    SPAPI OSErr (*GetList)(PIActionDescriptor descriptor, DescriptorKeyID key, PIActionList* value);
    SPAPI OSErr (*GetObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetGlobalObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetEnumerated)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorEnumTypeID* type, DescriptorEnumID* value);
    SPAPI OSErr (*GetReference)(PIActionDescriptor descriptor, DescriptorKeyID key, PIActionReference* value);
    SPAPI OSErr (*GetClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* value);
    SPAPI OSErr (*GetGlobalClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* value);
    SPAPI OSErr (*GetAlias)(PIActionDescriptor descriptor, DescriptorKeyID key, Handle* value);
    SPAPI OSErr (*HasKeys)(PIActionDescriptor descriptor, DescriptorKeyIDArray requiredKeys, Boolean* hasKeys);
    SPAPI OSErr (*PutIntegers)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32 count,  int32* );
    SPAPI OSErr (*GetIntegers)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32 count, int32* value);
    SPAPI OSErr (*AsHandle)(PIActionDescriptor descriptor, PIDescriptorHandle* value);
    SPAPI OSErr (*HandleToDescriptor)(PIDescriptorHandle value, PIActionDescriptor* descriptor);
    SPAPI OSErr (*PutZString)(PIActionDescriptor descriptor, DescriptorKeyID key, ASZString zstring);
    SPAPI OSErr (*GetZString)(PIActionDescriptor descriptor, DescriptorKeyID key, ASZString* zstring);
    SPAPI OSErr (*PutData)(PIActionDescriptor descriptor, DescriptorKeyID key, int32 length, void* value);
    SPAPI OSErr (*GetDataLength)(PIActionDescriptor descriptor, DescriptorKeyID key, int32* value);
    SPAPI OSErr (*GetData)(PIActionDescriptor descriptor, DescriptorKeyID key, void* value);
    SPAPI OSErr (*PutInteger64)(PIActionDescriptor descriptor, DescriptorKeyID key, int64 value);
    SPAPI OSErr (*GetInteger64)(PIActionDescriptor descriptor, DescriptorKeyID key, int64* value);
} PSActionDescriptorProcs3;
/* @} */

/**
 * The set of routines available in the Action Descriptor Suite. Version 2. See above for documentation.
 */
typedef struct PSActionDescriptorProcs2
{
    SPAPI OSErr (*Make)(PIActionDescriptor* descriptor);
    SPAPI OSErr (*Free)(PIActionDescriptor descriptor);
    SPAPI OSErr (*GetType)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorTypeID* type);
    SPAPI OSErr (*GetKey)(PIActionDescriptor descriptor, uint32 index, DescriptorKeyID* key);
    SPAPI OSErr (*HasKey)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean* hasKey);
    SPAPI OSErr (*GetCount)(PIActionDescriptor descriptor, uint32* count);
    SPAPI OSErr (*IsEqual)(PIActionDescriptor descriptor, PIActionDescriptor other, Boolean* isEqual);
    SPAPI OSErr (*Erase)(PIActionDescriptor descriptor, DescriptorKeyID );
    SPAPI OSErr (*Clear)(PIActionDescriptor descriptor);
    SPAPI OSErr (*PutInteger)(PIActionDescriptor descriptor, DescriptorKeyID key, int32 value);
    SPAPI OSErr (*PutFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, real64 value);
    SPAPI OSErr (*PutUnitFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorUnitID unit, real64 value);
    SPAPI OSErr (*PutString)(PIActionDescriptor descriptor, DescriptorKeyID key,  const char* cstrValue);
    SPAPI OSErr (*PutBoolean)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean value);
    SPAPI OSErr (*PutList)(PIActionDescriptor descriptor, DescriptorKeyID key,  PIActionList value);
    SPAPI OSErr (*PutObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID type,  PIActionDescriptor value);
    SPAPI OSErr (*PutGlobalObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID type,  PIActionDescriptor value);
    SPAPI OSErr (*PutEnumerated)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorEnumTypeID type, DescriptorEnumID value);
    SPAPI OSErr (*PutReference)(PIActionDescriptor descriptor, DescriptorKeyID key,  PIActionReference value);
    SPAPI OSErr (*PutClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID value);
    SPAPI OSErr (*PutGlobalClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID value);
    SPAPI OSErr (*PutAlias)(PIActionDescriptor descriptor, DescriptorKeyID key, Handle value);
    SPAPI OSErr (*GetInteger)(PIActionDescriptor descriptor, DescriptorKeyID key, int32* value);
    SPAPI OSErr (*GetFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, real64* value);
    SPAPI OSErr (*GetUnitFloat)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorUnitID* unit, real64* value);
    SPAPI OSErr (*GetStringLength)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32* stringLength);
    SPAPI OSErr (*GetString)(PIActionDescriptor descriptor, DescriptorKeyID key, char* cstrValue, uint32 maxLength);
    SPAPI OSErr (*GetBoolean)(PIActionDescriptor descriptor, DescriptorKeyID key, Boolean* value);
    SPAPI OSErr (*GetList)(PIActionDescriptor descriptor, DescriptorKeyID key, PIActionList* value);
    SPAPI OSErr (*GetObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetGlobalObject)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetEnumerated)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorEnumTypeID* type, DescriptorEnumID* value);
    SPAPI OSErr (*GetReference)(PIActionDescriptor descriptor, DescriptorKeyID key, PIActionReference* value);
    SPAPI OSErr (*GetClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* value);
    SPAPI OSErr (*GetGlobalClass)(PIActionDescriptor descriptor, DescriptorKeyID key, DescriptorClassID* value);
    SPAPI OSErr (*GetAlias)(PIActionDescriptor descriptor, DescriptorKeyID key, Handle* value);
    SPAPI OSErr (*HasKeys)(PIActionDescriptor descriptor, DescriptorKeyIDArray requiredKeys, Boolean* hasKeys);
    SPAPI OSErr (*PutIntegers)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32 count,  int32* );
    SPAPI OSErr (*GetIntegers)(PIActionDescriptor descriptor, DescriptorKeyID key, uint32 count, int32* value);
    SPAPI OSErr (*AsHandle)(PIActionDescriptor descriptor, PIDescriptorHandle* value);
    SPAPI OSErr (*HandleToDescriptor)(PIDescriptorHandle value, PIActionDescriptor* descriptor);
    SPAPI OSErr (*PutZString)(PIActionDescriptor descriptor, DescriptorKeyID key, ASZString zstring);
    SPAPI OSErr (*GetZString)(PIActionDescriptor descriptor, DescriptorKeyID key, ASZString* zstring);
    SPAPI OSErr (*PutData)(PIActionDescriptor descriptor, DescriptorKeyID key, int32 length, void* value);
    SPAPI OSErr (*GetDataLength)(PIActionDescriptor descriptor, DescriptorKeyID key, int32* value);
    SPAPI OSErr (*GetData)(PIActionDescriptor descriptor, DescriptorKeyID key, void* value);
} PSActionDescriptorProcs2;
/* @} */

//-------------------------------------------------------------------------------
//	ActionList suite.  Use to manage lists of keys.
//-------------------------------------------------------------------------------
/**
* @defgroup PicaActionListSuite Action List Suite
* Allows a plug-in to get values from and put values into a list.  These lists
* can be used as values for Action Descriptors. See @ref PicaActionDescriptorSuite.
*
* <b> Accessing the Suite </b> \n\n
* The Action List suite is referred to as:
* @code
  #define kPSActionListSuite	"df135116-c769-11d0-8079-00c04fd7ec47"
@endcode
* with the version constant:
* @code
  #define	kPSActionListSuiteVersion	1
@endcode
* The suite is acquired as follows:
* @code
  PSActionListProcs *sPSActionList;
  error = sSPBasic->AcquireSuite(kPSActionListSuite,
  								 kPSActionListSuiteVersion,
  								 &sPSActionList);
  if (error) goto . . . //handle error
@endcode
* Or, alternatively, use the global variable \c sPSActionList, by including the
* header file \c sampleCode\\common\\includes\\PIUSuites.h.  \n\n
* For PICA errors, see SPErrorCodes.h.
* @{
*/

/// Unique identifier for the Action List Suite
#define kPSActionListSuite			"df135116-c769-11d0-8079-00c04fd7ec47"
/// Current version of the Action List Suite. First release, CC 2015.5 version 17.0
#define	kPSActionListSuiteVersion		3
/// CS5 version 12.0
#define	kPSActionListSuiteVersion2		2
/// Original version
#define	kPSActionListSuiteVersion1		1

/**
* The set of available routines for the Action List Suite.
*/
typedef struct PSActionListProcs
	{

	/**
	* Make a new list.
	* @param actionList [OUT] The new list.
	* @returns Non-zero error if unable to allocate the memory.
	*/
	SPAPI OSErr (*Make)(PIActionList* actionList);

	/**
	* Free a list
	* @param actionList The list to free the memory for.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Free)(PIActionList actionList);

	/**
	* Gets the type for an index within a list. Often used with @ref GetCount to iterate
	* through a list, getting the type of each item in a list, and then using the index
	* and type to retrieve the value.  See the individual \c Get and \c Put routines for
	* the types associated with each.
	* @param list List to get the type of.
	* @param index  Index to get the type of.
	* @param value [OUT] Type for the value stored at index.
	* and the \c Get and \c Put routines for possible values.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetType)(PIActionList list, uint32 index, DescriptorTypeID* value);

	/**
	* Returns the number of items in the list. 	See @ref GetType for an example.
	* @param list The list from which to get the count.
	* @param value [OUT] The number of items in the list.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetCount)(PIActionList list, uint32* value);

	/**
	* Puts an integer value (\c typeInteger) into a list.
	* @param list The list in which to write.
	* @param value The integer value to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutInteger)(PIActionList list, int32 value);

	/**
	* Puts a floating point number (\c typeFloat) into a list.
	* @param list The list in which to write.
	* @param value The floating point number to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutFloat)(PIActionList list, real64 value);

	/**
	* Puts a unit floating point number (\c typeUnitFloat) into a list.
	* @param list The list in which to write.
	* @param unit The unit to write.
	* @param value The floating point number to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutUnitFloat)(PIActionList list, DescriptorUnitID unit, real64 value);

	/**
	* Puts a string (\c typeChar) into a list.
	* @param list The list in which to write.
	* @param cstr The string to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutString)(PIActionList list, const char* cstr);

	/**
	* Puts a boolean value (\c typeBoolean) into a list.
	* @param list The list in which to write.
	* @param value The boolean to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutBoolean)(PIActionList list, Boolean value);

	/**
	* Puts a list (\c typeValueList) into a list.
	* @param list The list in which to write.
	* @param value The list to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutList)(PIActionList list, PIActionList value);

	/**
	* Puts an object (\c  typeObject) of a specified type into a list.
	* @note Using @ref GetType on an index that contains an object returns \c typeObject, rather than
	* the \c type stored with the object.  This allows the code to easily determine which \c Get routine
	* to use to retrieve the object.  The actual type of the object is retrieved with @ref GetObject.
	* @param list The list in which to write.
	* @param type The type of object to insert.
	* @param value The object to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutObject)(PIActionList list, DescriptorClassID type, PIActionDescriptor value);

	/**
	* Puts a global object (\c  typeGlobalObject) of a specified type into a list.
	* @note Using @ref GetType on an index that contains a global object returns \c typeGlobalObject, rather than
	* the \c type stored with the object.  This allows the code to easily determine which \c Get routine
	* to use to retrieve the object.  The actual type of the object is retrieved with @ref GetGlobalObject.
	* @param list The list in which to write.
	* @param type The type of object to insert.
	* @param value The object to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutGlobalObject)(PIActionList list, DescriptorClassID type, PIActionDescriptor value);

	/**
	* Puts an enumeration id for a specified enumeration (\c typeEnumerated) into a list.
	* @param list The list in which to write.
	* @param type The type of enumeration.
	* @param value The enumeration id to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutEnumerated)(PIActionList list, DescriptorEnumTypeID type, DescriptorEnumID value);

	/**
	* Puts a reference (\c typeObjectReference, \c typeObjectSpecifier) into a list.
	* @param list The list in which to write.
	* @param value The reference to insert. See @ref PicaActionReferenceSuite.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutReference)(PIActionList list, PIActionReference value);

	/**
	* Puts a class (\c typeClass) into a list.
	* @param list The list in which to write.
	* @param value The class to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutClass)(PIActionList list, DescriptorClassID value);

	/**
	* Puts a global class (\c typeGlobalClass) into a list.
	* @param list The list in which to write.
	* @param value The class to insert.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*PutGlobalClass)(PIActionList list, DescriptorClassID value);

	/**
	* Puts an alias (\c typeAlias) into a list.
	* @param descriptor The list in which to write.
	* @param value The alias to insert.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*PutAlias)(PIActionList list, Handle value);

	/**
	* Gets an integer value (\c typeInteger) from a list, given an indexed position in the list.
	* Typically, code iterates through the indices in a list, first getting the type of the
	* item, and using the type to select the appropriate \c Get routine.  See @ref GetType for an
	* example.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The integer value returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetInteger)(PIActionList list, uint32 index, int32* value);

	/**
	* Gets a floating point number (\c typeFloat) from a list, given an indexed position in the list.
	* Typically, code iterates through the indices in a list, first getting the type of the
	* item, and using the type to select the appropriate \c Get routine.  See @ref GetType for an
	* example.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The floating point number returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetFloat)(PIActionList list, uint32 index, real64* value);

	/**
	* Gets a unit floating point number (\c typeUnitFloat) from a list, given an indexed position in the list.
	* Typically, code iterates through the indices in a list, first getting the type of the
	* item, and using the type to select the appropriate \c Get routine.  See @ref GetType for an
	* example.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param unit [OUT] The unit returned.
	* @param value [OUT] The floating point number returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetUnitFloat)(PIActionList list, uint32 index, DescriptorUnitID* unit, real64* value);

	/**
	* Gets a string length from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param stringLength [OUT] The length of the string at the indexed position.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetStringLength)(PIActionList list, uint32 index, uint32* stringLength);

	/**
	* Gets a string (\c typeChar) from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param cstr [OUT] The length of the string at the indexed position.
	* @param maxLength The maximum number of characters to return.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetString)(PIActionList list, uint32 index, char* cstr, uint32 maxLength);

	/**
	* Gets a boolean value (\c typeBoolean) from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The boolean value returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetBoolean)(PIActionList list, uint32 index, Boolean* value);

	/**
	* Gets a list (\c typeValueList) from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The list returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetList)(PIActionList list, uint32 index, PIActionList* actionList);

	/**
	* Gets an object (\c typeObject) from a list, given an indexed position in the list.
	* @note Using @ref GetType on an index that contains an object returns \c typeObject, rather than
	* the \c type stored with the object.  This allows the code to easily determine which \c Get routine
	* to use to retrieve the object.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param type [OUT] The type of the object returned.
	* @param value [OUT] The list returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetObject)(PIActionList list, uint32 index, DescriptorClassID* type, PIActionDescriptor* value);

	/**
	* Gets a global object (\c typeGlobalObject) from a list, given an indexed position in the list.
	* @note Using @ref GetType on an index that contains a global object returns \c typeGlobalObject, rather than
	* the \c type stored with the object.  This allows the code to easily determine which \c Get routine
	* to use to retrieve the object.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param type [OUT] The type of the object returned.
	* @param value [OUT] The list returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetGlobalObject)(PIActionList list, uint32 index, DescriptorClassID* type, PIActionDescriptor* value);

	/**
	* Gets an enumeration id and an enumeration type (\c typeEnumerated) from a list,
	* given an indexed position in the list.
	* @param list The list from which to read.
	* @param type [OUT] The type of enumeration, returned.
	* @param value [OUT] The enumeration id, returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetEnumerated)(PIActionList list, uint32 index, DescriptorEnumTypeID* type, DescriptorEnumID* value);

	/**
	* Gets a basic reference (\c typeObjectReference) from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The object reference returned.	 See @ref PicaActionReferenceSuite.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetReference)(PIActionList list, uint32 index, PIActionReference* value);

	/**
	* Gets a class (\c typeClass) from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The class returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetClass)(PIActionList list, uint32 index, DescriptorClassID* value);

	/**
	* Gets a global class (\c typeGlobalClass) from a list, given an indexed position in the list.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The global class returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetGlobalClass)(PIActionList list, uint32 index, DescriptorClassID* value);

	/**
	* Gets an alias (\c typeAlias) from a list, given an indexed position in the list.
	* Use DisposeRegularHandle from the Handle suite to dispose of the handle.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param aliasHandle [OUT] The alias returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetAlias)(PIActionList list, uint32 index, Handle* aliasHandle);

	/**
	* Puts \c count values from an integer array into a list.
	* @param list The list in which to write.
	* @param count The number of integers to write.
	* @param int32 Array containing the integer values to write.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*PutIntegers)(PIActionList list, uint32 count, int32* );

	/**
	* Gets \c count values into integer array \c value from a list.
	* @param list The list in which to write.
	* @param count The number of integers to return.
	* @param value [OUT] Array of integer values returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetIntegers)(PIActionList list, uint32 count, int32* value);

	/**
	* Puts a data block (\c typeRawData) into a list.
	* @param list The list in which to write.
	* @param length The length of the data block.
	* @param data The data block to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutData)(PIActionList list, int32 length, void* data);

	/**
	* Gets the length of a data block from a list for a given index.
	* @param list The list from which to read.
	* @param index The index for which to return the data block length.
	* @param value [OUT] The length of the data block.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetDataLength)(PIActionList list, uint32 index, int32* length);

	/**
	* Gets a data block (\c typeRawData) from a list for a given index.
	* @param list The list from which to read.
	* @param index The index for which to return the data block.
	* @param value [OUT] The data block returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetData)(PIActionList list, uint32 index, void* value);

	/**
	* Puts a zstring  (\c typeChar) into a list.
	* @param list The list in which to write.
	* @param zstring The zstring to write.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutZString)(PIActionList list, ASZString zstring);

	/**
	* Gets a zstring  (\c typeChar) from a list for a given index.
	* @param list The list from which to read.
	* @param index The index for which to return the string.
	* @param zstring [OUT] The zstring returned.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*GetZString)(PIActionList list, uint32 index, ASZString* zstring);

	/**
	* Puts a 64 bit integer value (\c typeComp (typeSInt64)) into a list.
	* @param list The list in which to write.
	* @param value The 64 bit integer value to insert.
	* @returns Non-zero error if failure
	*/
	SPAPI OSErr (*PutInteger64)(PIActionList list, int64 value);

	/**
	* Gets a 64 bit integer value (\c typeComp (typeSInt64)) from a list,
	* given an indexed position in the list.
	* Typically, code iterates through the indices in a list, first getting the type of the
	* item, and using the type to select the appropriate \c Get routine.  See @ref GetType for an
	* example.
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param value [OUT] The 64 bit integer value returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetInteger64)(PIActionList list, uint32 index, int64 *value);

	/**
	* Converts a bookmark to an alias and puts that alias (\c typeAlias) into a list.
	* Will switch to typeBookmark when Photoshop quits using the Alias Manager for aliases and switches to bookmarks
	* @param descriptor The list in which to write.
	* @param value The bookmark to insert.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*PutBookmark)(PIActionList list, CFDataRef value);

	/**
	* Gets an alias (\c typeAlias) from a list, given an indexed position in the list, converts to a bookmark, and returns it
	* Will switch to typeBookmark when Photoshop quits using the Alias Manager for aliases and switches to bookmarks
	* @param list The list from which to read.
	* @param index Indexed position in the list to retrieve.
	* @param bookmark [OUT] The bookmark returned. Caller must call CFRelease on the bookmark.
	* The bookmark will be NULL if the alias points to something which is not currently accessible.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*GetBookmark)(PIActionList list, uint32 index, CFDataRef* bookmark);

	} PSActionListProcs;
/* @} */

/**
 * The set of available routines for the Action List Suite. Version 2, see above for documentation
 */
typedef struct PSActionListProcs2
{
    SPAPI OSErr (*Make)(PIActionList* actionList);
    SPAPI OSErr (*Free)(PIActionList actionList);
    SPAPI OSErr (*GetType)(PIActionList list, uint32 index, DescriptorTypeID* value);
    SPAPI OSErr (*GetCount)(PIActionList list, uint32* value);
    SPAPI OSErr (*PutInteger)(PIActionList list, int32 value);
    SPAPI OSErr (*PutFloat)(PIActionList list, real64 value);
    SPAPI OSErr (*PutUnitFloat)(PIActionList list, DescriptorUnitID unit, real64 value);
    SPAPI OSErr (*PutString)(PIActionList list, const char* cstr);
    SPAPI OSErr (*PutBoolean)(PIActionList list, Boolean value);
    SPAPI OSErr (*PutList)(PIActionList list, PIActionList value);
    SPAPI OSErr (*PutObject)(PIActionList list, DescriptorClassID type, PIActionDescriptor value);
    SPAPI OSErr (*PutGlobalObject)(PIActionList list, DescriptorClassID type, PIActionDescriptor value);
    SPAPI OSErr (*PutEnumerated)(PIActionList list, DescriptorEnumTypeID type, DescriptorEnumID value);
    SPAPI OSErr (*PutReference)(PIActionList list, PIActionReference value);
    SPAPI OSErr (*PutClass)(PIActionList list, DescriptorClassID value);
    SPAPI OSErr (*PutGlobalClass)(PIActionList list, DescriptorClassID value);
    SPAPI OSErr (*PutAlias)(PIActionList list, Handle value);
    SPAPI OSErr (*GetInteger)(PIActionList list, uint32 index, int32* value);
    SPAPI OSErr (*GetFloat)(PIActionList list, uint32 index, real64* value);
    SPAPI OSErr (*GetUnitFloat)(PIActionList list, uint32 index, DescriptorUnitID* unit, real64* value);
    SPAPI OSErr (*GetStringLength)(PIActionList list, uint32 index, uint32* stringLength);
    SPAPI OSErr (*GetString)(PIActionList list, uint32 index, char* cstr, uint32 maxLength);
    SPAPI OSErr (*GetBoolean)(PIActionList list, uint32 index, Boolean* value);
    SPAPI OSErr (*GetList)(PIActionList list, uint32 index, PIActionList* actionList);
    SPAPI OSErr (*GetObject)(PIActionList list, uint32 index, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetGlobalObject)(PIActionList list, uint32 index, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetEnumerated)(PIActionList list, uint32 index, DescriptorEnumTypeID* type, DescriptorEnumID* value);
    SPAPI OSErr (*GetReference)(PIActionList list, uint32 index, PIActionReference* value);
    SPAPI OSErr (*GetClass)(PIActionList list, uint32 index, DescriptorClassID* value);
    SPAPI OSErr (*GetGlobalClass)(PIActionList list, uint32 index, DescriptorClassID* value);
    SPAPI OSErr (*GetAlias)(PIActionList list, uint32 index, Handle* aliasHandle);
    SPAPI OSErr (*PutIntegers)(PIActionList list, uint32 count, int32* );
    SPAPI OSErr (*GetIntegers)(PIActionList list, uint32 count, int32* value);
    SPAPI OSErr (*PutData)(PIActionList list, int32 length, void* data);
    SPAPI OSErr (*GetDataLength)(PIActionList list, uint32 index, int32* length);
    SPAPI OSErr (*GetData)(PIActionList list, uint32 index, void* value);
    SPAPI OSErr (*PutZString)(PIActionList list, ASZString zstring);
    SPAPI OSErr (*GetZString)(PIActionList list, uint32 index, ASZString* zstring);
    SPAPI OSErr (*PutInteger64)(PIActionList list, int64 value);
    SPAPI OSErr (*GetInteger64)(PIActionList list, uint32 index, int64 *value);
} PSActionListProcs2;
/* @} */

/**
 * The set of available routines for the Action List Suite. See above for documentation.
 */
typedef struct PSActionListProcs1
{
    SPAPI OSErr (*Make)(PIActionList* actionList);
    SPAPI OSErr (*Free)(PIActionList actionList);
    SPAPI OSErr (*GetType)(PIActionList list, uint32 index, DescriptorTypeID* value);
    SPAPI OSErr (*GetCount)(PIActionList list, uint32* value);
    SPAPI OSErr (*PutInteger)(PIActionList list, int32 value);
    SPAPI OSErr (*PutFloat)(PIActionList list, real64 value);
    SPAPI OSErr (*PutUnitFloat)(PIActionList list, DescriptorUnitID unit, real64 value);
    SPAPI OSErr (*PutString)(PIActionList list, const char* cstr);
    SPAPI OSErr (*PutBoolean)(PIActionList list, Boolean value);
    SPAPI OSErr (*PutList)(PIActionList list, PIActionList value);
    SPAPI OSErr (*PutObject)(PIActionList list, DescriptorClassID type, PIActionDescriptor value);
    SPAPI OSErr (*PutGlobalObject)(PIActionList list, DescriptorClassID type, PIActionDescriptor value);
    SPAPI OSErr (*PutEnumerated)(PIActionList list, DescriptorEnumTypeID type, DescriptorEnumID value);
    SPAPI OSErr (*PutReference)(PIActionList list, PIActionReference value);
    SPAPI OSErr (*PutClass)(PIActionList list, DescriptorClassID value);
    SPAPI OSErr (*PutGlobalClass)(PIActionList list, DescriptorClassID value);
    SPAPI OSErr (*PutAlias)(PIActionList list, Handle value);
    SPAPI OSErr (*GetInteger)(PIActionList list, uint32 index, int32* value);
    SPAPI OSErr (*GetFloat)(PIActionList list, uint32 index, real64* value);
    SPAPI OSErr (*GetUnitFloat)(PIActionList list, uint32 index, DescriptorUnitID* unit, real64* value);
    SPAPI OSErr (*GetStringLength)(PIActionList list, uint32 index, uint32* stringLength);
    SPAPI OSErr (*GetString)(PIActionList list, uint32 index, char* cstr, uint32 maxLength);
    SPAPI OSErr (*GetBoolean)(PIActionList list, uint32 index, Boolean* value);
    SPAPI OSErr (*GetList)(PIActionList list, uint32 index, PIActionList* actionList);
    SPAPI OSErr (*GetObject)(PIActionList list, uint32 index, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetGlobalObject)(PIActionList list, uint32 index, DescriptorClassID* type, PIActionDescriptor* value);
    SPAPI OSErr (*GetEnumerated)(PIActionList list, uint32 index, DescriptorEnumTypeID* type, DescriptorEnumID* value);
    SPAPI OSErr (*GetReference)(PIActionList list, uint32 index, PIActionReference* value);
    SPAPI OSErr (*GetClass)(PIActionList list, uint32 index, DescriptorClassID* value);
    SPAPI OSErr (*GetGlobalClass)(PIActionList list, uint32 index, DescriptorClassID* value);
    SPAPI OSErr (*GetAlias)(PIActionList list, uint32 index, Handle* aliasHandle);
    SPAPI OSErr (*PutIntegers)(PIActionList list, uint32 count, int32* );
    SPAPI OSErr (*GetIntegers)(PIActionList list, uint32 count, int32* value);
    SPAPI OSErr (*PutData)(PIActionList list, int32 length, void* data);
    SPAPI OSErr (*GetDataLength)(PIActionList list, uint32 index, int32* length);
    SPAPI OSErr (*GetData)(PIActionList list, uint32 index, void* value);
    SPAPI OSErr (*PutZString)(PIActionList list, ASZString zstring);
    SPAPI OSErr (*GetZString)(PIActionList list, uint32 index, ASZString* zstring);
} PSActionListProcs1;
/* @} */

//-------------------------------------------------------------------------------
//	ActionReference suite.  Use to build references to objects to be able to
//	get/set properties and target events.
//-------------------------------------------------------------------------------

/**
* @defgroup PicaActionReferenceSuite Action Reference Suite
* Provides routines for building references to objects, which allows the plug-in to
* get and set properties and target events from the @ref PicaActionControlSuite and
* the @ref PicaBasicControlSuite.  These references can also be used to build descriptors
* and lists by the @ref PicaActionDescriptorSuite and @ref PicaActionListSuite.
*
* <b> Accessing the Suite </b> \n\n
* The Action Reference suite is referred to as:
* @code
  #define kPSActionReferenceSuite	"df135117-c769-11d0-8079-00c04fd7ec47"
@endcode
* with the version constant:
* @code
  #define	kPSActionReferenceSuiteVersion	2
@endcode
* The suite is acquired as follows:
* @code
  PSActionReferenceProcs *sPSActionReference;
  error = sSPBasic->AcquireSuite(kPSActionReferenceSuite,
  								 kPSActionReferenceSuiteVersion,
  								 &sPSActionReference);
  if (error) goto . . . //handle error
@endcode
* Or, alternatively, use the global variable \c sPSActionReference, by including the
* header file \c sampleCode\\common\\includes\\PIUSuites.h.  \n\n
* For PICA errors, see SPErrorCodes.h.
* @{
*/

/// The unique identifier for the Action Reference Suite.
#define kPSActionReferenceSuite			"df135117-c769-11d0-8079-00c04fd7ec47"
/// The current version of the Action Reference Suite.
#define	kPSActionReferenceSuiteVersion	3
#define kPSActionReferenceSuitePrevVersion	2

/**
* The set of routines available in the Action Reference Suite.
*/
typedef struct PSActionReferenceProcs
	{

	/**
	* Make a new reference.
	* @param reference [OUT] The new reference.
	* @returns Non-zero error if unable to allocate the memory.
	*/
	SPAPI OSErr (*Make)(PIActionReference* reference);

	/**
	* Free a reference
	* @param ref The reference to free the memory for.
	* @returns Non-zero error if failure.
	*/
	SPAPI OSErr (*Free)(PIActionReference ref);

	/**
	* Gets the form of this reference.  Generally, when retrieving information from
	* a reference, the code uses \c GetForm, and uses the returned form to determine
	* which of the other \c Get routines to use.
	* The form identifiers are provided with each of the \c Get and \c Put routines.
	* @param ref The reference to read from.
	* @param value [OUT] The form for the reference, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetForm)(PIActionReference ref, DescriptorFormID* value);

	/**
	* Gets the class for the reference.
	* @param ref The reference to read from.
	* @param value [OUT] The class ID returned.  See PITerminology.h for predefined class.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetDesiredClass)(PIActionReference ref, DescriptorClassID* value);

	/**
	* Puts a name into a reference (\c formName) along with the desired class for the reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param cstrValue The name to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutName)(PIActionReference ref, DescriptorClassID desiredClass, const char* cstrValue);

	/**
	* Puts an index into a reference (\c formIndex) along with the desired class for the reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param value The index to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutIndex)(PIActionReference ref, DescriptorClassID desiredClass, uint32 value);

	/**
	* Puts an identifier into a reference (\c formIdentifier) along with the desired class for the reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param value The identifier to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutIdentifier)(PIActionReference ref, DescriptorClassID desiredClass, uint32 value);

	/**
	* Puts an offset into a reference (\c formOffset) along with the desired class for the reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param value The offset to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutOffset)(PIActionReference ref, DescriptorClassID desiredClass, int32 value);

	/**
	* Puts an enumeration type and enumeration ID  (\c formEnumerated)
	* into a reference along with the desired class for the reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param type The enumeration type to write.
	* @param value The enumeration ID to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutEnumerated)(PIActionReference ref, DescriptorClassID desiredClass, DescriptorEnumTypeID type, DescriptorEnumID value);

	/**
	* Puts a property into a reference (\c formProperty) along with the desired class for the reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param value The property key to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutProperty)(PIActionReference ref, DescriptorClassID desiredClass, DescriptorKeyID value);

	/**
	* Puts a class into a reference.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutClass)(PIActionReference ref, DescriptorClassID desiredClass);

	/**
	* Gets the length of a name from a reference. See @ref GetName for an example.
	* @param ref The reference from which to read.
	* @param strLength [OUT] The length of the name, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetNameLength)(PIActionReference ref, uint32* stringLength);

	/**
	* Gets a name from a reference (\c formName).
	* @param ref The reference from which to read.
	* @param name [OUT] The name, returned.
	* @param maxLength The maximum number of characters to read.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetName)(PIActionReference ref, char* name, uint32 maxLength);

	/**
	* Gets an index from a reference (\c formIndex).
	* @param ref The reference from which to read.
	* @param value [OUT] The index, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetIndex)(PIActionReference ref, uint32* value);

	/**
	* Gets an identifier from a reference (\c formIdentifier).
	* @param ref The reference from which to read.
	* @param value [OUT] The identifier, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetIdentifier)(PIActionReference ref, uint32* value);

	/**
	* Gets an offset from a reference (\c formOffset).
	* @param ref The reference from which to read.
	* @param value [OUT] The offset, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetOffset)(PIActionReference ref, int32* value);

	/**
	* Gets an enumeration type and enumeration id from a reference (\c formEnumerated).
	* @param ref The reference from which to read.
	* @param type [OUT] The enumeration type, returned.
	* @param enumValue [OUT] The enumeration ID, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetEnumerated)(PIActionReference ref, DescriptorEnumTypeID* type, DescriptorEnumID* enumValue);

	/**
	* Gets a property from a reference (\c formProperty).
	* @param ref The reference from which to read.
	* @param value [OUT] The property key, returned.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetProperty)(PIActionReference ref, DescriptorKeyID* value);

	/**
	* Gets a reference contained in this reference. Container references provide
	* additional pieces to the reference. This looks like another reference but is actually part
	* of the same reference.
	* @param ref The reference to get the container for.
	* @param value [OUT] A reference contained in \c ref. Is NULL if no container.
	* @returns Non-zero error on failure.
	*/
	SPAPI OSErr (*GetContainer)(PIActionReference ref, PIActionReference* value);

	/**
	* Puts a name into a reference (\c formName) along with the desired class for the reference using zstring.
	* @param ref The reference in which to write.
	* @param desiredClass The class for the reference.
	* @param zstring The name to write.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*PutNameZString)(PIActionReference ref, DescriptorClassID desiredClass, ASZString zstring);

	/**
	* Gets a name from a reference (\c formName) as a zstring
	* @param ref The reference from which to read.
	* @param zstring [OUT] The name, returned.
	* @param maxLength The maximum number of characters to read.
	* @returns Non-zero error in failure.
	*/
	SPAPI OSErr (*GetNameZString)(PIActionReference ref, ASZString* zstring);

	} PSActionReferenceProcs;
/**
@}
*/

/**
 * The set of routines available in the Action Reference Suite version 2. See above for documentation.
 */
typedef struct PSActionReferenceProcsOld
{
    SPAPI OSErr (*Make)(PIActionReference* reference);
    SPAPI OSErr (*Free)(PIActionReference ref);
    SPAPI OSErr (*GetForm)(PIActionReference ref, DescriptorFormID* value);
    SPAPI OSErr (*GetDesiredClass)(PIActionReference ref, DescriptorClassID* value);
    SPAPI OSErr (*PutName)(PIActionReference ref, DescriptorClassID desiredClass, const char* cstrValue);
    SPAPI OSErr (*PutIndex)(PIActionReference ref, DescriptorClassID desiredClass, uint32 value);
    SPAPI OSErr (*PutIdentifier)(PIActionReference ref, DescriptorClassID desiredClass, uint32 value);
    SPAPI OSErr (*PutOffset)(PIActionReference ref, DescriptorClassID desiredClass, int32 value);
    SPAPI OSErr (*PutEnumerated)(PIActionReference ref, DescriptorClassID desiredClass, DescriptorEnumTypeID type, DescriptorEnumID value);
    SPAPI OSErr (*PutProperty)(PIActionReference ref, DescriptorClassID desiredClass, DescriptorKeyID value);
    SPAPI OSErr (*PutClass)(PIActionReference ref, DescriptorClassID desiredClass);
    SPAPI OSErr (*GetNameLength)(PIActionReference ref, uint32* stringLength);
    SPAPI OSErr (*GetName)(PIActionReference ref, char* name, uint32 maxLength);
    SPAPI OSErr (*GetIndex)(PIActionReference ref, uint32* value);
    SPAPI OSErr (*GetIdentifier)(PIActionReference ref, uint32* value);
    SPAPI OSErr (*GetOffset)(PIActionReference ref, int32* value);
    SPAPI OSErr (*GetEnumerated)(PIActionReference ref, DescriptorEnumTypeID* type, DescriptorEnumID* enumValue);
    SPAPI OSErr (*GetProperty)(PIActionReference ref, DescriptorKeyID* value);
    SPAPI OSErr (*GetContainer)(PIActionReference ref, PIActionReference* value);
} PSActionReferenceProcsOld;
/**
 @}
 */

//-------------------------------------------------------------------------------
//	PIActionParameters structure.
//-------------------------------------------------------------------------------
#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

#if MSWindows
#pragma pack(push,1)
#endif

/**
* @ingroup AutomationModule
*/
/**
* Parameters passed to an automation plug-in through the message data.
* See \c PSActionsPlugInMessage.
*/
typedef struct PIActionParameters
	{

	PIDialogPlayOptions		playInfo;	/**< Flags for playback.
	                                         See @ref RecordPlayInfoFlags "flags for record and playback." */
	PIDialogRecordOptions	recordInfo;	/**< Flags for recording.
									         See @ref RecordPlayInfoFlags "flags for record and playback." */
	PIActionDescriptor		descriptor;	/**< The set of key/value pairs that provide the automation data
										     for the plug-in. */

	} PIActionParameters;


#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

#if MSWindows
#pragma pack(pop)
#endif

//-------------------------------------------------------------------------------

#endif // Rez

//-------------------------------------------------------------------------------

#endif // __PIActions_h__
