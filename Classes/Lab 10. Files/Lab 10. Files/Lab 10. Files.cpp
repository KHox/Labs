#include <iostream>
#include "Time.h"
#include "FileProcess.h"

// Lab 10. Files

using namespace std;

enum CMD
{
	Quit,
	Make,
	Print,
	Del,
	Incr,
	Add
};

int main()
{
	string fName = "File1.txt";
	int cmd = -1;
	do
	{
		cout << "1. Make File\n";
		cout << "2. Print File\n";
		cout << "3. Delete Records with Time =\n";
		cout << "4. Increase Times by...\n";
		cout << "5. Add K Times after N-element\n";
		cout << "0. Quit\n";

		cin >> cmd;
		CMD c = static_cast<CMD>(cmd);
		Time t1, t2;
		int k, i;
		bool res = true;
		switch (c)
		{
		case Make:
			res = FillFile(fName);
			break;
		case Print:
			res = PrintFile(fName);
			break;
		case Del:
			cin >> t1;
			res = DelSame(fName, t1);
			break;
		case Incr:
			cin >> t1 >> t2;
			if (t2 == Time())
			{
				res = Increase(fName, t1);
			}
			else
			{
				res = Increase(fName, t1, t2);
			}
			break;
		case Add:
			cout << "Count = ";
			cin >> k;
			cout << "After = ";
			cin >> i;
			res = AddN(fName, k, i);
			break;
		}

		if (!res) {
			cout << "Something goes wrong!\n";
		}
	} while (cmd != 0);
}