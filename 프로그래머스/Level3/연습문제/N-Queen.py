answer = 0

def check(visited, cnt) :
    
    for i in range(0, cnt) :
        if visited[cnt] == visited[i] :
            return 0
        if cnt-i == abs(visited[cnt]-visited[i]) :
            return 0
    return 1

def dfs(visited, n, cnt) :
    
    if cnt == n:
        global answer
        answer += 1
        return
    
    for i in range(0, n) :
        visited[cnt] = i
        if check(visited, cnt) == 1 :
            dfs(visited, n, cnt+1)
    
    return

def solution(n):
    global answer
    visited = [0 for _ in range(n)]
    
    dfs(visited, n, 0)
 
    return answer