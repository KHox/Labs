#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "Time.h"

using namespace std;

typedef stack<Time>St;
typedef vector<Time>Vec;

Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[v.size() - 1 - i]);
	}
	return s;
}

void PrintStack(St s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl;
}

St MakeStack(int n)
{
	St s;
	for (int i = 0; i < n; i++)
	{
		Time t;
		cin >> t;
		s.push(t);
	}
	return s;
}

Time Average(St s)
{
	int n = s.size();
	Time sum = s.top();
	s.pop();
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
	}
	return sum / n;
}

void add(Time& t, Time& average)
{
	t = t + average;
}

void ReplaceMaxElement(St& s, const Time& a)
{
	Vec v = copy_stack_to_vector(s);

	replace(v.begin(), v.end(), *max_element(v.begin(), v.end()), a);

	s = copy_vector_to_stack(v);
}

void EraseMinElement(St& s)
{
	Vec v = copy_stack_to_vector(s);

	auto i = remove(v.begin(), v.end(), *min_element(v.begin(), v.end()));
	v.erase(i, v.end());

	s = copy_vector_to_stack(v);
}

void ForEachInc(St& s, Time a)
{
	Vec v = copy_stack_to_vector(s);

	for_each(v.begin(), v.end(), [&](Time& t)
		{
			t = t + a;
		});

	s = copy_vector_to_stack(v);
}

void Execute2()
{
	int n;
	cout << "n = ";
	cin >> n;

	St s = MakeStack(n);
	PrintStack(s);

	Time a;
	cin >> a;

	ReplaceMaxElement(s, a);
	PrintStack(s);

	EraseMinElement(s);
	PrintStack(s);

	ForEachInc(s, Average(s));
	PrintStack(s);
}