def solution(numbers):
    answer = ''
    
    for i in range(0, len(numbers)) :
        numbers[i] = str(numbers[i])
    
    num_list = sorted(numbers, key=lambda x:x*3, reverse=True)
    
    for i in range(0, len(num_list)) :
        answer = answer + num_list[i]
    
    answer = str(int(answer))
    
    return answer