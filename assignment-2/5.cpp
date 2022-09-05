#include <iostream>

int main() {
    double number;
    double* p = &number;
    double& r = number;

    number = 1;
    std::cout << number << "\n";

    *p = 2;
    std::cout << number << "\n";

    r = 3;
    std::cout << number << "\n";

    return 0;
}