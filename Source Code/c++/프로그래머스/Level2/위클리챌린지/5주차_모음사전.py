def dfs(my_list, tmp_list, word_dic, visited, cnt, target_sz) :
    
    if cnt == target_sz :
        w = ''
        for tmp in tmp_list:
            w = w + tmp
        my_list.append(w)   
        return
    
    for i in range(0, 5) :
        tmp_list.append(word_dic[i])
        dfs(my_list, tmp_list, word_dic, visited, cnt+1, target_sz)
        tmp_list.pop()
    
    return

def solution(word):
    answer = 0
    my_list = []
    tmp_list = []
    word_dic = ['A', 'E', 'I', 'O', 'U']
    visited = [0 for _ in range(5)]
    
    for i in range(1, 6) :
        dfs(my_list, tmp_list, word_dic, visited, 0, i)
    
    my_list = sorted(my_list)
    
    for i in range(0,len(my_list)) :
        if word == my_list[i] :
            answer = i+1
            break
    
    return answer