@echo off
rem setlocal only set var in local script
rem setlocal
set "OverallExitCode=0"

set Arguments=-arch=amd64 -host_arch=amd64
rem Add one quoted path per entry. Paths may contain spaces.
for %%F in (
    "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"
    "E:\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"
) do call :RunIfExists "%%~F"

exit /b %OverallExitCode%

:RunIfExists
set "Target=%~1"

if not exist "%Target%" (
    echo [SKIP] Not found: "%Target%"
    exit /b 0
)

if /i not "%~x1"==".bat" (
    echo [SKIP] Not a .bat file: "%Target%"
    exit /b 0
)

echo [RUN ] "%Target%"
call "%Target%" %Arguments%
set "ExitCode=%errorlevel%"

if not "%ExitCode%"=="0" (
    echo [FAIL] "%Target%" returned %ExitCode%.
    if %ExitCode% GTR %OverallExitCode% set "OverallExitCode=%ExitCode%"
    exit /b %ExitCode%
)

echo [ OK ] "%Target%"
exit /b 0
