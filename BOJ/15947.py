n = int(input()) - 1
s = ["baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"]
l = len(s)

if (n % l) % 4 >= 2:
    k = n // l + (2 if (n % l) % 4 == 2 else 1)
    if k >= 5:
        print("tu+ru*{}".format(k))
    else:
        print("".join(["tu", "ru" * k]))
else:
    print(s[n%l])
