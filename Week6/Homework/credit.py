from cs50 import get_int
i, r, sum1, sum2, n, m, t = 0, 0, 0, 0, 1, 1, 1
n = get_int("Card Number: ")
m = n
r = m % 10
# Luhn’s Algorithm and counting number of digits
while (m != 0):
    r = m % 10
    m = int(m / 10)
    if (i % 2 == 0):
        sum1 += r
    else:
        sum2 += int(((2 * r) % 10 + (2 * r) / 10))
    i += 1

if (((sum1 + sum2) % 10) == 0):
    # finding the first two digits (twod)
    # checking length as well the starting two digits
    for j in range(1, i):
        t *= 10
    twod = int(n / (t / 10))

    if (i == 15):
        if (twod == 34 or twod == 37):
            print("AMEX")
        else:
            print("INVALID")
    elif (i == 16):
        if (51 <= twod and twod <= 55):
            print("MASTERCARD")
        elif (40 <= twod and twod <= 49):
            print("VISA")
        else:
            print("INVALID")
    elif (i == 13):
        if (40 <= twod and twod <= 49):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


else:
    print("INVALID")