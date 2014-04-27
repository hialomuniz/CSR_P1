#include "vigenere.h"

/************************************************************************
* TODO: A cifra transforma todos os caracteres em maísuculos. Pode-se 
* implementar para que ele diferencie maiúsculo de minúsculo e cifre de acordo. 
* A encriptação de valores numéricos (0 - 9) está funcionando, mas a desincriptação
* não. Tem que achar uma lógica para a desincriptação.
************************************************************************/

string Vigenere::encryptingUsingVigenere(string plaintext){
	string ciphertext = "";
	char temp, out;
	int index = 0;

	for (unsigned int i = 0; i < plaintext.size(); i++){
		temp = toupper(plaintext[i]);

		if (isalpha(temp)){
			ciphertext += (temp+key[index] - 2*'A') % 26 + 'A';
		}
		else if (temp >= '0' && temp <= '9'){
			out = ((temp + key[index]) - ('A' + '0'));

			if (out > 9)
				ciphertext += 'A' + (out - 10);
			else
				ciphertext += '0' + out;
		}
		else
			ciphertext += temp; 
			
		index = (index + 1) % key.length();
	}
	return ciphertext;
}

/************************************************************************
*
*
************************************************************************/
string Vigenere::decryptingUsingVigenere(string ciphertext){
	string plaintext = "";
	char temp;
	//char out;
	int index = 0;

	for (unsigned int i = 0; i < ciphertext.size(); i++){
		temp = ciphertext[i];
		//out = key[index] - 'A'; //number of rotations

		if (isalpha(temp))
			plaintext += (temp - key[index] + 26) % 26 + 'A';
		else
			plaintext += temp;

		/*if ((temp - out) >= 'A')
			plaintext += (temp - key[index] + 26) % 26 + 'A';
		else if (isalpha(temp) && (temp - out) < 'A')
			plaintext += (temp - key[index]) + ':';
		else if (temp >= '0' && temp <= '9')
			plaintext += (temp - key[index]) + 'A';
		else
			plaintext += temp; // codigo a arrumar */

		index = (index + 1) % key.length();

	}	
	return plaintext;

}

string Vigenere::readingFile(const char* filepath){
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

void Vigenere::writingFile (const string text, string type){
	ofstream output;
	type += "_file";

	const char* filepath = type.c_str();

	output.open (filepath);

	output << text;

	output.close();
}
