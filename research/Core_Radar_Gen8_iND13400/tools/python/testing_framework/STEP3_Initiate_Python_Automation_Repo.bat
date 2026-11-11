@echo off
setlocal enabledelayedexpansion

echo.
echo =========================================================
echo      Targeted Initiation of the Python Framework Repo
echo =========================================================
echo.

set "ORIGINAL_DIR=%CD%"
set "CICD_MODE=false"

REM --- Parse arguments ---
for %%A in (%*) do (
    if /i "%%A"=="--CICD" set "CICD_MODE=true"
)

if !CICD_MODE! == true (
    echo [MODE] Running in CICD mode - full clean reinitialize
) else (
    echo [MODE] Running in interactive mode
)
echo.

REM --- Step 1: Get absolute paths and define variables ---
for /f "delims=" %%i in ('git rev-parse --show-toplevel') do set "MAIN_REPO_ROOT=%%i"
set "MAIN_REPO_ROOT=%MAIN_REPO_ROOT:/=\%"
set "SUBMODULE_DIR=%MAIN_REPO_ROOT%\tools\python\testing_framework\Core_Radar_Python_Framework"
set "LOCK_FILE=%MAIN_REPO_ROOT%\.git\modules\tools\python\testing_framework\Core_Radar_Python_Framework\index.lock"
set "GIT_MODULES_DIR=%MAIN_REPO_ROOT%\.git\modules\tools\python\testing_framework\Core_Radar_Python_Framework"

echo [INFO] Main repository root: %MAIN_REPO_ROOT%
echo [INFO] Expected submodule directory: %SUBMODULE_DIR%
echo -------------------------------------------------
echo.

REM --- Step 2: Navigate to the main repository root ---
echo [INFO] Changing directory to repository root...
cd /d "%MAIN_REPO_ROOT%" || (
    echo [ERROR] Failed to navigate to the repository root directory.
    goto failure
)
echo [SUCCESS] Now operating from the repository root.
echo -------------------------------------------------
echo.

REM --- Step 3: Find the exact submodule path from .gitmodules ---
echo [INFO] Querying .gitmodules for the correct submodule path...
set "SUBMODULE_PATH_FROM_GIT="
for /f "tokens=2" %%p in ('git config --file .gitmodules --get-regexp path ^| findstr "Core_Radar_Python_Framework"') do (
    set "SUBMODULE_PATH_FROM_GIT=%%p"
)

if not defined SUBMODULE_PATH_FROM_GIT (
    echo [ERROR] Could not find a submodule containing 'Core_Radar_Python_Framework' in the .gitmodules file.
    echo      Please ensure the submodule is correctly registered.
    goto failure
)

echo [SUCCESS] Found exact submodule path from Git: "%SUBMODULE_PATH_FROM_GIT%"
echo -------------------------------------------------
echo.

REM --- Step 3b: Resolve tracked branch from .gitmodules (host-agnostic) ---
REM   Reads `branch = <name>` declared in .gitmodules. Falls back to 'dev'.
REM   The submodule is hosted on GitHub Enterprise (aptv.ghe.com); the branch
REM   directive stays the single source of truth and `git submodule` commands
REM   resolve the host from the URL in .gitmodules.
set "SUBMODULE_BRANCH="
for /f "tokens=*" %%b in ('git config --file .gitmodules --get submodule."tools/python/Core_Radar_Python_Framework".branch 2^>nul') do (
    set "SUBMODULE_BRANCH=%%b"
)
if not defined SUBMODULE_BRANCH set "SUBMODULE_BRANCH=dev"
echo [INFO] Tracking submodule branch: !SUBMODULE_BRANCH!
echo -------------------------------------------------
echo.

REM --- Step 4: Clean up stale lock file ---
if exist "%LOCK_FILE%" (
    echo [INFO] A stale lock file was found. Removing it...
    del /f /q "%LOCK_FILE%" || (
        echo [ERROR] Failed to delete the lock file. Please remove it manually.
        goto failure
    )
    echo [SUCCESS] Stale lock file removed.
    echo -------------------------------------------------
    echo.
)

REM --- Step 5: CICD mode - nuke and reinitialize from scratch ---
if !CICD_MODE! == true (
    echo [INFO] CICD mode: Deinitializing and removing submodule completely...

    git submodule deinit -f -- "%SUBMODULE_PATH_FROM_GIT%" >nul 2>&1

    if exist "%SUBMODULE_DIR%" (
        echo [INFO] Removing submodule working directory...
        rmdir /s /q "%SUBMODULE_DIR%" >nul 2>&1
    )

    if exist "%GIT_MODULES_DIR%" (
        echo [INFO] Removing cached submodule git data...
        rmdir /s /q "%GIT_MODULES_DIR%" >nul 2>&1
    )

    echo [SUCCESS] Submodule fully removed. Reinitializing fresh...
    echo -------------------------------------------------
    echo.
    goto :do_submodule_update
)

REM --- Step 5b: Normal mode - pre-clean local changes in submodule before update ---
if exist "%SUBMODULE_DIR%\.git" (
    echo [INFO] Submodule directory exists. Cleaning local changes before update...
    pushd "%SUBMODULE_DIR%"

    REM Safety check: confirm we are inside the submodule
    for /f "delims=" %%i in ('git rev-parse --show-toplevel') do set "CHECK_ROOT=%%i"
    set "CHECK_ROOT=!CHECK_ROOT:/=\!"
    set "EXPECTED_DIR=%SUBMODULE_DIR%"
    if /i "!CHECK_ROOT!"=="!EXPECTED_DIR!" (
        git reset --hard >nul 2>&1
        git clean -fdx >nul 2>&1
        echo [SUCCESS] Submodule local changes cleared.
    ) else (
        echo [WARNING] Safety check: unexpected git root, skipping pre-clean.
    )

    popd
    echo -------------------------------------------------
    echo.
) else if exist "%SUBMODULE_DIR%" (
    REM Directory exists but is not a valid git repo - remove it
    echo [INFO] Submodule directory exists but is not a valid git repo. Removing...
    rmdir /s /q "%SUBMODULE_DIR%" >nul 2>&1
    echo [SUCCESS] Cleaned up invalid submodule directory.
    echo -------------------------------------------------
    echo.
)

REM --- Step 6: Initialize and update the target submodule ---
:do_submodule_update
echo [INFO] Initializing and updating the target submodule (tracking branch tip)...
git submodule sync -- "%SUBMODULE_PATH_FROM_GIT%" >nul || (
    echo [ERROR] Failed to synchronize the submodule.
    goto failure
)

REM Section name in .gitmodules does not match the checkout path, so match on the repo name.
set "SUBMODULE_URL="
for /f "tokens=2" %%u in ('git config --file .gitmodules --get-regexp url ^| findstr "Core_Radar_Python_Framework"') do (
    set "SUBMODULE_URL=%%u"
)

if not defined SUBMODULE_URL (
    echo [ERROR] Unable to obtain submodule URL from .gitmodules.
    goto failure
)

echo [INFO] Expected submodule URL:
echo        !SUBMODULE_URL!

REM `--remote` makes git fetch the tip of the branch declared in .gitmodules
REM (resolved above as !SUBMODULE_BRANCH!) rather than the SHA recorded in the
REM main repo's index. Combined with Step 9's hard reset this guarantees the
REM submodule is always at origin/!SUBMODULE_BRANCH!, regardless of stale pins.
git submodule update --init --remote --force "%SUBMODULE_PATH_FROM_GIT%" >nul || (
    echo [ERROR] Failed to update submodule.
    goto failure
)

REM Existing clones keep the old origin after a host migration, so overwrite it.
if exist "%SUBMODULE_DIR%" (
    echo [INFO] Synchronizing submodule remote URL...
    git -C "%SUBMODULE_DIR%" remote set-url origin "!SUBMODULE_URL!" >nul 2>&1 || (
        echo [ERROR] Failed to update submodule origin URL.
        goto failure
    )
    echo [INFO] Active submodule remote:
    git -C "%SUBMODULE_DIR%" remote -v
)

echo [SUCCESS] Target submodule is initialized and updated.
echo -------------------------------------------------
echo.

REM --- Step 7: Navigate into submodule directory for final setup ---
if not exist "%SUBMODULE_DIR%" (
    echo [ERROR] Submodule directory does not exist: %SUBMODULE_DIR%
    goto failure
)
cd /d "%SUBMODULE_DIR%"

REM --- Step 8: Safety check ---
for /f "delims=" %%i in ('git rev-parse --show-toplevel') do set "CURRENT_REPO_ROOT=%%i"
set "CURRENT_REPO_ROOT=!CURRENT_REPO_ROOT:/=\!"
if /i not "!CURRENT_REPO_ROOT!"=="%SUBMODULE_DIR%" (
    echo [FATAL ERROR] Safety check failed! Operating in wrong directory.
    echo   Expected: %SUBMODULE_DIR%
    echo   Actual:   !CURRENT_REPO_ROOT!
    goto failure
)

REM --- Step 9: Ensure submodule is on the tracked branch tip ---
echo [INFO] Ensuring submodule is on the latest '!SUBMODULE_BRANCH!' branch...

echo [INFO] Current remote configuration:
git remote -v

git fetch origin >nul 2>&1 || (
    echo [ERROR] Failed to fetch from origin.
    goto failure
)

git checkout -f !SUBMODULE_BRANCH! >nul 2>&1 || (
    echo [ERROR] Failed to checkout branch !SUBMODULE_BRANCH!.
    goto failure
)

git reset --hard origin/!SUBMODULE_BRANCH! >nul || ( echo [ERROR] Failed to reset submodule. & goto failure )
git clean -fdx >nul || ( echo [ERROR] Failed to clean submodule directory. & goto failure )
echo [SUCCESS] Submodule is up-to-date with the latest '!SUBMODULE_BRANCH!' branch.

echo -------------------------------------------------
echo.
goto end

:failure
echo.
echo [FAILURE] The script encountered an error and could not complete.
echo -------------------------------------------------
echo.
cd /d "%ORIGINAL_DIR%"
if /i "!CICD_MODE!"=="false" pause
exit /b 1

:end
cd /d "%ORIGINAL_DIR%"
echo =========================================================
echo      Submodule update process finished successfully.
echo =========================================================
echo.
if /i "!CICD_MODE!"=="false" pause
endlocal
