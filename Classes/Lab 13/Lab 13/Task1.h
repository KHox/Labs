#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Time.h"

using namespace std;
typedef vector<Time> TVector;

TVector MakeVector(int n)
{
	Time a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void PrintVector(TVector v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

Time Average(TVector v)
{
	Time s = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		s = s + v[i];
	}
	return s / v.size();
}

void Execute1()
{
	int n;
	cout << "n = ";
	cin >> n;

	TVector v = MakeVector(n);

	Time max = *(max_element(v.begin(), v.end()));
	Time a;
	cin >> a;

	replace(v.begin(), v.end(), max, a);
	PrintVector(v);

	cout << endl;

	auto i = remove(v.begin(), v.end(), *min_element(v.begin(), v.end()));
	v.erase(i, v.end());
	PrintVector(v);
	cout << endl;

	Time s = Average(v);
	for_each(v.begin(), v.end(), [&](Time& t) { t = t + s; });
	PrintVector(v);
}