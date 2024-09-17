if __name__ == "__main__":
    a = float(input())
    b = float(input())
    c = float(input())

    if b == 1:
        output = "undefined"
    else:
        x = (c - a) / (b + 1)
        output = f"{x:g}"

    print(output)
