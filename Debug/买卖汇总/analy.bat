@echo off
cd %~dp0 
del total.txt
for /f %%i in ('dir /b "..\..\..\htzq\T0002\export\*.*"') do ("..\StockAnalys.exe" "..\..\..\htzq\T0002\export\%%i" 3 60 > %%i)
type *#*.txt>>total.txt
del *#*.txt