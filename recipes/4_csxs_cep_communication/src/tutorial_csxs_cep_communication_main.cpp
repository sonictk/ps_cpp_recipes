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

#include <SDKPlugPlug.cpp>

#include "tutorial_csxs_cep_communication_globals.h"
#include "libcsxs.cpp"


#define WIN32_MAX_CLASS_NAME_LENGTH 256

SPBasicSuite *sSPBasic = NULL;

static HWND globalPSMainWindowHwnd = NULL;
static SDKPlugPlug *globalSDKPlugPlug = NULL;
static bool globalEventListenerRegistered = false;


BOOL CALLBACK getPSMainWindowCB(HWND hwnd, LPARAM lParam)
{
	char windowClassName[WIN32_MAX_CLASS_NAME_LENGTH];
	GetClassNameA(hwnd, (LPSTR)windowClassName, WIN32_MAX_CLASS_NAME_LENGTH);

	if (strncmp(windowClassName, "Photoshop", WIN32_MAX_CLASS_NAME_LENGTH) == 0) {
		globalPSMainWindowHwnd = hwnd;
	}

	return TRUE;
}


void CSXSEventExportLayersCB(const csxs::event::Event *const event, void *const context)
{
	BOOL status = EnumWindows(getPSMainWindowCB, (LPARAM)NULL);
	assert(status != 0);
	MessageBoxA(globalPSMainWindowHwnd, "Hello World from CEP!", "Tutorial Dialog", MB_OK|MB_ICONINFORMATION);

	return;
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
		else if (sSPBasic->IsEqual(selector, kSPInterfaceStartupSelector)) {
			return kSPNoError;
		}
		else if (sSPBasic->IsEqual(selector, kSPInterfaceShutdownSelector)) {
			status = UninitializePlugin();
		}
	}

	else if (sSPBasic->IsEqual(caller, kPSPhotoshopCaller)) {
		if (sSPBasic->IsEqual(selector, kPSDoIt)) {
			PSActionsPlugInMessage *tmpMsg = (PSActionsPlugInMessage *)message;

			if (!globalSDKPlugPlug) {
				globalSDKPlugPlug = new SDKPlugPlug;
				status = globalSDKPlugPlug->Load();
				if (status != kSPNoError) {
					delete globalSDKPlugPlug;
					return status;
				}
			}

			if (!globalEventListenerRegistered) {
				csxs::event::EventErrorCode csxsStat;
				csxsStat = globalSDKPlugPlug->AddEventListener(EXPORT_LAYERS_CSXS_EVENT_ID,
															   CSXSEventExportLayersCB,
															   NULL);
				if (csxsStat != csxs::event::EventErrorCode::kEventErrorCode_Success) {
					return kSPLogicError;
				}

				globalEventListenerRegistered = true;
			}
		}
	}

	return status;
}
