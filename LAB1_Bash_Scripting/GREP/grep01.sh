# Listing the working directory contents.
ls

echo

# Searching the word "This" in file.txt
grep "This" file.txt

echo


# -w to only return the results having matching full words.
grep -w "This" file.txt

echo

# -i to make grep not case sensitive.
grep -i "This" file.txt

echo

# -in Also display the line number of match.
grep -in "This" file.txt

# Flags can be grouped like
# grep -wi, grep -win, etc...


# -B To get an idea about the context of the match by viewing few lines before and after the match.
