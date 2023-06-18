#pragma once
#include <iostream>
#include <stack>
#include "Time.h"

using namespace std;

stack<Time> MakeStack(int n)
{
	stack<Time> s;
	for (int i = 0; i < n; i++)
	{
		s.push(Time(rand() % 60, rand() % 60));
	}
	return s;
}

Time GetMax(stack<Time> s)
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

Time GetMin(stack<Time> s, int& pos)
{
	Time min = s.top();
	s.pop();
	pos = 0;
	int i = 1;

	while(!s.empty())
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

Time GetAverage(stack<Time> s)
{
	int sum = 0;
	int size = s.size();

	while(!s.empty())
	{
		sum += s.top().toNumber();
		s.pop();
	}

	int a = sum / size;

	return Time(a / 60, a % 60);
}

void AddForEach(stack<Time>& s, Time b)
{
	stack<Time> tmp;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		tmp.push(s.top() + b);
		s.pop();
	}

	for (int i = 0; i < size; i++)
	{
		s.push(tmp.top());
		tmp.pop();
	}
}

/*
void Insert(stack<Time>& s, int pos, Time elem)
{
	stack<Time> tmp;
	for (int i = 0; i < pos; i++)
	{
		tmp.push(s.top());
		s.pop();
	}

	s.push(elem);

	for (int i = 0; i < pos; i++)
	{
		s.push(tmp.top());
		tmp.pop();
	}
}
*/

void Erase(stack<Time>& s, int pos)
{
	stack<Time> tmp;
	for (int i = 0; i < pos; i++)
	{
		tmp.push(s.top());
		s.pop();
	}

	s.pop();

	for (int i = 0; i < pos; i++)
	{
		s.push(tmp.top());
		tmp.pop();
	}
}

void Execute4()
{
	auto st = MakeStack(10);

	st.push(GetMax(st));
	int pos = -1;
	GetMin(st, pos);
	Erase(st, pos);

	AddForEach(st, GetAverage(st));
}