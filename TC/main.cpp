#include "transpos.h"

using namespace std;

/***************************************************************/

int main (int argc, char *argv []){
	string plaintext, key, cip, type;

	if (argc != 4){
		fprintf(stderr, "./<name_of_the_program> <key> <filename> <encrypt/decrypt>\n");
		exit (0);
	}

	key = argv[1];
	type = argv[3];

	if ((type != "decrypt" && type != "encrypt") || key.size() < 8){
		fprintf(stderr, "ERROR: TYPE (third parameter) incorrect or KEY is smaller than 8 characters.\n");
		exit (0);
	}

	plaintext = readingFile(argv[2]);

	cip = encryptingUsingTransposition(plaintext, key, type);

	writingFile(cip, type);

	return 0;
}
