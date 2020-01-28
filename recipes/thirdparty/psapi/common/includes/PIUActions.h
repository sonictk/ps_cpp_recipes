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

#ifndef __PIUActions_H__		// Has this not been defined yet?
#define __PIUActions_H__		// Only include this once by predefining it

#include "PIUActionUtils.h"
#include "PITypes.h"
#include "PIGeneral.h"
#include "SPBasic.h"
#include "PIActions.h"

SPErr PIUActionsPlayByName(char* setName, char* actionName);
SPErr PIUActionsGetName(uint32 setIndex, 
					    uint32 actionIndex, 
					    char* actionName, 
					    uint32* actionNameLength);
SPErr PIUActionsGetName(char* setName, 
					    uint32 actionIndex, 
					    char* actionName, 
					    uint32* actionNameLength);
#endif
// end PIUActions.h