import math
tmp = []

def dfs(numbers, my_set, visited, cnt, sz) :
    
    if cnt==sz :
        answer = ""
        for t in tmp :
            answer = answer + t
        
        my_set.append(int(answer))
        return
    
    for i in range(0, len(numbers)):
        if visited[i]==1 :
            continue
            
        visited[i] = 1
        tmp.append(numbers[i])
        dfs(numbers, my_set, visited, cnt+1, sz)
        tmp.pop()
        visited[i] = 0
    
    return

def solution(numbers):
    answer = 0
    visited = [0 for _ in range(8)]
    my_set = []
    
    for i in range(0, len(numbers)) :
        dfs(numbers, my_set, visited, 0, i+1)
   
    my_set = set(my_set)
    my_set = list(my_set)
    
    for ele in my_set :
        if ele < 2 :
            continue
        
        check = True
        for i in range(2, ele) :
            if ele%i==0 :
                check = False
                break
        
        if check==True :
            answer += 1
            
    return answer