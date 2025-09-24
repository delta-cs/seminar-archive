hrac1 = input()
hrac2 = input()

if hrac1 == hrac2:
    print("remiza")

elif hrac1 == "kamen":
    if (hrac2 == "nuzky"):
        print("hrac1")
    else:
        print("hrac2")

elif hrac1 == "nuzky":
    if (hrac2 == "papir"):
        print("hrac1")
    else:
        print("hrac2")

elif hrac1 == "papir":
    if (hrac2 == "kamen"):
        print("hrac1")
    else:
        print("hrac2")