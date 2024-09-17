import sys
from typing import Dict, List, Tuple, Union


def expression_value(line_split: List[str], variables: Dict[str, Union[int, float]]) -> Tuple[bool, Union[int, float]]:
    if len(line_split) % 2 != 1:
        return False, 0

    expression_add = True
    expression_value = 0

    for w in range(len(line_split)):
        if w % 2 == 0:
            value = float(line_split[w]) if line_split[w].replace('.', '').replace('-', '').isdigit() else variables.get(line_split[w], None)

            if value is None:
                return False, 0

            expression_value += value if expression_add else -value
        else:
            if line_split[w] == "a":
                expression_add = True
            elif line_split[w] == "bez":
                expression_add = False
            else:
                return False, 0

    return True, expression_value


def condition_pass(line_split: List[str], variables: Dict[str, Union[int, float]]) -> Tuple[bool, bool]:
    or_indexes = [-1]
    for i in range(len(line_split)):
        if line_split[i] == "nebo":
            or_indexes.append(i)
    or_indexes.append(len(line_split))

    condition_pass = False

    for i in range(len(or_indexes) - 1):
        start_index = or_indexes[i] + 1
        end_index = or_indexes[i + 1] - 1

        comparator_index = -1
        for c in range(start_index, end_index + 1):
            if line_split[c] in ["rovno", "aspon", "nejvic"]:
                comparator_index = c
                break

        if comparator_index == -1:
            return False, False

        comparator = line_split[comparator_index]
        expression1_result = expression_value(line_split[start_index:comparator_index], variables)
        expression2_result = expression_value(line_split[comparator_index + 1:end_index + 1], variables)

        if not expression1_result[0] or not expression2_result[0]:
            return False, False

        if not condition_pass:
            expression1 = expression1_result[1]
            expression2 = expression2_result[1]

            if comparator == "rovno":
                condition_pass = expression1 == expression2
            elif comparator == "aspon":
                condition_pass = expression1 >= expression2
            elif comparator == "nejvic":
                condition_pass = expression1 <= expression2

    return True, condition_pass

if __name__ == "__main__":
    variables = {}

    c = int(input())

    lines_split = []
    lines_nest_levels = []

    for _ in range(c):
        line = input().split("//")[0].rstrip()

        if line == '':
            continue

        nest_level = 0
        while len(line) > 2 and line.startswith("  "):
            line = line[2:]
            nest_level += 1

        lines_split.append(line.split(' '))
        lines_nest_levels.append(nest_level)

    output = []

    repeating = False
    repeat_start_line_index = 0
    nest_level_current = 0

    i = 0
    while i < len(lines_split):
        line_split = lines_split[i]
        nest_level = lines_nest_levels[i]

        if nest_level > nest_level_current:
            i += 1
            continue

        at_last_line = i >= len(lines_split) - 1

        if repeating and (nest_level < lines_nest_levels[repeat_start_line_index] + 1 or at_last_line):
            repeating = False
            i = repeat_start_line_index - 1
            if not at_last_line:
                i += 1
                continue
        elif nest_level < nest_level_current:
            nest_level_current = nest_level

        if line_split[0] == "kdyz":
            if len(line_split) < 5 or line_split[-1] != "tak":
                print("error")
                sys.exit()

            condition_result = condition_pass(line_split[1:-1], variables)

            if not condition_result[0]:
                print("error")
                sys.exit()

            if condition_result[1]:
                nest_level_current += 1
        elif line_split[0] == "dokud":
            if len(line_split) < 5 or line_split[-1] != "tak":
                print("error")
                sys.exit()

            condition_result = condition_pass(line_split[1:-1], variables)

            if not condition_result[0]:
                print("error")
                sys.exit()

            if condition_result[1]:
                nest_level_current += 1
                repeating = True
                repeat_start_line_index = i
        elif line_split[0] == "vypsat":
            expression_result = expression_value(line_split[1:], variables)

            if not expression_result[0]:
                print("error")
                sys.exit()

            output.append(expression_result[1])
        else:
            variable_name = line_split[0]

            if not 'a' <= variable_name[0].lower() <= 'z' or len(line_split) < 2 or line_split[1] != "je":
                print("error")
                sys.exit()

            if variable_name in ["je", "a", "bez", "kdyz", "tak", "rovno", "aspon", "nejvic", "nebo", "dokud", "vypsat"]:
                print("error")
                sys.exit()

            expression_result = expression_value(line_split[2:], variables)

            if not expression_result[0]:
                print("error")
                sys.exit()

            variables[variable_name] = expression_result[1]

        i += 1

    for line in output:
        print(f"{line:g}")
