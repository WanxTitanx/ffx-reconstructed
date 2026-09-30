@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
echo vcvarsall_exit=%ERRORLEVEL%
where cl.exe
cl.exe
echo cl_exit=%ERRORLEVEL%
cd /d C:\IDA_DB
echo int __cdecl main(void){return 0;} > hello_vs2012.c
cl.exe /nologo /c /O2 /MD /GS- hello_vs2012.c /Fohello_vs2012.obj
echo compile_exit=%ERRORLEVEL%
link.exe /nologo /SUBSYSTEM:CONSOLE /OUT:hello_vs2012.exe hello_vs2012.obj kernel32.lib
echo link_exit=%ERRORLEVEL%
if exist hello_vs2012.exe (
  hello_vs2012.exe
  echo run_exit=%ERRORLEVEL%
)
