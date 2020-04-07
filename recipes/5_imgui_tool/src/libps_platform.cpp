#include "libps_platform.h"

#ifdef _WIN32
#include "libps_platform_win32.cpp"
#else
#error MSG_UNSUPPORTED_PLATFORM
#endif
