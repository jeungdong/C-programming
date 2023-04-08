#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(const string& theProfessorKey, const string& theName, const string& theDepartment,
	const string& theExtension, const string& thePhoneNum, int theDonation) : Person(theName, thePhoneNum, theDonation)
{
	professorKey = theProfessorKey;
	department = theDepartment;
	extension = theExtension;
};

string Professor::getKey() const {
	return professorKey;
}

string Professor::getExtension() const {
	return extension;
}

string Professor::getDepartment() const {
	return department;
}

string Professor::information() const {
	string information = "";
	return(information += "교직원 " + getKey() + " " + getName() + " "
		+ getDepartment() + " " + getPhoneNum() + " " + getExtension() + " "
		+ to_string(getDonation()) );
}

void Professor::printCheck() {
	cout << "[교직원] " << getName() << "(사번:" << getKey() << ", 부서:" << getDepartment() << "(x"
		<< getExtension() << ")) " << getPhoneNum() << " " << getDonation() <<endl;
}