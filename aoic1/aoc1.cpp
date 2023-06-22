#include <iostream>
#include <sstream>

#define SIZE 3

int addUpCals(bool* endFlag);

void updateMaxCals(int maxCalsArray[], int size, int cals);

int sumMaxCals(int maxCalsArray[], int size);

int main() {
    int maxCals[] = {0, 0, 0};
    bool endFlag = false;
    while (!endFlag) {
        int cals = addUpCals(&endFlag);
        updateMaxCals(maxCals, SIZE, cals);
    }
    std::cout << sumMaxCals(maxCals, SIZE) << '\n';
    return 0;
}

// Gets the calorires for the current elf
int addUpCals(bool* endFlag) {
    int cals = 0;
    std::string line;
    *endFlag = true;
    std::getline(std::cin, line);
    while (!line.empty()) {
        *endFlag = false;
        cals += std::stoi(std::string(line));
        std::getline(std::cin, line);
    }
    return cals;
}

// Updates the top 3 cals
void updateMaxCals(int maxCalsArray[], int size, int cals) {
    int i = size - 1;
    if (cals < maxCalsArray[i]) return;
    for (; i > 0 && cals > maxCalsArray[i - 1]; i--)
        maxCalsArray[i] = maxCalsArray[i - 1];
    maxCalsArray[i] = cals;
}

// Sums all cals in array
int sumMaxCals(int maxCalsArray[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++, maxCalsArray++)
        sum += *maxCalsArray;
    return sum;
}