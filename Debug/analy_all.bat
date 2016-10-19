@echo off
for /f "delims=" %%i in ('dir /b /a-d /s "analy.bat"') do call "%%i" 
#pause
