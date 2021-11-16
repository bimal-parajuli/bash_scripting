#! /bin/bash

cat Names.txt | while read reg_no      #read the file and store each line in a variable

do
    mkdir $reg_no                      #make a folder for every registration number.
    
    cd $reg_no                         #move into that folder.
    
    touch $reg_no.sh                   #make a new bash file inside that folder named corresponding Reg. No.
    
    echo "#!/bin/bash" >> $reg_no.sh   #Append shebang line in the bash file.
    
    echo "echo $reg_no" >> $reg_no.sh  #Append a echo line to print reg no in that bash file.
    
    chmod 777 $reg_no.sh               #make the bash file executable 
    
    ./$reg_no.sh                       #execute that bash file
    
    cd ..                              #move out of that folder
done


echo "================================================"
echo "Files and folders list for verification:"
    
ls  *                                  #display all directories and its files.
