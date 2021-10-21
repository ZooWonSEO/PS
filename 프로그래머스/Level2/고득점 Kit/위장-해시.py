def solution(clothes):
    answer = 0
    d = dict()
    
    for cloth in clothes :
        if cloth[1] not in d.keys() :
            d[cloth[1]] = 1
        else :
            d[cloth[1]] += 1
        
    num = 1
    for k in d.keys() :
        num *= (d[k]+1)
    
    answer = num - 1
    
    return answer