#include "vigenere.h"

void Vigenere::fillingMap(map<char, int> &map_of_characters, map<int, char> &key_map){
	int index = 0;

	for (int i = 0; i < 26; i++, index++){
		map_of_characters.insert(std::pair<char, int> (('A' + i), index));
		key_map.insert(std::pair<int, char> (index, ('A' + i)));
	}

}

/************************************************************************
* TODO: A cifra transforma todos os caracteres em maísuculos. Pode-se 
* implementar para que ele diferencie maiúsculo de minúsculo e cifre de acordo. 
* A encriptação de valores numéricos (0 - 9) está funcionando, mas a desincriptação
* não. Tem que achar uma lógica para a desincriptação.
************************************************************************/


string Vigenere::encryptingUsingVigenere(string plaintext){
	string ciphertext = "";
	char temp, rt;
	int index = 0, t1, t2;

	cout << "Encrypting using substitution..." << endl;

	for (unsigned int i = 0; i < plaintext.size(); i++){
		temp = toupper(plaintext[i]);
		rt = key[index];

		if (isalpha(temp)){
			t1 = map_of_characters.find(temp)->second;
			t2 = map_of_characters.find(rt)->second;

			if ((t1+t2) > MAX_ROTATIONS)
				ciphertext += key_map.find((t1 + t2) - (MAX_ROTATIONS + 1))->second;
			else
				ciphertext += key_map.find(t1 + t2)->second;	

			index = (index + 1) % key.length();			 			
		}

		
	}

	cout << "Done." << endl;

	return ciphertext;
}

/************************************************************************
*
*
************************************************************************/
string Vigenere::decryptingUsingVigenere(string ciphertext){
	string plaintext = "";
	char temp, rt;
	int index = 0, d1, d2;

	cout << "Decrypting using substitution..." << endl;

	for (unsigned int i = 0; i < ciphertext.size(); i++){
		temp = ciphertext[i];
		rt = key[index];

		if (isalpha(temp)){
			d1 = map_of_characters.find(temp)->second;
			d2 = map_of_characters.find(rt)->second;

			if (d1 < d2)
				plaintext += key_map.find(d1 + (MAX_ROTATIONS + 1 - d2))->second;
			else 
				plaintext += key_map.find(d1 - d2)->second;		

			index = (index + 1) % key.length(); 			
		}
	}

	cout << "Done." << endl;

	return plaintext;

}

