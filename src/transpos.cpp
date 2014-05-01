#include "transpos.h"
#include "functions.h"

/***************************************************************
* TODO: Função para recalcular uma chave de tamanho variável.
* Função de desincriptação: basta criar uma cópia da encryptingDataBlock()?
***************************************************************/

/***************************************************************
* Função que realiza a encriptação por transposição. Trabalha com
* uma chave de tamanho 4, em blocos de 8 caracteres cada. Os blocos são
* divididos em 4 substrings de 2 caracteres cada e então transpostas
* em uma nova string.
***************************************************************/

string Transposition::encryptingDataBlock(const string plaintext, const int *key){
	string ciphertext = "", temp;
	map<int, string> cipherset;

	int size = plaintext.size()/KEY_SIZE;

	for (int i = 0; i < KEY_SIZE; i++){
		temp = "";

		for (int j = 0; j < size; j++){
			temp += plaintext[(j*KEY_SIZE)+i];
		}

		cipherset[key[i]] = temp;
	}

	for (int i = 1; i <= KEY_SIZE; i++){
		ciphertext += cipherset.find(i)-> second;
	}

	cipherset.clear();
	return ciphertext;
}

/***************************************************************/

string Transposition::decryptingDataBlock(const string ciphertext, const int *key){
	string plaintext = "", temp;

	int size = ciphertext.size()/KEY_SIZE;

	for (int i = 0; i < KEY_SIZE; i++){
		temp = "";

		for (int j = 0; j < size; j++){
			temp += ciphertext[((key[j]-1)*KEY_SIZE)+i];
		}

		plaintext += temp;
	}

	return plaintext;
}

/***************************************************************
* Função que realiza a encriptação do texto. Recebe o texto inteiro
* em formato string, e divide a mesma em blocos de 8 caracteres, que
* são encriptados pela função encryptingDataBlock(). Retorna uma str
* com o texto completo encriptado.
***************************************************************/

string Transposition::encryptingUsingTransposition(string plaintext, const string key, const string type){
	string ciphertext = "", temp = key;
	
	int *intKey = new int [KEY_SIZE];
	unsigned int index = 0;

	while (plaintext.size()%DATA_BLOCK != 0)
		plaintext += " "; 

	//cout << plaintext.size() << endl;

	cout << "Working..." << endl;

	intKey = convertingStringKeytoInt(temp);

	while (index != (plaintext.size()/DATA_BLOCK)){

		temp = plaintext.substr(index*DATA_BLOCK, DATA_BLOCK);

		if (type == "decrypt")
			ciphertext += decryptingDataBlock(temp, intKey);

		if (type == "encrypt")
			ciphertext += encryptingDataBlock(temp, intKey);

		index++;
	}

	if (plaintext.size() > index*DATA_BLOCK){
		temp = plaintext.substr(index*DATA_BLOCK, std::string::npos);

		if (type == "decrypt")
			ciphertext += decryptingDataBlock(temp, intKey);

		if (type == "encrypt")
			ciphertext += encryptingDataBlock(temp, intKey);
	}

	cout << "Done." << endl;

	return ciphertext;
}
