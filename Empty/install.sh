#!/bin/bash

echo "Installation of empty: Program to empty text files..."
echo -n "Compiling... "

make

echo "Compilation done."
echo "Installing to /usr/local/bin..."

current=$(pwd)
sudo ln -s $current/empty /usr/local/bin

echo "Installation complete. Done!"
echo "See manual by entering \"empty --help\""
