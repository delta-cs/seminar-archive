import sys
from typing import List

SYMBOL_WIN_COUNT = 5

def is_win(board: List[List[int]], turnX: int, turnY: int) -> bool:
    symbolCountHorizontal = 0
    symbolCountVertical = 0
    symbolCountDiagonal1 = 0
    symbolCountDiagonal2 = 0

    for i in range(-SYMBOL_WIN_COUNT + 1, SYMBOL_WIN_COUNT):
        x = turnX + i
        y = turnY

        if has_coordinates(board, x, y) and board[x][y] == board[turnX][turnY]:
            symbolCountHorizontal += 1
        else:
            symbolCountHorizontal = 0

        x = turnX
        y = turnY + i

        if has_coordinates(board, x, y) and board[x][y] == board[turnX][turnY]:
            symbolCountVertical += 1
        else:
            symbolCountVertical = 0

        x = turnX + i
        y = turnY + i

        if has_coordinates(board, x, y) and board[x][y] == board[turnX][turnY]:
            symbolCountDiagonal1 += 1
        else:
            symbolCountDiagonal1 = 0

        x = turnX + i
        y = turnY - i

        if has_coordinates(board, x, y) and board[x][y] == board[turnX][turnY]:
            symbolCountDiagonal2 += 1
        else:
            symbolCountDiagonal2 = 0

        if (symbolCountHorizontal >= SYMBOL_WIN_COUNT
                or symbolCountVertical >= SYMBOL_WIN_COUNT
                or symbolCountDiagonal1 >= SYMBOL_WIN_COUNT
                or symbolCountDiagonal2 >= SYMBOL_WIN_COUNT):
            return True

    return False


def has_coordinates(board: List[List[int]], x: int, y: int) -> bool:
    return 0 <= x < len(board) and 0 <= y < len(board[0])


def read_int() -> int:
    return int(input())


if __name__ == "__main__":
    w = read_int()
    h = read_int()
    t = read_int()
    currentPlayerIsA = input() == "A"
    input()

    board = [[0 for _ in range(h)] for _ in range(w)]

    for i in range(t):
        turnX = read_int() - 1
        turnY = read_int() - 1
        input()

        if board[turnX][turnY] != 0:
            print("invalid")
            print(i + 1)
            sys.exit()

        board[turnX][turnY] = 1 if currentPlayerIsA else 2

        if is_win(board, turnX, turnY):
            print("A" if currentPlayerIsA else "B")
            print(i + 1)
            sys.exit()

        currentPlayerIsA = not currentPlayerIsA

    print("?")
