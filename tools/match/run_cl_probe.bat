@echo off
setlocal
set CL=C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\bin\cl.exe
set LINK=C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\bin\link.exe
echo === cl ===
"%CL%"
echo === link ===
"%LINK%"
echo === compile+link hello ===
cd /d C:\IDA_DB
echo int __cdecl main(void){return 0;} > hello_vs2012.c
"%CL%" /nologo /c /O2 /MD /GS- hello_vs2012.c /Fohello_vs2012.obj
echo cl_exit=%ERRORLEVEL%
"%LINK%" /nologo /SUBSYSTEM:CONSOLE /OUT:hello_vs2012.exe hello_vs2012.obj kernel32.lib
echo link_exit=%ERRORLEVEL%
if exist hello_vs2012.exe (
  hello_vs2012.exe
  echo run_exit=%ERRORLEVEL%
)
