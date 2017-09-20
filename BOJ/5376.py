import math

for _ in range(int(input())):
    num = input()[2:]
    n = d = 0
    if '(' in num:
        a, b = num.split('(')
        b = b[:-1]
        d = (10 ** len(a)) * (10 ** len(b) - 1)
        n = int(a + b) - (int(a) if a else 0)
    else:
        a = num
        d, n = 10 ** len(a), int(a)

    g = math.gcd(n, d)
    print("%d/%d" % (n // g, d // g))
