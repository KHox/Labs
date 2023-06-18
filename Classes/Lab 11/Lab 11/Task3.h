#pragma once
#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

Vector<Time> MakeVector3(int n)
{
	Vector<Time> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = Time(rand() % 60, rand() % 60);
	}
	return v;
}

Time GetMax(Vector<Time>* v)
{
	Time max = (*v)[0];

	for (int i = 1; i < v->Size(); i++)
	{
		if ((*v)[i] > max)
		{
			max = (*v)[i];
		}
	}
	return max;
}

Time GetMin(Vector<Time>* v, int& pos)
{
	Time min = (*v)[0];
	pos = 0;

	for (int i = 1; i < v->Size(); i++)
	{
		if ((*v)[i] < min)
		{
			min = (*v)[i];
			pos = i;
		}
	}

	return min;
}

Time GetAverage(Vector<Time>* v)
{
	int sum = 0;

	for (int i = 0; i < v->Size(); i++)
	{
		sum += (*v)[i].toNumber();
	}

	int a = sum / v->Size();

	return Time(a / 60, a % 60);
}

void AddForEach(Vector<Time>* v, Time b)
{
	for (int i = 0; i < v->Size(); i++)
	{
		(*v)[i] = (*v)[i] + b;
	}
}

void Execute3()
{
	auto vec = MakeVector3(10);
	vec.insert(0, GetMax(&vec));
	int pos = -1;
	GetMin(&vec, pos);
	vec.erase(pos);
	AddForEach(&vec, GetAverage(&vec));
}