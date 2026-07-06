@echo off
setlocal enabledelayedexpansion

echo ===== FFX_Reconstructed Build =====
echo.

REM Step 1: Find CMake
echo [1/4] Procurando CMake...
where cmake >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo [ERRO] CMake nao encontrado!
    echo Instale CMake 3.0+ em: https://cmake.org/download/
    echo Ou execute pelo terminal do Visual Studio Developer Command Prompt.
    pause
    exit /b 1
)
echo    CMake encontrado: 
for /f "tokens=*" %%a in ('where cmake') do echo    %%a
echo.

REM Step 2: Create build dir
echo [2/4] Criando diretorio build...
if not exist "%CD%\build" mkdir "%CD%\build"
cd /d "%CD%\build"
echo.

REM Step 3: CMake Configure
echo [3/4] Configurando CMake...
echo    Tentando Visual Studio 2022...
cmake .. -G "Visual Studio 17 2022" -A Win32 2>cmake_error.log
if %ERRORLEVEL% NEQ 0 (
    type cmake_error.log
    echo.
    echo    VS2022 nao encontrado, tentando VS 2019...
    cmake .. -G "Visual Studio 16 2019" -A Win32 2>cmake_error.log
)
if %ERRORLEVEL% NEQ 0 (
    type cmake_error.log
    echo.
    echo    VS2019 nao encontrado, tentando Ninja/MinGW...
    cmake .. -G "MinGW Makefiles" 2>cmake_error.log
)
if %ERRORLEVEL% NEQ 0 (
    type cmake_error.log
    echo.
    echo [ERRO] Nao foi possivel configurar o CMake.
    echo Certifique-se de ter o Visual Studio 2022/2019 instalado
    echo com a ferramenta "Desktop development with C++".
    pause
    exit /b 1
)
echo.
echo    CMake configurado com sucesso!

REM Step 4: Build
echo [4/4] Compilando...
cmake --build . --config Release 2>build_error.log
if %ERRORLEVEL% NEQ 0 (
    echo [ERRO] Build falhou!
    echo    Log de erros: build_error.log
    type build_error.log | findstr /i "error"
    pause
    exit /b 1
)

echo.
echo ===== BUILD SUCESSO! =====
echo Output: %CD%\Release\FFX_Reconstructed.exe
pause
endlocal
