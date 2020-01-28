#ifndef __PropertyUtils_H__
#define __PropertyUtils_H__

#include "PIDefines.h"
#include "PIGeneral.h"
#include "PIProperties.h"
#include <string>
#include "ASTypes.h"

#ifdef __PIMac__
  #include <CoreServices/CoreServices.h>
  #include <ApplicationServices/ApplicationServices.h>
#endif

using namespace std;

typedef basic_string<ASUnicode, char_traits<ASUnicode>, allocator<ASUnicode> > ps_wstring;


enum InterpolationMethod { nearestNeighbor = 1, bilinear, bicubic, bicubicSmoother, bicubicSharper, bicubicAutomatic };
enum PaintCursorKind { standard = 1, precise, brushSize };
enum PaintCursorShape { shapeNormal = 1, shapeFullSized };
enum UIBrightness { bright = 0, lightGray = 1, mediumGray = 2, darkGray = 3 };
enum CheckerBoardSize { noCheck = 0, smallCheck = 4, mediumCheck = 8, largeCheck = 16 };

OSErr HandleToString(const Handle h, string & outString);
OSErr HandleToString(const Handle h, ps_wstring & outString);
OSErr HandleToString(const Handle h, Str255 & outString);

OSErr StringToHandle(const string & inString, Handle & outHandle);
OSErr StringToHandle(const ps_wstring & inString, Handle & outHandle);

OSErr PIGetNumberChannels(int32 & numChannels);
OSErr PIGetChannelName(const int32 index, string & name);
OSErr PIGetChannelName(const int32 index, ps_wstring & name);
OSErr PIGetImageMode(int32 & mode);
OSErr PIGetTargetLayerLock(bool & transparency, bool & composite, bool & position);
OSErr PIGetNumberLayers(int32 & layers);
OSErr PIGetTargetLayerIndex(int32 & index);
OSErr PIGetLayerName(const int32 index, string & layerName);
OSErr PIGetLayerName(const int32 index, ps_wstring & layerName);
OSErr PIGetMUnits(ps_wstring & mUnits);
OSErr PIGetScaleFactor(int32 & scaleFactor);
OSErr PIGetPixelLength(int32 & pixelLength);
OSErr PIGetLogicalLength(int32 & logicalLength);
OSErr PIGetNumberPaths(int32 & numPaths);
OSErr PIGetPathName(const int32 index, string & name);
OSErr PIGetPathName(const int32 index, ps_wstring & name);
OSErr PIGetWorkPathIndex(int32 & index);
OSErr PIGetClippingPathIndex(int32 & index);
OSErr PIGetTargetPathIndex(int32 & index);
OSErr PIGetPathContents(const int32 index, Handle & contents);
OSErr PIGetPathContentsAI(const int32 index, Handle & contents);
OSErr PIGetCaption(Handle & caption);
OSErr PISetCaption(const Handle h);
OSErr PIGetBigNudge(double & horizontal, double & vertical);
OSErr PISetBigNudge(const double horizontal, const double vertical);
OSErr PIGetInterpolationMethod(InterpolationMethod & method);
OSErr PIGetRulerUnits(RulerUnits & rulerUnits);
OSErr PIGetRulerOrigin(double & horizontal, double & vertical);
OSErr PISetRulerOrigin(const double horizontal, const double vertical);
OSErr PIGetGrid(double & major, int32 & minor);
OSErr PISetGrid(const double major, const int32 minor);
OSErr PIGetSerialString(string & serial);
OSErr PIGetSerialStringOld(string & serial);

#if __PIWin__
	OSErr PIGetHardwareGammaTable(Handle & table);
#endif

OSErr PIGetInterfaceColor(const int8 index, PIInterfaceColor & color);
OSErr PIGetGuideColor(RGBColor & color);
OSErr PIGetGuideCount(int32 & count);
OSErr PIGetGuideHorizontal(const int32 index, bool & guideHorizontal);
OSErr PIGetGuidePosition(const int32 index, double & guidePosition);
OSErr PIGetTileSize(int32 & tileSize);
OSErr PIGetWatchSuspension(int32 & watch);
OSErr PISetWatchSuspension(const int32 inWatchSuspension);
OSErr PIGetGPUFlags(int32 & gpuFlags);
OSErr PIGetVRAM(int32 & vram);
OSErr PIGetCopyright(bool & copyright);
OSErr PISetCopyright(bool inCopyright);
OSErr PIGetCopyright2(bool & copyright);
OSErr PISetCopyright2(bool inCopyright);
OSErr PIGetURL(string & url);
OSErr PISetURL(const string & inURL);
OSErr PIGetDocumentName(string & name);
OSErr PIGetDocumentName(ps_wstring & name, bool withExtension = true);
OSErr PIGetUnicodeStr255Name(Str255 & name);
OSErr PIGetWatermark(bool & watermark);
OSErr PISetWatermark(void);
OSErr PIGetCrosshairVisible(bool & crossHairVisible);
OSErr PIGetZoomWithScrollWheel(bool & zoomWithWheel);
OSErr PIGetDocumentHeight(int32 & height);
OSErr PIGetDocumentWidth(int32 & width);
OSErr PIGetToolTips(bool & toopTips);
OSErr PIGetPaintCursorKind(PaintCursorKind & cursorKind);
OSErr PIGetPaintCursorShape(PaintCursorShape & cursorShape);
OSErr PIGetSlices(Handle & slices);
OSErr PISetSlices(const Handle inSlices);
OSErr PIGetScratchVolumeList(Handle & volumeList);
OSErr PIGetSelectedSliceID(int32 & sliceID);
OSErr PISetSelectedSliceID(const int32 sliceID);
OSErr PIGetSelectedSliceIndex(int32 & sliceIndex);
OSErr PISetSelectedSliceIndex(const int32 sliceIndex);
OSErr PIGetDontShowAgainCount(int32 & dontShowCount);
OSErr PIGetShowSliceNumbers(bool & showSliceNumbers);
OSErr PIGetSliceLineColor(RGBColor & lineColor);
OSErr PIGetPlayInProgress(bool & inProgress);
OSErr PIGetRecordInProgress(bool & inProgress);
OSErr PIGetDoingPlace(bool & doingPlace);
OSErr PIGetRasterizingSmartObject(bool & rasterizingSmart);
OSErr PIGetAppIsModal(bool & appIsModal);
OSErr PIGetLayerIsSmart(bool & inSmart);
OSErr PIGetHDPIAware(bool & inAware);
OSErr PIGetEXIFData(Handle & exifData);
OSErr PISetEXIFData(const Handle inEXIFData);
OSErr PIGetHostVersion(int32 & major, int32 & minor, int32 & fix);
OSErr PIGetXMP(string & xmp);
OSErr PISetXMP(const string & inXMP);
OSErr PIGetUIBrightness(UIBrightness & brightness);
OSErr PIGetLargeTabs(bool & inTabs);
OSErr PIGetCheckerboardColor(const int8 index, RGBColor & color);
OSErr PIGetCheckerboardSize(CheckerBoardSize & size);
OSErr PIGetCheckerboardOn(bool & on);

#endif
// end PropertyUtils.h