#include "transposition.h"
#include "functions.h"

int main (int argc, char* argv[]) {
    string text = "", temp;

    if (argc != 2){
        fprintf(stderr, "./<name_of_the_program> <encrypted_file>\n");
        exit (0);
    }

    text = readingFile(argv[1]);

    //int start_s = clock();
    TranspositionBreaker obj;

    for (int i = 1; i <= 8; i++){
        obj.calculatingPermutations(i, text);
    }    

    //int stop_s = clock();
    //cout << endl << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

  return 0;
}