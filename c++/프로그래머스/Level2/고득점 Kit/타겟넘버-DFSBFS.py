answer = 0

def dfs(numbers, target, cnt, total) :
    if cnt == len(numbers) :
        if total == target :
            global answer
            answer +=1
        return
    
    dfs(numbers, target, cnt+1, total+numbers[cnt])
    dfs(numbers, target, cnt+1, total-numbers[cnt])
    
    return

def solution(numbers, target):
    global answer
    
    dfs(numbers, target, 1, -numbers[0])
    dfs(numbers, target, 1, numbers[0])

    return answer