#!/bin/bash
. ~/.config/themes/blocks

echo "^b$bar^ ^c$cpu_ic_fg^^b$cpu_ic_bg^  ^c$cpu_fg^^b$cpu_bg^$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1"%"}') "