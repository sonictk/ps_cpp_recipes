// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2002 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
//-------------------------------------------------------------------------------
//
//	File:
//		PIUtilities.r
//
//
//	Description:
//		This rez file contains standard resources
//		to simplify the use of suites and also some
//		helpful common plug-in resources. 
//
//	Use:
//		PIUtilities is intended to group common resources
//		and functions into a simple library that provides
//		most of the basic plug-in functionality, including
//		error reporting and About boxes.
//
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//	Definitions -- Plug-in supplies.
//	Create generic definitions if not supplied by plug-in.
//-------------------------------------------------------------------------------

#ifndef plugInName
	#define plugInName	"Generic Plug-in"
#endif

#ifndef plugInCopyrightYear
	#define plugInCopyrightYear		"1990"
#endif

#ifndef plugInDescription
	#define plugInDescription		"An example plug-in module for Adobe Photoshop¨."
#endif

//-------------------------------------------------------------------------------
//	Defines -- Version information for SDK releases.
//-------------------------------------------------------------------------------

#ifndef VersionNumber
	#define VersionNumber	20
#endif

#ifndef VersionMinor
	#define VersionMinor    0
	#endif

#ifndef VersionDot
	#define VersionDot      0
#endif

#ifndef ComponentNumber
	#define ComponentNumber (VersionNumber << 16) | (VersionMinor << 8) | VersionDot
#endif

#ifndef VersionString
	#define VersionString 	"CC 2019"
#endif

#ifndef ReleaseString
	#define ReleaseString	"1 (10/2/2018)"
#endif

#ifndef CurrentYear
	#define CurrentYear		"2018"
#endif

//-------------------------------------------------------------------------------
//	Defines -- Generic resources, such as about boxes and resource IDs.
//	Redefine these if you need to.
//-------------------------------------------------------------------------------

#ifndef StringResource
	#define StringResource	'STR '
#endif

#ifndef ResourceID
	#define ResourceID		16000
#endif

#ifndef AboutID
	#define AboutID			ResourceID
#endif

#ifndef uiID
	#define uiID			ResourceID+1
#endif

#ifndef AlertID
	#define AlertID			16990
#endif

//-------------------------------------------------------------------------------
//	About string resource.  This is stored as text, instead of explicitly in
//	the About box definition, so that it can be used cross-platform.  Resources
//	of type 'STR ' (StringResource) are converted automatically by CNVTPIPL.
//-------------------------------------------------------------------------------

resource StringResource (AboutID, plugInName " About Text", purgeable)
{
	plugInName "\n\n"
	"Version " VersionString " "
	"Release " ReleaseString "\n"
	"© " plugInCopyrightYear "-" CurrentYear " Adobe. All rights reserved.\n"
	plugInDescription
};

//-------------------------------------------------------------------------------
//	Version 'vers' resource.
//-------------------------------------------------------------------------------

resource 'vers' (1, plugInName " Version", purgeable)
{
	VersionNumber, 0x00, final, 0, verUs,
	VersionString,
	VersionString "\u00A9 " plugInCopyrightYear "-" CurrentYear " Adobe. All Rights Reserved."
};

//-------------------------------------------------------------------------------
//
//	'FltD' resource.  Dynamic resource for Adobe Premiere.
//
//	Descriptor for allowing filters to animate over time. A
//	structure of this type can be added to a 'VFlt', an 'AFlt',
//	or a Photoshop filter to describe the data structure of its
//	data blob. Specify pdOpaque for any non-scalar data in the
//	record, or data that you don't want Premiere to interpolate
//	for you. Make the FltD describe all the bytes in the data
//	blob. Use ID 1000D
//
//-------------------------------------------------------------------------------

type 'FltD' {
	array {
		integer					// Specifies the type of the data
			pdOpaque = 0,			// Opaque - don't interpolate this
			pdChar = 1,				// Interpolate as signed byte
			pdShort = 2,			// Interpolate as signed short
			pdLong = 3,				// Interpolate as signed long
			pdUnsignedChar = 4,		// Interpolate as unsigned byte
			pdUnsignedShort = 5,	// Interpolate as unsigned short
			pdUnsignedLong = 6,		// Interpolate as unsigned long
			pdExtended = 7,			// Interpolate as an extended
			pdDouble = 8,			// Interpolate as a double
			pdFloat = 9;			// Interpolate as a float
		integer;				// Count of bytes to skip with pdOpaque, 0 otherwise.
	};
};

//-------------------------------------------------------------------------------

// end PIUtilities.r
