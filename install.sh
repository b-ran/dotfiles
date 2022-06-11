sudo pacman -S base-devel xorg xorg-xinit xorg-xrdb picom git archlinux-keyring alacritty sxhkd feh --noconfirm
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru


