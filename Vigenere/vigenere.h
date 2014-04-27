#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <cstdlib>
#include <cstring>	
#include <string>
#include <fstream>

using namespace std;

class Vigenere{
public:
	string key;

	Vigenere (string key){
		for (unsigned int i = 0; i < key.size(); i++){
			if (key[i] >= 'A' && key[i] <= 'Z')
				this->key += key[i];
			else if (key[i] >= 'a' && key[i] <= 'z')
				this->key += key[i] + 'A' - 'a';
		}
	}

	string encryptingUsingVigenere(string);
	string decryptingUsingVigenere(string);
	string readingFile(const char*);
	void writingFile (const string, string);


};

#endif