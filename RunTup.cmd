@REM ------------------------------------------------------------------------------------------------------------------------------------------------------
REM RunTup.cmd
@REM Copyright               acontis technologies GmbH, Weingarten, Germany
@REM Response                Paul Bussmann
@REM ------------------------------------------------------------------------------------------------------------------------------------------------------

SETLOCAL ENABLEDELAYEDEXPANSION

pushd %~dp0
set CURDIR=%cd%
popd

@REM ---------------------------------------------------------------------------
@REM Setup environment
set HOME=C:/Users/%USERNAME%
set INCLUDE=
set LIB=
set LIBPATH=
set PATH=C:\MinGW\msys\1.0\bin;C:\Program Files (x86)\WinSCP;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Python36_64
set > env.txt

cd /d %CURDIR%
if not exist .tup tup.exe init
tup.exe %*
rem @if not %errorlevel% equ 0 exit 1

@REM ------------------------------------------------------------------------------------------------------------------------------------------------------
