#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

char arr[5] = {'A', 'E', 'I', 'O', 'U'};
vector<string> total;

void dfs(vector<char> v, int cnt){
    if(v.size()==cnt){
        string tmp = "";
        for(int i=0; i<v.size(); i++){
            tmp = tmp + v[i];
        }
        total.push_back(tmp);
        return ;
    }
    
    for(int i=0; i<5; i++){
        v.push_back(arr[i]);
        dfs(v, cnt);
        v.pop_back();
    } 
}

int solution(string word) {
    int answer = 0;
    vector<char> v;
    total.clear();
    
    for(int i=1; i<=5; i++){
        v.clear();
        dfs(v, i);
    }
    
    sort(total.begin(), total.end());
    
    for(int i=0; i<total.size(); i++){
        if(total[i]==word){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}