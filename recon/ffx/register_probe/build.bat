@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
if errorlevel 1 exit /b 1
cd /d "%~dp0"
cl /TP /c /O2 /MD /GS- /Oy- /Oi /arch:IA32 /Gy probe.c /Foprobe.obj >build.log 2>&1
if errorlevel 1 exit /b 1
dumpbin /DISASM probe.obj >probe.dis.txt
if errorlevel 1 exit /b 1
exit /b 0
