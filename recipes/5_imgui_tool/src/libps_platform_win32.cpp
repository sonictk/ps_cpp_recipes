static HWND globalPSMainWindowHwnd = NULL;
static const char GLOBAL_PS_WIN32_WINDOW_CLASS_NAME[] = "Photoshop";

BOOL CALLBACK getPSMainWindowCB(HWND hwnd, LPARAM)
{
	char windowClassName[WIN32_MAX_CLASS_NAME_LENGTH];
	GetClassNameA(hwnd, (LPSTR)windowClassName, WIN32_MAX_CLASS_NAME_LENGTH);

	// NOTE: (yliangsiew) This is a horrific way to get the Photoshop main window, but
	// as of present there don't seem to be any better alternatives; Adobe doesn't seem to store
	// the window handle in the API, and attempting to use handles from application startup
	// is unreliable at best since there seem to be several cases that result in destroyed
	// and re-created window handles.
	if (strncmp(windowClassName, GLOBAL_PS_WIN32_WINDOW_CLASS_NAME, WIN32_MAX_CLASS_NAME_LENGTH) == 0) {
		globalPSMainWindowHwnd = hwnd;
	}

	return TRUE;
}

OSWindowHandle getPSMainWindow()
{
	BOOL status = EnumWindows(getPSMainWindowCB, (LPARAM)NULL);
	if (status == 0) {
		globalPSMainWindowHwnd = NULL;
	}

	return globalPSMainWindowHwnd;
}
