#include <iostream>

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::string compressInput;
    std::getline(std::cin, compressInput);
    bool compressing = (compressInput == "compress");

    if (compressing) {
        int currentLetterCount = 1;

        for (int i = 0; i < text.length(); i++) {
            if (i < text.length() - 1 && text[i] == text[i + 1]) {
                currentLetterCount++;
            } else {
                std::cout << text[i];
                if (currentLetterCount > 1) {
                    std::cout << currentLetterCount;
                }

                currentLetterCount = 1;
            }
        }
    } else {
        for (int i = 0; i < text.length(); i++) {
            std::cout << text[i];

            std::string countBuffer;
            for (int j = i; j < text.length(); j++) {
                if (j < text.length() - 1 && isdigit(text[j + 1])) {
                    countBuffer += text[j + 1];
                } else {
                    if (!countBuffer.empty()) {
                        int count = std::stoi(countBuffer);
                        for (int k = 0; k < count - 1; k++) {
                            std::cout << text[i];
                        }
                    }

                    i = j;
                    break;
                }
            }
        }
    }

    std::cout << std::endl;
    return 0;
}
