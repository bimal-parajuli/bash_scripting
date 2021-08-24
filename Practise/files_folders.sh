touch c_files.txt   #Creating three new files in 
touch txt_files.txt
touch sh_files.txt

echo " ---Files having extension .c---" > c_files.txt
echo " ---Files having extension .txt ---" > txt_files.txt
echo " ---Files having extension .sh ---" > sh_files.txt

for entry in `ls $search`; do
        if [[ $entry == *.txt ]]
        then
            echo $entry >> txt_files.txt
        elif [[ $file == *.c ]]
        then
            echo $entry >> c_files.txt
        elif [[ $file == *.sh ]]
        then
            echo $entry >> sh_files.txt
        fi

done

ls -l *

echo ===============
head sh_files.txt
echo ================
echo    
head txt_files.txt
echo ===============
echo    
head c_files.txt
echo ===============
echo    


echo finished
