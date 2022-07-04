#!/bin/bash
. ~/.config/themes/blocks

printf "^b#1E222A^ ^c#7797b7^  "
printf "^b#2E3440^ ^c#7797b7^ %s $(free -h | awk '/^Mem/ { print $3"/"$2 }' | sed s/i//g)"