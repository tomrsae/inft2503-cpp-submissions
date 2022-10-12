#include <iostream>
#include "set.hpp"

int main() {
    Set A;
    A += 1;
    A += 5;
    A += 1;
    std::cout << "A := " << A << "\n";

    Set B { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    B += 10;
    std::cout << "B := " << B << "\n";

    std::cout << "A U B = " << (A + B) << "\n";

    Set C = A;
    std::cout << "C = A = " << C << "\n";

    Set D;
    std::cout << "D = " << D << "\n";

    return 0;
}