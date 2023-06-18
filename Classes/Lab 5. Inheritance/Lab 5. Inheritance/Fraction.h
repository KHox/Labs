#pragma once
#include "Pair.h"

class Fraction : public Pair
{
public:
    Fraction(int iPart, int fParct);

    int getIntegerPart() const { return GetFirst(); };
    int getFractionalPart() const { return GetSecond(); };
    void setIntegerPart(int iPart);
    void setFractionalPart(int fPart);

    bool operator>(const Fraction& f) const;
    bool operator==(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
};