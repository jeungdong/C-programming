#include "Person.h"
#include "MyList.h"
#include "Manager.h"
#include "Ordinary.h"
#include "Professor.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <locale>
#include <typeinfo>

using namespace std;

Manager::Manager() {
	mylist = new MyList();
};

void Manager::loadFile(char* argv[]) {

	ifstream inStream;
	inStream.open(argv[1], ios::in);
	string str;
	vector<string> Info;
	if (!inStream.is_open()) {
		cout << argv[1] << "을 열 수 없습니다." << endl;
	}
	else {
		cout << "------- 기탁현황 -------" << endl;
		while (getline(inStream, str)) {
			Info = split(str, ' ');
			if (Info[0] == ( "학생")) {
				Person* s = new Student(Info[1], Info[2], Info[3], Info[4], stoi(Info[5]));
				mylist->insert(s);
			}
			else if (Info[0] == "교직원") {
				Person* p = new Professor(Info[1], Info[2], Info[3], Info[4], Info[5], stoi(Info[6]));
				mylist->insert(p);
			}
			else if (Info[0] == "일반") {
				Person* o = new Ordinary(Info[1], Info[2], Info[3], stoi(Info[4]));
				mylist->insert(o);
				int myKey = stoi(Info[1].substr(1, string::npos));
				if (maxKeyValue < myKey) {
					maxKeyValue = myKey;
				}
			}
			else {
				cout << "존재하지 않는 타입입니다.";
			};
		}
		mylist->show();
	}
	cout << endl;
	inStream.close();
}

void Manager::menu() {
	int menu;

	while (1)
	{

		cout << "[1] 전체 조회 / [2] 신규 기탁자 등록 / [3] 기탁정보 변경 / [4] 기탁자 삭제 / [5] 종료 : ";
		cin >> menu;

		if (menu == 5) { break; }
		switch (menu) 
		{

			case 1:
				mylist->show();
				break;

			case 2:
			{
				string str;
				vector<string> Info;
				cout << "신규 기탁자 정보를 입력하세요: ";
				cin.ignore();
				getline(cin, str);
				Info = split(str, ' ');

				if (Info[0] == "학생") {
					Person* p = new Student(Info[1], Info[2], Info[3], Info[4], stoi(Info[5]));
					if (!mylist->isExist(p)) {
						mylist->insert(p);
						cout << "<신규>";
						p->printCheck();
					}
					cout << endl;
				}
				else if (Info[0] == "교직원") {
					Person* p = new Professor(Info[1], Info[2], Info[3], Info[4], Info[5], stoi(Info[6]));
					if (!mylist->isExist(p)) {
						mylist->insert(p);
						cout << "<신규>";
						p->printCheck();
					}
					cout << endl;
				}
				else if (Info[0] == "일반") {
					string key = makeKey();
					Person* p = new Ordinary(key, Info[1], Info[2], stoi(Info[3]));
					if (!mylist->isExist(p)) {
						mylist->insert(p);
						cout << "<신규>";
						p->printCheck();
						maxKeyValue++;
					}
					cout << endl;
				}	
				else {
					cout << "존재하지 않는 타입입니다." << endl;
				}
				break;
			}

			case 3:
			{
				string datum;
				int theDonation;
				cout << "변경을 원하는 사번이나 학번 또는 전화번호(XXX-XXXX-XXXX)를 입력하세요 : ";
				cin >> datum;
				cout << "추가 기탁액을 입력하세요 : ";
				cin >> theDonation;
				mylist->change(datum, theDonation);
				mylist->sort(datum);
				break;
			}
			case 4:
			{
				string datum;
				cout << "삭제를 원하는 사번이나 학번 또는 전화번호(XXX - XXXX - XXXX)를 입력하세요 : ";
				cin >> datum;
				Node* removed = mylist->remove(datum);
				if (removed != NULL)
				{
					cout << "[삭제]";
					removed->getData()->printCheck();
					cout << endl;
					if (removed->getData()->getKey()[0] == 'V') {
						int removedKey = stoi(removed->getData()->getKey().substr(1, string::npos));
						if (maxKeyValue == removedKey) {
							maxKeyValue--;
						}
					}
				}break;
			}
			
		}
	}

}

void Manager::saveFile(char* argv[]) {

	while (1) {
		cin.clear();
		string menu;
		cout << "변경 사항을"<<argv[1]<<"에 저장하려면 W / w, "<<argv[1]<<"을 이전 상태로 유지하려면 C / c : ";
		cin >> menu;
		if (menu == "W" || menu == "w") {
			ofstream outStream;
			outStream.open(argv[1]);
			Node* cur = mylist->getHead()->getNext();
			while (cur != NULL) {
				string information = cur->getData()->information();
				outStream << information <<endl;
				cur = cur->getNext();
			}
			outStream.close();
			break;
		}
		else if (menu == "C" || menu == "c") {
			cout << "이전 상태로 유지 후 프로그램 종료" <<endl;
			break;
		}
		else {
			cout << "재입력해주세요"<<endl;
		}
	}
}

string Manager::makeKey() {
	string tempKey;
	string maxKeyValue_str = to_string((maxKeyValue+1));
	string order = string(NUM_ZERO - maxKeyValue_str.length(), '0') + maxKeyValue_str;
	return tempKey = "V" + order;
}

vector<string> Manager::split(string input, char delimiter) {
	vector<string> result;
	stringstream sStream(input);
	string temp;

	while (getline(sStream, temp, delimiter)) {
		result.push_back(temp);
	}

	return result;
}