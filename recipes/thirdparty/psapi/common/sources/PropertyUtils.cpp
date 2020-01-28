#include "PropertyUtils.h"
#include "PIUSuites.h"
#include <sstream>

static Fixed DoubleToFixed(double in);
static double FixedToDouble(Fixed in);

static OSErr HandleToColor(const Handle h, RGBColor & color);

OSErr HandleToString(const Handle h, string & outString)
{
	OSErr error = kNoErr;

	int32 s = sPSHandle->GetSize(h);
	
	if (s > 0)
	{
		Boolean oldLock = FALSE;
		Ptr p = NULL;
		sPSHandle->SetLock(h, true, &p, &oldLock);
		if (p != NULL)
		{
			outString.assign(p, p + s);
			sPSHandle->SetLock(h, false, &p, &oldLock);
		}
		else
		{
			error = errPlugInHostInsufficient;
		}
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr HandleToString(const Handle h, ps_wstring & outString)
{
	OSErr error = kNoErr;

	int32 s = sPSHandle->GetSize(h);
	
	if (s > 0)
	{
		Boolean oldLock = FALSE;
		ASUnicode * p = NULL;
		sPSHandle->SetLock(h, true, reinterpret_cast<char**>(&p), &oldLock);
		if (p != NULL)
		{
			outString.assign(p, p + ( s / sizeof(ASUnicode) ));
			sPSHandle->SetLock(h, false, reinterpret_cast<char**>(&p), &oldLock);
		}
		else
		{
			error = errPlugInHostInsufficient;
		}
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr HandleToString(const Handle h, Str255 & outString)
{
	OSErr error = kNoErr;

	int32 s = sPSHandle->GetSize(h);
	
	if (s > 0)
	{
		outString[0] = static_cast<unsigned char>(s);
		Boolean oldLock = FALSE;
		Ptr address = NULL;
		sPSHandle->SetLock(h, true, &address, &oldLock);
		if (address != NULL)
		{
			memcpy(outString, &address, s+1);
			sPSHandle->SetLock(h, false, &address, &oldLock);
		}
		else
		{
			error = errPlugInHostInsufficient;
		}
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr StringToHandle(const string & inString, Handle & outHandle)
{
	OSErr error = kNoErr;

	size_t s = inString.length();

	if (s) 
	{
		outHandle = sPSHandle->New((int32)s);
		if (outHandle != NULL)
		{
			Boolean oldLock = FALSE;
			Ptr p = NULL;
			sPSHandle->SetLock(outHandle, true, &p, &oldLock);
			if (p != NULL)
			{
				Ptr originalP = p;
				for(size_t a = 0; a < s; a++, p++)
					*p = inString.at(a);
				sPSHandle->SetLock(outHandle, false, &originalP, &oldLock);
			}
			else
			{
				sPSHandle->Dispose(outHandle);
				outHandle = NULL;
				error = errPlugInHostInsufficient;
			}
		}
		else
		{
			error = errPlugInHostInsufficient;
		}
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr StringToHandle(const ps_wstring & inString, Handle & outHandle)
{
	OSErr error = kNoErr;

	size_t s = inString.length();

	if (s) 
	{
		outHandle = sPSHandle->New((int32)s);
		if (outHandle != NULL)
		{
			Boolean oldLock = FALSE;
			ASUnicode * p = NULL;
			sPSHandle->SetLock(outHandle, true, reinterpret_cast<char**>(&p), &oldLock);
			if (p != NULL)
			{
				ASUnicode * originalP = p;
				for(size_t a = 0; a < s; a++, p++)
					*p = inString.at(a);
				sPSHandle->SetLock(outHandle, false, reinterpret_cast<char**>(&originalP), &oldLock);
			}
			else
			{
				sPSHandle->Dispose(outHandle);
				outHandle = NULL;
				error = errPlugInHostInsufficient;
			}
		}
		else
		{
			error = errPlugInHostInsufficient;
		}
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr PIGetNumberChannels(int32 & numChannels)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propNumberOfChannels,
                                               0, &t, NULL);
    if (!error)
        numChannels = (int32)t;
    
    return error;
}

OSErr PIGetChannelName(const int32 index, string & name)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propChannelName, 
											   index, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, name);
		sPSHandle->Dispose(h);
    } else {
        name.clear();
    }
	
	return error;
}

OSErr PIGetChannelName(const int32 index, ps_wstring & name)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propUnicodeChannelName, 
											   index, NULL, &h);

	if (!error && h != NULL)
	{
		error = HandleToString(h, name);
        sPSHandle->Dispose(h);
    } else {
        name.clear();
    }

	return error;
}

OSErr PIGetImageMode(int32 & mode)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propImageMode,
                                               0, &t, NULL);
    if (!error)
        mode = (int32)t;
    
    return error;
}

OSErr PIGetTargetLayerLock(bool & transparency, bool & composite, bool & position)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propTargetLayerLock, 
											   0, &simple, NULL);
	
	if (!error)
	{
		transparency = (simple & propTargetLayerLockTransparency) != 0;
		composite = (simple & propTargetLayerLockComposite) != 0;
		position = (simple & propTargetLayerLockPosition) != 0;
	}
	
	return error;
}

OSErr PIGetNumberLayers(int32 & layers)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propNumberOfLayers,
                                               0, &t, NULL);
    if (!error)
        layers = (int32)t;
    
    return error;
}

OSErr PIGetScaleFactor(int32 & scaleFactor)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propPixelScaleFactor,
                                               0, &t, NULL);
    if (!error)
        scaleFactor = (int32)t;
    
    return error;
}

OSErr PIGetPixelLength(int32 & pixelLength)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propPixelLength,
                                               0, &t, NULL);
    if (!error)
        pixelLength = (int32)t;
    
    return error;
}

OSErr PIGetLogicalLength(int32 & logicalLength)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propLogicalLength,
                                               0, &t, NULL);
    if (!error)
        logicalLength = (int32)t;
    
    return error;
}

OSErr PIGetTargetLayerIndex(int32 & index)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propTargetLayerIndex,
                                               0, &t, NULL);
    if (!error)
        index = (int32)t;
    
    return error;
}

OSErr PIGetLayerName(const int32 index, string & layerName)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
						                       propLayerName,
											   index, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, layerName);
		sPSHandle->Dispose(h);
    } else {
        layerName.clear();
    }
	
	return error;
}

OSErr PIGetLayerName(const int32 index, ps_wstring & layerName)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
						                       propUnicodeLayerName,
											   index, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, layerName);
		sPSHandle->Dispose(h);
    } else {
        layerName.clear();
    }
	
	return error;
}

OSErr PIGetMUnits(ps_wstring & mUnits)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
						                       propMUnits,
											   0, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, mUnits);
		sPSHandle->Dispose(h);
    } else {
        mUnits.clear();
    }
	
	return error;
}

OSErr PIGetNumberPaths(int32 & paths)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propNumberOfPaths, 
                                               0, &t, NULL);
    if (!error)
        paths = (int32)t;
    
    return error;
}

OSErr PIGetPathName(const int32 index, string & pathName)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
						                       propPathName, 
											   index, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, pathName);
		sPSHandle->Dispose(h);
    } else {
        pathName.clear();
    }
	
	return error;
}

OSErr PIGetPathName(const int32 index, ps_wstring & pathName)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propUnicodePathName, 
											   index, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, pathName);
		sPSHandle->Dispose(h);
    } else {
        pathName.clear();
    }
	
	return error;
}

OSErr PIGetWorkPathIndex(int32 & pathIndex)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propWorkPathIndex, 
                                               0, &t, NULL);
    if (!error)
        pathIndex = (int32)t;
    
    return error;
}

OSErr PIGetClippingPathIndex(int32 & pathIndex)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propClippingPathIndex, 
                                               0, &t, NULL);
    if (!error)
        pathIndex = (int32)t;
    
    return error;
}

OSErr PIGetTargetPathIndex(int32 & pathIndex)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propTargetPathIndex, 
                                               0, &t, NULL);
    if (!error)
        pathIndex = (int32)t;
    
    return error;
}

OSErr PIGetPathContents(const int32 index, Handle & contents)
{
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propPathContents, 
										index, NULL, &contents);
}

OSErr PIGetPathContentsAI(const int32 index, Handle & contents)
{
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propPathContentsAI, 
										index, NULL, &contents);
}

OSErr PIGetCaption(Handle & caption)
{
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propCaption, 
										0, NULL, &caption);
}

OSErr PISetCaption(const Handle inCaption)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propCaption, 
										0, NULL, inCaption);
}

OSErr PIGetBigNudge(double & horizontal, double & vertical)
{
	intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propBigNudgeH, 
											   0, &t, NULL);
	Fixed f = (Fixed)(t);
	
	if (!error)
	{
		horizontal = FixedToDouble(f);

		error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
			                                 propBigNudgeV,
											 0, &t, NULL);
	}
	
	f = (Fixed)(t);

	if (!error)
		vertical = FixedToDouble(f);

	return error;
}

OSErr PISetBigNudge(const double horizontal, const double vertical)
{
	OSErr error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                       propBigNudgeH, 
											   0, DoubleToFixed(horizontal), NULL);
	
	if (!error)
		error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                     propBigNudgeV, 
											 0, DoubleToFixed(vertical), NULL);

	return error;
}

OSErr PIGetInterpolationMethod(InterpolationMethod & method)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propInterpolationMethod, 
											   0, &simple, NULL);
	
	if (!error)
		method = static_cast<InterpolationMethod>(simple);

	return error;
}

OSErr PIGetRulerUnits(RulerUnits & units)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propRulerUnits, 
											   0, &simple, NULL);

	if (!error)
		units = static_cast<RulerUnits>(simple);

	return error;
}

OSErr PIGetRulerOrigin(double & horizontal, double & vertical)
{
	intptr_t t;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propRulerOriginH, 
											   0, &t, NULL);
	
	Fixed f = (Fixed)(t);

	if (!error)
	{
		horizontal = FixedToDouble(f);

		error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
			                                 propRulerOriginV,
											 0, &t, NULL);
	}

	f = (Fixed)(t);

	if (!error)
		vertical = FixedToDouble(f);

	return error;
}

OSErr PISetRulerOrigin(const double horizontal, const double vertical)
{
	OSErr error = sPSProperty->setPropertyProc(kPhotoshopSignature,
		                                       propRulerOriginH, 
											   0, DoubleToFixed(horizontal), NULL);
	
	if (!error)
		error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                     propRulerOriginV, 
											 0, DoubleToFixed(vertical), NULL);

	return error;
}
	
OSErr PIGetGrid(double & major, int32 & minor)
{
	intptr_t t;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propGridMajor, 
											   0, &t, NULL);
	
	Fixed f = (Fixed)(t);

	if (!error)
	{
		major = FixedToDouble(f);

		error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
			                                 propGridMinor, 
											 0, &t, NULL);
        if (!error)
            minor = (int32)t;
	}

	return error;
}

OSErr PISetGrid(const double major, const int32 minor)
{
	OSErr error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                       propGridMajor, 
											   0, DoubleToFixed(major), NULL);

	if (!error)
		error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                     propGridMinor, 
											 0, minor, NULL);

	return error;
}
	
OSErr PIGetSerialStringOld(string & serialStr)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propSerialString, 
											   0, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, serialStr);
		sPSHandle->Dispose(h);
    } else {
        serialStr.clear();
    }
	
	return error;
}

OSErr PIGetSerialString(string & serialStr )
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propSerialString2, 
											   0, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, serialStr);
		sPSHandle->Dispose(h);
    } else {
        serialStr.clear();
    }
	
	return error;
}

#if __PIWin__
OSErr PIGetHardwareGammaTable(Handle & gammaTable)
{
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propHardwareGammaTable, 
										0, NULL, &gammaTable);
}
#endif

OSErr PIGetInterfaceColor(const int8 index, PIInterfaceColor & color)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propInterfaceColor, 
											   index, NULL, &h);

	if (!error && h != NULL)
	{
		Boolean oldLock = FALSE;
		PIInterfaceColor * p = NULL;
		sPSHandle->SetLock(h, true, reinterpret_cast<char**>(&p), &oldLock);
		if (p != NULL)
		{
			color = *p;
			sPSHandle->SetLock(h, false, reinterpret_cast<char**>(&p), &oldLock);
			sPSHandle->Dispose(h);
		}
		else
		{
			sPSHandle->Dispose(h);
			h = NULL;
			error = errPlugInHostInsufficient;
		}
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr PIGetGuideColor (RGBColor & color)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc (kPhotoshopSignature,
												propGuideColor, 0, NULL, &h);

	if (!error && h != NULL)
	{
		error = HandleToColor(h, color);
		sPSHandle->Dispose(h);
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr PIGetGuideCount(int32 & count)
{
	intptr_t t;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propGuideCount, 
											   0, &t, NULL);
	
	if (!error)
		count = (int32)t;

	return error;
}

OSErr PIGetTileSize(int32 & tileSize)
{
	intptr_t t;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propTileSize, 
											   0, &t, NULL);
	
	if (!error)
		tileSize = (int32)t;

	return error;
}

OSErr PIGetGuideHorizontal(const int32 index, bool & guideHorizontal)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propGuideDirIsHoriz, 
											   index, &simple, NULL);
	
	if (!error)
		guideHorizontal = simple != 0;

	return error;
}

OSErr PIGetGuidePosition(const int32 index, double & guidePosition)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propGuideCoordinate, 
											   index, &simple, NULL);
	
	if (!error)
		guidePosition = (double)simple;

	return error;
}

OSErr PIGetWatchSuspension(int32 & watch)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propWatchSuspension, 
                                               0, &t, NULL);
    if (!error)
        watch = (int32)t;
    
    return error;
}

OSErr PIGetVRAM(int32 & vram)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propVRAM_MB, 
                                               0, &t, NULL);
    if (!error)
        vram = (int32)t;
    
    return error;
}

OSErr PIGetGPUFlags(int32 & gpuFlags)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propGPUFlags, 
                                               0, &t, NULL);
    if (!error)
        gpuFlags = (int32)t;
    
    return error;
}

OSErr PISetWatchSuspension(const int32 inWatchSuspension)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propWatchSuspension, 
										0, inWatchSuspension, NULL);
}

OSErr PIGetCopyright(bool & copyright)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propCopyright, 
											   0, &simple, NULL);
	
	if (!error)
		copyright = simple != 0;

	return error;
}
	
OSErr PIGetCopyright2(bool & copyright)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propCopyright2, 
											   0, &simple, NULL);
	
	if (!error)
		copyright = simple != 0;

	return error;
}
	
OSErr PISetCopyright(const bool inCopyright)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propCopyright, 
										0, inCopyright, NULL);
}

OSErr PISetCopyright2(const bool inCopyright)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propCopyright2, 
										0, inCopyright, NULL);
}

OSErr PIGetURL(string & url)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propURL, 
											   0, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, url);
		sPSHandle->Dispose(h);
    } else {
        url.clear();
    }
	
	return error;
}

OSErr PISetURL(const string & inURL)
{
	Handle h = NULL;

	OSErr error = StringToHandle(inURL, h);
	
	if (!error && h != NULL)
	{
		error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
			                                 propURL, 
											 0, NULL, h);
		sPSHandle->Dispose(h);
	}
	else
	{
		error = errPlugInHostInsufficient;
	}
	
	return error;
}

OSErr PIGetDocumentName(string & name)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propTitle, 
											   0, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, name);
		sPSHandle->Dispose(h);
    } else {
        name.clear();
    }
	
	return error;
}

OSErr PIGetWatermark(bool & watermark)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propWatermark, 
											   0, &simple, NULL);
	
	if (!error)
		watermark = (simple != 0);

	return error;
}

OSErr PIGetCrosshairVisible(bool & crossHairVisible)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propPaintCursorCrosshair, 
											   0, &simple, NULL);
	
	if (!error)
		crossHairVisible = (simple != 0);

	return error;
}

OSErr PIGetZoomWithScrollWheel(bool & zoomWithWheel)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propZoomWithScrollWheel, 
											   0, &simple, NULL);
	
	if (!error)
		zoomWithWheel = (simple != 0);

	return error;
}

OSErr PISetWatermark(void)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propWatermark, 
										0, 1, NULL);
}

OSErr PIGetDocumentHeight(int32 & height)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propDocumentHeight, 
                                               0, &t, NULL);
    if (!error)
        height = (int32)t;
    
    return error;
}

OSErr PIGetDocumentWidth(int32 & width)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propDocumentWidth, 
                                               0, &t, NULL);
    if (!error)
        width = (int32)t;
    
    return error;
}

OSErr PIGetToolTips(bool & toolTips)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propToolTips, 
											   0, &simple, NULL);
	
	if (!error)
		toolTips = simple != 0;

	return error;
}

OSErr PIGetPaintCursorKind(PaintCursorKind & cursorKind)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propPaintCursorKind, 
											   0, &simple, NULL);

	if (!error)
		cursorKind = static_cast<PaintCursorKind>(simple);

	return error;
}

OSErr PIGetPaintCursorShape(PaintCursorShape & cursorShape)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propPaintCursorShape, 
											   0, &simple, NULL);

	if (!error)
		cursorShape = static_cast<PaintCursorShape>(simple);

	return error;
}

OSErr PIGetSlices(Handle & slices)
{	
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propSlices, 
										0, NULL, &slices);
}

OSErr PISetSlices(const Handle inSlices)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propSlices, 
										0, NULL, inSlices);
}

OSErr PIGetScratchVolumeList(Handle & volumeList)
{	
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propScratchVolumeList, 
										0, NULL, &volumeList);
}

OSErr PIGetSelectedSliceID(int32 & sliceID)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
                                               propSelectedSliceID, 
                                               0, &t, 0);
    if (!error)
        sliceID = (int32)t;
    
    return error;
}

OSErr PISetSelectedSliceID(int32 sliceID)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propSelectedSliceID, 
										0, sliceID, 0);
}

OSErr PIGetSelectedSliceIndex(int32 & sliceIndex)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
                                               propSelectedSliceIndex, 
                                               0, &t, NULL);
    if (!error)
        sliceIndex = (int32)t;
    
    return error;
}

OSErr PIGetDontShowAgainCount(int32 & dontShowCount)
{
    intptr_t t;
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
                                               propDontShowAgainCount, 
                                               0, &t, NULL);
    if (!error)
        dontShowCount = (int32)t;
    
    return error;
}

OSErr PISetSelectedSliceIndex(int32 sliceIndex)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propSelectedSliceIndex, 
										0, sliceIndex, NULL);
}

OSErr PIGetShowSliceNumbers(bool & showSliceNumbers)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propShowSliceNumbers, 
											   0, &simple, NULL);
	
	if (!error)
		showSliceNumbers = simple != 0;

	return error;
}

OSErr PIGetSliceLineColor(RGBColor & lineColor)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propSliceLineColor, 
											   0, NULL, &h);

	if (!error && h != NULL)
	{
		error = HandleToColor(h, lineColor);
		sPSHandle->Dispose(h);
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr PIGetEXIFData(Handle & exif)
{
	return sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                propEXIFData, 
										0, NULL, &exif);
}

OSErr PISetEXIFData(const Handle inEXIFData)
{
	return sPSProperty->setPropertyProc(kPhotoshopSignature, 
		                                propEXIFData, 
										0, NULL, inEXIFData);
}

OSErr PIGetPlayInProgress(bool & inProgress)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propPlayInProgress, 
											   0, &simple, NULL);
	
	if (!error)
		inProgress = simple != 0;

	return error;
}

OSErr PIGetRecordInProgress(bool & inProgress)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propRecordInProgress, 
											   0, &simple, NULL);
	
	if (!error)
		inProgress = simple != 0;

	return error;
}

OSErr PIGetDoingPlace(bool & doingPlace)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propDoingPlace, 
											   0, &simple, NULL);
	
	if (!error)
		doingPlace = simple != 0;

	return error;
}

OSErr PIGetRasterizingSmartObject(bool & rasterizingSmart)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propRasterizingSmartObject, 
											   0, &simple, NULL);
	
	if (!error)
		rasterizingSmart = simple != 0;

	return error;
}

OSErr PIGetAppIsModal(bool & appIsModal)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propAppIsModal, 
											   0, &simple, NULL);
	
	if (!error)
		appIsModal = simple != 0;

	return error;
}

OSErr PIGetLayerIsSmart(bool & inSmart)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propLayerIsSmart, 
											   0, &simple, NULL);
	
	if (!error)
		inSmart = simple != 0;

	return error;
}

OSErr PIGetHDPIAware(bool & inAware)
{
	intptr_t simple = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propHDPIAware, 
											   0, &simple, NULL);
	
	if (!error)
		inAware = simple != 0;

	return error;
}

OSErr PIGetHostVersion(int32 & major, int32 & minor, int32 & fix)
{
	intptr_t s = 0;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propVersion, 
											   0, &s, NULL);

	int32 simple = (int32)s;
	if (!error)
	{
		major = (simple & 0xffff0000) >> 16;
		minor = (simple & 0x0000ff00) >> 8;
		fix =	(simple & 0x000000ff);
	}

	return error;
}

OSErr PIGetXMP(string & xmp)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propXMP, 
											   0, NULL, &h);
	
	if (!error && h != NULL)
	{
		error = HandleToString(h, xmp);
		sPSHandle->Dispose(h);
    } else {
        xmp.clear();
    }
	
	return error;
}

OSErr PISetXMP(const string & inXMP)
{
	Handle h = NULL;

	OSErr error = StringToHandle(inXMP, h);
    if (error) return error;
	
	if (h != NULL)
	{
		error = sPSProperty->setPropertyProc(kPhotoshopSignature, 
			                                 propXMP, 
											 0, NULL, h);
		sPSHandle->Dispose(h);
	}
	else
	{
		error = errPlugInHostInsufficient;
	}
	
	return error;
}

OSErr PIGetDocumentName(ps_wstring & name, bool withExtension)
{
	Handle h = NULL;
	
	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       withExtension ? propUnicodeName : propUnicodeNameWithoutExtension, 
											   0, NULL, &h);

	if (!error && h != NULL)
	{
		error = HandleToString(h, name);
		sPSHandle->Dispose(h);
    } else {
        name.clear();
    }

	return error;
}

OSErr PIGetUIBrightness(UIBrightness & brightness)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
											   propUIBrightness,
											   0, &simple, NULL);

	if (!error)
		brightness = (UIBrightness)simple;

	return error;
}

OSErr PIGetLargeTabs(bool & inTabs)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
											   propLargeTabs,
											   0, &simple, NULL);

	if (!error)
		inTabs = simple != 0;

	return error;
}

OSErr PIGetCheckerboardColor(const int8 index, RGBColor & color)
{
	Handle h = NULL;

	PIType key = index == 1 ? propCheckerboardColor1 : propCheckerboardColor2;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
											   key, 0, NULL, &h);

	if (!error && h != NULL)
	{
		error = HandleToColor(h, color);
		sPSHandle->Dispose(h);
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}

OSErr PIGetCheckerboardSize(CheckerBoardSize & size)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
											   propCheckerboardSize,
											   0, &simple, NULL);

	if (!error)
		size = (CheckerBoardSize)simple;

	return error;
}

OSErr PIGetCheckerboardOn(bool & on)
{
	intptr_t simple = 0;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature,
											   propUseCheckerboard,
											   0, &simple, NULL);

	if (!error)
		on = simple != 0;

	return error;
}


OSErr PIGetUnicodeStr255Name(Str255 & name)
{
	Handle h = NULL;

	OSErr error = sPSProperty->getPropertyProc(kPhotoshopSignature, 
		                                       propUniStr255Name, 
											   0, NULL, &h);

	if (!error && h != NULL)
	{
		error = HandleToString(h, name);
		sPSHandle->Dispose(h);
    } else {
        name[0] = 0;
        name[1] = 0;
    }

	return error;
}

static Fixed DoubleToFixed(double in)
{	
	uint16 n = static_cast<uint16>(in);
	double t = in - n;
	t *= 65536.0;
	uint16 r = static_cast<uint16>(t);
	Fixed f = n << 16;
	f += r;
	return (f);
}

static double FixedToDouble(Fixed in)
{
	uint16 * n = reinterpret_cast<uint16*>(&in);
	uint16 * r = n++;
	return ((double)(*n) + ((double)(*r) / 65536.0));
}

static OSErr HandleToColor(const Handle h, RGBColor & color)
{
	OSErr error = kNoErr;
	Boolean oldLock = FALSE;
	RGBColor * p = NULL;
	sPSHandle->SetLock(h, true, reinterpret_cast<char**>(&p), &oldLock);
	if (p != NULL)
	{
		color = *p;
		sPSHandle->SetLock(h, false, reinterpret_cast<char**>(&p), &oldLock);
	}
	else
	{
		error = errPlugInHostInsufficient;
	}

	return error;
}
// end PropertyUtils.cpp