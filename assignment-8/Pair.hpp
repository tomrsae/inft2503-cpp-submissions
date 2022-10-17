template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 first, T2 second) : first(first), second(second) { }

    bool operator>(const Pair& other) const {
        return first > other.first && second > other.second;
    }
    
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }
};