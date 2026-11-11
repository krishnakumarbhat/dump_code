@echo off
REM A-PRISM host verification: compile each landed module + assert harness with
REM host clang and run. Mirrors the Run 22-30 Python demo asserts in C.
REM Usage: run from the repo root: aprism_host_tests\run_host_tests.bat
setlocal
set FAIL=0
call :t appl_adaptive_cfar.c software/bbe32/rdd_proc/imp/src test_adaptive_cfar
call :t residual_track_ifc.c software/bbe32/src test_residual
call :t cdc_priority.c software/bbe32/src test_cdc_priority
call :t ghost_calib.c software/bbe32/dyn_alignment test_ghost_calib
call :t ghost_assoc_enabler.c software/bbe32/emb_tracker test_assoc_enabler
clang -std=c99 -Wall -Wextra -O1 -I software/bbe32/rdd_proc/imp/src -I software/bbe32/src -I software/bbe32/dyn_alignment software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.c software/bbe32/src/cdc_priority.c software/bbe32/dyn_alignment/ghost_calib.c aprism_host_tests/test_ab_compare.c -o aprism_host_tests/test_ab_compare.exe
if errorlevel 1 ( set /a FAIL+=1 & echo COMPILE-FAIL test_ab_compare )
aprism_host_tests\test_ab_compare.exe
if errorlevel 1 ( set /a FAIL+=1 & echo TEST-FAIL test_ab_compare )
echo RESULT: %FAIL% failures
exit /b %FAIL%

:t
set SRC=%1
set DIR=%2
set TST=%3
clang -std=c99 -Wall -Wextra -O1 -I %DIR% %DIR%/%SRC% aprism_host_tests/%TST%.c -o aprism_host_tests/%TST%.exe
if errorlevel 1 ( set /a FAIL+=1 & echo COMPILE-FAIL %TST% & goto :eof )
aprism_host_tests\%TST%.exe
if errorlevel 1 ( set /a FAIL+=1 & echo TEST-FAIL %TST% )
goto :eof
