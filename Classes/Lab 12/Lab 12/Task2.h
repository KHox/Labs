#pragma once;
#include <iostream>
#include <map>
#include "Time.h"

using namespace std;

typedef  std::multimap<int, Time> Tmap2;
typedef Tmap2::iterator it2;

Tmap2 createAndFillMultimap2(int n)
{
    Tmap2 container;
    for (int i = 0; i < n;i++)
    {
        Time a;
        cin >> a;
        container.insert(make_pair(i, a));
    }
    return container;
}
Time Average(Tmap2 v)
{
    Time s;
    int n = v.size();

    for (it2 it = v.begin(); it != v.end(); ++it)
    {
        s = s + it->second;
    }

    return s / n;
}

int Max(Tmap2 v)
{
    it2 i = v.begin();
    int pos = 0;
    int k = 0;
    Time m = i->second;

    while (i != v.end())
    {
        if (m < i->second)
        {
            m = i->second;
            pos = k;
        }
        ++i;
        ++k;
    }

    return pos;
}
int Min(Tmap2 v)
{
    it2 i = v.begin();
    int pos = 0;
    int k = 0;
    Time m = i->second;

    while (i != v.end())
    {
        if (m > i->second)
        {
            m = i->second;
            pos = k;
        }
        ++i;
        ++k;
    }
    return pos;
}
void del(Tmap2& container)
{
    int min = Min(container);

    auto it = container.begin();
    std::advance(it, min);

    container.erase(it);
}
void add(Tmap2& container)
{
    int max = Max(container);

    it2 maxIterator = container.begin();
    std::advance(maxIterator, max);

    auto& maxElement = *maxIterator;

    container.insert(container.begin()--, maxElement);
}
void add_avrg(Tmap2& container)
{
    Time avrg = Average(container);
    for (auto& elem : container)
    {
        elem.second = elem.second + avrg;
    }
}

void printMultimap(const Tmap2& container)
{
    for (const auto& element : container)
    {
        cout << "First: " << element.first << ", second: " << element.second << endl;
    }
}

void Execute2()
{
    int n;
    cout << "n = ";
    cin >> n;
    Tmap2 container = createAndFillMultimap2(n);
    printMultimap(container);
    cout << endl;

    add(container);
    printMultimap(container);
    cout << endl;

    del(container);
    printMultimap(container);
    cout << endl;

    add_avrg(container);
    printMultimap(container);
    cout << endl;
}