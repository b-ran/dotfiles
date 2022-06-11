sudo pacman -S base-devel xorg xorg-xinit xorg-xrdb picom archlinux-keyring alacritty sxhkd feh --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install window manager
mkdir .config
git clone https://github.com/bakkeby/dwm-flexipatch.git .config/dwm-flexipatch

# Clone and Link dotfiles

git clone https://github.com/b-ran/dotfiles.git
./dotfiles/util/link.sh


