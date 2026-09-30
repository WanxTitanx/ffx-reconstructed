@echo off
setlocal
py -3 "%~dp0leaf_build.py" %*
exit /b %errorlevel%
