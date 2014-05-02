#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

#include "functions.h"

using namespace std;

#define MAX_KEY_LENGTH 20
#define INIT -100.0
 
typedef array <pair<char, double>, 26> FreqArray;

class VigenereBreaker {
public:
  vector<double> targets;
  vector<double> sortedTargets;
  FreqArray freq;

  VigenereBreaker(const vector<double>& targetFreqs) {
    targets = targetFreqs;
    sortedTargets = targets;
    sort(sortedTargets.begin(), sortedTargets.end());
  }

FreqArray& gettingInputFrequency(const string&);
double gettingCoefficient(const string&);
int gettingKeyLength(string); 
string breakingUsingKeyLength(string, unsigned int); 
string decryptingUsingVigenere(string, string);

};
 
#endif