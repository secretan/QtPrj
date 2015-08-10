@echo off
REM set PATH=%PATH%;C:\MinGW\bin
set PATH=%PATH%;D:\Qt\Qt5.5.0\Tools\mingw492_32\bin
D:\Qt\Qt5.5.0\Tools\mingw492_32\bin\mingw32-make %
REM Qt creator will read the proper file name: .lib.
copy ../target/CyAPI.a ../target/CyAPI.lib

