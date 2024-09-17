#include <iostream>

void printMultiplicationTable(int n, int count) {
    for (int multiplier = 1; multiplier <= count; multiplier++) {
        std::cout << n * multiplier << std::endl;
    }
}

int main() {
    int n, p;

    std::cin >> n >> p;

    printMultiplicationTable(n, p);

    return 0;
}
