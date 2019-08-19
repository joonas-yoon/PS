s = input()
cr = ["dz=", "c=", "s=", "z=", "d-", "c-", "lj", "nj"]
ans = 0
for c in cr:
    ans += s.count(c)
    print(ans, s)
    s = s.replace(c, '*')
print(ans+len(s)-s.count('*'))
