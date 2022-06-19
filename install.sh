sudo pacman -S --needed base-devel xorg xorg-xinit xorg-xrdb picom archlinux-keyring alacritty sxhkd feh ttf-iosevka-nerd --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install window manager - dwmflexipatch
mkdir .config
git clone https://github.com/bakkeby/dwm-flexipatch.git .config/dwm
cd ~/.config/dwm && sudo make install

# Install status bar - dwm blocks
git clone https://github.com/torrinfail/dwmblocks.git .config/dwmblocks
cd ~/.config/dwmblocks && sudo make install

# Install display manager
paru -S ly --noconfirm
sudo systemctl enable ly.service

# Install packages
paru -S rofi nerd-fonts-complete tmux-git firefox --noconfirm

# Copy dotfiles
~/dotfiles/.bin/copy.sh


