#include "Vector.h"

Vector::Vector(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}

	beg.elem = &data[0];
	end.elem = &data[size];
}

Vector::Vector(const Vector& a)
{
	size = a.size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}

	beg.elem = &data[0];
	end.elem = &data[size];
}

Vector::~Vector()
{
	delete[] data;
	data = 0;
}

Vector& Vector::operator=(const Vector& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}

	beg.elem = &data[0];
	end.elem = &data[size];

	return *this;
}

int&Vector::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "Error! Index > size\n";
}

Vector Vector::operator+(const int k)
{
	Vector temp(*this);
	for (int i = 0; i < size; ++i) temp.data[i] += k;
	return temp;
}

int Vector::operator()()
{
	return size;
}

ostream&operator<<(ostream& out, Vector& a)
{
	for (int i = 0; i < a(); ++i) out << a.data[i] << " ";
	out << "\n";
	return out;
}

istream& operator>>(istream& in, Vector& a)
{
	for (int i = 0; i < a(); ++i) in >> a.data[i];
	return in;
}