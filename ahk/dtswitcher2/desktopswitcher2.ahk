

;   ^ for CTRL
;   ! for ALT
;   # for Windows Key
;   + for Shift


;#SETUP START
#NoEnv ; Recommended for performance and compatibility with future AutoHotkey releases.
#SingleInstance force
ListLines Off
SetBatchLines -1
SendMode Input ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir% ; Ensures a consistent starting directory.
#KeyHistory 0
#WinActivateForce

Process, Priority,, H

SetWinDelay -1
SetControlDelay -1

;include the library
#Include VD.ahk
; VD.init() ;COMMENT OUT `static dummyStatic1 := VD.init()` if you don't want to init at start of script

;you should WinHide invisible programs that have a window.
WinHide, % "Malwarebytes Tray Application"
;#SETUP END

VD.createUntil(3) ;create until we have at least 3 VD

return

MoveCurrentWindowToLeft()
{
    n := VD.getCurrentDesktopNum()
    if n = 1
    {
        Return
    }
    n -= 1
    VD.MoveWindowToDesktopNum("A",n), VD.goToDesktopNum(n)
    Return
}

^#+Left::MoveCurrentWindowToLeft()
CapsLock & q::MoveCurrentWindowToLeft()


MoveCurrentWindowToRight()
{
    n := VD.getCurrentDesktopNum()
    if n = % VD.getCount()
    {
        Return
    }
    n += 1
    VD.MoveWindowToDesktopNum("A",n), VD.goToDesktopNum(n)
    Return
}

^#+Right::MoveCurrentWindowToRight()
CapsLock & w::MoveCurrentWindowToRight()


switchDesktopToLeft()
{
    n := VD.getCurrentDesktopNum()
    if n = 1
    {
        Return
    }
    n -= 1
    VD.goToDesktopNum(n)
    Return
}

CapsLock & a::SwitchDesktopToLeft()

switchDesktopToRight()
{
    n := VD.getCurrentDesktopNum()
    if n = % VD.getCount()
    {
        Return
    }
    n += 1
    VD.goToDesktopNum(n)
    Return
}

CapsLock & s::SwitchDesktopToRight()


switchDesktopByNumber(targetDesktop)
{
    ;global CurrentDesktop, DesktopCount
    ;updateGlobalVariables()
    ;_switchDesktopToTarget(targetDesktop)

    VD.goToDesktopNum(targetDesktop)
    Return
}



CapsLock & 1::switchDesktopByNumber(1)
CapsLock & 2::switchDesktopByNumber(2)
CapsLock & 3::switchDesktopByNumber(3)
CapsLock & 4::switchDesktopByNumber(4)
CapsLock & 5::switchDesktopByNumber(5)
CapsLock & 6::switchDesktopByNumber(6)
CapsLock & 7::switchDesktopByNumber(7)
CapsLock & 8::switchDesktopByNumber(8)
CapsLock & 9::switchDesktopByNumber(9)

^!1::switchDesktopByNumber(1)
^!2::switchDesktopByNumber(2)
^!3::switchDesktopByNumber(3)
^!4::switchDesktopByNumber(4)
^!5::switchDesktopByNumber(5)
^!6::switchDesktopByNumber(6)
^!7::switchDesktopByNumber(7)
^!8::switchDesktopByNumber(8)
^!9::switchDesktopByNumber(9)

