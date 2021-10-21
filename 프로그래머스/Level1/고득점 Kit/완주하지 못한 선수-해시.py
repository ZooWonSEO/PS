def solution(participant, completion):
    
    d = dict()
    
    for p in participant :
        if p not in d.keys() :
            d[p] = 1
        else :
            d[p] = d[p] + 1
        
    for c in completion : 
        d[c] = d[c] + 1
        
    for k in d.keys() :
        if d[k]%2 == 1 :
            answer = k
            break
    
    return answer