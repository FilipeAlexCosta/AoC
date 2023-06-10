#include <iostream>
#include <sstream>

int addUpCals(bool* endFlag);

int main() {
    int maxCals = -1, maxElf = 0, elf = 0;
    bool endFlag = false;
    while (!endFlag) {
        int cals = addUpCals(&endFlag);
        elf++; // accidentally thought it was the number of the elf
        if (cals > maxCals) {
            maxElf = elf;
            maxCals = cals;
        }
    }
    std::cout << maxCals << '\n';
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