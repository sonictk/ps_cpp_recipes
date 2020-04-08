#ifndef LIBPS_PLATFORM_H
#define LIBPS_PLATFORM_H

#ifdef _WIN32
#include "libps_platform_win32.h"
#else
#error MSG_UNSUPPORTED_PLATFORM
#endif // _WIN32


OSWindowHandle getPSMainWindow();


#endif /* LIBPS_PLATFORM_H */
