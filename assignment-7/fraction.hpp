#pragma once
#include <sstream>

///
/// Authored by lecturer Ole Christian Eidheim
/// Modified by Tommy René Sætre
///

class Fraction {
public:
  int numerator;
  int denominator;

  Fraction();
  Fraction(int, int);
  void set(int, int = 1);
  Fraction operator+(const Fraction &) const;
  Fraction operator-(const Fraction&) const;
  Fraction operator*(const Fraction&) const;
  Fraction operator/(const Fraction&) const;
  Fraction operator-() const;
  Fraction operator-(const int&) const;
  Fraction &operator++();
  Fraction &operator--();
  Fraction &operator+=(const Fraction&);
  Fraction &operator-=(const Fraction&);
  Fraction &operator*=(const Fraction&);
  Fraction &operator/=(const Fraction&);
  Fraction &operator=(const Fraction&);
  bool operator==(const Fraction&) const;
  bool operator!=(const Fraction&) const;
  bool operator<=(const Fraction&) const;
  bool operator>=(const Fraction&) const;
  bool operator<(const Fraction&) const;
  bool operator>(const Fraction&) const;
  operator double() const;
  operator float() const;

  friend std::ostream &operator<<(std::ostream&, const Fraction&);
  friend Fraction operator-(int, const Fraction&);

private:
  void reduce();
  int compare(const Fraction&) const;
};