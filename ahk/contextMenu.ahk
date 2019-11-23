#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir "C:\Users\nathaniel_gustafson\Utilities"  ; Ensures a consistent starting directory.


;RWin::Send +{F10}

;RWin::Send {AppsKey}


;LWin & F12::Return
;LWin::Send {AppsKey}
RAlt & F12::Return
RAlt Up::Send {AppsKey}

;$~!E:: Send #{E}
;LAlt & F12::Return
;LAlt & E:: Send #{Tab}
;LAlt & Tab::Send !{Tab}
;LAlt::Send {RWin}





;AutoHotKey can do that. You can definitely keep track of the key states, but there's another trick. To remap Ctrl pressed alone to Esc but keep the other Ctrl-based shortcuts, just add this in your default script:

;Ctrl & AppsKey::Return
;Ctrl::Send {Esc}

;This will work fine for you unless you use Ctrl+AppsKey (the key that pops up the contextual menu), but this is highly unlikely. If so just change AppsKey to any key that you never use with Ctrl.

;The trick is to make Ctrl a prefix by using it in front of & at least once, and then make the release of the key produce the keystroke you want.


