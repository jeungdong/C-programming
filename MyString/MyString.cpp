#include<iostream>
#include"MyString.h"

bool MyString::isFull()const { return (terms == capacity); }

int MyString::strLength(const char* srcStr)const {
	int strlen = 0;
	for (strlen; srcStr[strlen] != '\0'; strlen++);
	return strlen;
}

void MyString::resize() {
	capacity = 2 * capacity;
	char* newArr = new char[capacity];
	copy(newArr, arr, terms);
	delete[] arr;
	arr = newArr;
}
void MyString::copy(char* str1, const char* str2, int len) {
	for (int i = 0; i <= len; i++) {
		str1[i] = str2[i];
	}
}
void MyString::concat(char* str1, const char* str2, int len, int pos) {
	for (int i = 0; i <= len; i++) {
		str1[pos + i] = str2[i];
	}
}
void MyString::concat(char* str1, const char* str2, int len, int pos,int pos2) {
	for (int i = 0; i <= len; i++) {
		str1[pos + i] = str2[pos2+i];
	}
}
int MyString::compareTo(const char* srcStr)const {
	int compareLen = (strLength(arr) >= strLength(srcStr)) ? strLength(srcStr) : strLength(arr);
	for (int i = 0; i < compareLen; i++) {
		if (arr[i] > srcStr[i]) { return 1; } // »çÀü¹è¿­»ó ´õ µÚ
		if (arr[i] < srcStr[i]) { return -1; } //
	}
	if (strLength(arr) > strLength(srcStr)) {
		return 1; //   
	}
	else if (strLength(arr) < strLength(srcStr)) {
		return -1;
	}
	else return 0;
}
MyString::MyString() {
	terms = 0;
	arr = new char[capacity];
	arr[0] = '\0';
}
MyString::MyString(const char* srcStr) {
	terms = strLength(srcStr);
	for (capacity; capacity <= terms; capacity *= 2);
	arr = new char[capacity];
	copy(arr, srcStr, terms);
}
MyString::MyString(const MyString& copyString) {
	terms = copyString.terms;
	capacity = copyString.capacity;
	arr = new char[capacity];
	copy(arr, copyString.arr, terms);
}
MyString::~MyString() {
	delete[] arr;
	arr = NULL;
}
const MyString& MyString::operator=(const MyString& srcStr) {
	if (this == &srcStr) { return *this; }
	else {
		return assignStr(srcStr.arr);
	}
}
const MyString& MyString::operator=(const char* srcStr) {
	return assignStr(srcStr);
}
const MyString& MyString::assignStr(const char* srcStr) {
	terms = strLength(srcStr);
	for (capacity; capacity <= terms; capacity *= 2);
	delete[] arr;
	arr = new char[capacity];
	copy(arr, srcStr, terms);
	return *this;
}
int MyString::length() const{
	return terms;
}
char MyString::at(int pos) const {
	if (arr[pos] == NULL || pos > terms||pos < 0) {
		cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù"<<endl; return NULL;  // ¶óÀÌºê·¯¸®´Â ¹üÀ§ ¹þ¾î³ª¸é ÅÍÁü
	}
	else return arr[pos];
}
bool MyString::empty() {
	if (terms == 0) { return true; }
	else return false;
}
istream& operator >> (istream& is, MyString& str) {
	char c = cin.get();
	while (c != '\n') {
		str.arr[str.terms++] = c;
		c = cin.get();
		if (str.isFull()) { str.resize(); }
	}
	str.arr[str.terms] = '\0';
	return is;
}
ostream& operator << (ostream& os, const MyString& str) {
	cout << str.arr;
	return os;
}

const MyString MyString :: operator+(const char* str2nd) {
	MyString sumString(arr);
	sumString.sumStr(sumString.terms, str2nd);
	return sumString;
}

const MyString MyString :: operator+(const MyString& str2nd) {
	MyString sumString(arr);
	sumString.sumStr(sumString.terms, str2nd.arr);
	return sumString;
}

const MyString& MyString::append(const char* str2nd) { 
	return sumStr(terms, str2nd);
}

const MyString& MyString::append(const MyString& str2nd) {
	return sumStr(terms, str2nd.arr);
}

const MyString& MyString::sumStr(int pos, const char* srcStr) {
	if (pos < 0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	terms += strLength(srcStr);
	for (capacity; capacity <= terms; capacity *= 2);
	char* newArr = new char[capacity];
	copy(newArr, arr, strLength(arr));
	concat(newArr, srcStr, strLength(srcStr), pos);
	delete[] arr;
	arr = newArr;
	return *this;
}

bool MyString::operator==(const MyString& str2nd) {
	if (this->compareTo(str2nd.arr) == 0) {
		return true;
	}
	return false;
}

bool MyString::operator!=(const MyString& str2nd) {
	if (this->compareTo(str2nd.arr) != 0) {
		return true;
	}
	return false;
}

int MyString::find(const char* subStr) {
	return basicFind(0, subStr);
}
int MyString::find(const MyString& subStr) {
	return basicFind(0, subStr.arr);
}
int MyString::find(int pos, const char* subStr) {
	return basicFind(pos, subStr);
}
int MyString::find(int pos, const MyString subStr) {

	return basicFind(pos, subStr.arr);
}
int MyString::basicFind(int pos, const char* subStr) {
	if (pos < 0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	int findIndex;
	for (int Index = pos; Index < terms; Index++) {
		if (arr[Index] == subStr[0]) {
			for (findIndex = 0; findIndex < strLength(subStr); findIndex++) {
				if (arr[Index + findIndex] != subStr[findIndex]) { break; }
			}
			if (findIndex == strLength(subStr)) { return Index; }
		}
	}
	return -1;
}
const MyString& MyString::operator+=(const char* str2nd) {
	return sumStr(terms, str2nd);
}

bool MyString::operator<(const MyString& str2nd) {
	if (this->compareTo(str2nd.arr) < 0) {
		return true;
	}
	return false;
}
bool MyString::operator<=(const MyString& str2nd) {
	if (this->compareTo(str2nd.arr) <= 0) {
		return true;
	}
	return false;
}
bool MyString::operator>(const MyString& str2nd) {
	if (this->compareTo(str2nd.arr) > 0) {
		return true;
	}
	return false;
}
bool MyString::operator>=(const MyString& str2nd) {
	if (this->compareTo(str2nd.arr) >= 0) {
		return true;
	}
	return false;
}
bool MyString::operator<(const char* str2nd) {
	if (this->compareTo(str2nd) < 0) {
		return true;
	}
	return false;
}
bool MyString::operator<=(const char* str2nd) {
	if (this->compareTo(str2nd) <= 0) {
		return true;
	}
	return false;
}
bool MyString::operator>(const char* str2nd) {
	if (this->compareTo(str2nd) > 0) {
		return true;
	}
	return false;
}
bool MyString::operator>=(const char* str2nd) {
	if (this->compareTo(str2nd) >= 0) {
		return true;
	}
	return false;
}
const MyString MyString::substr(int pos, int cnt) { 
	if (pos < 0 || cnt < 0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	char* newArr = new char[cnt+1];
	for (int i = 0; i < cnt; i++) {
		newArr[i] = arr[pos + i];
	}
	newArr[cnt] = '\0';
	return MyString(newArr);
}
const MyString& MyString::insert(int pos, const char* subStr) {
	if (pos < 0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	MyString subString = MyString(substr(pos, terms - pos));
	sumStr(pos, subStr);
	concat(arr, subString.arr, strLength(subString.arr), strLength(arr));
	return *this;
}

const MyString& MyString::insert(int pos, const MyString& subStr) {
	if (pos < 0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	MyString subString = substr(pos, terms - pos);
	sumStr(pos, subStr.arr);
	concat(arr, subString.arr, strLength(subString.arr), strLength(arr));
	return *this;
}
const MyString& MyString::replace(int pos, int cnt,const char* subStr) {
	if (pos < 0 || cnt <0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	if (cnt > strLength(subStr)) { return *this; }
	if (pos + cnt < terms) {
		concat(arr, subStr, cnt-1, pos);
	}
	else {
		MyString replaceString = MyString(subStr).substr(0, cnt);
		terms = pos;
		sumStr(pos, replaceString.arr);
	}
	return *this;
}
const MyString& MyString::replace(int pos, int cnt, const MyString& subStr) {
	if (pos < 0 || cnt<0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	if (cnt > strLength(subStr.arr)) { return *this; }
	if (pos + cnt < terms) {
		concat(arr, subStr.arr, cnt-1, pos);
	}
	else {
		MyString replaceString = MyString(subStr).substr(0, cnt);
		terms = pos;
		sumStr(pos, replaceString.arr);
	}
	return *this;
}
const MyString& MyString::erase(int pos, int cnt) {
	if (cnt + pos > strLength(arr)||cnt < 0||pos<0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù"<<endl; return NULL; }
	terms = terms - cnt;
	concat(arr, arr, strLength(arr)-pos-cnt, pos, pos + cnt);
	return *this;
}

int stoi(const MyString& str, int pos , int base) {
	int integer = 0;
	int sign = 1;
	if (pos < 0 || base<2||16<base ) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	if (str[pos] == '-') { sign = -1; pos++; }
	for (int i = pos; i < str.length(); i++) {
		int ctoi = str.ctoi(str[i]);
		if (ctoi >= base || ctoi == -1) {return integer * sign;}
		
		integer *= base;
		integer += ctoi;
	}
	return integer * sign;
}
const char MyString :: operator[](int pos) const{
	if (pos < 0 || pos > terms) { cout << "¹üÀ§ ¹þ¾î³µ½À´Ï´Ù" << endl; return NULL; }
	return at(pos);
}
int MyString :: ctoi(char a)const {
	int i = 0;
	if ('a' <= a && a <= 'f') { i = a - 87; }
	else if ('A' <= a && a <= 'F') { i = a - 55; }
	else if ('0' <= a && a <= '9') {i = a - '0';}
	else { return -1; }
	return i;
}