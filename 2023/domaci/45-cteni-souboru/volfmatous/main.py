import os
import sys

if __name__ == "__main__":
    file_path = input()
    if not os.path.exists(file_path):
        print("not found")
        sys.exit()

    with open(file_path, "r") as file:
        content = file.read()
        print(content)
