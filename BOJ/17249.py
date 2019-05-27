s = input()
i = s.find('0')
print(s[:i].count('@'), s[i:].count('@'))
