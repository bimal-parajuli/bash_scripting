#! /usr/bin/bash

#this is a comment.
#Im gonna make a simple echo.

echo Yo buddy.

#variables.
#Conventionally Variables are made upper case. But Lowercase works.
#still, Make Upper case.

NAME="Bimal"


echo "Hi my name is $NAME"
echo "My name is also ${NAME}. LOL"

#Users Input.
read -p "Enter any other name if you want.:  " NAME
echo "Hello $NAME, nice to meet you!"

#IF statement.
#Strictly important! don't forget to keep a space inside the brackets, from both sides of the square.
#otherwise, it's gonna throw a random error. like comman not found... :(


if [ ${NAME} == "Bimal" ]
then
    echo "You are Bimal, Fine"
elif [ $NAME == "bimal" ]
then
    echo "You are Bimal, fine. "
else
    echo "You are not Bimal, You are $NAME leave the laptop, You imposter."
fi 

if [ 5 -ne 6 ]
then 
    echo "5 not equal to 6. Obviously."
else
    echo "Hi, I'm computer and I'm mad. I need to see a doctor."
fi

NUM1=5
NUM2=10
if [ "$NUM1" -gt "$NUM2" ]
then
    echo "$NUM1" is greater than {$NUM2}
else
    echo $NUM2 is greater than $NUM1
fi

# -eq ===> equal to
# -ne ===> not equal to
# -gt ===> greater than
# -lt ===> less than
# -ge ===> greater than or equal to
# -le ===> less than or equal to

