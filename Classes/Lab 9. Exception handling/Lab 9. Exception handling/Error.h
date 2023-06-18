#pragma once
#include <string>
#include <iostream> 

using namespace std;

class Error
{
string str;
public:
	Error(string s) { str = s; }
	friend ostream& operator<<(ostream& out, const Error& err) { cout << err.str << endl; return cout; }
};
