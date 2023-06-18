#pragma once
#include <string>
#include <iostream>
using namespace std;
class Pair
{
public:
	Pair(int, int);
	Pair(const Pair&);

	int GetFirst() const { return first; }
	int GetSecond() const { return second; }

	void SetFirst(int f) { first = f; };
	void SetSecond(int s) { second = s; };

	bool operator>(const Pair&);

	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);

protected:
	int first;
	int second;
};