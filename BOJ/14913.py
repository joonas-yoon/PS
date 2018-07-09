def ans(a, d, k):
    if (k-a+d) % d != 0:
        return "X"
    x = (k-a+d) // d
    return "X" if x < 1 else x

a, d, k = map(int, input().split())
print(ans(a, d, k))
