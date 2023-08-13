#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<int> frequency(50, 0);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int year, week, n1, n2, n3, n4, n5, n6, n7;

        sscanf(line.c_str(), "%d;%d;%d;%d;%d;%d;%d;%d;%d", &year, &week, &n1, &n2, &n3, &n4, &n5, &n6, &n7);
        frequency[n1]++;
        frequency[n2]++;
        frequency[n3]++;
        frequency[n4]++;
        frequency[n5]++;
        frequency[n6]++;
        frequency[n7]++;
    }

    for (int c = 0; c < 3; c++) {
        int highest_index = 0;
        for (int i = 0; i < (int) frequency.size(); i++) {
            if (frequency[highest_index] < frequency[i]) {
                highest_index = i;
            }
        }

        std::cout << highest_index << std::endl;

        frequency[highest_index] = 0;
    }

    return 0;
}
