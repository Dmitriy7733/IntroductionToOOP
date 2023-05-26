#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);
bool operator == (const String& left, const String& right);
bool operator!=(const String& left, const String& right);
class String
{
	int size;//размер строки в байтах
	char* str; //адрес строки в динамической памяти

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	const char* get_str()
	{
		return str;
	}
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;//посколько класс хранит размер в байтах +1 нужен для хранения NULL-терминатор
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << endl;
	}
	String(String&& other) noexcept
	{
		//Shallow copy:
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//Operators
	String& operator=(const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/
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
	String& operator=(String&& other) noexcept//noexcept согласно рекомендаций компилятора
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
	
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str:  " << str << endl;
	}
	
};
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

bool operator == (const String& left, const String& right)
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

#define HOME_WORK
void main()
{
	setlocale(LC_ALL, "");
	//cout << " Hello, String" << endl;
	String str = "Hello";
	//str.print();
	cout << str << endl;
#ifdef HOME_WORK
	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;
	cout << str3 << endl;
	String str4 = str1;
	cout << str4 << endl;
	
	String str5 = move(str2);
	cout << str5 <<endl;
#endif HOME_WORK
	
}