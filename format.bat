@echo off
setlocal

set "BUILD_DIR=build"

where clang-format >nul 2>nul
if errorlevel 1 (
    echo clang-format not found in PATH.
    exit /b 1
)

set "COUNT=0"

for /r %%F in (*.c *.h) do (
    call :process "%%F"
)

echo Formatted %COUNT% file(s).
exit /b 0

:process
set "FILE=%~1"
echo %FILE% | findstr /i /c:"%BUILD_DIR%\" >nul
if not errorlevel 1 exit /b 0
clang-format -i -style=file "%FILE%"
set /a COUNT+=1
exit /b 0