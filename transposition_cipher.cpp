#include <iostream>
#include <cstdlib>
#include <cstring>	
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

using namespace std;

#define DATA_BLOCK 8
#define KEY_SIZE 4

/***************************************************************
* Função que realiza a encriptação por transposição. Trabalha com
* uma chave de tamanho 4, em blocos de 8 bytes cada. Os blocos são
* divididos em 4 substrings de 2 caracteres cada e então transpostas
* em uma nova string.
***************************************************************/

string encryptingDataBlock(string plaintext, int *key){
	string ciphertext = "";
	int index = 0;
	map<int, string> cipherset;

	for (int i = 0; i < KEY_SIZE; i++, index++){
		cipherset[key[i]] = plaintext.substr(index, 2);
		index++;
	}

	for (int i = 1; i <= KEY_SIZE; i++){
		ciphertext += cipherset.find(i)-> second;
	}

	return ciphertext;
}

/***************************************************************
* Função que "converte" a chave em formato string para inteiro.
* Esta função verifica qual a ordem das letras que compõem a chave
* e retorna um array de inteiros com as 4 posições calculadas.
* Exemplo: uma chave DCBA, retorna um array preenchido com 4, 3, 2, 1.
***************************************************************/

int *convertingStringKeytoInt(string key){
	int *intKey = new int [KEY_SIZE];
	int diff_key;

	memset(intKey, 0, KEY_SIZE);

	for (int i = 0; i < KEY_SIZE; i++){
		diff_key = 1;

		for (int j = 0; j < KEY_SIZE; j++){
			if (key[i] > key[j])
				diff_key++;
			if (key[i] == key[j] && i < j)
				diff_key++;
		}

		intKey[i] = diff_key;
	} 

	return intKey;
}

/***************************************************************/
string encryptingUsingTransposition(string plaintext, string key){
	string ciphertext = "", temp;

	int *intKey = new int [KEY_SIZE];
	unsigned int index = 0;

	while (plaintext.size()%DATA_BLOCK != 0)
		plaintext += " "; 

	while (index != (plaintext.size()/DATA_BLOCK)){
		temp = plaintext.substr(index*DATA_BLOCK, DATA_BLOCK);

		intKey = convertingStringKeytoInt(key);

		ciphertext += encryptingDataBlock(temp, intKey);

		index++;
	}

	cout << "Ciphertext: " << ciphertext << endl;

	return ciphertext;
}

/***************************************************************/

int main (){
	string plaintext, key, cip;

	cin >> plaintext >> key;

	cip = encryptingUsingTransposition(plaintext, key);
	//encryptingUsingTransposition(cip, key);

	return 0;
}