#include "libcsxs.h"


csxs::event::EventErrorCode dispatchCSXSLogEvent(SDKPlugPlug *plugPlugObj, const char *msg, const char *eventType, const char *extensionID)
{
	csxs::event::EventErrorCode csxsStat;

	csxs::event::Event logEvent;
	logEvent.type = eventType;
	logEvent.scope = csxs::event::kEventScope_Application;
	logEvent.appId = CSXS_PHOTOSHOP_APPID;
	logEvent.extensionId = extensionID;
	logEvent.data = msg;

	csxsStat = plugPlugObj->DispatchEvent(&logEvent);

	return csxsStat;
}
