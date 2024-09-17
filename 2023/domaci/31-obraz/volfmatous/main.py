import sys
from typing import List

LEFT = 0
RIGHT = 1
TOP = 2
BOTTOM = 3
NAIL_CHAR = "o"
TOP_EDGE_NAIL_COUNT = 2

def print_picture_from_side(picture: List[List[str]], side: int) -> None:
    rows, cols = len(picture), len(picture[0])

    if side == LEFT:
        for col in range(cols):
            for row in range(rows - 1, -1, -1):
                output = picture[row][col]
                if col == 0 or col == cols - 1 or row == 0 or row == rows - 1:
                    if output == "|":
                        output = "-"
                    elif output == "-":
                        output = "|"

                print(output, end="")
            print()

    elif side == RIGHT:
        for col in range(cols - 1, -1, -1):
            for row in range(rows):
                output = picture[row][col]
                if col == 0 or col == cols - 1 or row == 0 or row == rows - 1:
                    if output == "|":
                        output = "-"
                    elif output == "-":
                        output = "|"

                print(output, end="")
            print()

    elif side == TOP:
        for row in range(rows):
            for col in range(cols):
                print(picture[row][col], end="")
            print()

    elif side == BOTTOM:
        for row in range(rows - 1, -1, -1):
            for col in range(cols - 1, -1, -1):
                print(picture[row][col], end="")
            print()

def get_top_edge_side(picture: List[List[str]]) -> int:
    rows, cols = len(picture), len(picture[0])
    nails_count = 0

    for row in range(rows):
        if picture[row][0] == NAIL_CHAR:
            nails_count += 1

            if nails_count >= TOP_EDGE_NAIL_COUNT:
                return LEFT

    nails_count = 0

    for row in range(rows):
        if picture[row][cols - 1] == NAIL_CHAR:
            nails_count += 1

            if nails_count >= TOP_EDGE_NAIL_COUNT:
                return RIGHT

    nails_count = 0

    for col in range(cols):
        if picture[0][col] == NAIL_CHAR:
            nails_count += 1

            if nails_count >= TOP_EDGE_NAIL_COUNT:
                return TOP

    return BOTTOM

if __name__ == "__main__":
    w = int(input())
    h = int(input())
    input()

    if w < 1 or h < 1:
        sys.exit()

    picture = [["" for _ in range(w)] for _ in range(h)]

    for row in range(h):
        for col in range(w):
            picture[row][col] = input()

    top_edge_side = get_top_edge_side(picture)
    print_picture_from_side(picture, top_edge_side)
