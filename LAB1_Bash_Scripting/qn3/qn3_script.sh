#! /bin/bash
echo -n "Enter a 5-digit number: " 
read A                                  #Get a 5 digit number as input from the user.


second_digit="${A:1:1}"
echo Second Digit: $second_digit        #Extract the 2nd digit from that number.


counter=0
for ((i=0; i<5; i++))
do
each_digit=${A:i:1}
if [[ $second_digit = $each_digit ]]   #Loop through and check if each digit equals to 2nd digit.
    then
    counter=$((counter+1))
    fi
done

echo Number of Occurrences of $second_digit is: $counter