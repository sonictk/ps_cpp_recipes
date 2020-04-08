#ifndef TUTORIAL_IMGUI_GUI_H
#define TUTORIAL_IMGUI_GUI_H

#include <stdint.h>

#define GUI_ACCEPT 1
#define GUI_REJECT 0

struct GUIResult
{
	char *exportPath;
	int8_t accepted;
	int width;
	int height;
	int jpgQuality;
};

#endif /* TUTORIAL_IMGUI_GUI_H */
