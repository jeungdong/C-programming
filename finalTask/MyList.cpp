#include "MyList.h"
#include "Node.h"
#include "Person.h"
#include <iostream>
using namespace std;

MyList::MyList() {
	head = new Node();

}
MyList::~MyList() {
	Node* cur = head->getNext();
	delete head;

	while(cur != NULL) {
		head = cur;
		cur = cur->getNext();
		delete head;
	}
}
bool MyList::isExist(DataType* data) {
	Node* cur = head->getNext();
	while (cur != NULL) {
		if (cur->getData()->getKey() == data->getKey()) {
			cout << "!!! 동일한 키값이 존재하여 신규 등록 불가 !!!" << endl;
			return true;
		}
		else if (cur->getData()->getPhoneNum() == data->getPhoneNum()) {
			cout << "!!! 동일한 전화번호가 존재하여 신규 등록 불가 !!!" << endl;
			
			return true;
		}
		cur = cur->getNext();
	}
	return false;
}

Node* MyList::search(string str) {
	Node* cur = head->getNext();
	while (cur != NULL) {
		if (cur->getData()->getKey() == str) {
			return cur;
		}
		else if (cur->getData()->getPhoneNum() == str) {
			return cur;
		}
		cur = cur->getNext();
	}
	return NULL;
}

void MyList::change(string str, int addDonation) {
	Node* target = search(str);
	if (target != NULL) {
		target->getData()->addDonation(addDonation);
		cout << "<변경>";
		target->getData()->printCheck();
		cout << endl;
	}
	else {
		cout << "해당 사용자 없음 !!";
	}
}

void MyList::insert(DataType* data) {
	Node* newNode = new Node(data);

	if (head->getNext() == NULL) {
		head->setNext(newNode);
	}
	else {
		Node* prev = head;
		Node* cur = head->getNext();
		while (cur != NULL) {
			if (cur->getData()->getDonation() < newNode->getData()->getDonation()) {
				newNode->setNext(cur);
				prev->setNext(newNode);
				break;
			}
			else if(cur->getData()->getDonation() == newNode->getData()->getDonation()){
				if (cur->getData()->getName().compare(newNode->getData()->getName())==1) {
					newNode->setNext(cur);
					prev->setNext(newNode);
					break;
				}
				else if (cur->getData()->getName().compare( newNode->getData()->getName())==0) {
					if(cur->getData()->getPhoneNum().compare( newNode->getData()->getPhoneNum())==1){
						newNode->setNext(cur);
						prev->setNext(newNode);
						break;
					}
				}
			}
			if (cur->getNext() == NULL) {
				cur->setNext(newNode);
				break;
			}
			prev = cur;
			cur = cur->getNext();
		}
	}
	
}
Node* MyList::getPrev(Node* target) {
	Node* cur = head;
	Node* nextNode = NULL;

	while ((nextNode = cur->getNext()) != NULL) {
		if (nextNode == target) {
			return cur;
		}
		cur = nextNode;
	}
	return NULL;

}


Node* MyList :: remove(string str) {
	Node* target = search(str);
	Node* prevNode = getPrev(target);
	if (target != NULL) {
		prevNode->setNext(target->getNext());
		
		return target;
	}
	else {
		cout << "해당 사용자 없음 !!"<<endl;
		return NULL;
	}
	
}


void MyList::show() {
	Node* cur = head->getNext();
	while (cur != NULL) {
		cur->getData()->printCheck();
		cur = cur->getNext();
	}
}

Node* MyList::getHead() {
	return head;
}

void MyList::sort(string str) {
	Node* target = search(str);
	Node* prevNode = getPrev(target);
	prevNode->setNext(target->getNext());
	Node* cur = head->getNext();
	while (cur != NULL) {
		if (cur->getData()->getDonation() < target->getData()->getDonation()) {
			getPrev(cur)->setNext(target);
			target->setNext(cur);
			break;
		}
		cur = cur->getNext();
	}
}