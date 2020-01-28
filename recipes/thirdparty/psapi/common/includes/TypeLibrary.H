

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for ..\winsupp\OLEActions.IDL:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0620 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __TypeLibrary_h__
#define __TypeLibrary_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActionReference_FWD_DEFINED__
#define __IActionReference_FWD_DEFINED__
typedef interface IActionReference IActionReference;

#endif 	/* __IActionReference_FWD_DEFINED__ */


#ifndef __IActionList_FWD_DEFINED__
#define __IActionList_FWD_DEFINED__
typedef interface IActionList IActionList;

#endif 	/* __IActionList_FWD_DEFINED__ */


#ifndef __IActionDescriptor_FWD_DEFINED__
#define __IActionDescriptor_FWD_DEFINED__
typedef interface IActionDescriptor IActionDescriptor;

#endif 	/* __IActionDescriptor_FWD_DEFINED__ */


#ifndef __IActionControl_FWD_DEFINED__
#define __IActionControl_FWD_DEFINED__
typedef interface IActionControl IActionControl;

#endif 	/* __IActionControl_FWD_DEFINED__ */


#ifndef __IAutoPSDoc_FWD_DEFINED__
#define __IAutoPSDoc_FWD_DEFINED__
typedef interface IAutoPSDoc IAutoPSDoc;

#endif 	/* __IAutoPSDoc_FWD_DEFINED__ */


#ifndef __IAction_FWD_DEFINED__
#define __IAction_FWD_DEFINED__
typedef interface IAction IAction;

#endif 	/* __IAction_FWD_DEFINED__ */


#ifndef __IActions_FWD_DEFINED__
#define __IActions_FWD_DEFINED__
typedef interface IActions IActions;

#endif 	/* __IActions_FWD_DEFINED__ */


#ifndef __IPhotoshopApplication_FWD_DEFINED__
#define __IPhotoshopApplication_FWD_DEFINED__
typedef interface IPhotoshopApplication IPhotoshopApplication;

#endif 	/* __IPhotoshopApplication_FWD_DEFINED__ */


#ifndef __PhotoshopApplication_FWD_DEFINED__
#define __PhotoshopApplication_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoshopApplication PhotoshopApplication;
#else
typedef struct PhotoshopApplication PhotoshopApplication;
#endif /* __cplusplus */

#endif 	/* __PhotoshopApplication_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PhotoshopTypeLibrary_LIBRARY_DEFINED__
#define __PhotoshopTypeLibrary_LIBRARY_DEFINED__

/* library PhotoshopTypeLibrary */
/* [version][lcid][helpstring][uuid] */ 

typedef /* [public] */ 
enum __MIDL___MIDL_itf_OLEActions_0000_0000_0001
    {
        phDialogDontDisplay	= 0,
        phDialogDisplay	= 1,
        phDialogSilent	= 2,
        phTypeEnumerated	= 1701737837,
        phTypeFloat	= 1685026146,
        phTypeInteger	= 1819242087,
        phTypeBoolean	= 1651470188,
        phTypeAlias	= 1634494835,
        phTypeNull	= 1853189228,
        phFormAbsolutePosition	= 1768842360,
        phFormPropertyID	= 1886547824,
        phFormRelativePosition	= 1919249509,
        phTypeType	= 1954115685,
        phTypeChar	= 1413830740,
        phTypePath	= 1349806112,
        phTypeObjectSpecifier	= 1868720672,
        phTypeDouble	= 1685026146,
        phTypeUnitDouble	= 1433302086,
        phEnumGrayscales	= 1198684531,
        phKeySelection	= 1718838636,
        phClassAction	= 0x4163746e,
        phClassActionSet	= 0x41536574,
        phClassAdjustment	= 0x41646a73,
        phClassAdjustmentLayer	= 0x41646a4c,
        phClassAirbrushTool	= 0x4162546c,
        phClassAlphaChannelOptions	= 0x4143686c,
        phClassAntiAliasedPICTAcquire	= 0x416e7441,
        phClassApplication	= 0x63617070,
        phClassArrowhead	= 0x63417277,
        phClassAssert	= 0x41737274,
        phClassAssumedProfile	= 0x41737350,
        phClassBMPFormat	= 0x424d5046,
        phClassBackgroundLayer	= 0x42636b4c,
        phClassBevelEmboss	= 0x6562626c,
        phClassBitmapMode	= 0x42746d4d,
        phClassBlendRange	= 0x426c6e64,
        phClassBlurTool	= 0x426c546c,
        phClassBookColor	= 0x426b436c,
        phClassBrightnessContrast	= 0x42726743,
        phClassBrush	= 0x42727368,
        phClassBurnInTool	= 0x4272546c,
        phClassCachePrefs	= 0x43636850,
        phClassCMYKColor	= 0x434d5943,
        phClassCMYKColorMode	= 0x434d594d,
        phClassCMYKSetup	= 0x434d5953,
        phClassCalculation	= 0x436c636c,
        phClassChannel	= 0x43686e6c,
        phClassChannelMatrix	= 0x43684d78,
        phClassChannelMixer	= 0x43686e4d,
        phClassCineonFormat	= 0x53445058,
        phClassClippingInfo	= 0x436c706f,
        phClassClippingPath	= 0x436c7050,
        phClassCloneStampTool	= 0x436c546c,
        phClassColor	= 0x436c7220,
        phClassColorBalance	= 0x436c7242,
        phClassColorCorrection	= 0x436c7243,
        phClassColorPickerPrefs	= 0x436c726b,
        phClassColorSampler	= 0x436c536d,
        phClassColorStop	= 0x436c7274,
        phClassCommand	= 0x436d6e64,
        phClassCurves	= 0x43727673,
        phClassCurvePoint	= 0x43725074,
        phClassCustomPalette	= 0x4373746c,
        phClassCurvesAdjustment	= 0x43727641,
        phClassCustomPhosphors	= 0x43737450,
        phClassCustomWhitePoint	= 0x43737457,
        phClassDicomFormat	= 0x4469636d,
        phClassDisplayPrefs	= 0x44737050,
        phClassDocument	= 0x44636d6e,
        phClassDodgeTool	= 0x4464546c,
        phClassDropShadow	= 0x44725368,
        phClassDuotoneInk	= 0x44746e49,
        phClassDuotoneMode	= 0x44746e4d,
        phClassEPSGenericFormat	= 0x45505347,
        phClassEPSPICTPreview	= 0x45505343,
        phClassEPSTIFFPreview	= 0x45505354,
        phClassElement	= 0x456c6d6e,
        phClassEllipse	= 0x456c7073,
        phClassEraserTool	= 0x4572546c,
        phClassExport	= 0x45787072,
        phClassFileInfo	= 0x466c496e,
        phClassFileSavePrefs	= 0x466c5376,
        phClassFlashPixFormat	= 0x466c7350,
        phClassFontDesignAxes	= 0x466e7444,
        phClassFormat	= 0x466d7420,
        phClassFrameFX	= 0x46724658,
        phClassContour	= 0x46785363,
        phClassGeneralPrefs	= 0x476e7250,
        phClassGIF89aExport	= 0x47463839,
        phClassGIFFormat	= 0x47464672,
        phClassGlobalAngle	= 0x67626c41,
        phClassGradient	= 0x4772646e,
        phClassGradientFill	= 0x47726466,
        phClassGradientMap	= 0x47644d70,
        phClassGradientTool	= 0x4772546c,
        phClassGraySetup	= 0x47725374,
        phClassGrayscale	= 0x47727363,
        phClassGrayscaleMode	= 0x47727973,
        phClassGuide	= 0x47642020,
        phClassGuidesPrefs	= 0x47645072,
        phClassHalftoneScreen	= 0x486c6653,
        phClassHalftoneSpec	= 0x486c6670,
        phClassHSBColor	= 0x48534243,
        phClassHSBColorMode	= 0x4853424d,
        phClassHistoryBrushTool	= 0x4842546c,
        phClassHistoryPrefs	= 0x43487350,
        phClassHistoryState	= 0x48737453,
        phClassHueSatAdjustment	= 0x48537441,
        phClassHueSatAdjustmentV2	= 0x48737432,
        phClassHueSaturation	= 0x48537472,
        phClassIFFFormat	= 0x49464646,
        phClassIllustratorPathsExport	= 0x496c7350,
        phClassImagePoint	= 0x496d6750,
        phClassImport	= 0x496d7072,
        phClassIndexedColorMode	= 0x496e6443,
        phClassInkTransfer	= 0x496e6b54,
        phClassInnerGlow	= 0x4972476c,
        phClassInnerShadow	= 0x49725368,
        phClassInterfaceColor	= 0x49436c72,
        phClassInvert	= 0x496e7672,
        phClassJPEGFormat	= 0x4a504547,
        phClassLabColor	= 0x4c62436c,
        phClassLabColorMode	= 0x4c62434d,
        phClassLayer	= 0x4c797220,
        phClassLayerEffects	= 0x4c656678,
        phClassLayerFXVisible	= 0x6c667876,
        phClassLevels	= 0x4c766c73,
        phClassLevelsAdjustment	= 0x4c766c41,
        phClassLightSource	= 0x4c676853,
        phClassLine	= 0x4c6e2020,
        phClassMacPaintFormat	= 0x4d63506e,
        phClassMagicEraserTool	= 0x4d674572,
        phClassMagicPoint	= 0x4d676370,
        phClassMask	= 0x4d736b20,
        phClassMenuItem	= 0x4d6e2020,
        phClassMode	= 0x4d642020,
        phClassMultichannelMode	= 0x4d6c7443,
        phClassObsoleteTextLayer	= 0x54784c79,
        phClassNull	= 0x6e756c6c,
        phClassOffset	= 0x4f667374,
        phClassOpacity	= 0x4f706163,
        phClassOuterGlow	= 0x4f72476c,
        phClassPDFGenericFormat	= 0x50444647,
        phClassPICTFileFormat	= 0x50494346,
        phClassPICTResourceFormat	= 0x50494352,
        phClassPNGFormat	= 0x504e4746,
        phClassPageSetup	= 0x50675374,
        phClassPaintbrushTool	= 0x5062546c,
        phClassPath	= 0x50617468,
        phClassPathComponent	= 0x5061436d,
        phClassPathPoint	= 0x50746870,
        phClassPattern	= 0x50747452,
        phClassPatternStampTool	= 0x5061546c,
        phClassPencilTool	= 0x5063546c,
        phClassPhotoshop20Format	= 0x50687432,
        phClassPhotoshop35Format	= 0x50687433,
        phClassPhotoshopDCS2Format	= 0x50684432,
        phClassPhotoshopDCSFormat	= 0x50684431,
        phClassPhotoshopEPSFormat	= 0x50687445,
        phClassPhotoshopPDFFormat	= 0x50687450,
        phClassPixel	= 0x5078656c,
        phClassPixelPaintFormat	= 0x50786c50,
        phClassPluginPrefs	= 0x506c6750,
        phClassPoint	= 0x506e7420,
        phClassPointUI	= 0x50745549,
        phClassPoint16	= 0x506e7431,
        phClassPolygon	= 0x506c676e,
        phClassPosterize	= 0x50737472,
        phClassPreferences	= 0x476e7250,
        phClassProfileSetup	= 0x50726653,
        phClassProperty	= 0x50727072,
        phClassRange	= 0x52616e67,
        phClassRect16	= 0x52637431,
        phClassRGBColor	= 0x52474243,
        phClassRGBColorMode	= 0x5247424d,
        phClassRGBSetup	= 0x52474274,
        phClassRawFormat	= 0x52772020,
        phClassRectangle	= 0x5263746e,
        phClassRectUI	= 0x52745549,
        phClassSaturationTool	= 0x5372546c,
        phClassScitexCTFormat	= 0x53637478,
        phClassSelection	= 0x6373656c,
        phClassSelectiveColor	= 0x536c6343,
        phClassShapingCurve	= 0x53687043,
        phClassSharpenTool	= 0x5368546c,
        phClassSingleColumn	= 0x536e6763,
        phClassSingleRow	= 0x536e6772,
        phClassBackgroundEraserTool	= 0x5345546c,
        phClassSolidFill	= 0x536f4669,
        phClassArtHistoryBrushTool	= 0x4142546c,
        phClassSmudgeTool	= 0x536d546c,
        phClassSnapshot	= 0x536e7053,
        phClassSpotColorChannel	= 0x53436368,
        phClassStyle	= 0x53747943,
        phClassSubPath	= 0x5362706c,
        phClassTIFFFormat	= 0x54494646,
        phClassTargaFormat	= 0x54726746,
        phClassTextLayer	= 0x54784c72,
        phClassTextStyle	= 0x54787453,
        phClassTextStyleRange	= 0x54787474,
        phClassThreshold	= 0x54687273,
        phClassTool	= 0x546f6f6c,
        phClassTransferSpec	= 0x54726670,
        phClassTransferPoint	= 0x44746e50,
        phClassTransparencyPrefs	= 0x54726e50,
        phClassTransparencyStop	= 0x54726e53,
        phClassUnitsPrefs	= 0x556e7450,
        phClassUnspecifiedColor	= 0x556e7343,
        phClassVersion	= 0x5672736e,
        phClassWebdavPrefs	= 0x57646276,
        phClassXYYColor	= 0x58595943,
        phClassChromeFX	= 0x43684658,
        phClassBackLight	= 0x42616b4c,
        phClassFillFlash	= 0x46696c46,
        phClassColorCast	= 0x436f6c43,
        phEnumAdd	= 0x41646420,
        phEnumAmountHigh	= 0x616d4869,
        phEnumAmountLow	= 0x616d4c6f,
        phEnumAmountMedium	= 0x616d4d64,
        phEnumAntiAliasNone	= 0x416e6e6f,
        phEnumAntiAliasLow	= 0x416e4c6f,
        phEnumAntiAliasMedium	= 0x416e4d64,
        phEnumAntiAliasHigh	= 0x416e4869,
        phEnumAntiAliasCrisp	= 0x416e4372,
        phEnumAntiAliasStrong	= 0x416e5374,
        phEnumAntiAliasSmooth	= 0x416e536d,
        phEnumAppleRGB	= 0x41707052,
        phEnumASCII	= 0x41534349,
        phEnumAskWhenOpening	= 0x41736b57,
        phEnumBicubic	= 0x42636263,
        phEnumBinary	= 0x426e7279,
        phEnumMonitorSetup	= 0x4d6e7453,
        phEnum16BitsPerPixel	= 0x31364274,
        phEnum1BitPerPixel	= 0x4f6e4274,
        phEnum2BitsPerPixel	= 0x32427473,
        phEnum32BitsPerPixel	= 0x33324274,
        phEnum4BitsPerPixel	= 0x34427473,
        phEnum5000	= 0x35303030,
        phEnum5500	= 0x35353030,
        phEnum6500	= 0x36353030,
        phEnum72Color	= 0x3732436c,
        phEnum72Gray	= 0x37324772,
        phEnum7500	= 0x37353030,
        phEnum8BitsPerPixel	= 0x45676842,
        phEnum9300	= 0x39333030,
        phEnumA	= 0x41202020,
        phEnumAbsColorimetric	= 0x41436c72,
        phEnumADSBottoms	= 0x41644274,
        phEnumADSCentersH	= 0x41644348,
        phEnumADSCentersV	= 0x41644356,
        phEnumADSHorizontal	= 0x41644872,
        phEnumADSLefts	= 0x41644c66,
        phEnumADSRights	= 0x41645267,
        phEnumADSTops	= 0x41645470,
        phEnumADSVertical	= 0x41645672,
        phEnumAboutApp	= 0x41624170,
        phEnumAbsolute	= 0x4162736c,
        phEnumActualPixels	= 0x41637450,
        phEnumAdaptive	= 0x41647074,
        phEnumAdjustmentOptions	= 0x41646a4f,
        phEnumAirbrushEraser	= 0x41726273,
        phEnumAll	= 0x416c2020,
        phEnumAmiga	= 0x416d6761,
        phEnumAngle	= 0x416e676c,
        phEnumAny	= 0x416e7920,
        phEnumApplyImage	= 0x41706c49,
        phEnumAroundCenter	= 0x41726e43,
        phEnumArrange	= 0x41726e67,
        phEnumAsk	= 0x41736b20,
        phEnumB	= 0x42202020,
        phEnumBack	= 0x4261636b,
        phEnumBackground	= 0x42636b67,
        phEnumBackgroundColor	= 0x42636b43,
        phEnumBackward	= 0x42636b77,
        phEnumBehind	= 0x42686e64,
        phEnumBest	= 0x42737420,
        phEnumBetter	= 0x44746862,
        phEnumBilinear	= 0x426c6e72,
        phEnumBitDepth1	= 0x42443120,
        phEnumBitDepth16	= 0x42443136,
        phEnumBitDepth24	= 0x42443234,
        phEnumBitDepth32	= 0x42443332,
        phEnumBitDepth4	= 0x42443420,
        phEnumBitDepth8	= 0x42443820,
        phEnumBitDepthA1R5G5B5	= 0x31353635,
        phEnumBitDepthR5G6B5	= 0x78353635,
        phEnumBitDepthX4R4G4B4	= 0x78343434,
        phEnumBitDepthA4R4G4B4	= 0x34343434,
        phEnumBitDepthX8R8G8B8	= 0x78383838,
        phEnumBitmap	= 0x42746d70,
        phEnumBlack	= 0x426c636b,
        phEnumBlackAndWhite	= 0x42616e57,
        phEnumBlackBody	= 0x426c6342,
        phEnumBlacks	= 0x426c6b73,
        phEnumBlockEraser	= 0x426c6b20,
        phEnumBlast	= 0x426c7374,
        phEnumBlocks	= 0x426c6b73,
        phEnumBlue	= 0x426c2020,
        phEnumBlues	= 0x426c7320,
        phEnumBottom	= 0x4274746d,
        phEnumBrushDarkRough	= 0x42724452,
        phEnumBrushesAppend	= 0x42727341,
        phEnumBrushesDefine	= 0x42727344,
        phEnumBrushesDelete	= 0x42727366,
        phEnumBrushesLoad	= 0x42727364,
        phEnumBrushesNew	= 0x4272734e,
        phEnumBrushesOptions	= 0x4272734f,
        phEnumBrushesReset	= 0x42727352,
        phEnumBrushesSave	= 0x42727376,
        phEnumBrushLightRough	= 0x4272734c,
        phEnumBrushSimple	= 0x4272536d,
        phEnumBrushSize	= 0x42727353,
        phEnumBrushSparkle	= 0x42725370,
        phEnumBrushWideBlurry	= 0x42726257,
        phEnumBrushWideSharp	= 0x42727357,
        phEnumBuiltin	= 0x426c746e,
        phEnumBurnInH	= 0x42726e48,
        phEnumBurnInM	= 0x42726e4d,
        phEnumBurnInS	= 0x42726e53,
        phEnumButtonMode	= 0x42746e4d,
        phEnumCIERGB	= 0x43524742,
        phEnumWidePhosphors	= 0x57696465,
        phEnumWideGamutRGB	= 0x57524742,
        phEnumCMYK	= 0x434d594b,
        phEnumCMYK64	= 0x434d5346,
        phEnumCMYKColor	= 0x45434d59,
        phEnumCalculations	= 0x436c636c,
        phEnumCascade	= 0x43736364,
        phEnumCenter	= 0x436e7472,
        phEnumCenterGlow	= 0x53726343,
        phEnumCenteredFrame	= 0x43747246,
        phEnumChannelOptions	= 0x43686e4f,
        phEnumChannelsPaletteOptions	= 0x43686e50,
        phEnumCheckerboardNone	= 0x4368634e,
        phEnumCheckerboardSmall	= 0x43686353,
        phEnumCheckerboardMedium	= 0x4368634d,
        phEnumCheckerboardLarge	= 0x4368634c,
        phEnumClear	= 0x436c6172,
        phEnumClearGuides	= 0x436c7247,
        phEnumClipboard	= 0x436c7062,
        phEnumClippingPath	= 0x436c7050,
        phEnumCloseAll	= 0x436c7341,
        phEnumCoarseDots	= 0x43727344,
        phEnumColor	= 0x436c7220,
        phEnumColorBurn	= 0x4342726e,
        phEnumColorDodge	= 0x43446467,
        phEnumColorMatch	= 0x436c4d74,
        phEnumColorNoise	= 0x436c4e73,
        phEnumColorimetric	= 0x436c726d,
        phEnumComposite	= 0x436d7073,
        phEnumConvertToCMYK	= 0x436e7643,
        phEnumConvertToGray	= 0x436e7647,
        phEnumConvertToLab	= 0x436e764c,
        phEnumConvertToRGB	= 0x436e7652,
        phEnumCreateDuplicate	= 0x43727444,
        phEnumCreateInterpolation	= 0x43727449,
        phEnumCross	= 0x43727320,
        phEnumCurrentLayer	= 0x4372724c,
        phEnumCustom	= 0x43737420,
        phEnumCustomPattern	= 0x4373746d,
        phEnumCustomStops	= 0x43737453,
        phEnumCyan	= 0x43796e20,
        phEnumCyans	= 0x43796e73,
        phEnumDark	= 0x44726b20,
        phEnumDarken	= 0x44726b6e,
        phEnumDarkenOnly	= 0x44726b4f,
        phEnumDashedLines	= 0x4473684c,
        phEnumDesaturate	= 0x44737474,
        phEnumDiamond	= 0x446d6e64,
        phEnumDifference	= 0x4466726e,
        phEnumDiffusion	= 0x4466736e,
        phEnumDiffusionDither	= 0x44666e44,
        phEnumDisplayCursorsPreferences	= 0x44737043,
        phEnumDissolve	= 0x44736c76,
        phEnumDistort	= 0x44737472,
        phEnumDodgeH	= 0x44646748,
        phEnumDodgeM	= 0x4464674d,
        phEnumDodgeS	= 0x44646753,
        phEnumDots	= 0x44747320,
        phEnumDraft	= 0x44726674,
        phEnumDuotone	= 0x44746e20,
        phEnumEBUITU	= 0x45425420,
        phEnumEdgeGlow	= 0x53726345,
        phEnumEliminateEvenFields	= 0x456c6d45,
        phEnumEliminateOddFields	= 0x456c6d4f,
        phEnumEllipse	= 0x456c7073,
        phEnumEmboss	= 0x456d6273,
        phEnumExact	= 0x45786374,
        phEnumExclusion	= 0x58636c75,
        phEnumFPXCompressLossyJPEG	= 0x46784a50,
        phEnumFPXCompressNone	= 0x46784e6f,
        phEnumFaster	= 0x44746866,
        phEnumFile	= 0x466c6520,
        phEnumFileInfo	= 0x466c496e,
        phEnumFillBack	= 0x466c4263,
        phEnumFillFore	= 0x466c4672,
        phEnumFillInverse	= 0x466c496e,
        phEnumFillSame	= 0x466c536d,
        phEnumFineDots	= 0x466e4474,
        phEnumFirst	= 0x46727374,
        phEnumFirstIdle	= 0x46724964,
        phEnumFitOnScreen	= 0x46744f6e,
        phEnumForegroundColor	= 0x46726743,
        phEnumForward	= 0x46727772,
        phEnumFreeTransform	= 0x46725472,
        phEnumFront	= 0x46726e74,
        phEnumFullDocument	= 0x466c6c44,
        phEnumFullSize	= 0x466c537a,
        phEnumGaussianDistribution	= 0x47736e20,
        phEnumGIFColorFileColorTable	= 0x47464354,
        phEnumGIFColorFileColors	= 0x47464346,
        phEnumGIFColorFileMicrosoftPalette	= 0x47464d53,
        phEnumGIFPaletteAdaptive	= 0x47465041,
        phEnumGIFPaletteExact	= 0x47465045,
        phEnumGIFPaletteOther	= 0x4746504f,
        phEnumGIFPaletteSystem	= 0x47465053,
        phEnumGIFRequiredColorSpaceIndexed	= 0x47464349,
        phEnumGIFRequiredColorSpaceRGB	= 0x47465247,
        phEnumGIFRowOrderInterlaced	= 0x4746494e,
        phEnumGIFRowOrderNormal	= 0x47464e49,
        phEnumGeneralPreferences	= 0x476e7250,
        phEnumGood	= 0x47642020,
        phEnumGradientFill	= 0x4772466c,
        phEnumGrainClumped	= 0x47726e43,
        phEnumGrainContrasty	= 0x4772436e,
        phEnumGrainEnlarged	= 0x47726e45,
        phEnumGrainHorizontal	= 0x47726e48,
        phEnumGrainRegular	= 0x47726e52,
        phEnumGrainSoft	= 0x47725366,
        phEnumGrainSpeckle	= 0x47725370,
        phEnumGrainSprinkles	= 0x47725372,
        phEnumGrainStippled	= 0x47725374,
        phEnumGrainVertical	= 0x47726e56,
        phEnumGrainyDots	= 0x47726e44,
        phEnumGraphics	= 0x47727020,
        phEnumGray	= 0x47727920,
        phEnumGray16	= 0x47727958,
        phEnumGray18	= 0x47723138,
        phEnumGray22	= 0x47723232,
        phEnumGray50	= 0x47723530,
        phEnumGrayScale	= 0x47727963,
        phEnumGreen	= 0x47726e20,
        phEnumGreens	= 0x47726e73,
        phEnumGuidesGridPreferences	= 0x47756447,
        phEnumHDTV	= 0x48445456,
        phEnumHSBColor	= 0x4853426c,
        phEnumHSLColor	= 0x48534c43,
        phEnumHalftoneFile	= 0x486c6646,
        phEnumHalftoneScreen	= 0x486c6653,
        phEnumHardLight	= 0x4872644c,
        phEnumHeavy	= 0x48767920,
        phEnumHideAll	= 0x4864416c,
        phEnumHideSelection	= 0x4864536c,
        phEnumHigh	= 0x48696768,
        phEnumHighQuality	= 0x48676820,
        phEnumHighlights	= 0x4867686c,
        phEnumHistogram	= 0x48737467,
        phEnumHistory	= 0x48737479,
        phEnumHistoryPaletteOptions	= 0x4873744f,
        phEnumHistoryPreferences	= 0x48737450,
        phEnumHorizontal	= 0x48727a6e,
        phEnumHorizontalOnly	= 0x48727a4f,
        phEnumHue	= 0x48202020,
        phEnumIBMPC	= 0x49424d50,
        phEnumICC	= 0x49434320,
        phEnumIcon	= 0x49636e20,
        phEnumIdleVM	= 0x4964564d,
        phEnumIgnore	= 0x49676e72,
        phEnumImage	= 0x496d6720,
        phEnumImageCachePreferences	= 0x496d6750,
        phEnumIndexedColor	= 0x496e646c,
        phEnumInfoPaletteOptions	= 0x496e6650,
        phEnumInfoPaletteToggleSamplers	= 0x496e6654,
        phEnumInnerBevel	= 0x496e7242,
        phEnumInsetFrame	= 0x496e7346,
        phEnumInside	= 0x496e7364,
        phEnumJPEG	= 0x4a504547,
        phEnumJustifyAll	= 0x4a737441,
        phEnumJustifyFull	= 0x4a737446,
        phEnumKeepProfile	= 0x4b50726f,
        phEnumKeyboardPreferences	= 0x4b796250,
        phEnumLab	= 0x4c616220,
        phEnumLab48	= 0x4c624346,
        phEnumLabColor	= 0x4c62436c,
        phEnumLarge	= 0x4c726720,
        phEnumLast	= 0x4c737420,
        phEnumLastFilter	= 0x4c737446,
        phEnumLayerOptions	= 0x4c79724f,
        phEnumLayersPaletteOptions	= 0x4c797250,
        phEnumLeft	= 0x4c656674,
        phEnumLeft_PLUGIN	= 0x4c667420,
        phEnumLevelBased	= 0x4c766c42,
        phEnumLight	= 0x4c677420,
        phEnumLightBlue	= 0x4c677442,
        phEnumLightDirBottom	= 0x4c444274,
        phEnumLightDirBottomLeft	= 0x4c44424c,
        phEnumLightDirBottomRight	= 0x4c444252,
        phEnumLightDirLeft	= 0x4c444c66,
        phEnumLightDirRight	= 0x4c445267,
        phEnumLightDirTop	= 0x4c445470,
        phEnumLightDirTopLeft	= 0x4c44544c,
        phEnumLightDirTopRight	= 0x4c445452,
        phEnumLightGray	= 0x4c677447,
        phEnumLightDirectional	= 0x4c676844,
        phEnumLightenOnly	= 0x4c67684f,
        phEnumLightOmni	= 0x4c67684f,
        phEnumLightPosBottom	= 0x4c504274,
        phEnumLightPosBottomLeft	= 0x4c50424c,
        phEnumLightPosBottomRight	= 0x4c504272,
        phEnumLightPosLeft	= 0x4c504c66,
        phEnumLightPosRight	= 0x4c505267,
        phEnumLightPosTop	= 0x4c505470,
        phEnumLightPosTopLeft	= 0x4c50544c,
        phEnumLightPosTopRight	= 0x4c505452,
        phEnumLightRed	= 0x4c677452,
        phEnumLightSpot	= 0x4c676853,
        phEnumLighten	= 0x4c67686e,
        phEnumLightness	= 0x4c676874,
        phEnumLine	= 0x4c6e2020,
        phEnumLines	= 0x4c6e7320,
        phEnumLinear	= 0x4c6e7220,
        phEnumLinked	= 0x4c6e6b64,
        phEnumLongLines	= 0x4c6e674c,
        phEnumLongStrokes	= 0x4c6e6753,
        phEnumLow	= 0x4c6f7720,
        phEnumLower	= 0x4c777220,
        phEnumLowQuality	= 0x4c772020,
        phEnumLuminosity	= 0x4c6d6e73,
        phEnumMaya	= 0x4d617961,
        phEnumMacThumbnail	= 0x4d635468,
        phEnumMacintosh	= 0x4d636e74,
        phEnumMacintoshSystem	= 0x4d636e53,
        phEnumMagenta	= 0x4d676e74,
        phEnumMagentas	= 0x4d676e74,
        phEnumMask	= 0x4d736b20,
        phEnumMaskedAreas	= 0x4d736b41,
        phEnumMasterAdaptive	= 0x4d416470,
        phEnumMasterPerceptual	= 0x4d506572,
        phEnumMasterSelective	= 0x4d53656c,
        phEnumMaximum	= 0x4d786d6d,
        phEnumMaximumQuality	= 0x4d786d20,
        phEnumMedium	= 0x4d64696d,
        phEnumMediumBlue	= 0x4d646d42,
        phEnumMediumQuality	= 0x4d646d20,
        phEnumMediumDots	= 0x4d646d44,
        phEnumMediumLines	= 0x4d646d4c,
        phEnumMediumStrokes	= 0x4d646d53,
        phEnumMemoryPreferences	= 0x4d6d7250,
        phEnumMergeChannels	= 0x4d726743,
        phEnumMerged	= 0x4d726764,
        phEnumMergedLayers	= 0x4d726732,
        phEnumMergedLayersOld	= 0x4d72674c,
        phEnumMiddle	= 0x4d64646c,
        phEnumMidtones	= 0x4d64746e,
        phEnumModeGray	= 0x4d644772,
        phEnumModeRGB	= 0x4d645247,
        phEnumMonitor	= 0x4d6f6e69,
        phEnumMonotone	= 0x4d6e746e,
        phEnumMulti72Color	= 0x3732434d,
        phEnumMulti72Gray	= 0x3732474d,
        phEnumMultichannel	= 0x4d6c7468,
        phEnumMultiNoCompositePS	= 0x4e436d4d,
        phEnumMultiply	= 0x4d6c7470,
        phEnumNavigatorPaletteOptions	= 0x4e766750,
        phEnumNearestNeighbor	= 0x4e727374,
        phEnumNetscapeGray	= 0x4e734772,
        phEnumNeutrals	= 0x4e74726c,
        phEnumNewView	= 0x4e775677,
        phEnumNext	= 0x4e787420,
        phEnumNikon	= 0x4e6b6e20,
        phEnumNikon105	= 0x4e6b6e31,
        phEnumNo	= 0x4e202020,
        phEnumNoCompositePS	= 0x4e436d70,
        phEnumNone	= 0x4e6f6e65,
        phEnumNormal	= 0x4e726d6c,
        phEnumNormalPath	= 0x4e726d50,
        phEnumNTSC	= 0x4e545343,
        phEnumNull	= 0x6e756c6c,
        phEnumOS2	= 0x4f533220,
        phEnumOff	= 0x4f666620,
        phEnumOn	= 0x4f6e2020,
        phEnumOpenAs	= 0x4f704173,
        phEnumOrange	= 0x4f726e67,
        phEnumOutFromCenter	= 0x4f744672,
        phEnumOutOfGamut	= 0x4f744f66,
        phEnumOuterBevel	= 0x4f747242,
        phEnumOutside	= 0x4f747364,
        phEnumOutsetFrame	= 0x4f757446,
        phEnumOverlay	= 0x4f76726c,
        phEnumPaintbrushEraser	= 0x506e7462,
        phEnumPencilEraser	= 0x506e636c,
        phEnumP22EBU	= 0x50323242,
        phEnumPNGFilterAdaptive	= 0x50474164,
        phEnumPNGFilterAverage	= 0x50474176,
        phEnumPNGFilterNone	= 0x50474e6f,
        phEnumPNGFilterPaeth	= 0x50475074,
        phEnumPNGFilterSub	= 0x50475362,
        phEnumPNGFilterUp	= 0x50475570,
        phEnumPNGInterlaceAdam7	= 0x50474941,
        phEnumPNGInterlaceNone	= 0x5047494e,
        phEnumPagePosCentered	= 0x50675043,
        phEnumPagePosTopLeft	= 0x5067544c,
        phEnumPageSetup	= 0x50675374,
        phEnumPalSecam	= 0x506c5363,
        phEnumPanaVision	= 0x506e5673,
        phEnumPathsPaletteOptions	= 0x50746850,
        phEnumPattern	= 0x5074726e,
        phEnumPatternDither	= 0x50746e44,
        phEnumPerceptual	= 0x50657263,
        phEnumPerspective	= 0x50727370,
        phEnumPhotoshopPicker	= 0x5068746b,
        phEnumPickCMYK	= 0x50636b43,
        phEnumPickGray	= 0x50636b47,
        phEnumPickHSB	= 0x50636b48,
        phEnumPickLab	= 0x50636b4c,
        phEnumPickOptions	= 0x50636b4f,
        phEnumPickRGB	= 0x50636b52,
        phEnumPillowEmboss	= 0x506c4562,
        phEnumPixelPaintSize1	= 0x50785331,
        phEnumPixelPaintSize2	= 0x50785332,
        phEnumPixelPaintSize3	= 0x50785333,
        phEnumPixelPaintSize4	= 0x50785334,
        phEnumPlace	= 0x506c6365,
        phEnumPlaybackOptions	= 0x50626b4f,
        phEnumPluginPicker	= 0x506c6750,
        phEnumPluginsScratchDiskPreferences	= 0x506c6753,
        phEnumPolarToRect	= 0x506c7252,
        phEnumPondRipples	= 0x506e6452,
        phEnumPrecise	= 0x50726320,
        phEnumPreciseMatte	= 0x5072424c,
        phEnumPreviewOff	= 0x5072764f,
        phEnumPreviewCMYK	= 0x50727643,
        phEnumPreviewCyan	= 0x50727679,
        phEnumPreviewMagenta	= 0x5072764d,
        phEnumPreviewYellow	= 0x50727659,
        phEnumPreviewBlack	= 0x50727642,
        phEnumPreviewCMY	= 0x5072764e,
        phEnumPrevious	= 0x50727673,
        phEnumPrimaries	= 0x5072696d,
        phEnumPrintSize	= 0x50726e53,
        phEnumPrintingInksSetup	= 0x50726e49,
        phEnumPurple	= 0x50727020,
        phEnumPyramids	= 0x5079726d,
        phEnumQCSAverage	= 0x51637361,
        phEnumQCSCorner0	= 0x51637330,
        phEnumQCSCorner1	= 0x51637331,
        phEnumQCSCorner2	= 0x51637332,
        phEnumQCSCorner3	= 0x51637333,
        phEnumQCSIndependent	= 0x51637369,
        phEnumQCSSide0	= 0x51637334,
        phEnumQCSSide1	= 0x51637335,
        phEnumQCSSide2	= 0x51637336,
        phEnumQCSSide3	= 0x51637337,
        phEnumQuadtone	= 0x5164746e,
        phEnumQueryAlways	= 0x51757241,
        phEnumQueryAsk	= 0x5175726c,
        phEnumQueryNever	= 0x5175724e,
        phEnumRepeat	= 0x52707420,
        phEnumRGB	= 0x52474220,
        phEnumRGB48	= 0x52474246,
        phEnumRGBColor	= 0x52474243,
        phEnumRadial	= 0x52646c20,
        phEnumRandom	= 0x526e646d,
        phEnumRectToPolar	= 0x52637450,
        phEnumRed	= 0x52642020,
        phEnumRedrawComplete	= 0x5264436d,
        phEnumReds	= 0x52647320,
        phEnumReflected	= 0x52666c63,
        phEnumRelative	= 0x526c7476,
        phEnumRepeatEdgePixels	= 0x52707445,
        phEnumRevealAll	= 0x52766c41,
        phEnumRevealSelection	= 0x52766c53,
        phEnumRevert	= 0x52767274,
        phEnumRight	= 0x52676874,
        phEnumRotate	= 0x52747465,
        phEnumRotoscopingPreferences	= 0x52747350,
        phEnumRound	= 0x526e6420,
        phEnumRulerCm	= 0x5272436d,
        phEnumRulerInches	= 0x5272496e,
        phEnumRulerPercent	= 0x52725072,
        phEnumRulerPicas	= 0x52725069,
        phEnumRulerPixels	= 0x52725078,
        phEnumRulerPoints	= 0x52725074,
        phEnumAdobeRGB1998	= 0x534d5054,
        phEnumSMPTEC	= 0x534d5043,
        phEnumSRGB	= 0x53524742,
        phEnumSample3x3	= 0x536d7033,
        phEnumSample5x5	= 0x536d7035,
        phEnumSamplePoint	= 0x536d7050,
        phEnumSaturate	= 0x53747220,
        phEnumSaturation	= 0x53747274,
        phEnumSaved	= 0x53766564,
        phEnumSaveForWeb	= 0x53766677,
        phEnumSavingFilesPreferences	= 0x53766e46,
        phEnumScale	= 0x53636c20,
        phEnumScreen	= 0x5363726e,
        phEnumScreenCircle	= 0x53637243,
        phEnumScreenDot	= 0x53637244,
        phEnumScreenLine	= 0x5363724c,
        phEnumSelectedAreas	= 0x536c6341,
        phEnumSelection	= 0x536c6374,
        phEnumSelective	= 0x53656c65,
        phEnumSeparationSetup	= 0x53707253,
        phEnumSeparationTables	= 0x53707254,
        phEnumShadows	= 0x53686477,
        phEnumContourLinear	= 0x73703031,
        phEnumContourGaussian	= 0x73703032,
        phEnumContourSingle	= 0x73703033,
        phEnumContourDouble	= 0x73703034,
        phEnumContourTriple	= 0x73703035,
        phEnumContourCustom	= 0x73703036,
        phEnumShortLines	= 0x5368724c,
        phEnumShortStrokes	= 0x53685374,
        phEnumSingle72Color	= 0x37324353,
        phEnumSingle72Gray	= 0x37324753,
        phEnumSingleNoCompositePS	= 0x4e436d53,
        phEnumSkew	= 0x536b6577,
        phEnumSlopeLimitMatte	= 0x536c6d74,
        phEnumSmall	= 0x536d6c20,
        phEnumSmartBlurModeEdgeOnly	= 0x53424d45,
        phEnumSmartBlurModeNormal	= 0x53424d4e,
        phEnumSmartBlurModeOverlayEdge	= 0x53424d4f,
        phEnumSmartBlurQualityHigh	= 0x53425148,
        phEnumSmartBlurQualityLow	= 0x5342514c,
        phEnumSmartBlurQualityMedium	= 0x5342514d,
        phEnumSnapshot	= 0x536e7073,
        phEnumSolidColor	= 0x53436c72,
        phEnumSoftLight	= 0x5366744c,
        phEnumSoftMatte	= 0x5366424c,
        phEnumSpectrum	= 0x53706374,
        phEnumSpin	= 0x53706e20,
        phEnumSpotColor	= 0x53706f74,
        phEnumSquare	= 0x53717220,
        phEnumStagger	= 0x53746772,
        phEnumStampIn	= 0x496e2020,
        phEnumStampOut	= 0x4f757420,
        phEnumStandard	= 0x53746420,
        phEnumStdA	= 0x53746441,
        phEnumStdB	= 0x53746442,
        phEnumStdC	= 0x53746443,
        phEnumStdE	= 0x53746445,
        phEnumStretchToFit	= 0x53747246,
        phEnumStrokeDirHorizontal	= 0x5344487a,
        phEnumStrokeDirLeftDiag	= 0x53444c44,
        phEnumStrokeDirRightDiag	= 0x53445244,
        phEnumStrokeDirVertical	= 0x53445674,
        phEnumStylesAppend	= 0x536c7341,
        phEnumStylesDelete	= 0x536c7366,
        phEnumStylesLoad	= 0x536c7364,
        phEnumStylesNew	= 0x536c734e,
        phEnumStylesReset	= 0x536c7352,
        phEnumStylesSave	= 0x536c7376,
        phEnumSubtract	= 0x53627472,
        phEnumSwatchesAppend	= 0x53777441,
        phEnumSwatchesReplace	= 0x53777470,
        phEnumSwatchesReset	= 0x53777452,
        phEnumSwatchesSave	= 0x53777453,
        phEnumSystemPicker	= 0x53797350,
        phEnumTables	= 0x54626c20,
        phEnumTarget	= 0x54726774,
        phEnumTargetPath	= 0x54726770,
        phEnumTexTypeBlocks	= 0x5478426c,
        phEnumTexTypeBrick	= 0x54784272,
        phEnumTexTypeBurlap	= 0x54784275,
        phEnumTexTypeCanvas	= 0x54784361,
        phEnumTexTypeFrosted	= 0x54784672,
        phEnumTexTypeSandstone	= 0x54785374,
        phEnumTexTypeTinyLens	= 0x5478544c,
        phEnumThreshold	= 0x54687268,
        phEnumThumbnail	= 0x54686d62,
        phEnumTIFF	= 0x54494646,
        phEnumTile	= 0x54696c65,
        phEnumTile_PLUGIN	= 0x546c2020,
        phEnumToggleActionsPalette	= 0x54676c41,
        phEnumToggleBlackPreview	= 0x54674250,
        phEnumToggleBrushesPalette	= 0x54676c42,
        phEnumToggleCMYKPreview	= 0x54676c43,
        phEnumToggleCMYPreview	= 0x5467434d,
        phEnumToggleChannelsPalette	= 0x54676c68,
        phEnumToggleColorPalette	= 0x54676c63,
        phEnumToggleCyanPreview	= 0x54674350,
        phEnumToggleEdges	= 0x54676c45,
        phEnumToggleGamutWarning	= 0x54676c47,
        phEnumToggleGrid	= 0x54674772,
        phEnumToggleGuides	= 0x54676c64,
        phEnumToggleHistoryPalette	= 0x54676c48,
        phEnumToggleInfoPalette	= 0x54676c49,
        phEnumToggleLayerMask	= 0x54676c4d,
        phEnumToggleLayersPalette	= 0x54676c79,
        phEnumToggleLockGuides	= 0x54676c4c,
        phEnumToggleMagentaPreview	= 0x54674d50,
        phEnumToggleNavigatorPalette	= 0x54676c4e,
        phEnumToggleOptionsPalette	= 0x54676c4f,
        phEnumTogglePaths	= 0x54676c50,
        phEnumTogglePathsPalette	= 0x54676c74,
        phEnumToggleRGBMacPreview	= 0x54724d70,
        phEnumToggleRGBWindowsPreview	= 0x54725770,
        phEnumToggleRGBUncompensatedPreview	= 0x54725570,
        phEnumToggleRulers	= 0x54676c52,
        phEnumToggleSnapToGrid	= 0x5467536e,
        phEnumToggleSnapToGuides	= 0x54676c53,
        phEnumToggleStatusBar	= 0x54676c73,
        phEnumToggleStylesPalette	= 0x5467536c,
        phEnumToggleSwatchesPalette	= 0x54676c77,
        phEnumToggleToolsPalette	= 0x54676c54,
        phEnumToggleYellowPreview	= 0x54675950,
        phEnumToggleDocumentPalette	= 0x54674463,
        phEnumTop	= 0x546f7020,
        phEnumTransparency	= 0x54727370,
        phEnumTransparencyGamutPreferences	= 0x54726e47,
        phEnumTransparent	= 0x54726e73,
        phEnumTrinitron	= 0x54726e74,
        phEnumTritone	= 0x5472746e,
        phEnumUIBitmap	= 0x5542746d,
        phEnumUICMYK	= 0x55434d59,
        phEnumUIDuotone	= 0x5544746e,
        phEnumUIGrayscale	= 0x55477279,
        phEnumUIIndexed	= 0x55496e64,
        phEnumUILab	= 0x554c6162,
        phEnumUIMultichannel	= 0x554d6c74,
        phEnumUIRGB	= 0x55524742,
        phEnumUndo	= 0x556e6420,
        phEnumUniform	= 0x556e666d,
        phEnumUniformDistribution	= 0x556e6672,
        phEnumUnitsRulersPreferences	= 0x556e7452,
        phEnumUpper	= 0x55707220,
        phEnumUserStop	= 0x55737253,
        phEnumVMPreferences	= 0x564d5072,
        phEnumVertical	= 0x56727463,
        phEnumVerticalOnly	= 0x5672744f,
        phEnumViolet	= 0x566c7420,
        phEnumWaveSine	= 0x5776536e,
        phEnumWaveSquare	= 0x57765371,
        phEnumWaveTriangle	= 0x57765472,
        phEnumWeb	= 0x57656220,
        phEnumWhite	= 0x57687420,
        phEnumWhites	= 0x57687473,
        phEnumWinThumbnail	= 0x576e5468,
        phEnumWind	= 0x576e6420,
        phEnumWindows	= 0x57696e20,
        phEnumWindowsSystem	= 0x576e6453,
        phEnumWrap	= 0x57727020,
        phEnumWrapAround	= 0x57727041,
        phEnumWorkPath	= 0x57726b50,
        phEnumYellow	= 0x596c6c77,
        phEnumYellowColor	= 0x596c7720,
        phEnumYellows	= 0x596c7773,
        phEnumYes	= 0x59732020,
        phEnumZip	= 0x5a70456e,
        phEnumZoom	= 0x5a6d2020,
        phEnumZoomIn	= 0x5a6d496e,
        phEnumZoomOut	= 0x5a6d4f74,
        phEvent3DTransform	= 0x54645420,
        phEventAverage	= 0x41767267,
        phEventApplyStyle	= 0x41537479,
        phEventAssert	= 0x41737274,
        phEventAccentedEdges	= 0x41636345,
        phEventAdd	= 0x41646420,
        phEventAddNoise	= 0x41644e73,
        phEventAddTo	= 0x41646454,
        phEventAlign	= 0x416c676e,
        phEventAll	= 0x416c6c20,
        phEventAngledStrokes	= 0x416e6753,
        phEventApplyImage	= 0x41707049,
        phEventBasRelief	= 0x4273526c,
        phEventBatch	= 0x42746368,
        phEventBatchFromDroplet	= 0x42746346,
        phEventBlur	= 0x426c7220,
        phEventBlurMore	= 0x426c724d,
        phEventBorder	= 0x42726472,
        phEventBrightness	= 0x42726743,
        phEventCanvasSize	= 0x436e7653,
        phEventChalkCharcoal	= 0x43686c43,
        phEventChannelMixer	= 0x43686e4d,
        phEventCharcoal	= 0x43687263,
        phEventChrome	= 0x4368726d,
        phEventClear	= 0x436c6572,
        phEventClose	= 0x436c7320,
        phEventClouds	= 0x436c6473,
        phEventColorBalance	= 0x436c7242,
        phEventColorHalftone	= 0x436c7248,
        phEventColorRange	= 0x436c7252,
        phEventColoredPencil	= 0x436c7250,
        phEventConteCrayon	= 0x436e7443,
        phEventContract	= 0x436e7463,
        phEventConvertMode	= 0x436e764d,
        phEventCopy	= 0x636f7079,
        phEventCopyEffects	= 0x43704658,
        phEventCopyMerged	= 0x4370794d,
        phEventCopyToLayer	= 0x4370544c,
        phEventCraquelure	= 0x4372716c,
        phEventCreateDroplet	= 0x43727444,
        phEventCrop	= 0x43726f70,
        phEventCrosshatch	= 0x43727368,
        phEventCrystallize	= 0x43727374,
        phEventCurves	= 0x43727673,
        phEventCustom	= 0x4373746d,
        phEventCut	= 0x63757420,
        phEventCutToLayer	= 0x4374544c,
        phEventCutout	= 0x43742020,
        phEventDarkStrokes	= 0x44726b53,
        phEventDeInterlace	= 0x446e7472,
        phEventDefinePattern	= 0x44666e50,
        phEventDefringe	= 0x44667267,
        phEventDelete	= 0x446c7420,
        phEventDesaturate	= 0x44737474,
        phEventDeselect	= 0x44736c63,
        phEventDespeckle	= 0x44737063,
        phEventDifferenceClouds	= 0x44667243,
        phEventDiffuse	= 0x44667320,
        phEventDiffuseGlow	= 0x44667347,
        phEventDisableLayerFX	= 0x646c6678,
        phEventDisplace	= 0x4473706c,
        phEventDistribute	= 0x44737472,
        phEventDraw	= 0x44726177,
        phEventDryBrush	= 0x44727942,
        phEventDuplicate	= 0x44706c63,
        phEventDustAndScratches	= 0x44737453,
        phEventEmboss	= 0x456d6273,
        phEventEqualize	= 0x45716c7a,
        phEventExchange	= 0x45786368,
        phEventExpand	= 0x4578706e,
        phEventExport	= 0x45787072,
        phEventExtrude	= 0x45787472,
        phEventFacet	= 0x46637420,
        phEventFade	= 0x46616465,
        phEventFeather	= 0x46746872,
        phEventFibers	= 0x46627273,
        phEventFill	= 0x466c2020,
        phEventFilmGrain	= 0x466c6d47,
        phEventFilter	= 0x466c7472,
        phEventFindEdges	= 0x466e6445,
        phEventFlattenImage	= 0x466c7449,
        phEventFlip	= 0x466c6970,
        phEventFragment	= 0x4672676d,
        phEventFresco	= 0x46727363,
        phEventGaussianBlur	= 0x47736e42,
        phEventGet	= 0x67657464,
        phEventGlass	= 0x476c7320,
        phEventGlowingEdges	= 0x476c7745,
        phEventGradient	= 0x4772646e,
        phEventGradientMap	= 0x47724d70,
        phEventGrain	= 0x47726e20,
        phEventGraphicPen	= 0x47726150,
        phEventGroup	= 0x4772704c,
        phEventGrow	= 0x47726f77,
        phEventHalftoneScreen	= 0x486c6653,
        phEventHide	= 0x48642020,
        phEventHighPass	= 0x48676850,
        phEventHSBHSL	= 0x48736250,
        phEventHueSaturation	= 0x48537472,
        phEventImageSize	= 0x496d6753,
        phEventImport	= 0x496d7072,
        phEventInkOutlines	= 0x496e6b4f,
        phEventIntersect	= 0x496e7472,
        phEventIntersectWith	= 0x496e7457,
        phEventInverse	= 0x496e7673,
        phEventInvert	= 0x496e7672,
        phEventLensFlare	= 0x4c6e7346,
        phEventLevels	= 0x4c766c73,
        phEventLightingEffects	= 0x4c676845,
        phEventLink	= 0x4c6e6b20,
        phEventMake	= 0x4d6b2020,
        phEventMaximum	= 0x4d786d20,
        phEventMedian	= 0x4d646e20,
        phEventMergeLayers	= 0x4d726732,
        phEventMergeLayersOld	= 0x4d72674c,
        phEventMergeSpotChannel	= 0x4d537074,
        phEventMergeVisible	= 0x4d726756,
        phEventMezzotint	= 0x4d7a746e,
        phEventMinimum	= 0x4d6e6d20,
        phEventMosaic	= 0x4d736320,
        phEventMosaic_PLUGIN	= 0x4d736354,
        phEventMotionBlur	= 0x4d746e42,
        phEventMove	= 0x6d6f7665,
        phEventNTSCColors	= 0x4e545343,
        phEventNeonGlow	= 0x4e476c77,
        phEventNext	= 0x4e787420,
        phEventNotePaper	= 0x4e745072,
        phEventNotify	= 0x4e746679,
        phEventNull	= 0x6e756c6c,
        phEventOceanRipple	= 0x4f636e52,
        phEventOffset	= 0x4f667374,
        phEventOpen	= 0x4f706e20,
        phEventPaintDaubs	= 0x506e7444,
        phEventPaletteKnife	= 0x506c744b,
        phEventPaste	= 0x70617374,
        phEventPasteEffects	= 0x50614658,
        phEventPasteInto	= 0x50737449,
        phEventPasteOutside	= 0x5073744f,
        phEventPatchwork	= 0x50746368,
        phEventPhotocopy	= 0x50687463,
        phEventPinch	= 0x506e6368,
        phEventPlace	= 0x506c6320,
        phEventPlaster	= 0x506c7374,
        phEventPlasticWrap	= 0x506c7357,
        phEventPlay	= 0x506c7920,
        phEventPointillize	= 0x506e746c,
        phEventPolar	= 0x506c7220,
        phEventPosterEdges	= 0x50737445,
        phEventPosterize	= 0x50737472,
        phEventPrevious	= 0x50727673,
        phEventPrint	= 0x50726e74,
        phEventProfileToProfile	= 0x50726654,
        phEventPurge	= 0x50726765,
        phEventQuit	= 0x71756974,
        phEventRadialBlur	= 0x52646c42,
        phEventRasterize	= 0x52737472,
        phEventRasterizeTypeSheet	= 0x52737454,
        phEventRemoveBlackMatte	= 0x526d7642,
        phEventRemoveLayerMask	= 0x526d764c,
        phEventRemoveWhiteMatte	= 0x526d7657,
        phEventRename	= 0x526e6d20,
        phEventReplaceColor	= 0x52706c43,
        phEventReset	= 0x52736574,
        phEventReticulation	= 0x5274636c,
        phEventRevert	= 0x52767274,
        phEventRipple	= 0x52706c65,
        phEventRotate	= 0x52747465,
        phEventRoughPastels	= 0x52676850,
        phEventSave	= 0x73617665,
        phEventSelect	= 0x736c6374,
        phEventSelectiveColor	= 0x536c6343,
        phEventSet	= 0x73657464,
        phEventSharpenEdges	= 0x53687245,
        phEventSharpen	= 0x53687270,
        phEventSharpenMore	= 0x5368724d,
        phEventShear	= 0x53687220,
        phEventShow	= 0x53687720,
        phEventSimilar	= 0x536d6c72,
        phEventSmartBlur	= 0x536d7242,
        phEventSmooth	= 0x536d7468,
        phEventSmudgeStick	= 0x536d6453,
        phEventSolarize	= 0x536c727a,
        phEventSpatter	= 0x53707420,
        phEventSpherize	= 0x53706872,
        phEventSplitChannels	= 0x53706c43,
        phEventSponge	= 0x53706e67,
        phEventSprayedStrokes	= 0x53707253,
        phEventStainedGlass	= 0x53746e47,
        phEventStamp	= 0x53746d70,
        phEventStop	= 0x53746f70,
        phEventStroke	= 0x5374726b,
        phEventSubtract	= 0x53627472,
        phEventSubtractFrom	= 0x53627446,
        phEventSumie	= 0x536d6965,
        phEventTakeMergedSnapshot	= 0x546b4d72,
        phEventTakeSnapshot	= 0x546b536e,
        phEventTextureFill	= 0x54787446,
        phEventTexturizer	= 0x5478747a,
        phEventThreshold	= 0x54687273,
        phEventTiles	= 0x546c7320,
        phEventTornEdges	= 0x54726e45,
        phEventTraceContour	= 0x54726343,
        phEventTransform	= 0x54726e66,
        phEventTrap	= 0x54726170,
        phEventTwirl	= 0x5477726c,
        phEventUnderpainting	= 0x556e6472,
        phEventUndo	= 0x756e646f,
        phEventUngroup	= 0x556e6772,
        phEventUnlink	= 0x556e6c6b,
        phEventUnsharpMask	= 0x556e734d,
        phEventVariations	= 0x5672746e,
        phEventWait	= 0x57616974,
        phEventWaterPaper	= 0x57747250,
        phEventWatercolor	= 0x57747263,
        phEventWave	= 0x57617665,
        phEventWind	= 0x576e6420,
        phEventZigZag	= 0x5a675a67,
        phEventBackLight	= 0x4261634c,
        phEventFillFlash	= 0x46696c45,
        phEventColorCast	= 0x436f6c45,
        phEventOpenUntitled	= 0x4f706e55,
        phFormClass	= 0x436c7373,
        phFormEnumerated	= 0x456e6d72,
        phFormIdentifier	= 0x49646e74,
        phFormIndex	= 0x696e6478,
        phFormOffset	= 0x72656c65,
        phFormProperty	= 0x70726f70,
        phKey3DAntiAlias	= 0x416c6973,
        phKeyA	= 0x41202020,
        phKeyAdjustment	= 0x41646a73,
        phKeyAligned	= 0x416c6764,
        phKeyAlignment	= 0x416c676e,
        phKeyAllPS	= 0x416c6c20,
        phKeyAllExcept	= 0x416c6c45,
        phKeyAllToolOptions	= 0x416c546c,
        phKeyAlphaChannelOptions	= 0x4143686e,
        phKeyAlphaChannels	= 0x416c7043,
        phKeyAmbientBrightness	= 0x416d6242,
        phKeyAmbientColor	= 0x416d6243,
        phKeyAmount	= 0x416d6e74,
        phKeyAmplitudeMax	= 0x416d4d78,
        phKeyAmplitudeMin	= 0x416d4d6e,
        phKeyAnchor	= 0x416e6368,
        phKeyAngle	= 0x416e676c,
        phKeyAngle1	= 0x416e6731,
        phKeyAngle2	= 0x416e6732,
        phKeyAngle3	= 0x416e6733,
        phKeyAngle4	= 0x416e6734,
        phKeyAntiAlias	= 0x416e7441,
        phKeyAppend	= 0x41707065,
        phKeyApply	= 0x41706c79,
        phKeyArea	= 0x41722020,
        phKeyArrowhead	= 0x41727277,
        phKeyAs	= 0x41732020,
        phKeyAssetBin	= 0x41737374,
        phKeyAssumedCMYK	= 0x41737343,
        phKeyAssumedGray	= 0x41737347,
        phKeyAssumedRGB	= 0x41737352,
        phKeyAt	= 0x41742020,
        phKeyAuto	= 0x4175746f,
        phKeyAutoContrast	= 0x4175436f,
        phKeyAutoErase	= 0x41747273,
        phKeyAutoKern	= 0x41744b72,
        phKeyAutoUpdate	= 0x41745570,
        phKeyShowMenuColors	= 0x53774d43,
        phKeyAxis	= 0x41786973,
        phKeyB	= 0x42202020,
        phKeyBackground	= 0x42636b67,
        phKeyBackgroundColor	= 0x42636b43,
        phKeyBackgroundLevel	= 0x42636b4c,
        phKeyBackward	= 0x42776420,
        phKeyBalance	= 0x426c6e63,
        phKeyBaselineShift	= 0x42736c6e,
        phKeyBeepWhenDone	= 0x42705768,
        phKeyBeginRamp	= 0x42676e52,
        phKeyBeginSustain	= 0x42676e53,
        phKeyBevelDirection	= 0x62766c44,
        phKeyBevelEmboss	= 0x6562626c,
        phKeyBevelStyle	= 0x62766c53,
        phKeyBevelTechnique	= 0x62766c54,
        phKeyBigNudgeH	= 0x42674e48,
        phKeyBigNudgeV	= 0x42674e56,
        phKeyBitDepth	= 0x42744470,
        phKeyBlack	= 0x426c636b,
        phKeyBlackClip	= 0x426c6343,
        phKeyBlackGeneration	= 0x426c636e,
        phKeyBlackGenerationCurve	= 0x426c6347,
        phKeyBlackIntensity	= 0x426c6349,
        phKeyBlackLevel	= 0x426c634c,
        phKeyBlackLimit	= 0x426c634c,
        phKeyBleed	= 0x426c6420,
        phKeyBlendRange	= 0x426c6e64,
        phKeyBlue	= 0x426c2020,
        phKeyBlueBlackPoint	= 0x426c426c,
        phKeyBlueGamma	= 0x426c476d,
        phKeyBlueWhitePoint	= 0x426c5768,
        phKeyBlueX	= 0x426c5820,
        phKeyBlueY	= 0x426c5920,
        phKeyBlur	= 0x626c7572,
        phKeyBlurMethod	= 0x426c724d,
        phKeyBlurQuality	= 0x426c7251,
        phKeyBook	= 0x426b2020,
        phKeyBorderThickness	= 0x42726454,
        phKeyBottom	= 0x42746f6d,
        phKeyBrightness	= 0x42726768,
        phKeyBrushDetail	= 0x42727344,
        phKeyBrushes	= 0x42727368,
        phKeyBrushSize	= 0x42727353,
        phKeyBrushType	= 0x42727354,
        phKeyBumpAmplitude	= 0x426d7041,
        phKeyBumpChannel	= 0x426d7043,
        phKeyBy	= 0x42792020,
        phKeyByline	= 0x42796c6e,
        phKeyBylineTitle	= 0x42796c54,
        phKeyByteOrder	= 0x4279744f,
        phKeyCachePrefs	= 0x43636850,
        phKeyChokeMatte	= 0x436b6d74,
        phKeyCloneSource	= 0x436c6e53,
        phKeyCMYKSetup	= 0x434d5953,
        phKeyCalculation	= 0x436c636c,
        phKeyCalibrationBars	= 0x436c6272,
        phKeyCaption	= 0x4370746e,
        phKeyCaptionWriter	= 0x43707457,
        phKeyCategory	= 0x43746772,
        phKeyCellSize	= 0x436c537a,
        phKeyCenter	= 0x436e7472,
        phKeyCenterCropMarks	= 0x436e7443,
        phKeyChalkArea	= 0x43686c41,
        phKeyChannel	= 0x43686e6c,
        phKeyChannelMatrix	= 0x43684d78,
        phKeyChannelName	= 0x43686e4e,
        phKeyChannels	= 0x43686e73,
        phKeyChannelsInterleaved	= 0x43686e49,
        phKeyCharcoalAmount	= 0x4368416d,
        phKeyCharcoalArea	= 0x43687241,
        phKeyChromeFX	= 0x43684658,
        phKeyCity	= 0x43697479,
        phKeyClearAmount	= 0x436c7241,
        phKeyClippingPath	= 0x436c5074,
        phKeyClippingPathEPS	= 0x436c7050,
        phKeyClippingPathFlatness	= 0x436c7046,
        phKeyClippingPathIndex	= 0x436c7049,
        phKeyClippingPathInfo	= 0x436c7067,
        phKeyClosedSubpath	= 0x436c7370,
        phKeyColor	= 0x436c7220,
        phKeyColorChannels	= 0x436c7268,
        phKeyColorCorrection	= 0x436c7243,
        phKeyColorIndicates	= 0x436c7249,
        phKeyColorManagement	= 0x436c4d67,
        phKeyColorPickerPrefs	= 0x436c7272,
        phKeyColorTable	= 0x436c7254,
        phKeyColorize	= 0x436c727a,
        phKeyColors	= 0x436c7273,
        phKeyColorsList	= 0x436c724c,
        phKeyColorSpace	= 0x436c7253,
        phKeyColumnWidth	= 0x436c6d57,
        phKeyCommandKey	= 0x436d644b,
        phKeyCompensation	= 0x436d706e,
        phKeyCompression	= 0x436d7072,
        phKeyConcavity	= 0x436e6376,
        phKeyCondition	= 0x436e6474,
        phKeyConstant	= 0x436e7374,
        phKeyConstrain	= 0x436e7374,
        phKeyConstrainProportions	= 0x436e7350,
        phKeyConstructionFOV	= 0x43666f76,
        phKeyContiguous	= 0x436e7467,
        phKeyContinue	= 0x436e746e,
        phKeyContinuity	= 0x436e7479,
        phKeyContrast	= 0x436e7472,
        phKeyConvert	= 0x436e7672,
        phKeyCopy	= 0x43707920,
        phKeyCopyright	= 0x43707972,
        phKeyCopyrightNotice	= 0x4370724e,
        phKeyCornerCropMarks	= 0x43726e43,
        phKeyCount	= 0x436e7420,
        phKeyCountryName	= 0x436e744e,
        phKeyCrackBrightness	= 0x43726342,
        phKeyCrackDepth	= 0x43726344,
        phKeyCrackSpacing	= 0x43726353,
        phKeyCreateLayersFromLayerFX	= 0x626c666c,
        phKeyCredit	= 0x43726474,
        phKeyCrossover	= 0x43727373,
        phKeyCurrent	= 0x43726e74,
        phKeyCurrentHistoryState	= 0x43726e48,
        phKeyCurrentLight	= 0x43726e4c,
        phKeyCurrentToolOptions	= 0x43726e54,
        phKeyCurve	= 0x43727620,
        phKeyCurveFile	= 0x43727646,
        phKeyCustom	= 0x4373746d,
        phKeyCustomForced	= 0x43737446,
        phKeyCustomMatte	= 0x4373744d,
        phKeyCustomPalette	= 0x43737450,
        phKeyCyan	= 0x43796e20,
        phKeyDarkIntensity	= 0x44726b49,
        phKeyDarkness	= 0x44726b6e,
        phKeyDateCreated	= 0x44744372,
        phKeyDatum	= 0x44742020,
        phKeyDCS	= 0x44435320,
        phKeyDefinition	= 0x44666e74,
        phKeyDensity	= 0x446e7374,
        phKeyDepth	= 0x44707468,
        phKeyDestBlackMax	= 0x4473746c,
        phKeyDestBlackMin	= 0x44737442,
        phKeyDestinationMode	= 0x4473744d,
        phKeyDestWhiteMax	= 0x44737474,
        phKeyDestWhiteMin	= 0x44737457,
        phKeyDetail	= 0x44746c20,
        phKeyDiameter	= 0x446d7472,
        phKeyDiffusionDither	= 0x44666644,
        phKeyDirection	= 0x44726374,
        phKeyDirectionBalance	= 0x44726342,
        phKeyDisplaceFile	= 0x44737046,
        phKeyDisplacementMap	= 0x4473704d,
        phKeyDisplayPrefs	= 0x44737050,
        phKeyDistance	= 0x4473746e,
        phKeyDistortion	= 0x44737472,
        phKeyDistribution	= 0x44737472,
        phKeyDither	= 0x44746872,
        phKeyDitherAmount	= 0x44746841,
        phKeyDitherPreserve	= 0x44746870,
        phKeyDitherQuality	= 0x44746871,
        phKeyDocumentID	= 0x446f6349,
        phKeyDotGain	= 0x4474476e,
        phKeyDotGainCurves	= 0x44744743,
        phKeyDPXFormat	= 0x44505866,
        phKeyDropShadow	= 0x44725368,
        phKeyDuplicate	= 0x44706c63,
        phKeyDynamicColorSliders	= 0x446e6d43,
        phKeyEdge	= 0x45646720,
        phKeyEdgeBrightness	= 0x45646742,
        phKeyEdgeFidelity	= 0x45646746,
        phKeyEdgeIntensity	= 0x45646749,
        phKeyEdgeSimplicity	= 0x45646753,
        phKeyEdgeThickness	= 0x45646754,
        phKeyEdgeWidth	= 0x45646757,
        phKeyEffect	= 0x45666663,
        phKeyEmbedProfiles	= 0x456d6250,
        phKeyEmbedCMYK	= 0x456d6243,
        phKeyEmbedGray	= 0x456d6247,
        phKeyEmbedLab	= 0x456d624c,
        phKeyEmbedRGB	= 0x456d6252,
        phKeyEmulsionDown	= 0x456d6c44,
        phKeyEnabled	= 0x656e6162,
        phKeyEnableGestures	= 0x45477374,
        phKeyEncoding	= 0x456e6364,
        phKeyEnd	= 0x456e6420,
        phKeyEndArrowhead	= 0x456e6441,
        phKeyEndRamp	= 0x456e6452,
        phKeyEndSustain	= 0x456e6453,
        phKeyEngine	= 0x456e676e,
        phKeyEraserKind	= 0x4572734b,
        phKeyEraseToHistory	= 0x45727354,
        phKeyExactPoints	= 0x45786350,
        phKeyExport	= 0x45787072,
        phKeyExportClipboard	= 0x45787043,
        phKeyExposure	= 0x45787073,
        phKeyExtend	= 0x45787464,
        phKeyExtension	= 0x4578746e,
        phKeyExtensionsQuery	= 0x45787451,
        phKeyExtrudeDepth	= 0x45787444,
        phKeyExtrudeMaskIncomplete	= 0x4578744d,
        phKeyExtrudeRandom	= 0x45787452,
        phKeyExtrudeSize	= 0x45787453,
        phKeyExtrudeSolidFace	= 0x45787446,
        phKeyExtrudeType	= 0x45787454,
        phKeyEyeDropperSample	= 0x45794472,
        phKeyFadeoutSteps	= 0x46647453,
        phKeyFadeTo	= 0x46645420,
        phKeyFalloff	= 0x466c4f66,
        phKeyFPXCompress	= 0x4678436d,
        phKeyFPXQuality	= 0x4678516c,
        phKeyFPXSize	= 0x4678537a,
        phKeyFPXView	= 0x46785677,
        phKeyFeather	= 0x46746872,
        phKeyFiberLength	= 0x4662724c,
        phKeyFile	= 0x46696c65,
        phKeyFileCreator	= 0x466c4372,
        phKeyFileInfo	= 0x466c496e,
        phKeyFileReference	= 0x46696c52,
        phKeyFileSavePrefs	= 0x466c5350,
        phKeyFilesList	= 0x666c7374,
        phKeyFileType	= 0x466c5479,
        phKeyFill	= 0x466c2020,
        phKeyFillColor	= 0x466c436c,
        phKeyFillNeutral	= 0x466c4e74,
        phKeyFilterLayerRandomSeed	= 0x466c5273,
        phKeyFilterLayerPersistentData	= 0x466c5064,
        phKeyFingerpainting	= 0x466e6772,
        phKeyFlareCenter	= 0x466c7243,
        phKeyFlatness	= 0x466c746e,
        phKeyFlatten	= 0x466c7474,
        phKeyFlipVertical	= 0x466c7056,
        phKeyFocus	= 0x46637320,
        phKeyFolders	= 0x466c6472,
        phKeyFontDesignAxes	= 0x466e7444,
        phKeyFontDesignAxesVectors	= 0x466e7456,
        phKeyFontName	= 0x466e744e,
        phKeyFontScript	= 0x53637270,
        phKeyFontStyleName	= 0x466e7453,
        phKeyFontTechnology	= 0x466e7454,
        phKeyForcedColors	= 0x46726343,
        phKeyForegroundColor	= 0x46726743,
        phKeyForegroundLevel	= 0x4672674c,
        phKeyFormat	= 0x466d7420,
        phKeyForward	= 0x46776420,
        phKeyFrameFX	= 0x46724658,
        phKeyFrameWidth	= 0x46726d57,
        phKeyFreeTransformCenterState	= 0x46546373,
        phKeyFrequency	= 0x4672716e,
        phKeyFrom	= 0x46726f6d,
        phKeyFromBuiltin	= 0x46726d42,
        phKeyFromMode	= 0x46726d4d,
        phKeyFunctionKey	= 0x466e634b,
        phKeyFuzziness	= 0x467a6e73,
        phKeyGamutWarning	= 0x476d7457,
        phKeyGCR	= 0x47435220,
        phKeyGeneralPrefs	= 0x476e7250,
        phKeyGIFColorFileType	= 0x47465054,
        phKeyGIFColorLimit	= 0x4746434c,
        phKeyGIFExportCaption	= 0x47464543,
        phKeyGIFMaskChannelIndex	= 0x47464d49,
        phKeyGIFMaskChannelInverted	= 0x47464d56,
        phKeyGIFPaletteFile	= 0x47465046,
        phKeyGIFPaletteType	= 0x4746504c,
        phKeyGIFRequiredColorSpaceType	= 0x47464353,
        phKeyGIFRowOrderType	= 0x47464954,
        phKeyGIFTransparentColor	= 0x47465443,
        phKeyGIFTransparentIndexBlue	= 0x47465442,
        phKeyGIFTransparentIndexGreen	= 0x47465447,
        phKeyGIFTransparentIndexRed	= 0x47465452,
        phKeyGIFUseBestMatch	= 0x4746424d,
        phKeyGamma	= 0x476d6d20,
        phKeyGlobalAngle	= 0x67626c41,
        phKeyGlobalLightingAngle	= 0x6761676c,
        phKeyGloss	= 0x476c6f73,
        phKeyGlowAmount	= 0x476c7741,
        phKeyGlowTechnique	= 0x476c7754,
        phKeyGradient	= 0x47726164,
        phKeyGradientFill	= 0x47726466,
        phKeyGrain	= 0x47726e20,
        phKeyGrainType	= 0x47726e74,
        phKeyGraininess	= 0x47726e73,
        phKeyGray	= 0x47727920,
        phKeyGrayBehavior	= 0x47724268,
        phKeyGraySetup	= 0x47725374,
        phKeyGreen	= 0x47726e20,
        phKeyGreenBlackPoint	= 0x47726e42,
        phKeyGreenGamma	= 0x47726e47,
        phKeyGreenWhitePoint	= 0x47726e57,
        phKeyGreenX	= 0x47726e58,
        phKeyGreenY	= 0x47726e59,
        phKeyGridColor	= 0x47726443,
        phKeyGridCustomColor	= 0x47726473,
        phKeyGridMajor	= 0x4772644d,
        phKeyGridMinor	= 0x4772646e,
        phKeyGridStyle	= 0x47726453,
        phKeyGridUnits	= 0x47726474,
        phKeyGroup	= 0x47727570,
        phKeyGroutWidth	= 0x47727457,
        phKeyGrowSelection	= 0x47727753,
        phKeyGuides	= 0x47646573,
        phKeyGuidesColor	= 0x47647343,
        phKeyGuidesCustomColor	= 0x47647373,
        phKeyGuidesStyle	= 0x47647353,
        phKeyGuidesPrefs	= 0x47645072,
        phKeyGutterWidth	= 0x47747457,
        phKeyHalftoneFile	= 0x486c6646,
        phKeyHalftoneScreen	= 0x486c6653,
        phKeyHalftoneSpec	= 0x486c6670,
        phKeyHalftoneSize	= 0x486c537a,
        phKeyHardness	= 0x4872646e,
        phKeyHasCmdHPreference	= 0x48436448,
        phKeyHeader	= 0x48647220,
        phKeyHeadline	= 0x48646c6e,
        phKeyHeight	= 0x48676874,
        phKeyHostName	= 0x4873744e,
        phKeyHighlightArea	= 0x48676841,
        phKeyHighlightColor	= 0x68676c43,
        phKeyHighlightLevels	= 0x4867684c,
        phKeyHighlightMode	= 0x68676c4d,
        phKeyHighlightOpacity	= 0x68676c4f,
        phKeyHighlightStrength	= 0x48676853,
        phKeyHistoryBrushSource	= 0x48737442,
        phKeyHistoryPrefs	= 0x48737450,
        phKeyHistoryStateSource	= 0x48735353,
        phKeyHistoryStates	= 0x48735374,
        phKeyHorizontal	= 0x48727a6e,
        phKeyHorizontalScale	= 0x48727a53,
        phKeyHostVersion	= 0x48737456,
        phKeyHue	= 0x48202020,
        phKeyICCEngine	= 0x49434345,
        phKeyICCSetupName	= 0x49434374,
        phKeyID	= 0x49646e74,
        phKeyIdle	= 0x49646c65,
        phKeyImageBalance	= 0x496d6742,
        phKeyImport	= 0x496d7072,
        phKeyImpressionist	= 0x496d7073,
        phKeyIn	= 0x496e2020,
        phKeyInherits	= 0x6340235e,
        phKeyInkColors	= 0x496e6b43,
        phKeyInks	= 0x496e6b73,
        phKeyInnerGlow	= 0x4972476c,
        phKeyInnerGlowSource	= 0x676c7753,
        phKeyInnerShadow	= 0x49725368,
        phKeyInput	= 0x496e7074,
        phKeyInputBlackPoint	= 0x6b494250,
        phKeyInputMapRange	= 0x496e6d72,
        phKeyInputRange	= 0x496e7072,
        phKeyInputWhitePoint	= 0x6b495750,
        phKeyIntensity	= 0x496e746e,
        phKeyIntent	= 0x496e7465,
        phKeyInterfaceBevelHighlight	= 0x496e7448,
        phKeyInterfaceBevelShadow	= 0x496e7476,
        phKeyInterfaceBlack	= 0x496e7442,
        phKeyInterfaceBorder	= 0x496e7464,
        phKeyInterfaceButtonDarkShadow	= 0x496e746b,
        phKeyInterfaceButtonDownFill	= 0x496e7474,
        phKeyInterfaceButtonUpFill	= 0x496e4246,
        phKeyInterfaceColorBlue2	= 0x4943424c,
        phKeyInterfaceColorBlue32	= 0x49434248,
        phKeyInterfaceColorGreen2	= 0x4943474c,
        phKeyInterfaceColorGreen32	= 0x49434748,
        phKeyInterfaceColorRed2	= 0x4943524c,
        phKeyInterfaceColorRed32	= 0x49435248,
        phKeyInterfaceIconFillActive	= 0x496e7449,
        phKeyInterfaceIconFillDimmed	= 0x496e7446,
        phKeyInterfaceIconFillSelected	= 0x496e7463,
        phKeyInterfaceIconFrameActive	= 0x496e746d,
        phKeyInterfaceIconFrameDimmed	= 0x496e7472,
        phKeyInterfaceIconFrameSelected	= 0x496e7453,
        phKeyInterfacePaletteFill	= 0x496e7450,
        phKeyInterfaceRed	= 0x496e7452,
        phKeyInterfaceWhite	= 0x496e7457,
        phKeyInterfaceToolTipBackground	= 0x496e7454,
        phKeyInterfaceToolTipText	= 0x49545454,
        phKeyInterfaceTransparencyForeground	= 0x49544667,
        phKeyInterfaceTransparencyBackground	= 0x49544267,
        phKeyInterlace	= 0x496e7472,
        phKeyInterlaceCreateType	= 0x496e7443,
        phKeyInterlaceEliminateType	= 0x496e7445,
        phKeyInterpolation	= 0x496e7472,
        phKeyInterpolationMethod	= 0x496e744d,
        phKeyInvert	= 0x496e7672,
        phKeyInvertMask	= 0x496e764d,
        phKeyInvertSource2	= 0x496e7653,
        phKeyInvertTexture	= 0x496e7654,
        phKeyIsDirty	= 0x49734472,
        phKeyItemIndex	= 0x49746d49,
        phKeyJPEGQuality	= 0x4a504551,
        phKeyKerning	= 0x4b726e67,
        phKeyKeywords	= 0x4b797764,
        phKeyKind	= 0x4b6e6420,
        phKeyLZWCompression	= 0x4c5a5743,
        phKeyLabels	= 0x4c626c73,
        phKeyLandscape	= 0x4c6e6473,
        phKeyLastTransform	= 0x4c737454,
        phKeyLayerEffects	= 0x4c656678,
        phKeyLayerFXVisible	= 0x6c667876,
        phKeyLayer	= 0x4c797220,
        phKeyLayerID	= 0x4c797249,
        phKeyLayerName	= 0x4c79724e,
        phKeyLayers	= 0x4c797273,
        phKeyLeading	= 0x4c646e67,
        phKeyLeft	= 0x4c656674,
        phKeyTermLength	= 0x4c6e6774,
        phKeyLens	= 0x4c6e7320,
        phKeyLevel	= 0x4c766c20,
        phKeyLevels	= 0x4c766c73,
        phKeyLightDark	= 0x4c674472,
        phKeyLightDirection	= 0x4c676844,
        phKeyLightIntensity	= 0x4c676849,
        phKeyLightPosition	= 0x4c676850,
        phKeyLightSource	= 0x4c676853,
        phKeyLightType	= 0x4c676854,
        phKeyLightenGrout	= 0x4c676847,
        phKeyLightness	= 0x4c676874,
        phKeyLine	= 0x4c696e65,
        phKeyLinkedLayerIDs	= 0x4c6e6b4c,
        phKeyLocalLightingAngle	= 0x6c61676c,
        phKeyLocalLightingAltitude	= 0x4c616c64,
        phKeyLocalRange	= 0x4c636c52,
        phKeyLocation	= 0x4c63746e,
        phKeyLog	= 0x4c6f6720,
        phKeyLogarithmic	= 0x6b4c6f67,
        phKeyLowerCase	= 0x4c774373,
        phKeyLuminance	= 0x4c6d6e63,
        phKeyLUTAnimation	= 0x4c546e6d,
        phKeyMagenta	= 0x4d676e74,
        phKeyMakeVisible	= 0x4d6b5673,
        phKeyManipulationFOV	= 0x4d666f76,
        phKeyMapBlack	= 0x4d70426c,
        phKeyMapping	= 0x4d706e67,
        phKeyMappingShape	= 0x4d706753,
        phKeyMaterial	= 0x4d74726c,
        phKeyMatrix	= 0x4d747278,
        phKeyMatteColor	= 0x4d747443,
        phKeyMaximum	= 0x4d786d20,
        phKeyMaximumStates	= 0x4d786d53,
        phKeyMemoryUsagePercent	= 0x4d6d7255,
        phKeyMerge	= 0x4d726765,
        phKeyMerged	= 0x4d726764,
        phKeyMessage	= 0x4d736765,
        phKeyMethod	= 0x4d746864,
        phKeyMezzotintType	= 0x4d7a7454,
        phKeyMidpoint	= 0x4d64706e,
        phKeyMidtoneLevels	= 0x4d64744c,
        phKeyMinimum	= 0x4d6e6d20,
        phKeyMismatchCMYK	= 0x4d736d43,
        phKeyMismatchGray	= 0x4d736d47,
        phKeyMismatchRGB	= 0x4d736d52,
        phKeyMode	= 0x4d642020,
        phKeyMonochromatic	= 0x4d6e6368,
        phKeyMoveTo	= 0x4d765420,
        phKeyName	= 0x4e6d2020,
        phKeyNegative	= 0x4e677476,
        phKeyNew	= 0x4e772020,
        phKeyNoise	= 0x4e6f7365,
        phKeyNonImageData	= 0x4e6e496d,
        phKeyNonLinear	= 0x4e6e4c6e,
        phKeyNull	= 0x6e756c6c,
        phKeyNumLights	= 0x4e6d2020,
        phKeyNumber	= 0x4e6d6272,
        phKeyNumberOfCacheLevels	= 0x4e436368,
        phKeyNumberOfCacheLevels64	= 0x4e433634,
        phKeyNumberOfChannels	= 0x4e6d624f,
        phKeyNumberOfChildren	= 0x4e6d6243,
        phKeyNumberOfDocuments	= 0x4e6d6244,
        phKeyNumberOfGenerators	= 0x4e6d6247,
        phKeyNumberOfLayers	= 0x4e6d624c,
        phKeyNumberOfLevels	= 0x4e6d624c,
        phKeyNumberOfPaths	= 0x4e6d6250,
        phKeyNumberOfRipples	= 0x4e6d6252,
        phKeyNumberOfSiblings	= 0x4e6d6253,
        phKeyObjectName	= 0x4f626a4e,
        phKeyOffset	= 0x4f667374,
        phKeyOn	= 0x4f6e2020,
        phKeyOpacity	= 0x4f706374,
        phKeyOptimized	= 0x4f70746d,
        phKeyOrientation	= 0x4f726e74,
        phKeyOriginalHeader	= 0x4f726748,
        phKeyOriginalTransmissionReference	= 0x4f726754,
        phKeyOtherCursors	= 0x4f746843,
        phKeyOuterGlow	= 0x4f72476c,
        phKeyOutput	= 0x4f747074,
        phKeyOutputBlackPoint	= 0x6b4f4250,
        phKeyOutputWhitePoint	= 0x6b4f5750,
        phKeyOverprintColors	= 0x4f767243,
        phKeyOverrideOpen	= 0x4f76724f,
        phKeyOverridePrinter	= 0x4f627250,
        phKeyOverrideSave	= 0x4f767264,
        phKeyPaintCursorKind	= 0x506e434b,
        phKeyParentIndex	= 0x5072496e,
        phKeyParentName	= 0x50724e6d,
        phKeyPNGFilter	= 0x504e4766,
        phKeyPNGInterlaceType	= 0x50474954,
        phKeyPageFormat	= 0x504d7066,
        phKeyPageNumber	= 0x50674e6d,
        phKeyPageSetup	= 0x50675374,
        phKeyPagePosition	= 0x50675073,
        phKeyPaintingCursors	= 0x506e7443,
        phKeyPaintType	= 0x506e7454,
        phKeyPalette	= 0x506c7420,
        phKeyPaletteFile	= 0x506c7446,
        phKeyPaperBrightness	= 0x50707242,
        phPSkeyPath	= 0x50617468,
        phKeyPathContents	= 0x50746843,
        phKeyPathName	= 0x5074684e,
        phKeyPattern	= 0x5074746e,
        phKeyPencilWidth	= 0x506e636c,
        phKeyPerspectiveIndex	= 0x50727370,
        phKeyPhosphors	= 0x50687370,
        phKeyPickerID	= 0x50636b49,
        phKeyPickerKind	= 0x50636b72,
        phKeyPixelPaintSize	= 0x5050537a,
        phKeyPlatform	= 0x506c7466,
        phKeyPluginFolder	= 0x506c6746,
        phKeyPluginPrefs	= 0x506c6750,
        phKeyPoints	= 0x50747320,
        phKeyPosition	= 0x5073746e,
        phKeyPosterization	= 0x50737472,
        phKeyPostScriptColor	= 0x50737453,
        phKeyPredefinedColors	= 0x50726443,
        phKeyPreferBuiltin	= 0x50726642,
        phKeyPreserveAdditional	= 0x50727341,
        phKeyPreserveLuminosity	= 0x5072734c,
        phKeyPreserveTransparency	= 0x50727354,
        phKeyPressure	= 0x50727320,
        phKeyPreferences	= 0x50726672,
        phKeyPreview	= 0x50727677,
        phKeyPreviewCMYK	= 0x5072764b,
        phKeyPreviewFullSize	= 0x50727646,
        phKeyPreviewIcon	= 0x50727649,
        phKeyPreviewMacThumbnail	= 0x5072764d,
        phKeyPreviewWinThumbnail	= 0x50727657,
        phKeyPreviewsQuery	= 0x50727651,
        phKeyPrintSettings	= 0x504d7073,
        phKeyProfileSetup	= 0x50726653,
        phKeyProvinceState	= 0x50727653,
        phKeyQuality	= 0x516c7479,
        phKeyExtendedQuality	= 0x45516c74,
        phKeyQuickMask	= 0x5175634d,
        phKeyRGBSetup	= 0x52474253,
        phKeyRadius	= 0x52647320,
        phKeyRandomSeed	= 0x526e6453,
        phKeyRatio	= 0x52742020,
        phKeyRecentFiles	= 0x52636e66,
        phKeyRed	= 0x52642020,
        phKeyRedBlackPoint	= 0x5264426c,
        phKeyRedGamma	= 0x5264476d,
        phKeyRedWhitePoint	= 0x52645768,
        phKeyRedX	= 0x52645820,
        phKeyRedY	= 0x52645920,
        phKeyRegistrationMarks	= 0x5267734d,
        phKeyRelative	= 0x526c7476,
        phKeyRelief	= 0x526c6620,
        phKeyRenderFidelity	= 0x52666964,
        phKeyResample	= 0x52736d70,
        phKeyResizeWindowsOnZoom	= 0x52574f5a,
        phKeyResolution	= 0x52736c74,
        phKeyResourceID	= 0x52737249,
        phKeyResponse	= 0x5273706e,
        phKeyRetainHeader	= 0x52746e48,
        phKeyReverse	= 0x52767273,
        phKeyRight	= 0x52676874,
        phKeyRippleMagnitude	= 0x52706c4d,
        phKeyRippleSize	= 0x52706c53,
        phKeyRotate	= 0x52747420,
        phKeyRoundness	= 0x526e646e,
        phKeyRulerOriginH	= 0x526c7248,
        phKeyRulerOriginV	= 0x526c7256,
        phKeyRulerUnits	= 0x526c7255,
        phKeySaturation	= 0x53747274,
        phKeySaveAndClose	= 0x5376416e,
        phKeySaveComposite	= 0x5376436d,
        phKeySavePaletteLocations	= 0x506c744c,
        phKeySavePaths	= 0x53765074,
        phKeySavePyramids	= 0x53765079,
        phKeySaving	= 0x53766e67,
        phKeyScale	= 0x53636c20,
        phKeyScaleHorizontal	= 0x53636c48,
        phKeyScaleVertical	= 0x53636c56,
        phKeyScaling	= 0x53636c6e,
        phKeyScans	= 0x53636e73,
        phKeyScratchDisks	= 0x53637244,
        phKeyScreenFile	= 0x53637246,
        phKeyScreenType	= 0x53637254,
        phKeyShadingIntensity	= 0x53686449,
        phKeyShadingNoise	= 0x5368644e,
        phKeyShadingShape	= 0x53686453,
        phKeyContourType	= 0x53687043,
        phKeySerialString	= 0x53726c53,
        phKeySeparations	= 0x53707274,
        phKeyShadowColor	= 0x73647743,
        phKeyShadowIntensity	= 0x53686449,
        phKeyShadowLevels	= 0x5368644c,
        phKeyShadowMode	= 0x7364774d,
        phKeyShadowOpacity	= 0x7364774f,
        phKeyShape	= 0x53687020,
        phKeySharpness	= 0x53687270,
        phKeyShearEd	= 0x53687245,
        phKeyShearPoints	= 0x53687250,
        phKeyShearSt	= 0x53687253,
        phKeyShiftKey	= 0x5368664b,
        phKeyShiftKeyToolSwitch	= 0x53684b54,
        phKeyShortNames	= 0x5368724e,
        phKeyShowEnglishFontNames	= 0x53687745,
        phKeyShowToolTips	= 0x53687754,
        phKeyShowTransparency	= 0x53685472,
        phKeySizeKey	= 0x537a2020,
        phKeySkew	= 0x536b6577,
        phKeySmartBlurMode	= 0x536d424d,
        phKeySmartBlurQuality	= 0x536d4251,
        phKeySmooth	= 0x536d6f6f,
        phKeySmoothness	= 0x536d7468,
        phKeySnapshotInitial	= 0x536e7049,
        phKeySoftClip	= 0x5366436c,
        phKeySoftness	= 0x5366746e,
        phKeySmallFontType	= 0x53667473,
        phKeyOldSmallFontType	= 0x53667474,
        phKeySolidFill	= 0x536f4669,
        phKeySource	= 0x53726365,
        phKeySource2	= 0x53726332,
        phKeySourceMode	= 0x5372634d,
        phKeySpacing	= 0x5370636e,
        phKeySpecialInstructions	= 0x53706349,
        phKeySpherizeMode	= 0x5370684d,
        phKeySpot	= 0x53706f74,
        phKeySprayRadius	= 0x53707252,
        phKeySquareSize	= 0x53717253,
        phKeySrcBlackMax	= 0x5372636c,
        phKeySrcBlackMin	= 0x53726342,
        phKeySrcWhiteMax	= 0x5372636d,
        phKeySrcWhiteMin	= 0x53726357,
        phKeyStart	= 0x53747274,
        phKeyStartArrowhead	= 0x53747241,
        phKeyState	= 0x53747465,
        phKeyStrength	= 0x73726768,
        phKeyStrengthRatio	= 0x73726752,
        phKeyStrength_PLUGIN	= 0x53747267,
        phKeyStrokeDetail	= 0x53744474,
        phKeyStrokeDirection	= 0x53446972,
        phKeyStrokeLength	= 0x5374724c,
        phKeyStrokePressure	= 0x53747250,
        phKeyStrokeSize	= 0x53747253,
        phKeyStrokeWidth	= 0x53747257,
        phKeyStyle	= 0x5374796c,
        phKeyStyles	= 0x53747973,
        phKeyStylusIsPressure	= 0x53746c50,
        phKeyStylusIsColor	= 0x53746c43,
        phKeyStylusIsOpacity	= 0x53746c4f,
        phKeyStylusIsSize	= 0x53746c53,
        phKeySubPathList	= 0x5362704c,
        phKeySupplementalCategories	= 0x53706c43,
        phKeySystemInfo	= 0x53737449,
        phKeySystemPalette	= 0x53737450,
        phKeyTarget	= 0x6e756c6c,
        phKeyTargetPath	= 0x54726770,
        phKeyTargetPathIndex	= 0x54726750,
        phKeyText	= 0x54787420,
        phKeyTextClickPoint	= 0x54787443,
        phKeyTextData	= 0x54787444,
        phKeyTextStyle	= 0x54787453,
        phKeyTextStyleRange	= 0x54787474,
        phKeyTexture	= 0x54787472,
        phKeyTextureCoverage	= 0x54787443,
        phKeyTextureFile	= 0x54787446,
        phKeyTextureType	= 0x54787454,
        phKeyThreshold	= 0x54687368,
        phKeyTileNumber	= 0x546c4e6d,
        phKeyTileOffset	= 0x546c4f66,
        phKeyTileSize	= 0x546c537a,
        phKeyTitle	= 0x54746c20,
        phKeyTo	= 0x54202020,
        phKeyToBuiltin	= 0x54426c20,
        phKeyToLinked	= 0x546f4c6b,
        phKeyToMode	= 0x544d6420,
        phKeyToggleOthers	= 0x54676c4f,
        phKeyTolerance	= 0x546c726e,
        phKeyTop	= 0x546f7020,
        phKeyTotalLimit	= 0x54746c4c,
        phKeyTracking	= 0x5472636b,
        phKeyTransferSpec	= 0x54726e53,
        phKeyTransparencyGrid	= 0x54726e47,
        phKeyTransferFunction	= 0x54726e46,
        phKeyTransparency	= 0x54726e73,
        phKeyTransparencyGridColors	= 0x54726e43,
        phKeyTransparencyGridSize	= 0x54726e47,
        phKeyTransparencyPrefs	= 0x54726e50,
        phKeyTransparencyShape	= 0x54726e53,
        phKeyTransparentIndex	= 0x54726e49,
        phKeyTransparentWhites	= 0x54726e57,
        phKeyTwist	= 0x54777374,
        phKeyType	= 0x54797065,
        phKeyUCA	= 0x55432020,
        phKeyUnitsPrefs	= 0x556e7450,
        phKeyURL	= 0x55524c20,
        phKeyUndefinedArea	= 0x556e6441,
        phKeyUnderline	= 0x556e646c,
        phKeyUntitled	= 0x556e746c,
        phKeyUpperY	= 0x55707059,
        phKeyUrgency	= 0x5572676e,
        phKeyUseAccurateScreens	= 0x41637253,
        phKeyUseAdditionalPlugins	= 0x4164506c,
        phKeyUseCacheForHistograms	= 0x55734363,
        phKeyUseCurves	= 0x55734372,
        phKeyUseDefault	= 0x55734466,
        phKeyUseGlobalAngle	= 0x75676c67,
        phKeyUseICCProfile	= 0x55734943,
        phKeyUseMask	= 0x55734d73,
        phKeyUserMaskEnabled	= 0x5573724d,
        phKeyUserMaskLinked	= 0x55737273,
        phKeyLinkEnable	= 0x6c6e6b45,
        phKeyUsing	= 0x55736e67,
        phKeyValue	= 0x566c2020,
        phKeyVariance	= 0x56726e63,
        phKeyVector0	= 0x56637430,
        phKeyVector1	= 0x56637431,
        phKeyVectorColor	= 0x56637443,
        phKeyVersionFix	= 0x56727346,
        phKeyVersionMajor	= 0x5672734d,
        phKeyVersionMinor	= 0x5672734e,
        phKeyVertical	= 0x56727463,
        phKeyVerticalScale	= 0x56727453,
        phKeyVideoAlpha	= 0x56646c70,
        phKeyVisible	= 0x5673626c,
        phKeyWatchSuspension	= 0x57746353,
        phKeyWatermark	= 0x77617472,
        phKeyWaveType	= 0x57767470,
        phKeyWavelengthMax	= 0x574c4d78,
        phKeyWavelengthMin	= 0x574c4d6e,
        phKeyWebdavPrefs	= 0x57626450,
        phKeyWetEdges	= 0x57746467,
        phKeyWhat	= 0x57686174,
        phKeyWhiteClip	= 0x57687443,
        phKeyWhiteIntensity	= 0x57687449,
        phKeyWhiteIsHigh	= 0x57684869,
        phKeyWhiteLevel	= 0x5768744c,
        phKeyWhitePoint	= 0x57687450,
        phKeyWholePath	= 0x57685074,
        phKeyWidth	= 0x57647468,
        phKeyWindMethod	= 0x576e644d,
        phKeyWith	= 0x57697468,
        phKeyWorkPath	= 0x57725074,
        phKeyWorkPathIndex	= 0x57726b50,
        phKeyX	= 0x58202020,
        phKeyY	= 0x59202020,
        phKeyYellow	= 0x596c7720,
        phKeyZigZagType	= 0x5a5a5479,
        phKeyLighter	= 0x4c696768,
        phKeyDarker	= 0x4461726b,
        phKeyStartUpInPrefs	= 0x53747570,
        phKeyLegacySerialString	= 0x6c534e73,
        phKey_Source	= 0x54202020,
        phPInherits	= 0x6340235e,
        phTypeActionReference	= 0x23416374,
        phTypeActionData	= 0x41637444,
        phTypeAlignDistributeSelector	= 0x41445374,
        phTypeAlignment	= 0x416c6720,
        phTypeAmount	= 0x416d6e74,
        phTypeAntiAlias	= 0x416e6e74,
        phTypeAreaSelector	= 0x4172536c,
        phTypeAssumeOptions	= 0x4173734f,
        phTypeBevelEmbossStampStyle	= 0x42455373,
        phTypeBevelEmbossStyle	= 0x4245536c,
        phTypeBitDepth	= 0x42744470,
        phTypeBlackGeneration	= 0x426c6347,
        phTypeBlendMode	= 0x426c6e4d,
        phTypeBlurMethod	= 0x426c724d,
        phTypeBlurQuality	= 0x426c7251,
        phTypeBrushType	= 0x42727354,
        phTypeBuiltinProfile	= 0x426c7450,
        phTypeBuiltInContour	= 0x426c7443,
        phTypeCMYKSetupEngine	= 0x434d5945,
        phTypeCalculation	= 0x436c636e,
        phTypeChannel	= 0x43686e6c,
        phTypeChannelReference	= 0x23436852,
        phTypeCheckerboardSize	= 0x4368636b,
        phTypeClass	= 0x74797065,
        phTypeClassColor	= 0x23436c72,
        phTypeClassElement	= 0x23436c45,
        phTypeClassExport	= 0x23436c65,
        phTypeClassFormat	= 0x23436c46,
        phTypeClassHueSatHueSatV2	= 0x23487356,
        phTypeClassImport	= 0x23436c49,
        phTypeClassMode	= 0x23436c4d,
        phTypeClassStringFormat	= 0x23436c53,
        phTypeClassTextExport	= 0x23435445,
        phTypeClassTextImport	= 0x23436c54,
        phTypeColor	= 0x436c7220,
        phTypeColorChannel	= 0x23436c43,
        phTypeColorPalette	= 0x436c7250,
        phTypeColorSpace	= 0x436c7253,
        phTypeColorStopType	= 0x436c7279,
        phTypeColors	= 0x436c7273,
        phTypeCompensation	= 0x436d706e,
        phTypeContourEdge	= 0x436e7445,
        phTypeConvert	= 0x436e7672,
        phTypeCorrectionMethod	= 0x4372634d,
        phTypeCursorKind	= 0x4372734b,
        phTypeDCS	= 0x44435320,
        phTypeDeepDepth	= 0x44704470,
        phTypeDepth	= 0x44707468,
        phTypeDiffuseMode	= 0x4466734d,
        phTypeDirection	= 0x44726374,
        phTypeDisplacementMap	= 0x4473704d,
        phTypeDistribution	= 0x44737472,
        phTypeDither	= 0x44746872,
        phTypeDitherQuality	= 0x44746871,
        phTypeDocumentReference	= 0x23446352,
        phTypeEPSPreview	= 0x45505350,
        phTypeElementReference	= 0x23456c52,
        phTypeEncoding	= 0x456e6364,
        phTypeEraserKind	= 0x4572734b,
        phTypeExtrudeRandom	= 0x45787452,
        phTypeExtrudeType	= 0x45787454,
        phTypeEyeDropperSample	= 0x45794470,
        phTypeFPXCompress	= 0x4678436d,
        phTypeFill	= 0x466c2020,
        phTypeFillColor	= 0x466c436c,
        phTypeFillContents	= 0x466c436e,
        phTypeFillMode	= 0x466c4d64,
        phTypeForcedColors	= 0x46726343,
        phTypeFrameFill	= 0x4672466c,
        phTypeFrameStyle	= 0x4653746c,
        phTypeGIFColorFileType	= 0x47465054,
        phTypeGIFPaletteType	= 0x4746504c,
        phTypeGIFRequiredColorSpaceType	= 0x47464353,
        phTypeGIFRowOrderType	= 0x47464954,
        phTypeGlobalClass	= 0x476c6243,
        phTypeGlobalObject	= 0x476c624f,
        phTypeGradientType	= 0x47726454,
        phTypeGradientForm	= 0x47726446,
        phTypeGrainType	= 0x47726e74,
        phTypeGrayBehavior	= 0x47724268,
        phTypeGuideGridColor	= 0x47644772,
        phTypeGuideGridStyle	= 0x47644753,
        phTypeHistoryStateSource	= 0x48737453,
        phTypeHorizontalLocation	= 0x48727a4c,
        phTypeImageReference	= 0x23496d52,
        phTypeInnerGlowSource	= 0x49475372,
        phTypeIntegerChannel	= 0x23696e43,
        phTypeIntent	= 0x496e7465,
        phTypeInterlaceCreateType	= 0x496e7443,
        phTypeInterlaceEliminateType	= 0x496e7445,
        phTypeInterpolation	= 0x496e7470,
        phTypeKelvin	= 0x4b6c766e,
        phTypeKelvinCustomWhitePoint	= 0x234b6c76,
        phTypeLens	= 0x4c6e7320,
        phTypeLightDirection	= 0x4c676844,
        phTypeLightPosition	= 0x4c676850,
        phTypeLightType	= 0x4c676854,
        phTypeLocationReference	= 0x234c6374,
        phTypeMaskIndicator	= 0x4d736b49,
        phTypeMatteColor	= 0x4d747443,
        phTypeMatteTechnique	= 0x42455445,
        phTypeMenuItem	= 0x4d6e4974,
        phTypeMethod	= 0x4d746864,
        phTypeMezzotintType	= 0x4d7a7454,
        phTypeMode	= 0x4d642020,
        phTypeNotify	= 0x4e746679,
        phTypeObject	= 0x4f626a63,
        phTypeObjectReference	= 0x6f626a20,
        phTypeOnOff	= 0x4f6e4f66,
        phTypeOrdinal	= 0x4f72646e,
        phTypeOrientation	= 0x4f726e74,
        phTypePNGFilter	= 0x504e4766,
        phTypePNGInterlaceType	= 0x50474954,
        phTypePagePosition	= 0x50675073,
        phTypePathKind	= 0x5074684b,
        phTypePathReference	= 0x23507452,
        phTypePhosphors	= 0x50687370,
        phTypePhosphorsCustomPhosphors	= 0x23506873,
        phTypePickerKind	= 0x50636b4b,
        phTypePixelPaintSize	= 0x5050537a,
        phTypePlatform	= 0x506c7466,
        phTypePreview	= 0x50727677,
        phTypePreviewCMYK	= 0x50727674,
        phTypeProfileMismatch	= 0x5072664d,
        phTypePurgeItem	= 0x50726749,
        phTypeQuadCenterState	= 0x51435374,
        phTypeQuality	= 0x516c7479,
        phTypeQueryState	= 0x51757253,
        phTypeRGBSetupSource	= 0x52474253,
        phTypeRawData	= 0x74647461,
        phTypeRippleSize	= 0x52706c53,
        phTypeRulerUnits	= 0x526c7255,
        phTypeScreenType	= 0x53637254,
        phTypeShape	= 0x53687020,
        phTypeSmartBlurMode	= 0x536d424d,
        phTypeSmartBlurQuality	= 0x536d4251,
        phTypeSourceMode	= 0x436e646e,
        phTypeSpherizeMode	= 0x5370684d,
        phTypeState	= 0x53747465,
        phTypeStringClassFormat	= 0x23537443,
        phTypeStringChannel	= 0x23737468,
        phTypeStringCompensation	= 0x2353746d,
        phTypeStringFSS	= 0x23537466,
        phTypeStringInteger	= 0x23537449,
        phTypeStrokeDirection	= 0x53747244,
        phTypeStrokeLocation	= 0x5374724c,
        phTypeTermText	= 0x54455854,
        phTypeTextureType	= 0x54787454,
        phTypeTransparencyGridColors	= 0x54726e6c,
        phTypeTransparencyGridSize	= 0x54726e47,
        phTypeTypeClassModeOrClassMode	= 0x2354794d,
        phTypeUndefinedArea	= 0x556e6441,
        phTypeUnitFloat	= 0x556e7446,
        phTypeUrgency	= 0x5572676e,
        phTypeUserMaskOptions	= 0x5573724d,
        phTypeValueList	= 0x566c4c73,
        phTypeVerticalLocation	= 0x5672744c,
        phTypeWaveType	= 0x57767470,
        phTypeWindMethod	= 0x576e644d,
        phTypeYesNo	= 0x59734e20,
        phTypeZigZagType	= 0x5a5a5479,
        phUnitAngle	= 0x23416e67,
        phUnitDensity	= 0x2352736c,
        phUnitDistance	= 0x23526c74,
        phUnitNone	= 0x234e6e65,
        phUnitPercent	= 0x23507263,
        phUnitPixels	= 0x2350786c,
        phUnitMillimeters	= 0x234d6c6d,
        phUnitPoints	= 0x23506e74
    } 	PSConstants;








EXTERN_C const IID LIBID_PhotoshopTypeLibrary;

#ifndef __IActionReference_INTERFACE_DEFINED__
#define __IActionReference_INTERFACE_DEFINED__

/* interface IActionReference */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IActionReference;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b249c0b1-a004-11d1-b036-00c04fd7ec47")
    IActionReference : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetForm( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDesiredClass( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutClass( 
            /* [in] */ long desiredClass) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutName( 
            /* [in] */ long desiredClass,
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIndex( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutIndex( 
            /* [in] */ long desiredClass,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutIdentifier( 
            /* [in] */ long desiredClass,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutOffset( 
            /* [in] */ long desiredClass,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumerated( 
            /* [out] */ long *type,
            /* [out] */ long *enumValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutEnumerated( 
            /* [in] */ long desiredClass,
            /* [in] */ long type,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutProperty( 
            /* [in] */ long desiredClass,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContainer( 
            /* [out] */ IActionReference **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActionReferenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActionReference * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActionReference * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActionReference * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActionReference * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActionReference * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActionReference * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActionReference * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetForm )( 
            IActionReference * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetDesiredClass )( 
            IActionReference * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutClass )( 
            IActionReference * This,
            /* [in] */ long desiredClass);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IActionReference * This,
            /* [out] */ BSTR *name);
        
        HRESULT ( STDMETHODCALLTYPE *PutName )( 
            IActionReference * This,
            /* [in] */ long desiredClass,
            /* [in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetIndex )( 
            IActionReference * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutIndex )( 
            IActionReference * This,
            /* [in] */ long desiredClass,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IActionReference * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutIdentifier )( 
            IActionReference * This,
            /* [in] */ long desiredClass,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffset )( 
            IActionReference * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutOffset )( 
            IActionReference * This,
            /* [in] */ long desiredClass,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnumerated )( 
            IActionReference * This,
            /* [out] */ long *type,
            /* [out] */ long *enumValue);
        
        HRESULT ( STDMETHODCALLTYPE *PutEnumerated )( 
            IActionReference * This,
            /* [in] */ long desiredClass,
            /* [in] */ long type,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IActionReference * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutProperty )( 
            IActionReference * This,
            /* [in] */ long desiredClass,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainer )( 
            IActionReference * This,
            /* [out] */ IActionReference **value);
        
        END_INTERFACE
    } IActionReferenceVtbl;

    interface IActionReference
    {
        CONST_VTBL struct IActionReferenceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActionReference_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActionReference_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActionReference_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActionReference_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActionReference_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActionReference_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActionReference_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActionReference_GetForm(This,value)	\
    ( (This)->lpVtbl -> GetForm(This,value) ) 

#define IActionReference_GetDesiredClass(This,value)	\
    ( (This)->lpVtbl -> GetDesiredClass(This,value) ) 

#define IActionReference_PutClass(This,desiredClass)	\
    ( (This)->lpVtbl -> PutClass(This,desiredClass) ) 

#define IActionReference_GetName(This,name)	\
    ( (This)->lpVtbl -> GetName(This,name) ) 

#define IActionReference_PutName(This,desiredClass,name)	\
    ( (This)->lpVtbl -> PutName(This,desiredClass,name) ) 

#define IActionReference_GetIndex(This,value)	\
    ( (This)->lpVtbl -> GetIndex(This,value) ) 

#define IActionReference_PutIndex(This,desiredClass,value)	\
    ( (This)->lpVtbl -> PutIndex(This,desiredClass,value) ) 

#define IActionReference_GetIdentifier(This,value)	\
    ( (This)->lpVtbl -> GetIdentifier(This,value) ) 

#define IActionReference_PutIdentifier(This,desiredClass,value)	\
    ( (This)->lpVtbl -> PutIdentifier(This,desiredClass,value) ) 

#define IActionReference_GetOffset(This,value)	\
    ( (This)->lpVtbl -> GetOffset(This,value) ) 

#define IActionReference_PutOffset(This,desiredClass,value)	\
    ( (This)->lpVtbl -> PutOffset(This,desiredClass,value) ) 

#define IActionReference_GetEnumerated(This,type,enumValue)	\
    ( (This)->lpVtbl -> GetEnumerated(This,type,enumValue) ) 

#define IActionReference_PutEnumerated(This,desiredClass,type,value)	\
    ( (This)->lpVtbl -> PutEnumerated(This,desiredClass,type,value) ) 

#define IActionReference_GetProperty(This,value)	\
    ( (This)->lpVtbl -> GetProperty(This,value) ) 

#define IActionReference_PutProperty(This,desiredClass,value)	\
    ( (This)->lpVtbl -> PutProperty(This,desiredClass,value) ) 

#define IActionReference_GetContainer(This,value)	\
    ( (This)->lpVtbl -> GetContainer(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActionReference_INTERFACE_DEFINED__ */


#ifndef __IActionList_INTERFACE_DEFINED__
#define __IActionList_INTERFACE_DEFINED__

/* interface IActionList */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IActionList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b249c0b0-a004-11d1-b036-00c04fd7ec47")
    IActionList : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [in] */ long index,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInteger( 
            /* [in] */ long index,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutInteger( 
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDouble( 
            /* [in] */ long index,
            /* [out] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutDouble( 
            /* [in] */ double value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnitDouble( 
            /* [in] */ long index,
            /* [out] */ long *unit,
            /* [out] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutUnitDouble( 
            /* [in] */ long unit,
            /* [in] */ double value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetString( 
            /* [in] */ long index,
            /* [out] */ BSTR *str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutString( 
            /* [in] */ BSTR str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBoolean( 
            /* [in] */ long index,
            /* [out] */ BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutBoolean( 
            /* [in] */ BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetList( 
            /* [in] */ long index,
            /* [out] */ IActionList **actionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutList( 
            /* [in] */ IActionList *actionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [in] */ long index,
            /* [out] */ long *type,
            /* [out] */ IActionDescriptor **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutObject( 
            /* [in] */ long type,
            /* [in] */ IActionDescriptor *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalObject( 
            /* [in] */ long index,
            /* [out] */ long *type,
            /* [out] */ IActionDescriptor **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutGlobalObject( 
            /* [in] */ long type,
            /* [in] */ IActionDescriptor *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumerated( 
            /* [in] */ long index,
            /* [out] */ long *type,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutEnumerated( 
            /* [in] */ long type,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReference( 
            /* [in] */ long index,
            /* [out] */ IActionReference **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutReference( 
            /* [in] */ IActionReference *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClass( 
            /* [in] */ long index,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutClass( 
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalClass( 
            /* [in] */ long index,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutGlobalClass( 
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [in] */ long index,
            /* [out] */ BSTR *pathString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutPath( 
            /* [in] */ BSTR pathString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataLength( 
            /* [in] */ long index,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [in] */ long index,
            /* [out] */ BSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutData( 
            /* [in] */ long length,
            /* [in] */ BSTR value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActionListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActionList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActionList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActionList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActionList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActionList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActionList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActionList * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IActionList * This,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetInteger )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutInteger )( 
            IActionList * This,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetDouble )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutDouble )( 
            IActionList * This,
            /* [in] */ double value);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnitDouble )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *unit,
            /* [out] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutUnitDouble )( 
            IActionList * This,
            /* [in] */ long unit,
            /* [in] */ double value);
        
        HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ BSTR *str);
        
        HRESULT ( STDMETHODCALLTYPE *PutString )( 
            IActionList * This,
            /* [in] */ BSTR str);
        
        HRESULT ( STDMETHODCALLTYPE *GetBoolean )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutBoolean )( 
            IActionList * This,
            /* [in] */ BOOL value);
        
        HRESULT ( STDMETHODCALLTYPE *GetList )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ IActionList **actionList);
        
        HRESULT ( STDMETHODCALLTYPE *PutList )( 
            IActionList * This,
            /* [in] */ IActionList *actionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *type,
            /* [out] */ IActionDescriptor **value);
        
        HRESULT ( STDMETHODCALLTYPE *PutObject )( 
            IActionList * This,
            /* [in] */ long type,
            /* [in] */ IActionDescriptor *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetGlobalObject )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *type,
            /* [out] */ IActionDescriptor **value);
        
        HRESULT ( STDMETHODCALLTYPE *PutGlobalObject )( 
            IActionList * This,
            /* [in] */ long type,
            /* [in] */ IActionDescriptor *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnumerated )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *type,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutEnumerated )( 
            IActionList * This,
            /* [in] */ long type,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetReference )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ IActionReference **value);
        
        HRESULT ( STDMETHODCALLTYPE *PutReference )( 
            IActionList * This,
            /* [in] */ IActionReference *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetClass )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutClass )( 
            IActionList * This,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetGlobalClass )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutGlobalClass )( 
            IActionList * This,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ BSTR *pathString);
        
        HRESULT ( STDMETHODCALLTYPE *PutPath )( 
            IActionList * This,
            /* [in] */ BSTR pathString);
        
        HRESULT ( STDMETHODCALLTYPE *GetDataLength )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            IActionList * This,
            /* [in] */ long index,
            /* [out] */ BSTR *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutData )( 
            IActionList * This,
            /* [in] */ long length,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } IActionListVtbl;

    interface IActionList
    {
        CONST_VTBL struct IActionListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActionList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActionList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActionList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActionList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActionList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActionList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActionList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActionList_GetType(This,index,value)	\
    ( (This)->lpVtbl -> GetType(This,index,value) ) 

#define IActionList_GetCount(This,value)	\
    ( (This)->lpVtbl -> GetCount(This,value) ) 

#define IActionList_GetInteger(This,index,value)	\
    ( (This)->lpVtbl -> GetInteger(This,index,value) ) 

#define IActionList_PutInteger(This,value)	\
    ( (This)->lpVtbl -> PutInteger(This,value) ) 

#define IActionList_GetDouble(This,index,value)	\
    ( (This)->lpVtbl -> GetDouble(This,index,value) ) 

#define IActionList_PutDouble(This,value)	\
    ( (This)->lpVtbl -> PutDouble(This,value) ) 

#define IActionList_GetUnitDouble(This,index,unit,value)	\
    ( (This)->lpVtbl -> GetUnitDouble(This,index,unit,value) ) 

#define IActionList_PutUnitDouble(This,unit,value)	\
    ( (This)->lpVtbl -> PutUnitDouble(This,unit,value) ) 

#define IActionList_GetString(This,index,str)	\
    ( (This)->lpVtbl -> GetString(This,index,str) ) 

#define IActionList_PutString(This,str)	\
    ( (This)->lpVtbl -> PutString(This,str) ) 

#define IActionList_GetBoolean(This,index,value)	\
    ( (This)->lpVtbl -> GetBoolean(This,index,value) ) 

#define IActionList_PutBoolean(This,value)	\
    ( (This)->lpVtbl -> PutBoolean(This,value) ) 

#define IActionList_GetList(This,index,actionList)	\
    ( (This)->lpVtbl -> GetList(This,index,actionList) ) 

#define IActionList_PutList(This,actionList)	\
    ( (This)->lpVtbl -> PutList(This,actionList) ) 

#define IActionList_GetObject(This,index,type,value)	\
    ( (This)->lpVtbl -> GetObject(This,index,type,value) ) 

#define IActionList_PutObject(This,type,value)	\
    ( (This)->lpVtbl -> PutObject(This,type,value) ) 

#define IActionList_GetGlobalObject(This,index,type,value)	\
    ( (This)->lpVtbl -> GetGlobalObject(This,index,type,value) ) 

#define IActionList_PutGlobalObject(This,type,value)	\
    ( (This)->lpVtbl -> PutGlobalObject(This,type,value) ) 

#define IActionList_GetEnumerated(This,index,type,value)	\
    ( (This)->lpVtbl -> GetEnumerated(This,index,type,value) ) 

#define IActionList_PutEnumerated(This,type,value)	\
    ( (This)->lpVtbl -> PutEnumerated(This,type,value) ) 

#define IActionList_GetReference(This,index,value)	\
    ( (This)->lpVtbl -> GetReference(This,index,value) ) 

#define IActionList_PutReference(This,value)	\
    ( (This)->lpVtbl -> PutReference(This,value) ) 

#define IActionList_GetClass(This,index,value)	\
    ( (This)->lpVtbl -> GetClass(This,index,value) ) 

#define IActionList_PutClass(This,value)	\
    ( (This)->lpVtbl -> PutClass(This,value) ) 

#define IActionList_GetGlobalClass(This,index,value)	\
    ( (This)->lpVtbl -> GetGlobalClass(This,index,value) ) 

#define IActionList_PutGlobalClass(This,value)	\
    ( (This)->lpVtbl -> PutGlobalClass(This,value) ) 

#define IActionList_GetPath(This,index,pathString)	\
    ( (This)->lpVtbl -> GetPath(This,index,pathString) ) 

#define IActionList_PutPath(This,pathString)	\
    ( (This)->lpVtbl -> PutPath(This,pathString) ) 

#define IActionList_GetDataLength(This,index,value)	\
    ( (This)->lpVtbl -> GetDataLength(This,index,value) ) 

#define IActionList_GetData(This,index,value)	\
    ( (This)->lpVtbl -> GetData(This,index,value) ) 

#define IActionList_PutData(This,length,value)	\
    ( (This)->lpVtbl -> PutData(This,length,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActionList_INTERFACE_DEFINED__ */


#ifndef __IActionDescriptor_INTERFACE_DEFINED__
#define __IActionDescriptor_INTERFACE_DEFINED__

/* interface IActionDescriptor */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IActionDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7ca9de40-9eb3-11d1-b033-00c04fd7ec47")
    IActionDescriptor : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [in] */ long key,
            /* [out] */ long *type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKey( 
            /* [in] */ long index,
            /* [out] */ long *key) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasKey( 
            /* [in] */ long key,
            /* [out] */ BOOL *hasKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ long *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [in] */ IActionDescriptor *otherDesc,
            /* [out] */ BOOL *isEqual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Erase( 
            /* [in] */ long key) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInteger( 
            /* [in] */ long key,
            /* [out] */ long *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutInteger( 
            /* [in] */ long key,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDouble( 
            /* [in] */ long key,
            /* [out] */ double *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutDouble( 
            /* [in] */ long key,
            /* [in] */ double value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnitDouble( 
            /* [in] */ long key,
            /* [out] */ long *unitID,
            /* [out] */ double *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutUnitDouble( 
            /* [in] */ long key,
            /* [in] */ long unitID,
            /* [in] */ double value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetString( 
            /* [in] */ long key,
            /* [out] */ BSTR *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutString( 
            /* [in] */ long key,
            /* [in] */ BSTR value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBoolean( 
            /* [in] */ long key,
            /* [out] */ BOOL *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutBoolean( 
            /* [in] */ long key,
            /* [in] */ BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetList( 
            /* [in] */ long key,
            /* [out] */ IActionList **list) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutList( 
            /* [in] */ long key,
            /* [in] */ IActionList *list) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [in] */ long key,
            /* [out] */ long *classID,
            /* [out] */ IActionDescriptor **retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutObject( 
            /* [in] */ long key,
            /* [in] */ long classID,
            /* [in] */ IActionDescriptor *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalObject( 
            /* [in] */ long key,
            /* [out] */ long *classID,
            /* [out] */ IActionDescriptor **retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutGlobalObject( 
            /* [in] */ long key,
            /* [in] */ long classID,
            /* [in] */ IActionDescriptor *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumerated( 
            /* [in] */ long key,
            /* [out] */ long *enumType,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutEnumerated( 
            /* [in] */ long key,
            /* [in] */ long enumType,
            /* [in] */ long value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReference( 
            /* [in] */ long key,
            /* [out] */ IActionReference **reference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutReference( 
            /* [in] */ long key,
            /* [in] */ IActionReference *reference) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClass( 
            /* [in] */ long key,
            /* [out] */ long *classID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutClass( 
            /* [in] */ long key,
            /* [in] */ long classID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalClass( 
            /* [in] */ long key,
            /* [out] */ long *classID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutGlobalClass( 
            /* [in] */ long key,
            /* [in] */ long classID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [in] */ long key,
            /* [out] */ BSTR *pathString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutPath( 
            /* [in] */ long key,
            /* [in] */ BSTR pathString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataLength( 
            /* [in] */ long key,
            /* [out] */ long *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [in] */ long key,
            /* [out] */ BSTR *retval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutData( 
            /* [in] */ long key,
            /* [in] */ BSTR value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActionDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActionDescriptor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActionDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActionDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActionDescriptor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActionDescriptor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActionDescriptor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActionDescriptor * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *type);
        
        HRESULT ( STDMETHODCALLTYPE *GetKey )( 
            IActionDescriptor * This,
            /* [in] */ long index,
            /* [out] */ long *key);
        
        HRESULT ( STDMETHODCALLTYPE *HasKey )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ BOOL *hasKey);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IActionDescriptor * This,
            /* [out] */ long *count);
        
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IActionDescriptor * This,
            /* [in] */ IActionDescriptor *otherDesc,
            /* [out] */ BOOL *isEqual);
        
        HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IActionDescriptor * This,
            /* [in] */ long key);
        
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IActionDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetInteger )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutInteger )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetDouble )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ double *retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutDouble )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ double value);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnitDouble )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *unitID,
            /* [out] */ double *retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutUnitDouble )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long unitID,
            /* [in] */ double value);
        
        HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ BSTR *retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutString )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ BSTR value);
        
        HRESULT ( STDMETHODCALLTYPE *GetBoolean )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ BOOL *retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutBoolean )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ BOOL value);
        
        HRESULT ( STDMETHODCALLTYPE *GetList )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ IActionList **list);
        
        HRESULT ( STDMETHODCALLTYPE *PutList )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ IActionList *list);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *classID,
            /* [out] */ IActionDescriptor **retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutObject )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long classID,
            /* [in] */ IActionDescriptor *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetGlobalObject )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *classID,
            /* [out] */ IActionDescriptor **retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutGlobalObject )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long classID,
            /* [in] */ IActionDescriptor *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnumerated )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *enumType,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *PutEnumerated )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long enumType,
            /* [in] */ long value);
        
        HRESULT ( STDMETHODCALLTYPE *GetReference )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ IActionReference **reference);
        
        HRESULT ( STDMETHODCALLTYPE *PutReference )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ IActionReference *reference);
        
        HRESULT ( STDMETHODCALLTYPE *GetClass )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *classID);
        
        HRESULT ( STDMETHODCALLTYPE *PutClass )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long classID);
        
        HRESULT ( STDMETHODCALLTYPE *GetGlobalClass )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *classID);
        
        HRESULT ( STDMETHODCALLTYPE *PutGlobalClass )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ long classID);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ BSTR *pathString);
        
        HRESULT ( STDMETHODCALLTYPE *PutPath )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ BSTR pathString);
        
        HRESULT ( STDMETHODCALLTYPE *GetDataLength )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ long *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [out] */ BSTR *retval);
        
        HRESULT ( STDMETHODCALLTYPE *PutData )( 
            IActionDescriptor * This,
            /* [in] */ long key,
            /* [in] */ BSTR value);
        
        END_INTERFACE
    } IActionDescriptorVtbl;

    interface IActionDescriptor
    {
        CONST_VTBL struct IActionDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActionDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActionDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActionDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActionDescriptor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActionDescriptor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActionDescriptor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActionDescriptor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActionDescriptor_GetType(This,key,type)	\
    ( (This)->lpVtbl -> GetType(This,key,type) ) 

#define IActionDescriptor_GetKey(This,index,key)	\
    ( (This)->lpVtbl -> GetKey(This,index,key) ) 

#define IActionDescriptor_HasKey(This,key,hasKey)	\
    ( (This)->lpVtbl -> HasKey(This,key,hasKey) ) 

#define IActionDescriptor_GetCount(This,count)	\
    ( (This)->lpVtbl -> GetCount(This,count) ) 

#define IActionDescriptor_IsEqual(This,otherDesc,isEqual)	\
    ( (This)->lpVtbl -> IsEqual(This,otherDesc,isEqual) ) 

#define IActionDescriptor_Erase(This,key)	\
    ( (This)->lpVtbl -> Erase(This,key) ) 

#define IActionDescriptor_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IActionDescriptor_GetInteger(This,key,retval)	\
    ( (This)->lpVtbl -> GetInteger(This,key,retval) ) 

#define IActionDescriptor_PutInteger(This,key,value)	\
    ( (This)->lpVtbl -> PutInteger(This,key,value) ) 

#define IActionDescriptor_GetDouble(This,key,retval)	\
    ( (This)->lpVtbl -> GetDouble(This,key,retval) ) 

#define IActionDescriptor_PutDouble(This,key,value)	\
    ( (This)->lpVtbl -> PutDouble(This,key,value) ) 

#define IActionDescriptor_GetUnitDouble(This,key,unitID,retval)	\
    ( (This)->lpVtbl -> GetUnitDouble(This,key,unitID,retval) ) 

#define IActionDescriptor_PutUnitDouble(This,key,unitID,value)	\
    ( (This)->lpVtbl -> PutUnitDouble(This,key,unitID,value) ) 

#define IActionDescriptor_GetString(This,key,retval)	\
    ( (This)->lpVtbl -> GetString(This,key,retval) ) 

#define IActionDescriptor_PutString(This,key,value)	\
    ( (This)->lpVtbl -> PutString(This,key,value) ) 

#define IActionDescriptor_GetBoolean(This,key,retval)	\
    ( (This)->lpVtbl -> GetBoolean(This,key,retval) ) 

#define IActionDescriptor_PutBoolean(This,key,value)	\
    ( (This)->lpVtbl -> PutBoolean(This,key,value) ) 

#define IActionDescriptor_GetList(This,key,list)	\
    ( (This)->lpVtbl -> GetList(This,key,list) ) 

#define IActionDescriptor_PutList(This,key,list)	\
    ( (This)->lpVtbl -> PutList(This,key,list) ) 

#define IActionDescriptor_GetObject(This,key,classID,retval)	\
    ( (This)->lpVtbl -> GetObject(This,key,classID,retval) ) 

#define IActionDescriptor_PutObject(This,key,classID,value)	\
    ( (This)->lpVtbl -> PutObject(This,key,classID,value) ) 

#define IActionDescriptor_GetGlobalObject(This,key,classID,retval)	\
    ( (This)->lpVtbl -> GetGlobalObject(This,key,classID,retval) ) 

#define IActionDescriptor_PutGlobalObject(This,key,classID,value)	\
    ( (This)->lpVtbl -> PutGlobalObject(This,key,classID,value) ) 

#define IActionDescriptor_GetEnumerated(This,key,enumType,value)	\
    ( (This)->lpVtbl -> GetEnumerated(This,key,enumType,value) ) 

#define IActionDescriptor_PutEnumerated(This,key,enumType,value)	\
    ( (This)->lpVtbl -> PutEnumerated(This,key,enumType,value) ) 

#define IActionDescriptor_GetReference(This,key,reference)	\
    ( (This)->lpVtbl -> GetReference(This,key,reference) ) 

#define IActionDescriptor_PutReference(This,key,reference)	\
    ( (This)->lpVtbl -> PutReference(This,key,reference) ) 

#define IActionDescriptor_GetClass(This,key,classID)	\
    ( (This)->lpVtbl -> GetClass(This,key,classID) ) 

#define IActionDescriptor_PutClass(This,key,classID)	\
    ( (This)->lpVtbl -> PutClass(This,key,classID) ) 

#define IActionDescriptor_GetGlobalClass(This,key,classID)	\
    ( (This)->lpVtbl -> GetGlobalClass(This,key,classID) ) 

#define IActionDescriptor_PutGlobalClass(This,key,classID)	\
    ( (This)->lpVtbl -> PutGlobalClass(This,key,classID) ) 

#define IActionDescriptor_GetPath(This,key,pathString)	\
    ( (This)->lpVtbl -> GetPath(This,key,pathString) ) 

#define IActionDescriptor_PutPath(This,key,pathString)	\
    ( (This)->lpVtbl -> PutPath(This,key,pathString) ) 

#define IActionDescriptor_GetDataLength(This,key,value)	\
    ( (This)->lpVtbl -> GetDataLength(This,key,value) ) 

#define IActionDescriptor_GetData(This,key,retval)	\
    ( (This)->lpVtbl -> GetData(This,key,retval) ) 

#define IActionDescriptor_PutData(This,key,value)	\
    ( (This)->lpVtbl -> PutData(This,key,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActionDescriptor_INTERFACE_DEFINED__ */


#ifndef __IActionControl_INTERFACE_DEFINED__
#define __IActionControl_INTERFACE_DEFINED__

/* interface IActionControl */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IActionControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38fb4290-9df6-11d1-b032-00c04fd7ec47")
    IActionControl : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ long eventID,
            /* [in] */ IActionDescriptor *parameters,
            /* [in] */ long dialogOptions,
            /* [retval][full][out] */ IActionDescriptor **result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActionProperty( 
            /* [in] */ IActionReference *reference,
            /* [out] */ IActionDescriptor **propertyDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StringIDToTypeID( 
            /* [in] */ BSTR stringID,
            /* [out] */ long *typeID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TypeIDToStringID( 
            /* [in] */ long typeID,
            /* [out] */ BSTR *stringID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActionControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActionControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActionControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActionControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActionControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActionControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActionControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActionControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IActionControl * This,
            /* [in] */ long eventID,
            /* [in] */ IActionDescriptor *parameters,
            /* [in] */ long dialogOptions,
            /* [retval][full][out] */ IActionDescriptor **result);
        
        HRESULT ( STDMETHODCALLTYPE *GetActionProperty )( 
            IActionControl * This,
            /* [in] */ IActionReference *reference,
            /* [out] */ IActionDescriptor **propertyDesc);
        
        HRESULT ( STDMETHODCALLTYPE *StringIDToTypeID )( 
            IActionControl * This,
            /* [in] */ BSTR stringID,
            /* [out] */ long *typeID);
        
        HRESULT ( STDMETHODCALLTYPE *TypeIDToStringID )( 
            IActionControl * This,
            /* [in] */ long typeID,
            /* [out] */ BSTR *stringID);
        
        END_INTERFACE
    } IActionControlVtbl;

    interface IActionControl
    {
        CONST_VTBL struct IActionControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActionControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActionControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActionControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActionControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActionControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActionControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActionControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActionControl_Play(This,eventID,parameters,dialogOptions,result)	\
    ( (This)->lpVtbl -> Play(This,eventID,parameters,dialogOptions,result) ) 

#define IActionControl_GetActionProperty(This,reference,propertyDesc)	\
    ( (This)->lpVtbl -> GetActionProperty(This,reference,propertyDesc) ) 

#define IActionControl_StringIDToTypeID(This,stringID,typeID)	\
    ( (This)->lpVtbl -> StringIDToTypeID(This,stringID,typeID) ) 

#define IActionControl_TypeIDToStringID(This,typeID,stringID)	\
    ( (This)->lpVtbl -> TypeIDToStringID(This,typeID,stringID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActionControl_INTERFACE_DEFINED__ */


#ifndef __IAutoPSDoc_INTERFACE_DEFINED__
#define __IAutoPSDoc_INTERFACE_DEFINED__

/* interface IAutoPSDoc */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IAutoPSDoc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9077D1E1-8959-11cf-86B4-444553540000")
    IAutoPSDoc : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SaveTo( 
            /* [in] */ BSTR fileName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAutoPSDocVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoPSDoc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoPSDoc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoPSDoc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoPSDoc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoPSDoc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoPSDoc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoPSDoc * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IAutoPSDoc * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IAutoPSDoc * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveTo )( 
            IAutoPSDoc * This,
            /* [in] */ BSTR fileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IAutoPSDoc * This);
        
        END_INTERFACE
    } IAutoPSDocVtbl;

    interface IAutoPSDoc
    {
        CONST_VTBL struct IAutoPSDocVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoPSDoc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoPSDoc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoPSDoc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoPSDoc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoPSDoc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoPSDoc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoPSDoc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAutoPSDoc_get_Title(This,retval)	\
    ( (This)->lpVtbl -> get_Title(This,retval) ) 

#define IAutoPSDoc_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IAutoPSDoc_SaveTo(This,fileName)	\
    ( (This)->lpVtbl -> SaveTo(This,fileName) ) 

#define IAutoPSDoc_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAutoPSDoc_INTERFACE_DEFINED__ */


#ifndef __IAction_INTERFACE_DEFINED__
#define __IAction_INTERFACE_DEFINED__

/* interface IAction */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IAction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("90CED626-8D78-11cf-86B4-444553540000")
    IAction : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAction * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAction * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAction * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAction * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAction * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAction * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IAction * This);
        
        END_INTERFACE
    } IActionVtbl;

    interface IAction
    {
        CONST_VTBL struct IActionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAction_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAction_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAction_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAction_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAction_get_Name(This,retval)	\
    ( (This)->lpVtbl -> get_Name(This,retval) ) 

#define IAction_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAction_INTERFACE_DEFINED__ */


#ifndef __IActions_INTERFACE_DEFINED__
#define __IActions_INTERFACE_DEFINED__

/* interface IActions */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IActions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("90CED625-8D78-11cf-86B4-444553540000")
    IActions : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IAction **retval) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **retval) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActions * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActions * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActions * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActions * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IActions * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IActions * This,
            /* [in] */ long Index,
            /* [retval][out] */ IAction **retval);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IActions * This,
            /* [retval][out] */ IUnknown **retval);
        
        END_INTERFACE
    } IActionsVtbl;

    interface IActions
    {
        CONST_VTBL struct IActionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActions_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActions_get_Count(This,retval)	\
    ( (This)->lpVtbl -> get_Count(This,retval) ) 

#define IActions_get_Item(This,Index,retval)	\
    ( (This)->lpVtbl -> get_Item(This,Index,retval) ) 

#define IActions_get__NewEnum(This,retval)	\
    ( (This)->lpVtbl -> get__NewEnum(This,retval) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActions_INTERFACE_DEFINED__ */


#ifndef __IPhotoshopApplication_INTERFACE_DEFINED__
#define __IPhotoshopApplication_INTERFACE_DEFINED__

/* interface IPhotoshopApplication */
/* [object][dual][oleautomation][helpstring][uuid] */ 


EXTERN_C const IID IID_IPhotoshopApplication;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9414F179-C905-11d1-92CC-00600808FC44")
    IPhotoshopApplication : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FullName( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Quit( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR fileName,
            /* [retval][out] */ IAutoPSDoc **retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PlayAction( 
            /* [in] */ BSTR fileName,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Actions( 
            /* [retval][out] */ IActions **retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MakeControlObject( 
            /* [retval][out] */ IActionControl **retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MakeDescriptor( 
            /* [retval][out] */ IActionDescriptor **retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MakeList( 
            /* [retval][out] */ IActionList **retval) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MakeReference( 
            /* [retval][out] */ IActionReference **retval) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ BOOL *isVisible) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ BOOL vis) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPhotoshopApplicationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoshopApplication * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoshopApplication * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoshopApplication * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPhotoshopApplication * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPhotoshopApplication * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPhotoshopApplication * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPhotoshopApplication * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FullName )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Quit )( 
            IPhotoshopApplication * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IPhotoshopApplication * This,
            /* [in] */ BSTR fileName,
            /* [retval][out] */ IAutoPSDoc **retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PlayAction )( 
            IPhotoshopApplication * This,
            /* [in] */ BSTR fileName,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Actions )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ IActions **retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MakeControlObject )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ IActionControl **retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MakeDescriptor )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ IActionDescriptor **retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MakeList )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ IActionList **retval);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *MakeReference )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ IActionReference **retval);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IPhotoshopApplication * This,
            /* [retval][out] */ BOOL *isVisible);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IPhotoshopApplication * This,
            /* [in] */ BOOL vis);
        
        END_INTERFACE
    } IPhotoshopApplicationVtbl;

    interface IPhotoshopApplication
    {
        CONST_VTBL struct IPhotoshopApplicationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoshopApplication_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoshopApplication_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoshopApplication_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoshopApplication_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPhotoshopApplication_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPhotoshopApplication_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPhotoshopApplication_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPhotoshopApplication_get_FullName(This,retval)	\
    ( (This)->lpVtbl -> get_FullName(This,retval) ) 

#define IPhotoshopApplication_Quit(This)	\
    ( (This)->lpVtbl -> Quit(This) ) 

#define IPhotoshopApplication_Open(This,fileName,retval)	\
    ( (This)->lpVtbl -> Open(This,fileName,retval) ) 

#define IPhotoshopApplication_PlayAction(This,fileName,retval)	\
    ( (This)->lpVtbl -> PlayAction(This,fileName,retval) ) 

#define IPhotoshopApplication_get_Actions(This,retval)	\
    ( (This)->lpVtbl -> get_Actions(This,retval) ) 

#define IPhotoshopApplication_MakeControlObject(This,retval)	\
    ( (This)->lpVtbl -> MakeControlObject(This,retval) ) 

#define IPhotoshopApplication_MakeDescriptor(This,retval)	\
    ( (This)->lpVtbl -> MakeDescriptor(This,retval) ) 

#define IPhotoshopApplication_MakeList(This,retval)	\
    ( (This)->lpVtbl -> MakeList(This,retval) ) 

#define IPhotoshopApplication_MakeReference(This,retval)	\
    ( (This)->lpVtbl -> MakeReference(This,retval) ) 

#define IPhotoshopApplication_get_Visible(This,isVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,isVisible) ) 

#define IPhotoshopApplication_put_Visible(This,vis)	\
    ( (This)->lpVtbl -> put_Visible(This,vis) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoshopApplication_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PhotoshopApplication;

#ifdef __cplusplus

class DECLSPEC_UUID("6DECC242-87EF-11cf-86B4-444553540000")
PhotoshopApplication;
#endif
#endif /* __PhotoshopTypeLibrary_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


