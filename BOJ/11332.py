import math

def isPassed(n, t, limit):
    return n * t <= (10 ** 8) * limit

for _ in range(int(input())):
    ar = input().split()
    on = ar[0][2:len(ar[0])-1]
    n, t, limit = map(int, ar[1:])
    if on == "N":
        ok = isPassed(n, t, limit)
    elif on == "N^2":
        ok = isPassed(n ** 2, t, limit)
    elif on == "N^3":
        ok = isPassed(n ** 3, t, limit)
    elif on == "N!":
        ok = isPassed(math.factorial(n), t, limit) if n <= 12 else False
    else:
        ok = isPassed(2 ** n, t, limit) if n < 32 else False
    print("May Pass." if ok else "TLE!")
