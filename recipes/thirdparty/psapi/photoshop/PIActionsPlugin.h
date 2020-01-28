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
 *	\file PIActionsPlugIn.h	
 *
 *	\brief This file describes Photoshop's actions plug-in module
 *		interface.
 *
 *	Distribution:
 *		PUBLIC
 *
 *	\details
 *		Include in Photoshop Action plug-ins.
 *		
 */

#ifndef __PIActionsPlugIn__
#define __PIActionsPlugIn__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"
#include "SPMData.h"

/********************************************************************************/

/** 
* @defgroup AutomationModule Automation Module
* Automation plug-in modules access all Photoshop scriptable events.  These modules
* appear under the \b Automate menu or the \b Help menu. 
* Automation plug-ins are built on top of the Adobe Plug-in Component Architecture (PICA).
* For further information, see <a href="../Photoshop Actions Guide.pdf">Photoshop Actions Event Guide</a>, 
* and <a href="../PICA.pdf">Adobe PICA API</a>.
*
* Since Automation modules are built on top of PICA, they have a different invocation than many
* of the other Photoshop plug-in modules.  By convention the entry point is called \c AutoPluginMain: 
*
*@code
		DLLExport SPAPI SPErr AutoPluginMain(
			const char* caller,	  // who is calling
			const char* selector, // what do they want
			void* message	      // what is the message
		)
@endcode
* Three arguments are passed to the \c AutoPluginMain( ) function, collectively they
* make up a message. The first two parameters represent the message action,
* describing what the plug-in is supposed to do. The \c caller string identifies the
* sender of the message and a general category of action. The \c selector string
* specifies the action to take within the category of action. 
* 
* All PICA plug-ins receive five message actions: startup, shutdown, reload, unload and about. 
* These are documented in <a href="../PICA.pdf">The Adobe PICA API</a>.  
* In addition, automation plug-ins receive a caller/selector pair that indicates the plug-in 
* should begin the automation.  See @ref kPSPhotoshopCaller and @ref kPSDoIt.
* 
* The third parameter is a pointer to a data structure, which provides data that depends on the
* message action.  For an Automation module, when the caller/selector pair is 
* \c kPSPhotoshopCaller/kPSDoIt, the data structure is the \c PSActionsPlugInMessage. 
* @{
*/

/**
* Message passed to all automation plug-in entry points, when the caller is 
* is \c kPSPhotoshopCaller and the selector is \c kPSDoIt. See <a href="../PICA.pdf">Adobe PICA API</a>.
*/
typedef struct PSActionsPlugInMessage
	{
	SPMessageData			d;					/**< Basic message information. The PICA Basic Suite
													 is available through this message data by
													 referencing \c d->basic. 
													 See <a href="../PICA.pdf">Adobe PICA API</a>. 													 */
	PIActionParameters		*actionParameters;	/**< Parameters for recording and playback */
	} PSActionsPlugInMessage;

#endif // __PIActionsPlugIn_h__

/** @} */
