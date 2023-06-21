#include "stack.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	stack s(5);
	s.push(20);
	s.showlast();
	s.push(40);
	s.showlast();
	s.pop();
	s.showlast();
	cout << s.getsize();
}