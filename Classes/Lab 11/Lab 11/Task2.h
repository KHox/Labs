#pragma once
#include <iostream>
#include <vector>
#include "Time.h"

using namespace std;

vector<Time> MakeVector2(int n)
{
	vector<Time> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = Time(rand() % 60, rand() % 60);
	}
	return v;
}

Time GetMax(vector<Time>* v)
{
	Time max = (*v)[0];

	for (int i = 1; i < v->size(); i++)
	{
		if ((*v)[i] > max)
		{
			max = (*v)[i];
		}
	}
	return max;
}

Time GetMin(vector<Time>* v, int& pos)
{
	Time min = (*v)[0];
	pos = 0;

	for (int i = 1; i < v->size(); i++)
	{
		if ((*v)[i] < min)
		{
			min = (*v)[i];
			pos = i;
		}
	}

	return min;
}

Time GetAverage(vector<Time>* v)
{
	int sum = 0;

	for (int i = 0; i < v->size(); i++)
	{
		sum += (*v)[i].toNumber();
	}

	int a = sum / v->size();

	return Time(a / 60, a % 60);
}

void AddForEach(vector<Time>* v, Time b)
{
	for (int i = 0; i < v->size(); i++)
	{
		(*v)[i] = (*v)[i] + b;
	}
}

void Execute2()
{
	auto vec = MakeVector2(10);

	vec.insert(vec.begin(), GetMax(&vec));

	int pos = -1;
	GetMin(&vec, pos);

	vec.erase(vec.begin() + pos);

	AddForEach(&vec, GetAverage(&vec));
}