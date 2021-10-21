answer = 0

def Find(parents, v) :
    if parents[v]==v:
        return v
    parents[v] = Find(parents, parents[v])
    return parents[v]

def Union(parents, v1, v2) :
    p1 = Find(parents, v1)
    p2 = Find(parents, v2)
    
    if p1 == p2 :
        return
    elif p1 < p2 :
        parents[p2] = p1
    elif p1 > p2 :
        parents[p1] = p2
    return
        
def solution(n, costs):
    global answer
    costs = sorted(costs, key=lambda x:x[2])
    
    parents = [0 for _ in range(0,n)]
    for i in range(0, n):
        parents[i] = i
    
    for cost in costs :
        if Find(parents, cost[0]) != Find(parents, cost[1]) :
            answer += cost[2]
            Union(parents, cost[0], cost[1])
    
    return answer