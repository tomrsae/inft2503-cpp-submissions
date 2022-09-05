#include <iostream>

int main() {
    // a)
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    // i = 3
    // j = 5
    // p = address of i, something along the lines of 0x7fffe0861910. Dereferencing this pointer would result in i's value (3)
    // q = address of j, something along the lines of 0x7fffe0861914. Dereferencing this pointer would result in j's value (5)

    std::cout << "Value of i = " << i << "\n";
    std::cout << "Address of i = " << &i << "\n\n";

    std::cout << "Value of j = " << j << "\n";
    std::cout << "Address of j = " << &j << "\n\n";

    std::cout << "Value of p = " << *p << "\n";
    std::cout << "Address of p = " << p << "\n\n";
    
    std::cout << "Value of q = " << *q << "\n";
    std::cout << "Address of q = " << q << "\n\n";

    // Yes, my assumptions did correspond to the actual output.

    // b)
    *p = 7; // i now has a value of 7
    *q += 4; // j now has a value of 5 + 4 = 9
    *q = *p + 1; // j now has a value of i + 1 = 7 + 1 = 8
    p = q; // p now points to j instead, i remains unchanged

    std::cout << *p << " " << *q << "\n";

    // Everything checks out with my assumptions.

    return 0;
}