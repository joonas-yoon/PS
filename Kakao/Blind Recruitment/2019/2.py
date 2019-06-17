# Problem 2

import bisect

def solution(N, stages):
    tried = [0 for _ in range(N)]
    failed = [0 for _ in range(N)]
    stages.sort()
    for id in range(N):
        low = bisect.bisect_left(stages, id+1, lo=0, hi=len(stages))
        high = bisect.bisect_right(stages, id+1, lo=0, hi=len(stages))
        tried[id] = len(stages) - low
        failed[id] = high - low
    
    res = [(i+1, 0 if tried[i] == 0 else failed[i] / tried[i]) for i in range(N)]
    res = sorted(res, key=lambda s: s[1], reverse=True)
    answer = [r[0] for r in res]
    return answer