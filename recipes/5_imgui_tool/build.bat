@echo off
setlocal

echo Build script started executing at %time% ...
set BuildType=%1
if "%BuildType%"=="" (set BuildType=release)

set PhotoshopSDKRoot=C:\Users\sonictk\src\thirdparty\adobe\photoshop\cc_2019_win\pluginsdk
set CnvtPiPLExePath="%PhotoshopSDKRoot%\samplecode\resources\Cnvtpipl.exe"
set PhotoshopPluginsDeployPath=C:\Users\sonictk\psplugins

call "%vs2017installdir%\VC\Auxiliary\Build\vcvarsall.bat" x64

set BuildDir=%~dp0msbuild
if not exist %BuildDir% mkdir %BuildDir%
pushd %BuildDir%

set ProjectName=tutorial_imgui

set AutoEntryPoint=%~dp0src\%ProjectName%_auto_main.cpp
set AutoResourcePiPL=%~dp0src\%ProjectName%_auto_pipl.r
set AutoResourceRC=%BuildDir%\%ProjectName%_auto_pipl.rc
set AutoResourceRES=%BuildDir%\%ProjectName%_auto_pipl.res

set FilterEntryPoint=%~dp0src\%ProjectName%_filter_main.cpp
set FilterResourcePiPL=%~dp0src\%ProjectName%_filter_pipl.r
set FilterResourceRC=%BuildDir%\%ProjectName%_filter_pipl.rc
set FilterResourceRES=%BuildDir%\%ProjectName%filter__pipl.res

set ThirdPartyDirPath=%~dp0..\thirdparty

set AutoOutBin=%BuildDir%\%ProjectName%_auto.8li
set FilterOutBin=%BuildDir%\%ProjectName%_filter.8bf

set CommonLinkerFlags=/dll /incremental:no /machine:x64 /nologo /defaultlib:Kernel32.lib /defaultlib:User32.lib /defaultlib:Shell32.lib /nodefaultlib:LIBCMTD.lib /nodefaultlib:LIBCMT.lib
set DebugLinkerFlags=%CommonLinkerFlags% /opt:noref /debug
set ReleaseLinkerFlags=%CommonLinkerFlags% /opt:ref
set RelWithDebInfoLinkerFlags=%CommonLinkerFlags% /opt:ref /debug

set FilterCommonLinkerFlags=/dll /incremental:no /machine:x64 /nologo /defaultlib:Kernel32.lib /defaultlib:Shlwapi.lib /defaultlib:User32.lib /defaultlib:Shell32.lib /defaultlib:Ole32.lib /defaultlib:Comctl32.lib /nodefaultlib:LIBCMTD.lib /nodefaultlib:LIBCMT.lib
set FilterDebugLinkerFlags=%FilterCommonLinkerFlags% /opt:noref /debug /pdb:"%BuildDir%\%ProjectName%_filter.pdb" "%FilterResourceRES%"
set FilterReleaseLinkerFlags=%FilterCommonLinkerFlags% /opt:ref "%FilterResourceRES%"
set FilterRelWithDebInfoLinkerFlags=%FilterCommonLinkerFlags% /opt:ref /debug /pdb:"%BuildDir%\%FilterProjectName%.pdb" "%FilterResourceRES%"

set PSPreprocessorDefines=/DISOLATION_AWARE_ENABLED=1 /DWIN32=1 /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_WINDOWS /D_USRDLL /D_WINDLL /D_MBCS
set PSCompilerFlags=/EHsc
set CommonIncludePaths=/I "%ThirdPartyDirPath%" /I "%ThirdPartyDirPath%\psapi\common\includes" /I "%ThirdPartyDirPath%\psapi\common\resources" /I "%ThirdPartyDirPath%\psapi\common\sources" /I "%ThirdPartyDirPath%\psapi\photoshop" /I "%ThirdPartyDirPath%\psapi\pica_sp" /I "%ThirdPartyDirPath%\psapi\resources" /I "%ThirdPartyDirPath%\psapi\ai" /I "%ThirdPartyDirPath%\imgui" /I "%ThirdPartyDirPath%\imgui\examples" /I "%BuildDir%"
set CommonCompilerFlags=/nologo /W3 /WX %CommonIncludePaths% /Zc:__cplusplus /arch:AVX2 %PSCompilerFlags% %PSPreprocessorDefines%
set CompilerFlagsDebug=%CommonCompilerFlags% /Od /Zi /D_DEBUG /MDd
set CompilerFlagsRelease=%CommonCompilerFlags% /Ox /DNDEBUG /MD
set CompilerFlagsRelWithDebInfo=%CommonCompilerFlags% /Ox /Zi /DNDEBUG /MD

set AutoLinkerFlagsDebug=%DebugLinkerFlags% /pdb:"%BuildDir%\%ProjectName%_auto.pdb" "%AutoResourceRES%"
set AutoLinkerFlagsRelease=%ReleaseLinkerFlags% "%AutoResourceRES%"
set AutoLinkerFlagsRelWithDebinfo=%RelWithDebInfoLinkerFlags% /pdb:"%BuildDir%\%ProjectName%_auto.pdb" "%AutoResourceRES%"


if "%BuildType%"=="debug" (
    set AutoBuildCommand=cl %CompilerFlagsDebug% "%AutoEntryPoint%" /Fe:"%AutoOutBin%" /link %AutoLinkerFlagsDebug%
    set AutoBuildRRCommand=cl %CompilerFlagsDebug% /EP /DMSWindows=1 /Tc "%AutoResourcePiPL%"

    set FilterBuildCommand=cl %CompilerFlagsDebug% "%FilterEntryPoint%" /Fe:"%FilterOutBin%" /link %FilterDebugLinkerFlags%
    set FilterBuildRRCommand=cl %CompilerFlagsDebug% /EP /DMSWindows=1 /Tc "%FilterResourcePiPL%"
) else if "%BuildType%"=="relwithdebinfo" (
    set AutoBuildCommand=cl %CompilerFlagsRelWithDebInfo% "%AutoEntryPoint%" /Fe:"%AutoOutBin%" /link %AutoLinkerFlagsRelWithDebInfo%
    set AutoBuildRRCommand=cl %CompilerFlagsRelWithDebInfo% /EP /DMSWindows=1 /Tc "%AutoResourcePiPL%"

    set FilterBuildCommand=cl %CompilerFlagsRelWithDebInfo% "%FilterEntryPoint%" /Fe:"%FilterOutBin%" /link %FilterRelWithDebInfoLinkerFlags%
    set FilterBuildRRCommand=cl %CompilerFlagsRelWithDebInfo% /EP /DMSWindows=1 /Tc "%FilterResourcePiPL%"
) else (
    set AutoBuildCommand=cl %CompilerFlagsRelease% "%AutoEntryPoint%" /Fe:"%AutoOutBin%" /link %AutoLinkerFlagsRelease%
    set AutoBuildRRCommand=cl %CompilerFlagsRelease% /EP /DMSWindows=1 /Tc "%AutoResourcePiPL%"

    set FilterBuildCommand=cl %CompilerFlagsRelease% "%FilterEntryPoint%" /Fe:"%FilterOutBin%" /link %FilterReleaseLinkerFlags%
    set FilterBuildRRCommand=cl %CompilerFlagsRelease% /EP /DMSWindows=1 /Tc "%FilterResourcePiPL%"
)


echo.
echo Compiling resources (command follows below)...
set AutoResourceRR=%BuildDir%\%ProjectName%_auto_pipl.rr
set FilterResourceRR=%BuildDir%\%ProjectName%_filter_pipl.rr


echo %AutoBuildRRCommand%
%AutoBuildRRCommand% > "%AutoResourceRR%"
if %errorlevel% neq 0 goto error

echo %FilterBuildRRCommand%
%FilterBuildRRCommand% > "%FilterResourceRR%"
if %errorlevel% neq 0 goto error

echo.
echo Converting Automation PiPL to Windows resource file format...
echo %CnvtPiPLExePath% "%AutoResourceRR%" "%AutoResourceRC%"
%CnvtPiPLExePath% "%AutoResourceRR%" "%AutoResourceRC%"
if %errorlevel% neq 0 goto error

echo.
echo Converting Filter PiPL to Windows resource file format...
echo %CnvtPiPLExePath% "%FilterResourceRR%" "%FilterResourceRC%"
%CnvtPiPLExePath% "%FilterResourceRR%" "%FilterResourceRC%"
if %errorlevel% neq 0 goto error

echo.
echo Compiling Windows Resources for automation plug-in...
rc /v /fo "%AutoResourceRES%" "%AutoResourceRC%"
if %errorlevel% neq 0 goto error

echo.
echo Compiling Windows Resources for filter plug-in...
rc /v /fo "%FilterResourceRES%" "%FilterResourceRC%"
if %errorlevel% neq 0 goto error


echo.
echo Compiling source files for automation plug-in (command follows below)...
echo %AutoBuildCommand%
echo.
echo Output from compilation:
%AutoBuildCommand%
if %errorlevel% neq 0 goto error

echo.
echo Compiling source files for filter plug-in (command follows below)...
echo %FilterBuildCommand%
echo.
echo Output from compilation:
%FilterBuildCommand%
if %errorlevel% neq 0 goto error


echo.
echo Deploying built binaries and symbols...
copy /Y "%AutoOutBin%"  "%PhotoshopPluginsDeployPath%"
if %errorlevel% neq 0 goto error

echo.
echo Deploying built binaries and symbols...
copy /Y "%FilterOutBin%"  "%PhotoshopPluginsDeployPath%"
if %errorlevel% neq 0 goto error

if "%BuildType%"=="debug" (
    copy /Y "%BuildDir%\%ProjectName%_auto.pdb" "%PhotoshopPluginsDeployPath%"
    if %errorlevel% neq 0 goto error

    copy /Y "%BuildDir%\%ProjectName%_filter.pdb" "%PhotoshopPluginsDeployPath%"
    if %errorlevel% neq 0 goto error
)

if %errorlevel% == 0 goto success


:error
echo.
echo ***************************************
echo *      !!! An error occurred!!!       *
echo ***************************************
goto end


:success
echo.
echo ***************************************
echo *    Build completed successfully.    *
echo ***************************************
goto end


:end
echo.
echo Build script finished execution at %time%.
popd

endlocal

exit /b %errorlevel%
