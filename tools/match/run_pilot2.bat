@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot
cl.exe /nologo /c /GS- /O2 /MD pilot2_memcmp.c /Foobj_p2.obj
echo compile_exit=%ERRORLEVEL%
dumpbin.exe /DISASM obj_p2.obj
