sudo pacman -S --needed base-devel xorg xorg-xinit xorg-xrdb xmenu imlib2 picom archlinux-keyring alacritty sxhkd feh --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install dwm
mkdir .config
~/dotfiles/scripts/copy.sh
cd ~/.config/dwm && sudo make install
cd ~/.config/dwmblocks && sudo make install

# Install display manager
paru -S ly --noconfirm
sudo systemctl enable ly.service

# Install packages
paru -S rofi tmux-git firefox nerd-fonts-complete pamixer thunar udiskie --noconfirm