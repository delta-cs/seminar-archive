cipher = int(input())
ignor = int(input())
if(cipher == 1):
    print(9)
elif(ignor == 0):
    print(9**cipher-9**(cipher-2))
else:
    print(9**cipher-9**(cipher-1))