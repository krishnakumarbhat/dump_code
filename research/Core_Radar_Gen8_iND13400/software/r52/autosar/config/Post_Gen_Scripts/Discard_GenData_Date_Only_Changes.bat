@REM File:        Discard_GenData_Date_Only_Changes.bat
@REM Description: Reverts DaVinci GenData files whose only change from HEAD is a
@REM              date/timestamp line. Files with any other content change are kept
@REM              in full. Delegates all logic to the companion Python script.

@echo off

cd /d %~dp0
python discard_gendata_date_only_changes.py
