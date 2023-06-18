#pragma once
#include "Object.h"

class Vector
{
public:
	Vector(int);
	~Vector();

	void Add(Object*);
	void Del();
	void Show();
	int operator()();
	Object* TryGet(int, bool&);

protected:
	Object** beg;
	int size;
	int cur;
};
