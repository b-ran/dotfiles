#!/usr/bin/env bash

cp -rf ~/dotfiles/.config/* ~/.config/
sudo mkdir -p /usr/share/xsessions && sudo cp -rf ~/dotfiles/xsessions/* /usr/share/xsessions
