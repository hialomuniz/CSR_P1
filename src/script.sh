#!/bin/bash
echo -e "Compiling...\name_of_the_program"

g++ transpos.cpp vigenere.cpp functions.cpp main.cpp -o exec -W -Wall -pedantic -ansi

echo -e "Usage: ./<name_of_the_program> <key> <filename> <encrypt/decrypt> <-sub/-transp>\n"
echo -e "Example: ./exec NLCIPHER text.txt encrypt -sub\n"
