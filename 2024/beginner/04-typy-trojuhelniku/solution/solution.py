a = int(input())
b = int(input())
c = int(input())

if(a+b <= c or b+c <= a or c+a <= b):
    print("0")
elif(a == b and b == c):
    print("3")
elif(a == b or b == c or a == c):
    print("2")
else:
    print("1")
input()