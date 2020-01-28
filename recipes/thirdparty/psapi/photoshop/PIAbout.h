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
 *	\file PIAbout.h
 *
 *	\brief This file describes Photoshop's plug-in module interface
 *		for the about box selector.
 *
 *	Distribution:
 *		PUBLIC
 *
 */		

#ifndef __PIAbout__
#define __PIAbout__

#if PRAGMA_ONCE
#pragma once
#endif

#include "SPBasic.h"
#include "SPMData.h"

/******************************************************************************/
#define plugInSelectorAbout 	 0

/** 
* Record passed to plug-in modules for the about selectors. When the host
* sends the about selector to a plug-in module, the usual plug-in parameter block 
* is not filled out, none of the callbacks or standard data are available.  Instead
* the parameter block points to this data structure. 
* 
* See @ref PGAboutBoxes	"About Boxes" for more information.
*/
typedef struct AboutRecord 
	{

	void *		platformData;		/**< Platform specific information. See PlatformData in PITypes.h. */
	
	SPBasicSuite *sSPBasic;			/**< PICA basic suite */
	void		*plugInRef;			/**< Plug-in reference used by PICA */
	char		reserved [244]; 	/**< Reserved bytes. Set to zero */

	}
AboutRecord, *AboutRecordPtr;

/******************************************************************************/

#endif // __PIAbout_h__ 
