#include <iostream>
#include <string.h>

#define ITEM_QUANTITY 52
#define SECOND_HALF_OFFSET 26

class presenceArray {
    private:
        bool itemArray[ITEM_QUANTITY];
    public:
        inline void clear();
        presenceArray();
        inline bool checkPresence(char item);
        inline void confirmPresence(char item);
};

int getVal(char item) {
    int val = 0;
    if ('A' <= item && item <= 'Z') {
        val = item - 'A';
        val += SECOND_HALF_OFFSET;
    } else {
        val = item - 'a';
    }
    return val;
}

// Clears the presenceArray.
inline void presenceArray::clear() {
    for (int i = 0; i < ITEM_QUANTITY; i++) {
        itemArray[i] = false;
    }
}

// Clears the starting array.
presenceArray::presenceArray() {
    for (int i = 0; i < ITEM_QUANTITY; i++) {
        itemArray[i] = false;
    }
}

// Returns whether or not the item is present.
inline bool presenceArray::checkPresence(char item) {
    return itemArray[getVal(item)];
}

inline void presenceArray::confirmPresence(char item) {
    itemArray[getVal(item)] = true;
}

int main() {
    presenceArray trackPresences;
    int sum = 0;
    std::string line;
    std::getline(std::cin, line);
    while (!std::cin.eof()) {
        int half = line.size() / 2;
        for (int i = 0; i < half; i++) {
            trackPresences.confirmPresence(line[i]);
        }
        half = line.size();
        int max = 0;
        for (int i = half / 2; i < half; i++) {
            if (trackPresences.checkPresence(line[i])) {
                int possibleMax = getVal(line[i]) + 1;
                if (possibleMax > max)
                    max = possibleMax;
            }
        }
        sum += max;
        std::getline(std::cin, line);
        trackPresences.clear();
    }
    std::cout << "The final value is: " << sum << ".\n";
    return 0;
}
