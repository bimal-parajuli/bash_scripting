#WHILE LOOP - TO READ THROUGH A FILE LINE BY LINE.
#We have a file called new-new-1 which has 20 lines of lorem ipsum text as lists.

LINE=1
while read -r CURRENT_LINE
    do
        echo "$LINE: $CURRENT_LINE"
        ((LINE++))
    done < "./new-new-1.txt"