import random


d = random.randint(10, 500_000) # 10 m - 500 km

c = random.randint(1, 5120) # 1 Gb - 5 Tb (3 Tb has been done IRL)

v = random.randint(1, 340) # 1 m/s - mach 1 (turbojet powered holub I guess?)

p = random.randint(1, 1024_00)/100 # 0.01 Mb/s - 1 GB


n = random.randint(1, 60)

s = random.randint(1, 20)


for x in [d, c, v, p, n, s]:
    print(x)