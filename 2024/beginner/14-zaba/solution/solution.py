
def collatz(x):
    i = 0
    while x != 1:
        if x%2 == 0:
            x = x//2
        else:
            x = 3*x+1
        
        i += 1

    return i

if __name__ == '__main__':
    n = int(input())
    print(collatz(n))