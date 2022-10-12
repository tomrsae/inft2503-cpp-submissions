#include <algorithm>
#include "set.hpp"

Set::Set() : vec(std::vector<int>()) { }

Set::Set(const Set& other) : vec(other.vec) { }

Set::Set(std::initializer_list<int> init_list) {
    for (auto element : init_list) {
        add(element);
    }
}

Set::Set(std::vector<int> vec) : vec(vec) { }

Set Set::U(const Set& other) const {
    Set new_set(vec);
    for (auto element : other.vec) {
        new_set.add(element);
    }

    return new_set;
}

void Set::add(const int element) {
    if (std::find(vec.begin(), vec.end(), element) == vec.end()) {
        vec.push_back(element);
    }
}

std::ostream &operator<<(std::ostream& os, const Set& set) {
    os << "{";
    for (size_t i = 0; i < set.vec.size(); i++) {
            os << " " << set.vec.at(i);
        if (i < set.vec.size() - 1) {
            os << ",";
        }
    }
    os << " }";

    return os;
}