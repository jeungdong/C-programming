#pragma once
#include <string>
#include "MyList.h"
using namespace std;
class Manager {
private: 
	MyList* mylist;
	const static int NUM_ZERO = 5;
	int maxKeyValue = 0;
public:
	Manager();
	void loadFile(char* argv[]);
	void menu();
	void saveFile(char* argv[]);
	string makeKey();
	vector<string> split(string input, char delimiter);
	
};