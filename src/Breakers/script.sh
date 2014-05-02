#!/bin/bash
echo -e "Compiling...\n"

g++ transposition.cpp functions.cpp t_main.cpp -o exec -W -Wall -pedantic -ansi -std=c++11
g++ vigenere.cpp functions.cpp v_main.cpp -o exec2 -W -Wall -pedantic -ansi -std=c++11

echo -e "Usage: ./<name_of_the_program> <filename>\n"
echo -e "Example: ./exec text.txt\n"
