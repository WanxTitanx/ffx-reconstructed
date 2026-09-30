@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\lua\src
for %%F in (l*.c) do if not "%%F"=="lua.c" if not "%%F"=="luac.c" cl.exe /nologo /c /GS- /O2 /MD /Oy- /Oi /GL %%F /Foobj_%%~nF.obj >nul 2>&1
echo compiled=%ERRORLEVEL%
link.exe /nologo /LTCG /OUT:lua_test.exe obj_*.obj kernel32.lib /SUBSYSTEM:CONSOLE /ENTRY:luaS_eqstr > link.log 2>&1
echo link=%ERRORLEVEL%
dumpbin.exe /DISASM lua_test.exe > lua_dis.txt 2>&1
echo DIS_DONE
