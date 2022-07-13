#!/bin/bash

cp -srf ~/dotfiles/.config/* ~/.config/
cp -srf ~/dotfiles/.Xresources ~/.Xresources
cp -srf ~/dotfiles/.fehbg ~/.fehbg
sudo mkdir -p /usr/share/xsessions && sudo cp -srf ~/dotfiles/xsessions/* /usr/share/xsessions