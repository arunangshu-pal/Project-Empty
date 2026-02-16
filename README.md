# Project-Empty
This repository contains the package for the program called "empty". empty is a program to empty text files, i.e. delete the contents of text files.

Installation steps:
1. Download the repository as follows:
   $ git clone https://github.com/arunangshu-pal/Project-Empty
2. Run the install.sh bash script placed inside the "Empty" directory as follows.
   $ cd Empty
   $ sudo chmod +x install.sh    # to make install.sh executable
   $ sudo ./install.sh           # install.sh compiles the source file to create a binary called "empty", and places a symbolic link to the binary in /usr/local/bin directory
3. Installation of the command "empty" is complete. Enjoy!

Usage:
The binary is named "empty". Enter the following in a bash shell to see the help description.
$ empty --help

The program has been built and tested in a Debian 13 Trixie-based system, but it should run in any Linux-based operating system, which has bash, after installing from the source code.

Manual page
-----------
Program Name:
empty - empty text files

Description:
When the program is run with a list of text files as command-line arguments, the files will be emptied, i.e. the contents of the files will be deleted (and the files themselves are not deleted). The usage syntax given below clarifies how the program works. Confirmation is taken from the user for each empty operation (default behaviour); only a response of "yes" will cause a file to be emptied.

Syntax:
$ <executable> [OPTION] [FILE]
[FILE] is a list of text files (separated by blank space(s)) that the program will attempt to empty. If [FILE] is empty, then nothing happens.

For the list of options [OPTION], the following options are available:
-f, --force
      empty the file(s) by force if they exist, never prompt for confirmation

-y    do not prompt for confirmation and assume response as "yes" for all attempts to empty file(s) (essentially same as -f option)

-v, --verbose
      print messages to describe what is happening (by default, no descriptive message is printed, i.e. the program runs silently)

-h, --help
      print this help message and exit, do nothing

Examples:
$ ./empty.out f1 f2 f3
Here, the files f1, f2, f3 will be emptied, i.e. will become blank text files, if user confirms with a response of "yes" for each file.

$ ./empty.out -f -v f1 f2
f1 and f2 will be emptied without any prompt for confirmation, and also messages will be printed to show what happened.

Author:
Written by Arunangshu Pal.
February 2026. India.
