@echo off
setlocal
rem Defaults use ../ffx_memcmp.c and ./build_c relative to this package.
rem For a staged build, pass --source and --output-dir explicitly.
rem The helper captures build.log and publishes the manifest only on success.
py -3 "%~dp0build_memcmp.py" %*
exit /b %errorlevel%
