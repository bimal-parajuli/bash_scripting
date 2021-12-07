#! /bin/bash

#array of string to store the wordws of sentence.
sentence=() 

#Loop until done is found.
while [ 1 ];
do

    # read input from the user and store it as word.
    read word
    
    #if word is done, break the loop.
    if [ $word = "done" ]
    then
        break;
    fi
    
    #ammend the word to the sentence array.
    sentence+=($word)
done

#Counting the total number of words in the sentence array.
word_count=${#sentence[@]}  

#display the number of words.
echo $word_count


# checking whether the word count is odd or even.
if [ $(($(($word_count))%2)) -eq 0 ]
then
    center=$(($word_count / 2))
    center=$(($center - 1))
else
    center=$(($word_count / 2))
fi

#extracting the middle onr from the string.
middle_string=${sentence[$center]}

# Displaying the middle one.
echo ${middle_string}

