#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <cstring>	
#include <string>
#include <fstream>

#define DATA_BLOCK 64
#define KEY_SIZE 8
#define PRIME 31
#define UPPER 65

using namespace std;

string readingFile(const char*);
void writingFile (const string, string);
int *convertingStringKeytoInt(const string key);
string shrinkingKeytoLength(string key, unsigned int size);

#endif

