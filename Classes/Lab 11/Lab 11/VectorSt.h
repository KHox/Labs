#pragma once
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class VectorS
{
public:
	VectorS(int s);
	VectorS(int s, T k);
	VectorS(const VectorS<T>& a);

	int Size()
	{
		return size;
	}

	void erase(int pos)
	{
		stack<Time> tmp;
		for (int i = 0; i < pos; i++)
		{
			tmp.push(st.top());
			st.pop();
		}

		st.pop();

		for (int i = 0; i < pos; i++)
		{
			st.push(tmp.top());
			tmp.pop();
		}

		data = copyToVec(st);
	}

	void insert(int pos, T elem)
	{
		stack<T> tmp;
		for (int i = 0; i < pos; i++)
		{
			tmp.push(st.top());
			st.pop();
		}

		st.push(elem);

		for (int i = 0; i < pos; i++)
		{
			st.push(tmp.top());
			tmp.pop();
		}

		data = copyToVec(st);
	}

	VectorS& operator=(const VectorS<T>& a);
	T& operator[](int index);
	VectorS operator+(const T k);

	friend ostream& operator<< <>(ostream& out, VectorS<T>& a);
	friend istream& operator>> <>(istream& in, VectorS<T>& a);
	
	stack<T> st;

	stack<T> copyToStack()
	{
		stack<T> s;
		for (int i = 0; i < size; i++)
		{
			s.push(data[i]);
		}
		return s;
	}

	stack<T> copyToStack(T* a, int n)
	{
		stack<T> s;
		for (int i = 0; i < n; i++)
		{
			s.push(a[i]);
		}
		return s;
	}

	T* copyToVec(stack<T> s)
	{
		T* a = new T[s.size()];
		int i = 0;
		while (!s.empty())
		{
			a[i] = s.top();
			s.pop();
			i++;
		}
		return a;
	}

private:
	int size;
	T* data;
};

template <class T>
VectorS<T>::VectorS(int s)
{
	size = s;
	data = new T[size];
	st = copyToStack(data, size);
}

template <class T>
VectorS<T>::VectorS(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	st = copyToStack(data, size);
}

template <class T>
VectorS<T>::VectorS(const VectorS& a)
{
	size = a.size;
	data = new T[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}

	st = copyToStack(data, size);
}

template <class T>
VectorS<T>& VectorS<T>::operator=(const VectorS<T>& a)
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[] data;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
	st = copyToStack(data, size);
	return *this;
}

template <class T>
T& VectorS<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "Error! Index > size\n";
}

template <class T>
VectorS<T> VectorS<T>::operator+(const T b)
{
	VectorS<T> temp(*this);
	stack<Time> tmp;
	for (int i = 0; i < size; i++)
	{
		tmp.push(temp.st.top() + b);
		temp.st.pop();
	}

	for (int i = 0; i < size; i++)
	{
		temp.st.push(tmp.top());
		tmp.pop();
	}

	temp.data = copyToVec(temp.st);
	return temp;
}


template <class T>
ostream& operator<<(ostream& out, VectorS<T>& a)
{
	for (int i = 0; i < a(); ++i) out << a.data[i] << " ";
	out << "\n";
	return out;
}

template <class T>
istream& operator>>(istream& in, VectorS<T>& a)
{
	for (int i = 0; i < a(); ++i) in >> a.data[i];
	return in;
}