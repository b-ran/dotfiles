#!/bin/bash
. ~/.config/themes/blocks

echo "^b$bar^ ^c$mem_ic_fg^^b$mem_ic_bg^  ^c$mem_fg^^b$mem_bg^ $(free -h | awk '/^Mem/ { print $3"/"$2 }' | sed s/i//g) "