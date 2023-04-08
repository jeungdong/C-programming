#pragma once
#include "Person.h"

class Professor : public Person
{
private:
	string professorKey;
	string department;
	string extension;
public:
	Professor(const string& professorKey, const string& theName, const string& department,
		const string& theExtension, const string& thePhoneNum, int theDonation);
	void printCheck();
	string getKey() const;
	string getExtension() const;
	string getDepartment() const;
	string information() const;

};