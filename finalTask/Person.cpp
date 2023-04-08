#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
	name = "No name yet";
	phoneNum = "NO phoneNumber yet";
	donation = 0;
}
Person::Person(const string& theName, const string& thePhoneNum, int theDonation) {
	name = theName;
	phoneNum = thePhoneNum;
	donation = theDonation;
}
string Person::getName() const { 
	return name; 
}
string Person::getPhoneNum() const { 
	return phoneNum; 
}
int Person::getDonation() const { 
	return donation; 
}
string Person::getKey() const { 
	return "NULL";
}
string Person::getDepartment() const {
	return "NULL";
}
void Person::addDonation(int theDonation) { 
	donation = donation + theDonation; 
}

void Person::printCheck() {
	cout << "NULL";
}
string Person::getExtension() const {
	return "NO EXTENSION YET";
}
string Person::information() const {
	return "NULL";
}

