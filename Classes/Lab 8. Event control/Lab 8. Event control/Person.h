#pragma once
#include "Object.h"
#include <string>

using namespace std;

class Person : public Object
{
public:
	Person();
	virtual ~Person();
	void Show();
	void Input();
	Person(string, int);
	Person(const Person&);

	string GetName() { return name; }
	int GetAge() { return age; }

	void SetName(string);
	void SetAge(int);

	Person& operator=(const Person&);
protected:
	string name;
	int age;
};