#include "functions.h"
#include "transposition.h"

/******************************************************************/

int K_SIZE = 1;
int D_BLOCK = 1;

void TranspositionBreaker::fillingDictionary(vector<string> &dictionary, string filepath){
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

int TranspositionBreaker::findingPatterns (string text){
    int count = 0;

    vector<string> dictionary;

    if (dictionary.empty())
        fillingDictionary(dictionary, "dictionary_file");

    size_t found;

    for (unsigned int i = 0; i < dictionary.size(); i++){
        found = text.find(dictionary[i]);

        if (found != std::string::npos)
            count++;
    }

    return count;
}

/******************************************************************/

string TranspositionBreaker::decryptingDataBlock(const string ciphertext, const int *key){
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

string TranspositionBreaker::encryptingUsingTransposition(string plaintext, const int *key){
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

bool TranspositionBreaker::verifyingNewKey(string text, int* key){
    string ciphertext; 
    int count = 0;

    ciphertext = encryptingUsingTransposition(text, key);
    count = findingPatterns (ciphertext);

    if (count >= DICTIONARY_SIZE){
        cout << "Key found: ";

        for (int i = 0; i < K_SIZE; i++){
            cout << key[i] << " ";
        }

        cout << endl;

        writingFile(ciphertext, "breaked_t");

        return true;  
    }

    return false;
}

/******************************************************************/

bool TranspositionBreaker::calculatingPermutations(int N, string text){
    int *numbers = new int [N];

    K_SIZE = N;
    D_BLOCK = N*N;

    for (int i = 1; i <= N; i++){
        numbers[i - 1] = i;
    }

    sort (numbers, numbers + N);

    do {
        if (verifyingNewKey(text, numbers))
            return true;
    } while (next_permutation(numbers, numbers + N));

    delete[] numbers;

    return false;
}

/***************************************************************/


