#include "PIDefines.h"
#include "tutorial_imgui_globals.h"

#ifdef __PIMac__
	#include "PIGeneral.r"
    #include "PIUtilities.r"
#elif defined(__PIWin__)
	#define Rez
	#include "PIGeneral.h"
	#include "PIUtilities.r"
#endif

#include "PITerminology.h"
#include "PIActions.h"

resource 'PiPL' ( TUTORIAL_IMGUI_AUTO_RESOURCE_ID, TUTORIAL_IMGUI_AUTO_PLUGINNAME, purgeable)
	{
		{
		Kind { Actions },
		Name { TUTORIAL_IMGUI_AUTO_PLUGINNAME },
		Category { "AdobeSDK" },
		Version { (latestActionsPlugInVersion << 16) | latestActionsPlugInSubVersion },

		Component { ComponentNumber, TUTORIAL_IMGUI_AUTO_PLUGINNAME },

		#ifdef __PIMac__
			CodeMacIntel64 { "AutoPluginMain" },
		#else
			#if defined(_WIN64)
				CodeWin64X86 { "AutoPluginMain" },
			#else
				CodeWin32X86 { "AutoPluginMain" },
			#endif
		#endif

		// This has the side effect of disabling the plugin in the UI until a document is
		// actually open. Perfect.
		EnableInfo { "true" },

		HasTerminology
			{
			TUTORIAL_IMGUI_AUTO_CLASS_ID,
			TUTORIAL_IMGUI_AUTO_EVENT_ID,
			TUTORIAL_IMGUI_AUTO_RESOURCE_ID,
			TUTORIAL_IMGUI_AUTO_UUID
			},

		// We include "Persistent" to keep the plug-in loaded until
		// until Photoshop quits.
		Persistent{},

		// Only relevant if Persistent is set.
		Messages
		{
			startupRequired,
			doesNotPurgeCache,
			shutdownRequired,
			acceptProperty
		},
		}
	};

//-------------------------------------------------------------------------------
//	Dictionary (scripting) resource
//-------------------------------------------------------------------------------
resource 'aete' (TUTORIAL_IMGUI_AUTO_RESOURCE_ID, TUTORIAL_IMGUI_AUTO_PLUGINNAME " dictionary", purgeable)
	{
	1, 0, english, roman,					/* aete version and language specifiers */
		{
		TUTORIAL_IMGUI_AUTO_VENDORNAME,							/* vendor suite name */
		TUTORIAL_IMGUI_AUTO_PLUGINDESC,		/* optional description */
		TUTORIAL_IMGUI_AUTO_SUITE_ID,	/* suite ID */
		1,									/* suite code, must be 1 */
		1,									/* suite level, must be 1 */
			{								/* structure for automation */
			TUTORIAL_IMGUI_AUTO_PLUGINNAME,		/* name */
			TUTORIAL_IMGUI_AUTO_PLUGINDESC,		/* optional description */
			TUTORIAL_IMGUI_AUTO_CLASS_ID,		/* class ID, must be unique or Suite ID */
			TUTORIAL_IMGUI_AUTO_EVENT_ID,		/* event ID, must be unique */

			NO_REPLY,						/* never a reply */
			IMAGE_DIRECT_PARAMETER,			/* direct parameter, used by Photoshop */
				{							// filter or selection class here:
				}
			},
			{},	/* non-filter/automation plug-in class here */
			{}, /* comparison ops (not supported) */
			{ // Enumerations go here:
			}	/* end of any enumerations */
		}
	};
