import random

Z = 1000

rnd = lambda : random.randint(-1000, 1000)



print(f"{rnd()}\n{rnd()}\n{Z}")


for i in range(2*Z):
    print(rnd())