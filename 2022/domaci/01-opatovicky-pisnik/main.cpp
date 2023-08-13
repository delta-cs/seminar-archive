#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<int> data;

    int point;
    while (std::cin >> point) {
        data.emplace_back(point);
    }

    int min = std::numeric_limits<int>::max();
    unsigned minIndex = data.size();

    for (int i = 0; i < data.size() - 3; i++) {
        int val = data[i] + data[i + 1] + data[i + 2];
        if (val < min) {
            minIndex = i;
            min = val;
        }
    }

    std::cout << data[minIndex] << std::endl
              << data[minIndex + 1] << std::endl
              << data[minIndex + 2] << std::endl
              << std::endl;

    return 0;
}
