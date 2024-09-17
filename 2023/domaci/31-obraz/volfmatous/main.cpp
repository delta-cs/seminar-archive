#include <iostream>
#include <vector>

const int LEFT = 0;
const int RIGHT = 1;
const int TOP = 2;
const int BOTTOM = 3;
const char NAIL_CHAR = 'o';
const int TOP_EDGE_NAIL_COUNT = 2;

int getTopEdgeSide(const std::vector<std::vector<char>>& picture) {
    int nailsCount = 0;

    for (int row = 0; row < picture.size(); row++) {
        if (picture[row][0] == NAIL_CHAR) {
            nailsCount++;

            if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                return LEFT;
            }
        }
    }

    nailsCount = 0;

    for (int row = 0; row < picture.size(); row++) {
        if (picture[row][picture[0].size() - 1] == NAIL_CHAR) {
            nailsCount++;

            if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                return RIGHT;
            }
        }
    }

    nailsCount = 0;

    for (int col = 0; col < picture[0].size(); col++) {
        if (picture[0][col] == NAIL_CHAR) {
            nailsCount++;

            if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                return TOP;
            }
        }
    }

    return BOTTOM;
}

void printPictureFromSide(const std::vector<std::vector<char>>& picture, int side) {
    switch (side) {
        case LEFT:
            for (int col = 0; col < picture[0].size(); col++) {
                for (int row = picture.size() - 1; row >= 0; row--) {
                    char output = picture[row][col];

                    if (col == 0 || col == picture[0].size() - 1 || row == 0 || row == picture.size() - 1) {
                        switch (output) {
                            case '|':
                                output = '-';
                                break;

                            case '-':
                                output = '|';
                                break;
                        }
                    }

                    std::cout << output;
                }

                std::cout << std::endl;
            }

            break;

        case RIGHT:
            for (int col = picture[0].size() - 1; col >= 0; col--) {
                for (int row = 0; row < picture.size(); row++) {
                    char output = picture[row][col];

                    if (col == 0 || col == picture[0].size() - 1 || row == 0 || row == picture.size() - 1) {
                        switch (output) {
                            case '|':
                                output = '-';
                                break;

                            case '-':
                                output = '|';
                                break;
                        }
                    }

                    std::cout << output;
                }

                std::cout << std::endl;
            }

            break;

        case TOP:
            for (const auto& row : picture) {
                for (char col : row) {
                    std::cout << col;
                }

                std::cout << std::endl;
            }

            break;

        case BOTTOM:
            for (int row = picture.size() - 1; row >= 0; row--) {
                for (int col = picture[0].size() - 1; col >= 0; col--) {
                    std::cout << picture[row][col];
                }

                std::cout << std::endl;
            }

            break;
    }
}

int main() {
    int w, h;
    std::cin >> w >> h;

    if (w < 1 || h < 1) {
        return 0;
    }

    std::vector<std::vector<char>> picture(h, std::vector<char>(w));

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            std::cin >> picture[row][col];
        }
    }

    int topEdgeSide = getTopEdgeSide(picture);
    printPictureFromSide(picture, topEdgeSide);
    return 0;
}
