#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

std::ostream &operator<<(std::ostream &out, const std::vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
    std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    std::cout << "v1: " << v1 << std::endl;

    std::vector<int> v2 = {2, 3, 12, 14, 24};
    std::cout << "v2: " << v2 << std::endl;

    // a)
    auto r1 = std::find_if(v1.begin(), v1.end(), [](int element) {
        return element > 15;
    });

    std::cout << "First element in v1 bigger than 15: " << *r1 << "\n";

    // b)
    auto approx_equal_predicate = [](int e1, int e2) {
        return std::abs(e1 - e2) <= 2;
    };

    auto r2 = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), approx_equal_predicate);

    std::cout << "First five elements in v1 and v2 are " << (r2 ? "" : "NOT ") << "approximately equal (difference <= 2)\n";

    auto r3 = std::equal(v1.begin(), v1.begin() + 4, v2.begin(), approx_equal_predicate);

    std::cout << "First four elements in v1 and v2 are " << (r3 ? "" : "NOT ") << "approximately equal (difference <= 2)\n";

    // c)
    std::cout << "v1 with odd numbers replaced with 100: { ";
    std::replace_copy_if(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ", "), [] (int element) {
        return element % 2 == 1;
    }, 100);
    std::cout << "}\n";

}