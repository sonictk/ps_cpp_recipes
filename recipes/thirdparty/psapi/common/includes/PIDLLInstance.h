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
#ifndef _PIDLLInstance_H
#define _PIDLLInstance_H

#include "PIDefines.h"

#include "SPPlugs.h"
#include "SPAccess.h"

#include "PIUSuites.h"

#include <windows.h>

HINSTANCE GetDLLInstance(SPPluginRef plugin = NULL);

#endif
// end PIDLLInstance.h
