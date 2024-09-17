import os
import sys
import zipfile

if __name__ == "__main__":
    file_path = input()

    if not os.path.exists(file_path):
        print("not found")
        sys.exit()

    with zipfile.ZipFile(file_path, "r") as zip_ref:
        with zip_ref.open("input.txt") as text_file:
            for line in text_file:
                print(line.decode("utf-8").strip())
