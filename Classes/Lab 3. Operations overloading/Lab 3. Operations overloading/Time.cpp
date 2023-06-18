#include "Time.h"
#include <iostream>
using namespace std;

Time Time::operator +(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60; 
	return p;
}

bool Time::operator ==(const Time& t)
{
	return t.min == min && t.sec == sec;
}

istream& operator >>(istream&in, Time&t)
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