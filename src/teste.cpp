#include <algorithm>   
#include <vector>
#include <ctime>

#include "functions.h"

#define DICTIONARY_SIZE 3

using namespace std;

int K_SIZE = 1;
int D_BLOCK = 1;

/******************************************************************/

void fillingDictionary(vector<string> &dictionary, string filepath){
    string text;

    ifstream file(filepath.c_str());

    if (file.is_open()){        
        while (file >> text)
            dictionary.push_back(text);

        file.close();
    }

    else {
        fprintf(stderr, "Unable to open file.\n");
        exit (0);
    }

}

/******************************************************************/

int findingPatterns (string text){
    int count = 0;

    vector<string> dictionary;

    if (dictionary.empty())
        fillingDictionary(dictionary, "dictionary_file");

    //const char* args[] = {"cryptography", "security", "data"};
    //vector<string> dictionary (args, args + DICTIONARY_SIZE);

    size_t found;

    for (unsigned int i = 0; i < dictionary.size(); i++){
        found = text.find(dictionary[i]);

        if (found != std::string::npos)
            count++;
    }

    return count;
}

/******************************************************************/

string decryptingDataBlock(const string ciphertext, const int *key){
    string plaintext = "", temp;

    int size = ciphertext.size()/K_SIZE;

    for (int i = 0; i < K_SIZE; i++){
        temp = "";

        for (int j = 0; j < size; j++){
            temp += ciphertext[((key[j]-1)*K_SIZE)+i];
        }

        plaintext += temp;
    }

    return plaintext;
}

/******************************************************************/

string encryptingUsingTransposition(string plaintext, const int *key){
    string ciphertext = "", temp;
    
    unsigned int index = 0;

    while (index != (plaintext.size()/D_BLOCK)){

        temp = plaintext.substr(index*D_BLOCK, D_BLOCK);

        ciphertext += decryptingDataBlock(temp, key);

        index++;
    }

    if (plaintext.size() > index*D_BLOCK){
        temp = plaintext.substr(index*D_BLOCK, std::string::npos);

        ciphertext += decryptingDataBlock(temp, key);
    }

    return ciphertext;
}

/******************************************************************/

bool verifyingNewKey(string text, int* key){
    string ciphertext; 
    int count = 0;

    ciphertext = encryptingUsingTransposition(text, key);
    count = findingPatterns (ciphertext);

    if (count >= 2){
        cout << "Key found: ";

        for (int i = 0; i < K_SIZE; i++){
            cout << key[i] << " ";
        }

        cout << endl;

        writingFile(ciphertext, "breaked");

        return true;  
    }

    return false;
}

/******************************************************************/

bool calculatingPermutations(int N, string text){
    int numbers[N];

    for (int i = 1; i <= N; i++){
        numbers[i - 1] = i;
    }

    sort (numbers, numbers + N);

    do {
        if (verifyingNewKey(text, numbers))
            return true;
    } while (next_permutation(numbers, numbers + N));

    return false;
}

/***************************************************************/

int main (int argc, char* argv[]) {
    string text = "", temp;

    if (argc != 2){
        fprintf(stderr, "./<name_of_the_program> <encrypted_file>\n");
        exit (0);
    }

    text = readingFile(argv[1]);

    //int start_s = clock();

    for (int i = 1; i <= 8; i++){
        K_SIZE = i;
        D_BLOCK = i*i;

        calculatingPermutations(K_SIZE, text);
    }    

    //int stop_s = clock();
    //cout << endl << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

  return 0;
}
