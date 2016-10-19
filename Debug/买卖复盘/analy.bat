@echo off
cd %~dp0 
for /f %%i in ('dir /b "..\..\..\htzq\T0002\export\*.*"') do ("..\StockAnalys.exe" "..\..\..\htzq\T0002\export\%%i" 1 60 > %%i)