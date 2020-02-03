#include <SPBasic.h>
#include <SPInterf.h>

#include <PIActionsPlugin.h>
#include <PIUtilities.h>

#include <Windows.h>
#include <string.h>
#include <assert.h>

#include <DialogUtilitiesWin.cpp>
#include <PIDLLInstance.cpp>
#include <PIUSuites.cpp>
#include <PIUtilities.cpp>
#include <PIUtilitiesWin.cpp>
#include <PIWinUI.cpp>


#define WIN32_MAX_CLASS_NAME_LENGTH 256

SPBasicSuite *sSPBasic = NULL;
HWND globalPSMainWindowHwnd = NULL;


BOOL CALLBACK getPSMainWindowCB(HWND hwnd, LPARAM lParam)
{
	char windowClassName[WIN32_MAX_CLASS_NAME_LENGTH];
	GetClassNameA(hwnd, (LPSTR)windowClassName, WIN32_MAX_CLASS_NAME_LENGTH);

	if (strncmp(windowClassName, "Photoshop", WIN32_MAX_CLASS_NAME_LENGTH) == 0) {
		globalPSMainWindowHwnd = hwnd;
	}

	return TRUE;
}


SPErr ExecuteCB(void *params)
{
	SPErr stat = kSPNoError;
	Auto_Desc descriptor;
	Auto_Desc result(false);

	DescriptorTypeID workFilterEventID;
	DescriptorEnumID workFilterEnumID = TUTORIAL_FILTER_ENUMINFO;
	DescriptorEnumTypeID workFilterTypeID;

	sPSActionDescriptor->PutEnumerated(descriptor.get(),
									   TUTORIAL_FILTER_KEYTRIGGER,
									   TUTORIAL_FILTER_TYPETRIGGER,
									   0);

	sPSActionControl->StringIDToTypeID(TUTORIAL_FILTER_UUID,
									   &workFilterEventID);

	sPSActionControl->Play(&result,
						   workFilterEventID,
						   descriptor.get(),
						   plugInDialogSilent);

	if (result.get() != NULL) {
		sPSActionDescriptor->GetEnumerated(result.get(),
										   TUTORIAL_FILTER_KEYRESULT,
										   &workFilterTypeID,
										   &workFilterEnumID);
	} else {
		BOOL status = EnumWindows(getPSMainWindowCB, (LPARAM)NULL);
		assert(status != 0);
		MessageBoxA(globalPSMainWindowHwnd, "Error occurred!", "Error", MB_OK|MB_ICONERROR);

		return stat;
	}

	// TODO: (sonictk) If you'd like to do things like check if the filter successfully
	// executed, what you can do is write a temporary file to disk _before_ calling the
	// filter, then deleting the temporary file within the filter, and then checking for it
	// here after the filter has finished execution. Basically, treat the two plug-ins as
	// two separate DLLs with their own memory allocated within the process, so any form
	// of communication between the two plug-ins that works within that restriction will do.

	return stat;
}


SPErr MenuExecuteCB()
{
	SPErr status = kSPNoError;

	// NOTE: (sonictk) Do this in order to suspend the history and improve performance.
	// This will allow only one entry to show up in the History palette of the UI. Also,
	// it will allow the history item to show up as the automation plugin, rather than
	// the filter plugin which is what was _actually_ executing.
	Auto_Ref reference;
	ASZString nameAsZString = NULL;
	sPSUIHooks->GetPluginName(message->d.self, &nameAsZString);
	sPSActionReference->PutEnumerated(reference.get(),
									  classDocument,
									  typeOrdinal,
									  enumTarget);

	sPSActionControl->SuspendHistory(reference.get(),
									 ::ExecuteCB,
									 NULL,
									 nameAsZString);
	sASZString->Release(nameAsZString);

	return gError;
}


SPErr UninitializePlugin()
{
	PIUSuitesRelease();
	return kSPNoError;
}


DLLExport SPAPI SPErr AutoPluginMain(const char* caller,
									 const char* selector,
									 void* message)
{
	SPErr status = kSPNoError;

	SPMessageData *basicMessage = (SPMessageData *)message;

	sSPBasic = basicMessage->basic;

	if (sSPBasic->IsEqual(caller, kSPInterfaceCaller)) {
		if (sSPBasic->IsEqual(selector, kSPInterfaceAboutSelector)) {
			DoAbout(basicMessage->self, AboutID);
		}

		if (sSPBasic->IsEqual(selector, kSPInterfaceStartupSelector)) {
			return kSPNoError;
		}

		if (sSPBasic->IsEqual(selector, kSPInterfaceShutdownSelector)) {
			status = UninitializePlugin();
		}
	}

	if (sSPBasic->IsEqual(caller, kPSPhotoshopCaller)) {
		if (sSPBasic->IsEqual(selector, kPSDoIt)) {
			PSActionsPlugInMessage *tmpMsg = (PSActionsPlugInMessage *)message;
			status = MenuExecuteCB();
		}
	}

	return status;
}
