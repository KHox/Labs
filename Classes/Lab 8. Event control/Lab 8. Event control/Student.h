#pragma once
#include "Person.h"

class Student : public Person
{
public:
	Student();
	~Student();
	void Show();
	void Input();

	Student(string, int, float);
	Student(const Student&);
	
	float GetRating() { return rating; }
	void SetRating(float);

	Student& operator=(const Student&);

protected:
	float rating;
};