#include "Set.h"
#include <iostream>
using namespace std;

istream& operator >>(istream& inputStream, Set& set) {
	int num;
	while (1) {
		cin >> num;
		if (num < 0) { break; }
		if (!set.isRepetition(num)) { set.input(num); }
		else { cout << num << "는 중복원소이므로 제거" << endl; }
	}
	return inputStream;
}
ostream& operator <<(ostream & outputStream, const Set & set) {
	for (int i = 0; i < set.terms; i++) 
		cout << set.arr[i] << " ";
	return outputStream;
}
void Set::input(int n) {
	if (terms == capacity) {resize();}
	arr[terms++] = n;
}
bool Set::isRepetition(int n) {
	for (int i = 0; i < terms; i++) {
		if (n == arr[i]) {return true;}
	}
	return false;
}
void Set::resize() {
	capacity *= 2;
	int* newArr = new int[capacity];
	for (int i = 0; i < terms; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}
const Set Set :: operator|(Set& s2){
	Set newSet;
	for (int i = 0; i < terms; i++) {
		newSet.input(arr[i]);
	}
	for (int i = 0; i < s2.terms; i++) {
		if (!newSet.isRepetition(s2.arr[i])) { newSet.input(s2.arr[i]); }
	}
	return Set(newSet);
}
const Set Set :: operator&(Set& s2) {
	Set newSet;
	for (int i = 0; i < terms; i++) {
		if (s2.isRepetition(arr[i])) { newSet.input(arr[i]); }
	}
	return Set(newSet);
}
