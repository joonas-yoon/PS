import operator
n, m = list(map(int, input().split()))

solve = {}
for i in range(m) :
    inputs = input().split()
    a, b = list(map(int, inputs[:2]))
    c = inputs[2]

    if(b not in solve) :
        solve[b] = {}
    solve[b][a] = c

result = []

for key, value in sorted(solve.items(), key=operator.itemgetter(0)) :
    for k, v in sorted(value.items(), key=operator.itemgetter(0)) :
        result.append(v)

print(''.join(result))