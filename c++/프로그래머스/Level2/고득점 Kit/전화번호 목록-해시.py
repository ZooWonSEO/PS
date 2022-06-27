def solution(phone_book):
    answer = True
    d = dict()
    pb = sorted(phone_book)
    
    for i in range(1, len(pb)) :
        if pb[i].startswith(pb[i-1]) :
            answer = False;
            break
    
    return answer