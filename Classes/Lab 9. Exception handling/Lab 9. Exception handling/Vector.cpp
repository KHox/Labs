#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

Vector::Vector(int s)
{
	if (s > MAX_SIZE)
	{
		throw Error("Maximum allowed array size exceeded, maximum allowed array size is " + to_string(MAX_SIZE));
	}
	else if (s < 0)
	{
		throw Error("Array size can't be less than 0");
	}

	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
	{
		beg[i] = 0;
	}
}

Vector::Vector(int s, int* arr)
{
	if (s > MAX_SIZE)
	{
		throw Error("Maximum allowed array size exceeded, maximum allowed array size is " + to_string(MAX_SIZE));
	}
	else if (s < 0)
	{
		throw Error("Array size can't be less than 0");
	}

	size = s;
	beg = new int[s];
	Copy(arr);
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	Copy(v.beg);
}

Vector::~Vector()
{
	if (beg != 0) delete[] beg;
}

const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v) return *this;

	if (beg != 0) delete[] beg;

	size = v.size;
	beg = new int[size];
	Copy(v.beg);
	
	return *this;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) 
	{
		out << "Empty\n";
	}
	else
	{
		for (int i = 0; i < v.size; i++)
		{
			out << v.beg[i] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		in >> v.beg[i];
	}

	return in;
}

int Vector::operator[](int i)
{
	if (i < 0) throw Error("Index cannot be less than 0");
	if (i >= size) throw Error("Index out of range");

	return beg[i];
}

Vector Vector::operator+(int a)
{
	for (int i = 0; i < size; i++)
	{
		beg[i] += a;
	}
	return *this;
}

Vector Vector::operator-(int a)
{
	if (a > size) throw Error("Can't remove more elements than in array");
	else if (a < 0) throw Error("Can't remove less than 0 elements");

	size -= a;
	int* temp = beg;
	beg = new int[size];
	Copy(temp);
	return *this;
}

void Vector::Copy(int* arr)
{
	for (int i = 0; i < size; i++)
	{
		beg[i] = arr[i];
	}
}
