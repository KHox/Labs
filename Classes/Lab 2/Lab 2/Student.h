#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	string group;
	float marks;

public:
	Student();
	Student(string, string, float);
	Student(const Student&);
	~Student();

	string GetName();
	void SetName(string);

	string GetGroup();
	void SetGroup(string);

	float GetMarks();
	void SetMarks(float);

	void Show();
};