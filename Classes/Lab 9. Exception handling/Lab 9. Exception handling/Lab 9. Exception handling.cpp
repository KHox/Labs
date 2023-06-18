#include <iostream>
#include "Vector.h"
#include "Error.h"

// Lab 9. Exception handling

using namespace std;

int main()
{
	try
	{
		Vector x(2);
		Vector y;
		cout << x;

		y = x + 5;

		int i;
		cout << "Enter index\n> ";
		cin >> i;

		cout << y[i] << endl;

		int len;
		cout << "Enter length of Vector (Max: 30)\n> ";
		cin >> len;

		Vector z(len);

		int count;
		cout << "Enter count of items to remove\n> ";
		cin >> count;

		x - count;
		cout << x;
	}
	catch (Error err)
	{
		cout << err;
	}
}