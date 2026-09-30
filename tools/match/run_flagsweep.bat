@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot
set SRC=pilot30_memcmp.c
if not "%~1"=="" set SRC=%~1
for %%G in ("/O1 /Oy-" "/Ox /Oy-" "/O2 /Oy- /Ot" "/O2 /Oy- /Os" "/O1 /Oy- /Os" "/O2 /Oy- /Ob1" "/O2 /Oy- /Oi-" "/O2 /Oy- /Gy-" "/O2 /Oy- /GT" "/Od /Oy-") do (
  for /f "tokens=1,2" %%A in (%%G) do (
    echo === FLAGS [%%A %%B] ===
    cl.exe /nologo /c /GS- /MD %%A %%B %SRC% /Foobj_fs.obj >nul 2>&1
    echo compile_exit=%ERRORLEVEL%
    dumpbin.exe /DISASM obj_fs.obj | findstr /R "^  0000000[0-9A-F]:"
  )
)
