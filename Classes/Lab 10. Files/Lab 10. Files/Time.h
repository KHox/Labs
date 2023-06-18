#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Time
{
public:
	Time() { min = 0; sec = 0; };
	Time(int m, int s) { min = m; sec = s; };
	Time(const Time&);

	Time operator=(const Time&);
	Time operator+(const Time&);
	bool operator==(const Time&);

	friend ostream& operator<<(ostream&, const Time&);
	friend istream& operator>>(istream&, Time&);

	friend fstream& operator<<(fstream&, const Time&);
	friend fstream& operator>>(fstream&, Time&);

private:
	int min;
	int sec;
};
