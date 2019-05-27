from math import inf as INF

n, m = map(int, input().split())
g = [[INF if i != j else 0 for j in range(n+1)] for i in range(n+1)]
for _ in range(m):
    a, b, k = map(int, input().split())
    g[a][b] = g[b][a] = k

for k in range(1, n+1):
    for i in range(1, n+1):
        if g[i][k] == INF or i == k:
            continue
        for j in range(1, n+1):
            if g[k][j] == INF or i == j or j == k:
                continue
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

q = int(input())
for _ in range(q):
    x, y = map(int, input().split())
    ans = -1 if g[x][y] is INF else g[x][y]
    print(ans)