def solution(sizes):
    answer = 0
    my_list = []
    
    for size in sizes :
        if size[1] > size[0] :
            size[0], size[1] = size[1], size[0]
        my_list.append(size)
    
    s1 = sorted(my_list, key=lambda x:x[0], reverse=True)
    s2 = sorted(my_list, key=lambda x:x[1], reverse=True)
    
    h = s1[0][0]
    w = s2[0][1]
    
    answer = h*w
    
    return answer