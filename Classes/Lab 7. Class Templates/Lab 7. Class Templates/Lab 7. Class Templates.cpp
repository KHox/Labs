#include <iostream>
#include "Time.h"
#include "Vector.h"

// Lab 7. Class Templates

using namespace std;

int main()
{
    Time t;
    cin >> t;
    cout << t << endl;

    Time t2;
    cin >> t2;
    cout << t2 << endl;

    
    t2 = t2 + t;
    cout << t2 << endl;

    Vector<Time> a(3, t2);
    cout << "Enter array:\n";
    cin >> a;
    
    cout << "Array a is:\n";
    cout << a;

    Vector<Time> b(5, t);
    cout << "Array b is:\n";
    cout << b;

    b = a;
    cout << "Array b is:\n";
    cout << b;

    cout << "a[2] is " << a[2] << endl;

    cout << "Size of a is " << a() << endl;

    b = a + 10;
    cout << "Array b is:\n";
    cout << b;
}