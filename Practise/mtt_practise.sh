#!/bin/bash

echo "whatever"
echo "IDK what is this" 

valid=true
count=1
        # while [ $valid ]
        # do
        # echo $count
        # if [ $count -eq 5 ]
        # then
        # break
        # fi
        # ((count++))
        # done

for (( counter=10; counter>0; counter-- ))
do
echo -n "$counter"
if [ $(( counter%2)) -eq 0 ]
then
echo "It is even."
fi
done
printf  "\n"






