#pragma once
#include <iostream>
using namespace std;

class Set {
private:
	int terms;
	int capacity;
	int* arr;
public :
	Set() {
		terms = 0;
		capacity = 4;
		arr = new int[capacity];
	}
	Set(const Set& copySet) : terms(copySet.terms), capacity(copySet.capacity) {
		arr = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			arr[i] = copySet.arr[i];
		}
	}
	~Set() {
		delete[] arr;
	}
	void input(int n);
	void resize();
	bool isRepetition(int n);
	const Set operator|(Set& set2);
	const Set operator&(Set& set2);
	friend istream& operator >>(istream& inputStream, Set& set);
	friend ostream& operator << (ostream& outputStream,const Set& set);
};