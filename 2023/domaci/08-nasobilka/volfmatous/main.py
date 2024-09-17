def print_multiplication_table(n: int, count: int) -> None:
    for multiplier in range(1, count + 1):
        print(n * multiplier)


def read_int() -> int:
    return int(input())


if __name__ == "__main__":
    n = read_int()
    p = read_int()

    print_multiplication_table(n, p)
