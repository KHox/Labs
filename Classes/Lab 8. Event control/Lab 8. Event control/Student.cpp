#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() :Person()
{
	rating = 0;
}

Student::~Student()
{
}

Student::Student(string n, int a, float r) :Person(n, a)
{
	rating = r;
}

Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	rating = s.rating;
}

void Student::SetRating(float r)
{
	rating = r;
}

Student& Student::operator=(const Student& s)
{
	if (&s != this)
	{
		name = s.name;
		age = s.age;
		rating = s.rating;
	}
	return *this;
}

void Student::Show()
{
	Person::Show();
	cout << "Rating: " << rating << endl;
}

void Student::Input()
{
	Person::Input();
	cout << "Rating = ";
	cin >> rating;
}