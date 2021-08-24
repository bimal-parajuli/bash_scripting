#! /usr/bin/sh

#Case statement in Bash.

read -p "Are you 18 years or above? Y/N  " ANSWER

case $ANSWER in 
    [yY] | [yY][eE][sS])
        echo "You are qualified to vote. :)"
        ;;
    [nN] | [nN][oO])
        echo "Sorry, You're a kiddo. No voting for now. :/"
        ;;
    *)
        echo "Please enter Y/yes or N/no."
esac
