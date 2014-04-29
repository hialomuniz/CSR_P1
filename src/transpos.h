#ifndef TRANSPOS_H
#define TRANSPOS_H

#include <iostream>
#include <cstdlib>
#include <cstring>	
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

#include "functions.h"

using namespace std;

class Transposition{
public:
	string key;

	Transposition(string key){
		if (key.size() > KEY_SIZE)
			this->key = shrinkingKeytoLength(key, KEY_SIZE);
		else
			this->key = key;
	}

string encryptingDataBlock(const string, const int *);
string decryptingDataBlock(const string, const int *);
string encryptingUsingTransposition(string, const string, const string);

};

#endif
