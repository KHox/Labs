#pragma once
#include <fstream>
#include "Time.h"
#include <iostream>
//#include <string>

using namespace std;

bool FillFile(string fName)
{
	fstream stream(fName, ios::out | ios::trunc);

	if (!stream) return false;
	int n;
	cout << "n = ";
	cin >> n;

	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t;
	}
	stream.close();
	return true;
}

bool PrintFile(string fName)
{
	fstream stream(fName, ios::in);
	if (!stream) return false;

	Time t;
	while (stream >> t)
	{
		cout << t << endl;
	}
	stream.close();
	return true;
}

bool DelSame(string fName, Time tt)
{
	fstream fTemp("temp", ios::out);
	fstream stream(fName, ios::in);

	if (!stream || !fTemp) return false;

	Time t;
	while (stream >> t)
	{
		if (!(t == tt))
		{
			fTemp << t;
		}
	}

	stream.close();
	fTemp.close();
	remove(fName.c_str());
	rename("temp", fName.c_str());
	return true;
}

bool Increase(string fName, Time what, Time by = Time(1, 30))
{
	fstream fTemp("temp", ios::out);
	fstream stream(fName, ios::in);

	if (!stream || !fTemp) return false;

	Time t;
	while (stream >> t)
	{
		if (t == what)
		{
			fTemp << (t + by);
		}
		else
		{
			fTemp << t;
		}
	}

	stream.close();
	fTemp.close();
	remove(fName.c_str());
	rename("temp", fName.c_str());
	return true;
}

bool AddN(string fName, int addCount, int after)
{
	fstream fTemp("temp", ios::out);
	fstream stream(fName, ios::in);

	if (!stream || !fTemp) return false;

	Time t;
	int i = 0;
	while (stream >> t)
	{

		fTemp << t;
		if (i == after)
		{
			for (int j = 0; j < addCount; j++)
			{
				cin >> t;
				fTemp << t;
			}
		}
		i++;
	}

	stream.close();
	fTemp.close();
	remove(fName.c_str());
	rename("temp", fName.c_str());
	return true;
}