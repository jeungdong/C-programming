#pragma once

#include <string>
#include "Person.h"
#include"Node.h"
#include "MyList.h"
#include "Ordinary.h"
#include "Professor.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale>


class MyList {
private: 
	Node* head;
	
public :
	MyList();
	~MyList();
	void insert(DataType* data);
	bool isExist(DataType* data);
	Node* remove(string str);
	void change(string str,int addDonation);
	void show();
	Node* search(string str);
	Node* getPrev(Node* target);
	int getSize();
	Node* getHead();
	void sort(string str);
};