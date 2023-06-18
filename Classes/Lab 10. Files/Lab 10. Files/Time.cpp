#include <iostream>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}

Time Time::operator=(const Time& t)
{
	if (&t != this)
	{
		min = t.min;
		sec = t.sec;
	}
	return *this;
}

Time Time::operator+(const Time& t)
{
	int sum = (min + t.min) * 60 + sec + t.sec;
	return Time(sum / 60, sum % 60);
}

bool Time::operator==(const Time& t)
{
	return t.min == min && t.sec == sec;
}

ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec;
	return out;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "min = ";
	in >> t.min;
	cout << "sec = ";
	in >> t.sec;
	return in;
}

fstream& operator<<(fstream& fout, const Time& t)
{
	fout << t.min << ":" << t.sec << endl;
	return fout;
}


fstream& operator>>(fstream& fin, Time& t)
{
	string s;
	fin >> s;

	if (s != "")
	{
		t.min = stoi(s.substr(0, s.find(":")));
		t.sec = stoi(s.substr(s.find(":") + 1));
	}

	return fin;
}