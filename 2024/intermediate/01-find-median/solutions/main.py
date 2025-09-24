K = int(input())
arraynumbers = []
for i in range(K):
    arraynumbers.append(int(input()))
arraynumbers.sort()
if(K % 2 == 0 ):
    median = (arraynumbers[K // 2] + arraynumbers[(K // 2) - 1]) / 2.0
    if median.is_integer():
        print(int(median))
    else:
        print(median)
else:
    print(arraynumbers[K // 2])