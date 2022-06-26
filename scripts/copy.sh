#!/bin/bash

cp -rf ~/dotfiles/.config/* ~/.config/
cp -rf ~/dotfiles/.Xresources ~/.Xresources
sudo mkdir -p /usr/share/xsessions && sudo cp -rf ~/dotfiles/xsessions/* /usr/share/xsessions