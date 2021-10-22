from collections import deque
def solution(n, edge):
    answer = 0
    
    g = [[] for _ in range(n)]
    visited = [0 for _ in range(n)]
    
    for i in range(0, len(edge)) :
        v1 = edge[i][0] - 1
        v2 = edge[i][1] - 1
        
        g[v1].append(v2)
        g[v2].append(v1)
        
    q = deque()
    q.append(0)
    
    visited[0] = 1
  
    while len(q)>0 :
        cur_v = q[0]
        q.popleft()
                
        for i in range(0, len(g[cur_v])) :
            next_v = g[cur_v][i]
            if visited[next_v] > 0 :
                continue
            
            visited[next_v] = visited[cur_v] + 1
            q.append(next_v)
    
    mx = max(visited)
    answer = visited.count(mx)
    
    return answer