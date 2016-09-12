#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "DynMap.h"

void insert(DynMap<string,string>* map, string keyFileName, string valFileName) {
	ifstream keyFile(keyFileName);
	ifstream valFile(valFileName);
	
	int i = 0;
	while(keyFile.good() && valFile.good()) {

		clock_t t;

		string key;
		string val;

		getline(keyFile, key);
		getline(valFile, val);

		t = clock();
		map->insert(key,val);
		t = clock() - t;
		
		i++;
		cout << i << "\t" << t << endl;
	}
}

void access(DynMap<string,string>* map, string keyFileName) {
	ifstream keyFile(keyFileName);
	
	int i = 0;
	while(keyFile.good()) {

		clock_t t;

		string key;
		string val;

		getline(keyFile, key);

		t = clock();
		val = map->search(key);
		t = clock() - t;

		i++;
		cout << i << "\t" << t << endl;
	}
}

int main(int argc, char**argv) {
	double loadFactor = 0.8;
	DynMap<string,string> * map = new DynMap<string,string>(loadFactor);

	string keyFileName = "lastNames.txt";
	string valFileName = "lastNames.txt";

	cout << "INSERT:\n";
	insert(map, keyFileName, valFileName);

	cout << "\n\n\n\n\nACCESS:\n";
	access(map, keyFileName);
	return 0;
}


