#include "FilterBigDocument.h"

VPoint GetImageSize(void)
{
	VPoint returnPoint = { 0, 0};

	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnPoint.h = gFilterRecord->bigDocumentData->imageSize32.h;
		returnPoint.v = gFilterRecord->bigDocumentData->imageSize32.v;
	}
	else
	{
		returnPoint.h = gFilterRecord->imageSize.h;
		returnPoint.v = gFilterRecord->imageSize.v;
	}

	return returnPoint;
}

VRect GetFilterRect(void)
{
	VRect returnRect = { 0, 0, 0, 0};
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnRect.right = gFilterRecord->bigDocumentData->filterRect32.right;
		returnRect.top = gFilterRecord->bigDocumentData->filterRect32.top;
		returnRect.left = gFilterRecord->bigDocumentData->filterRect32.left;
		returnRect.bottom = gFilterRecord->bigDocumentData->filterRect32.bottom;
	}
	else
	{
		returnRect.right = gFilterRecord->filterRect.right;
		returnRect.top = gFilterRecord->filterRect.top;
		returnRect.left = gFilterRecord->filterRect.left;
		returnRect.bottom = gFilterRecord->filterRect.bottom;
	}
	
	return returnRect;
}

VRect GetInRect(void)
{
	VRect returnRect = { 0, 0, 0, 0};
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnRect.right = gFilterRecord->bigDocumentData->inRect32.right;
		returnRect.top = gFilterRecord->bigDocumentData->inRect32.top;
		returnRect.left = gFilterRecord->bigDocumentData->inRect32.left;
		returnRect.bottom = gFilterRecord->bigDocumentData->inRect32.bottom;
	}
	else
	{
		returnRect.right = gFilterRecord->inRect.right;
		returnRect.top = gFilterRecord->inRect.top;
		returnRect.left = gFilterRecord->inRect.left;
		returnRect.bottom = gFilterRecord->inRect.bottom;
	}
	
	return returnRect;
}

VRect GetOutRect(void)
{
	VRect returnRect = { 0, 0, 0, 0};
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnRect.right = gFilterRecord->bigDocumentData->outRect32.right;
		returnRect.top = gFilterRecord->bigDocumentData->outRect32.top;
		returnRect.left = gFilterRecord->bigDocumentData->outRect32.left;
		returnRect.bottom = gFilterRecord->bigDocumentData->outRect32.bottom;
	}
	else
	{
		returnRect.right = gFilterRecord->outRect.right;
		returnRect.top = gFilterRecord->outRect.top;
		returnRect.left = gFilterRecord->outRect.left;
		returnRect.bottom = gFilterRecord->outRect.bottom;
	}
	
	return returnRect;
}

VRect GetMaskRect(void)
{
	VRect returnRect = { 0, 0, 0, 0};
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnRect.right = gFilterRecord->bigDocumentData->maskRect32.right;
		returnRect.top = gFilterRecord->bigDocumentData->maskRect32.top;
		returnRect.left = gFilterRecord->bigDocumentData->maskRect32.left;
		returnRect.bottom = gFilterRecord->bigDocumentData->maskRect32.bottom;
	}
	else
	{
		returnRect.right = gFilterRecord->maskRect.right;
		returnRect.top = gFilterRecord->maskRect.top;
		returnRect.left = gFilterRecord->maskRect.left;
		returnRect.bottom = gFilterRecord->maskRect.bottom;
	}
	
	return returnRect;
}

VPoint GetFloatCoord(void)
{
	VPoint returnPoint = { 0, 0};

	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnPoint.h = gFilterRecord->bigDocumentData->floatCoord32.h;
		returnPoint.v = gFilterRecord->bigDocumentData->floatCoord32.v;
	}
	else
	{
		returnPoint.h = gFilterRecord->floatCoord.h;
		returnPoint.v = gFilterRecord->floatCoord.v;
	}

	return returnPoint;
}

VPoint GetWholeSize(void)
{
	VPoint returnPoint = { 0, 0};

	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		returnPoint.h = gFilterRecord->bigDocumentData->wholeSize32.h;
		returnPoint.v = gFilterRecord->bigDocumentData->wholeSize32.v;
	}
	else
	{
		returnPoint.h = gFilterRecord->wholeSize.h;
		returnPoint.v = gFilterRecord->wholeSize.v;
	}

	return returnPoint;
}

void SetInRect(VRect inRect)
{
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		gFilterRecord->bigDocumentData->inRect32.right = inRect.right;
		gFilterRecord->bigDocumentData->inRect32.top = inRect.top;
		gFilterRecord->bigDocumentData->inRect32.left = inRect.left;
		gFilterRecord->bigDocumentData->inRect32.bottom = inRect.bottom;
	}
	else
	{
		gFilterRecord->inRect.right = (int16)inRect.right;
		gFilterRecord->inRect.top = (int16)inRect.top;
		gFilterRecord->inRect.left = (int16)inRect.left;
		gFilterRecord->inRect.bottom = (int16)inRect.bottom;
	}
}

void SetOutRect(VRect inRect)
{
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		gFilterRecord->bigDocumentData->outRect32.right = inRect.right;
		gFilterRecord->bigDocumentData->outRect32.top = inRect.top;
		gFilterRecord->bigDocumentData->outRect32.left = inRect.left;
		gFilterRecord->bigDocumentData->outRect32.bottom = inRect.bottom;
	}
	else
	{
		gFilterRecord->outRect.right = (int16)inRect.right;
		gFilterRecord->outRect.top = (int16)inRect.top;
		gFilterRecord->outRect.left = (int16)inRect.left;
		gFilterRecord->outRect.bottom = (int16)inRect.bottom;
	}
}

void SetMaskRect(VRect inRect)
{
	if (gFilterRecord->bigDocumentData != NULL && 
		gFilterRecord->bigDocumentData->PluginUsing32BitCoordinates)
	{
		gFilterRecord->bigDocumentData->maskRect32.right = inRect.right;
		gFilterRecord->bigDocumentData->maskRect32.top = inRect.top;
		gFilterRecord->bigDocumentData->maskRect32.left = inRect.left;
		gFilterRecord->bigDocumentData->maskRect32.bottom = inRect.bottom;
	}
	else
	{
		gFilterRecord->maskRect.right = (int16)inRect.right;
		gFilterRecord->maskRect.top = (int16)inRect.top;
		gFilterRecord->maskRect.left = (int16)inRect.left;
		gFilterRecord->maskRect.bottom = (int16)inRect.bottom;
	}
}
// end FilterBigDocument.cpp
