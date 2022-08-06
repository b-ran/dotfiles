#!/bin/bash
. ~/.config/themes/blocks

echo "^b$bar^ ^c$storage_ic_fg^^b$storage_ic_bg^  ^c$storage_fg^^b$storage_bg^ $(df -h / | awk 'NR==2 { print $4 }' | sed s/i//g) "
