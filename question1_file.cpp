#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char caesar( char c );

int main(){

	string line;

	ifstream myfile("fibonacci.asm");

	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
        	string output = "";
        	for(int x = 0; x < line.length(); x++)
        	{
            	output += caesar(line[x]);
        	}
        	cout << output << endl;
    	}
    	myfile.close();
  	}

  	else 
  		cout << "Unable to open file"; 
	return 0;	
}

char caesar( char c )
{
    if( isalpha(c) )
    {
        c = toupper(c); //use upper to keep from having to use two seperate for A..Z a..z
        c = (((c-65)+13) % 26) + 65;
    }
    //if c isn't alpha, just send it back.
    return c;
}
