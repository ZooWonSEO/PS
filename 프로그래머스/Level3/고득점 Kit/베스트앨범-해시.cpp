#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

bool comp2(pair<string,pair<int,int>> a, pair<string,pair<int,int>> b){
    
    if(a.second.second==b.second.second){
        return a.second.first < b.second.first;
    }
    else{
        return a.second.second > b.second.second;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    map<string, int>::iterator it;
    vector<pair<string,int>> total;
    vector<pair<string,pair<int,int>>> v;
    
    // 1. 각 장르별 플레이 회수 합계 구하기
    for(int i=0; i<genres.size(); i++){
        m[genres[i]] += plays[i];
    }
    
    for(it=m.begin(); it!=m.end(); it++){
        total.push_back(pair<string,int>(it->first,it->second));
    }

    // 2. 각 노래별 플레이 회수 저장
    for(int i=0; i<genres.size(); i++){
        pair<int,int> p;
        p.first = i;
        p.second = plays[i];
        v.push_back(pair<string,pair<int,int>>(genres[i],p));
    }
    
    // 3. 장르별 플레이 회수 높은 순으로 정렬
    sort(total.begin(), total.end(), comp);
    
    // 4. 노래별 플레이 회수 높은 순으로 정렬
    // 재생횟수가 같으면 고유 번호가 낮은 순으로 정렬
    sort(v.begin(), v.end(), comp2);
    
    for(int i=0; i<total.size(); i++){
        string music = total[i].first;
        int cnt = 0;
        for(int j=0; j<v.size(); j++){
            if(cnt==2)
                break;
            if(v[j].first==music){
                answer.push_back(v[j].second.first);
                cnt++;
            }
        }
    }
    
    return answer;
}