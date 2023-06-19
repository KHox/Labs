#pragma once
#include <iostream>
#include <map>
#include "Time.h"
#include "Vector.h"
using namespace std;

void Execute3()
{
    int n;
    cout << "n = ";
    cin >> n;
    Vector<Time> container(n);
    for (int i = 0; i < n; i++)
    {
        Time t;
        cin >> t;
        container[i] = t;
    }

    container.Print();
    cout << endl;

    int pos = container.Max();
    container.insert(0, container[pos]);
    container.Print();
    cout << endl;

    int b = container.Min();
    container.erase(b);
    container.Print();
    cout << endl;

    Time c = container.Average();
    container = container + c;
    container.Print();
    cout << endl;
}