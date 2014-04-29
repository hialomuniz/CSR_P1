#include "vigenere.h"
#include "transpos.h"
#include "functions.h"

using namespace std;

/***************************************************************/

int main (int argc, char *argv []){
	string text, key, e_text, type, e_cipher;

	if (argc != 5){
		fprintf(stderr, "./<name_of_the_program> <key> <filename> <encrypt/decrypt> <encryption_type>\n");
		exit (0);
	}

	key = argv[1];
	type = argv[3];
	e_cipher = argv[4];

	if ((type != "decrypt" && type != "encrypt") || key.size() < 8 || (e_cipher != "-sub" && e_cipher != "-transp")){
		fprintf(stderr, "ERROR: TYPE (third parameter) incorrect or KEY is smaller than 8 characters or cipher incorrect (-sub or -transp).\n");
		exit (0);
	}

	text = readingFile(argv[2]);

	if (e_cipher == "-transp"){
		Transposition cipher(key);

		e_text = cipher.encryptingUsingTransposition(text, cipher.key, type);
	}

	else {
		Vigenere v_cipher (key);

		if (type == "encrypt"){
			e_text = v_cipher.encryptingUsingVigenere(text);
		}
		
		else if(type == "decrypt"){
			e_text = v_cipher.decryptingUsingVigenere(text);
		}
	}

	writingFile(e_text, type);

	return 0;
}
