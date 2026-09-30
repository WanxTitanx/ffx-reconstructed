@echo off
setlocal
py -3 "%~dp0relocation_build.py" %*
exit /b %errorlevel%
