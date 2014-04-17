#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

char caesarCipher (char c, int key)
{
	if(isalpha(c)){
		c = (((c-65)-key) % 26);
		if (c < 0){
			c = 91 + c;
		}
		else {
			c = c + 65;
		}
	}
	return c;
}


void decryptingFileUsingCaesar(int key, char* filepath){

	ifstream myfile(filepath);

	ofstream file_output;
	file_output.open ("output_decrypt");

	string input, output;

	if (myfile.is_open()){
		while (getline (myfile, input)){
			output = "";

		for(unsigned int x = 0; x < input.length(); x++) {
	            output += caesarCipher(input[x], key);
	        }
		
		file_output << output << "\n";
		}
		file_output.close();
		myfile.close();
	}

	else
		cout << "Unable to open file." << endl;

}

/***************************************/

int main (int argc, char *argv []){

	if (argc != 3){
		//cout << "./name_of_the_program key filename\n"; 
		fprintf(stderr, "./<name_of_the_program> <key> <filename>\n");
		exit (0);
	}

	int key = atoi (argv[1]);

	decryptingFileUsingCaesar(key, argv[2]);

	return 0;
}
