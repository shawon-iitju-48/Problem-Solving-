@echo off
rem Clear screen and set up colors
cls
color 0A

echo ===================================================
echo                 Stress Testing 
echo ===================================================

rem Compile the test, solution, and brute force programs
echo Compiling test generator...
g++ -std=c++17 -o test.exe test.cpp
if errorlevel 1 (
    color 0C
    echo Compilation of test.cpp failed! Exiting...
    exit /b
)
echo test.exe compiled successfully.

echo Compiling solution...
g++ -std=c++17 -o soln.exe soln.cpp
if errorlevel 1 (
    color 0C
    echo Compilation of soln.cpp failed! Exiting...
    exit /b
)
echo soln.exe compiled successfully.

echo Compiling brute force solution...
g++ -std=c++17 -o brute.exe brute.cpp
if errorlevel 1 (
    color 0C
    echo Compilation of brute.cpp failed! Exiting...
    exit /b
)
echo brute.exe compiled successfully.

rem Run the tests
set PASSED=0
set TOTAL=5
echo ===================================================
echo Starting tests...

for /l %%x in (1, 1, %TOTAL%) do (
    test > input.in
    soln < input.in > output.out
    brute < input.in > output2.out
    fc output.out output2.out > nul
    if errorlevel 1 (
        color 0C
        echo ===================================================
        echo Test %%x failed!
        echo ===================================================
        echo Input:
        type input.in
        echo ---------------------------------------------------
        echo Solution Output:
        type output.out
        echo ---------------------------------------------------
        echo Brute Force Output:
        type output2.out
        echo ===================================================
        exit /b
    )
    echo Test %%x passed.
    set /a PASSED+=1
)

color 0A
echo ===================================================
echo All tests passed!
echo Total Tests: %TOTAL% ^| Passed: %PASSED% ^| Failed: 0
echo ===================================================

rem Clean up generated files
echo Cleaning up...
del test.exe
del soln.exe
del brute.exe
del input.in
del output.out
del output2.out
if exist diagnostics del diagnostics
pause
