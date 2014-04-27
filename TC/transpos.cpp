#include "transpos.h"

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

string encryptingDataBlock(const string plaintext, const int *key){
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

string decryptingDataBlock(const string ciphertext, const int *key){
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
* Função que recebe uma chave de tamanho variável e a transforma
* em uma chave de tamanho fixo (size). Neste sistema, por padrão
* a chave é transformada em uma de 8 caracteres (KEY_SIZE).
**************************************************************/

string shrinkingKeytoLength(string key, unsigned int size){
	char temp;
	unsigned int i = 0;

	while (key.size() != size){
		temp = ((key[i] + key[key.size() - 1]) + PRIME) % 26;

		temp += UPPER;

		key[i] = temp;
		key.erase(key.size() - 1);

		i++;

		if (i >= key.size())
			i = 0;
	}

	return key;
}

/***************************************************************
* Função que "converte" a chave em formato string para inteiro.
* Esta função verifica qual a ordem das letras que compõem a chave
* e retorna um array de inteiros com as 4 posições calculadas.
* Exemplo: uma chave DCBA, retorna um array preenchido com 4, 3, 2, 1.
***************************************************************/

int *convertingStringKeytoInt(const string key){
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

/***************************************************************
* Função que realiza a encriptação do texto. Recebe o texto inteiro
* em formato string, e divide a mesma em blocos de 8 caracteres, que
* são encriptados pela função encryptingDataBlock(). Retorna uma str
* com o texto completo encriptado.
***************************************************************/

string encryptingUsingTransposition(string plaintext, const string key, const string type){
	string ciphertext = "", temp = key;

	int *intKey = new int [KEY_SIZE];
	unsigned int index = 0;

	while (plaintext.size()%KEY_SIZE != 0)
		plaintext += " "; 

	cout << "Working..." << endl;

	temp = shrinkingKeytoLength(temp, KEY_SIZE);
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

/**************************************************************
* Função de leitura do arquivo, contendo o texto em claro.
***************************************************************/

string readingFile(const char* filepath){
	string text = "";
	string temp;

	ifstream file(filepath);

	if (file.is_open()){
		cout << "Reading file..." << endl;
		
		while (getline (file, temp)){
			text += temp;
			text += "\n";
		}

		file.close();
	}

	else {
		fprintf(stderr, "Unable to open file.\n");
		exit (0);
	}

	return text;
}

/**************************************************************
* Função de escrita do texto cifrado em arquivo.
***************************************************************/

void writingFile (const string text, string type){
	ofstream output;
	type += "_file";

	const char* filepath = type.c_str();

	output.open (filepath);

	output << text;

	output.close();
}


