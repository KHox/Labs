#pragma once
#include <iostream>
#include "fraction.h"
using namespace std;

struct fraction
{
	double first;
	int second;
	void Init(int, int);
	void Read(); //метод для инициализации полей void Read();
	//метод для чтения значений полей
	void Show();
	int Power();
	int ipart();
	//метод для вывода значений полей double Power();
	//вычисление степени
};