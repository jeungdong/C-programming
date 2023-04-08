#include "Node.h"

Node::Node() {
	data = nullptr;
	next = nullptr;
}
Node::Node(DataType* theData) {
	data = theData;
}
Node::~Node() {
	delete data;
	delete next;
}
DataType* Node:: getData() {
	return data;
};
void Node::setNext(Node* TheNext) {
	next = TheNext;
}
Node* Node::getNext() {
	return next;
}
void Node::setData(DataType* theData) {
	data = theData;
}
