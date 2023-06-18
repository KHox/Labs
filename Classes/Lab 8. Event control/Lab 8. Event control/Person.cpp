#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person()
{
	name = "";
	age = 0;
}

Person::~Person()
{
}

Person::Person(string n, int a)
{
	name = n;
	age = a;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

void Person::SetName(string n)
{
	name = n;
}

void Person::SetAge(int a)
{
	age = a;
}

Person& Person::operator= (const Person& p)
{
	if (&p == this) return *this;

	name = p.name;
	age = p.age;

	return *this;
}

void Person::Show()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void Person::Input()
{
	cout << "Name = ";
	cin >> name;

	cout << "Age = ";
	cin >> age;
}