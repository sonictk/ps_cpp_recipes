// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2002 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------------------

#ifndef __PIUSelect_H__		// Has this not been defined yet?
#define __PIUSelect_H__		// Only include this once by predefining it

#include "PIUActionUtils.h"
#include "PITypes.h"
#include "PIGeneral.h"
#include "SPBasic.h"
#include "PIActions.h"

SPErr PIUSelectByName(DescriptorClassID desiredClass, char *cstrValue);
SPErr PIUSelectByIndex(DescriptorClassID desiredClass, uint32 value);
SPErr PIUSelectByID(DescriptorClassID desiredClass, uint32 value);
SPErr PIUSelectByOffset(DescriptorClassID desiredClass, int32 value);

#endif
// end PIUSelect.h
