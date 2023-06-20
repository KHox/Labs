#pragma once
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef set<int> Set;

void ReplaceMax(Set& container, int newValue)
{
    if (!container.empty()) {
        int maxElement = *max_element(container.begin(), container.end());

        container.erase(maxElement);
        container.insert(newValue);
    }
}

void RemoveMin(Set& container)
{
    if (!container.empty()) {
        container.erase(*container.begin());
    }
}

void AddAverage(Set& container)
{
    if (!container.empty()) {
        int sum = 0;
        for (int num : container) {
            sum += num;
        }
        int average = sum / container.size();

        Set tempContainer;

        for (int num : container) {
            tempContainer.insert(num + average);
        }

        container = move(tempContainer);
    }
}

void PrintSet(Set container)
{
    for (int num : container) {
        cout << num << " ";
    }
    cout << endl;
}

Set MakeSet(int n)
{
    Set temp;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        temp.insert(a);
    }
    return temp;
}

void Execute3()
{
    int n;
    cout << "n = ";
    cin >> n;

    Set container = MakeSet(n);

    cout << "Replace n = ";
    cin >> n;

    ReplaceMax(container, n);
    PrintSet(container);

    RemoveMin(container);
    PrintSet(container);

    AddAverage(container);
    PrintSet(container);
}