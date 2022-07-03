#!/bin/bash
. ~/.config/themes/blocks

echo " ^b#1E222A^ ^c#2E3440^^b#caaa6a^ ^c#2E3440^ $(df -h / | awk 'NR==2 { print $4 }' | sed s/i//g)"
