
def inverse_collatz(x, i): # all numbers that could have been landed on
    global COUNT
    if i <= 0:
        COUNT += 1
        return
    
    prev_even = ( x*2 ) # possible previous
    prev_odd = ((x-1)/3)

    if prev_even%2 == 0 and prev_even != 1:
        inverse_collatz(prev_even, i-1)
    
    if (x-1)%3 == 0 and prev_odd %2 != 0 and prev_odd != 1:
        inverse_collatz(prev_odd, i-1)



if __name__ == "__main__":
    COUNT = 0

    x = int(input())
    j = int(input())


    inverse_collatz(x, j)
    
    print(COUNT)