from collections import deque

def solution(begin, target, words):
    answer = 0
    q = deque()
    q.append([begin,0])
    
    while len(q)>0 :
        cur_word = q[0]
        q.popleft()
        
        if cur_word[0] == target :
            answer = cur_word[1]
            break
        
        for word in words :
            cnt = 0
            for i in range(0, len(word)) :
                if cur_word[0][i]!=word[i] :
                    cnt +=1
            
            if cnt==1 :
                q.append([word,cur_word[1]+1])
                words.remove(word)    
    
    return answer