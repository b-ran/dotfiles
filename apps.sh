#!/bin/bash

PS3='Packages sets - enter choice: '
options=("Home" "Dev" "Games" "General" "Nvidia" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Home")
            paru -S coolero discord betterdiscord-installer qbittorrent --noconfirm
            ;;
        "Dev")
            paru -S keepassxc remmina freerdp docker pycharm-professional webstorm python slack-desktop gparted --noconfirm
            sudo groupadd docker
            sudo usermod -aG docker "$USER"
            sudo systemctl enable docker.service
            sudo systemctl enable containerd.service
            ;;
        "Games")
            paru -S steam lutris-git bottles --noconfirm
            ;;
        "General")
            paru -S firefox chromium spotify spotify-tui --noconfirm
            ;;
        "Nvidia")
            paru -S nvidia nvidia-utils nvidia-settings --noconfirm
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
