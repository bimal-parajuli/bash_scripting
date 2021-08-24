for i in 1 2 3 4 5
do
    echo $i
done

for i in {1..10}
do
    echo $i
done

for i in Hello wassup How you doin
do
    echo $i
done

# Output:
# Hello
# wassup
# How
# you
# doin

for i in {1..10..3}
do
    echo $i
done

# Output:
# 1
# 4
# 7
# 10
#This may not work in classic bash shell.

for i in $(seq 1 3 10)
do
    echo $i
done

# Output:
# 1
# 4
# 7
# 10
#This works properly in all old and new shell and bash.

for ((i=10; i<=19; i++))
do
    echo $i
done
# Output:
# 10
# 11
# 12
# ...
# 19

#for loop with double braces works in modern bash shell only.

# for i in {1..5}
# do
#     rm  file-$i
# done

# rm filename             #TO rename a file
# rmdir                   #To remove a empty directory
#rm -r folder_or_filename #To remove it forcefully either its a empty folder or not.

mkdir folder
touch folder/myfile.txt
echo wassup > "folder/myfile.txt"
rm -r folder