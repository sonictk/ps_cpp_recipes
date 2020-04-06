struct GUIResult
{
	int width;
	int height;
	int jpgQuality;
	char *exportPath;
};

#ifdef _WIN32
#include "tutorial_imgui_gui_win32_d3d11.cpp"
#else
#error "Unsupported platform for compilation."
#endif // _WIN32
