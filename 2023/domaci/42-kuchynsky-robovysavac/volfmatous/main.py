from typing import List, Dict

LEFT = 0
RIGHT = 1
FORWARD = 2
BACK = 3


def try_program(floor: List[List[str]], cleanerY: int, cleanerX: int, stationY: int, stationX: int,
                program: Dict[str, int]) -> bool:
    floor_visited = [[False] * len(floor[0]) for _ in range(len(floor))]

    while True:
        tile = floor[cleanerY][cleanerX]
        direction = program.get(tile, -1)

        if direction == LEFT:
            cleanerX -= 1
        elif direction == RIGHT:
            cleanerX += 1
        elif direction == FORWARD:
            cleanerY -= 1
        elif direction == BACK:
            cleanerY += 1

        if (cleanerY < 0 or cleanerY >= len(floor) or cleanerX < 0 or cleanerX >= len(floor[0])
                or floor_visited[cleanerY][cleanerX]):
            return False

        if cleanerY == stationY and cleanerX == stationX:
            return True

        floor_visited[cleanerY][cleanerX] = True


if __name__ == "__main__":
    inputSplit = input().split()
    h = int(inputSplit[0])

    floor = []
    tile_colors = []
    program = {}

    for row in range(h):
        floor.append([tile[0] for tile in input().split()])

        for tile in floor[row]:
            if tile[0] not in program:
                program[tile[0]] = LEFT
                tile_colors.append(tile[0])

    inputSplit = input().split()
    cleanerY = int(inputSplit[0]) - 1
    cleanerX = int(inputSplit[1]) - 1

    inputSplit = input().split()
    stationY = int(inputSplit[0]) - 1
    stationX = int(inputSplit[1]) - 1

    total_possible_programs = 0

    while True:
        if try_program(floor, cleanerY, cleanerX, stationY, stationX, program):
            total_possible_programs += 1

        end = False
        for tile_color in tile_colors:
            program[tile_color] += 1
            if program[tile_color] > 3:
                if tile_color == tile_colors[-1]:
                    end = True

                program[tile_color] = 0
            else:
                break

        if end:
            break

    print(total_possible_programs)
