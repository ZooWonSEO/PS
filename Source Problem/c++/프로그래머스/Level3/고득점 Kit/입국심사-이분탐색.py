def solution(n, times):
    answer = 0
    
    left = 1
    right = n*max(times)
    
    while left<=right :
        
        total = 0
        mid = int((left+right)/2)
        
        for time in times :
            total = total + int(mid/time)
        
        if total >= n :
            right = mid-1
            answer = mid
        
        else :
            left = mid+1
            
    return answer