def solution(array, commands):
    answer = []
    
    for cmd in commands :
        i = cmd[0] - 1
        j = cmd[1] - 1
        k = cmd[2] - 1
        
        tmp_list = array[i:j+1]
        tmp_list = sorted(tmp_list)
        answer.append(tmp_list[k])
        
    return answer