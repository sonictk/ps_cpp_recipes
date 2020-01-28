#include <Windows.h>
#include <string>
#include <cassert>


int getCurrentProcessFileName(char *filename, int size)
{
	DWORD resultDW = GetModuleFileNameA(NULL, (LPTSTR)filename, (DWORD)size);

	int result = (int)resultDW;

	return result;
}


std::string PSFindPlugPlugDLLFileName()
{
	char plugPlugOwlDLLFileName[SDKPLUGPLUG_MAX_PATH];
	int processFilePathLength = getCurrentProcessFileName(plugPlugOwlDLLFileName, SDKPLUGPLUG_MAX_PATH);

	assert(processFilePathLength > 0);

	std::string result = std::string(plugPlugOwlDLLFileName);

	size_t lastPathSepIdx = result.rfind("\\");
	result.erase(lastPathSepIdx + 1);

	result += SDKPLUGPLUG_OWL_DLL_FILENAME;

	return result;
}
