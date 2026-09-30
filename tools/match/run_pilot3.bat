@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot
set VARIANT=pilot3_memcmp.c
if not "%~1"=="" set VARIANT=%~1
set EXTRA=%~2
cl.exe /nologo /c /GS- /O2 /MD %EXTRA% %VARIANT% /Foobj_p3.obj
echo compile_exit=%ERRORLEVEL%
dumpbin.exe /DISASM obj_p3.obj
