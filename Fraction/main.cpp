#include<iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
	int integerPart;
public:
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_integerPart()const
	{
		return integerPart;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	void set_integerPart(int integerPart)
	{
		this->integerPart = integerPart;
	}
	Fraction()
	{
		numerator = 0;
		denominator = 1;
		integerPart = 0;
	}
	Fraction(int integerPart, int numerator, int denominator)
	{
		this->integerPart = integerPart;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	~Fraction()
	{

	}
	void print()const
	{
		if (integerPart != 0)
		{
			cout << integerPart;
		}
		if (numerator != 0)
		{
			if (integerPart != 0)
			{
				cout << " ";
			}
			cout << numerator << "/" << denominator;
		}
		if (integerPart == 0 && numerator == 0)
		{
			cout << "Дроби не содержат нулей!";
		}
		cout << endl;
	}
	Fraction& operator + (const Fraction& other) const
	{
		int numerator = (integerPart * denominator + this->numerator) * other.denominator +
			(other.integerPart * other.denominator + other.numerator) * denominator;
		int denominator = this->denominator * other.denominator;
		Fraction result(integerPart, numerator, denominator);
		return result;
	}

};
void main()
{
	setlocale(LC_ALL, "");

	Fraction f1(1, 2, 3);
	f1.print();
	Fraction f2(3, 5, 7);
	f2.print();
	Fraction f3 = f1 + f2;
	f3.print();
	
}