#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const string& theStudentKey, const string& theName, const string& theDepartment,
	const string& thePhoneNum, int theDonation) : Person(theName, thePhoneNum, theDonation) {
	studentKey = theStudentKey;
	department = theDepartment;
}

string Student::getKey() const {
	return studentKey;
}

string Student::getDepartment() const {
	return department;
}
string  Student::information() const {
	string information = "";
	return (information += "학생 " + getKey() + " " + getName() + " "
		+ getDepartment() + " " + getPhoneNum() + " " + to_string(getDonation()) );
}
void Student::printCheck() {
	cout << "[ 학생 ] " << getName() << "(학번:" << getKey() << ", 학과:" << getDepartment() << ") "
		<< getPhoneNum() << " " << getDonation() <<endl;
}