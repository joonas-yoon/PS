def solution(arrangement):
    s = []
    answer = 0
    prev = None
    for x in arrangement:
        if x is '(':
            s.append(0)
        else:
            s.pop()
            answer += 1 if prev is ')' else len(s)
        prev = x

    return answer