#include "fraction.hpp"

///
/// Authored by lecturer Ole Christian Eidheim
/// Modified by Tommy René Sætre
///

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
    set(numerator, denominator);
}

void Fraction::set(int numerator_, int denominator_) {
    if (denominator_ != 0) {
        numerator = numerator_;
        denominator = denominator_;
        reduce();
    } else {
        throw "denominator is zero";
    }
}

Fraction Fraction::operator+(const Fraction &other) const {
    Fraction fraction = *this;
    fraction += other;
    return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    set(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
    Fraction fraction = *this;
    fraction -= other;
    return fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    set(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator-() const {
    Fraction fraction;
    fraction.numerator = -numerator;
    fraction.denominator = denominator;
    return fraction;
}

Fraction Fraction::operator-(const int& integer) const {
    Fraction other(integer, 1);

    return *this - other;
}

Fraction operator-(int integer, const Fraction& fraction) {
    Fraction other(integer * fraction.denominator, fraction.denominator);

    return other - fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction fraction = *this;
    fraction *= other;
    return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    set(numerator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    Fraction fraction = *this;
    fraction /= other;
    return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    set(numerator * other.denominator, denominator * other.numerator);
    return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const {
    return (compare(other) == 0) ? true : false;
}

bool Fraction::operator!=(const Fraction &other) const {
    return (compare(other) != 0) ? true : false;
}

bool Fraction::operator<=(const Fraction &other) const {
    return (compare(other) <= 0) ? true : false;
}

bool Fraction::operator>=(const Fraction &other) const {
    return (compare(other) >= 0) ? true : false;
}

bool Fraction::operator<(const Fraction &other) const {
    return (compare(other) < 0) ? true : false;
}

bool Fraction::operator>(const Fraction &other) const {
    return (compare(other) > 0) ? true : false;
}

Fraction::operator double() const {
    return double(numerator) / denominator;
}

Fraction::operator float() const {
    return float(numerator) / denominator;
}

std::ostream &operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = numerator;
    int b = denominator;
    int c;
    if (a < 0)
        a = -a;

    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    numerator /= a;
    denominator /= a;
}

int Fraction::compare(const Fraction &other) const {
    Fraction fraction = *this - other;
    if (fraction.numerator > 0)
        return 1;
    else if (fraction.numerator == 0)
        return 0;
    else
        return -1;
}