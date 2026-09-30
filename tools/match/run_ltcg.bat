@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot\ltcg
cl.exe /nologo /c /GS- /O2 /MD /Oy- /Oi /GL w1.c /Fow1_gl.obj
echo gl_compile=%ERRORLEVEL%
link.exe /nologo /LTCG /OUT:w1_ltcg.exe w1_gl.obj kernel32.lib /SUBSYSTEM:CONSOLE /ENTRY:W1 > link.log 2>&1
echo ltcg_link=%ERRORLEVEL%
dumpbin.exe /DISASM w1_ltcg.exe > w1_dis.txt 2>&1
findstr /R /C:"_W1:" w1_dis.txt
