#include "fraction.h"
void fraction::Init(int F, int S)
{
	first = F; second = S;
}
void fraction::Read()
{
	cout << "first:";
	cin >> first; cout << "second:"; cin >> second;
}
void fraction::Show()
{
	cout << "\nfirst=" << first; cout << "\nsecond=" << second; cout << "\n";
}
int fraction::Power()
{
	return pow(first, second);
}
int fraction::ipart()
{
	return(first / second);
}