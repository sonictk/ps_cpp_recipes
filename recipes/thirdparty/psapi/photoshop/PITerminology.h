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
* \file PITerminology.h
*
* \brief This file defines constants for the keys used to access descriptor
* events, keys, classes, enum types, and enum values. 
* 
* \details
* Copyright 2000 Adobe Systems Incorporated.
* All Rights Reserved.
* 
* Distribution:
* PUBLIC
*/
//*****************************************************************************
//		WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
//		WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
// This file should NO LONGER BE USED to define OSTypes for keys, classes,
// enumeration types, and enumeration values. It exists only for backward
// compatibility. 
//
// Add names of new events, keys, classes, enum types and enum values to
// PIStringTerminology.h
//
// The aete resource, which referenced these keys, IS BEING
// DELETED. A Pate resource is being used instead (see UActionsTerminology.r
// for the format). This resource identifies items with strings instead
// of OSTypes. New APIs support construction and
// access of descriptors with strings instead of OSTypes. If you need to
// find the string equivalent of an OSType from this table, you can look
// in UActions.cpp. If you need to look it up the string corresponding to
// an ID at runtime inside the app, you can use:
// charPtr = GetStringIDMap ()->Find (DescType)
// From a plugin, use StringIDToTypeID in the ActionControlSuite or the
// BasicActionControlSuite
//
// The symbols in this file are still needed for forms, types, and units,
// and so that existing code which references them will still work. But 
// NEW CODE SHOULD USE THE STRING-BASED APIs and define the string constants
// in PIStringTerminology.h

#ifndef __PITerminology_h__ // Already defined?
#define __PITerminology_h__

#if PRAGMA_ONCE
#pragma once
#endif

//*****************************************************************************
//
//
//	Use:
//		Use any of these predefined keys, types, and events for
//		mapping to predefined action terms.
//
//	Version history:
//		Version 1.0.0	1/21/1998	Ace		Initial compilation.
//			Compiled from AdobePITerminology.h, PIActions.h,
//			UActionsTerminology.h, and UBatchTerminology.h.
//		Version 2.0.0	10/20/1999	RW		Frozen -- no new OSType symbols
//											should be added.
//
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//	Classes.
//-------------------------------------------------------------------------------
#define classAction					'Actn'	// Action palette keyName, keyItemIndex, keyNumberOfSiblings, keyNumberOfChildren, keyParentName, keyParentIndex.
#define classActionSet				'ASet'	// Action palette keyName, keyItemIndex, keyNumberOfSiblings, keyNumberOfChildren, keyParentName, keyParentIndex.
#define classAdjustment				'Adjs'	// classLevels, classCurves, classBrightnessContrast, classColorBalance, classHueSaturation, classSelectiveColor, classThreshold, classPosterize, classInvert, classChannelMixer.
#define classAdjustmentLayer		'AdjL'	// See also: classLayer, classBackgroundLayer, classTextLayer, classObsoleteTextLayer.
#define classAirbrushTool			'AbTl'
#define classAlphaChannelOptions	'AChl'	// Breaks hash.
#define classAntiAliasedPICTAcquire	'AntA'
#define classApplication			'capp'	// cApplication
#define classArrowhead				'cArw'	// break rule because of keyArrowhead
#define classAssert					'Asrt'
#define classAssumedProfile			'AssP'
#define classBMPFormat				'BMPF'
#define classBackgroundLayer		'BckL'	// See also: classLayer, classAdjustmentLayer, classTextLayer.
#define classBevelEmboss			'ebbl'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classBitmapMode				'BtmM'	// classMode, keyMode.
#define classBlendRange				'Blnd'	// Breaks hash for bilinear.
#define classBlurTool				'BlTl'
#define classBookColor				'BkCl'
#define classBrightnessContrast		'BrgC'	// classAdjustment.
#define classBrush					'Brsh'
#define classBurnInTool				'BrTl'
#define classCachePrefs				'CchP'
#define classCMYKColor				'CMYC'	// keyCyan, keyMagenta, keyYellow, keyBlack.
#define classCMYKColorMode			'CMYM'	// classMode, keyMode.
#define classCMYKSetup				'CMYS'
#define classCalculation			'Clcl'
#define classChannel				'Chnl'
#define classChannelMatrix			'ChMx'
#define classChannelMixer			'ChnM'	// classAdjustment.
#define classCineonFormat			'SDPX'
#define classClippingInfo			'Clpo'
#define classClippingPath			'ClpP'	// There is also a keyClippingPath, enumClippingPath.
#define classCloneStampTool			'ClTl'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classColor					'Clr '
#define classColorBalance			'ClrB'	// classAdjustment.
#define classColorCorrection		'ClrC'
#define classColorPickerPrefs		'Clrk'	// Contains: keyPickerKind, keyPickerID.  There is also a keyColorPickerPrefs.
#define classColorSampler			'ClSm'
#define classColorStop				'Clrt'
#define classCommand				'Cmnd'
#define classCurves					'Crvs'	// classAdjustment.
#define classCurvePoint				'CrPt'
#define classCustomPalette			'Cstl'	// Breaks hash for classCustomPhosphors
#define classCurvesAdjustment		'CrvA'
#define classCustomPhosphors		'CstP'
#define classCustomWhitePoint		'CstW'
#define classDicomFormat			'Dicm'
#define classDisplayPrefs			'DspP'
#define classDocument				'Dcmn'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classDodgeTool				'DdTl'
#define classDropShadow				'DrSh'
#define classDuotoneInk				'DtnI'
#define classDuotoneMode			'DtnM'	// classMode, keyMode.
#define classEPSGenericFormat		'EPSG'	// Used by Parser plug-ins.
#define classEPSPICTPreview			'EPSC'	// Breaks hash for typeEPSPreview.
#define classEPSTIFFPreview			'EPST'
#define classElement				'Elmn'
#define classEllipse				'Elps'
#define classEraserTool				'ErTl'
#define classExport					'Expr'	// There is also a keyExport.
#define classFileInfo				'FlIn'
#define classFileSavePrefs			'FlSv'
#define classFlashPixFormat			'FlsP'
#define classFontDesignAxes			'FntD'	// There is also a keyFontDesignAxes
#define classFormat					'Fmt '	// There is also a keyFormat.
#define classFrameFX				'FrFX'
#define classContour				'FxSc'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classGeneralPrefs			'GnrP'
#define classGIF89aExport			'GF89'
#define classGIFFormat				'GFFr'
#define classGlobalAngle			'gblA'
#define classGradient				'Grdn'
#define classGradientFill			'Grdf'
#define classGradientMap			'GdMp'
#define classGradientTool			'GrTl'
#define classGraySetup				'GrSt'
#define classGrayscale				'Grsc'	// keyGray.
#define classGrayscaleMode			'Grys'	// classMode, keyMode.
#define classGuide					'Gd  '
#define classGuidesPrefs			'GdPr'
#define classHalftoneScreen			'HlfS' // There is also enumHalftoneScreen, keyHalftoneScreen, eventHalftoneScreen.
#define classHalftoneSpec			'Hlfp' // Collides with classHalftoneScreen
#define classHSBColor				'HSBC'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classHSBColorMode			'HSBM'
#define classHistoryBrushTool		'HBTl'
#define classHistoryPrefs			'CHsP'	// Breaks hash.
#define classHistoryState			'HstS'
#define classHueSatAdjustment		'HStA'
#define classHueSatAdjustmentV2		'Hst2'	// Breaks has for classHueSatAdjustment.
#define classHueSaturation			'HStr'	// classAdjustment.
#define classIFFFormat				'IFFF'
#define classIllustratorPathsExport	'IlsP'
#define classImagePoint				'ImgP'
#define classImport					'Impr'	// There is also a keyImport.
#define classIndexedColorMode		'IndC'	// classMode, keyMode.
#define classInkTransfer			'InkT'
#define classInnerGlow				'IrGl'
#define classInnerShadow			'IrSh'
#define classInterfaceColor			'IClr'
#define classInvert					'Invr'	// classAdjustment.
#define classJPEGFormat				'JPEG'	// There is also an enumJPEG.
#define classLabColor				'LbCl'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classLabColorMode			'LbCM'	// classMode, keyMode. Breaks hash for Lab Color.
#define classLayer					'Lyr '	// See also: classAdjustmentLayer, classBackgroundLayer, classTextLayer, classObsoleteTextLayer.
#define classLayerEffects			'Lefx'
#define classLayerFXVisible			'lfxv'
#define classLevels					'Lvls'	// classAdjustment.
#define classLevelsAdjustment		'LvlA'
#define classLightSource			'LghS'	// There is also a keyLightSource.
#define classLine					'Ln  '
#define classMacPaintFormat			'McPn'
#define classMagicEraserTool		'MgEr'
#define classMagicPoint				'Mgcp'	// keyHorizontal, keyVertical.
#define classMask					'Msk '
#define classMenuItem				'Mn  '	// Breaks hash. It was classMenu.
#define classMode					'Md  '	// There is also a keyMode, typeMode.
#define classMultichannelMode		'MltC'	// classMode, keyMode.
#define classObsoleteTextLayer		'TxLy'	// See also: classLayer, classAdjustmentLayer, classBackgroundLayer, classTextLayer.
#define classNull					'null'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classOffset					'Ofst'	// There is also keyOffset, eventOffset.
#define classOpacity				'Opac'
#define classOuterGlow				'OrGl'
#define classPDFGenericFormat		'PDFG'	// Used by Parser plug-ins.
#define classPICTFileFormat			'PICF'
#define classPICTResourceFormat		'PICR'
#define classPNGFormat				'PNGF'
#define classPageSetup				'PgSt'
#define classPaintbrushTool			'PbTl'
//#define classPaintStroke			'PntS'	// Paint stroke recording deleted for 6.0
#define classPath					'Path'
#define classPathComponent			'PaCm'
#define classPathPoint				'Pthp'
#define classPattern				'PttR'
#define classPatternStampTool		'PaTl'
#define classPencilTool				'PcTl'
#define classPhotoshop20Format		'Pht2'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classPhotoshop35Format		'Pht3'
#define classPhotoshopDCS2Format	'PhD2'
#define classPhotoshopDCSFormat		'PhD1'
#define classPhotoshopEPSFormat		'PhtE'
#define classPhotoshopPDFFormat		'PhtP'
#define classPixel					'Pxel'
#define classPixelPaintFormat		'PxlP'
#define classPluginPrefs			'PlgP'
#define classPoint					'Pnt '	// keyHorizontal, keyVertical.
#define classPointUI				'PtUI'
#define classPoint16				'Pnt1'
#define classPolygon				'Plgn'	// keyPoints.
#define classPosterize				'Pstr'	// classAdjustment.
#define classPreferences			'GnrP'
#define classProfileSetup			'PrfS'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classProperty				'Prpr'
#define classRange					'Rang'
#define classRect16					'Rct1'
#define classRGBColor				'RGBC'	// keyRed, keyGreen, keyBlue.
#define classRGBColorMode			'RGBM'	// classMode, keyMode.
#define classRGBSetup				'RGBt'	// Breaks hash. with RGBSetupSource
#define classRawFormat				'Rw  '
#define classRectangle				'Rctn'	// keyTop, keyLeft, keyBottom, keyRight.
#define classRectUI					'RtUI'
#define classSaturationTool			'SrTl'
#define classScitexCTFormat			'Sctx'
#define classSelection				'csel'	// cSelection
#define classSelectiveColor			'SlcC'	// classAdjustment.
#define classShapingCurve			'ShpC'
#define classSharpenTool			'ShTl'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classSingleColumn			'Sngc'	// keyLeft.
#define classSingleRow				'Sngr'	// keyTop.
#define classBackgroundEraserTool	'SETl'
#define classSolidFill				'SoFi'
#define classArtHistoryBrushTool	'ABTl'
#define classSmudgeTool				'SmTl'
#define classSnapshot				'SnpS'
#define classSpotColorChannel		'SCch'
#define classStyle					'StyC'
#define classSubPath				'Sbpl'
#define classTIFFFormat				'TIFF'
#define classTargaFormat			'TrgF'
#define classTextLayer				'TxLr'	// See also: classLayer, classAdjustmentLayer, classBackgroundLayer, classObsoleteTextLayer.
#define classTextStyle				'TxtS'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classTextStyleRange			'Txtt'	// Collides with classTextStyle
#define classThreshold				'Thrs'	// classAdjustment.
#define classTool					'Tool'
#define classTransferSpec			'Trfp'	// Collides with classTransparencyStop
#define classTransferPoint			'DtnP'	// Used to be DuotonePoint
#define classTransparencyPrefs		'TrnP'
#define classTransparencyStop		'TrnS'
#define classUnitsPrefs				'UntP'
#define classUnspecifiedColor		'UnsC'
#define classVersion				'Vrsn'	// keyVersionMajor, keyVersionMinor, keyVersionFix.
#define classWebdavPrefs			'Wdbv'
#define classXYYColor				'XYYC'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define classChromeFX				'ChFX'

#define classBackLight				'BakL'	// classBackLight. rkulkarn
#define classFillFlash				'FilF'	// classFillFlash. rkulkarn  //11/15/2000
#define classColorCast				'ColC'	// classColorCast. rkulkarn

//-------------------------------------------------------------------------------
//	Enumerations.
//-------------------------------------------------------------------------------
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumAdd								'Add '	// typeCalculation.
#define enumAmountHigh						'amHi'	// typeAmount.
#define enumAmountLow						'amLo'	// typeAmount.
#define enumAmountMedium					'amMd'	// typeAmount.
#define enumAntiAliasNone					'Anno'	// typeAntiAlias.
#define enumAntiAliasLow					'AnLo'	// typeAntiAlias.
#define enumAntiAliasMedium					'AnMd'	// typeAntiAlias.
#define enumAntiAliasHigh					'AnHi'	// typeAntiAlias.
#define enumAntiAliasCrisp					'AnCr'	// typeAntiAlias.
#define enumAntiAliasStrong					'AnSt'	// typeAntiAlias.
#define enumAntiAliasSmooth					'AnSm'	// typeAntiAlias.
#define enumAppleRGB						'AppR'	// typeBuiltinProfile.
#define enumASCII							'ASCI'	// typeEncoding.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumAskWhenOpening					'AskW'	// typeProfileMismatch, typeAssumeOptions.
#define enumBicubic							'Bcbc'	// typeInterpolation.
#define enumBinary							'Bnry'	// typeEncoding.
#define enumMonitorSetup					'MntS'	// typeMenuItem. Old file calibration settings menu.
#define enum16BitsPerPixel					'16Bt'	// typeDeepDepth.
#define enum1BitPerPixel					'OnBt'	// typeDepth.
#define enum2BitsPerPixel					'2Bts'	// typeDeepDepth.
#define enum32BitsPerPixel					'32Bt'	// typeDeepDepth.
#define enum4BitsPerPixel					'4Bts'	// typeDeepDepth.
#define enum5000							'5000'	// typeKelvin.
#define enum5500							'5500'	// typeKelvin.
#define enum6500							'6500'	// typeKelvin.
#define enum72Color							'72Cl'	// typeDCS. Was k72ColorEnum.
#define enum72Gray							'72Gr'	// typeDCS. Was k72GrayEnum.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enum7500							'7500'	// typeKelvin.
#define enum8BitsPerPixel					'EghB'	// typeDeepDepth, typeDepth.
#define enum9300							'9300'	// typeKelvin.
#define enumA								'A   '	// typeChannel.
#define enumAbsColorimetric					'AClr'	// typeIntent.
#define enumADSBottoms						'AdBt'	// typeAlignDistributeSelector.
#define enumADSCentersH						'AdCH'	// typeAlignDistributeSelector.
#define enumADSCentersV						'AdCV'	// typeAlignDistributeSelector.
#define enumADSHorizontal					'AdHr'	// typeAlignDistributeSelector.
#define enumADSLefts						'AdLf'	// typeAlignDistributeSelector.
#define enumADSRights						'AdRg'	// typeAlignDistributeSelector.
#define enumADSTops							'AdTp'	// typeAlignDistributeSelector.
#define enumADSVertical						'AdVr'	// typeAlignDistributeSelector.
#define enumADSSpacingH                     'AdSH'  // typeAlignDistributeSelector.
#define enumADSSpacingV                     'AdSV'  // typeAlignDistributeSelector.
#define enumAboutApp						'AbAp'	// typeMenuItem. About menu.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumAbsolute						'Absl'	// typeCorrectionMethod.
#define enumActualPixels					'ActP'	// typeMenuItem. View menu.
#define enumAdaptive						'Adpt'	// typeColorPalette.
#define enumAdjustmentOptions				'AdjO'	// typeMenuItem. Layer menu.
#define enumAirbrushEraser					'Arbs'	// typeEraserKind
#define enumAll								'Al  '	// typeOrdinal, typePurgeItem.
#define enumAmiga							'Amga'	// typePlatform
#define enumAngle							'Angl'	// typeGradientType.
#define enumAny								'Any '	// typeOrdinal.
#define enumApplyImage						'AplI'	// typeMenuItem. Image menu.
#define enumAroundCenter					'ArnC'	// typeZigZagType.
#define enumArrange							'Arng'	// typeMenuItem. Window menu.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumAsk								'Ask '	// typeYesNo.
#define enumB								'B   '	// typeChannel.
#define enumBack							'Back'	// typeOrdinal.
#define enumBackground						'Bckg'	// typeFillMode. There is also a keyBackground.
#define enumBackgroundColor					'BckC'	// typeFill, typeFillContents, typeColorStopType, typeMatteColor.
#define enumBackward						'Bckw'	// typeOrdinal.
#define enumBehind							'Bhnd'	// typeBlendMode.
#define enumBest							'Bst '	// typeBlurQuality.
#define enumBetter							'Dthb'	// typeDitherQuality.
#define enumBilinear						'Blnr'	// typeInterpolation.
#define enumBitDepth1						'BD1 '	// typeBitDepth. Breaks hash.
#define enumBitDepth16						'BD16'	// typeBitDepth. Breaks hash.
#define enumBitDepth24						'BD24'	// typeBitDepth. Breaks hash.
#define enumBitDepth32						'BD32'	// typeBitDepth. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumBitDepth4						'BD4 '	// typeBitDepth. Breaks hash.
#define enumBitDepth8						'BD8 '	// typeBitDepth. Breaks hash.
#define enumBitDepthA1R5G5B5				'1565'	// typeBitDepth. Breaks hash.
#define enumBitDepthR5G6B5					'x565'	// typeBitDepth. Breaks hash.
#define enumBitDepthX4R4G4B4				'x444'	// typeBitDepth. Breaks hash.
#define enumBitDepthA4R4G4B4				'4444'	// typeBitDepth. Breaks hash.
#define enumBitDepthX8R8G8B8				'x888'	// typeBitDepth. Breaks hash.
#define enumBitmap							'Btmp'	// typeColorSpace.
#define enumBlack							'Blck'	// typeGrayBehavior, typeFillContents, typeChannel.
#define enumBlackAndWhite					'BanW'	// typeForcedColors.
#define enumBlackBody						'BlcB'	// typeColorPalette.
#define enumBlacks							'Blks'	// typeColors.
#define enumBlockEraser						'Blk '	// typeEraserKind
#define enumBlast							'Blst'	// typeWindMethod.
#define enumBlocks							'Blks'	// typeExtrudeType. CONFLICT: enumBlacks.
#define enumBlue							'Bl  '	// typeChannel, typeDither. There is also a keyBlue.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumBlues							'Bls '	// typeColors.
#define enumBottom							'Bttm'	// typeVerticalLocation.
#define enumBrushDarkRough					'BrDR'	// typeBrushType. Breaks hash.
#define enumBrushesAppend					'BrsA'	// typeMenuItem. Brushes Palette menu
#define enumBrushesDefine					'BrsD'	// typeMenuItem. Brushes Palette menu
#define enumBrushesDelete					'Brsf'	// typeMenuItem. Brushes Palette menu
#define enumBrushesLoad						'Brsd'	// typeMenuItem. Brushes Palette menu
#define enumBrushesNew						'BrsN'	// typeMenuItem. Brushes Palette menu
#define enumBrushesOptions					'BrsO'	// typeMenuItem. Brushes Palette menu
#define enumBrushesReset					'BrsR'	// typeMenuItem. Brushes Palette menu
#define enumBrushesSave						'Brsv'	// typeMenuItem. Brushes Palette menu
#define enumBrushLightRough					'BrsL'	// typeBrushType.
#define enumBrushSimple						'BrSm'	// typeBrushType. Breaks hash.
#define enumBrushSize						'BrsS'	// typeCursorKind
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumBrushSparkle					'BrSp'	// typeBrushType. Breaks hash.
#define enumBrushWideBlurry					'BrbW'	// typeBrushType.
#define enumBrushWideSharp					'BrsW'	// typeBrushType.
#define enumBuiltin							'Bltn'	// typeRGBSetupSource, typeCompensation, typeCMYKSetupEngine, typeAssumeOptions.
#define enumBurnInH							'BrnH'	// typeBlendMode
#define enumBurnInM							'BrnM'	// typeBlendMode
#define enumBurnInS							'BrnS'	// typeBlendMode
#define enumButtonMode						'BtnM'	// typeMenuItem. Actions palette menu.
#define enumCIERGB							'CRGB'	// typePhosphors, typeBuiltinProfile.
#define enumWidePhosphors					'Wide'	// typePhosphors.
#define enumWideGamutRGB					'WRGB'	// typeBuiltinProfile.
#define enumCMYK							'CMYK'	// typeChannel.
#define enumCMYK64							'CMSF'	// typeColorSpace. CMYK Sixty-four
#define enumCMYKColor						'ECMY'	// typeColorSpace.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumCalculations					'Clcl'	// typeMenuItem. Image menu.
#define enumCascade							'Cscd'	// typeMenuItem. Window menu.
#define enumCenter							'Cntr'	// typeAlignment, typeStrokeLocation.
#define enumCenterGlow						'SrcC'	// typeInnerGlowSource.
#define enumCenteredFrame					'CtrF'
#define enumChannelOptions					'ChnO'	// typeMenuItem. Channels palette menu.
#define enumChannelsPaletteOptions			'ChnP'	// typeMenuItem. Channels palette menu.
#define enumCheckerboardNone				'ChcN'	// typeCheckerboardSize
#define	enumCheckerboardSmall				'ChcS'	// typeCheckerboardSize
#define enumCheckerboardMedium				'ChcM'	// typeCheckerboardSize
#define enumCheckerboardLarge				'ChcL'	// typeCheckerboardSize
#define enumClear							'Clar'	// typeBlendMode.
#define enumClearGuides						'ClrG'	// typeMenuItem. View menu.
#define enumClipboard						'Clpb'	// typePurgeItem.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumClippingPath					'ClpP'	// typePathKind. There is also a classClippingPath, keyClippingPath.
#define enumCloseAll						'ClsA'	// typeMenuItem. Window menu.
#define enumCoarseDots						'CrsD'	// typeMezzotintType.
#define enumColor							'Clr '	// typeBlendMode.
#define enumColorBurn						'CBrn'	// typeBlendMode, typeCalculation.
#define enumColorDodge						'CDdg'	// typeBlendMode, typeCalculation.
#define enumColorMatch						'ClMt'	// typeBuiltinProfile. Breaks hash for foo.
#define enumColorNoise						'ClNs'	// typeGradientForm
#define enumColorimetric					'Clrm'	// typeIntent.
#define enumComposite						'Cmps'	// typeChannel.
#define enumConvertToCMYK					'CnvC'	// typeProfileMismatch. Breaks hash with other "convert to" enums
#define enumConvertToGray					'CnvG'	// typeProfileMismatch. Breaks hash with other "convert to" enums
#define enumConvertToLab					'CnvL'	// typeProfileMismatch. Breaks hash with other "convert to" enums
#define enumConvertToRGB					'CnvR'	// typeProfileMismatch. Breaks hash with other "convert to" enums
#define enumCreateDuplicate					'CrtD'	// typeInterlaceCreateType.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumCreateInterpolation				'CrtI'	// typeInterlaceCreateType.
#define enumCross							'Crs '	// typeShape.
#define enumCurrentLayer					'CrrL'	// typeHistoryStateSource.
#define enumCustom							'Cst '	// typeRGBSetupSource. Breaks hash for enumCustomPattern.
#define enumCustomPattern					'Cstm'	// typeMethod. There is also eventCustom, keyCustom.
#define enumCustomStops						'CstS'	// typeGradientForm
#define enumCyan							'Cyn '	// typeChannel.
#define enumCyans							'Cyns'	// typeColors.
#define enumDark							'Drk '	// typePredefinedColors
#define enumDarken							'Drkn'	// typeBlendMode, typeCalculation.
#define enumDarkenOnly						'DrkO'	// typeDiffuseMode.
#define enumDashedLines						'DshL'	// typeGuideGridStyle
#define enumDesaturate						'Dstt'	// typeBlendMode
#define enumDiamond							'Dmnd'	// typeShape, typeGradientType.
#define enumDifference						'Dfrn'	// typeBlendMode, typeCalculation.
#define enumDiffusion						'Dfsn'	// typeDither.
#define enumDiffusionDither					'DfnD'	// typeMethod.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumDisplayCursorsPreferences		'DspC'	// typeMenuItem. File preferences menu.
#define enumDissolve						'Dslv'	// typeBlendMode.
#define enumDistort							'Dstr'	// typeMenuItem. Edit transform menu.
#define enumDodgeH							'DdgH'	// typeBlendMode
#define enumDodgeM							'DdgM'	// typeBlendMode
#define enumDodgeS							'DdgS'	// typeBlendMode
#define enumDots							'Dts '	// typeGuideGridStyle
#define enumDraft							'Drft'	// typeBlurQuality.
#define enumDuotone							'Dtn '	// typeChannel.
#define enumEBUITU							'EBT '	// typePhosphors.
#define enumEdgeGlow						'SrcE'	// typeInnerGlowSource.
#define enumEliminateEvenFields				'ElmE'	// typeInterlaceEliminateType.
#define enumEliminateOddFields				'ElmO'	// typeInterlaceEliminateType.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumEllipse							'Elps'	// typeShape.
#define enumEmboss							'Embs'	// typeBevelEmbossStyle. There is also an eventEmboss.
#define enumExact							'Exct'	// typeColorPalette.
#define enumExclusion						'Xclu'	// typeBlendMode, typeCalculation.
#define enumFPXCompressLossyJPEG			'FxJP'	// typeFPXCompress. Breaks hash.
#define enumFPXCompressNone					'FxNo'	// typeFPXCompress. Breaks hash.
#define enumFaster							'Dthf'	// typeDitherQuality.
#define enumFile							'Fle '	// typeRGBSetupSource. Breaks hash for enumFill.
#define enumFileInfo						'FlIn'	// typeMenuItem. File menu.
#define enumFillBack						'FlBc'	// typeFillColor.
#define enumFillFore						'FlFr'	// typeFillColor.
#define enumFillInverse						'FlIn'	// typeFillColor. CONFLICT: enumFileInfo.
#define enumFillSame						'FlSm'	// typeFillColor.
#define enumFineDots						'FnDt'	// typeMezzotintType.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumFirst							'Frst'	// typeOrdinal.
#define enumFirstIdle						'FrId'	// PR#17472, typeNotify
#define enumFitOnScreen						'FtOn'	// typeMenuItem. View menu.
#define enumForegroundColor					'FrgC'	// typeFillContents, typeColorStopType, typeMatteColor.
#define enumForward							'Frwr'	// typeOrdinal.
#define enumFreeTransform					'FrTr'	// typeMenuItem. Layer menu.
#define enumFront							'Frnt'	// typeOrdinal.
#define enumFullDocument					'FllD'	// typeHistoryStateSource.
#define enumFullSize						'FlSz'	// typePreview.
#define enumGaussianDistribution			'Gsn '	// typeDistribution. 
#define enumGIFColorFileColorTable			'GFCT'	// typeGIFColorFileType.
#define enumGIFColorFileColors				'GFCF'	// typeGIFColorFileType.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumGIFColorFileMicrosoftPalette	'GFMS'	// typeGIFColorFileType.
#define enumGIFPaletteAdaptive				'GFPA'	// typeGIFPaletteType.
#define enumGIFPaletteExact					'GFPE'	// typeGIFPaletteType.
#define enumGIFPaletteOther					'GFPO'	// typeGIFPaletteType.
#define enumGIFPaletteSystem				'GFPS'	// typeGIFPaletteType.
#define enumGIFRequiredColorSpaceIndexed	'GFCI'	// typeGIFRequiredColorSpaceType.
#define enumGIFRequiredColorSpaceRGB		'GFRG'	// typeGIFRequiredColorSpaceType.
#define enumGIFRowOrderInterlaced			'GFIN'	// typeGIFRowOrderType.
#define enumGIFRowOrderNormal				'GFNI'	// typeGIFRowOrderType.
#define enumGeneralPreferences				'GnrP'	// typeMenuItem. File preferences menu.
#define enumGood							'Gd  '	// typeBlurQuality.
#define enumGradientFill					'GrFl'	// typeFrameFill
#define enumGrainClumped					'GrnC'	// typeGrainType.
#define enumGrainContrasty					'GrCn'	// typeGrainType. Breaks hash.
#define enumGrainEnlarged					'GrnE'	// typeGrainType.
#define enumGrainHorizontal					'GrnH'	// typeGrainType.
#define enumGrainRegular					'GrnR'	// typeGrainType.
#define enumGrainSoft						'GrSf'	// typeGrainType. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumGrainSpeckle					'GrSp'	// typeGrainType. Breaks hash.
#define enumGrainSprinkles					'GrSr'	// typeGrainType. Breaks hash.
#define enumGrainStippled					'GrSt'	// typeGrainType. Breaks hash.
#define enumGrainVertical					'GrnV'	// typeGrainType.
#define enumGrainyDots						'GrnD'	// typeMezzotintType.
#define enumGraphics						'Grp '	// typeIntent.
#define enumGray							'Gry '	// typeFillContents, typeChannel, typeColor. There is also a keyGray.
#define enumGray16							'GryX'	// typeColorSpace. GRaY siXteen.
#define enumGray18							'Gr18'	// typeBuiltinProfile.
#define enumGray22							'Gr22'	// typeBuiltinProfile.
#define enumGray50							'Gr50'	// typeMatteColor.
#define enumGrayScale						'Gryc'	// typeColorSpace. Breaks hash for enumGrayscale ('Grys').
#define enumGrayscale						'Grys'	// typeColorSpace, typeColorPalette.
#define enumGreen							'Grn '	// typeChannel, typeColor. There is also a keyGreen.
#define enumGreens							'Grns'	// typeColors.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumGuidesGridPreferences			'GudG'	// typeMenuItem. File preferences menu.
#define enumHDTV							'HDTV'	// typePhosphors.
#define enumHSBColor						'HSBl'	// typeColorSpace. Breaks hash.
#define enumHSLColor						'HSLC'	// typeColorSpace.
#define enumHalftoneFile					'HlfF'	// typeMethod.
#define enumHalftoneScreen					'HlfS'	// typeMethod. There is also keyHalftoneScreen, eventHalftoneScreen, classHalftoneScreen
#define enumHardLight						'HrdL'	// typeBlendMode, typeCalculation.
#define enumHeavy							'Hvy '	// typeBlackGeneration.
#define enumHideAll							'HdAl'	// typeUserMaskOptions.
#define enumHideSelection					'HdSl'	// typeUserMaskOptions.
#define enumHigh							'High'	// typeUrgency.
#define enumHighQuality						'Hgh ' 	// typeQuality.
#define enumHighlights						'Hghl'	// typeColors.
#define enumHistogram						'Hstg'	// typeMenuItem. Image menu.
#define enumHistory							'Hsty'	// typePurgeItem.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumHistoryPaletteOptions			'HstO'	// typeMenuItem. History palette menu.
#define enumHistoryPreferences				'HstP'	// typeMenuItem. File preferences menu.
#define enumHorizontal						'Hrzn'	// typeOrientation. There is also a keyHorizontal.
#define enumHorizontalOnly					'HrzO'	// typeSpherizeMode.
#define enumHue								'H   '	// typeBlendMode.
#define enumIBMPC							'IBMP'	// typePlatform.
#define enumICC								'ICC '	// typeCMYKSetupEngine, typeAssumeOptions.
#define enumIcon							'Icn '	// typePreview.
#define enumIdleVM							'IdVM'	// typeState
#define enumIgnore							'Ignr'	// typeProfileMismatch.
#define enumImage							'Img '	// typeIntent, typeAreaSelector.
#define enumImageCachePreferences			'ImgP'	// typeMenuItem. File preferences menu.
#define enumIndexedColor					'Indl'	// typeColorSpace. Breaks hash.
#define enumInfoPaletteOptions				'InfP'	// typeMenuItem. Info palette menu.
#define enumInfoPaletteToggleSamplers		'InfT'	// typeMenuItem. Info palette menu.
#define enumInnerBevel						'InrB'	// typeBevelEmbossStyle.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumInsetFrame						'InsF'
#define enumInside							'Insd'	// typeStrokeLocation.
#define enumJPEG							'JPEG'	// typeDepth, typeEncoding. There is also a classJPEGFormat.
#define enumJustifyAll						'JstA'	// typeAlignment.
#define enumJustifyFull						'JstF'	// typeAlignment.
#define enumKeepProfile						'KPro'	// typeProfileMismatch.
#define enumKeyboardPreferences				'KybP'	// typeMenuItem. File preferences menu.
#define enumLab								'Lab '	// typeChannel.
#define enumLab48							'LbCF'	// typeColorSpace. LaB Color Forty-eight.
#define enumLabColor						'LbCl'	// typeColorSpace.
#define enumLarge							'Lrg '	// typeRippleSize.
#define enumLast							'Lst '	// typeOrdinal.
#define enumLastFilter						'LstF'	// typeMenuItem. Filter menu.
#define enumLayerOptions					'LyrO'	// typeMenuItem. Layer menu.
#define enumLayersPaletteOptions			'LyrP'	// typeMenuItem. Layers palette menu.
#define enumLeft							'Left'	// From UActionsTerminology. typeHorizontalLocation. CONFLICT: enumLeft ('Lft ').
#define enumLeft_PLUGIN						'Lft '	// From AdobePITerminology. typeDirection, typeAlignment. CONFLICT: enumLeft ('Left').
#define enumLevelBased						'LvlB'	// typeExtrudeRandom.
#define enumLight							'Lgt '	// typeBlackGeneration.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumLightBlue						'LgtB'	// typeGuideGridColor
#define enumLightDirBottom					'LDBt'	// typeLightDirection. Breaks hash.
#define enumLightDirBottomLeft				'LDBL'	// typeLightDirection. Breaks hash.
#define enumLightDirBottomRight				'LDBR'	// typeLightDirection. Breaks hash.
#define enumLightDirLeft					'LDLf'	// typeLightDirection. Breaks hash.
#define enumLightDirRight					'LDRg'	// typeLightDirection. Breaks hash.
#define enumLightDirTop						'LDTp'	// typeLightDirection. Breaks hash.
#define enumLightDirTopLeft					'LDTL'	// typeLightDirection. Breaks hash.
#define enumLightDirTopRight				'LDTR'	// typeLightDirection. Breaks hash.
#define enumLightGray						'LgtG'	// typeGuideGridColor
#define enumLightDirectional				'LghD'	// typeLightType.
#define enumLightenOnly						'LghO'	// typeDiffuseMode. CONFLICT: enumLightOmni.
#define enumLightOmni						'LghO'	// typeLightType. CONFLICT: enumLightenOnly.
#define enumLightPosBottom					'LPBt'	// typeLightPosition. Breaks hash.
#define enumLightPosBottomLeft				'LPBL'	// typeLightPosition. Breaks hash.
#define enumLightPosBottomRight				'LPBr'	// typeLightPosition. Breaks hash.
#define enumLightPosLeft					'LPLf'	// typeLightPosition. Breaks hash.
#define enumLightPosRight					'LPRg'	// typeLightPosition. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumLightPosTop						'LPTp'	// typeLightPosition. Breaks hash.
#define enumLightPosTopLeft					'LPTL'	// typeLightPosition. Breaks hash.
#define enumLightPosTopRight				'LPTR'	// typeLightPosition. Breaks hash.
#define enumLightRed						'LgtR'	// typeGuideGridColor
#define enumLightSpot						'LghS'	// typeLightType.
#define enumLighten							'Lghn'	// typeBlendMode, typeCalculation. Breaks hash for Lightness.
#define enumLightness						'Lght'	// typeChannel.
#define enumLine							'Ln  '	// typeShape.
#define enumLines							'Lns '	// typeGuideGridStyle
#define enumLinear							'Lnr '	// typeGradientType.
#define enumLinked							'Lnkd'	// typeOrdinal.
#define enumLongLines						'LngL'	// typeMezzotintType.
#define enumLongStrokes						'LngS'	// typeMezzotintType.
#define enumLow								'Low '	// typeUrgency.
#define enumLower							'Lwr '	// typeContourEdge.
#define enumLowQuality						'Lw  ' 	// typeQuality.
#define enumLuminosity						'Lmns'	// typeBlendMode.
#define enumMaya							'Maya'	// typePlatform
#define enumMacThumbnail					'McTh'	// typePreview.
#define enumMacintosh						'Mcnt'	// typePlatform, typeEPSPreview.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumMacintoshSystem					'McnS'	// typeColorPalette.
#define enumMagenta							'Mgnt'	// typeChannel.
#define enumMagentas						'Mgnt'	// typeColors. CONFLICT: enumMagenta.
#define enumMask							'Msk '	// typeChannel.
#define enumMaskedAreas						'MskA'	// typeMaskIndicator.
#define enumMasterAdaptive					'MAdp'	// typeColorPalette.
#define enumMasterPerceptual				'MPer'	// typeColorPalette.
#define enumMasterSelective					'MSel'	// typeColorPalette.
#define enumMaximum							'Mxmm'	// typeBlackGeneration.
#define enumMaximumQuality					'Mxm ' 	// typeQuality. There is also a keyMaximum, eventMaximum.
#define enumMedium							'Mdim'	// typeBlackGeneration
#define enumMediumBlue						'MdmB'	// typeGuideGridColor
#define enumMediumQuality					'Mdm '	// typeQuality, typeRippleSize
#define enumMediumDots						'MdmD'	// typeMezzotintType.
#define enumMediumLines						'MdmL'	// typeMezzotintType.
#define enumMediumStrokes					'MdmS'	// typeMezzotintType.
#define enumMemoryPreferences				'MmrP'	// typeMenuItem. File preferences menu.
#define enumMergeChannels					'MrgC'	// typeMenuItem. Channels palette menu.
#define enumMerged							'Mrgd'	// typeOrdinal.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumMergedLayers					'Mrg2'	// typeHistoryStateSource.		new for PSCS2
#define enumMergedLayersOld					'MrgL'	// typeHistoryStateSource.		used for PSCS1 and prior
#define enumMiddle							'Mddl'	// typeOrdinal.
#define enumMidtones						'Mdtn'	// typeColors.
#define enumModeGray						'MdGr'	// typeMode.
#define enumModeRGB							'MdRG'	// typeMode.
#define enumMonitor							'Moni'	// typeRGBSetupSource, typeAssumeOptions.
#define enumMonotone						'Mntn'	// typeChannel.
#define enumMulti72Color					'72CM'	// typeDCS. Was kMulti72ColorEnum.
#define enumMulti72Gray						'72GM'	// typeDCS. Was kMulti72GrayEnum.
#define enumMultichannel					'Mlth'	// typeColorSpace. Breaks hash.
#define enumMultiNoCompositePS				'NCmM'	// typeDCS. Was kMultiNoCompositePSEnum.
#define enumMultiply						'Mltp'	// typeBlendMode, typeCalculation.
#define enumNavigatorPaletteOptions			'NvgP'	// typeMenuItem. Navigator palette menu.
#define enumNearestNeighbor					'Nrst'	// typeInterpolation.
#define enumNetscapeGray					'NsGr'	// typeMatteColor.
#define enumNeutrals						'Ntrl'	// typeColors.
#define enumNewView							'NwVw'	// typeMenuItem. View menu.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumNext							'Nxt '	// typeOrdinal.
#define enumNikon							'Nkn '	// typeLens.
#define enumNikon105						'Nkn1'	// typeLens.
#define enumNo								'N   '	// typeYesNo.
#define enumNoCompositePS					'NCmp'	// typeDCS. Was kNoCompositePSEnum.
#define enumNone							'None'	// typeOrdinal, typePreview, typeCompensation, typeBlackGeneration, typeAssumeOptions, typeForcedColors, typeMatteColor.
#define enumNormal							'Nrml'	// typeBlendMode, typeCalculation, typeSherizeMode, typeDiffuseMode.
#define enumNormalPath						'NrmP'	// typePathKind. Breaks hash.
#define enumNTSC							'NTSC'	// typePhosphors, typeBuiltinProfile.
#define enumNull							'null'
#define enumOS2								'OS2 '	// typePlatform. Breaks hash.
#define enumOff								'Off '	// typeOnOff.
#define enumOn								'On  '	// typeOnOff.
#define enumOpenAs							'OpAs'	// typeMenuItem. File menu.
#define enumOrange							'Orng' 	// typeColor.
#define enumOutFromCenter					'OtFr'	// typeZigZagType.
#define enumOutOfGamut						'OtOf'	// typeColors.
#define enumOuterBevel						'OtrB'	// typeBevelEmbossStyle.
#define enumOutside							'Otsd'	// typeStrokeLocation.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumOutsetFrame						'OutF'
#define enumOverlay							'Ovrl'	// typeBlendMode, typeCalculation.
#define enumPaintbrushEraser				'Pntb'	// typeEraserKind
#define enumPencilEraser					'Pncl'	// typeEraserKind
#define enumP22EBU							'P22B'	// typePhosphors.
#define enumPNGFilterAdaptive				'PGAd'	// typePNGFilter. Breaks hash.
#define enumPNGFilterAverage				'PGAv'	// typePNGFilter. Breaks hash.
#define enumPNGFilterNone					'PGNo'	// typePNGFilter. Breaks hash.
#define enumPNGFilterPaeth					'PGPt'	// typePNGFilter. Breaks hash. NOTE: File format named after Alan Paeth. Spelling is correct.
#define enumPNGFilterSub					'PGSb'	// typePNGFilter. Breaks hash.
#define enumPNGFilterUp						'PGUp'	// typePNGFilter. Breaks hash.
#define enumPNGInterlaceAdam7				'PGIA'	// typePNGInterlaceType. Breaks hash.
#define enumPNGInterlaceNone				'PGIN'	// typePNGInterlaceType. Breaks hash.
#define enumPagePosCentered					'PgPC'	// typePagePosition. Breaks hash.
#define enumPagePosTopLeft					'PgTL'	// typePagePosition. Breaks hash.
#define enumPageSetup						'PgSt'	// typeMenuItem. File menu.
#define enumPalSecam						'PlSc'	// typeBuiltinProfile.
#define enumPanaVision						'PnVs'	// typeLens.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumPathsPaletteOptions				'PthP'	// typeMenuItem. Paths palette menu.
#define enumPattern							'Ptrn'	// typeDither, typeFillContents, typePurgeItem.
#define enumPatternDither					'PtnD'	// typeMethod.
#define enumPerceptual						'Perc'	// typeColorPalette.
#define enumPerspective						'Prsp'	// typeMenuItem. Edit transform menu.
#define enumPhotoshopPicker					'Phtk'	// typePickerKind.
#define enumPickCMYK						'PckC'	// typeMenuItem. Color Palette menu
#define enumPickGray						'PckG'	// typeMenuItem. Color Palette menu
#define enumPickHSB							'PckH'	// typeMenuItem. Color Palette menu
#define enumPickLab							'PckL'	// typeMenuItem. Color Palette menu
#define enumPickOptions						'PckO'	// typeMenuItem. Color Palette menu
#define enumPickRGB							'PckR'	// typeMenuItem. Color Palette menu
#define enumPillowEmboss					'PlEb'	// typeBevelEmbossStyle.
#define enumPixelPaintSize1					'PxS1'	// Breaks hash.
#define enumPixelPaintSize2					'PxS2'	// Breaks hash.
#define enumPixelPaintSize3					'PxS3'	// Breaks hash.
#define enumPixelPaintSize4					'PxS4'	// Breaks hash.
#define enumPlace							'Plce'	// typeMenuItem. File menu.
#define enumPlaybackOptions					'PbkO'	// typeMenuItem. Actions palette menu.
#define enumPluginPicker					'PlgP'	// typePickerKind.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumPluginsScratchDiskPreferences	'PlgS'	// typeMenuItem. File preferences menu.
#define enumPolarToRect						'PlrR'	// typeConvert.
#define enumPondRipples						'PndR'	// typeZigZagType.
#define enumPrecise							'Prc '	// typeCursorKind
#define enumPreciseMatte					'PrBL'	// typeMatteTechnique
#define enumPreviewOff						'PrvO'  // typePreviewCMYK.
#define enumPreviewCMYK						'PrvC'  // typePreviewCMYK.
#define enumPreviewCyan						'Prvy'  // typePreviewCMYK.
#define enumPreviewMagenta					'PrvM'  // typePreviewCMYK.
#define enumPreviewYellow					'PrvY'  // typePreviewCMYK.
#define enumPreviewBlack					'PrvB'  // typePreviewCMYK.
#define enumPreviewCMY						'PrvN'  // typePreviewCMYK.
#define enumPrevious						'Prvs'	// typeColorPalette, typeOrdinal.
#define enumPrimaries						'Prim'	// typeForcedColors.
#define enumPrintSize						'PrnS'	// typeMenuItem. View menu.
#define enumPrintingInksSetup				'PrnI'	// typeMenuItem. Old file calibration settings menu.
#define enumPurple							'Prp '	// typePredefinedColors
#define enumPyramids						'Pyrm'	// typeExtrudeType.
#define enumQCSAverage						'Qcsa'	// typeQuadCenterState.
#define enumQCSCorner0						'Qcs0'	// typeQuadCenterState.
#define enumQCSCorner1						'Qcs1'	// typeQuadCenterState.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumQCSCorner2						'Qcs2'	// typeQuadCenterState.
#define enumQCSCorner3						'Qcs3'	// typeQuadCenterState.
#define enumQCSIndependent					'Qcsi'	// typeQuadCenterState.
#define enumQCSSide0						'Qcs4'	// typeQuadCenterState.
#define enumQCSSide1						'Qcs5'	// typeQuadCenterState.
#define enumQCSSide2						'Qcs6'	// typeQuadCenterState.
#define enumQCSSide3						'Qcs7'	// typeQuadCenterState.
#define enumQuadtone						'Qdtn'	// typeChannel.
#define enumQueryAlways						'QurA'	// typeQueryState
#define enumQueryAsk						'Qurl'	// typeQueryState
#define enumQueryNever						'QurN' 	// typeQueryState
#define enumRepeat							'Rpt '	// typeFillMode.
#define enumRGB								'RGB '	// typeGrayBehavior, typeChannel.
#define enumRGB48							'RGBF'	// typeColorSpace. RGB Forty-eight
#define enumRGBColor						'RGBC'	// typeColorSpace.
#define enumRadial							'Rdl '	// typeGradientType.
#define enumRandom							'Rndm'	// typeExtrudeRandom.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumRectToPolar						'RctP'	// typeConvert.
#define enumRed								'Rd  '	// typeChannel, typeColor.
#define enumRedrawComplete					'RdCm'	// typeState.
#define enumReds							'Rds '	// typeColors.
#define enumReflected						'Rflc'	// typeGradientType.
#define enumRelative						'Rltv'	// typeCorrectionMethod.
#define enumRepeatEdgePixels				'RptE'	// typeUndefinedArea.
#define enumRevealAll						'RvlA'	// typeUserMaskOptions.
#define enumRevealSelection					'RvlS'	// typeUserMaskOptions.
#define enumRevert							'Rvrt'	// typeBlendMode
#define enumRight							'Rght'	// typeDirection, typeAlignment, typeHorizontalLocation.
#define enumRotate							'Rtte'	// typeMenuItem. Edit transform menu.
#define enumRotoscopingPreferences			'RtsP'	// typeMenuItem. File preferences menu.
#define enumRound							'Rnd '	// typeShape.
#define enumRulerCm							'RrCm'	// typeRulerUnits. Breaks hash.
#define enumRulerInches						'RrIn'	// typeRulerUnits. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumRulerPercent					'RrPr'	// typeRulerUnits. Breaks hash.
#define enumRulerPicas						'RrPi'	// typeRulerUnits. Breaks hash.
#define enumRulerPixels						'RrPx'	// typeRulerUnits. Breaks hash.
#define enumRulerPoints						'RrPt'	// typeRulerUnits. Breaks hash.
#define enumAdobeRGB1998					'SMPT'	// typePhosphors, typeBuiltinProfile.
#define enumSMPTEC							'SMPC'	// typePhosphors. typeBuiltinProfile.
#define enumSRGB							'SRGB'	// typeBuiltinProfile.
#define enumSample3x3						'Smp3'	// typeEyeDropperSample.
#define enumSample5x5						'Smp5'	// typeEyeDropperSample.
#define enumSamplePoint						'SmpP'	// typeEyeDropperSample.
#define enumSaturate						'Str '	// typeBlendMode. Breaks hash with enumSaturation
#define enumSaturation						'Strt'	// typeBlendMode.
#define enumSaved							'Sved'	// typeFillContents.
#define enumSaveForWeb						'Svfw'	// typeMenuItem
#define enumSavingFilesPreferences			'SvnF'	// typeMenuItem. File preferences menu.
#define enumScale							'Scl '	// typeMenuItem. Edit transform menu. There is also a keyScale.
#define enumScreen							'Scrn'	// typeBlendMode, typeCalculation.
#define enumScreenCircle					'ScrC'	// typeScreenType.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumScreenDot						'ScrD'	// typeScreenType.
#define enumScreenLine						'ScrL'	// typeScreenType.
#define enumSelectedAreas					'SlcA'	// typeMaskIndicator.
#define enumSelection						'Slct'	// typeAreaSelector.
#define enumSelective						'Sele'	// typeColorPalette.
#define enumSeparationSetup					'SprS'	// typeMenuItem. Old file calibration settings menu.
#define enumSeparationTables				'SprT'	// typeMenuItem. Old file calibration settings menu.
#define enumShadows							'Shdw'	// typeColors.
#define enumContourLinear					'sp01'	// typeBuiltInContour
#define enumContourGaussian					'sp02'
#define enumContourSingle					'sp03'
#define enumContourDouble					'sp04'
#define enumContourTriple					'sp05'
#define enumContourCustom					'sp06'
#define enumShortLines						'ShrL'	// typeMezzotintType.
#define enumShortStrokes					'ShSt'	// typeMezzotintType. Breaks hash.
#define enumSingle72Color					'72CS'	// typeDCS. Was kSngl72ColorEnum.
#define enumSingle72Gray					'72GS'	// typeDCS. Was kSngl72GrayEnum.
#define enumSingleNoCompositePS				'NCmS'	// typeDCS. Was kSnglNoCompositePSEnum.
#define enumSkew							'Skew'	// typeMenuItem. Edit transform menu.
#define enumSlopeLimitMatte					'Slmt'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumSmall							'Sml '	// typeRippleSize.
#define enumSmartBlurModeEdgeOnly			'SBME'	// typeSmartBlurMode.
#define enumSmartBlurModeNormal				'SBMN'	// typeSmartBlurMode.
#define enumSmartBlurModeOverlayEdge		'SBMO'	// typeSmartBlurMode.
#define enumSmartBlurQualityHigh			'SBQH'	// typeSmartBlurQuality.
#define enumSmartBlurQualityLow				'SBQL'	// typeSmartBlurQuality.
#define enumSmartBlurQualityMedium			'SBQM'	// typeSmartBlurQuality.
#define enumSnapshot						'Snps'	// typeFillContents, typePurgeItem.
#define enumSolidColor						'SClr'	// typeFrameFill
#define enumSoftLight						'SftL'	// typeBlendMode, typeCalculation.
#define enumSoftMatte						'SfBL'	// typeMatteTechnique
#define enumSpectrum						'Spct'	// typeColorPalette.
#define enumSpin							'Spn '	// typeBlurMethod.
#define enumSpotColor						'Spot'	// typeMaskIndicator.
#define enumSquare							'Sqr '	// typeShape.
#define enumStagger							'Stgr'	// typeWindMethod.
#define enumStampIn							'In  '	// typeBevelEmbossStampStyle.
#define enumStampOut						'Out '	// typeBevelEmbossStampStyle.
#define enumStandard						'Std '	// typeCursorKind
#define enumStdA							'StdA'	// typeKelvin.
#define enumStdB							'StdB'	// typeKelvin.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumStdC							'StdC'	// typeKelvin.
#define enumStdE							'StdE'	// typeKelvin.
#define enumStretchToFit					'StrF'	// typeDisplacementMap.
#define enumStrokeDirHorizontal				'SDHz'	// typeStrokeDirection. Breaks hash. Was enumStokeDirHorizontal.
#define enumStrokeDirLeftDiag				'SDLD'	// typeStrokeDirection. Breaks hash. Was enumStrokeDirLeftDiag.
#define enumStrokeDirRightDiag				'SDRD'	// typeStrokeDirection. Breaks hash. Was enumStokeDirRightDiag.
#define enumStrokeDirVertical				'SDVt'	// typeStrokeDirection. Breaks hash. Was enumStrokeDirVertical.
#define enumStylesAppend					'SlsA'	// typeMenuItem. Styles Palette menu
#define enumStylesDelete					'Slsf'	// typeMenuItem. Styles Palette menu
#define enumStylesLoad						'Slsd'	// typeMenuItem. Styles Palette menu
#define enumStylesNew						'SlsN'	// typeMenuItem. Styles Palette menu
#define enumStylesReset						'SlsR'	// typeMenuItem. Styles Palette menu
#define enumStylesSave						'Slsv'	// typeMenuItem. Styles Palette menu
#define enumSubtract						'Sbtr'	// typeCalculation.
#define enumSwatchesAppend					'SwtA'	// typeMenuItem. Swatches Palette menu
#define enumSwatchesReplace					'Swtp'	// typeMenuItem. Swatches Palette menu
#define enumSwatchesReset					'SwtR'	// typeMenuItem. Swatches Palette menu
#define enumSwatchesSave					'SwtS'	// typeMenuItem. Swatches Palette menu
#define enumSystemPicker					'SysP'	// typePickerKind.
#define enumTables							'Tbl '	// typeCMYKSetupEngine.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumTarget							'Trgt'	// typeOrdinal.
#define enumTargetPath						'Trgp'	// typePathKind. There is also a keyTargetPath. Breaks hash.
#define enumTexTypeBlocks					'TxBl'	// typeTextureType. Breaks hash.
#define enumTexTypeBrick					'TxBr'	// typeTextureType. Breaks hash.
#define enumTexTypeBurlap					'TxBu'	// typeTextureType. Breaks hash.
#define enumTexTypeCanvas					'TxCa'	// typeTextureType. Breaks hash.
#define enumTexTypeFrosted					'TxFr'	// typeTextureType. Breaks hash.
#define enumTexTypeSandstone				'TxSt'	// typeTextureType. Breaks hash.
#define enumTexTypeTinyLens					'TxTL'	// typeTextureType. Breaks hash.
#define enumThreshold						'Thrh'	// typeMethod.
#define enumThumbnail						'Thmb'	// typePreview.
#define enumTIFF							'TIFF' 	// typeEPSPreview.
#define enumTile							'Tile'	// From UActionsTerminology. typeMenuItem. Window menu. CONFLICT: enumTile ('Tl  ').
#define enumTile_PLUGIN						'Tl  '	// From AdobePITerminology. typeDisplacementMap. CONFLICT: enumTile ('Tile').
#define enumToggleActionsPalette			'TglA'	// typeMenuItem. Window menu.
#define enumToggleBlackPreview				'TgBP'	// typeMenuItem. View menu.
#define enumToggleBrushesPalette			'TglB'	// typeMenuItem. Window menu.
#define enumToggleCMYKPreview				'TglC'	// typeMenuItem. View menu.
#define enumToggleCMYPreview				'TgCM'	// typeMenuItem. View menu.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumToggleChannelsPalette			'Tglh'	// typeMenuItem. Window menu. Breaks hash for ToggleCMYKPreview.
#define enumToggleColorPalette				'Tglc'	// typeMenuItem. Window menu. Breaks hash for TogglePaths.
#define enumToggleCyanPreview				'TgCP'	// typeMenuItem. View menu.	Breaks hash for ToggleCMYKPreview.
#define enumToggleEdges						'TglE'	// typeMenuItem. View menu.
#define enumToggleGamutWarning				'TglG'	// typeMenuItem. View menu.
#define enumToggleGrid						'TgGr'	// typeMenuItem. View menu.
#define enumToggleGuides					'Tgld'	// typeMenuItem. View menu. Breaks hash for ToggleGamutWarning.
#define enumToggleHistoryPalette			'TglH'	// typeMenuItem. Window menu.
#define enumToggleInfoPalette				'TglI'	// typeMenuItem. Window menu.
#define enumToggleLayerMask					'TglM'	// typeMenuItem. Edit transform menu. Breaks hash for ToggleLockGuides.
#define enumToggleLayersPalette				'Tgly'	// typeMenuItem. Window menu. Breaks hash for ToogleLockGuides.
#define enumToggleLockGuides				'TglL'	// typeMenuItem. View menu.
#define enumToggleMagentaPreview			'TgMP'	// typeMenuItem. View menu.
#define enumToggleNavigatorPalette			'TglN'	// typeMenuItem. Window menu.
#define enumToggleOptionsPalette			'TglO'	// typeMenuItem. Window menu.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumTogglePaths						'TglP'	// typeMenuItem. View menu.
#define enumTogglePathsPalette				'Tglt'	// typeMenuItem. Window menu. Breaks hash for TogglePaths.
#define enumToggleRGBMacPreview				'TrMp'	// typeMenuItem. Window menu
#define enumToggleRGBWindowsPreview			'TrWp'	// typeMenuItem. Window menu
#define enumToggleRGBUncompensatedPreview	'TrUp'	// typeMenuItem. Window menu
#define enumToggleRulers					'TglR'	// typeMenuItem. View menu.
#define enumToggleSnapToGrid				'TgSn'	// typeMenuItem. View menu.
#define enumToggleSnapToGuides				'TglS'	// typeMenuItem. View menu.
#define enumToggleStatusBar					'Tgls'	// typeMenuItem. Window menu. Breaks hash for ToggleSnapToGuides.
#define enumToggleStylesPalette				'TgSl'	// typeMenuItem. Window menu.
#define enumToggleSwatchesPalette			'Tglw'	// typeMenuItem. Window menu. Breaks hash for ToggleSnapToGuides.
#define enumToggleToolsPalette				'TglT'	// typeMenuItem. Window menu.
#define enumToggleYellowPreview				'TgYP'	// typeMenuItem. View menu.
#define enumToggleDocumentPalette			'TgDc'	// typeMenuItem. Window menu. Breaks hash for ToogleLockGuides.
#define enumTop								'Top '	// typeVerticalLocation.
#define enumTransparency					'Trsp'	// typeChannel.
#define enumTransparencyGamutPreferences	'TrnG'	// typeMenuItem. File preferences menu.
#define enumTransparent						'Trns'	// typeFill.
#define enumTrinitron						'Trnt'	// typePhosphors.
#define enumTritone							'Trtn'	// typeChannel.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumUIBitmap						'UBtm'	// type SourceMode, for ModeChange plugin
#define enumUICMYK							'UCMY'	// type SourceMode, for ModeChange plugin
#define enumUIDuotone						'UDtn'	// type SourceMode, for ModeChange plugin
#define enumUIGrayscale 					'UGry'	// type SourceMode, for ModeChange plugin
#define enumUIIndexed						'UInd'	// type SourceMode, for ModeChange plugin
#define enumUILab							'ULab'	// type SourceMode, for ModeChange plugin
#define enumUIMultichannel					'UMlt'	// type SourceMode, for ModeChange plugin
#define enumUIRGB							'URGB'	// type SourceMode, for ModeChange plugin
#define enumUndo							'Und '	// typePurgeItem.
#define enumUniform							'Unfm'	// typeColorPalette.
#define enumUniformDistribution				'Unfr'	// typeDistribution.
#define enumUnitsRulersPreferences			'UntR'	// typeMenuItem. File preferences menu.
#define enumUpper							'Upr '	// typeContourEdge.
#define enumUserStop						'UsrS'	// typeColorStopType.
#define enumVMPreferences					'VMPr'	// typeMenuItem. File preferences menu.
#define enumVertical						'Vrtc'	// typeOrientation.
#define enumVerticalOnly					'VrtO'	// typeSpherizeMode.
#define enumViolet							'Vlt ' 	// typeColor.
#define enumWaveSine						'WvSn'	// typeWaveType. Breaks hash.
#define enumWaveSquare						'WvSq'	// typeWaveType. Breaks hash.
#define enumWaveTriangle					'WvTr'	// typeWaveType. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumWeb								'Web '	// typeColorPalette, typeForcedColors.
#define enumWhite							'Wht '	// typeFill, typeFillContents, typeMatteColor, typeDither.
#define enumWhites							'Whts'	// typeColors.
#define enumWinThumbnail					'WnTh'	// typePreview.
#define enumWind							'Wnd '	// typeWindMethod.
#define enumWindows							'Win '	// typePlatform. Breaks hash.
#define enumWindowsSystem					'WndS'	// typeColorPalette.
#define enumWrap							'Wrp '	// typeFillMode.
#define enumWrapAround						'WrpA'	// typeUndefinedArea.
#define enumWorkPath						'WrkP'	// typePathKind. There is also keyWorkPathIndex.
#define enumYellow							'Yllw'	// typeChannel.
#define enumYellowColor						'Ylw ' 	// typeColor. Different from other typeColor enums due to conflict with enumYellow.
#define enumYellows							'Ylws'	// typeColors.
#define enumYes								'Ys  '	// typeYesNo.
#define enumZip								'ZpEn'	// typeEncoding.
#define enumZoom							'Zm  '	// typeLens.
#define enumZoomIn							'ZmIn'	// typeMenuItem. View menu.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define enumZoomOut							'ZmOt'	// typeMenuItem. View menu.

//-------------------------------------------------------------------------------
//	Events.
//-------------------------------------------------------------------------------
#define event3DTransform			'TdT '
#define eventAverage				'Avrg'
#define eventApplyStyle				'ASty'
#define eventAssert					'Asrt'
#define eventAccentedEdges			'AccE'
#define eventAdd					'Add '
#define eventAddNoise				'AdNs'
#define eventAddTo					'AddT'
#define eventAlign					'Algn'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventAll					'All '
#define eventAngledStrokes			'AngS'
#define eventApplyImage				'AppI'
#define eventBasRelief				'BsRl'
#define eventBatch					'Btch'
#define eventBatchFromDroplet		'BtcF'
#define eventBlur					'Blr '
#define eventBlurMore				'BlrM'	// There is also keyBlurMethod, typeBlurMethod.
#define eventBorder					'Brdr'
#define eventBrightness				'BrgC'
#define eventCanvasSize				'CnvS'
#define eventChalkCharcoal			'ChlC'
#define eventChannelMixer			'ChnM'
#define eventCharcoal				'Chrc'
#define eventChrome					'Chrm'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventClear					'Cler'
#define eventClose					'Cls '
#define eventClouds					'Clds'
#define eventColorBalance			'ClrB'
#define eventColorHalftone			'ClrH'
#define eventColorRange				'ClrR'
#define eventColoredPencil			'ClrP'
#define eventContactSheet			"63676b34-cb65-11d1-bc43-0060b0a13dc4"
#define eventConteCrayon			'CntC'
#define eventContract				'Cntc'	// Breaks hash for Center.
#define eventConvertMode			'CnvM'
#define eventCopy					'copy'	// kAECopy
#define eventCopyEffects			'CpFX'
#define eventCopyMerged				'CpyM'
#define eventCopyToLayer			'CpTL'
#define eventCraquelure				'Crql'
#define eventCreateDroplet			'CrtD'	// There is also an enumCreateDuplicate
#define eventCrop					'Crop'
#define eventCrosshatch				'Crsh'
#define eventCrystallize			'Crst'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventCurves					'Crvs'
#define eventCustom					'Cstm'	// There is also keyCustom, enumCustomPattern.
#define eventCut					'cut '	// kAECut
#define eventCutToLayer				'CtTL'
#define eventCutout					'Ct  '
#define eventDarkStrokes			'DrkS'
#define eventDeInterlace			'Dntr'
#define eventDefinePattern			'DfnP'
#define eventDefringe				'Dfrg'	// Breaks hash for Difference.
#define eventDelete					'Dlt '
#define eventDesaturate				'Dstt'	// Breaks hash for Distribution.
#define eventDeselect				'Dslc'
#define eventDespeckle				'Dspc'
#define eventDifferenceClouds		'DfrC'
#define eventDiffuse				'Dfs '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventDiffuseGlow			'DfsG'
#define eventDisableLayerFX			'dlfx'
#define eventDisplace				'Dspl'
#define eventDistribute				'Dstr'
#define eventDraw					'Draw'	// Draw Line
#define eventDryBrush				'DryB'
#define eventDuplicate				'Dplc'	// There is also a keyDuplicate.
#define eventDustAndScratches		'DstS'
#define eventEmboss					'Embs'	// There is also an enumEmboss.
#define eventEqualize				'Eqlz'
#define eventExchange				'Exch'
#define eventExpand					'Expn'
#define eventExport					'Expr'
#define eventExportTransparentImage	"02879e00-cb66-11d1-bc43-0060b0a13dc4"
#define eventExtrude				'Extr'
#define eventFacet					'Fct '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventFade					'Fade'
#define eventFeather				'Fthr'
#define eventFibers					'Fbrs'
#define eventFill					'Fl  '	// There is also keyFill, typeFill.
#define eventFilmGrain				'FlmG'
#define eventFilter					'Fltr'
#define eventFindEdges				'FndE'
#define eventFitImage				"3caa3434-cb67-11d1-bc43-0060b0a13dc4"
#define eventFlattenImage			'FltI'
#define eventFlip					'Flip'
#define eventFragment				'Frgm'
#define eventFresco					'Frsc'
#define eventGaussianBlur			'GsnB'
#define eventGet					'getd'	// kAEGetData
#define eventGlass					'Gls '
#define eventGlowingEdges			'GlwE'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventGradient				'Grdn'
#define eventGradientMap			'GrMp'
#define eventGrain					'Grn '
#define eventGraphicPen				'GraP'	// Breaks Hash for "Group with Prev."
#define eventGroup					'GrpL'
#define eventGrow					'Grow'
#define eventHalftoneScreen			'HlfS'	// There is also keyHalftoneScreen, enumHalftoneScreen, classHalftoneScreen.
#define eventHide					'Hd  '
#define eventHighPass				'HghP'
#define eventHSBHSL					'HsbP'
#define eventHueSaturation			'HStr'
#define eventImageSize				'ImgS'
#define eventImport					'Impr'
#define eventInkOutlines			'InkO'
#define eventIntersect				'Intr'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventIntersectWith			'IntW'
#define eventInverse				'Invs'	// Breaks hash for Invert.
#define eventInvert					'Invr'
#define eventLensFlare				'LnsF'
#define eventLevels					'Lvls'
#define eventLightingEffects		'LghE'
#define eventLink					'Lnk '
#define eventMake					'Mk  '	// Was kMakeEvent.
#define eventMaximum				'Mxm '	// There is also a keyMaximum, enumMaximumQuality.
#define eventMedian					'Mdn '
#define eventMergeLayers			'Mrg2'		// starting in PSCS2, use this constant for merge actions
#define eventMergeLayersOld			'MrgL'		// previous to PSCS2 actions use this for merge
#define eventMergeSpotChannel		'MSpt'
#define eventMergeVisible			'MrgV'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventMezzotint				'Mztn'
#define eventMinimum				'Mnm '	// There is also a keyMinimum.
#define eventModeChange				"8cba8cd6-cb66-11d1-bc43-0060b0a13dc4"
#define eventMosaic					'Msc '	// From UActionsTerminology. CONFLICT: eventMosaic ('MscT'). Was kMosaicEvent.
#define eventMosaic_PLUGIN			'MscT'	// From AdobePITerminology. CONFLICT: eventMosaic ('Msc ').
#define eventMotionBlur				'MtnB'
#define eventMove					'move'	// kAEMove
#define eventMultiPagePDFtoPSD		"ec8d7010-cb66-11d1-bc43-0060b0a13dc4"
#define eventNTSCColors				'NTSC'
#define eventNeonGlow				'NGlw'
#define eventNext					'Nxt '
#define eventNotePaper				'NtPr'
#define eventNotify					'Ntfy'	// PR#17472
#define eventNull					'null'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventOceanRipple			'OcnR'
#define eventOffset					'Ofst'	// There is also keyOffset, classOffset.
#define eventOpen					'Opn '
//#define eventPaint					'Pnt '	// Paint stroke recording deleted for 6.0
#define eventPaintDaubs				'PntD'
#define eventPaletteKnife			'PltK'
#define eventPaste					'past'	// kAEPaste
#define eventPasteEffects			'PaFX'
#define eventPasteInto				'PstI'
#define eventPasteOutside			'PstO'
#define eventPatchwork				'Ptch'
#define eventPhotocopy				'Phtc'
#define eventPinch					'Pnch'
#define eventPlace					'Plc '
#define eventPlaster				'Plst'
#define eventPlasticWrap			'PlsW'
#define eventPlay					'Ply '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventPointillize			'Pntl'
#define eventPolar					'Plr '
#define eventPosterEdges			'PstE'
#define eventPosterize				'Pstr'
#define eventPrevious				'Prvs'
#define eventPrint					'Prnt'
#define eventProfileToProfile		'PrfT'
#define eventPurge					'Prge'
#define eventQuit					'quit'	// kAEQuitApplication
#define eventRadialBlur				'RdlB'
#define eventRasterize				'Rstr'
#define eventRasterizeTypeSheet		'RstT'
#define eventRemoveBlackMatte		'RmvB'
#define eventRemoveLayerMask		'RmvL'
#define eventRemoveWhiteMatte		'RmvW'
#define eventRename					'Rnm '
#define eventReplaceColor			'RplC'
#define eventReset					'Rset'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventResizeImage				"1333cf0c-cb67-11d1-bc43-0060b0a13dc4"
#define eventReticulation			'Rtcl'
#define eventRevert					'Rvrt'
#define eventRipple					'Rple'
#define eventRotate					'Rtte'
#define eventRoughPastels			'RghP'
#define eventSave					'save'	// kAESave
#define eventSelect					'slct'	// kAESelect. Was kSelectEvent.
#define eventSelectiveColor			'SlcC'
#define eventSet					'setd'	// kAESetData
#define eventSharpenEdges			'ShrE'
#define eventSharpen				'Shrp'
#define eventSharpenMore			'ShrM'
#define eventShear					'Shr '
#define eventShow					'Shw '
#define eventSimilar				'Smlr'
#define eventSmartBlur				'SmrB'
#define eventSmooth					'Smth'
#define eventSmudgeStick			'SmdS'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventSolarize				'Slrz'
#define eventSpatter				'Spt '
#define eventSpherize				'Sphr'
#define eventSplitChannels			'SplC'
#define eventSponge					'Spng'
#define eventSprayedStrokes			'SprS'
#define eventStainedGlass			'StnG'
#define eventStamp					'Stmp'
#define eventStop					'Stop'
#define eventStroke					'Strk'
#define eventSubtract				'Sbtr'
#define eventSubtractFrom			'SbtF'
#define eventSumie					'Smie'	// Breaks hash.
#define eventTakeMergedSnapshot		'TkMr'
#define eventTakeSnapshot			'TkSn'
#define eventTextureFill			'TxtF'
#define eventTexturizer				'Txtz'	// Breaks hash.
#define eventThreshold				'Thrs'
#define eventTiles					'Tls '
#define eventTornEdges				'TrnE'
#define eventTraceContour			'TrcC'
#define eventTransform				'Trnf'	// Breaks hash for Transparent.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define eventTrap					'Trap'
#define eventTwirl					'Twrl'
#define eventUnderpainting			'Undr'
#define eventUndo					'undo'	// kAEUndo
#define eventUngroup				'Ungr'
#define eventUnlink					'Unlk'
#define eventUnsharpMask			'UnsM'
#define eventVariations				'Vrtn'
#define eventWait					'Wait'
#define eventWaterPaper				'WtrP'
#define eventWatercolor				'Wtrc'
#define eventWave					'Wave'	// Breaks hash.
#define eventWind					'Wnd '
#define eventZigZag					'ZgZg'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////


#define eventBackLight				'BacL'
#define eventFillFlash				'FilE' //rkulkarn 11/15/2000
#define eventColorCast				'ColE'
#define eventOpenUntitled			'OpnU'

//-------------------------------------------------------------------------------
//	Forms.
//-------------------------------------------------------------------------------
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define formClass			'Clss'
#define formEnumerated		'Enmr'
#define formIdentifier		'Idnt'					// Also keyID.
#define formIndex			'indx'					// formAbsolutePosition
#define formOffset			'rele'					// formRelativePosition
#define formProperty		'prop'					// formPropertyID

//-------------------------------------------------------------------------------
//	Keys.
//-------------------------------------------------------------------------------
#define key3DAntiAlias						'Alis'	// Is of typeAntiAlias.
#define keyA								'A   '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyAdjustment						'Adjs'
#define keyAligned							'Algd'	// Collides with keyAlignment
#define keyAlignment						'Algn'
#define keyAllPS							'All '
#define keyAllExcept						'AllE'
#define keyAllToolOptions					'AlTl'
#define keyAlphaChannelOptions				'AChn'	// Property. Breaks hash.
#define keyAlphaChannels					'AlpC'
#define keyAmbientBrightness				'AmbB'
#define keyAmbientColor						'AmbC'
#define keyAmount							'Amnt'	// There is also a typeAmount.
#define keyAmplitudeMax						'AmMx'	// Breaks hash.
#define keyAmplitudeMin						'AmMn'	// Breaks hash.
#define keyAnchor							'Anch'
#define keyAngle							'Angl'
#define keyAngle1							'Ang1'
#define keyAngle2							'Ang2'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyAngle3							'Ang3'
#define keyAngle4							'Ang4'
#define keyAntiAlias						'AntA'
#define keyAppend							'Appe'
#define keyApply							'Aply'
#define keyArea								'Ar  '
#define keyArrowhead						'Arrw'
#define keyAs								'As  '
#define keyAssetBin							'Asst'
#define keyAssumedCMYK						'AssC'
#define keyAssumedGray						'AssG'
#define keyAssumedRGB						'AssR'
#define keyAt								'At  '
#define keyAuto								'Auto'
#define keyAutoContrast						'AuCo'
#define keyAutoErase						'Atrs'
#define keyAutoKern							'AtKr'
#define keyAutoUpdate						'AtUp'
#define keyShowMenuColors					'SwMC'
#define keyAxis								'Axis'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyB								'B   '
#define keyBackground						'Bckg'	// There is also an enumBackground.
#define keyBackgroundColor					'BckC'
#define keyBackgroundLevel					'BckL'
#define keyBackward							'Bwd '
#define keyBalance							'Blnc'
#define keyBaselineShift					'Bsln'
#define keyBeepWhenDone						'BpWh'
#define keyBeginRamp						'BgnR'
#define keyBeginSustain						'BgnS'
#define keyBevelDirection					'bvlD'
#define keyBevelEmboss						'ebbl'
#define keyBevelStyle						'bvlS'
#define keyBevelTechnique					'bvlT'
#define keyBigNudgeH						'BgNH'	// Property. Breaks hash.
#define keyBigNudgeV						'BgNV'	// Property. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyBitDepth							'BtDp'	// There is also a keyBitDepth.
#define keyBlack							'Blck'
#define keyBlackClip						'BlcC'
#define keyBlackGeneration					'Blcn'	// Breaks hash for keyBlackGenerationCurve.
#define keyBlackGenerationCurve				'BlcG'
#define keyBlackIntensity					'BlcI'
#define keyBlackLevel						'BlcL'	// CONFLICT: keyBlackLimit.
#define keyBlackLimit						'BlcL'	// CONFLICT: keyBlackLevel.
#define keyBleed							'Bld '
#define keyBlendRange						'Blnd'	// Breaks hash for bilinear.
#define keyBlue								'Bl  '	// typeColor. There is also an enumBlue.
#define keyBlueBlackPoint					'BlBl'
#define keyBlueGamma						'BlGm'
#define keyBlueWhitePoint					'BlWh'
#define keyBlueX							'BlX '
#define keyBlueY							'BlY '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyBlur								'blur'
#define keyBlurMethod						'BlrM'	// There is also a typeBlurMethod.
#define keyBlurQuality						'BlrQ'	// There is also a typeBlurQuality.
#define keyBook								'Bk  '
#define keyBorderThickness					'BrdT'
#define keyBottom							'Btom'
#define keyBrightness						'Brgh'
#define keyBrushDetail						'BrsD'
#define keyBrushes							'Brsh'
#define keyBrushSize						'BrsS'
#define keyBrushType						'BrsT'
#define keyBumpAmplitude					'BmpA'
#define keyBumpChannel						'BmpC'
#define keyBy								'By  '
#define keyByline							'Byln'
#define keyBylineTitle						'BylT'
#define keyByteOrder						'BytO'
#define keyCachePrefs						'CchP'
#define keyChokeMatte						'Ckmt'
#define keyCloneSource						'ClnS'
#define keyCMYKSetup						'CMYS'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyCalculation						'Clcl'
#define keyCalibrationBars					'Clbr'
#define keyCaption							'Cptn'	// Property.
#define keyCaptionWriter					'CptW'
#define keyCategory							'Ctgr'
#define keyCellSize							'ClSz'
#define keyCenter							'Cntr'
#define keyCenterCropMarks					'CntC'
#define keyChalkArea						'ChlA'
#define keyChannel							'Chnl'	// Does not conflict. Last character is l, not captial i.
#define keyChannelMatrix					'ChMx'
#define keyChannelName						'ChnN'	// Property. Breaks hash.
#define keyChannels							'Chns'	// Breaks rule for plural
#define keyChannelsInterleaved				'ChnI'	// Does not conflict.  Last character is capital i, not L.
#define keyCharcoalAmount					'ChAm'	// Breaks hash.
#define keyCharcoalArea						'ChrA'
#define keyChromeFX							'ChFX'
#define keyCity								'City'
#define keyClearAmount						'ClrA'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyClippingPath						'ClPt'	// CONFLICT: Name keyClippingPathEPS.
#define keyClippingPathEPS					'ClpP'	// There is also a classClippingPath, enumClippingPath. CONFLICT: With name keyClippingPath.
#define keyClippingPathFlatness				'ClpF'	// Property. Breaks hash.
#define keyClippingPathIndex				'ClpI'	// Property. Breaks hash.
#define keyClippingPathInfo					'Clpg'	// Property. Breaks hash.
#define keyClosedSubpath					'Clsp'
#define keyColor							'Clr '
#define keyColorChannels					'Clrh'	// Conflicts with keyColorCorrection
#define keyColorCorrection					'ClrC'
#define keyColorIndicates					'ClrI'
#define keyColorManagement 					'ClMg'
#define keyColorPickerPrefs					'Clrr'	// There is also a classColorPickerPrefs.
#define keyColorTable						'ClrT'
#define keyColorize							'Clrz'
#define keyColors							'Clrs'
#define keyColorsList						'ClrL'
#define keyColorSpace						'ClrS'
#define keyColumnWidth						'ClmW'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyCommandKey						'CmdK'
#define keyCompensation						'Cmpn'
#define keyCompression						'Cmpr'
#define keyConcavity						'Cncv'
#define keyCondition						'Cndt'	// for ModeChange plugin
#define keyConstant							'Cnst'	// CONFLICT: keyConstrainProportions.
#define keyConstrain						'Cnst'	// CONFLICT: keyConstant.
#define keyConstrainProportions				'CnsP'
#define keyConstructionFOV					'Cfov'
#define keyContiguous						'Cntg'
#define keyContinue							'Cntn'
#define keyContinuity						'Cnty'
#define keyContrast							'Cntr'
#define keyConvert							'Cnvr'	// There is also a typeConvert.
#define keyCopy								'Cpy '
#define keyCopyright						'Cpyr'	// Property.
#define keyCopyrightNotice					'CprN'
#define keyCornerCropMarks					'CrnC'
#define keyCount							'Cnt '	// Use for count of objects.
#define keyCountryName						'CntN'
#define keyCrackBrightness					'CrcB'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyCrackDepth						'CrcD'
#define keyCrackSpacing						'CrcS'
#define keyCreateLayersFromLayerFX			'blfl'
#define keyCredit							'Crdt'
#define keyCrossover						'Crss'
#define keyCurrent							'Crnt'
#define keyCurrentHistoryState				'CrnH'
#define keyCurrentLight						'CrnL'
#define keyCurrentToolOptions				'CrnT'
#define keyCurve							'Crv '
#define keyCurveFile						'CrvF'
#define keyCustom							'Cstm'	// There is also eventCustom, enumCustomPattern. 
#define keyCustomForced						'CstF'
#define keyCustomMatte						'CstM'
#define keyCustomPalette					'CstP'
#define keyCyan								'Cyn '
#define keyDarkIntensity					'DrkI'
#define keyDarkness							'Drkn'
#define keyDateCreated						'DtCr'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyDatum							'Dt  '	// There is a struct called keyData, so we use this cute name.
#define keyDCS								'DCS '	// There is also a typeDCS.
#define keyDefinition						'Dfnt'
#define keyDensity							'Dnst'
#define keyDepth							'Dpth'	// There is also a typeDepth.
#define keyDestBlackMax						'Dstl'	// Breaks hash for destBlackMin.
#define keyDestBlackMin						'DstB'
#define keyDestinationMode					'DstM'	// for ModeChange plugin
#define keyDestWhiteMax						'Dstt'	// Breaks hash for destWhiteMin.
#define keyDestWhiteMin						'DstW'
#define keyDetail							'Dtl '
#define keyDiameter							'Dmtr'
#define keyDiffusionDither					'DffD'
#define keyDirection						'Drct'
#define keyDirectionBalance					'DrcB'
#define keyDisplaceFile						'DspF'
#define keyDisplacementMap					'DspM'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyDisplayPrefs						'DspP'
#define keyDistance							'Dstn'	// There is also a unitDistance.
#define keyDistortion						'Dstr'	// CONFLICT: keyDistribution.
#define keyDistribution						'Dstr'	// CONFLICT: keyDistortion.
#define keyDither							'Dthr'
#define keyDitherAmount						'DthA'
#define keyDitherPreserve					'Dthp'
#define keyDitherQuality					'Dthq'
#define keyDocumentID						'DocI'
#define keyDotGain							'DtGn'
#define keyDotGainCurves					'DtGC'	// Breaks hash for keyDotGain.
#define keyDPXFormat						'DPXf'
#define keyDropShadow						'DrSh'
#define keyDuplicate						'Dplc'	// There is also an eventDuplicate.
#define keyDynamicColorSliders				'DnmC'
#define keyEdge								'Edg '
#define keyEdgeBrightness					'EdgB'
#define keyEdgeFidelity						'EdgF'
#define keyEdgeIntensity					'EdgI'
#define keyEdgeSimplicity					'EdgS'
#define keyEdgeThickness					'EdgT'
#define keyEdgeWidth						'EdgW'
#define keyEffect							'Effc'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyEmbedProfiles					'EmbP'
#define keyEmbedCMYK						'EmbC'
#define keyEmbedGray						'EmbG'
#define keyEmbedLab							'EmbL'
#define keyEmbedRGB							'EmbR'
#define keyEmulsionDown						'EmlD'
#define keyEnabled							'enab'
#define keyEnableGestures					'EGst'
#define keyEncoding							'Encd'
#define keyEnd								'End '
#define keyEndArrowhead						'EndA'
#define keyEndRamp							'EndR'
#define keyEndSustain						'EndS'
#define keyEngine							'Engn'
#define keyEraserKind						'ErsK'	// There is also a typeEraserKind
#define keyEraseToHistory					'ErsT'
#define keyExactPoints						'ExcP'
#define keyExport							'Expr'	// There is also a classExport.
#define keyExportClipboard					'ExpC'
#define keyExposure							'Exps'
#define keyExtend							'Extd'
#define keyExtension						'Extn'
#define keyExtensionsQuery					'ExtQ'
#define keyExtrudeDepth						'ExtD'
#define keyExtrudeMaskIncomplete			'ExtM'
#define keyExtrudeRandom					'ExtR'	// There is also a typeExtrudeRandom.
#define keyExtrudeSize						'ExtS'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyExtrudeSolidFace					'ExtF'
#define keyExtrudeType						'ExtT'	// There is also a typeExtrudeType.
#define keyEyeDropperSample					'EyDr'
#define keyFadeoutSteps						'FdtS'
#define keyFadeTo							'FdT '
#define keyFalloff							'FlOf'
#define keyFPXCompress						'FxCm'	// There is also a typeFPXCompress. Breaks hash.
#define keyFPXQuality						'FxQl'	// Breaks hash.
#define keyFPXSize							'FxSz'	// Breaks hash.
#define keyFPXView							'FxVw'	// Breaks hash.
#define keyFeather							'Fthr'
#define keyFiberLength						'FbrL'
#define keyFile								'File'
#define keyFileCreator						'FlCr'
#define keyFileInfo							'FlIn'
#define keyFileReference					'FilR'
#define keyFileSavePrefs					'FlSP'
#define keyFilesList						'flst'
#define keyFileType							'FlTy'
#define keyFill								'Fl  '	// There is also typeFill, eventFIll.
#define keyFillColor						'FlCl'	// There is also a typeFillColor.
#define keyFillNeutral						'FlNt'
#define keyFilterLayerRandomSeed			'FlRs'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyFilterLayerPersistentData		'FlPd'
#define keyFingerpainting					'Fngr'
#define keyFlareCenter						'FlrC'
#define keyFlatness							'Fltn'
#define keyFlatten							'Fltt'	// Break hash for Flatness.
#define keyFlipVertical						'FlpV'
#define keyFocus							'Fcs '
#define keyFolders							'Fldr'
#define keyFontDesignAxes					'FntD'	// There is also a classFontDesignAxes
#define keyFontDesignAxesVectors			'FntV'	// Break hash for FontDesignAxes
#define keyFontName							'FntN'
#define keyFontScript						'Scrp'	// was keyScript; conflicts with <Navigation.h>.
#define keyFontStyleName					'FntS'
#define keyFontTechnology					'FntT'
#define keyForcedColors						'FrcC'
#define keyForegroundColor					'FrgC'
#define keyForegroundLevel					'FrgL'
#define keyFormat							'Fmt '	// There is also a classFormat.
#define keyForward							'Fwd '	// Points in a path.
#define keyFrameFX							'FrFX'
#define keyFrameWidth						'FrmW'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyFreeTransformCenterState			'FTcs'
#define keyFrequency						'Frqn'
#define keyFrom								'From'
#define keyFromBuiltin						'FrmB'
#define keyFromMode							'FrmM'
#define keyFunctionKey						'FncK'
#define keyFuzziness						'Fzns'
#define keyGamutWarning						'GmtW'
#define keyGCR								'GCR '
#define keyGeneralPrefs						'GnrP'
#define keyGIFColorFileType					'GFPT'	// There is also a typeGIFColorFileType.
#define keyGIFColorLimit					'GFCL'
#define keyGIFExportCaption					'GFEC'
#define keyGIFMaskChannelIndex				'GFMI'
#define keyGIFMaskChannelInverted			'GFMV'
#define keyGIFPaletteFile					'GFPF'
#define keyGIFPaletteType					'GFPL'	// There is also a typeGIFPaletteType.
#define keyGIFRequiredColorSpaceType		'GFCS'	// There is also a typeGIFRequiredColorSpaceType.
#define keyGIFRowOrderType					'GFIT'	// There is also a typeGIFRowOrderType.
#define keyGIFTransparentColor				'GFTC'
#define keyGIFTransparentIndexBlue			'GFTB'
#define keyGIFTransparentIndexGreen			'GFTG'
#define keyGIFTransparentIndexRed			'GFTR'
#define keyGIFUseBestMatch					'GFBM'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyGamma							'Gmm '
#define keyGlobalAngle						'gblA'
#define keyGlobalLightingAngle				'gagl'
#define keyGloss							'Glos'	// Breaks hash.
#define keyGlowAmount						'GlwA'
#define keyGlowTechnique					'GlwT'
#define keyGradient							'Grad'
#define keyGradientFill						'Grdf'
#define keyGrain							'Grn '	// CONFLICT: keyGreen.
#define keyGrainType						'Grnt'
#define keyGraininess						'Grns'
#define keyGray								'Gry '	// There is also an enumGray.
#define keyGrayBehavior						'GrBh'
#define keyGraySetup						'GrSt'
#define keyGreen							'Grn '	// There is also an enumGreen. CONFLICT: keyGrain.
#define keyGreenBlackPoint					'GrnB'
#define keyGreenGamma						'GrnG'
#define keyGreenWhitePoint					'GrnW'
#define keyGreenX							'GrnX'
#define keyGreenY							'GrnY'
#define keyGridColor						'GrdC'
#define keyGridCustomColor					'Grds'	// Collides with keyGridColor
#define keyGridMajor						'GrdM'	// Property.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyGridMinor						'Grdn'	// Property. Breaks hash.
#define keyGridStyle						'GrdS'
#define keyGridUnits						'Grdt'	// Collides with keyGridMinor
#define keyGroup							'Grup'
#define keyGroutWidth						'GrtW'
#define keyGrowSelection					'GrwS'
#define keyGuides							'Gdes'	// Property.
#define keyGuidesColor						'GdsC'
#define keyGuidesCustomColor				'Gdss'	// Collides with keyGuidesColor
#define keyGuidesStyle						'GdsS'
#define keyGuidesPrefs						'GdPr'
#define keyGutterWidth						'GttW'
#define keyHalftoneFile						'HlfF'
#define keyHalftoneScreen					'HlfS'	// There is also eventHalftoneScreen, enumHalftoneScreen, classHalftoneScreen.
#define keyHalftoneSpec						'Hlfp'	// Collides with keyHalftoneScreen
#define keyHalftoneSize						'HlSz'	// Breaks hash.
#define keyHardness							'Hrdn'
#define keyHasCmdHPreference				'HCdH'
#define keyHeader							'Hdr '
#define keyHeadline							'Hdln'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyHeight							'Hght'
#define keyHostName							'HstN'
#define keyHighlightArea					'HghA'
#define keyHighlightColor					'hglC'
#define keyHighlightLevels					'HghL'
#define keyHighlightMode					'hglM'
#define keyHighlightOpacity					'hglO'
#define keyHighlightStrength				'HghS'
#define keyHistoryBrushSource				'HstB'
#define keyHistoryPrefs						'HstP'	// History prefs.
#define keyHistoryStateSource				'HsSS'
#define keyHistoryStates					'HsSt'
#define keyHorizontal						'Hrzn'	// There is also an enumHorizontal.
#define keyHorizontalScale					'HrzS'
#define keyHostVersion						'HstV'
#define keyHue								'H   '
#define keyICCEngine						'ICCE'
#define keyICCSetupName						'ICCt'	// Breaks hash for keyICCSetupSource.
#define keyID								'Idnt'	// Breaks hash to match formIndentifier.
#define keyIdle								'Idle'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyImageBalance 					'ImgB'
#define keyImport							'Impr'	// There is also a classImport.
#define keyImpressionist					'Imps'
#define keyIn								'In  '
#define keyInherits							'c@#^'	// Hey, Apple defined it!
#define keyInkColors						'InkC'
#define keyInks								'Inks'
#define keyInnerGlow						'IrGl'
#define keyInnerGlowSource					'glwS'
#define keyInnerShadow						'IrSh'
#define keyInput							'Inpt'
#define keyInputBlackPoint					'kIBP'
#define keyInputMapRange					'Inmr'
#define keyInputRange						'Inpr'
#define keyInputWhitePoint					'kIWP'
#define keyIntensity						'Intn'
#define keyIntent							'Inte'	// Breaks hash for keyIntensity.
#define keyInterfaceBevelHighlight			'IntH'	// classInterfaceColor. Breaks hash.
#define keyInterfaceBevelShadow				'Intv'	// classInterfaceColor. Breaks hash.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyInterfaceBlack					'IntB'	// classInterfaceColor.
#define keyInterfaceBorder					'Intd'	// classInterfaceColor. Breaks hash.
#define keyInterfaceButtonDarkShadow		'Intk'	// classInterfaceColor. Breaks hash.
#define keyInterfaceButtonDownFill			'Intt'	// classInterfaceColor.
#define keyInterfaceButtonUpFill			'InBF'	// classInterfaceColor. Breaks hash.
#define keyInterfaceColorBlue2				'ICBL'	// classInterfaceColor. Breaks hash.
#define keyInterfaceColorBlue32				'ICBH'	// classInterfaceColor. Breaks hash.
#define keyInterfaceColorGreen2				'ICGL'	// classInterfaceColor. Breaks hash.
#define keyInterfaceColorGreen32			'ICGH'	// classInterfaceColor. Breaks hash.
#define keyInterfaceColorRed2				'ICRL'	// classInterfaceColor. Breaks hash for InterfaceColorRedLow.
#define keyInterfaceColorRed32				'ICRH'	// classInterfaceColor. Breaks hash for InterfaceColorRedHigh.
#define keyInterfaceIconFillActive			'IntI'	// classInterfaceColor.
#define keyInterfaceIconFillDimmed			'IntF'	// classInterfaceColor. Breaks hash.
#define keyInterfaceIconFillSelected		'Intc'	// classInterfaceColor.
#define keyInterfaceIconFrameActive			'Intm'	// classInterfaceColor. Breaks hash.
#define keyInterfaceIconFrameDimmed			'Intr'	// classInterfaceColor. Breaks hash.
#define keyInterfaceIconFrameSelected		'IntS'	// classInterfaceColor. Breaks hash.
#define keyInterfacePaletteFill				'IntP'	// classInterfaceColor.
#define keyInterfaceRed						'IntR'	// classInterfaceColor.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyInterfaceWhite					'IntW'	// classInterfaceColor.
#define keyInterfaceToolTipBackground		'IntT'	// classInterfaceColor.
#define keyInterfaceToolTipText				'ITTT'	// classInterfaceColor. Breaks hash
#define keyInterfaceTransparencyForeground	'ITFg'	// classInterfaceColor.
#define keyInterfaceTransparencyBackground	'ITBg'	// classInterfaceColor.
#define keyInterlace						'Intr'	// CONFLICT: keyInterpolation.
#define keyInterlaceCreateType				'IntC'	// There is also a typeInterlaceCreateType.
#define keyInterlaceEliminateType			'IntE'	// There is also a typeInterlaceEliminateType.
#define keyInterpolation					'Intr'	// CONFLICT: keyInterlace.
#define keyInterpolationMethod				'IntM'	// Property.
#define keyInvert							'Invr'
#define keyInvertMask						'InvM'
#define keyInvertSource2					'InvS'
#define keyInvertTexture					'InvT'
#define keyIsDirty							'IsDr'	// Has the document changed since last save (or open)?
#define keyItemIndex						'ItmI'	// Actions palette classAction, classActionSet. Can't use keyIndex, that's reserved.
#define keyJPEGQuality						'JPEQ'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyKerning							'Krng'
#define keyKeywords							'Kywd'
#define keyKind								'Knd '
#define keyLZWCompression					'LZWC'
#define keyLabels							'Lbls'
#define keyLandscape						'Lnds'
#define keyLastTransform					'LstT'
#define keyLayerEffects						'Lefx'
#define keyLayerFXVisible					'lfxv'
#define keyLayer							'Lyr '	// Was kLayerKeyword.
#define keyLayerID							'LyrI'
#define keyLayerName						'LyrN'
#define keyLayers							'Lyrs'
#define keyLeading							'Ldng'
#define keyLeft								'Left'
//#define keyLength                           'Lngt'	// HFS extents also have a keyLength. Don't define this, use keyTermLength instead.
#define keyTermLength						'Lngt'		// NOTE: This used to be keyLength, but was changed to avoid conflicts with PDFL.
#define keyLens								'Lns '
#define keyLevel							'Lvl '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyLevels							'Lvls'
#define keyLightDark						'LgDr'	// Breaks hash.
#define keyLightDirection					'LghD'
#define keyLightIntensity					'LghI'
#define keyLightPosition					'LghP'
#define keyLightSource						'LghS'	// There is also a classLightSource.
#define keyLightType						'LghT'
#define keyLightenGrout						'LghG'
#define keyLightness						'Lght'
#define keyLine								'Line'
#define keyLinkedLayerIDs					'LnkL'
#define keyLocalLightingAngle				'lagl'
#define keyLocalLightingAltitude			'Lald'
#define keyLocalRange						'LclR'
#define keyLocation							'Lctn'
#define keyLog								'Log '	// From UBatchTerminology.
#define keyLogarithmic						'kLog'
#define keyLowerCase						'LwCs'
#define keyLuminance						'Lmnc'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyLUTAnimation						'LTnm'
#define keyMagenta							'Mgnt'
#define keyMakeVisible						'MkVs'
#define keyManipulationFOV					'Mfov'
#define keyMapBlack							'MpBl'
#define keyMapping							'Mpng'
#define keyMappingShape						'MpgS'
#define keyMaterial							'Mtrl'
#define keyMatrix							'Mtrx'
#define keyMatteColor						'MttC'
#define keyMaximum							'Mxm '	// There is also a keyMaximumQuality, eventMaximum.
#define keyMaximumStates					'MxmS'	// History prefs.
#define keyMemoryUsagePercent				'MmrU'
#define keyMerge							'Mrge'
#define keyMerged							'Mrgd'
#define keyMessage							'Msge'
#define keyMethod							'Mthd'
#define keyMezzotintType					'MztT'	// There is also a typeMezzotintType.
#define keyMidpoint							'Mdpn'
#define keyMidtoneLevels					'MdtL'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyMinimum							'Mnm '	// There is also an eventMinimum.
#define keyMismatchCMYK						'MsmC'
#define keyMismatchGray						'MsmG'
#define keyMismatchRGB						'MsmR'
#define keyMode								'Md  '	// There is also a classMode, typeMode.
#define keyMonochromatic					'Mnch'
#define keyMoveTo							'MvT '
#define keyName							    'Nm  '	// NOTE: This used to be keyName, but was changed to avoid conflicts with PDFL.
#define keyNegative							'Ngtv'
#define keyNew								'Nw  '	// Was kNewKeyword.
#define keyNoise							'Nose'
#define keyNonImageData						'NnIm'
#define keyNonLinear						'NnLn'	// History prefs.
#define keyNull								'null'
#define keyNumLights						'Nm L'
#define keyNumber							'Nmbr'
#define	keyNumberOfCacheLevels				'NCch'
#define	keyNumberOfCacheLevels64			'NC64'
#define keyNumberOfChannels					'NmbO'	// Property.
#define keyNumberOfChildren					'NmbC'	// Actions palette classAction, classActionSet.
#define keyNumberOfDocuments				'NmbD'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyNumberOfGenerators				'NmbG'
#define keyNumberOfLayers					'NmbL'	// CONFLICT: keyNumberOfLevels.
#define keyNumberOfLevels					'NmbL'	// CONFLICT: keyNumberOfLayers.
#define keyNumberOfPaths					'NmbP'	// Property.
#define keyNumberOfRipples					'NmbR'
#define keyNumberOfSiblings					'NmbS'	// Actions palette classAction, classActionSet.
#define keyObjectName						'ObjN'
#define keyOffset							'Ofst'	// There is also classOffset, eventOffset.
#define keyOn								'On  '
#define keyOpacity							'Opct'
#define keyOptimized						'Optm'
#define keyOrientation						'Ornt'
#define keyOriginalHeader					'OrgH'
#define keyOriginalTransmissionReference	'OrgT'
#define keyOtherCursors						'OthC'
#define keyOuterGlow						'OrGl'
#define keyOutput							'Otpt'
#define keyOutputBlackPoint					'kOBP'
#define keyOutputWhitePoint					'kOWP'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyOverprintColors					'OvrC'
#define keyOverrideOpen						'OvrO'
#define keyOverridePrinter					'ObrP'
#define keyOverrideSave						'Ovrd'	// Breaks hash for compatibility (used to be called override).
//#define keyPaintStroke						'PntS'	// Paint stroke recording deleted for 6.0
#define keyPaintCursorKind					'PnCK'
#define keyParentIndex						'PrIn'	// Actions palette classAction, classActionSet.
#define keyParentName						'PrNm'	// Actions palette classAction, classActionSet.
#define keyPNGFilter						'PNGf'	// There is also a typePNGFilter.
#define keyPNGInterlaceType					'PGIT'	// There is also a typePNGInterlaceType. Breaks hash.
#define keyPageFormat						'PMpf'	// Carbon PrintManager PageFormat.
#define keyPageNumber						'PgNm'
#define keyPageSetup						'PgSt'
#define keyPagePosition						'PgPs'	// There is also a typePagePosition.
#define keyPaintingCursors					'PntC'
#define keyPaintType						'PntT'
#define keyPalette							'Plt '
#define keyPaletteFile						'PltF'
#define keyPaperBrightness					'PprB'
#define PSkeyPath								'Path'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyPathContents						'PthC'	// Property.
#define keyPathName							'PthN'	// Property.
#define keyPattern							'Pttn'
#define keyPencilWidth						'Pncl'
#define keyPerspectiveIndex					'Prsp'
#define keyPhosphors						'Phsp'
#define keyPickerID							'PckI'
#define keyPickerKind						'Pckr'	// There is also a typePickerKind.
#define keyPixelPaintSize					'PPSz'	// There is also a typePixelPaintSize. Breaks hash.
#define keyPlatform							'Pltf'	// There is also a typePlatform.
#define keyPluginFolder						'PlgF'
#define keyPluginPrefs						'PlgP'
#define keyPoints							'Pts '
#define keyPosition							'Pstn'
#define keyPosterization					'Pstr'
#define keyPostScriptColor					'PstS'
#define keyPredefinedColors					'PrdC'
#define keyPreferBuiltin					'PrfB'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyPreserveAdditional				'PrsA'
#define keyPreserveLuminosity				'PrsL'
#define keyPreserveTransparency				'PrsT'
#define keyPressure							'Prs '
#define keyPreferences						'Prfr'
#define keyPreview							'Prvw'	// There is also a typePreview.
#define keyPreviewCMYK						'PrvK'
#define keyPreviewFullSize					'PrvF'
#define keyPreviewIcon						'PrvI'
#define keyPreviewMacThumbnail				'PrvM'
#define keyPreviewWinThumbnail				'PrvW'
#define keyPreviewsQuery					'PrvQ'
#define keyPrintSettings					'PMps'	// Carbon PrintManager PrintSettings, but also CPrintOption in an action
#define keyProfileSetup						'PrfS'
#define keyProvinceState					'PrvS'
#define keyQuality							'Qlty'	// There is also a typeQuality.
#define keyExtendedQuality					'EQlt'	// There is also a typeQuality.
#define keyQuickMask						'QucM'	// Property.
#define keyRGBSetup							'RGBS'
#define keyRadius							'Rds '
#define keyRandomSeed						'RndS'
#define keyRatio							'Rt  '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyRecentFiles						'Rcnf'
#define keyRed								'Rd  '	// There is also an enumRed.
#define keyRedBlackPoint					'RdBl'
#define keyRedGamma							'RdGm'
#define keyRedWhitePoint					'RdWh'
#define keyRedX								'RdX '
#define keyRedY								'RdY '
#define keyRegistrationMarks				'RgsM'
#define keyRelative							'Rltv'
#define keyRelief							'Rlf '
#define keyRenderFidelity					'Rfid'	// Is of typeAmount.
#define keyResample							'Rsmp'
#define keyResizeWindowsOnZoom				'RWOZ'
#define keyResolution						'Rslt'
#define keyResourceID						'RsrI'
#define keyResponse							'Rspn'
#define keyRetainHeader						'RtnH'
#define keyReverse							'Rvrs'
#define keyRight							'Rght'
#define keyRippleMagnitude					'RplM'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyRippleSize						'RplS'	// There is also a typeRippleSize.
#define keyRotate							'Rtt '
#define keyRoundness						'Rndn'
#define keyRulerOriginH						'RlrH'	// Property. Breaks hash.
#define keyRulerOriginV						'RlrV'	// Property. Breaks hash.
#define keyRulerUnits						'RlrU'	// Property.
#define keySaturation						'Strt'
#define keySaveAndClose						'SvAn'
#define keySaveComposite					'SvCm'
#define keySavePaletteLocations				'PltL'
#define keySavePaths						'SvPt'
#define keySavePyramids						'SvPy'
#define keySaving							'Svng'
#define keyScale							'Scl '	// There is also an enumScale.
#define keyScaleHorizontal					'SclH'
#define keyScaleVertical					'SclV'
#define keyScaling							'Scln'
#define keyScans							'Scns'
#define keyScratchDisks						'ScrD'
#define keyScreenFile						'ScrF'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyScreenType						'ScrT'
#define keyShadingIntensity					'ShdI'
#define keyShadingNoise						'ShdN'
#define keyShadingShape						'ShdS'
#define keyContourType						'ShpC'
#define keySerialString						'SrlS'	// Property.
#define keySeparations						'Sprt'
#define keyShadowColor						'sdwC'
#define keyShadowIntensity					'ShdI'
#define keyShadowLevels						'ShdL'
#define keyShadowMode						'sdwM'
#define keyShadowOpacity					'sdwO'
#define keyShape							'Shp '
#define keySharpness						'Shrp'
#define keyShearEd							'ShrE'
#define keyShearPoints						'ShrP'
#define keyShearSt							'ShrS'
#define keyShiftKey							'ShfK'
#define keyShiftKeyToolSwitch				'ShKT'
#define keyShortNames						'ShrN'
#define keyShowEnglishFontNames				'ShwE'
#define keyShowToolTips						'ShwT'
#define keyShowTransparency					'ShTr'	// classGradient
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keySizeKey							'Sz  '
#define keySkew								'Skew'
#define keySmartBlurMode					'SmBM'	// There is also a typeSmartBlurMode.
#define keySmartBlurQuality					'SmBQ'	// There is also a typeSmartBlurQuality.
#define keySmooth							'Smoo'
#define keySmoothness						'Smth'
#define keySnapshotInitial					'SnpI'	// History prefs.
#define keySoftClip							'SfCl'
#define keySoftness							'Sftn'
#define keySmallFontType					'Sfts'
#define keyOldSmallFontType					'Sftt'
#define keySolidFill						'SoFi'
#define keySource							'Srce'
#define keySource2							'Src2'
#define keySourceMode						'SrcM'	// for ModeChange plugin
#define keySpacing							'Spcn'
#define keySpecialInstructions				'SpcI'
#define keySpherizeMode						'SphM'	// There is also a typeSpherizeMode.
#define keySpot								'Spot'	// Collides with keySpatter
#define keySprayRadius						'SprR'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keySquareSize						'SqrS'
#define keySrcBlackMax						'Srcl'	// Breaks hash for srcBlackMin.
#define keySrcBlackMin						'SrcB'
#define keySrcWhiteMax						'Srcm'	// Breaks hash for srcWhiteMin.
#define keySrcWhiteMin						'SrcW'
#define keyStart							'Strt'
#define keyStartArrowhead					'StrA'
#define keyState							'Stte'
#define keyStrength							'srgh'	// From UActionsTerminology. CONFLICTS: keyStrength ('Strg').
#define keyStrengthRatio					'srgR'
#define keyStrength_PLUGIN					'Strg'	// From AdobePITerminology. CONFLICTS: keyStrength ('srgh').
#define keyStrokeDetail						'StDt'
#define keyStrokeDirection					'SDir'	// Breaks hash.
#define keyStrokeLength						'StrL'
#define keyStrokePressure					'StrP'
#define keyStrokeSize						'StrS'
#define keyStrokeWidth						'StrW'
#define keyStyle							'Styl'
#define keyStyles							'Stys'
#define keyStylusIsPressure					'StlP'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyStylusIsColor					'StlC'
#define keyStylusIsOpacity					'StlO'
#define keyStylusIsSize						'StlS'
#define keySubPathList						'SbpL'
#define keySupplementalCategories			'SplC'
#define keySystemInfo						'SstI'
#define keySystemPalette					'SstP'
#define keyTarget							'null'
#define keyTargetPath						'Trgp'	// There is also an enumTargetPath.
#define keyTargetPathIndex					'TrgP'	// Property.
#define keyText								'Txt '
#define keyTextClickPoint					'TxtC'
#define keyTextData							'TxtD'
#define keyTextStyle						'TxtS'
#define keyTextStyleRange					'Txtt'	// Collides with keyTextStyle
#define keyTexture							'Txtr'
#define keyTextureCoverage					'TxtC'	// CONFLICT: keyTextClickPoint.
#define keyTextureFile						'TxtF'
#define keyTextureType						'TxtT'
#define keyThreshold						'Thsh'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyTileNumber						'TlNm'
#define keyTileOffset						'TlOf'
#define keyTileSize							'TlSz'
#define keyTitle							'Ttl '	// Property.
#define keyTo								'T   '
#define keyToBuiltin						'TBl '
#define keyToLinked							'ToLk'
#define keyToMode							'TMd '
#define keyToggleOthers						'TglO'
#define keyTolerance						'Tlrn'
#define keyTop								'Top '
#define keyTotalLimit						'TtlL'
#define keyTracking							'Trck'
#define keyTransferSpec						'TrnS'
#define keyTransparencyGrid					'TrnG'
#define keyTransferFunction					'TrnF'
#define keyTransparency						'Trns'
#define keyTransparencyGridColors			'TrnC'
#define keyTransparencyGridSize				'TrnG'
#define keyTransparencyPrefs				'TrnP'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyTransparencyShape				'TrnS'
#define keyTransparentIndex					'TrnI'
#define keyTransparentWhites				'TrnW'
#define keyTwist							'Twst'
#define keyType								'Type'
#define keyUCA								'UC  '
#define keyUIScaleType						'UIsc'
#define keyUnitsPrefs						'UntP'
#define keyURL								'URL '	// Property.
#define keyUndefinedArea					'UndA'
#define keyUnderline						'Undl'
#define keyUntitled							'Untl'
#define keyUpperY							'UppY'
#define keyUrgency							'Urgn'
#define keyUseAccurateScreens				'AcrS'
#define keyUseAdditionalPlugins				'AdPl'
#define	keyUseCacheForHistograms			'UsCc'
#define keyUseCurves						'UsCr'
#define keyUseDefault						'UsDf'
#define keyUseGlobalAngle					'uglg'
#define keyUseICCProfile					'UsIC'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyUseMask							'UsMs'
#define keyUserMaskEnabled					'UsrM'
#define keyUserMaskLinked					'Usrs'	// Breaks hash for userMaskEnabled.
#define keyLinkEnable						'lnkE'
#define keyUsing							'Usng'
#define keyValue							'Vl  '
#define keyVariance							'Vrnc'
#define keyVector0							'Vct0'
#define keyVector1							'Vct1'
#define keyVectorColor						'VctC'	// classGradient
#define keyVersionFix						'VrsF'	// classVersion.
#define keyVersionMajor						'VrsM'	// classVersion.
#define keyVersionMinor						'VrsN'	// classVersion.
#define keyVertical							'Vrtc'
#define keyVerticalScale					'VrtS'
#define keyVideoAlpha						'Vdlp'
#define keyVisible							'Vsbl'
#define keyWatchSuspension					'WtcS'	// Property.
#define keyWatermark						'watr'	// Property.
#define keyWaveType							'Wvtp'
#define keyWavelengthMax					'WLMx'	// Breaks hash.
#define keyWavelengthMin					'WLMn'	// Breaks hash.
#define keyWebdavPrefs						'WbdP'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyWetEdges							'Wtdg'
#define keyWhat								'What' // PR#17472
#define keyWhiteClip						'WhtC'
#define keyWhiteIntensity					'WhtI'
#define keyWhiteIsHigh						'WhHi'	// Breaks hash.
#define keyWhiteLevel						'WhtL'
#define keyWhitePoint						'WhtP'
#define keyWholePath						'WhPt'
#define keyWidth							'Wdth'
#define keyWindMethod						'WndM'
#define keyWith								'With'
#define keyWorkPath							'WrPt'
#define keyWorkPathIndex					'WrkP'	// Property. There is also enumWorkPath.
#define keyX								'X   '
#define keyY								'Y   '
#define keyYellow							'Ylw '
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define keyZigZagType						'ZZTy'	// There is also a typeZigZagType. Breaks hash.

#define keyLighter							'Ligh'   //rkulkarn
#define keyDarker							'Dark'	//rkulkarn
#define keyStartUpInPrefs					'Stup'	

#define keyLegacySerialString				'lSNs'

#define key_Source							keyTo

//-------------------------------------------------------------------------------
//	Special inheritance property.
//-------------------------------------------------------------------------------
#ifndef pInherits 
#ifdef WIN32
#define pInherits	'c@#^'	// This is the inheritance property. It is documented in develop 21.
#endif
#endif

//-------------------------------------------------------------------------------
//	Types.	
//-------------------------------------------------------------------------------
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeActionReference				'#Act'
#define typeActionData					'ActD'
#define typeAlignDistributeSelector		'ADSt'	// enumADSTops, enumADSCentersV, enumADSBottoms, enumADSVertical, enumADSLefts, enumADSCentersH, enumADSRights, enumADSHorizontal, enumADSSpacingH, enumADSSpacingV. 
#define typeAlignment					'Alg '	// enumLeft, enumCenter, enumRight, enumJustifyFull, enumJustifyAll.
#define typeAmount						'Amnt'	// There is also a keyAmount. enumAmountLow, enumAmountMedium, enumAmountHigh.
#define typeAntiAlias					'Annt'	// enumAntiAliasNone, enumAntiAliasLow, enumAntiAliasMedium, enumAntiAliasHigh.
#define typeAreaSelector				'ArSl'	// enumSelection, enumImage.
#define typeAssumeOptions				'AssO'	// enumNone, enumAskWhenOpening, enumMonitor, enumBuiltin, enumICC.
#define typeBevelEmbossStampStyle		'BESs'	// enumStampIn, enumStampOut.
#define typeBevelEmbossStyle			'BESl'	// enumOuterBevel, enumInnerBevel, enumEmboss, enumPillowEmboss.
#define typeBitDepth					'BtDp'	// There is also a keyBitDepth. enumBitDepth1, enumBitDepth4, enumBitDepth8, enumBitDepth24.
#define typeBlackGeneration				'BlcG'	// enumNone, enumLight, enumMedium ('Mdim'), enumHeavy, enumMaximum.
#define typeBlendMode					'BlnM'	// enumNormal, enumDissolve, enumBehind, enumClear, enumMultiply, enumScreen, enumOverlay, enumSoftLight, enumHardLight, enumDarken, enumLighten, enumDifference, enumHue, enumSaturation, enumColor, enumLuminosity, enumExclusion, enumColorDodge, enumColorBurn.
#define typeBlurMethod  				'BlrM'	// There is also a keyBlurMethod. enumSpin.
#define typeBlurQuality 				'BlrQ'	// There is also a keyBlurQuality. enumDraft, enumGood, enumBest.
#define typeBrushType					'BrsT'	// enumBrushSimple, enumBrushLightRough, enumBrushDarkRough, enumBrushWideSharp, enumBrushWideBlurry.
#define typeBuiltinProfile				'BltP'	// enumAppleRGB, enumSRGB, enumCIERGB, enumNTSC, enumPalSecam, enumAdobeRGB1998, enumSMPTEC, enumGray18, enumGray22. 
#define typeBuiltInContour				'BltC'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeCMYKSetupEngine				'CMYE'	// enumBuiltin, enumICC, enumTables.
#define typeCalculation					'Clcn'	// enumNormal, enumMultiply, enumScreen, enumOverlay, enumSoftLight, enumHardLight, enumDarken, enumLighten, enumDifference, enumExclusion, enumColorDodge, enumColorBurn, enumAdd, enumSubtract.
#define typeChannel						'Chnl'	// enumBlack, enumCMYK, enumRGB, enumLab, enumRed, enumGreen, enumCyan, enumLightness, enumBlue, enumMagenta, enumYellow, enumA, enumB, enumComposite, enumMask, enumMonotone, enumDuotone, enumTritone, enumQuadtone, enumTransparency.
#define typeChannelReference			'#ChR'
#define typeCheckerboardSize			'Chck'	// enumCheckerboardNone, enumCheckerboardSmall, enumCheckerboardMedium, enumCheckerboardLarge
#define typeClass						typeType
#define typeClassColor					'#Clr'
#define typeClassElement				'#ClE'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeClassExport					'#Cle'	// CONFLICTS: typeClassElement. Changed '#ClE' -> '#Cle'. Specifies multiple types.  Read Develop 21 for more info. CONFLICT: typeClassElement.
#define typeClassFormat					'#ClF'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeClassHueSatHueSatV2			'#HsV'
#define typeClassImport					'#ClI'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeClassMode					'#ClM'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeClassStringFormat			'#ClS'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeClassTextExport				'#CTE'	// Breaks hash.
#define typeClassTextImport				'#ClT'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeColor						'Clr ' 	// enumRed, enumOrange, enumYellowColor, enumGreen, enumBlue, enumViolet, enumGray.
#define typeColorChannel				'#ClC' 	// Specifies multiple types.  Read Develop 21 for more info.
#define typeColorPalette				'ClrP'	// enumExact, enumWeb, enumUniform, enumAdaptive, enumPerceptual, enumSelective, enumMasterAdaptive, enumMasterPerceptual, enumMasterSeletive, enumPrevious, enumSpectrum, enumGrayscale, enumBlackBody, enumMacintoshSystem, enumWindowsSystem.
#define typeColorSpace					'ClrS'	// enumGrayscale, enumRGBColor, enumCMYKColor, enumLabColor, enumBitmap, enumGrayScale, enumGray16, enumIndexedColor, enumRGB48, enumCMYK64, enumHSLColor, enumHSBColor, enumMultichannel, enumLab48.
#define typeColorStopType				'Clry'	// enumForegroundColor, enumBackgroundColor, enumUserStop.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeColors						'Clrs'	// enumReds, enumYellows, enumGreens, enumCyans, enumBlues, enumMagentas, enumWhites, enumNeutrals, enumBlacks, enumHighlights, enumMidtones, enumShadows, enumOutOfGamut.
#define typeCompensation				'Cmpn'	// enumNone, enumBuiltin.
#define typeContourEdge					'CntE'	// enumUpper, enumLower.
#define typeConvert						'Cnvr'	// There is also a keyConvert. enumRectToPolar, enumPolarToRect.
#define typeCorrectionMethod			'CrcM'	// enumRelative, enumAbsolute.
#define typeCursorKind					'CrsK'	// enumStandard, enumPrecise, enumBrushSize
#define typeDCS							'DCS '	// enumSingleNoCompositePS, enumSingle72Gray, enumSingle72Color, enumMultiNoCompositePS, enumMulti72Gray, enumMulti72Color, enumNoCompositePS, enum72Gray, enum72Color. There is also a keyDCS.
#define typeDeepDepth					'DpDp'	// enum2BitsPerPixel, enum4BitsPerPixel, enum8BitsPerPixel, enum16BitsPerPixel, enum32BitsPerPixel.
#define typeDepth						'Dpth'	// enum1BitPerPixel, enum8BitsPerPixel. There is also a keyDepth.
#define typeDiffuseMode					'DfsM'	// enumNormal, enumLightenOnly, enumDarkenOnly.
#define typeDirection					'Drct'	// enumLeft, enumRight.
#define typeDisplacementMap				'DspM'	// enumStretchToFit, enumTile.
#define typeDistribution				'Dstr'	// enumUniformDistribution, enumGaussianDistribution.
#define typeDither						'Dthr'	// enumPattern, enumDiffusion.
#define typeDitherQuality				'Dthq'	// enumBetter, enumFaster.
#define typeDocumentReference			'#DcR'
#define typeEPSPreview					'EPSP'	// enumTIFF, enumMacintosh.
#define typeElementReference			'#ElR'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeEncoding					'Encd'	// enumASCII, enumBinary, enumJPEG, enumZip.
#define typeEraserKind					'ErsK'	// There is also a keyEraserKind
#define typeExtrudeRandom				'ExtR'	// There is also a keyExtrudeRandom. enumRandom, enumLevelBased.
#define typeExtrudeType 				'ExtT'	// There is also a keyExtrudeType. enumBlocks, enumPyramids.
#define typeEyeDropperSample			'EyDp'	// enumSamplePoint, enumSample3x3, enumSample5x5.
#define typeFPXCompress 				'FxCm'	// There is also a keyFPXCompress. Breaks hash. enumFPXCompressNone, enumFPXCompressLossyJPEG.
#define typeFill						'Fl  '	// enumWhite, enumBackgroundColor, enumTransparent. There is also keyFill, eventFill.
#define typeFillColor					'FlCl'	// There is also a keyFillColor. enumFillBack, enumFillFore, enumFillInverse, enumFillSame.
#define typeFillContents				'FlCn'	// enumForegroundColor, enumBackgroundColor, enumPattern, enumSaved, enumSnapshot, enumBlack, enumWhite, enumGray.
#define typeFillMode					'FlMd'	// enumBackground, enumRepeat, enumWrap.
#define typeForcedColors				'FrcC'	// enumNone, enumBlackAndWhite, enumPrimaries, enumWeb.
#define typeFrameFill					'FrFl'
#define typeFrameStyle					'FStl'
#define typeGIFColorFileType			'GFPT'	// There is also a keyGIFColorFileType. enumGIFColorFileColors, enumGIFColorFileColorTable, enumGIFColorFileMicrosoftPalette.
#define typeGIFPaletteType				'GFPL'	// There is also a keyGIFPaletteType. enumGIFPaletteExact, enumGIFPaletteAdaptive, enumGIFPaletteSystem, enumGIFPaletteOther.
#define typeGIFRequiredColorSpaceType	'GFCS'	// There is also a keyGIFRequiredColorSpaceType. enumGIFRequiredColorSpaceRGB, enumGIFRequiredColorSpaceIndexed.
#define typeGIFRowOrderType				'GFIT'	// There is also a keyGIFRowOrderType. enumGIFRowOrderNormal, enumGIFRowOrderInterlaced.
#define typeGlobalClass					'GlbC'
#define typeGlobalObject				'GlbO'
#define typeGradientType				'GrdT'	// enumLinear, enumRadial, enumAngle, enumReflected, enumDiamond.
#define typeGradientForm				'GrdF'	// user stops or color noise
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeGrainType  					'Grnt'	// enumGrainRegular, enumGrainSoft, enumGrainSprinkles, enumGrainClumped, enumGrainContrasty, enumGrainEnlarged, enumGrainStippled, enumGrainHorizontal, enumGrainVertical, enumGrainSpeckle.
#define typeGrayBehavior				'GrBh'	// enumRGB, enumBlack.
#define typeGuideGridColor				'GdGr'	// enumCustom, enumLightBlue, enumLightRed, enumGreen, enumMediumBlue, enumYellow, enumMagenta, enumCyan, enumLightGray, enumBlack
#define typeGuideGridStyle				'GdGS'	// conflicts with typeGuideGridColor; enumLines, enumDashedLines, enumDots
#define typeHistoryStateSource			'HstS'	// enumFullDocument, enumMergedLayers, enumCurrentLayer.
#define typeHorizontalLocation			'HrzL'	// enumLeft, enumRight. 
#define typeImageReference				'#ImR'	// <Enumerated> Used as filter direct paramter.
#define typeInnerGlowSource				'IGSr'	// enumCenterGlow, enumEdgeGlow.
#define typeIntegerChannel				'#inC'
#define typeIntent						'Inte'	// enumImage, enumGraphics, enumColorimetric.
#define typeInterlaceCreateType			'IntC'	// There is also a keyInterlaceCreateType. enumCreateDuplicate, enumCreateInterpolation.
#define typeInterlaceEliminateType		'IntE'	// There is also a keyInterlaceEliminateType. enumEliminateOddFields, enumEliminateEvenFields.
#define typeInterpolation				'Intp'	// enumNearestNeighbor, enumBilinear, enumBicubic. Breaks hash for Intersect.
#define typeKelvin						'Klvn'	// enum5000, enum5500, enum6500, enum7500, enum9300, enumStdA, enumStdB, enumStdC, enumStdE.
#define typeKelvinCustomWhitePoint		'#Klv'
#define typeLens						'Lns '	// enumZoom, enumPanaVision, enumNikon, enumNikon105.
#define typeLightDirection				'LghD'	// enumLightDirBottom, enumLightDirBottomLeft, enumLightDirLeft, enumLightDirTopLeft, enumLightDirTop, enumLightDirTopRight, enumLightDirRight, enumLightDirBottomRight.
#define typeLightPosition				'LghP'	// enumLightPosBottom, enumLightPosBottomLeft, enumLightPosBottomRight, enumLightPosLeft, enumLightPosTopLeft, enumLightPosTop, enumLightPosTopRight, enumLightPosRight.
#define typeLightType					'LghT'	// enumLightDirectional, enumLightOmni, enumLightSpot.
#define typeLocationReference			'#Lct'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeMaskIndicator				'MskI'	// enumMaskedAreas, enumSelectedAreas, enumSpotColor.
#define typeMatteColor					'MttC'	// enumNone, enumForegroundColor, enumBackgroundColor, enumWhite, enumBlack, enumGray50, enumNetscapeGray
#define typeMatteTechnique				'BETE'	// enumSoftMatte, enumPreciseBevel.
#define typeMenuItem					'MnIt'	// enumAboutAp, enumPlace, enumOpenAs, enumFileInfo, enumPageSetup, ...
#define typeMethod						'Mthd'	// enumThreshold, enumPatternDither, enumDiffusionDither, enumHalftoneScreen, enumHalftoneFile, enumCustomPattern.
#define typeMezzotintType				'MztT'	// There is also a keyMezzotintType. enumFineDots, enumMediumDots, enumGrainyDots, enumCoarseDots, enumShortLines, enumMediumLines, enumLongLines, enumShortStrokes, enumMediumStrokes, enumLongStrokes.
#define typeMode						'Md  '	// enumModeGray, enumModeRGB. There is also keyMode, classMode.
#define typeNotify						'Ntfy'	// PR#17472, enumFirstIdle
#define typeObject						'Objc'
#define typeObjectReference				'obj '
#define typeOnOff						'OnOf'	// enumOn, enumOff.
#define typeOrdinal						'Ordn'	// enumAll, enumFirst, enumLast, enumNext, enumPrevious, enumMiddle, enumAny, enumNone, enumTarget, enumForward, enumBackward, enumFront, enumBack, enumMerged, enumLinked.
#define typeOrientation					'Ornt'	// enumHorizontal, enumVertical.
#define typePNGFilter					'PNGf'	// There is also a keyPNGFilter. enumPNGFilterNone, enumPNGFilterSub, enumPNGFilterUp, enumPNGFilterAverage, enumPNGFilterPaeth, enumPNGFilterAdaptive.
#define typePNGInterlaceType			'PGIT'	// There is also a keyPNGInterlaceType. Breaks hash. enumPNGInterlaceNone, enumPNGInterlaceAdam7.
#define typePagePosition				'PgPs'	// There is also a keyPagePosition. enumPagePosTopLeft, enumPagePosCentered.
#define typePathKind					'PthK'	// enumNormalPath, enumWorkPath, enumClippingPath, enumTargetPath.
#define typePathReference				'#PtR'
#define typePhosphors					'Phsp'	// enumCIERGB, enumEBUITU, enumHDTV, enumNTSC, enumP22EBU, enumAdobeRGB1998, enumSMPTEC, enumTrinitron.
#define typePhosphorsCustomPhosphors	'#Phs'
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typePickerKind					'PckK'	// enumSystemPicker, enumPhotoshopPicker, enumPluginPicker.
#define typePixelPaintSize				'PPSz'	// There is also a keyPixelPaintSize. Breaks hash. enumPixelPaintSize1, enumPixelPaintSize2, enumPixelPaintSize3, enumPixelPaintSize4.
#define typePlatform					'Pltf'	// There is also a keyPlatform. enumOS2, enumWindows, enumMacintosh, enumIBMPC.
#define typePreview						'Prvw'	// enumNone, enumIcon, enumThumbnail, enumMacThumbnail, enumWinThumbnail, enumFullSize. There is also a keyPreview.
#define typePreviewCMYK					'Prvt'	// enumPreviewOff, enumPreviewCMYK, enumPreviewCyan, enumPreviewMagenta, enumPreviewYellow, enumPreviewBlack, enumPreviewCMY
#define typeProfileMismatch				'PrfM'	// enumIgnore, enumAskWhenOpening, enumConvertToCMYK, enumConvertToRGB, enumConvertToLab, enumConvertToGray, enumKeepProfile.
#define typePurgeItem					'PrgI'	// enumClipboard, enumSnapshot, enumUndo, enumPattern, enumHistory, enumAll.
#define typeQuadCenterState				'QCSt'	// enumQCSAverage, enumQCSCorner0, enumQCSCorner1, enumQCSCorner2, enumQCSCorner3, enumQCSSide0, enumQCSSide1, enumQCSSide2, enumQCSSide3, enumQCSIndependent.
#define typeQuality						'Qlty'	// enumLowQuality, enumMediumQuality, enumHighQuality, enumMaximumQuality. There is also a typeQuality.
#define typeQueryState					'QurS'	// enumQueryAlways, enumQueryAsk, enumQueryNever
#define typeRGBSetupSource				'RGBS'	// enumCustom, enumBuiltin, enumMonitor, enumFile.
#define typeRawData						'tdta'	// same as typeData
#define typeRippleSize  				'RplS'	// There is also a keyRippleSize. enumSmall, enumMediumQuality, enumLarge.
#define typeRulerUnits					'RlrU'	// enumRulerPixels, enumRulerInches, enumRulerCm, enumRulerPoints, enumRulerPicas, enumRulerPercent.
#define typeScreenType  				'ScrT'	// enumScreenCircle, enumScreenDot, enumScreenLine.
#define typeShape						'Shp '	// enumRound, enumDiamond, enumEllipse, enumLine, enumSquare, enumCross.
#define typeSmartBlurMode				'SmBM'	// There is also a keySmartBlurMode. enumSmartBlurModeNormal, enumSmartBlurModeEdgeOnly, enumSmartBlurModeOverlayEdge.
#define typeSmartBlurQuality			'SmBQ'	// There is also a keySmartBlurQuality. enumSmartBlurQualityLow, enumSmartBlurQualityMedium, enumSmartBlurQualityHigh.
#define typeSourceMode					'Cndn'	// for ModeChange plugin
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeSpherizeMode				'SphM'	// There is also a keySpherizeMode. enumNormal, enumHorizontalOnly, enumVerticalOnly.
#define typeState						'Stte'	// enumRedrawComplete.
#define typeStringClassFormat			'#StC'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeStringChannel				'#sth'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeStringCompensation			'#Stm'	// Breaks hash for typeStringClassFormat.
#define typeStringFSS					'#Stf'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeStringInteger				'#StI'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeStrokeDirection				'StrD'	// enumStrokeDirRightDiag, enumStrokeDirHorizontal, enumStrokeDirLeftDiag, enumStrokeDirVertical.
#define typeStrokeLocation				'StrL'	// enumInside, enumOutside, enumCenter.
#define typeTermText					typeChar
#define typeTextureType 				'TxtT'	// enumTexTypeBrick, enumTextTypeBurlap, enumTextTypeCanvas, enumTexTypeSandstone, enumTexTypeBlocks, enumTexTypeFrosted, enumTexTypeTinyLens.
#define typeTransparencyGridColors		'Trnl'	// enumLight, enumMedium, enumDark, enumRed, enumOrange, enumGreen, enumBlue, enumPurple, enumCustom
#define typeTransparencyGridSize		'TrnG'	// enumNone, enumSmall, enumMedium, enumLarge
#define typeTypeClassModeOrClassMode	'#TyM'	// Specifies multiple types.  Read Develop 21 for more info.
#define typeUndefinedArea				'UndA'	// enumWrapAround, enumRepeatEdgePixels.
#define typeUnitFloat					'UntF'	// Special type for unit values.
#define typeUrgency						'Urgn'	// enumLow, enumHigh.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////
#define typeUserMaskOptions				'UsrM'	// enumHideAll, enumRevealAll, enumHideSelection, enumRevealSelection.
#define typeValueList					'VlLs'
#define typeVerticalLocation			'VrtL'	// enumTop, enumBottom.
#define typeWaveType					'Wvtp'	// enumWaveSine, enumWaveTriangle, enumWaveSquare.
#define typeWindMethod  				'WndM'	// enumWind, enumBlast, enumStagger.
#define typeYesNo						'YsN '	// enumYes, enumNo, enumAsk.
#define typeZigZagType  				'ZZTy'	// There is also a keyZigZagType. Breaks hash.

//-------------------------------------------------------------------------------
//	Units.
//-------------------------------------------------------------------------------
#define unitAngle		'#Ang'	// Unit value - base degrees
#define unitDensity		'#Rsl'	// Unit value - base per inch
#define unitDistance	'#Rlt'	// Unit value - base 72ppi
#define unitNone		'#Nne'	// Unit value - coerced.
#define unitPercent		'#Prc'	// Tagged unit value.
#define unitPixels		'#Pxl'	// Tagged unit value.
/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////

#define unitMillimeters	'#Mlm'	// Unit value used ONLY by text code
#define unitPoints		'#Pnt'	// Unit value used ONLY by text code

//-------------------------------------------------------------------------------

/////// DO NOT ADD ANYTHING HERE - SEE WARNING AT TOP OF FILE ///////////

#endif // __PITerminology_h__
