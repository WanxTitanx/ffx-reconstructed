@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot
set SRC=%1
call :ONE "/O2 /Oy- /Os"
call :ONE "/Ox /Oy- /Os"
call :ONE "/O2 /Oy- /Os /Ob0"
call :ONE "/O2 /Oy-"
goto :EOF
:ONE
echo === FLAGS [%~1] ===
cl.exe /nologo /c /GS- /MD %~1 %SRC% /Foobj_sw.obj >nul 2>&1
echo compile_exit=%ERRORLEVEL%
dumpbin.exe /DISASM obj_sw.obj
goto :EOF
