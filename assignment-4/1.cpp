#include <iostream>
#include <vector>
#include <algorithm>

void find_and_print(const std::vector<double>&, double);

int main() {
    std::vector<double> vec;
    vec.emplace_back(1.34);
    vec.emplace_back(5.212);
    vec.emplace_back(2.07);
    vec.emplace_back(3.44467);
    vec.emplace_back(9.1564);

    std::cout << "Numbers in vector:\n";
    for (auto &el : vec) {
        std::cout << el << std::endl;
    }

    // front()
    std::cout << "\nfront() funtion on vector gives: " << vec.front() << std::endl;

    // back()
    std::cout << "back() funtion on vector gives: " << vec.back() << std::endl << std::endl;

    // Assignment is vague:
    // asks to insert number AFTER first element, then print result using front() - this won't print the result.
    // Therefore I did it both ways:

    // front() does NOT print result of emplace()
    vec.emplace(vec.begin() + 1, 2.22);
    std::cout << "front() function after inserting element AFTER first element: " << vec.front() << std::endl;

    // front() DOES print result of emplace()
    vec.emplace(vec.begin(), 0.378);
    std::cout << "front() function after inserting element BEFORE first element: " << vec.front() << std::endl << std::endl;

    // find()
    
    // find existing value
    std::cout << "Finding exisitng value:\n";
    find_and_print(vec, 5.212);

    // find non-existing value
    std::cout << "\nFinding non-existing value:\n";
    find_and_print(vec, -22222);

    return 0;
}

void find_and_print(const std::vector<double>& vec, double val_to_find) {
    auto found = find(vec.begin(), vec.end(), val_to_find);

    if (found != vec.end()) {
        std::cout << "Found value " << *found << std::endl;
    } else {
        std::cout << "Failed to find value " << val_to_find << std::endl;
    }
}