answer = 0

def dfs(n, computers, visited, x, y) :
    
    visited[x][y] = 1
    
    for i in range(0, n) :
        if visited[y][i]==1 or computers[y][i]==0 :
            continue
        dfs(n, computers, visited, y, i)
    
    return

def solution(n, computers):
    global answer
    visited = [[0]*n for _ in range(n)]
    print(visited)
    
    for i in range(0, n) :
        for j in range(0, n) :
            if visited[i][j]==1 or computers[i][j]==0:
                continue
            dfs(n, computers, visited, i, j)
            answer += 1
            
    return answer