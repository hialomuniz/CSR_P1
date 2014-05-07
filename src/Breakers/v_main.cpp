#include "vigenere.h"
#include "functions.h"

const vector <double> ic_english = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
    0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
    0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
    0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
    0.01974, 0.00074};

const vector <double> ic_portuguese = {
    0.14634, 0.01043, 0.03882, 0.04992, 0.12570, 0.01023,
    0.01303, 0.00781, 0.06186, 0.00397, 0.00015, 0.02779,
    0.04738, 0.05046, 0.10735, 0.02523, 0.01204, 0.06530,
    0.07805, 0.04736, 0.04634, 0.01665, 0.00037, 0.00253,
    0.00006, 0.00470};

int main (int argc, char* argv[]){
  string input = "";

  if (argc != 2){
        fprintf(stderr, "./<name_of_the_program> <encrypted_file>\n");
        exit (0);
    }

  input = readingFile(argv[1]);
 
  VigenereBreaker obj(ic_english);

  unsigned int length = obj.gettingKeyLength(input);
  string key = obj.breakingUsingKeyLength(input, length);
 
  cout << "Key found: " << key << endl;
  string output = obj.decryptingUsingVigenere(input, key);

  writingFile(output, "breaked_v");
}