#include <iostream>

#define LOSS 0
#define DRAW 3
#define WIN 6
#define MATCHUPS 3
#define LOSS_OFFSET 2
#define DRAW_OFFSET 0
#define WIN_OFFSET 1

const int LOOKUPCHOICE[] {1, 2, 3};
const int  LOOKUPMATCHUP[] {LOSS, DRAW, WIN};
const int LOOKUPOFFSET[] {LOSS_OFFSET, DRAW_OFFSET, WIN_OFFSET};

inline int modulus(int val, int mod) {
    val = val % mod;
    return ((val < 0) ? val + mod : val);
}

int main() {
    char op, pl;
    int res = 0;
    while (true) {
        std::cin >> op >>  pl;
        if (std::cin.eof()) break;
        int plIdx = pl - 'X';
        int opIdx = op - 'A';
        int choiceIdx = modulus(opIdx + LOOKUPOFFSET[plIdx], MATCHUPS);
        res += LOOKUPCHOICE[choiceIdx] + LOOKUPMATCHUP[plIdx]; 
    }
    std::cout << "You get: " << res << " points.\n";
    return 0;
}
