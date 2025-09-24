


if __name__ == "__main__":
    EXISTING_VALUES = [1, 2, 5, 10, 20, 50]
    EXISTING_VALUES.sort(reverse=True)

    C = int(input()) # coffee cost

    V = int(input())

    entered_sum = 0
    for i in range(V): entered_sum += int(input())

    to_return = entered_sum - C

    if to_return < 0:
        print("nelze vydat")
        exit()

    for val in EXISTING_VALUES:
        for i in range(to_return // val): print(val)
        to_return %= val