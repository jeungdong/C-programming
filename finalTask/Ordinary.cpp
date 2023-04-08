#include "Ordinary.h"
#include <iostream>
#include <string>
using namespace std;


Ordinary::Ordinary(const string& theKey, const string& theName, const string& thePhoneNum, int theDonation)
	: Person(theName, thePhoneNum, theDonation)
{
	key = theKey;
}


string Ordinary::getKey() const { return key; }

string Ordinary:: information() const {
	string information = "";
	return (information +=  "�Ϲ� " + getKey() + " " + getName() + " "
		+ getPhoneNum() + " " + to_string(getDonation()));
}

void Ordinary::printCheck() {
	cout << "[ �Ϲ� ] " << getName() << "(��Ź���ڵ�:" << getKey() << ") " << getPhoneNum() << " "
		<< getDonation() <<endl;
}