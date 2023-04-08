#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Ordinary : public Person {
private:
	string key;
public:

	Ordinary(const string& theKey, const string& theName, const string& thePhoneNum, int theDonation);

	string getKey() const;
	
	void printCheck();

	string information() const;

};