#!/bin/bash

echo "Installation of 'empty': Program to empty text files"
echo "----------------------------------------------------"
echo "Compiling... "

make

echo "Compilation done."
echo "Installing to /usr/local/bin..."

current=$(pwd)
sudo ln -f -s $current/empty /usr/local/bin

echo -e "Installation complete. Done!\n"
echo "See manual by entering \"empty --help\"."
