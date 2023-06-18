#include "fraction.h"

//Lab 1. Classes and objects

fraction make_fraction(int F, int S)
{
	fraction t;//создали временную переменную
	t.Init(F, S);//инициализировали поля переменной t с помощью параметров функции
	return t;//вернули значение переменной t
}

void main()
{
	setlocale(LC_ALL, "");
	fraction t;
	t.Read();
	if ((t.first > 0) && (t.second > 0))
	{
		cout <<"Целая часть F/S "<< t.ipart() << "\n";
	}
	else
	{
		cout << "Введите положительное целое число!" << endl;
	}
	//определение переменных А и В
	fraction A;
	fraction B;
	A.Init(12, 3);//инициализация переменной
	B.Read();//ввод полей переменных через консоль

	A.Show();//вывод значений полей переменной
	cout << "A.Power(" << A.first << "," << A.second << ")=" << A.Power() << endl;

	B.Show();//вывод значений полей переменной В
	cout << "B.Power(" << B.first << "," << B.second << ")=" << B.Power() << endl;

	cout << "\nСпособ через указатель\n";
	//указатели
	fraction* X = new fraction;//выделение памяти под динамическую переменную
	X->Read();//инициализация

	X->Show();//вывод значений полей
	cout << "X.Power(" << X->first << "," << X->second << ")=" << X->Power() << endl;

	//массивы
	cout << "\nСпособ массивов без указателей\n";
	fraction mas[3];//определение массива
	for (int i = 0; i < 3; i++)
		mas[i].Read();//чтение значений полей

	for (int i = 0; i < 3; i++)
		mas[i].Show(); //вывод значений полей

	for (int i = 0; i < 3; i++)
	{
		cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Power() << endl;
	}

	//динамические масивы
	cout << "\nСпособ массивов с указателями\n";
	fraction* p_mas = new fraction[3];//выделение памяти
	for (int i = 0; i < 3; i++)
		p_mas[i].Read();//чтение значений полей
	for (int i = 0; i < 3; i++)
		p_mas[i].Show();//вывод значений полей

	for (int i = 0; i < 3; i++)
	{
		cout << "p_mas[" << i << "].Power(" << p_mas[i].first << "," << p_mas[i].second; cout << ")=" << p_mas[i].Power() << endl;
	}

	//вызов функции make_fraction()
	cout << "Способ через функцию" << endl;
	int y; int z;
	cout << "first:"; cin >> y;
	cout << "second:"; cin >> z;
	//переменная F формируется с помощью функции make_fraction()
	fraction F = make_fraction(y, z);
	F.Show();
}