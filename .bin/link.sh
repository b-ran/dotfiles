#!/usr/bin/env bash

cp -rsf ~/dotfiles/.config/*/ ~/.config/*/
sudo mkdir -p /usr/share/xsessions && cp -rs ~/dotfiles/xsessions/* /usr/share/xsessions
