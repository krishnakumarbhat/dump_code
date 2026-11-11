@echo off
for /f %%i in ('git rev-parse HEAD') do set VAR=%%i
echo STABLE_BUILD_SCM_REVISION %VAR%

git diff --quiet
IF %errorlevel%==0 (
    echo STABLE_BUILD_SCM_STATUS clean
) ELSE (
    echo STABLE_BUILD_SCM_STATUS dirty
)
