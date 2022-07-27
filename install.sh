sudo pacman -S --needed base-devel xorg xorg-xinit xorg-xrdb picom archlinux-keyring alacritty sxhkd feh --noconfirm

# Install aur helper -- paru
git clone https://aur.archlinux.org/paru.git
cd paru && makepkg -si --noconfirm
cd .. && rm -rf paru

# Install packages
paru -S rofi networkmanager-openvpn network-manager-applet networkmanager-dmenu-git \
        ttf-jetbrains-mono ttf-ms-fonts nerd-fonts-jetbrains-mono papirus-icon-theme pamixer xmenu imlib2 udiskie gpick \
        ly thunar thunar-archive-plugin tumbler ffmpeg ffmpegthumbnailer gvfs-smb gtk3 gvfs-afc peazip-gtk2-bin ranger ncdu \
        pavucontrol alsa-plugins alsa-tools alsa-utils pamixer portaudio wireplumber pipewire-alsa pipewire-jack pipewire-zeroconf pipewire-pulse mpv-git \
        unzip tmux rsync openssh zsh exa xclip htop gtop neofetch wget oh-my-zsh-git bat cbonsai viddy shell-color-scripts \
        bluez blueberry xfce4-power-manager xfce4-settings --noconfirm

sudo systemctl enable ly.service
sudo systemctl enable bluetooth.service

# Install dwm
mkdir .config
~/dotfiles/scripts/copy.sh
cd ~/.config/dwm && sudo make install
cd ~/.config/dwmblocks && sudo make install
cd ~/.config/xmenu && sudo make install
