#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <cstdlib>
#include <cstring>	
#include <string>
#include <fstream>
#include <map>

using namespace std;

#define MAX_ROTATIONS 36

class Vigenere{
public:
	string key;
	map<char, int> map_of_characters;
	map<int, char> key_map;

	Vigenere (string key){
		for (unsigned int i = 0; i < key.size(); i++){
			if (key[i] >= 'A' && key[i] <= 'Z')
				this->key += key[i];
			else if (key[i] >= 'a' && key[i] <= 'z')
				this->key += key[i] + 'A' - 'a';
		}

		fillingMap (map_of_characters, key_map);
	}

	string encryptingUsingVigenere(string);
	string decryptingUsingVigenere(string);
	void fillingMap (map<char, int>&, map<int, char>&);

};

#endif