#include <iostream>
#include "Pair.h"
#include "Fraction.h"

//Lab 5. Inheritance

using namespace std;

void main()
{
	Pair p1(4, 5);
	Pair p2(5, 2);

	cout << "Pair 1:\n" << p1 << "Pair 2:\n" << p2;
	cout << "p1 > p2: " << boolalpha << (p1 > p2) << endl;

	Fraction f1(2, 5);
	Fraction f2(3, 6);
	cout << "f1 >  f2: " << boolalpha << (f1 > f2) << endl;
	cout << "f1 == f2: " << boolalpha << (f1 == f2) << endl;
	cout << "f1 <  f2: " << boolalpha << (f1 < f2) << endl;
	cout << "f1 <= f2: " << boolalpha << (f1 <= f2) << endl;
	cout << "f1 >= f2: " << boolalpha << (f1 >= f2) << endl;
}