#include <iostream>
#include <clocale>
#include <sstream>

std::size_t strlen_mb(const std::string_view s) {
    std::mblen(nullptr, 0); // reset the conversion state
    std::size_t result = 0;
    const char *ptr = s.data();
    for (const char *const end = ptr + s.size(); ptr < end; ++result) {
        const int next = std::mblen(ptr, end - ptr);
        if (next == -1)
            throw std::runtime_error("strlen_mb(): conversion error");
        ptr += next;
    }
    return result;
}

int printWord(int cursor, int lineLength, const std::string &word, int wordLength) {
    if (word.empty() && wordLength == 0) {
        return cursor;
    }

    if (cursor > 0 && cursor + 1 + wordLength > lineLength) {
        std::cout << std::endl;
        cursor = 0;
    }

    if (cursor > 0) {
        std::cout << " ";
        cursor += 1;
    }

    std::cout << word;
    cursor += wordLength;

    return cursor;
}

int main() {
    // allow mblen() to work with UTF-8 multibyte encoding
    std::setlocale(LC_ALL, "cs_CZ.utf8");

    int lineLength;
    std::cin >> lineLength;

    int rows;
    std::cin >> rows;

    std::string toilet;
    std::getline(std::cin, toilet);
    std::getline(std::cin, toilet);

    int cursor = 0;

    std::string line, word, previousWord;
    int wordLength = 0, previousWordLength = 0;

    for (int i = 0; i < rows; i++) {
        std::getline(std::cin, line);

        if (line.empty()) {
            printWord(cursor, lineLength, previousWord, previousWordLength);
            std::cout << std::endl << std::endl;
            previousWord = "";
            previousWordLength = 0;
            cursor = 0;
            continue;
        }

        std::stringstream liness(line);
        while (liness >> word) {
            wordLength = (int) strlen_mb(word);

            // k/s/v/z or K/S/V/Z
//            if (wordLength == 1 &&
//                (previousWord == "k" || previousWord == "K" ||
//                 previousWord == "s" || previousWord == "S" ||
//                 previousWord == "v" || previousWord == "V" ||
//                 previousWord == "z" || previousWord == "Z")) {
//                previousWord = word;
//                previousWordLength = wordLength;
//                continue;
//            }

            bool hadForcedBreak = false;

            if (previousWordLength == 1 &&
                (previousWord == "k" || previousWord == "K" || previousWord == "s" || previousWord == "S" ||
                 previousWord == "v" || previousWord == "V" || previousWord == "z" || previousWord == "Z")
                && (cursor > 0 ? cursor + 1 : 0) + previousWordLength + 1 + wordLength > lineLength) {
                if (cursor > 0) {
                    std::cout << std::endl;
                }
                cursor = 0;
                hadForcedBreak = true;
            }

            if (previousWordLength > 0) {
                cursor = printWord(cursor, lineLength, previousWord, previousWordLength);
            }

            previousWord = word;
            previousWordLength = wordLength;

            if (hadForcedBreak) {
                std::cout << " " << word;
                cursor += 1 + wordLength;

                previousWord = "";
                previousWordLength = 0;

                word = "";
                wordLength = 0;
            }
        }
    }

    if (wordLength > 0) {
        printWord(cursor, lineLength, word, wordLength);
    }
    std::cout << std::endl;

    return 0;
}
