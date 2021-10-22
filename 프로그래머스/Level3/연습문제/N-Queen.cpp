#include <string>
#include <vector>

using namespace std;
int answer = 0;
int visited[16] = {0,};

bool check(int cnt){
    
    for(int i=0; i<cnt; i++){
        if(visited[cnt]==visited[i]){
            return false;
        }
        if(cnt-i == abs(visited[cnt]-visited[i])){
            return false;
        }
    }
    return true;
}

void dfs(int cnt, int target){
    
    if(cnt==target){
        answer ++;
        return;
    }
    
    for(int i=0; i<target; i++){
        visited[cnt] = i;
        if(check(cnt)==true){
            dfs(cnt+1, target);
        }
    }
    return;
}

int solution(int n) {
    dfs(0, n);
    return answer;
}