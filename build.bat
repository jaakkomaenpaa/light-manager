@echo off

gcc -o lights.exe ^
    src\main.c ^
    src\wiz_light.c ^
    src\tuya_light.c ^
    src\error.c ^
    src\config.c ^
    src\helpers.c ^
    -Iinclude ^
    -lWs2_32
    
if %errorlevel% neq 0 (
    echo Build failed
    exit /b %errorlevel%
)

echo Build succeeded