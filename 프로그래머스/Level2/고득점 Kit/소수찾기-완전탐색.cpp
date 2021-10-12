#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;

int visited[8] = {0,};
vector<char> v;
set<int> st;
set<int>::iterator it;

void init(){
    for(int i=0; i<8; i++){
        visited[i] = 0;
    }
    v.clear();
    return;
}

void dfs(string numbers, int cnt){
    
    if(v.size()==cnt){
        string tmp = "";
        for(int i=0; i<v.size(); i++){
            tmp = tmp + v[i];
        }
        st.insert(stoi(tmp));
        return;
    }
    
    for(int i=0; i<numbers.size(); i++){
        if(visited[i]==1)
            continue;
        
        visited[i] = 1;
        v.push_back(numbers[i]);
        dfs(numbers, cnt);
        v.pop_back();
        visited[i] = 0;
    }
    return;    
}

int solution(string numbers) {
    int answer = 0;
    int sz = numbers.size();
    
    for(int i=1; i<=sz; i++){    
        dfs(numbers, i);
    }
    
    for(it=st.begin(); it!=st.end(); it++){
        int cur_num = *it;
        
        if(cur_num<2)
            continue;
        
        bool check = true;
        
        for(int i=2; i<=sqrt(cur_num); i++){
            if(cur_num%i==0){
                check = false;
                break;
            }
        }
        
        if(check==true)
            answer++;
    }
    
    return answer;
}