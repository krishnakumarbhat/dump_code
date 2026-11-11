@REM File: Post_OS_Gen.bat
@REM author: Mounir Karmada
@REM version  1.0.0
@REM description: This is a post-generation script to rename the generated .asm files to GNU compatible .S
@REM              This script is to be obsolete if/when Vector changes their generated assembly files extension

@echo off

@REM Change directory to Generated folder
cd %~dp0\..\Appl\GenData

@REM  Check if there is a newly generated asm file
IF EXIST "Os_Hal_EntryAsm_Lcfg.asm" (
   @REM Delete older .S files - Generation does not remove older files
   DEL *.S
   @REM Rename all files with .asm extension to .S
   ren *.asm *.S
) ELSE (
   @REM Do nothing
   ECHO "No asm files found"
)

@REM Return to this script's directory in case the generation is done again on the same window
cd %~dp0

python Post_Gen_BSW_RTE_Mods.py
