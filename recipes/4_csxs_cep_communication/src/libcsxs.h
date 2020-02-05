#ifndef LIBCSXS_H
#define LIBCSXS_H

#include <SDKPlugPlug.h>


#define CSXS_PHOTOSHOP_APPID "PHXS"


csxs::event::EventErrorCode dispatchCSXSLogEvent(SDKPlugPlug *plugPlugObj, const char *msg, const char *eventType, const char *extensionID);


#endif /* LIBCSXS_H */
