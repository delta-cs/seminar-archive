import math


def apply_operation(a: float, operation: str, b: float) -> float:
    result = 0

    if operation == "+":
        result = a + b
    elif operation == "-":
        result = a - b
    elif operation == "*":
        result = a * b
    elif operation == "/":
        result = a / b
    elif operation == "^":
        result = math.pow(a, b)

    return result


if __name__ == "__main__":
    n = int(input())

    result = 0

    operation = "+"

    temp1 = 0
    temp1_operation = "+"
    temp1_used = False

    temp2 = 0
    temp2_operation = "+"
    temp2_used = False

    for i in range(n):
        operand = float(input())
        next_operation = "+"

        if i < n - 1:
            next_operation = input()

        if temp2_used:
            temp2 = apply_operation(temp2, temp2_operation, operand)
            temp2_operation = next_operation

        if next_operation == "+" or next_operation == "-" or i >= n - 1:
            if temp1_used:
                if temp2_used:
                    temp1 = apply_operation(temp1, temp1_operation, temp2)
                else:
                    temp1 = apply_operation(temp1, temp1_operation, operand)

                result = apply_operation(result, operation, temp1)
                temp1_used = False
                temp2_used = False
            else:
                result = apply_operation(result, operation, operand)

            operation = next_operation
        elif next_operation == "*" or next_operation == "/":
            if temp1_used:
                if temp2_used:
                    temp1 = apply_operation(temp1, temp1_operation, temp2)
                else:
                    temp1 = apply_operation(temp1, temp1_operation, operand)

                temp1_used = True
                temp1_operation = next_operation
            else:
                temp1_used = True
                temp1 = operand
                temp1_operation = next_operation
        elif next_operation == "^":
            if temp1_used:
                if temp2_used:
                    continue

                if temp1_operation == "^":
                    temp1 = apply_operation(temp1, temp1_operation, operand)
                    temp1_operation = next_operation
                else:
                    temp2_used = True
                    temp2 = operand
                    temp2_operation = next_operation
            else:
                temp1_used = True
                temp1 = operand
                temp1_operation = next_operation

    print(f"{result:g}")
