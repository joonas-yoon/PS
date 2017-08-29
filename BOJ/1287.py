s = raw_input()
def is_num(c, y):
    k = "0123456789" + y
    return k.find(c) != -1

try:
    for i in range(0, len(s)):
        if "+-/*".find(s[i]) != -1:
        	if i > 0 and is_num(s[i-1], ")") and is_num(s[i+1], "("): pass
        	else: raise
        if s[i] == '(' and not is_num(s[i+1], "("): raise
        if s[i] == ')' and not is_num(s[i-1], ")"): raise
    print eval(s)
except:
    print "ROCK"
