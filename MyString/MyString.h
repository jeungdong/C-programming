#pragma once
#include<iostream>
using namespace std;

class MyString {
private:
	int capacity = 8;
	int terms;
	char* arr;
	void resize();
	void copy(char* str, const char* str2, int length);
	void concat(char* str1, const char* str2, int len, int pos);
	void concat(char* str1, const char* str2, int len, int pos,int pos2);
	int strLength(const char* srcStr) const;
	int compareTo(const char* srcStr) const;
	int basicFind(int pos, const char* subStr);
	
	const MyString& assignStr(const char* srcStr);
public:
	MyString();
	MyString(const char* srcStr);
	MyString(const MyString& myString);
	~MyString();
	int length() const;
	char at(int pos)const;
	bool empty();
	bool isFull() const;
	const MyString& operator=(const MyString& srcStr);
	const MyString& operator=(const char* srcStr);
	friend ostream& operator << (ostream& outputStream, const MyString& String);
	friend istream& operator >> (istream& inputStream, MyString& String);
	const MyString operator+(const char* str2nd);
	const MyString operator+(const MyString& str2nd);
	const MyString& append(const char* str2nd);
	const MyString& append(const MyString& str2nd);
	bool operator==(const MyString& str);
	bool operator!=(const MyString& str);
	int find(const char* subStr);
	int find(const MyString& subStr);
	int find(int pos, const char* subStr);
	int find(int pos, const MyString subStr);
	const MyString& operator+=(const char* str2nd);
	bool operator<(const MyString& str2nd);
	bool operator<=(const MyString& str2nd);
	bool operator>(const MyString& str2nd);
	bool operator>=(const MyString& str2nd);
	bool operator<(const char* str2nd);
	bool operator<=(const char* str2nd);
	bool operator>(const char* str2nd);
	bool operator>=(const char* str2nd);
	const MyString substr(int pos, int cnt);
	const MyString& insert(int pos, const char* subStr);
	const MyString& insert(int pos, const MyString& subStr);
	const MyString& replace(int pos, int cnt, const char* subStr);
	const MyString& replace(int pos, int cnt, const MyString& subStr);
	const MyString& erase(int pos, int cnt);
	const MyString& sumStr(int pos, const char* srcStr);
	int ctoi(char a)const;
	const char operator[](int pos)const;
}; 
int stoi(const MyString& str, int pos, int base);
int stoi(const MyString& str, int pos = 0, int base = 10);