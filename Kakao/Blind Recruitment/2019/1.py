# Problem 1

def solution(record):
    name_of = dict()
    
    for r in record:
        s = r.split()
        if s[0] != "Leave":
            name_of[s[1]] = s[2]
            
    answer = []
    for r in record:
        s = r.split()
        if s[0] != "Change":
            answer.append("{}님이 {}습니다.".format(name_of[s[1]], "들어왔" if s[0] == "Enter" else "나갔"))
    
    return answer