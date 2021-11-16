touch c_files.txt     #Creating three new files in working directory
touch txt_files.txt
touch sh_files.txt


# Writing initial line of each files
echo " ---Files having extension .c---" > c_files.txt
echo " ---Files having extension .txt ---" > txt_files.txt
echo " ---Files having extension .sh ---" > sh_files.txt

for filename in `ls $search`; #Looping through all the filenames in working directory and saving their names in a variable.
do
        if [[ $filename == *.txt ]]           #if it is .txt file, redirect it to txt_files.txt
        then
            echo $filename >> txt_files.txt
        elif [[ $filename == *.c ]]            #if it is .c file, redirect it to c_files.txt
        then
            echo $filename >> c_files.txt
        elif [[ $filename == *.sh ]]           #if it is .sh file, redirect it to sh_files.txt
        then
            echo $filename >> sh_files.txt
        fi
done

ls -l *                               #List all the files, directories and subdirectories in working directories

echo ===============================
echo    
head sh_files.txt
echo ===============================
echo    
head txt_files.txt
echo ===============================
echo    
head c_files.txt
echo ===============================
echo    


echo finished
