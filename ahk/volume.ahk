﻿#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.


SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

;CoordMode, Mouse, Screen


;   ^ for CTRL
;   ! for ALT
;   # for Windows Key
;   + for Shift


;f7::SoundSet,-2
;f8::SoundSet,+2

f7::Send {Volume_Down}
f8::Send {Volume_Up}

