
# For windows:

#in cmd: install wsl
wsl --install 
# reboot etc
wsl
# in home dir or wherever





mkdir utils
cd utils
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
./util/qmk_install.sh

# source ./util/qmk_install.sh # shouldn't be needed
# sudo apt-get install python3 pip # need python if not avail

pip install qmk
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
qmk # exists!

#in qmk_firmware
qmk setup


// PERMISSIVE_HOLD is 
// f'd up on mac after 0.20.8.  Permissive hold isn't working, can sidestep by shortening tapping_term but hacky.
// TO BUILD
//   git checkout 0.20.8
//   make atreus62:nalgmac:flash


make atreus62:default
make atreus62:nalg
make atreus62:nalg:flash # can do on native *nix

# may not be able to flash USB device through WSL
# so qmk toolbox can flash the hex
# use everything etc to find .hex,
#   https://github.com/qmk/qmk_toolbox/releases

open QMK toolbox, install drivers as prompted
ATmega32U4 as default should work fine
auto-flash and reset board (hotkey, or reset button or short)

