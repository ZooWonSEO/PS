#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int visited[46] = {0,};
vector<int> v;
int mx = 6;
int mn = 1;

void check(vector<int> win_nums){
    
    int cnt = 0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(win_nums[i]==v[j]){
                cnt++;
                break;
            }
        }
    }
    
    if(cnt==0){
        mx = min(mx, 6);
        mn = max(mn, 6);
    }
    else if(cnt>0){    
        mx = min(mx, 7-cnt);
        mn = max(mn, 7-cnt);
    }
    
    return;
}

void dfs(int start, vector<int> win_nums){
    
    if(v.size()==6){
        check(win_nums);
        return;
    }
    
    for(int i=start; i<=45; i++){
        if(visited[i]==1)
            continue;
        
        visited[i] = 1;
        v.push_back(i);
        dfs(i, win_nums);
        v.pop_back();
        visited[i] = 0;
    }
    
    return;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i]>0 && visited[lottos[i]]==0){
            visited[lottos[i]] = 1;
            v.push_back(lottos[i]);
        }
    }
    
    dfs(1, win_nums);
    
    answer.push_back(mx);
    answer.push_back(mn);
    
    return answer;
}