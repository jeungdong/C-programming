#pragma once
#include "Person.h"

class Student : public Person {
private:
	string department;
	string studentKey;

public:
	Student(const string& studentKey, const string& theName, const string& department,
		const string& thePhoneNum, int theDonation);

	string getKey() const;
	string getDepartment() const;
	void printCheck();
	string information() const;
};