#include <iostream>
#include "Vector.h"

// Lab 6. Containers

using namespace std;

int main()
{
	Vector a(5);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";

	a[2] = 100;
	cout << a << "\n";

	Vector b(10);
	cout << b << "\n";

	b = a;
	cout << b << "\n";

	Vector c(10); 
	c = b + 100;
	cout << c << "\n";

	cout << "\nThe length of a = " << a() << endl;

	cout << "a.first() = " << *(a.first()) << endl;

	Iterator i = a.first();
	++i;
	cout << *i << endl;

	for (i = b.first(); i != b.last(); ++i)
	{
		cout << *i << endl;
	}
}