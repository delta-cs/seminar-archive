#include <iostream>

int main() {
    int inputCount = 0;
    int value;

    while (std::cin >> value) {
        inputCount++;
    }

    std::cout << inputCount << std::endl;

    return 0;
}
