#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction& left, Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(Fraction& left, Fraction& right);
bool operator<=(Fraction& left, Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(double decimal)
	{
		decimal += 1e-10;
		this->integer = decimal;
		decimal -= integer;
		denominator = 1e9;//записываем максимально возможный знаменатель
	//или 1e10=1*10^10
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//					Operators:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//                Increment/Decrement:
	Fraction operator++()
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction& operator++(int) //Postfix increment
	{
		//всегда принимает один и только один параметр типа int и только int
		//это позволяет компилятору на уровне перегрузки функций отличить постфиксный инкремент от префиксного
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction operator--()
	{
		to_proper();
		integer--;
		return *this;
	}
	Fraction& operator--(int) //Postfix decrement
	{
		to_proper();
		Fraction old = *this;
		integer--;
		return old;
	}
	 //Type-cast operators
	explicit operator int()
	{
		to_proper();
		return integer;
	}
	explicit operator double()
	{
		return integer + (double)numerator / denominator;
	}
	/*operator Fraction()
	{
		int integer = (int)x;
	}*/

	//					Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		//Этот метод обращает дробь.
		Fraction inverted = *this;
		inverted.to_improper();
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Compound%20assignment%20(%2B%3D%2C%20%2D%3D%2C%20*%3D%2C%20/%3D%2C%20%25%3D%2C%20%3E%3E%3D%2C%20%3C%3C%3D%2C%20%26%3D%2C%20%5E%3D%2C%20%7C%3D)
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Bitwise%20operators%20(%20%26%2C%20%7C%2C%20%5E%2C%20~%2C%20%3C%3C%2C%20%3E%3E%20)
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;   //наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	//friend bool operator==(Fraction& left, Fraction& right);
	//friend bool operator!=(Fraction& left, Fraction& right);
	//friend bool operator>(Fraction& left, Fraction& right);
	//friend bool operator<(Fraction& left, Fraction& right);
	//friend bool operator>=(Fraction& left, Fraction& right);
	//friend bool operator<=(Fraction& left, Fraction& right);
};


Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	//Прямо в 'return' создаем временный безымянрый объект типа 'Fraction'
	//Временные безымянные объекты существуют в пределах одного выражения, 
	//и удаляются из памяти по завершении выражения
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
#ifdef SIMPLE_IMPUT
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);
#endif SIMPLE_IMPUT
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	int number[3] = {};
	int n = 0;//количество введенных чисел
	char delimeters[] = "() /";
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
	{
		number[n++] = atoi(pch);
	}
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numerator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]); break;
	}
	return is;
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
	{
		return false;
	}*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		(
			(left.get_numerator() * right.get_denominator()) >
			(right.get_numerator() * left.get_denominator())
		);
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		(
			(left.get_numerator() * right.get_denominator()) <
			(right.get_numerator() * left.get_denominator())
		);
}
bool operator>=(Fraction& left, Fraction& right)
{
	//left.to_improper();
	//right.to_improper();
	return
		(
			left > right || left == right
			);
}
bool operator<=(Fraction& left, Fraction& right)
{
	//left.to_improper();
	//right.to_improper();
	return
		(
			left < right || left == right
		);
}


//#define CONSTRUCTORS_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATORS
//#define ISTREAM_OPERATOR
//#define TYPE_CONVERSION_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define HOME_WORK_1
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	int a;
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 5;		//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif CONSTRUCTORS_CHECK
#ifdef ARIFMETICAL_OPERATORS_CHECK

	Fraction A(5, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	double a = 2;
	double b = 5;
	double c = a * b;


	/*Fraction C = A * B;
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print(); */

	/*A *= B;
	A.print();
	A /= B;
	A.print();*/

	Fraction E = A + B;
	cout << "E = A + B= " << E << endl;
	Fraction K = A - B;
	cout << "K = A - B = " << K << endl;
	/*A += B;
	A.print();*/
	A -= B;
	A.print();

#endif ARIFMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_DECREMENT

	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
	for (Fraction i(5, 1, 2); i.get_integer() >= 0; i--)
	{
		i.print();
	}

#endif INCREMENT_DECREMENT

#ifdef COMPARISON_OPERATORS

	Fraction A(4, 2, 4);
	cout << A << endl;
	Fraction B(3, 2, 4);
	cout << B << endl;


	if (A == B)
	{
		cout << "Дробь A равна дроби B" << endl;
	}
	cout << A << endl;
	cout << B << endl;
	if (A != B)
	{
		cout << "Дробь A не равна дроби B" << endl;
	}
	if (A < B)
	{
		cout << "Дробь A меньше дроби В" << endl;
	}
	if (A > B)
	{
		cout << "Дробь А больше дроби В" << endl;
	}
	if (A >= B)
	{
		cout << "Дробь А больше или равна дроби В" << endl;
	}
	if (A <= B)
	{
		cout << "Дробь А меньше или равна дроби В" << endl;
	}
#ifdef ISTREAM_OPERATOR
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif ISTREAM_OPERATOR

#endif COMPARISON_OPERATORS

#ifdef TYPE_CONVERSION_BASICS
	int a = 2;
	double b = 3;
	int c = a + b;
	cout << c << endl;
	int d = 8.3;
	cout << d << endl;
#endif //TYPE_CONVERSION_BASICS
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	//cout << sizeof(Fraction) << endl;
	Fraction A = (Fraction)5;		//Conversion from 'int' to 'Fraction'
	cout << A << endl;
	cout << delimiter << endl;

	Fraction B;			//Default constructor
	B = Fraction(8);
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
	/*Fraction A(2, 3, 4);
	//A.to_improper();
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;*/
#ifdef HOME_WORK_1
	Fraction A = 2.75;
	cout << A << endl;
#endif HOME_WORK_1

}