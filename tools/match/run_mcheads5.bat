@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot\mcheads5
for %%F in (r_*.c) do (
  cl.exe /nologo /c /GS- /O2 /MD /Oy- /Oi %%F /Foobj_%%~nF.obj >nul 2>&1
  dumpbin.exe /DISASM obj_%%~nF.obj > dis_%%~nF.txt 2>&1
)
echo MCHEADS5_DONE
