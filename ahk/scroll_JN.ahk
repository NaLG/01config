#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.


SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

; eg. Allows window title to contain 'Excel' anywhere:
SetTitleMatchMode, 2 
;WinWaitActive, Excel

;or this:

;#Persistent   
;SetTitleMatchMode, 1 ; match start of the title
;SetTimer, myLabel, 60000
;Return
;
;myLabel:
;    If WinActive("GSdx |")
;        Send, {F1}
;Return

	
;CoordMode, Mouse, Screen


;   ^ for CTRL
;   ! for ALT
;   # for Windows Key
;   + for Shift


;Multiple scaling on multi-monitor setup in Windows 10 seems to break this!

; $ and or !~! allow passthrough so I don't break Ctrl-Up on other programs:
;$~^Up::
$~^Up::
	WinGetClass, class, A
	;MsgBox, The active window's class is "%class%".
	; for Chrome: The active window's class is "Chrome_WidgetWin_1".
	if (class == "Chrome_WidgetWin_1")
	{
		If WinActive("Jupyter Notebook")
		{
			CoordMode, Mouse, Screen ; This did it!
			WinGetPos, X, Y, Width, Height, A 
			MouseGetPos, curX, curY
			if (curX > X+Width | curX < X | curY > Y+Height | curY < Y)
			{
				destX = %X%
				destY = %Y%
				destX += %Width%
				destX -= 50		
				destY += 250
				;Move mouse to active window so scroll wheel has correct context
				MouseMove, %destX%, %destY%
			}
			Send,{WheelUp}

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
		}
	}
	else
	{
		;MsgBox, %class%
	}
return

$~^Down::
	WinGetClass, class, A
	if (class == "Chrome_WidgetWin_1")
	{
		If WinActive("Jupyter Notebook")
		{
			CoordMode, Mouse, Screen ; This did it!
			WinGetPos, X, Y, Width, Height, A 
			MouseGetPos, curX, curY
			if (curX > X+Width | curX < X | curY > Y+Height | curY < Y)
			{
				destX = %X%
				destY = %Y%
				destX += %Width%
				destX -= 50
				destY += 250
				;Move mouse to active window so scroll wheel has correct context
				MouseMove, %destX%, %destY%
			}
			Send,{WheelDown}

			;sleep 1
			;MouseMove, %curX%, %curY%


			;old (works?)

			;;WinGetPos, X, Y, Width, Height, A; Does not work
			;WinGetPos, X, Y, Width, Height, A 
			;;destX = %Width% - 50  ; Doesn't work - keeps a string
			;destX = %Width%
			;destX -= 50		; Uses a number, yay
			;;MsgBox, %Width%w, %destX%d, %Height%h
			;MouseMove, %destX%, 200
			;Send,{WheelDown}
		}
	}
	else
	{ 
		;MsgBox, %class%
	}
return



;WinGetPos , X, Y, Width, Height, WinTitle, WinText, ExcludeTitle, ExcludeText





;#IfWinActive, ahk_class Chrome.exe ;; start of IfWinActive condition, for me it didn't work with ahk_class so i ;changed it to ahk_exe
;^Up::
;	WinGetPos, X, Y, Width, Height, A ;
;	MouseMove, %Width%-50, 200
;	send,{WheelUp}
;return
;
;^Down::
;	WinGetPos, X, Y, Width, Height, A ;
;	MouseMove, %Width%-50, 200
;	send,{WheelDown}
;return
;
;#IfWinActive ;; end of condition IfWinActive




;WinGetPos, X, Y, Width, Height, Calculator
;MsgBox, Calculator is at %X%`,%Y%
;
;WinGetPos, X, Y, , , A  ; "A" to get the active window's pos.
;MsgBox, The active window is at %X%`,%Y%
;
;if WinExist("Untitled - Notepad")
;{
;    WinGetPos, Xpos, Ypos  ; Uses the window found above.
;    MsgBox, Notepad is at %Xpos%`,%Ypos%
;}