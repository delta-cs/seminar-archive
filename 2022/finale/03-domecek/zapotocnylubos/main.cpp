#include <iostream>

void printHouse(int roofLevels, int baseWidth, int baseLevels) {
    for (int i = 1; i <= roofLevels; i++) {
        for (int m = 0; m < roofLevels - i; m++) {
            std::cout << " ";
        }

        std::cout << "*";

        for (int j = 1; j < i; j++) {
            std::cout << " *";
        }

        std::cout << std::endl;
    }

    for (int i = 1; i <= baseLevels; i++) {
        std::cout << " ";

        for (int b = 0; b < baseWidth; b++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

int main() {
    int stones;
    std::cin >> stones;

    bool housePrinted = false;
    for (int i = 3; i <= stones; i++) {
        int roofStones = (i * (1 + i)) / 2;
        int roofWidth = i + (i - 1);

        int leftStones = stones - roofStones;

        int baseWidth = roofWidth - 2;
        int baseLevels = leftStones / baseWidth;

        // zakladna musi by alespon 3 siroka a 3 vysoka
        if (baseWidth < 3 || baseLevels < 3) {
            continue;
        }

        // nevyjde mi to "presne"
        if (leftStones % baseWidth != 0) {
            continue;
        }

        // vloz extra newline, pokud budu vykreslovat vice nez jeden dum
        if (housePrinted) {
            std::cout << std::endl;
        }

        printHouse(i, baseWidth, baseLevels);
        housePrinted = true;
    }

    return 0;
}
