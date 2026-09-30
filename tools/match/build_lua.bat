@echo off
REM Rebuild the Lua 5.2.1 candidates from the PhyreEngine SDK tree.
REM Run on the Windows VM. Copy the SDK's External/lua/src to C:\IDA_DB\lua\all first.
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\lua\all
if not exist obj mkdir obj
if not exist dis mkdir dis
for %%F in (l*.c) do (
  cl.exe /nologo /c /GS- /O2 /MD /Oy- /Oi /Foobj\%%~nF.obj %%F >nul 2>&1
  if exist obj\%%~nF.obj dumpbin.exe /DISASM obj\%%~nF.obj > dis\%%~nF.txt 2>&1
)
echo LUA_BUILD_DONE
