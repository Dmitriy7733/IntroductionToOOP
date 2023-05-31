#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


////////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
class String
{
	int size;//������ ������ � ������
	char* str; //����� ������ � ������������ ������

public:
	int get_size()const;
	const char* get_str()const;
	const char* get_str();
	//            Constructors:

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other)noexcept;
	~String();
	//Operators
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;

	String& operator+=(const String& other);

	char operator[](int i)const;
	char& operator[](int i);
	void print()const;
};
