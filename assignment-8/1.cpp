#include <iostream>
#include <iomanip>
#include <cmath>

template <typename T>
bool equal(T, T);

double equal(double, double);

int main() {
    int a = 2;
    int b = 2;

    std::string c("somestr");
    std::string d("somestr");

    double e = 1.23456789;
    double f = 1.2345689;

    bool ab_eq = equal(a, b);
    bool cd_eq = equal(c, d);
    bool ef_eq = equal(e, f);

    std::cout << "\n";
    std::cout << "a: " << a << " & b: " << b << " are " << (!ab_eq ? "not " : "") << "equal\n";
    std::cout << "c: " << c << " & d: " << d << " are " << (!cd_eq ? "not " : "") << "equal\n";
    std::cout << "e: " << std::setprecision(8) << e << " & f: " << f << " are " << (!ef_eq ? "not " : "") << "equal\n";
    std::cout << "\n";

    int g = 3;
    int h = 2;

    std::string i("somestring");
    std::string j("somestr");

    double k = 1.23456789;
    double l = 1.2345789;

    bool gh_eq = equal(g, h);
    bool ij_eq = equal(i, j);
    bool kl_eq = equal(k, l);

    std::cout << "\n";
    std::cout << "g: " << g << " & h: " << h << " are " << (!gh_eq ? "not " : "") << "equal\n";
    std::cout << "i: " << i << " & j: " << j << " are " << (!ij_eq ? "not " : "") << "equal\n";
    std::cout << "k: " << std::setprecision(8) << k << " & l: " << l << " are " << (!kl_eq ? "not " : "") << "equal\n";

    return 0;
}

template <typename T>
bool equal(T a, T b) {
    std::cout << "Template function called\n";

    return a == b;
}

double equal(double a, double b) {
    std::cout << "double overload function called\n";

    double epsilon = 0.00001;
    return std::abs(a - b) < epsilon;
}