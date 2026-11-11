@echo off
setlocal enabledelayedexpansion
rem Start PowerView for R52 + BBE32 with XT paths resolved from Bazel

pushd "%~dp0\..\.."
set "target=bazel-core_radar_gen8_ind13400"
set "bazel_root="
for /f "delims=" %%D in ('dir /s /b /ad "%target%" 2^>nul') do (
  set "bazel_root=%%~fD"
  rem Strip any ".git\" or ".git" segments from the path
  set "bazel_root=!bazel_root:.git\=!"
  set "bazel_root=!bazel_root:.git=!"
  goto :done
)
popd

:done
if defined bazel_root (
  echo bazel_root: %bazel_root%
) else (
  echo Not found
)

    set "XtCoreLibPath=%bazel_root%external\bbe_windows_luna~\RJ-2025.5-win32\bbe32_luna\config\"
    set "XtToolLibPath=%bazel_root%external\bbe_windows~\tools\RJ-2025.5-win32\XtensaTools\lib\"

echo %XtCoreLibPath%
echo %XtToolLibPath%

rem Start t32marm with extra args when present
start "" /D %~dp0 C:\T32\bin\windows64\t32marm -c config.t32 -s start_powerview.cmm CPU=ind13400 R52 BBE32 USER_CONFIG=default_user_config.cmm XtCoreLibPath="%XtCoreLibPath%" XtToolLibPath="%XtToolLibPath%"
