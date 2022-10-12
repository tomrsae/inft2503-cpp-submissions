#include <iostream>
#include "fraction.hpp"

int main() {
    Fraction f1(2,7);

    Fraction f2 = f1 - 3;
    std::cout << f1 << " - 3 = " << f2 << " = " << double(f2) << "\n";

    Fraction f3 = 5 - f1;
    std::cout << "5 - " << f1 << " = " << f3 << " = " << double(f3) << "\n";

    Fraction f4 = 5 - 3 - f1 - 7 - f3;
    // b) Analyzing the above statement (declaration of f4):
    //
    // First of all, the operator precedence follows the C++ standard,
    // meaning they are evaluated sequentially in this case (as it's only -).
    //
    // Therefore, let's analyze the statement left to right:
    // 5 - 3 is evaluated to be 2, using the standard integer operator -.
    //
    // (5 - 3) - f1 = 2 - f1 is evaluated using the friend function `Fraction operator-(int, const Fraction&)`.
    //
    // ((5 - 3) - f1) - 7 = (2 - f1) - 7 is evaluated using the member function `Fraction operator-(const int&) const;`.
    // This is because the last evaluation (2 - f1) was evaluated as a fraction (return value of friend function is Fraction).
    //
    // (((5 - 3) - f1) - 7) - f3 = ((2 - f1) - 7) - f3 is evaluated using the member function `Fraction operator-(const Fraction&) const`.
    // This is because the last evaluation ((2 - f1) - 7) was also evaluated as a fraction (return value of member function is Fraction).
    //
    // Hence, all - operator overloads are used in this statement.
    std::cout << "5 - 3 - " << f1 << " - 7 - " << f3 << " = " << f4 << " = " << double(f4) << "\n";

    return 0;
}