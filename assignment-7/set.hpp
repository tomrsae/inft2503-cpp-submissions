#pragma once
#include <vector>
#include <sstream>

class Set {
public:
    Set();
    Set(const Set&);
    Set(std::vector<int>);
    Set(std::initializer_list<int>);
    Set U(const Set&) const;
    void add(const int);

    friend std::ostream &operator<<(std::ostream&, const Set&);

private:
    std::vector<int> vec;
};