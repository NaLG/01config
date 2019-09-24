#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.


SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

;CoordMode, Mouse, Screen


;   ^ for CTRL
;   ! for ALT
;   # for Windows Key
;   + for Shift

smallStep := 50
largeStep := 250
waitTicks := 1000
waitMultiplier := 4

;Multiple scaling on multi-monitor setup in Windows 10 seems to break this!

; $ and or !~! allow passthrough so I don't break Ctrl-Up on other programs:
;$~!+Up::
$~!+Up::
	;WinGetClass, class, A
	;MsgBox, A_ScreenWidth: "%A_ScreenWidth%" A_ScreenHeight: "%A_ScreenHeight%".
	;MsgBox, Tick Count: "%A_TickCount%".
	;MsgBox, The active window's class is "%class%".
	;WinGetPos , X, Y, Width, Height, WinTitle, WinText, ExcludeTitle, ExcludeText
	
	WinGetPos , X, Y, Width, Height, A, , , 
	
	;MsgBox, Title: "%WinTitle%" Text: "%WinText%" X: "%X%" Ypre: "%Y%"
	; for Chrome: The active window's class is "Chrome_WidgetWin_1".
	;CoordMode, Mouse, Screen ; This did it!
	;WinGetPos, X, Y, Width, Height, A 
	
	Y -= %smallStep%
	
	;if (Y < 0)
	;{
	;	Y = 0
	;}
	;MsgBox, Title: "%WinTitle%" Text: "%WinText%" X: "%X%" Ypost: "%Y%"
	;WinMove, %WinTitle%, %WinText%, %X%, %Y% ;
	;MsgBox, Title: "%WinTitle%" Text: "%WinText%" X: "%X%" Ypost: "%Y%"
	;WinMove, %X%, %Y% ;
	;MsgBox, Title: "%WinTitle%" Text: "%WinText%" X: "%X%" Ypost: "%Y%"
	
	WinMove, A, , %X%, %Y% ;
	
	;MsgBox, Tick Count: "%A_TickCount%".

	; extras:
	;relX = %destX%
	;relY = %destY%
	;relX -= %curX%
	;relY -= %curY%
	;MsgBox, %Width%w, %destX%d, %Height%h
	;MsgBox, %X%X, %Y%Y, %Width%w, %Height%h, %curX%curX, %curY%curY, %destX%destX, %destY%destY, %relX%relX, %relY%relY
	;MouseMove, %destX%, 200
	;MouseMove, 500, 500
	;MouseMove, %relX%, %relY%, 0, R
	;MouseMove, 40, 40, 0, R

	;MouseGetPos, newX, newY
	;MsgBox, %X%X, %Y%Y, %Width%w, %Height%h, %curX%curX, %curY%curY, %destX%destX, %destY%destY, %relX%relX, %relY%relY, %newX%newX, %newY%newY

	; Better for multi screen? The first number is the X-coordinate and the second is the Y (relative to the screen).
	;DllCall("SetCursorPos", "int", 100, "int", 400)  
	
	;sleep 1
	;MouseMove, %curX%, %curY%
return


$~!+Down::
	WinGetPos , X, Y, Width, Height, A, , , 
	Y += %smallStep%
	;if (Y > 0)
	;	{Y = 0}
	WinMove, A, , %X%, %Y% ;
return

$~!+Left::
	WinGetPos , X, Y, Width, Height, A, , , 
	X -= %smallStep%
	WinMove, A, , %X%, %Y% ;
return

$~!+Right::
	;IniRead, lastTick, lastTick.ini, variables, lastTick, 3

	;ticks = %A_TickCount%
	;ticks -= %lastTick%
	;ticks -= %waitTicks%
	;IniWrite, %A_TickCount%, lastTick.ini, variables, lastTick
	;MsgBox, ticks: "%ticks%" lastTicks: "%lastTicks%" waitTicks: "%waitTicks%" a_ticks: "%A_TickCount%"
	WinGetPos , X, Y, Width, Height, A, , , 
	;if (%ticks% > %waitTicks%)
	;{
		X += %smallStep%
	;	MsgBox, "One Move"
	;}
	;else
	;{
	;	MsgBox, "Many Move"
	;	Loop, %waitMultiplier%
	;	{
	;		X += %smallStep%
	;	}
	;}
	WinMove, A, , %X%, %Y% ;
return




$~^!+Up::
	WinGetPos , X, Y, Width, Height, A, , , 
	Y -= %largeStep%
	WinMove, A, , %X%, %Y% 
return

$~^!+Down::
	WinGetPos , X, Y, Width, Height, A, , , 
	Y += %largeStep%
	WinMove, A, , %X%, %Y% 
return

$~^!+Left::
	WinGetPos , X, Y, Width, Height, A, , , 
	X -= %largeStep%
	WinMove, A, , %X%, %Y% 
return

$~^!+Right::
	WinGetPos , X, Y, Width, Height, A, , , 
	X += %largeStep%
	WinMove, A, , %X%, %Y% 
return







