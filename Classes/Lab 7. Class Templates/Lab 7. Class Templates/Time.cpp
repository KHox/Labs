#include "Time.h"
#include <iostream>
using namespace std;

Time Time::operator+(const Time& t)
{
	int tt = min * 60 + sec + t.min * 60 + t.sec;
	return Time(tt / 60, tt % 60);
}

Time& Time::operator=(const Time& t)
{
	min = t.min;
	sec = t.sec;
	return *this;
}

bool Time::operator ==(const Time& t)
{
	return t.min == min && t.sec == sec;
}

istream& operator >>(istream& in, Time& t)
{
	cout << "minutes = ";
	in >> t.min;
	cout << "seconds = ";
	in >> t.sec;
	return in;
}

ostream& operator <<(ostream& out, const Time& t)
{
	return (out << t.min << ":" << t.sec);
}