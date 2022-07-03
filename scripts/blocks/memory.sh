#!/bin/bash
. ~/.config/themes/blocks

echo " ^b#1E222A^ ^c#7797b7^^b#2E3440^  ^c#7797b7^ $(free -h | awk '/^Mem/ { print $3"/"$2 }' | sed s/i//g)"