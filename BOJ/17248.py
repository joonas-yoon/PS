def solve(x, y, z):
    t = 0
    while (t+1) * t < 2*(y-x)/z:
        t += 1
    return t

T = int(input())
for _ in range(T):
    x, y, z = map(int, input().split())
    print(solve(x, y, z))
