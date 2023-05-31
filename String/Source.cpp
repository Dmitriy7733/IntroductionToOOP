#include"String.h"


/// //////////////////////



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