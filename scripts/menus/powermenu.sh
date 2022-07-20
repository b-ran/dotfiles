#!/bin/bash

shutdown() {
    echo "Shutting down..."
#    systemctl poweroff
}

reboot() {
    echo "Rebooting..."
#    systemctl reboot
}

lock() {
    echo "Locking..."
}

suspend() {
    echo "Suspending..."
#    systemctl suspend
}

logout() {
    echo "Logging out..."
#    systemctl restart ly.service
}

get_options() {
  echo -en "Shutdown\0icon\x1fsystem-shutdown\n"
  echo -en "Reboot\0icon\x1fsystem-reboot\n"
  echo -en "Lock\0icon\x1fsystem-lock-screen\n"
  echo -en "Suspend\0icon\x1fsystem-suspend\n"
  echo -en "Logout\0icon\x1fsystem-log-out\n"
}

if [ x"$*" = x"Shutdown" ]
then
    shutdown
elif [ x"$*" = x"Reboot" ]
then
    reboot
elif [ x"$*" = x"Lock" ]
then
    lock
elif [ x"$*" = x"Suspend" ]
then
    suspend
elif [ x"$*" = x"Logout" ]
then
    logout
fi

get_options




# rofi -combi-modi "drun,window,Power Menu:scripts/menus/powermenu.sh" -theme .config/themes/rofi.rasi -font "hack 12" -show combi -show-icons -icon-theme "Papirus-Dark" -combi-display-format {text} -display-combi "Run"
# rofi -combi-modi "drun,Power Menu:scripts/menus/powermenu.sh,window" -theme .config/themes/rofi.rasi -font "hack 12" -show combi -show-icons -combi-display-format {text} -display-combi "Run"