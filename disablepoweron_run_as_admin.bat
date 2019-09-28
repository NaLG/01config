
REM Tired of computer waking from every new USB device you plug in?
REM Tire no longer.  Run this batch file and any devices which CAN
REM wake the PC, will be asked kindly not to.
REM
REM This doesn't disable wake timers.  Also things like Xbox controllers 
REM which change states AFTER the PC sleeps may still wake it. 
REM Frustrating but this bat should help with most new devices.
REM
REM Right click -> Run as admin 


REM powercfg -devicequery wake_from_any > temp.txt
powercfg -devicequery wake_armed > devices.txt

REM powercfg -devicequery wake_from_any > devices.txt

rem for /F "delims=" %i in (devices.txt) do powercfg -devicedisablewake "%i" done
rem for /F "delims=" %%i in (devices.txt) do echo powercfg -devicedisablewake "%%i" done
rem for /F "delims=" %%i in (devices.txt) do powercfg --devicedisablewake "%%i" done
for /F "delims=" %%i in (devices.txt) do powercfg /devicedisablewake "%%i"

