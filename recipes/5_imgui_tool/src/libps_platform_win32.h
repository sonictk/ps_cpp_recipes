#ifndef LIBPS_PLATFORM_WIN32_H
#define LIBPS_PLATFORM_WIN32_H


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#define OS_PATH_SEP '\\'
#define PS_MAX_PATH MAX_PATH

#define WIN32_MAX_CLASS_NAME_LENGTH 256
#define WIN32_ENV_VAR_MAX_LEN 32767

typedef HWND OSWindowHandle;
typedef HINSTANCE OSInstHandle;
typedef HANDLE OSFileHandle;


#endif /* LIBPS_PLATFORM_WIN32_H */
