#include <iostream>
#include <vector>

const int LEFT = 0;
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;

const int NONE = 0;
const int ROBOT = 1;
const int PILLAR = 2;
const int BOX = 3;

int rotate(int currentOrientation, bool clockwise) {
    if (clockwise) {
        return (currentOrientation + 1) % 4;
    } else {
        return (currentOrientation - 1 + 4) % 4;
    }
}

std::vector<int> moveForward(std::vector<std::vector<int>>* warehouse, int robotX, int robotY, int orientation) {
    int w = static_cast<int>(warehouse->size());
    int h = static_cast<int>((*warehouse)[0].size());

    switch (orientation) {
        case LEFT:
            for (int col = robotX - 1; col >= 0; col--) {
                if ((*warehouse)[col][robotY] == PILLAR) {
                    break;
                }

                if ((*warehouse)[col][robotY] == BOX) {
                    continue;
                }

                for (int col2 = col + 1; col2 <= robotX; col2++) {
                    (*warehouse)[col2 - 1][robotY] = (*warehouse)[col2][robotY];
                }

                (*warehouse)[robotX][robotY] = NONE;
                return {robotX - 1, robotY};
            }
            break;

        case RIGHT:
            for (int col = robotX + 1; col < w; col++) {
                if ((*warehouse)[col][robotY] == PILLAR) {
                    break;
                }

                if ((*warehouse)[col][robotY] == BOX) {
                    continue;
                }

                for (int col2 = col - 1; col2 >= robotX; col2--) {
                    (*warehouse)[col2 + 1][robotY] = (*warehouse)[col2][robotY];
                }

                (*warehouse)[robotX][robotY] = NONE;
                return {robotX + 1, robotY};
            }
            break;

        case UP:
            for (int row = robotY - 1; row >= 0; row--) {
                if ((*warehouse)[robotX][row] == PILLAR) {
                    break;
                }

                if ((*warehouse)[robotX][row] == BOX) {
                    continue;
                }

                for (int row2 = row + 1; row2 <= robotY; row2++) {
                    (*warehouse)[robotX][row2 - 1] = (*warehouse)[robotX][row2];
                }

                (*warehouse)[robotX][robotY] = NONE;
                return {robotX, robotY - 1};
            }
            break;

        case DOWN:
            for (int row = robotY + 1; row < h; row++) {
                if ((*warehouse)[robotX][row] == PILLAR) {
                    break;
                }

                if ((*warehouse)[robotX][row] == BOX) {
                    continue;
                }

                for (int row2 = row - 1; row2 >= robotY; row2--) {
                    (*warehouse)[robotX][row2 + 1] = (*warehouse)[robotX][row2];
                }

                (*warehouse)[robotX][robotY] = NONE;
                return {robotX, robotY + 1};
            }
            break;
    }

    return {robotX, robotY};
}

void printWarehouse(const std::vector<std::vector<int>>& warehouse) {
    int w = static_cast<int>(warehouse.size());
    int h = static_cast<int>(warehouse[0].size());

    for (int i = 0; i < w + 2; i++) {
        std::cout << '.';
    }

    std::cout << std::endl;

    for (int row = 0; row < h; row++) {
        std::cout << '.';

        for (int col = 0; col < w; col++) {
            char output = ' ';

            switch (warehouse[col][row]) {
                case ROBOT:
                    output = 'r';
                    break;

                case PILLAR:
                    output = 'o';
                    break;

                case BOX:
                    output = '#';
                    break;
            }

            std::cout << output;
        }

        std::cout << '.' << std::endl;
    }

    for (int i = 0; i < w + 2; i++) {
        std::cout << '.';
    }

    std::cout << std::endl;
}

int main() {
    int w, h, robotX, robotY, robotOrientation;
    std::cin >> w >> h;
    std::cin.ignore();

    std::cin >> robotX >> robotY;
    robotX -= 1;
    robotY -= 1;
    std::cin.ignore();
    robotOrientation = LEFT;

    std::vector<std::vector<int>> warehouse(w, std::vector<int>(h, 0));
    warehouse[robotX][robotY] = ROBOT;

    int p;
    std::cin >> p;
    std::cin.ignore();
    for (int i = 0; i < p; i++) {
        int x, y;
        std::cin >> x >> y;
        x -= 1;
        y -= 1;
        warehouse[x][y] = PILLAR;
        std::cin.ignore();
    }

    int b;
    std::cin >> b;
    std::cin.ignore();
    for (int i = 0; i < b; i++) {
        int x, y;
        std::cin >> x >> y;
        x -= 1;
        y -= 1;
        warehouse[x][y] = BOX;
        std::cin.ignore();
    }

    int c;
    std::cin >> c;
    std::cin.ignore();
    for (int i = 0; i < c; i++) {
        char command;
        std::cin >> command;

        switch (command) {
            case 'L':
            case 'R':
                robotOrientation = rotate(robotOrientation, command == 'R');
                break;

            case 'F':
                std::vector<int> newPosition = moveForward(&warehouse, robotX, robotY, robotOrientation);
                robotX = newPosition[0];
                robotY = newPosition[1];
                break;
        }
    }

    printWarehouse(warehouse);

    return 0;
}
