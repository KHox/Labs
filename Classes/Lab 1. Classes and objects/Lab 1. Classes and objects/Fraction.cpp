#include "fraction.h"
//реализация метода для инициализации полей структуры
void fraction::Init(int F, int S)
{
	first = F; second = S;
}
//реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << "first:";
	cin >> first; cout << "second:"; cin >> second;
}
//реализация метода для вывода значений полей структуры
void fraction::Show()
{
	cout << "\nfirst=" << first; cout << "\nsecond=" << second; cout << "\n";
}
//метод для возведения в степень
int fraction::Power()
{
	return pow(first, second);
}
int fraction::ipart()
{
	return(first / second);
}