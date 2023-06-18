#include "fraction.h"

Fraction::Fraction(int iPart, int fPart) : Pair(iPart, fPart) {}

void Fraction::setIntegerPart(int iPart) {
    SetFirst(iPart);
}

void Fraction::setFractionalPart(int fPart) {
    SetSecond(fPart);
}

bool Fraction::operator>(const Fraction& f) const {

    return (getIntegerPart() > f.getIntegerPart()) || (getIntegerPart() == f.getIntegerPart() && getFractionalPart() > f.getFractionalPart());
}

bool Fraction::operator==(const Fraction& f) const {
    return getIntegerPart() == f.getIntegerPart() && getFractionalPart() == f.getFractionalPart();
}

bool Fraction::operator<(const Fraction& f) const {
    return f > *this && !(*this == f);
}

bool Fraction::operator<=(const Fraction& f) const {
    return !(*this > f);
}

bool Fraction::operator>=(const Fraction& f) const {
    return !(f > *this);
}