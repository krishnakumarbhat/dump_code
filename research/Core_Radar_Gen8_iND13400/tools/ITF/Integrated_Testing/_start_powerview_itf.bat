echo off
SET t32basepath="C:\T32"
SET t32path=%t32basepath%\bin\windows64
IF NOT EXIST %t32path%\t32marm.exe SET t32path=%t32basepath%\bin\windows
IF NOT EXIST %t32path%\t32marm.exe SET t32path=%t32basepath%
cd ..\..\..\lauterbach\
start "" %t32path%\t32marm -c config.t32
