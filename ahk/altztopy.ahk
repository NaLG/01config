#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.


SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


;   ^ for CTRL
;   ! for ALT
;   # for Windows Key
;   + for Shift

;SetKeyDelay 30,50
;Send, {ALT DOWN}{TAB}{ALT UP}

;Highlight line and copy into running python terminal. alt-z
!z::
Send {END}
Send {SHIFTDOWN}{HOME}
Send {SHIFTUP}
Send ^c

sleep 50
Send {HOME}
sleep 50

;Send !{ENTER}

;SetTitleMatchMode, 2

WinActivate, *REPL* [python] - Sublime Text

var := clipboard
;WinActivate, another window
sleep 50
Send %var%
Send {enter}

Send, {ALT DOWN}{TAB}{ALT UP}

return



; copy highlighted selection into running python terminal. alt-d
!d::
Send ^c

sleep 150

WinActivate, *REPL* [python] - Sublime Text

var := clipboard
;WinActivate, another window
sleep 150
;Send %var%
Send ^v
sleep 500
Send {enter}
sleep 1000

SetKeyDelay 60,100
Send, {ALT DOWN}{TAB}{ALT UP}

return

