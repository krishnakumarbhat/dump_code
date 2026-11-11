@echo off
REM ============================================================================
REM AUTOSAR Module Generation Script
REM
REM This batch file generates specific AUTOSAR BSW/MCAL modules.
REM The generate_autosar.py script automatically handles:
REM   1. SIP generator check/download (if needed)
REM   2. MCAL package copy via repo_copy.py
REM   3. AUTOSAR code generation using DVCfgCmd.exe
REM ============================================================================

echo ============================================================================
echo AUTOSAR Module Generation Workflow
echo ============================================================================
echo Modules: Dio I2c Port Adc Gpt Mcu Spi Pwm Eth Fls Can Uart Dma
echo.

python generate_autosar.py --modules Dio I2c Port Adc Gpt Mcu Spi Pwm Eth Fls Can Uart Dma

echo.
echo ============================================================================
echo Generation Complete
echo ============================================================================
pause
