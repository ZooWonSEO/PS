def solution(price, money, count):
    answer = 0

    for i in range(0,count):
        answer = answer + (price*(i+1))
    
    if money >= answer :
        return 0
    
    else :
        return answer-money