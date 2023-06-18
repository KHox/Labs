#pragma once
#include <iostream>
#include "VectorSt.h"
#include "Time.h"

using namespace std;

VectorS<Time> MakeVectorS5(int n)
{
	VectorS<Time> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = Time(rand() % 60, rand() % 60);
	}

	v.st = v.copyToStack();
	return v;
}

Time GetMax2(stack<Time> s)
{
	Time max = s.top();
	s.pop();

	while (!s.empty())
	{
		if (s.top() > max)
		{
			max = s.top();
		}

		s.pop();
	}
	return max;
}

Time GetMin2(stack<Time> s, int& pos)
{
	Time min = s.top();
	s.pop();
	pos = 0;
	int i = 1;

	while (!s.empty())
	{
		if (s.top() < min)
		{
			min = s.top();
			pos = i;
		}
		s.pop();
		i++;
	}

	return min;
}

Time GetAverage2(stack<Time> s)
{
	int sum = 0;
	int size = s.size();

	while (!s.empty())
	{
		sum += s.top().toNumber();
		s.pop();
	}

	int a = sum / size;

	return Time(a / 60, a % 60);
}

void AddForEach(VectorS<Time>* v, Time b)
{
	for (int i = 0; i < v->Size(); i++)
	{
		(*v)[i] = (*v)[i] + b;
	}
}

void Execute5()
{
	auto vec = MakeVectorS5(10);
	vec.insert(0, GetMax2(vec.st));
	int pos = -1;
	GetMin2(vec.st, pos);
	vec.erase(pos);

	vec = vec + GetAverage2(vec.st);
}