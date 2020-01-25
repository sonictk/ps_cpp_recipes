SPBasicSuite *sSPBasic = NULL;


SPErr UninitializePlugin()
{
	PIUSuitesRelease();
	return status;
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
		}
	}

	return status;
}
