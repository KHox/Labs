#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<double> MakeVector(int n)
{
	vector<double> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = rand() % 100 - 50;
	}
	return v;
}

double GetMax(vector<double>* v)
{
	double max = (*v)[0];

	for (int i = 1; i < v->size(); i++)
	{
		if ((*v)[i] > max)
		{
			max = (*v)[i];
		}
	}

	return max;
}

double GetMin(vector<double>* v, int& pos)
{
	double min = (*v)[0];
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

double GetAverage(vector<double>* v)
{
	double sum = 0;

	for (int i = 0; i < v->size(); i++)
	{
		sum += (*v)[i];
	}

	return sum / v->size();
}

void AddForEach(vector<double>* v, double b)
{
	for (int i = 0; i < v->size(); i++)
	{
		(*v)[i] += b;
	}
}

void Execute1()
{
	auto vec = MakeVector(10);

	vec.insert(vec.begin(), GetMax(&vec));

	int pos = -1;
	GetMin(&vec, pos);

	vec.erase(vec.begin() + pos);

	AddForEach(&vec, GetAverage(&vec));
}