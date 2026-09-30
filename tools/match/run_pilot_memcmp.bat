@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 >nul 2>&1
cd /d C:\IDA_DB\pilot
call :BUILD O2  "/O2 /MD"
call :BUILD O1  "/O1 /MD"
call :BUILD Ox  "/Ox /MD"
call :BUILD MT  "/O2 /MT"
call :BUILD GS  "/O2 /MD /GS"
goto :EOF
:BUILD
set TAG=%1
set FLAGS=%~2
echo === FLAGS %TAG% [%FLAGS%] ===
cl.exe /nologo /c /GS- %FLAGS% pilot_ffx_memcmp.c /Foobj_%TAG%.obj
echo compile_exit=%ERRORLEVEL%
dumpbin.exe /nologo /DISASM obj_%TAG%.obj
goto :EOF
