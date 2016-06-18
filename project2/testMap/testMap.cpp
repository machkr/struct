#include <iostream>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

unsigned int hashFunc(string const &key, int size)
{
	unsigned long n = 1;
	for (string::const_iterator it = key.begin(); it != key.end(); it++) {
		n = (1103515245 * (n + (*it)) + 12345) % 4294967296; 
	}
	return (unsigned int)(n % size);
}

int main(int argc, char**argv) {
	ifstream inFile("lastNames.txt");

	while(inFile.good() ) {
		string line;
		getline(inFile, line);
		unsigned int h = hashFunc(line,stoi(argv[1]));
		cout << h << endl;

	}

}
