@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot\batch1
for %%F in (v*.c) do (
  cl.exe /nologo /c /GS- /O1 /MD /Oy- %%F /Foobj_%%~nF.obj >nul 2>&1
  dumpbin.exe /DISASM obj_%%~nF.obj > dis_%%~nF.txt 2>&1
)
echo BATCH1_DONE
