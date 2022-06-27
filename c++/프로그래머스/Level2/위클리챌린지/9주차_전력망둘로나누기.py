def init(parents) :
    for i in range(0, len(parents)) :
        parents[i] = i
    return

def Find(parents, v) :
    if parents[v] == v :
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

def Start(wires, parents, visited) :
    for i in range(0, len(wires)) :
        if visited[i]==1 :
            continue
        v1 = wires[i][0]-1
        v2 = wires[i][1]-1
        
        if Find(parents, v1) != Find(parents, v2) :
            Union(parents, v1, v2)
    
    for i in range(0, len(parents)) :
        Find(parents, i)
    
    cnt = 0 
    for i in range(0, len(parents)) :
        if parents[i] == 0 :
            cnt += 1
    
    return abs(cnt-(len(parents)-cnt))
    
def solution(n, wires):
    answer = 102
    parents = [0 for _ in range(n)]
    visited = [0 for _ in range(n)]
    
    for i in range(0, len(wires)) :
        visited[i] = 1
        init(parents)
        answer = min(answer, Start(wires, parents, visited))
        visited[i] = 0
    
    return answer