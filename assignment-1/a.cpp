#include <iostream>

int main() {
    const int TEMPS_TO_READ = 5;

    int below10 = 0, between10and20 = 0, above20 = 0;

    for (int i = 0; i < TEMPS_TO_READ; i++) {
        std::cout << "Enter temperature number " << (i + 1) << ": ";

        double input;
        std::cin >> input;

        if (input < 10) {
            ++below10;
        }
        else if (input >= 10 && input <= 20) {
            ++between10and20;
        }
        else if (input > 20) {
            ++above20;
        }
    }

    std::cout << "# below 10 is " << below10 << "\n";
    std::cout << "# between 10 and 20 (inclusive) is " << between10and20 << "\n";
    std::cout << "# above 20 is " << above20 << "\n";

    return 0;
}