#!/usr/bin/env bash

cp -rsfu ~/dotfiles/.config/* ~/.config/
sudo mkdir -p /usr/share/xsessions && cp -rsu ~/dotfiles/xsessions/* /usr/share/xsessions
