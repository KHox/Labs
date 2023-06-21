#include <iostream>
#include <string>
#include "Student.h"

// Lab 2. Classes and objects

using namespace std;

Student MakeStudent()
{
	string n;
	string g;
	float m;
	cout << "Student name: ";
	getline(cin, n);
	cout << "Student group: ";
	getline(cin, g);
	cout << "Marks: ";
	cin >> m;

	return Student(n, g, m);
}

void PrintStudent(Student s)
{
	s.Show();
}

void main()
{
	Student s1;
	s1.Show();

	Student s2("Vitalik", "Group1", 15000);
	s2.Show();

	Student s3 = s2;

	s3.SetName("Demid");
	s3.SetGroup("Group2");
	s3.SetMarks(0);

	PrintStudent(s3);

	s1 = MakeStudent();
	s1.Show();
}