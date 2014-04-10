#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

char caesarCipher (char c, int key)
{
    if(isalpha(c)) {
        c = toupper(c); 
        c = (((c-65)+key) % 26) + 65;
    }

    return c;
}

/***************************************/

int main (int argc, char *argv []){

	if (argc < 3){
		cout << "./name_of_the_program key filename\n\n"; 
	}

	ifstream myfile(argv[2]);

	int key = atoi (argv[1]);

	string input, output;

	if (myfile.is_open()){
		while (getline (myfile, input)){
			output = "";

			for(int x = 0; x < input.length(); x++) {
	            output += caesarCipher(input[x], key);
	        }

	        cout << output << endl;
		}
		myfile.close();
	}

	else

		cout << "Unable to open file." << endl;

	return 0;
}