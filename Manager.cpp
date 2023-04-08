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
		cout << argv[1] << "�� �� �� �����ϴ�." << endl;
	}
	else {
		cout << "------- ��Ź��Ȳ -------" << endl;
		while (getline(inStream, str)) {
			Info = split(str, ' ');
			if (Info[0] == ( "�л�")) {
				Person* s = new Student(Info[1], Info[2], Info[3], Info[4], stoi(Info[5]));
				mylist->insert(s);
			}
			else if (Info[0] == "������") {
				Person* p = new Professor(Info[1], Info[2], Info[3], Info[4], Info[5], stoi(Info[6]));
				mylist->insert(p);
			}
			else if (Info[0] == "�Ϲ�") {
				Person* o = new Ordinary(Info[1], Info[2], Info[3], stoi(Info[4]));
				mylist->insert(o);
				int myKey = stoi(Info[1].substr(1, string::npos));
				if (maxKeyValue < myKey) {
					maxKeyValue = myKey;
				}
			}
			else {
				cout << "�������� �ʴ� Ÿ���Դϴ�.";
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

		cout << "[1] ��ü ��ȸ / [2] �ű� ��Ź�� ��� / [3] ��Ź���� ���� / [4] ��Ź�� ���� / [5] ���� : ";
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
				cout << "�ű� ��Ź�� ������ �Է��ϼ���: ";
				cin.ignore();
				getline(cin, str);
				Info = split(str, ' ');

				if (Info[0] == "�л�") {
					Person* p = new Student(Info[1], Info[2], Info[3], Info[4], stoi(Info[5]));
					if (!mylist->isExist(p)) {
						mylist->insert(p);
						cout << "<�ű�>";
						p->printCheck();
					}
					cout << endl;
				}
				else if (Info[0] == "������") {
					Person* p = new Professor(Info[1], Info[2], Info[3], Info[4], Info[5], stoi(Info[6]));
					if (!mylist->isExist(p)) {
						mylist->insert(p);
						cout << "<�ű�>";
						p->printCheck();
					}
					cout << endl;
				}
				else if (Info[0] == "�Ϲ�") {
					string key = makeKey();
					Person* p = new Ordinary(key, Info[1], Info[2], stoi(Info[3]));
					if (!mylist->isExist(p)) {
						mylist->insert(p);
						cout << "<�ű�>";
						p->printCheck();
						maxKeyValue++;
					}
					cout << endl;
				}	
				else {
					cout << "�������� �ʴ� Ÿ���Դϴ�." << endl;
				}
				break;
			}

			case 3:
			{
				string datum;
				int theDonation;
				cout << "������ ���ϴ� ����̳� �й� �Ǵ� ��ȭ��ȣ(XXX-XXXX-XXXX)�� �Է��ϼ��� : ";
				cin >> datum;
				cout << "�߰� ��Ź���� �Է��ϼ��� : ";
				cin >> theDonation;
				mylist->change(datum, theDonation);
				mylist->sort(datum);
				break;
			}
			case 4:
			{
				string datum;
				cout << "������ ���ϴ� ����̳� �й� �Ǵ� ��ȭ��ȣ(XXX - XXXX - XXXX)�� �Է��ϼ��� : ";
				cin >> datum;
				Node* removed = mylist->remove(datum);
				if (removed != NULL)
				{
					cout << "[����]";
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
		cout << "���� ������"<<argv[1]<<"�� �����Ϸ��� W / w, "<<argv[1]<<"�� ���� ���·� �����Ϸ��� C / c : ";
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
			cout << "���� ���·� ���� �� ���α׷� ����" <<endl;
			break;
		}
		else {
			cout << "���Է����ּ���"<<endl;
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