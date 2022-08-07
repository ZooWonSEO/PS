#include <string>
#include <vector>
#include <iostream>
using namespace std;

int visited[21] = {0,};
vector<int> v;
int answer = 0;

void init(){
    for(int i=0; i<21; i++){
        visited[i] = 0;
    }
    v.clear();
    return;
}

void dfs(vector<int> numbers, int target, int sz, int cnt, int total){
    
    if(cnt==sz){
        if(total==target){
            answer++;
        }
        return;
    }
    
    dfs(numbers, target, sz, cnt+1, total+numbers[cnt]);
    dfs(numbers, target, sz, cnt+1, total-numbers[cnt]);
    
    return;
}

int solution(vector<int> numbers, int target) {
    int sz = numbers.size();
    int total = numbers[0];
    
    dfs(numbers, target, sz, 1, total);
    dfs(numbers, target, sz, 1, -total);
    
    return answer;
}