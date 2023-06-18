#include "Pair.h"

Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

Pair::Pair(const Pair& Pair)
{
	first = Pair.first;
	second = Pair.second;
}

bool Pair::operator>(const Pair& p)
{
	return (first > p.first) || (first == p.first && second > p.second);
}

istream& operator >>(istream& in, Pair& p)
{
	cout << "First: ";
	in >> p.first;
	cout << "Second:";
	in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << p.first << ":" << p.second << "\n";
	return out;
}