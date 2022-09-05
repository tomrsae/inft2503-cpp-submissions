#include <iostream>

int find_sum(const int*, int);

int main() {
    const int TABLE_SIZE = 20;

    int table[TABLE_SIZE];
    for (int i = 1; i <= TABLE_SIZE; i++) {
        table[i - 1] = i;
    }

    int* table_it = table;

    int first_ten[10];
    for (int i = 0; i < 10; i++) {
        first_ten[i] = *table_it++;
    }

    int next_five[5];
    for (int i = 0; i < 5; i++) {
        next_five[i] = *table_it++;
    }

    int last_five[5];
    for (int i = 0; i < 5; i++) {
        last_five[i] = *table_it++;
    }

    int sum = find_sum(first_ten, 10);
    std::cout << "Sum of first 10 numbers = " << sum << "\n";

    sum = find_sum(next_five, 5);
    std::cout << "Sum of next 5 numbers = " << sum << "\n";
    
    sum = find_sum(last_five, 5);
    std::cout << "Sum of last 5 numbers = " << sum << "\n";

    return 0;
}

int find_sum(const int *table, int length) {
    // Instead of taking length as an argument, we could also do
    // sizeof(table)/sizeof(int)
    // However, the signature was given by the assignment, so I stuck to that.

    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }

    return sum;
}