#include "functions.h"

string readingFile(const char* filepath){
	string text = "";
	string temp;

	ifstream file(filepath);

	if (file.is_open()){
		cout << "Reading file..." << endl;
		
		while (getline (file, temp)){
			text += temp;
			//text.push_back('\n');
			//text += "\n";
		}

		//text.pop_back();
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

	cout << "new key: " << key << endl;
	return key;
}
