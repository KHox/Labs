#pragma once
#include <iostream>
#include "fraction.h"
using namespace std;

struct fraction
{
	double first;
	int second;
	void Init(int, int);
	void Read();
	void Show();
	int Power();
	int ipart();
};