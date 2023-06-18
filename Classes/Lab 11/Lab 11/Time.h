#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int min, sec;

public:
	Time(int m = 0, int s = 0) { min = m; sec = s; }
	Time(const Time& t) { min = t.min;sec = t.sec; }
	~Time() {};

	int get_min() { return min; }
	int get_sec() { return sec; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }

	int toNumber() { return min * 60 + sec; }

	Time operator+(const Time& t)
	{
		int temp1 = toNumber();
		int temp2 = t.min * 60 + t.sec;
		Time p;
		p.min = (temp1 + temp2) / 60;
		p.sec = (temp1 + temp2) % 60;
		return p;
	}

	bool operator>(const Time& t)
	{
		if (min > t.min || (min == t.min && sec > t.sec)) return true;
		return false;
	}

	bool operator==(const Time& t)
	{
		return t.min == min && t.sec == sec;
	}

	bool operator<(const Time& t)
	{
		if (*this > t || *this == t) return false;
		return true;
	}

	friend istream& operator>>(istream& in, Time& t)
	{
		cout << "minutes = ";
		in >> t.min;
		cout << "seconds = ";
		in >> t.sec;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Time& t)
	{
		return (out << t.min << ":" << t.sec);
	}
};