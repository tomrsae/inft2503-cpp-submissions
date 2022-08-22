#include <iostream>
#include <fstream>

const int TEMPS_TO_READ = 5;

void read_temperatures(double[], int);

int main() {
    double temperatures[TEMPS_TO_READ];
    
    read_temperatures(temperatures, TEMPS_TO_READ);

    std::cout << "Read temperatures from file:\n";
    for (int i = 0; i < TEMPS_TO_READ; i++) {
        std::cout << "Temperature " << (i + 1) << ": " << temperatures[i] << "\n";
    }

    return 0;
}

void read_temperatures(double temperatures[], int len) {
    const char* filename = "../temperatures.txt";
    std::ifstream file;
    file.open(filename);
    if (!file) {
        exit(EXIT_FAILURE);
    }

    double temp;
    int i = 0;
    while (file >> temp) {
        if (i >= len) return;

        temperatures[i] = temp;
        i++;
    }
}