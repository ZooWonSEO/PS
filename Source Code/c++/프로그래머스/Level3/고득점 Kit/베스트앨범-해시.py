def solution(genres, plays):
    answer = []
    play_dict = dict()
    music_dict = dict()
    
    for i in range(0, len(plays)) :
        if genres[i] not in play_dict.keys() :
            play_dict[genres[i]] = plays[i]
            music_dict[genres[i]] = list()
            music_dict[genres[i]].append([i,plays[i]])
        else :
            play_dict[genres[i]] += plays[i]
            music_dict[genres[i]].append([i,plays[i]]) 
    
    play_dict = sorted(play_dict.items(), key=lambda x:x[1], reverse=True)

    for k in music_dict.keys() :
        k_list = music_dict[k]
        music_dict[k] = sorted(k_list, key=lambda x:(-x[1],x[0]))
            
    for i in range(0, len(play_dict)):
        target_g = play_dict[i][0]
        target_list = music_dict[target_g]
        
        for j in range(0,len(target_list)):
            if j==2:
                break
            answer.append(target_list[j][0])
    
    return answer