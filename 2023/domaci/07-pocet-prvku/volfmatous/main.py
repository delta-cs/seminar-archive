if __name__ == "__main__":
    inputCount = 0

    while True:
        try:
            input()
        except EOFError:
            break

        inputCount += 1

    print(inputCount)
