import os
import sys


def print_directory_contents(folder_path: str, nest_level: int = 0) -> None:
    files = sorted(os.listdir(folder_path))
    directories = sorted([d for d in files if os.path.isdir(os.path.join(folder_path, d))])
    files = sorted([f for f in files if os.path.isfile(os.path.join(folder_path, f))])

    print(" " * max(nest_level - 1, 0) * 2, end="")
    if nest_level > 0:
        print("- ", end="")
    print(os.path.basename(folder_path))

    for file in files:
        print(" " * nest_level * 2 + f"- {file}")

    for directory in directories:
        print_directory_contents(os.path.join(folder_path, directory), nest_level + 1)


if __name__ == "__main__":
    folder_path = input()

    if not os.path.exists(folder_path):
        print("not found")
        sys.exit()

    print_directory_contents(folder_path)
