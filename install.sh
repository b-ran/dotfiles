sudo pacman -S base-devel xorg xorg-xinit xorg-xrdb picom archlinux-keyring alacritty sxhkd feh --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install window manager
mkdir .config
git clone https://github.com/bakkeby/dwm-flexipatch.git .config/dwm
cd ~/.config/dwm && sudo make clean install

# Install display manager
paru -S ly --noconfirm
sudo systemctl enable ly.service

# Install application launcher

paru -S rofi --noconfirm

# Link dotfiles
./dotfiles/.bin/link.sh


