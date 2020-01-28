#ifndef SystemSevenOrLater
#define SystemSevenOrLater	1
#endif

#define BUILDING_FOR_MACH 1

#define Macintosh 1
#define MAC 1
#define MSWindows 0
#define qMipStuff 0

#define TARGET_CARBON 1

#ifndef TARGET_API_MAC_CARBON
#define TARGET_API_MAC_CARBON 1
#endif

#ifndef TARGET_MAC_OS_MACH
#define TARGET_MAC_OS_MACH 1
#endif

#ifndef TARGET_MAC_OS
#define TARGET_MAC_OS 1
#endif

#ifndef qLimited6
#define qLimited6	0
#endif

#include <Carbon.r>

