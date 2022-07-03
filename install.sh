sudo pacman -S --needed base-devel xorg xorg-xinit xorg-xrdb picom archlinux-keyring alacritty sxhkd feh --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install dwm
mkdir .config
git clone https://github.com/bakkeby/dwm-flexipatch.git ~/.config/dwm
git clone https://github.com/torrinfail/dwmblocks.git ~/.config/dwmblocks

~/dotfiles/scripts/copy.sh
cd ~/.config/dwm && sudo make install
cd ~/.config/dwmblocks && sudo make install

# Install display manager
paru -S ly --noconfirm
sudo systemctl enable ly.service

# Install packages
paru -S rofi tmux-git firefox --noconfirm


git clone https://aur.archlinux.org/nerd-fonts-complete.git
cd nerd-fonts-complete
wget -O nerd-fonts-2.1.0.tar.gz https://github.com/ryanoasis/nerd-fonts/archive/v2.1.0.tar.gz
makepkg -sci BUILDDIR=.