w, h = map(int, input().split())

def ii(x):
    try:
        return int(x)
    except:
        return None

res = 1
for _ in range(h):
    s = input().split()
    for x in s:
        k = ii(x)
        if k is not None:
            res *= k

print(res)
