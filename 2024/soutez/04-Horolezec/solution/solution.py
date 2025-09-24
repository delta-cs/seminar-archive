import math


if __name__ == "__main__":
    n = int(input())

    x = 0
    y = 0

    max_height = y
    
    for i in range(n):
        u, l = map(int, input().split(" "))

        u_r = math.radians(u)

        delta = (math.cos(u_r)*l, math.sin(u_r)*l)

        x += delta[0]
        y += delta[1]

        if y > max_height: max_height = y

    
    cutoff = lambda n : int(n*100)/100

    print(cutoff(max_height))
    print(cutoff(x))