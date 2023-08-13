#include <iostream>
#include <limits>

int main() {
    int months;
    std::cin >> months;

    int bestIncreases = 0;
    int currentIncreases = 0;

    int current, previous = std::numeric_limits<int>::max();
    for (int i = 0; i < months; i++) {
        std::cin >> current;

        if (current > previous) {
            currentIncreases++;
            if (currentIncreases > bestIncreases) {
                bestIncreases = currentIncreases;
            }
        } else {
            currentIncreases = 0;
        }

        previous = current;
    }

    std::cout << bestIncreases << std::endl;
    return 0;
}
