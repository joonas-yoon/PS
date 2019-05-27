gr = [i for i in range(100000)]
sz = []

def find(u):
    while u != gr[u]:
        gr[u] = gr[gr[u]]
        u = gr[u]
    return u


def merge(p, q):
    p = find(p)
    q = find(q)

    if p == q:
        return sz[p]

    gr[p] = q
    sz[q] += sz[p]
    sz[p] = 0
    return sz[q]


n, m = map(int, input().split())
sz = [int(input()) for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    print(merge(a-1, b-1))