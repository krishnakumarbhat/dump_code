@echo off
:: ============================================================
::  Radar Test Launcher  –  SQTS Automation Framework
::  Works with GEN8, GEN7_V2 and any future generation.
::  All options chosen interactively — no batch file editing needed.
:: ============================================================
setlocal

:: Force UTF-8 console so all symbols render correctly
chcp 65001 > nul
set PYTHONIOENCODING=utf-8

set FRAMEWORK_DIR=%~dp0Core_Radar_Python_Framework
set VENV_DIR=%FRAMEWORK_DIR%\installation\venv
set LAUNCHER=%FRAMEWORK_DIR%\src\launcher.py

set PYTHONWARNINGS=ignore::DeprecationWarning
set PYTHONDONTWRITEBYTECODE=1

call "%VENV_DIR%\Scripts\activate.bat"

cd /d "%FRAMEWORK_DIR%"
python -W ignore::DeprecationWarning "%LAUNCHER%"
set EXIT_CODE=%ERRORLEVEL%

call "%VENV_DIR%\Scripts\deactivate.bat"

exit /B %EXIT_CODE%
