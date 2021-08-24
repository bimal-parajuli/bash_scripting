#simple for loop.

NAMES="Bimal Parajuli"
for x in $NAMES
do
    echo "Hello $x"
done
#Output:
#Hello Bimal
#Hello Parajuli

#FOR LOOP TO RENAME FILES
FILES=$(ls *.txt)
NEW="new"
for FILE in $FILES
    do
        echo "Renaming $FILE to new-$FILE"
        mv $FILE $NEW-$FILE
    done
#Output:
# Renaming 1.txt to new-1.txt
# Renaming 2.txt to new-2.txt
# Renaming 3.txt to new-3.txt
# Renaming save.txt to new-save.txt

#WHILE LOOP - TO READ THROUGH A FILE LINE BY LINE.
LINE=1
while read -r CURRENT_LINE
    do
        echo "$LINE: $CURRENT_LINE"
        ((LINE++))
    done < "./new-1.txt"