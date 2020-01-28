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

#ifndef __PIUActionUtils_H__		// Has this not been defined yet?
#define __PIUActionUtils_H__		// Only include this once by predefining it

#include <vector>
#include <fstream>

#include "PITypes.h"
#include "PIGeneral.h"
#include "SPBasic.h"
#include "PIActions.h"
#include "PIUSuites.h"
#include "PIUFile.h"
#include "PSConstantArray.h"
#include "PITerminology.h"

using namespace std;

const int16 HashStrMaxLen =	35;
const int16 BigStrMaxLen  =	256;
const int32 SmallestHashValue = 538976288; // '    ' four spaces

SPErr PIUCheckPlayResult(PIActionDescriptor result);
void PIUDumpDescriptor(const DescriptorEventID event,	
					   const PIActionDescriptor result, 
					   const char* fullpathtofile);
unsigned long PIUCharToID(const char* inChars);

double UnitsToPixels(double value, int units, double resolution);
double PixelsToUnits(double value, int units, double resolution);

#endif
// end PIUActionUtils.h
