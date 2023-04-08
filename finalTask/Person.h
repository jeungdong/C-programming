#pragma once
#include <string>
using namespace std;

class Person {
private:
	string name;
	string phoneNum;
	long donation;
public:
	Person();
	Person(const string& theName, const string& thePhoneNum, int theDonation);
	string getName() const;
	string getPhoneNum() const;
	int getDonation() const;
	void addDonation(int theDonation);
	virtual string getDepartment() const;
	virtual string getKey() const;
	virtual	void printCheck();
	virtual string getExtension() const;
	virtual string information() const;
	
};