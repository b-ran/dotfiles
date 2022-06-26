. ~/.config/themes/blocks

printf "^c$blue^^b$black^  "
printf "^c$blue^ $(free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g)"