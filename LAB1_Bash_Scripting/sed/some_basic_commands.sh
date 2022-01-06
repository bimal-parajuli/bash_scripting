


date
# returns the current date



 date "+  %b %Y %d (%a) %I:%M%p"
# Displays the date in specific format
# start with a +
# %A => daty of week eg: Sunday, Monday
# %a => Day of week in short eg: Sun, Mon, etc..

# %B => Name of the month eg: January, February, etc..
# %b => Name of month in short eg: Jan, Feb, Mer, etc..

# %D => Complete date Eg: 01/02/22, 05/13/99, etc..
# %d => day of the month Eg: 02, 25, 28, etc..

# %p => AM/PM in uppercaps
# %P => am/pm in lower caps

# %Y => Year Eg: 2020, 2021, 2022, etc..
# %y => year in short Eg: 20, 21, 22, etc..

# so on.....

cal
# Current Month's Calendar
cal -3
# 3 months calendar i.e. a month before, this month adn next month.
cal June 248
# Calendar of any month of any year




df
# disk information (free space)
du
# disk information (used space)
df -h
du -h 
# more human readable disk information 
du -h 
# used space(size of files)in a particular folder



ps 
ps -axc
# see the running processes
# various flags available. see man page for more.
pidof pname
# returns the process ID of a currentlly running process.
kill pid
# ends a process by its ID.


top
# live view of running processes.
htop
# more colourful live overview of running processes.


uname
# Flags:: -s -a -p -n -o -r -v -M 


ip addr