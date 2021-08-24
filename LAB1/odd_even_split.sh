touch onetohundred.txt
touch odd_file.txt
touch even_file.txt

seq 1 100 > onetohundred.txt

cat onetohundred.txt | while read line

do
	if [`expr $line % 2` == 0]
	then
		echo $line >> even_file.txt
	else
		echo $line >> odd_file.txt
	fi
done

echo for numbers from  1 to 100:
head onetohundred.txt
echo --------------------
tail onetohundred.txt

