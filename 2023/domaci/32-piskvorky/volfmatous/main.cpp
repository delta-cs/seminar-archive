#include <iostream>
#include <vector>

const int SYMBOL_WIN_COUNT = 5;

bool hasCoordinates(const std::vector<std::vector<int>>& board, int x, int y) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
}

bool isWin(const std::vector<std::vector<int>>& board, int turnX, int turnY) {
    int symbolCountHorizontal = 0;
    int symbolCountVertical = 0;
    int symbolCountDiagonal1 = 0;
    int symbolCountDiagonal2 = 0;

    for (int i = -SYMBOL_WIN_COUNT + 1; i <= SYMBOL_WIN_COUNT - 1; i++) {
        int x = turnX + i;
        int y = turnY;

        if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
            symbolCountHorizontal++;
        } else {
            symbolCountHorizontal = 0;
        }

        x = turnX;
        y = turnY + i;

        if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
            symbolCountVertical++;
        } else {
            symbolCountVertical = 0;
        }

        x = turnX + i;
        y = turnY + i;

        if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
            symbolCountDiagonal1++;
        } else {
            symbolCountDiagonal1 = 0;
        }

        x = turnX + i;
        y = turnY - i;

        if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
            symbolCountDiagonal2++;
        } else {
            symbolCountDiagonal2 = 0;
        }

        if (symbolCountHorizontal >= SYMBOL_WIN_COUNT ||
            symbolCountVertical >= SYMBOL_WIN_COUNT ||
            symbolCountDiagonal1 >= SYMBOL_WIN_COUNT ||
            symbolCountDiagonal2 >= SYMBOL_WIN_COUNT) {
            return true;
        }
    }

    return false;
}

int main() {
    int w, h, t;
    std::cin >> w >> h >> t;

    bool currentPlayerIsA;
    char playerInput;
    std::cin >> playerInput;
    currentPlayerIsA = (playerInput == 'A');

    std::vector<std::vector<int>> board(w, std::vector<int>(h, 0));

    for (int i = 0; i < t; i++) {
        int turnX, turnY;
        std::cin >> turnX >> turnY;
        turnX -= 1;
        turnY -= 1;

        if (board[turnX][turnY] != 0) {
            std::cout << "invalid" << std::endl;
            std::cout << i + 1 << std::endl;
            return 0;
        }

        board[turnX][turnY] = currentPlayerIsA ? 1 : 2;

        if (isWin(board, turnX, turnY)) {
            std::cout << (currentPlayerIsA ? 'A' : 'B') << std::endl;
            std::cout << i + 1 << std::endl;
            return 0;
        }

        currentPlayerIsA = !currentPlayerIsA;
    }

    std::cout << '?' << std::endl;

    return 0;
}
