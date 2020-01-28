#ifndef __FilterBigDocument_H__
#define __FilterBigDocument_H__

#include "PIDefines.h"
#include "PITypes.h"
#include "PIFilter.h"

VPoint GetImageSize(void);
VRect GetFilterRect(void);
VRect GetInRect(void);
VRect GetOutRect(void);
VRect GetMaskRect(void);
VPoint GetFloatCoord(void);
VPoint GetWholeSize(void);

void SetInRect(VRect inRect);
void SetOutRect(VRect inRect);
void SetMaskRect(VRect inRect);

extern FilterRecord * gFilterRecord;

#endif
