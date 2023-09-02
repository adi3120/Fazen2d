@echo off

echo Compiling and building the project...
make

if %errorlevel% neq 0 (
    echo Error: Compilation failed.
    pause
    exit /b %errorlevel%
)

echo Cleaning up...
make clean

if %errorlevel% neq 0 (
    echo Error: Clean-up failed.
    pause
    exit /b %errorlevel%
)

echo Running the program...
echo Compiling and Linking Done!.
