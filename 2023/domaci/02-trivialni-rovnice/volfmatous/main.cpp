#include <iostream>
#include <string>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    std::string output;
    if (b == 1) {
        output = "undefined";
    } else {
        double x = (c - a) / (b + 1);
        output = std::to_string(x);
        output.erase(output.find_last_not_of('0') + 1, std::string::npos);
        output.erase(output.find_last_not_of('.') + 1, std::string::npos);
    }

    std::cout << output << std::endl;

    return 0;
}
