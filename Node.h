#pragma once
#include "person.h"

typedef Person DataType;
class Node {
private :
	DataType* data;
	Node* next;
public :
	Node();
	~Node();
	Node(DataType* TheData);
	DataType* getData();
	void setNext(Node* n);
	Node* getNext();
	void setData(DataType* theData);
};
