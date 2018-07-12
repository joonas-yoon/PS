s = input()
if s[1] != '0':
    print(int(s[0])+int(s[1:]))
else:
    print(int(s[:2])+int(s[2:]))