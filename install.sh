sudo pacman -S --needed base-devel xorg xorg-xinit xorg-xrdb picom archlinux-keyring alacritty sxhkd feh --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install packages
paru -S rofi ttf-jetbrains-mono nerd-fonts-jetbrains-mono pamixer xmenu imlib2 udiskie --noconfirm

# Install dwm
mkdir .config
~/dotfiles/scripts/copy.sh
cd ~/.config/dwm && sudo make install
cd ~/.config/dwmblocks && sudo make install
cd ~/.config/xmenu && sudo make install

# Install display manager
paru -S ly --noconfirm
sudo systemctl enable ly.service