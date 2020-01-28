// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------------------
//
//	File:
//		PIMI.r
//
//	Copyright 1991-2000, Adobe Systems Incorporated.
//	All Rights Reserved.
//
//	Distribution:
//		PUBLIC
//
//	Description:
//		This file contains the public resource template
//		for the PiMI plug-in meta information.
//
//	Use:
//		This file must be included to correctly compile any
//		resource (.r) files with PiMI's defined in them.
//
//	Version history:
//		Version 1.0.0	10/9/1997	Ace		Separation from PIGeneral.r.
//			Rolled out of PIGeneral.r for compilation to make
//			PIPiPL.r inclusive of all other Adobe GAP products.
//
//-------------------------------------------------------------------------------

#ifndef __PIMI_r__		// Only include this once.
#define __PIMI_r__

//-------------------------------------------------------------------------------
//	Definitions -- Version and include information
//-------------------------------------------------------------------------------

// Version of Plug-in Meta Information template in this file:
#ifndef PiMIVersion
	#define PiMIVersion 0
#endif

//-------------------------------------------------------------------------------
//	Don't include this file on MSWindows
//-------------------------------------------------------------------------------

#define qIncludeMe 1

#ifdef MSWindows
	#undef qIncludeMe
	#define qIncludeMe !MSWindows
#endif

#if qIncludeMe // Not MSWindows

//-------------------------------------------------------------------------------
//	PiMI resource template
//-------------------------------------------------------------------------------

type 'PiMI'
{
Start:				/* The following is common to all Photoshop 2.5 Plugin modules	  */
	integer;						/* The version number of the interface supported. */
	integer;						/* The sub-version number.						  */
	integer;						/* The plug-in's priority.                        */
	integer = (General-Start)/8;	/* The size of the general info.				  */
	integer = (TypeInfo-General)/8;	/* The size of the type specific info.			  */
	integer;						/* A bit mask indicating supported image modes.   */
	literal longint;				/* A required host if any.						  */
General:

	array {			/* The following is used only for Format Plugin modules			  */
		integer = $$Countof(TypeArray);				/* type count */
		integer = $$Countof(ExtensionArray);		/* extension count */
		byte  cannotRead, canRead;					/* Can we read using this format?				  */
		byte  cannotReadAll, canReadAll;			/* Can this plug-in read from all files?		  */
		byte  cannotWrite, canWrite;				/* Can we write using this format?				  */
		byte  cannotWriteIfRead, canWriteIfRead;	/* Can we write if we read using this format?	  */
		byte  doesntSaveResources, savesResources;	/* Does this file format save the resource data?  */
		#if PiMIVersion > 0
		byte  doesntSupportsFilterCalls, supportsFilterCalls; /* Supports filter calls for formats. */
		#else
		fill byte;					/* Padding */
		#endif
		wide array [16]
			{ integer; };			/* Maximum # of channels with each plug-in mode.  */
		integer;					/* Maximum rows allowed in document.			  */
		integer;					/* Maximum columns allowed in document.			  */
		literal longint;			/* The file type if we create a file.			  */
		literal longint;			/* The creator type if we create a file.		  */
		array TypeArray
		{
			literal longint;		/* The type-creator pairs supported.			  */
			literal longint;
		};
		array ExtensionArray
		{
			literal longint;		/* The extensions supported.					  */
		};
	};
	TypeInfo:
};

#ifdef EXAMPLE_CODE_BELOW

/* Example of Format plugin resource */

resource 'PiMI' (16000, purgeable)
{
	latestFormatVersion, 	/* Version, subVersion, and priority of the interface */
	latestFormatSubVersion,
	0,
	supportsGrayScale+supportsRGBColor+supportsCMYKColor,
	'8BIM',
	
	{
		canRead,
		cannotReadAll,
		canWrite,
		canWriteIfRead,
		doesntSaveResources,
		{ 0, 1, 0, 3,
		  4, 0, 0, 0,
		  0, 0, 0, 0,
		  0, 0, 0, 0 },
		32767,
		32767,
		'JPEG',
		'8BIM',
		{
			'JPEG', '8BIM'
		},
		{
			'JPG '
		}
	}
};

/* Example of Acquire/Export resource */

resource 'PiMI' (16001, purgeable)
{
	latestAcquireVersion, 	/* Version, subVersion, and priority of the interface */ 
	latestAcquireSubVersion, 
	0,
	supportsGrayScale+supportsRGBColor+supportsCMYKColor,
	'8BIM',
	{}			/* Null Format extension field */
};

#endif // Examples

//-------------------------------------------------------------------------------

#endif // qIncludeMe
#endif // __PIMI_r__
