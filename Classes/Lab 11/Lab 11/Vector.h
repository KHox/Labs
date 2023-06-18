#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
public:
	Vector(int s);
	Vector(int s, T k);
	Vector(const Vector<T>& a);

	int Size()
	{
		return size;
	}

	void erase(int pos)
	{
		auto temp = new T[size - 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = data[i];
		}

		for (int i = pos + 1; i < size; i++)
		{
			temp[i - 1] = data[i];
		}

		data = temp;
	}

	void insert(int pos, T elem)
	{
		auto temp = new T[size + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = data[i];
		}

		for (int i = pos; i < size; i++)
		{
			temp[i + 1] = data[i];
		}

		temp[pos] = elem;

		data = temp;
	}

	Vector& operator=(const Vector<T>& a);
	T& operator[](int index);
	Vector operator+(const T k);

	friend ostream& operator<< <>(ostream& out, Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);

private:
	int size;
	T* data;
};

template <class T>
Vector<T>::Vector(int s)
{
	size = s;
	data = new T[size];
}

template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
}

template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "Error! Index > size\n";
}

template <class T>
Vector<T> Vector<T>::operator+(const T k)
{
	Vector<T> temp(*this);
	for (int i = 0; i < size; ++i) temp.data[i] = data[i] + k;
	return temp;
}


template <class T>
ostream& operator<<(ostream& out, Vector<T>& a)
{
	for (int i = 0; i < a(); ++i) out << a.data[i] << " ";
	out << "\n";
	return out;
}

template <class T>
istream& operator>>(istream& in, Vector<T>& a)
{
	for (int i = 0; i < a(); ++i) in >> a.data[i];
	return in;
}