#!/bin/bash
. ~/.config/themes/blocks

echo "^b#1e222a^ ^c#abb2bf^^c#abb2bf^ $(uptime --pretty | sed -e 's/up //g' -e 's/ days/d/g' -e 's/ day/d/g' -e 's/ hours/h/g' -e 's/ hour/h/g' -e 's/ minutes/m /g' -e 's/, / /g')"
