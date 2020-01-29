#include <PIDefines.h>
#include <PIAbout.h>
#include <PIFilter.h>
#include <SPBasic.h>


SPBasicSuite *sSPBasic = NULL;


void executeFilter(const FilterRecordPtr &filterRecord)
{
	return;
}


/**
 * By convention, this is the entry point for Photoshop Filter plug-ins.
 *
 * @param selector			Host provides selector indicating what command to do.

 * @param filterRecord		Host provides a pointer to parameter block containing
 * 						pertinent data and callbacks. See ``PIFilter.h``.

 * @param data				Use this to store a pointer to our global data structure,
 * 						which is maintained by the host between calls to the plug-in.

 * @param result			Returns error result. Some errors are handled by the host,
 * 						some are silent, and some you must handle. See ``PIGeneral.h``.
 */
DLLExport MACPASCAL void PluginMain(const int16_t selector,
									FilterRecordPtr filterRecord,
									long long *data,
									int16_t *result)
{
	switch (selector) {
	case filterSelectorAbout:
		sSPBasic = ((AboutRecord *)filterRecord)->sSPBasic;

	case filterSelectorStart:
	{
		sSPBasic = filterRecord->sSPBasic;
		if (filterRecord->bigDocumentData != NULL) {
			filterRecord->bigDocumentData->PluginUsing32BitCoordinates = true;
		}

		executeFilter(filterRecord);

		break;
	}
	default:
		break;
	}

	return;
}
