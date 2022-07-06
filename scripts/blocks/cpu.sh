#!/bin/bash
. ~/.config/themes/blocks

echo "^c#3b414d^^b#414753^^c#abb2bf^ ^c#abb2bf^ ^b#414753^ $(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1"%"}') "
