#ifndef TRANSPOS_H
#define TRANSPOS_H

#include <iostream>
#include <cstdlib>
#include <cstring>	
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

#define DATA_BLOCK 64
#define KEY_SIZE 8
#define PRIME 31
#define UPPER 65

using namespace std;

string encryptingDataBlock(const string plaintext, const int *key);
int *convertingStringKeytoInt(const string key);
string encryptingUsingTransposition(string plaintext, const string key, const string type);
string readingFile(const char* filepath);
void writingFile (const string text, string type);
string shrinkingKeytoLength(string key, unsigned int size);

#endif
