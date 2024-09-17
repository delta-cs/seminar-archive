from typing import List

LEFT = 0
UP = 1
RIGHT = 2
DOWN = 3

NONE = 0
ROBOT = 1
PILLAR = 2
BOX = 3


def rotate(current_orientation: int, clockwise: bool) -> int:
    if clockwise:
        return (current_orientation + 1) % 4
    else:
        return (current_orientation - 1 + 4) % 4


def move_forward(warehouse: List[List[int]], robot_x: int, robot_y: int, orientation: int) -> None:
    if orientation == LEFT:
        for col in range(robot_x - 1, -1, -1):
            if warehouse[col][robot_y] == PILLAR:
                break

            if warehouse[col][robot_y] == BOX:
                continue

            for col2 in range(col + 1, robot_x + 1):
                warehouse[col2 - 1][robot_y] = warehouse[col2][robot_y]

            warehouse[robot_x][robot_y] = NONE
            return [robot_x - 1, robot_y]

    elif orientation == RIGHT:
        for col in range(robot_x + 1, len(warehouse)):
            if warehouse[col][robot_y] == PILLAR:
                break

            if warehouse[col][robot_y] == BOX:
                continue

            for col2 in range(col - 1, robot_x - 1, -1):
                warehouse[col2 + 1][robot_y] = warehouse[col2][robot_y]

            warehouse[robot_x][robot_y] = NONE
            return [robot_x + 1, robot_y]

    elif orientation == UP:
        for row in range(robot_y - 1, -1, -1):
            if warehouse[robot_x][row] == PILLAR:
                break

            if warehouse[robot_x][row] == BOX:
                continue

            for row2 in range(row + 1, robot_y + 1):
                warehouse[robot_x][row2 - 1] = warehouse[robot_x][row2]

            warehouse[robot_x][robot_y] = NONE
            return [robot_x, robot_y - 1]

    elif orientation == DOWN:
        for row in range(robot_y + 1, len(warehouse[0])):
            if warehouse[robot_x][row] == PILLAR:
                break

            if warehouse[robot_x][row] == BOX:
                continue

            for row2 in range(row - 1, robot_y - 1, -1):
                warehouse[robot_x][row2 + 1] = warehouse[robot_x][row2]

            warehouse[robot_x][robot_y] = NONE
            return [robot_x, robot_y + 1]

    return [robot_x, robot_y]


def print_warehouse(warehouse: List[List[int]]) -> None:
    for _ in range(len(warehouse) + 2):
        print(".", end="")
    print()

    for row in range(len(warehouse[0])):
        print(".", end="")
        for col in range(len(warehouse)):
            output = " "

            if warehouse[col][row] == ROBOT:
                output = "r"
            elif warehouse[col][row] == PILLAR:
                output = "o"
            elif warehouse[col][row] == BOX:
                output = "#"

            print(output, end="")

        print(".")

    for _ in range(len(warehouse) + 2):
        print(".", end="")
    print()


def read_int() -> int:
    return int(input())


if __name__ == "__main__":
    w = read_int()
    h = read_int()
    input()

    robot_x = read_int() - 1
    robot_y = read_int() - 1
    input()
    robot_orientation = LEFT

    warehouse = [[NONE for _ in range(h)] for _ in range(w)]
    warehouse[robot_x][robot_y] = ROBOT

    p = read_int()
    input()
    for _ in range(p):
        warehouse[read_int() - 1][read_int() - 1] = PILLAR
        input()

    b = read_int()
    input()
    for _ in range(b):
        warehouse[read_int() - 1][read_int() - 1] = BOX
        input()

    c = read_int()
    input()
    for _ in range(c):
        command = input()

        if command == "L" or command == "R":
            robot_orientation = rotate(robot_orientation, command == "R")
        elif command == "F":
            new_position = move_forward(warehouse, robot_x, robot_y, robot_orientation)
            robot_x = new_position[0]
            robot_y = new_position[1]

    print_warehouse(warehouse)
