#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	int **data;
public:
	
	int get_rows() 
	{
		return rows;
	}
	int get_cols() 
	{
		return cols;
	}
	void set_data(int i, int j, int val) 
	{
		data[i][j] = val;
	}
	int get_data(int i, int j) 
	{
		return data[i][j];
	}
	//                 Constructors
	Matrix(int r, int c)
	{
		rows = r;
		cols = c;
		data = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int[cols];
		}
		cout << "Constructor:\t" << this << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
		
	//                    Operators

	Matrix operator+(Matrix& other)
	{
		Matrix sum(rows, cols);
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++) 
			{
				sum.set_data(i, j, data[i][j] + other.get_data(i, j));
			}
		}
		return sum;
	}
		
		void print()
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << data[i][j] << " ";
				}
				cout << endl;
			}

		}
};

void main()
{
	setlocale(LC_ALL, "");

		Matrix mat1(2, 3);
		mat1.print();
	
}
