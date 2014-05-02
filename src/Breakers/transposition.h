#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include <algorithm>   
#include <vector>
#include <ctime>

#include "functions.h"

#define DICTIONARY_SIZE 4

class TranspositionBreaker {

public:
	void fillingDictionary(vector<string> &, string);
	int findingPatterns (string);
	string decryptingDataBlock(const string, const int *);
	string encryptingUsingTransposition(string, const int *);
	bool verifyingNewKey(string, int*);
	bool calculatingPermutations(int, string);
};

#endif