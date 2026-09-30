@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\lua\obj
cl.exe /nologo /c /GS- /O2 /MD /Oy- /Oi lstrlib.c > lstrlib.log 2>&1
echo strlib=%ERRORLEVEL%
type lstrlib.log
cl.exe /nologo /c /GS- /O2 /MD /Oy- /Oi lstring.c > lstring.log 2>&1
echo string=%ERRORLEVEL%
type lstring.log
dumpbin.exe /DISASM lstrlib.obj > dis_lstrlib.txt 2>&1
dumpbin.exe /DISASM lstring.obj > dis_lstring.txt 2>&1
echo DIS_DONE
