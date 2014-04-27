#include <iostream>
#include <string>

#include "vigenere.h"

using namespace std;

int main (int argc, char *argv []){
	string text, key, cip, type;

	if (argc != 4){
		fprintf(stderr, "./<name_of_the_program> <key> <filename> <encrypt/decrypt>\n");
		exit (0);
	}

	key = argv[1];
	type = argv[3];

	if ((type != "decrypt" && type != "encrypt") || key.size() < 8){
		fprintf(stderr, "ERROR: TYPE (third parameter) incorrect or KEY is smaller than 8 characters.\n");
		exit (0);
	}

	Vigenere cipher (key);
	text = cipher.readingFile(argv[2]);

	if (type == "encrypt")
		cip = cipher.encryptingUsingVigenere(text);
	else if(type == "decrypt")
		cip = cipher.decryptingUsingVigenere(text);

	cipher.writingFile(cip, type);
	return 0;
}