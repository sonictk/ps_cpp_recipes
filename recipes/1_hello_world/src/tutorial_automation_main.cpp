#include <SPBasic.h>
// #include <SPTypes.h>
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
            BOOL status = EnumWindows(getPSMainWindowCB, (LPARAM)NULL);
            assert(status != 0);
            MessageBoxA(globalPSMainWindowHwnd, "Hello World!", "Tutorial Dialog", MB_OK|MB_ICONINFORMATION);
		}
	}

	return status;
}
