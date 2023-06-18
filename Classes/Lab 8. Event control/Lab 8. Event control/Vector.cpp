#include "Vector.h"
#include <iostream>

using namespace std;

Vector::~Vector(void)
{
    if (beg != 0)
    {
        delete[] beg;
    }
    beg = 0;
}

Vector::Vector(int n)
{
    beg = new Object * [n];
    cur = 0;
    size = n;
}

void Vector::Add(Object* elem)
{
    if (cur < size)
    {
        beg[cur] = elem;
        cur++;
        cout << "> Object successfully added\n";
    }
    else
    {
        cout << "> Vector is full\n";
    }
}
void Vector::Show()
{
    if (cur == 0)
    {
        cout << "Empty\n";
        return;
    }

    Object** p = beg;

    for (int i = 0; i < cur; i++)
    {
        (*p++)->Show();
    }
}

int Vector::operator ()()
{
    return cur;
}

Object* Vector::TryGet(int n, bool& tg)
{
    if (n < cur && n > -1)
    {
        tg = true;
        return beg[n];
    }
    else
    {
        cout << "> Index Error\n";
        tg = false;
        return NULL;
    }
}

void Vector::Del()
{
    if (cur != 0)
    {
        cur--;
        beg[cur] = NULL;
        cout << "> Last Object successfully deleted\n";
    }
    else
    {
        cout << "> Vector is Empty\n";
    }
}