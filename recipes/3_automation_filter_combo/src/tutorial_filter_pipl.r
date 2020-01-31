#include "PIDefines.h"
#include "tutorial_globals.h"

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

resource 'PiPL' ( TUTORIAL_FILTER_RESOURCE_ID, TUTORIAL_FILTER_PLUGINNAME, purgeable )
{
	{
		Kind { Filter },
		Name { TUTORIAL_FILTER_PLUGINNAME },
		// Category { "**Hidden**" }, // This is so that the filter doesn't show up in the UI
		Version { (latestFilterVersion << 16) | latestFilterSubVersion },

		Component { ComponentNumber, TUTORIAL_FILTER_PLUGINNAME },

		#ifdef __PIMac__
			CodeMacIntel64 { "PluginMain" },
		#else
			#if defined(_WIN64)
				CodeWin64X86 { "PluginMain" },
			#else
				CodeWin32X86 { "PluginMain" },
			#endif
		#endif

		EnableInfo { "true" },
		HasTerminology { TUTORIAL_FILTER_CLASS_ID,
						 TUTORIAL_FILTER_EVENT_ID,
						 TUTORIAL_FILTER_RESOURCE_ID,
						 TUTORIAL_FILTER_UUID },
		FilterCaseInfo
		{
			{
				/* Flat data, no selection */
				inWhiteMat, outWhiteMat,
				doNotWriteOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination,

				/* Flat data with selection */
				inWhiteMat, outWhiteMat,
				writeOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination,

				/* Floating selection */
				inWhiteMat, outWhiteMat,
				writeOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination,

				/* Editable transparency, no selection */
				inWhiteMat, outWhiteMat,
				doNotWriteOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination,

				/* Editable transparency, with selection */
				inWhiteMat, outWhiteMat,
				writeOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination,

				/* Preserved transparency, no selection */
				inWhiteMat, outWhiteMat,
				doNotWriteOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination,

				/* Preserved transparency, with selection */
				inWhiteMat, outWhiteMat,
				writeOutsideSelection,
				filtersLayerMasks, worksWithBlankData,
				copySourceToDestination
			}
		},
	}
};


resource 'aete' ( TUTORIAL_FILTER_RESOURCE_ID, " dictionary", purgeable)
{
	1, 0, english, roman,									/* aete version and language specifiers */
	{
		TUTORIAL_FILTER_VENDORNAME,	/* vendor suite name */
		TUTORIAL_FILTER_PLUGINDESC,	/* optional description */
		TUTORIAL_FILTER_SUITE_ID,		/* suite ID */
		1,													/* suite code, must be 1 */
		1,													/* suite level, must be 1 */
		{													/* structure for filters */
			TUTORIAL_FILTER_PLUGINNAME,	/* unique filter name */
			TUTORIAL_FILTER_PLUGINDESC,	/* optional description */
			TUTORIAL_FILTER_CLASS_ID,		/* class ID, must be unique or Suite ID */
			TUTORIAL_FILTER_EVENT_ID,		/* event ID, must be unique to class ID */

			NO_REPLY,										/* never a reply */
			IMAGE_DIRECT_PARAMETER,						/* direct parameter, used by Photoshop */
			{												/* parameters here, if any */
				TUTORIAL_FILTER_TRIGGERNAME,
				TUTORIAL_FILTER_KEYTRIGGER,
				TUTORIAL_FILTER_TYPETRIGGER,
				TUTORIAL_FILTER_TRIGGERDESC,
				flagsSingleParameter
			}
		},
		{													/* non-filter plug-in class here */
		},
		{													/* comparison ops (not supported) */
		},
		{													/* any enumerations */
			// TUTORIAL_FILTER_TYPETRIGGER,
			// {
			// 	TUTORIAL_FILTER_ENUMINFONAME,
			// 	TUTORIAL_FILTER_ENUMINFO,
			// 	""
			// }
		}
	}
};
