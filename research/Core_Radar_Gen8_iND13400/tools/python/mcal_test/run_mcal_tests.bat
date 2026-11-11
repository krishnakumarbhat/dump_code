@echo off
REM ============================================================================
REM MCAL Test Automation Batch Script
REM ============================================================================
REM This script runs the MCAL test automation with configuration from INI file
REM ============================================================================

setlocal

echo.
echo ============================================================================
echo MCAL Test Automation
echo ============================================================================
echo.

REM Set the repository root (batch file is now in tools/python/mcal_test/)
set REPO_ROOT=%~dp0..\..\..
cd /d "%REPO_ROOT%"

echo Repository Root: %CD%
echo.

REM Set paths (files are now in mcal_test subfolder)
set CONFIG_FILE=tools\python\mcal_test\mcal_test_config.ini
set PYTHON_SCRIPT=tools\python\mcal_test\mcal_test_automation.py

REM Check if config file exists
if not exist "%CONFIG_FILE%" (
    echo ERROR: Configuration file not found: %CONFIG_FILE%
    echo.
    echo Please create the configuration file with your paths.
    echo Example: tools\python\mcal_test\mcal_test_config.ini
    pause
    exit /b 1
)

echo Configuration File: %CONFIG_FILE%
echo Python Script: %PYTHON_SCRIPT%
echo.

REM Run the Python script with config file
echo Starting MCAL test automation...
echo.
python "%PYTHON_SCRIPT%" --config "%CONFIG_FILE%"

REM Check exit code
if %ERRORLEVEL% EQU 0 (
    echo.
    echo ============================================================================
    echo MCAL Test Automation COMPLETED SUCCESSFULLY
    echo ============================================================================
    echo.
) else (
    echo.
    echo ============================================================================
    echo MCAL Test Automation FAILED
    echo ============================================================================
    echo.
    pause
    exit /b %ERRORLEVEL%
)

pause
