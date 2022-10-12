#include <iostream>
#include "set.hpp"

int main() {
    Set A;
    A.add(1);
    A.add(5);
    A.add(1);
    std::cout << "A := " << A << "\n";

    Set B { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    B.add(10);
    std::cout << "B := " << B << "\n";

    std::cout << "A U B = " << A.U(B) << "\n";

    Set C = A;
    std::cout << "C = A = " << C << "\n";

    Set D;
    std::cout << "D = " << D << "\n";

    return 0;
}