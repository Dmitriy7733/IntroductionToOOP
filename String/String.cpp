#include"String.h"

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
const char* String::get_str()
{
	return str;
}
//            Constructors:

String::String(int size) : size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++) this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor: " << endl;
}
String::String(String&& other)noexcept :size(other.size), str(new char[size] {})
{
	//Shallow copy:
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}
String& String::operator=(const String& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)noexcept//noexcept согласно рекомендаций компилятора
{
	if (this != &other)
	{
		delete[] str;
		str = other.str;
		size = other.size;
		other.str = nullptr;
		other.size = 0;

	}
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
void String::print()const
{
	cout << "Size: " << size << endl;
	cout << "Str:  " << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

bool operator==(const String& left, const String& right)
{
	if (left.get_size() != right.get_size())
	{
		return false;
	}
	for (int i = 0; i < left.get_size(); i++)
	{
		if (left[i] != right[i])
			return false;
	}
	return true;
}
bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}