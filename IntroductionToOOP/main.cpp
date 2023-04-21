#include<iostream>
using namespace std;

#define delimiter "\n----------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment: \t\t" << this << endl;
		return *this;
	}
	void print()const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}
	double distance(const Point other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);

		return distance;
	}
};
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define CONSTRUCTORS_CHECK
#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, ""); 

#ifdef STRUCT_POINT

	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;

#endif STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK

	Point A;
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() <<"\t"<< A.get_y() << endl;
	A.print();
	Point B = 5;
	B.print();
	Point C(2, 3);
	C.print();
	//Point D(2, 3);
	Point D = C;
	D.print();
	Point E;
	E = D;
#endif CONSTRUCTORS_CHECK
#ifdef DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();
	Point A,B,C;
	cout << delimeter << endl;
	A = B = C = Point(2, 3);
	cout << delimeter << endl;
	A.print();
	B.print();
	C.print();
#endif ASSIGNMENT_CHECK

	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A,B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками В и А: " << distance(B, A) << endl;
	cout << delimiter << endl; 
#endif  DISTANCE_CHECK

}