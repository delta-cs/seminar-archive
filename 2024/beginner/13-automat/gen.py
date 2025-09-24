import random

with open("in.txt", "w") as f:
    f.write("99999999\n999999\n")

    for i in range(999999): f.write(f"{random.choice([1,2,5,10,20,50])}\n")