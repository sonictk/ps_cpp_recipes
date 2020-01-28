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
//		PiPL.r
//
//	Copyright 1991-1998, Adobe Systems Incorporated.
//	All Rights Reserved.
//
//	Distribution:
//		PUBLIC
//
//	Description:
//		This file contains the public resource templates
//		for all PiPL types for all graphic and dynamic
//		media products.
//
//	Use:
//		This file must be included to correctly compile any
//		resource (.r) files with PiPLs defined in them.
//
//	Version history:
//		Version 1.0.0	10/9/1997	Cnvtpipl 3.0.1		Ace		Initial compilation.
//			Compiled for Photoshop, After Effects, Premiere, Illustrator.
//
//		Version 1.0.1	3/9/1998	Cnvtpipl 3.0.37		Ace		Premiere/PICA updates.
//			PrImporter, PrCompile, PrRecord, PrPlay, AdapterVersion, InternalName.
//
//-------------------------------------------------------------------------------

#ifndef __PIPL_r__		// Only include this once.
#define __PIPL_r__

//-------------------------------------------------------------------------------
//	Definitions -- Version and include information
//-------------------------------------------------------------------------------

// Version of Plug In Properties Template described in this file:
#ifndef kPIPropertiesVersion
	#define kPIPropertiesVersion 0
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
//	Temporarily define PiPL types for all references:
//-------------------------------------------------------------------------------

#define PIPiPLTypes								\
	/* Photoshop plug-in types: */				\
	General = '8BPI',							\
	Filter = '8BFM',							\
	Parser = '8BYM',							\
	ImageFormat='8BIF',							\
	Extension = '8BXM',							\
	Acquire = '8BAM',							\
	Export = '8BEM',							\
	Selection = '8BSM',							\
	Picker = '8BCM',							\
	Actions = '8LIZ',							\
	Measurement = '8MEA',						\
	MSPUtility = '8SPU'							\
	/* After Effects plug-in types: */			\
	AEEffect = 'eFKT', 							\
	AEImageFormat = 'FXIF', 					\
	AEAccelerator = 'eFST', 					\
	AEGeneral = 'AEgp',							\
	/* Premiere plug-in types: */				\
	PrEffect = 'SPFX', 							\
	PrVideoFilter = 'VFlt', 					\
	PrAudioFilter = 'AFlt', 					\
	PrEDLExport = 'ExpM', 						\
	PrDataExport = 'ExpD', 						\
	PrDevice = 'DevC', 							\
	PrImporter = 'IMPT'							\
	PrCompile = 'CMPM',							\
	PrRecord = 'RECM',							\
	PrPlay = 'PLYM',							\
	/* Illustrator/SweetPea plug-in types: */	\
	SweetPea = 'SPEA'							\
	AIGeneral = 'ARPI'

//-------------------------------------------------------------------------------
//	PiPL resource template
//-------------------------------------------------------------------------------

type 'PiPL'
	{
	longint = kPIPropertiesVersion;
	longint = $$CountOf(properties);
	array properties
		{
		switch
			{


			//-------------------------------------------------------------------
			// General PiPL properties
			//-------------------------------------------------------------------
			case Kind:
				longint = '8BIM';
				key longint = 'kind';
				longint = 0;
				longint = 4;
				literal longint PIPiPLTypes;

			case Version:
				longint = '8BIM';
				key longint = 'vers';
				longint = 0;
				longint = 4;
				longint;

			case Priority:
				longint = '8BIM';
				key longint = 'prty';
				longint = 0;
				longint = 4;
				longint;

			case Component:
				longint = '8BIM';
				key longint = 'cmpt';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (componentEnd[$$ArrayIndex(properties)] - componentStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  componentStart:
				longint;				// Version.
				cstring;				// UUID.
			  componentEnd:
			  	align long;
			  	
			case RequiredHost:
				longint = '8BIM';
				key longint = 'host';
				longint = 0;
				longint = 4;
				literal longint;

			case Name:
				longint = '8BIM';
				key longint = 'name';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (nameEnd[$$ArrayIndex(properties)] - nameStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  nameStart:
				pstring;
			  nameEnd:
				align long;

			case ZStringName:
				longint = '8BIM';
				key longint = 'znam';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (ZNameEnd[$$ArrayIndex(properties)] - ZNameStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  ZNameStart:
				pstring;
			  ZNameEnd:
				align long;

			case Category:
				longint = '8BIM';
				key longint = 'catg';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (catgEnd[$$ArrayIndex(properties)] - catgStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  catgStart:
				pstring
					// Use Help category to put automation plug-ins in the "Help" menu:
					PSHelpMenu = "**Help**",
					
					// Use Hidden category to keep plug-ins out of menus.
					// WARNING: The only way to access a hidden plug-in is
					// by calling it by its event ID from the Play callback!
					PSHidden = "**Hidden**",
					
					// Use Copyright-Checker category to detect copyrights on first-opened files:
					PSCopyrightChecker = "**Copyright-Checker**",
					
					// Use PSPaletteMenu category to add a menu item on the Window (i.e., palette) menu.
					//	This is currently only enabled for automation plugins.
					PSPaletteMenu ="**Palette**";
					
			  catgEnd:
				align long;

			case ZStringCategory:
				longint = '8BIM';
				key longint = 'zcat';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (ZCatgEnd[$$ArrayIndex(properties)] - ZCatgStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  ZCatgStart:
				pstring
					// Use Help category to put automation plug-ins in the "Help" menu:
					PSHelpMenu = "$$$/AdobePlugin/PIPLInfo/Category/PSHelpMenu=**Help**",
					
					// Use Hidden category to keep plug-ins out of menus.
					// WARNING: The only way to access a hidden plug-in is
					// by calling it by its event ID from the Play callback!
					PSHidden = "$$$/AdobePlugin/PIPLInfo/Category/PSHiddenMenu=**Hidden**",
					
					// Use Copyright-Checker category to detect copyrights on first-opened files:
					PSCopyrightChecker = "$$$/AdobePlugin/PIPLInfo/Category/PSCopyrightChecker=**Copyright-Checker**",
					
					// Use PSPaletteMenu category to add a menu item on the Window (i.e., palette) menu.
					//	This is currently only enabled for automation plugins.
					PSPaletteMenu ="$$$/AdobePlugin/PIPLInfo/Category/PSPaletteMenu=**Panel**";
					
			  ZCatgEnd:
				align long;

			case ProgressText:
				longint = '8BIM';
				key longint = 'prog';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (progEnd[$$ArrayIndex(properties)] - progStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  progStart:
				pstring
					// Progress bar suppression
					PSPlugInHandlesProgess = "**No-Progress**";
			  progEnd:
				align long;

			case ZStringProgressText:
				longint = '8BIM';
				key longint = 'zpro';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (ZProgEnd[$$ArrayIndex(properties)] - ZProgStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  ZProgStart:
				pstring
					// Progress bar suppression
					PSPlugInHandlesProgess = "$$$/AdobePlugin/PIPLInfo/Progress/NoProgress=**No-Progress**";
			  ZProgEnd:
				align long;

			// May no longer be supported in current versions, but kept
			// for backwards and PUBLIC compatibility:
			case Code68k:
				longint = '8BIM';
				key longint = 'm68k';
				longint = 0;
				longint = 6;
				literal longint PIPiPLTypes;
				integer;
				align long;

			case Code68kFPU:
				longint = '8BIM';
				key longint = '68fp';
				longint = 0;
				longint = 6;
				literal longint PIPiPLTypes;
				integer;
				align long;

			case CodePowerPC:
				longint = '8BIM';
				key longint = 'pwpc';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (pwpcEnd[$$ArrayIndex(properties)] - pwpcStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  pwpcStart:
				longint;
				longint;
				pstring;
			  pwpcEnd:
				align long;

			case CodeCarbonPowerPC:
				longint = '8BIM';
				key longint = 'ppcb';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (pwpcCarbonEnd[$$ArrayIndex(properties)] - pwpcCarbonStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  pwpcCarbonStart:
				longint;
				longint;
				pstring;
			  pwpcCarbonEnd:
				align long;

			// Mach-O Support
			case CodeMachOPowerPC:
				longint = '8BIM';
				key longint = 'mach';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (pwpcMachEnd[$$ArrayIndex(properties)] - pwpcMachStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  pwpcMachStart:
				longint;
				longint;
				pstring;
			  pwpcMachEnd:
				align long;

			// Mach-O Intel 32bit Support
			case CodeMacIntel32:
				longint = '8BIM';
				key longint = 'mi32';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (pwpcMacIntel32End[$$ArrayIndex(properties)] - pwpcMacIntel32Start[$$ArrayIndex(properties)]) / 8;
				#endif
			  pwpcMacIntel32Start:
				pstring;
			  pwpcMacIntel32End:
				align long;

			// Mach-O Intel 64bit Support
			case CodeMacIntel64:
				longint = '8BIM';
				key longint = 'mi64';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (pwpcMacIntel64End[$$ArrayIndex(properties)] - pwpcMacIntel64Start[$$ArrayIndex(properties)]) / 8;
				#endif
			  pwpcMacIntel64Start:
				pstring;
			  pwpcMacIntel64End:
				align long;

			// If this property is present, then its on.  No parameters
			// are required:
			case Cocoa:
				longint = '8BIM';
				key longint = 'coco';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			// new code fragment ('cfrg') based code pointer
			case CodeFragmentPPC:
				longint = '8BIM';
				key longint = 'frag';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (fragEnd[$$ArrayIndex(properties)] - fragStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  fragStart:
				longint;	// resource ID
				longint;	// fragment # (starting at 1)
				pstring;	// entrypoint name
			  fragEnd:
				align long;

			// new code fragment ('cfrg') based code pointer
			case CodeFragmentCarbonPPC:
				longint = '8BIM';
				key longint = 'frgc';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (fragCarbonEnd[$$ArrayIndex(properties)] - fragCarbonStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  fragCarbonStart:
				longint;	// resource ID
				longint;	// fragment # (starting at 1)
				pstring;	// entrypoint name
			  fragCarbonEnd:
				align long;

			// For documentation purposes, here's the Windows
			// code resource template:
			#ifdef MSWindows
				case CodeWin32X86:
					longint = '8BIM';
					key longint = 'wx86';
					longint = 0;
					longint = (win32x86End[$$ArrayIndex(properties)] - win32x86Start[$$ArrayIndex(properties)]) / 8;
				  win32x86Start:
					cstring;
				  win32x86End:
					align long;
			#endif

			case SupportedModes:
				longint = '8BIM';
				key longint = 'mode';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (modeEnd[$$ArrayIndex(properties)] - modeStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  modeStart:
				boolean noBitmap, doesSupportBitmap;
				boolean noGrayScale, doesSupportGrayScale;
				boolean noIndexedColor, doesSupportIndexedColor;
				boolean noRGBColor, doesSupportRGBColor;
				boolean noCMYKColor, doesSupportCMYKColor;
				boolean noHSLColor, doesSupportHSLColor;
				boolean noHSBColor, doesSupportHSBColor;
				boolean noMultichannel, doesSupportMultichannel;
				boolean noDuotone, doesSupportDuotone;
				boolean noLABColor, doesSupportLABColor;
				fill bit[6];
			  modeEnd:
				align long;

			case EnableInfo:
				longint = '8BIM';
				key longint = 'enbl';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (EnableInfoEnd[$$ArrayIndex(properties)] - EnableInfoStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  EnableInfoStart:
				cstring;
			  EnableInfoEnd:
				align long;

			// If this property is present, then its on.  No parameters
			// are required:
			case WantsScrap:
				longint = '8BIM';
				key longint = 'wnsc';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			// If this property is present, then its on.  No parameters
			// are required:
			case FileBrowserAware:
				longint = '8BIM';
				key longint = 'fbaw';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on. No parameters
			// are required:
			case NoAboutBox:
				longint = '8BIM';
				key longint = 'nabo';
				longint = 0;	// Index.
				longint = 4;	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on. No parameters
			// are required:
			case LegacyFilterGalleryMenuItem:
				longint = '8BIM';
				key longint = 'lFGm';
				longint = 0;	// Index.
				longint = 4;	// Length.
				literal longint = 1;	// If specified, always on.

			case PlugInMaxSize:
				longint = '8BIM';
				key longint = 'ms32';
				longint = 0;
				longint = 8;
				longint; // maximum height
				longint; // maximum width

			case PlugInMinSize:
				longint = '8BIM';
				key longint = 'mn32';
				longint = 0;
				longint = 8;
				longint; // maximum height
				longint; // maximum width

			// If this property is present, then its on.  No parameters
			// are required:
			case FilterLayerSupport:
				longint = '8BIM';
				key longint = 'flly';
				longint = 0;	// Index.
				#if DeRez
					fill long;
				#else
					longint = (filterLayerSupportEnd[$$ArrayIndex(properties)] - filterLayerSupportStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  filterLayerSupportStart:
				boolean noFilterLayers, doesSupportFilterLayers;
				fill bit[7];
			  filterLayerSupportEnd:
				align long;

			// If this property is present, then its on.  No parameters
			// are required:
			case LoadUnload:
				longint = '8BIM';
				key longint = 'piLU';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case Preferences:
				longint = '8BIM';
				key longint = 'piPF';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			case FeatureEnabled:
				longint = '8BIM';
				key longint = 'feen';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (featureEnabledEnd[$$ArrayIndex(properties)] - featureEnabledStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  featureEnabledStart:
				pstring;
			  featureEnabledEnd:
				align long;

			//-------------------------------------------------------------------
			// Photoshop Filter PiPL properties
			//-------------------------------------------------------------------
			case FilterCaseInfo:
				longint = '8BIM';
				key longint = 'fici';
				longint = 0;
				longint = 28;
				array [7]
					{
					byte inCantFilter = 0,
						 inStraightData = 1,
						 inBlackMat = 2,
						 inGrayMat = 3,
						 inWhiteMat = 4,
						 inDefringe = 5,
						 inBlackZap = 6,
						 inGrayZap = 7,
						 inWhiteZap = 8,
						 inBackgroundZap = 10,
						 inForegroundZap = 11;
					byte outCantFilter = 0,
						 outStraightData = 1,
						 outBlackMat = 2,
						 outGrayMat = 3,
						 outWhiteMat = 4,
						 outFillMask = 9;
					fill bit [4];
					boolean doNotWriteOutsideSelection, writeOutsideSelection;
					boolean doesNotFilterLayerMasks, filtersLayerMasks;
					boolean doesNotWorkWithBlankData, worksWithBlankData;
					boolean copySourceToDestination, doNotCopySourceToDestination;
					fill byte;
					};

			//-------------------------------------------------------------------
			// Photoshop Export PiPL properties
			//-------------------------------------------------------------------
			case ExportFlags:
				longint = '8BIM';
				key longint = 'expf';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (expFlagsEnd[$$ArrayIndex(properties)] - expFlagsStart[$$ArrayIndex(properties)]) / 8;
				#endif
			 expFlagsStart:
				boolean expDoesNotSupportTransparency, expSupportsTransparency;
				fill bit[7];
			  expFlagsEnd:
				align long;

			//-------------------------------------------------------------------
			// Photoshop File Format PiPL properties
			//-------------------------------------------------------------------
			case FmtFileType:
				longint = '8BIM';
				key longint = 'fmTC';
				longint = 0;
				longint = 8;
				literal longint; // Default file type.
				literal longint; // Default file creator.

			// NOTE: If you specify you can READ type 'foo_', then you
			// will never be called with a FilterFile for type 'foo_'.
			case ReadTypes:
				longint = '8BIM';
				key longint = 'RdTy';
				longint = 0;
				longint = $$CountOf(ReadableTypes) * 8;
				wide array ReadableTypes { literal longint; literal longint; } ;

			case WriteTypes:
				longint = '8BIM';
				key longint = 'WrTy';
				longint = 0;
				longint = $$CountOf(WritableTypes) * 8;
				wide array WritableTypes { literal longint; literal longint; } ;

			// NOTE: If you specify you want to filter type 'foo_' AND you
			// specify you can read type 'foo_', you will never get
			// a filter call.
			case FilteredTypes:
				longint = '8BIM';
				key longint = 'fftT';
				longint = 0;
				longint = $$CountOf(FilteredTypes) * 8;
				wide array FilteredTypes { literal longint; literal longint; } ;

			// Macintosh plug-ins can use Windows file extensions
			// to determine read/write/parseability.
			//
			// NOTE: If you specify you READ extension '.foo' then you
			// won't be called to Filter that type.
			case ReadExtensions:
				longint = '8BIM';
				key longint = 'RdEx';
				longint = 0;
				longint = $$CountOf(ReadableExtensions) * 4;
				wide array ReadableExtensions { literal longint; } ;

			case WriteExtensions:
				longint = '8BIM';
				key longint = 'WrEx';
				longint = 0;
				longint = $$CountOf(WriteableExtensions) * 4;
				wide array WriteableExtensions { literal longint; } ;

			// NOTE: If you specify you want to filter extension '.foo'
			// AND you specify you can read extension '.foo', you will
			// never get a filter call.
			case FilteredExtensions:
				longint = '8BIM';
				key longint = 'fftE';
				longint = 0;
				longint = $$CountOf(FilteredExtensions) * 4;
				wide array FilteredExtensions { literal longint; } ;

			case FormatFlags:
				longint = '8BIM';
				key longint = 'fmtf';
				longint = 0;
				longint = (fmtFlagsEnd[$$ArrayIndex(properties)] - fmtFlagsStart[$$ArrayIndex(properties)]) / 8;
			 fmtFlagsStart:
				boolean = false; // Obsolete.
				boolean fmtDoesNotSaveImageResources, fmtSavesImageResources;
				boolean fmtCannotRead, fmtCanRead;
				boolean fmtCannotWrite, fmtCanWrite;
				boolean fmtWritesAll, fmtCanWriteIfRead;
				boolean fmtCannotWriteTransparency, fmtCanWriteTransparency;
				boolean fmtCannotCreateThumbnail, fmtCanCreateThumbnail;
				fill bit[1];
			  fmtFlagsEnd:
				align long;

			case FormatMaxSize:
				longint = '8BIM';
				key longint = 'mxsz';
				longint = 0;
				longint = 4;
				Point;

			case FormatFileSizeLimit:
				longint = '8BIM';
				key longint = 'fslm';
				longint = 0;
				longint = 4;
				longint;

			case FormatMaxChannels:
				longint = '8BIM';
				key longint = 'mxch';
				longint = 0;
				longint = $$CountOf(ChannelsSupported) * 2;
				wide array ChannelsSupported { integer; } ;
				align long;

			case FormatHiddenFlags:
				longint = '8BIM';
				key longint = 'fmhi';
				longint = 0;
				longint = (hiddenFlagsEnd[$$ArrayIndex(properties)] - hiddenFlagsStart[$$ArrayIndex(properties)]) / 8;
			  hiddenFlagsStart:
				boolean formatShowRead, formatReadHidden;
				boolean formatShowWrite, formatWriteHidden;
				fill bit[6];
			  hiddenFlagsEnd:
				align long;

			case FormatICCFlags:
				longint = '8BIM';
				key longint = 'fmip';
				longint = 0;
				longint = (iccFlagsEnd[$$ArrayIndex(properties)] - iccFlagsStart[$$ArrayIndex(properties)]) / 8;
			  iccFlagsStart:
				boolean iccCannotEmbedGray   , iccCanEmbedGray;
				boolean iccCannotEmbedIndexed, iccCanEmbedIndexed;
				boolean iccCannotEmbedRGB    , iccCanEmbedRGB;
				boolean iccCannotEmbedCMYK   , iccCanEmbedCMYK;
				fill bit[4];
			  iccFlagsEnd:
				align long;

			case FormatICCRequiredFlags:
				longint = '8BIM';
				key longint = 'fmir';
				longint = 0;
				longint = (iccRequiredFlagsEnd[$$ArrayIndex(properties)] - iccRequiredFlagsStart[$$ArrayIndex(properties)]) / 8;
			  iccRequiredFlagsStart:
				boolean iccGrayOptional   , iccGrayRequired;
				boolean iccIndexedOptional, iccIndexedRequired;
				boolean iccRGBOptional    , iccRGBRequired;
				boolean iccCMYKOptional   , iccCMYKRequired;
				fill bit[4];
			  iccRequiredFlagsEnd:
				align long;

			// If this property is present, then its on.  No parameters
			// are required:
			case FileProperties:
				longint = '8BIM';
				key longint = 'ffps';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case LosslessRotate:
				longint = '8BIM';
				key longint = 'fllr';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			// If this property is present, then its on.  No parameters
			// are required:
			case BulkSettings:
				longint = '8BIM';
				key longint = 'ffbs';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case PrimaryMetadataSource:
				longint = '8BIM';
				key longint = 'ffpm';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case PrimaryThumbnailSource:
				longint = '8BIM';
				key longint = 'ffpt';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case XMPRead:
				longint = '8BIM';
				key longint = 'xmpr';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			// If this property is present, then its on.  No parameters
			// are required:
			case XMPWrite:
				longint = '8BIM';
				key longint = 'xmpw';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case QuickExtractThumbnail:
				longint = '8BIM';
				key longint = 'qthm';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			// If this property is present, then its on.  No parameters
			// are required:
			case BulkOpen:
				longint = '8BIM';
				key longint = 'ffbo';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case RawSettings:
				longint = '8BIM';
				key longint = 'rscp';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case OpenWriteAccess:
				longint = '8BIM';
				key longint = 'fowa';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case WarnIfOverridden:
				longint = '8BIM';
				key longint = 'fwio';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case ResourceThreadSafe:
				longint = '8BIM';
				key longint = 'frts';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case SupportsBackgroundSave:
				longint = '8BIM';
				key longint = 'fbgs';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
				
			// If this property is present, then its on.  No parameters
			// are required:
			case SupportsPOSIXIO:
				longint = '8BIM';
				key longint = 'fxio';
				longint = 0;    // Index.
				longint = 4;    // Length.
				literal longint = 1;    // If specified, always on.
				
			//-------------------------------------------------------------------
			// Photoshop Parser PiPL properties
			//-------------------------------------------------------------------
			// NOTE: If you specify you want to filter type 'foo_' and you
			// specify you can parse type 'foo_', you will never get a
			// filter call.
			case ParsableTypes:
				longint = '8BIM';
				key longint = 'psTY';
				longint = 0;
				longint = $$CountOf(ParsableTypes) * 8;
				wide array ParsableTypes { literal longint; literal longint; } ;

			case ParsableClipboardTypes:
				longint = '8BIM';
				key longint = 'psCB';
				longint = 0;
				longint = $$CountOf(ParsableClipboardTypes) * 4;
				wide array ParsableClipboardTypes { literal longint; };

			// NOTE: If you want to filter type 'foo_' and you specify you
			// can parse type 'foo_', you will never get a filter call.
			case FilteredParsableTypes:
				longint = '8BIM';
				key longint = 'psTy';
				longint = 0;
				longint = $$CountOf(ParsableTypes) * 8;
				wide array ParsableTypes { literal longint; literal longint; } ;


			// Macintosh plug-ins can use Windows file extensions
			// to determine read/write/parseability.
			//
			// NOTE: If you want to filter extension '.foo' and you
			// specify you can parse extension '.foo', you will
			// never get a filter call.
			case ParsableExtensions:
				longint = '8BIM';
				key longint = 'psEX';
				longint = 0;
				longint = $$CountOf(ParsableExtensions) * 4;
				wide array ParsableExtensions { literal longint; };

			case FilteredParsableExtensions:
				longint = '8BIM';
				key longint = 'psEx';
				longint = 0;
				longint = $$CountOf(ParsableExtensions) * 4;
				wide array ParsableExtensions { literal longint; };

			//-------------------------------------------------------------------
			// Photoshop Parser PiPL properties
			//-------------------------------------------------------------------
			case PickerID:
				longint = '8BIM';
				key longint = 'pnme';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (PickerIDEnd[$$ArrayIndex(properties)] - PickerIDStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  PickerIDStart:
				pstring;			// Unique ID string.
			  PickerIDEnd:
				align long;

			//-------------------------------------------------------------------
			// Photoshop Actions/Scripting PiPL properties
			// (Photoshop 4.0 and later)
			//-------------------------------------------------------------------
			case HasTerminology:
				longint = '8BIM';
				key longint = 'hstm';
				longint = 0;
				longint = (hasTermEnd[$$ArrayIndex(properties)] - hasTermStart[$$ArrayIndex(properties)]) / 8;
			hasTermStart:
				longint = 0;	// Version.
				longint;		// Class ID, always required.  Can be Suite ID.
				longint;		// Event ID, or typeNULL if not Filter/Color Picker/Selection.
				integer;		// Dictionary ('AETE') resource ID.
				cstring;		// Unique scope string.  Always required in Photoshop 5.0 and later.
			hasTermEnd:
				align long;

			// If this property is present, then its on.  No parameters
			// are required:
			case Persistent:
				longint = '8BIM';
				key longint = 'prst';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			// If this property is present, then its on.  No parameters
			// are required:
			case Reentrant:
				longint = '8BIM';
				key longint = 'reen';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

            // The following property is used only on Windows.
            // When on, the plug-in loader will load the plug-in dll using the
            // alteres search path.
			// If this property is present, then its on.  No parameters
			// are required:
			case LoadWithAlteredSearchPath:
				longint = '8BIM';
				key longint = 'adll';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.

			//-------------------------------------------------------------------
			// After Effects and Premiere specific PiPL properties
			//-------------------------------------------------------------------
			case AE_PiPL_Version:
				longint = '8BIM';
				key longint = 'ePVR';
				longint = 0;
				longint = 4;
				integer;		// Minor version. *NOTE: May have these reversed.
				integer;		// Major version.
				
			case AE_Effect_Spec_Version:
				longint = '8BIM';
				key longint = 'eSVR';
				longint = 0;
				longint = 4;
				integer;		// Minor version. *NOTE: May have these reversed.
				integer;		// Major version.

			case AE_Effect_Version:
				longint = '8BIM';
				key longint = 'eVER';
				longint = 0;
				longint = 4;
				longint;
				
			case AE_Effect_Match_Name:
				longint = '8BIM';
				key longint = 'eMNA';
				longint = 0;
				#if DeRez
					fill long;
				#else
					longint = (matchNameEnd[$$ArrayIndex(properties)] - matchNameStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  matchNameStart:
				pstring;
			  matchNameEnd:
				align long;

			//-------------------------------------------------------------------
			// After Effects effects PiPL properties
			//-------------------------------------------------------------------
			case AE_Effect_Info_Flags:
				longint = '8BIM';
				key longint = 'eINF';
				longint = 0;
				longint = 4; 	// NOTE CHANGE: Was 2, but everything must be 4 byte aligned.
				// integer;		// Was defined this way.
				// align long;	// Was defined this way.
				longint;		// This is consistent with Windows resource.

			case AE_Effect_Global_OutFlags:
				longint = '8BIM';
				key longint = 'eGLO';
				longint = 0;	// Index.
				longint = 4;	// Length.
				fill bit[6];	// Reserved.
				boolean=0; // PF_OutFlag_RESERVED4
				boolean=0; // PF_OutFlag_RESERVED3
				boolean=0; // PF_OutFlag_RESERVED2
				boolean=0; // PF_OutFlag_RESERVED1
				boolean notObsolete, obsolete; 							// PF_OutFlag_I_AM_OBSOLETE
				boolean dontUseAudio, useAudio; 						// PF_OutFlag_I_USE_AUDIO
				boolean dontUseShutterAngle, useShutterAngle;			// PF_OutFlag_I_USE_SHUTTER_ANGLE
				boolean noFrameNopRender, useFrameNopRender;			// PF_OutFlag_NOP_RENDER (frame)
				boolean noRefreshUIEvent, useRefreshUIEvent;			// PF_OutFlag_REFRESH_UI (event)
				boolean noCustomNTRP, haveCustomNTRP;					// PF_OutFlag_CUSTOM_NTRP
				boolean noCustomUI, haveCustomUI;						// PF_OutFlag_CUSTOM_UI
				boolean nonSquarePixOk, squarePixOnly;					// PF_OutFlag_SQUARE_PIX_ONLY
				boolean dontWorkInPlace, workInPlace;					// PF_OutFlag_WORKS_IN_PLACE
				boolean doesntShrinkBuffer, shrinksBuffer;				// PF_OutFlag_I_SHRINK_BUFFER
				boolean doesntWriteInputBuffer, writesInputBuffer;		// PF_OutFlag_I_WRITE_INPUT_BUFFER
				boolean pixDependent, pixIndependent;					// PF_OutFlag_PIX_INDEPENDENT
				boolean doesntExpandBuffer, expandsBuffer;				// PF_OutFlag_I_EXPAND_BUFFER
				boolean dontDisplayErrorMessage, displayErrorMessage;	// PF_OutFlag_DISPLAY_ERROR_MESSAGE
				boolean dontSendDoDialog, sendDoDialog;					// PF_OutFlag_SEND_DO_DIALOG (sequence)
				boolean dontUseOutputExtent, useOutputExtent;			// PF_OutFlag_USE_OUTPUT_EXTENT
				boolean doesntDoDialog, doesDialog;						// PF_OutFlag_I_DO_DIALOG
				boolean dontFlattenSequenceData, flattenSequenceData;	// PF_OutFlag_SEQUENCE_DATA_NEEDS_FLATTENING
				boolean dontSendParamsUpdate, sendParamsUpdate;			// PF_OutFlag_SEND_PARAMS_UPDATE
				boolean noNonParamVary, nonParamVary;					// PF_OutFlag_NON_PARAM_VARY
				boolean noWideTimeInput, wideTimeInput;					// PF_OutFlag_WIDE_TIME_INPUT
				boolean dontKeepResourceOpen, keepResourceOpen;			// PF_OutFlag_KEEP_RESOURCE_OPEN

			case AE_Reserved:
				longint = '8BIM';
				key longint = 'aeRD';
				longint = 0;
				longint = 4;
				longint;

			case AE_Reserved_Info:
				longint = '8BIM';
				key longint = 'aeFL';
				longint = 0;
				longint = 4;
				longint;

			//-------------------------------------------------------------------
			// After Effects Image Format Extension PiPL properties
			//-------------------------------------------------------------------
			case AE_ImageFormat_Extension_Info:
				longint = '8BIM';
				key longint = 'FXMF';
				longint = 0;
				longint = 16;
				integer;		// Major version.
				integer;		// Minor version.
				fill bit[21];
				boolean hasOptions, hasNoOptions;
				boolean sequentialOnly, nonSequentialOk;
				boolean noInteractRequired, mustInteract;
				boolean noInteractPut, hasInteractPut;
				boolean noInteractGet, hasInteractGet;
				boolean hasTime, hasNoTime;
				boolean noVideo, hasVideo;
				boolean noStill, still;
				boolean noFile, hasFile;
				boolean noOutput, output;
				boolean noInput, input;

				longint = 0;		// Reserved.
				literal longint;	// Signature.

			//-------------------------------------------------------------------
			// After Effects and Premiere ANIM PiPL properties
			//-------------------------------------------------------------------
			case ANIM_FilterInfo:
				longint = '8BIM';
				key longint = 'aFLT';
				longint = 0;	// Index.
				#if DeRez
					fill long;
				#else
					longint = (animFilterEnd[$$ArrayIndex(properties)] - animFilterStart[$$ArrayIndex(properties)]) / 8;
				#endif

			  animFilterStart:
			  	longint=1;		// spec_version_major (AE & PrMr)
			  	longint=1;		// spec_version_minor (AE & PrMr)
			  	longint;		// filter_params_version (AE only)

				fill bit[19];
				boolean reserved1False, reserved1True; 		// ANIM_FF_RESERVED1 (AE only)
				boolean reserved0False, reserved0True; 		// ANIM_FF_RESERVED0 (AE only)
				boolean driveMe, dontDriveMe; 				// ANIM_FF_DONT_DRIVE_ME (AE only)
				boolean needsDialog, doesntNeedDialog;		// ANIM_FF_DOESNT_NEED_DLOG (AE only)
				boolean paramsNotPointer, paramsPointer;	// ANIM_FF_PARAMS_ARE PTR (AE only)
				boolean paramsNotHandle, paramsHandle;		// ANIM_FF_PARAMS_ARE_HANDLE (AE only)
				boolean paramsNotMacHandle,paramsMacHandle;	// ANIM_FF_PARAMS_ARE_MAC_HANDLE (AE only)
				boolean dialogNotInRender, dialogInRender;	// ANIM_FF_DIALOG_IN_RENDER (AE only)
				boolean paramsNotInGlobals,paramsInGlobals;	// ANIM_FF_PARAMS_IN_GLOBALS (AE only)
				boolean bgNotAnimatable, bgAnimatable;		// ANIM_FF_BG_ANIMATABLE (AE only)
				boolean fgNotAnimatable, fgAnimatable;		// ANIM_FF_FG_ANIMATABLE (AE only)
				boolean geometric, notGeometric;			// ANIM_FF_NON_GEOMETRIC (AE only)
				boolean noRandomness, randomness;			// ANIM_FF_HAS_RANDOMNESS (AE only)

				longint;		// number of parameters

				cstring[32];	// match name

			  	longint=0;		// Operates in place - not currently implemented
			  	longint=0;		// reserved
			  	longint=0;		// reserved
			  	longint=0;		// reserved
			  animFilterEnd:

			case ANIM_ParamAtom:
				longint = '8BIM';
				key longint = 'aPAR';
				longint;		// property id *NOTE: Breaks model -- MUST SPECIFY.
				#if DeRez
					fill long;
				#else
					longint = (animParamEnd[$$ArrayIndex(properties)] - animParamStart[$$ArrayIndex(properties)]) / 8;
				#endif

			  animParamStart:
				cstring[32];					// external name

			  	longint;						// match id
			  	
			  	longint ANIM_DT_OPAQUE, 		// obsolete, don't use OPAQUE with Premiere
			  			ANIM_DT_CHAR,
						ANIM_DT_SHORT,
						ANIM_DT_LONG,
						ANIM_DT_UNSIGNED_CHAR,
						ANIM_DT_UNSIGNED_SHORT,
						ANIM_DT_UNSIGNED_LONG,
						ANIM_DT_FIXED,
						ANIM_DT_UNSIGNED_FIXED,
						ANIM_DT_EXTENDED_96,
						ANIM_DT_DOUBLE_64,
						ANIM_DT_FLOAT_32,
						ANIM_DT_COLOR_RGB;

			  	longint ANIM_UI_NO_UI,			// UI types are only used by AE
			  			ANIM_UI_ANGLE,
						ANIM_UI_SLIDER,
						ANIM_UI_POINT,
						ANIM_UI_RECT,
						ANIM_UI_COLOR_RGB,
						ANIM_UI_COLOR_CMYK,
						ANIM_UI_COLOR_LAB;

				// These next four sets of longints are IEEE 64-bit doubles.  To store
				// them correctly, you must specify them as hexidecimal numbers.  To
				// find the correct hexidecimal number, you must convert your decimal
				// number to a double.
			  	hex longint;		// low long, valid_min (used for UI type slider - AE only)
			  	hex longint;		// high long, valid_min (64-bit double)
			  	
			  	hex longint;		// low long, valid_max (used for UI type slider - AE only)
			  	hex longint;		// high long, valid_max (64-bit double)

			  	hex longint;		// low long, ui_min (used for UI type slider - AE only)
			  	hex longint;		// high long, ui_min (64-bit double)

			  	hex longint;		// low long, ui_max (used for UI type slider - AE only)
			  	hex longint;		// high long, ui_max (64-bit double)

			  	fill bit[28];		// ANIM_ParamFlags
			  	boolean dontAnimateParam, animateParam;		// ANIM_PR_DONT_ANIMATE (PrMr)
			  	boolean dontRestrictBounds, restrictBounds;	// ANIM_PF_RESTRICT_BOUNDS (AE only)
			  	boolean	spaceIsAbsolute, spaceIsRelative;	// ANIM_PF_SPACE_IS_RELATIVE (AE only)
			  	boolean resIndependent, resDependant;		// ANIM_PF_IS_RES_DEPENDENT (AE only)

			  	longint;			// size of property described in bytes (int16 = 2, int32 = 4, etc.)

			  	longint=0;			// reserved0
			  	longint=0;			// reserved1
			  	longint=0;			// reserved2
			  	longint=0;			// reserved3
			  animParamEnd:			  

			//-------------------------------------------------------------------
			// Premiere Transition Effect PiPL properties
			//-------------------------------------------------------------------
			case Pr_Effect_Info:		// Mirrors the old Premiere 'Fopt' resource
				longint = 'PrMr';		// Premiere host.
				key longint = 'pOPT';
				longint = 0;			// Index.
				longint = 16;			// Length.
				longint = 0;			// Version.
				
				// Valid corners mask and initial corners (lsb to msb):
				// bitTop | bitRight | bitBottom | bitLeft | bitUpperRight |
				// bitLowerRight | bitLowerLeft | bitUpperLeft
				byte;					// Valid corners mask.
				byte;					// Initial corners.
				fill bit[2];
				boolean doesNotNeedCallbacksAtSetup, needsCallbacksAtSetup;
				boolean;		
				boolean wantInitialSetupCall, dontWantInitialSetupCall;	
				boolean treatAsTransition, treatAsTwoInputFilter;
				boolean noCustomDialog, hasCustomDialog;				
				boolean dontHighlightOppositeCorners, highlightOppositeCorners;

				// These should be changed to booleans:
				byte notExclusive = 0, exclusive = 1;		
				byte notReversible = 0, reversible = 1;
				byte doesNotHaveEdges = 0, haveEdges = 1;
				byte doesNotHaveStartPoint = 0, haveStartPoint = 1;
				byte doesNotHaveEndPoint = 0, haveEndPoint = 1;

				longint = 0;			// Reserved.

			case Pr_Effect_Description:	// The text description of the transition.
				longint = 'PrMr';		// Premiere host.
				key longint = 'TEXT';	// This should be changed to 'pDES'.
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (descEnd[$$ArrayIndex(properties)] - descStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  descStart:
				pstring;
			  descEnd:
				align long;
								
			//-------------------------------------------------------------------
			// Illustrator/SweetPea PiPL properties
			//-------------------------------------------------------------------
			case InterfaceVersion:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'ivrs';
				longint = 0;			// Index.
				longint = 4;			// Length.
				longint;				// Version.
				
			case AdapterVersion:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'adpt';
				longint = 0;			// Index.
				longint = 4;			// Length.
				longint;				// Version.
			
			case SP_STSP:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'STSP';
				longint = 0;			// Index.
				longint = 4;			// Length.
				longint;
					
			case InternalName:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'pinm';
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (plugInNameEnd[$$ArrayIndex(properties)] -
							   plugInNameStart[$$ArrayIndex(properties)]) / 8;
				#endif
				plugInNameStart:
					cstring;
				plugInNameEnd:
					align long;

			case Imports:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'impt';
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (importsEnd[$$ArrayIndex(properties)] - 
							   importsStart[$$ArrayIndex(properties)]) / 8;
				#endif
				importsStart:
					longint = $$CountOf(ImportSuites);
					wide array ImportSuites
					{  
						isuitesStart:
							// Length (including this long):
							#if DeRez
								fill long;
							#else
								longint = ((isuitesEnd[$$ArrayIndex(properties), $$ArrayIndex(ImportSuites)] - 
											isuitesStart[$$ArrayIndex(properties), $$ArrayIndex(ImportSuites)]) / 8);
							#endif

							cstring;
							align long;
							longint;			// Suite version.
						isuitesEnd:
					};
				importsEnd:
								
			case Exports:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'expt';
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (exportsEnd[$$ArrayIndex(properties)] - 
							   exportsStart[$$ArrayIndex(properties)]) / 8;
				#endif
				exportsStart:
					longint = $$CountOf(ExportSuites);
					wide array ExportSuites
					{  
						esuitesStart:
							// Length (including this long):
							#if DeRez
								fill long;
							#else
								longint = ((esuitesEnd[$$ArrayIndex(properties), $$ArrayIndex(ExportSuites)] - 
											esuitesStart[$$ArrayIndex(properties), $$ArrayIndex(ExportSuites)]) / 8);
							#endif

							cstring;
							align long;
							longint;			// Suite version.
						esuitesEnd:
					};
				exportsEnd:
			
			case Description:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'desc';
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (descriptionEnd[$$ArrayIndex(properties)] -
							   descriptionStart[$$ArrayIndex(properties)]) / 8;
				#endif
				descriptionStart:
					cstring;
				descriptionEnd:
					align long;
					
			case Keywords:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'keyw';
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (keywordsEnd[$$ArrayIndex(properties)] - 
							   keywordsStart[$$ArrayIndex(properties)]) / 8;
				#endif
				keywordsStart:
					longint = $$CountOf(KeywordsArray);
					wide array KeywordsArray
					{  
						keywordsArrayStart:
							// Length (including this long):
							#if DeRez
								fill long;
							#else
								longint = ((keywordsArrayEnd[$$ArrayIndex(properties), $$ArrayIndex(KeywordsArray)] - 
											keywordsArrayStart[$$ArrayIndex(properties), $$ArrayIndex(KeywordsArray)]) / 8);
							#endif

							cstring;
						keywordsArrayEnd:
					};
				keywordsEnd:
					align long;
				
			case Title:
				longint = 'ADBE';		// SweetPea/Illustrator host.
				key longint = 'titl';
				longint = 0;			// Index.
				#if DeRez
					fill long;
				#else
					longint = (titleEnd[$$ArrayIndex(properties)] -
							   titleStart[$$ArrayIndex(properties)]) / 8;
				#endif
				titleStart:
					cstring;
				titleEnd:
					align long;
					
			case Messages:
				longint = 'ADBE';		// SweetPea/Illustrator host
				key longint = 'AcpM';
				longint = 0;			// Index.
				longint = 4;			// Length.
				fill bit[28];			// Reserved.
				
				boolean startupRequired, noStartupRequired;
				boolean doesNotPurgeCache, purgeCache;
				boolean shutdownRequired, noShutdownRequired;	// Default is to give shutdown msg.
				boolean doNotAcceptProperty, acceptProperty;
				
			//-------------------------------------------------------------------
			// PhotoDeluxe PiPL properties
			//-------------------------------------------------------------------
			case ButtonIcon:
				longint = '8BIM';
				key longint = 'btni';
				longint = 0;		// pad
				#if DeRez
					fill long;
				#else
					longint = (buttonIconEnd[$$ArrayIndex(properties)] - buttonIconStart[$$ArrayIndex(properties)]) / 8; // length
				#endif
			buttonIconStart:
				longint = 0;		// version
				longint none = 0,
					 	cicn = 1;	// Macintosh icon type
				longint none = 0,
					 	ICON = 1;	// Windows icon type
				longint;			// Icon resource ID
				cstring;			// Button icon name
			buttonIconEnd:
				align long;

			//-------------------------------------------------------------------
			// PhotoDeluxe extension to Import plug-in PiPL properties
			//-------------------------------------------------------------------			
			case Class:
				longint = '8BIM';
				key longint = 'clas';
				longint = 0;	// pad
				longint = 8;	// length
				longint = 0;	// version
				longint none = 0,
						scanner = 1,
						camera = 2,
						video = 3,
						floppy = 4,
						cdrom = 5,
						internet = 6;

			case PreviewFile:
				longint = '8BIM';
				key longint = 'prvw';
				longint = 0;	// pad
				#if DeRez
					fill long;
				#else
					longint = (previewFileEnd[$$ArrayIndex(properties)] - previewFileStart[$$ArrayIndex(properties)]) / 8; // length
				#endif
			previewFileStart:
				longint = 0;	// version
				cstring;		// preview filename
			previewFileEnd:
				align long;
			
			case FormatLayerSupport:
				longint = '8BIM';
				key longint = 'fmsl';
				longint = 0;	// Index.
				#if DeRez
					fill long;
				#else
					longint = (formatLayerSupportEnd[$$ArrayIndex(properties)] - formatLayerSupportStart[$$ArrayIndex(properties)]) / 8;
				#endif
			  formatLayerSupportStart:
				boolean noFormatLayers, doesSupportFormatLayers;
				fill bit[7];
			  formatLayerSupportEnd:
				align long;

			// Indicates layer support is read-only.
			// To use this setting, also include FormatLayerSupport with a value of doesSupportFormatLayers (see above).
			// If this property is present, then it's on. No parameters are required.
			case FormatLayerSupportReadOnly:
				longint = '8BIM';
				key longint = 'slRO';
				longint = 0;	// Index.
				longint = 4;	// Length.
				literal longint = 1;	// If specified, always on.
				
				
			// Is this plugin a stack renderer? (uses channel ports to read a document of layers and render a new document)
			// NOTE - This applies only to acquire plugins
			// If this property is present, then its on.  No parameters are required
			case StackRenderer:
				longint = '8BIM';
				key longint = 'sRnd';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
			
			
			// Should files or stacks be edited in the plugin?
			// This applies to file formats and smart objects, and image stack renderers
			// If this property is present, then the plugin will be called to edit the file/stack
			// 		instead of opening the file/stack in Photoshop
			// If this property is present, then its on.  No parameters are required
			case EditinPlugin:
				longint = '8BIM';
				key longint = 'ediP';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
			
			
			// Should the plugin be called to launch an editor?
			// This applies to file formats and smart objects
			// If this property is present, then the plugin will be called with a file reference
			//		so it can launch an external editor.  There is a new file format selector for this call.
			// If this property is present, then its on.  No parameters are required
			case PluginLaunchesEditor:
				longint = '8BIM';
				key longint = 'piLe';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.


			// For animation we need to know if the plug-in is position dependent
			// If this property is present, then its on.  No parameters are required
			case PositionDependent:
				longint = '8BIM';
				key longint = 'posd';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
			
			
			// For UI we need to know if the plug-in knows how to deal with different scale factors per monitor.
			// If this property is present, then its on.  No parameters are required
			case MonitorScalingAware:
				longint = '8BIM';
				key longint = 'pmsa';
				longint = 0;	// Index.
				longint = 4; 	// Length.
				literal longint = 1;	// If specified, always on.
			
			
			};
		};
	};

#undef PIPiPLTypes

//-------------------------------------------------------------------------------

#endif // qIncludeMe
#endif // PIPL.r
