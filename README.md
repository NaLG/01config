# 01config
Configuration for an easier desktop.  

Mostly oriented around Hotkeys and Darkmode.  Uses Sublime Text 3 hotkeys with some tweaks.

For Windows 10.  Feel free to port whatever is useful to you.

## AHK:

Install autohotkey.

Run the .ahk scripts, change as desired, play with them.

For each .ahk you want persistent:

  Set a shortcuts in startup to that .ahk:
    C:\Users\<username>\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup

This will run that script at login.

### Movewin
hotkeys for resizing and moving windows Requires sizer 4.0.

### scroll_JN
ctrl+up and ctrl+down for scrolling in Jupyter Notebook.  Requires sizer 4.0.

### pageudmany
Experiment, used for sending many pgup/pgdn signals in short succession.  Useful for scrolling large data sets.

### altztopy
Hotkeys for sending lines out of SublimeREPL into a python interpreter.  Unstable but handy if Sublime->Python is your goal.

### contextMenu
Enable RWin to be used as a context menu key.  Not perfect but beats the lack of a context menu key.

### desktop_switcher
Thanks to [pmb6tz's windows desktop switcher](https://github.com/pmb6tz/windows-desktop-switcher/).  I did not branch this repo, Just copied the files, so go there for the latest.

I made some modifications - removed looping desktops, added hotkeys for moving windows to Left or Right desktops, convert to default windows hotkeys to avoid flickering issues.

## EverythingDarkMode.txt

Notes and references on how to get darkmode in various tools.

## jupyterNotebook.txt

Notes and references on getting a visually happy, darkmode setup in Jupyter notebook with sublime-like hotkeys.

## sizer.xml

Install sizer 4.0 by Brianapps.

Import sizer.xml

Change as desired.

This is setup mainly for 3440x1440 and 3840x1600 ultrawide displays.

## Default (Windows).sublime-keymap
Changes to Sublime's hotkeys

## SublimeShortcuts.vssettings
Thanks to [justcla](https://github.com/justcla/SublimeVS) for Sublime shortcuts available in Visual Studio.  Made some tweaks here for my needs.

