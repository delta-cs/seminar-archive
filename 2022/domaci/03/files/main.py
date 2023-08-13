from sys import stdin


a = 0
b = 0
a0 = 0
b0 = 0
a1 = 0
b1 = 0
n = 0
na = 0
nb = 0
q = 0

for line in stdin:
    input = line.lstrip().rstrip().split()

    if line == '' or len(input) != 2:
        break

    a, b = [int(x) for x in line.lstrip().rstrip().split()]

    if a < b:
        a = b
        b = a

    #
    #     a  | b
    #   +---------+
    # a | 1  | 0  | "( a0, b0 )"
    # b | 0  | 1  | "( a1, b1 )"
    # n | na | nb | q
    #   |    |    |
    #
    #

    a0 = 1
    b0 = 0
    a1 = 0
    b1 = 1

    n = a % b
    q = a / b

    na = a0 - q * a1
    nb = b0 - q * b1

    a = b
    a0 = a1
    b0 = b1

    b = n
    a1 = na
    b1 = nb

    while n != 0:
        n = a % b
        q = a / b

        na = a0 - q * a1
        nb = b0 - q * b1

        a = b
        a0 = a1
        b0 = b1

        b = n
        a1 = na
        b1 = nb

    print(a)
