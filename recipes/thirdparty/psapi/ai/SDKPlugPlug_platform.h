/**
 * @file   SDKPlugPlug_platform.h
 * @brief  Additional platform-related functionality for the modified Adobe Illustrator SDK.
 */
#ifndef SDKPLUGPLUG_PLATFORM_H
#define SDKPLUGPLUG_PLATFORM_H

#ifdef _WIN32
#include "SDKPlugPlug_win32.cpp"
#else
#error "Only Windows is supported for compilation with this modified Adobe Illustrator SDK at this time."
#endif // OS Layer


/**
 * Returns the full file path to the Photoshop PlugPlugOwl DLL for the given Photoshop process.
 *
 * @return    The full file path to the DLL.
 */
std::string PSFindPlugPlugDLLFileName();


#endif /* SDKPLUGPLUG_PLATFORM_H */
