from random import randint

n = randint(1, 1000)
print(n)

for i in range(n):
    output = ""
    output += str(randint(-90, 90)) + " "
    output += str(randint(1, 10000))
    print(output)