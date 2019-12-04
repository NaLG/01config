#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.


SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


;   ^ for CTRL
;   ! for ALT
;   # for Windows Key
;   + for Shift


$j::Send {Backspace}
$/::Send {j}
$+/::Send {J}
$!/::Send {/}
$!+/::Send {?}

$k::Send {Return}
$`;::Send `k
$+`;::Send `K
$!`;::Send `:
$!+`;::Send `;


;  <!Up  = left alt + up
;  >!Up  = right alt + up

;!Up:
;	Send {Up}
;	sleep 100
;	Send {Up}
;return
;!Down:
;	Send {Down}
;	sleep 100
;	Send {Down}
;return

