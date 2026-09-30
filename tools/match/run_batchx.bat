@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot\batchx
cl.exe /nologo /c /GS- /O2 /MD /Oy- /Tp v31.cpp /Foobj_x_cpp.obj >nul 2>&1
dumpbin.exe /DISASM obj_x_cpp.obj > dis_x_cpp.txt 2>&1
cl.exe /nologo /c /GS- /O2 /MD /Oy- /G7 v31.c /Foobj_x_g7.obj >nul 2>&1
dumpbin.exe /DISASM obj_x_g7.obj > dis_x_g7.txt 2>&1
cl.exe /nologo /c /GS- /O2 /MD /Oy- /arch:SSE v31.c /Foobj_x_sse.obj >nul 2>&1
dumpbin.exe /DISASM obj_x_sse.obj > dis_x_sse.txt 2>&1
cl.exe /nologo /c /GS- /O2 /MD /Oy- /Ob2 /Oi /Ot v31.c /Foobj_x_ob.obj >nul 2>&1
dumpbin.exe /DISASM obj_x_ob.obj > dis_x_ob.txt 2>&1
echo BATCHX_DONE
