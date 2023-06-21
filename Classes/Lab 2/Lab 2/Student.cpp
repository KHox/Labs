#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
	name = "Unnamed";
	group = "Ungrouped";
	marks = 0;
}

Student::Student(string N, string G, float M)
{
	name = N;
	group = G;
	marks = M;
}
Student::Student(const Student& t)
{
	name = t.name;
	group = t.group;
	marks = t.marks;
}

Student::~Student()
{
}
string Student::GetName()
{
	return name;
}

string Student::GetGroup()
{
	return group;
}

float Student::GetMarks()
{
	return marks;
}

void Student::SetName(string N)
{
	name = N;
}

void Student::SetGroup(string G)
{
	group = G;
}

void Student::SetMarks(float M)
{
	marks = M;
}

void Student::Show()
{
	cout << "name :" << name << endl;
	cout << "group :" << group << endl;
	cout << "marks :" << marks << endl;
}