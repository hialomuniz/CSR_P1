#include "vigenere.h" 

/*****************************************************************/

bool comparing(const pair<char, double>& a1, const pair<char, double>& a2) {
    return a2.second > a1.second;
}

/*****************************************************************/

FreqArray& VigenereBreaker::gettingInputFrequency(const string& input) {
    for (char c = 'A'; c <= 'Z'; ++c)
      freq[c - 'A'] = make_pair(c, 0);
 
    for (size_t i = 0; i < input.size(); ++i)
      freq[input[i] - 'A'].second++;
 
    return freq;
}

/*****************************************************************/
 
double VigenereBreaker::gettingCoefficient(const string& input) {
    double result = 0.0;
    gettingInputFrequency(input);

    sort(freq.begin(), freq.end(), comparing);
 
    for (size_t i = 0; i < 26; ++i)
      result += freq[i].second * sortedTargets[i];
 
    return result;
  }

/*****************************************************************/
 
int VigenereBreaker::gettingKeyLength(string input) {
    string ciphertext;
    unsigned int bestLength = 0;
    double bestIC = INIT;

    for (unsigned int i = 0; i < input.size(); ++i)
        ciphertext += input[i];
 
    for (unsigned int i = 2; i < ciphertext.size() / MAX_KEY_LENGTH; ++i) {
      vector<string> substrs(i);

      for (unsigned int j = 0; j < ciphertext.size(); ++j)
        substrs[j % i] += ciphertext[j];

      double actualIC = -0.5 * i;
      //double actualIC = 0.0;

      for (unsigned int j = 0; j < i; ++j)
        actualIC += gettingCoefficient(substrs[j]);

      actualIC /= 26;

      //cout << actualIC << endl; 

      if (actualIC > bestIC) {
        bestLength = i;
        bestIC = actualIC;
      }
    }
 
    if (bestLength == 0)
        cout << "ERROR: Length not found." << endl; 

    return bestLength;
  }

/***********************************************************/

string VigenereBreaker::breakingUsingKeyLength(string input, unsigned int length){
    string key = "";
    string result = "";
    vector<string> substrs(length);
    vector<FreqArray> freqs;

    for (unsigned int i = 0; i < input.size(); ++i)
      substrs[i % length] += input[i];
    
    for (unsigned int i = 0; i < length; ++i)
      freqs.push_back(gettingInputFrequency(substrs[i]));

    for (unsigned int i = 0; i < length; ++i) {
      sort(freqs[i].begin(), freqs[i].end(), comparing);
 
      unsigned int rotations = 0;
      double mCorr = 0.0;

      for (unsigned int j = 0; j < 26; ++j) {
        double corr = 0.0;
        char c = 'A' + j;

        for (unsigned int k = 0; k < 26; ++k){
          int index = (freqs[i][k].first - c + 26) % 26;
          corr += freqs[i][k].second * targets[index];
        }
 
        if (corr > mCorr){
          rotations = j;
          mCorr = corr;
        }
      }
 
      key += 'A' + rotations;
    }

    for (unsigned int i = 0; i < input.size(); ++i)
      result += (input[i] - key[i % key.length()] + 26) % 26 + 'A';
 
    return key;
}

/***********************************************************/

string VigenereBreaker::decryptingUsingVigenere(string ciphertext, string key){
  string plaintext = "";
  char temp, rt;
  int index = 0;

  cout << "Decrypting using substitution..." << endl;

  for (unsigned int i = 0; i < ciphertext.size(); i++){
    temp = ciphertext[i];
    rt = key[index];

    plaintext += (temp - rt + 26) % 26 + 'A';  

    index = (index + 1) % key.length();       
    
  }

  cout << "Done." << endl;

  return plaintext;

}