#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Find(int parents[], int v){
    if(parents[v]==v){
        return v;
    }
    parents[v] = Find(parents, parents[v]);
    return parents[v];
}

void Union(int parents[], int v1, int v2){
    int p1 = Find(parents, v1);
    int p2 = Find(parents, v2);
    
    if(p1==p2){
        return;
    }
    else if(p1<p2){
        parents[p2] = p1;
    }
    else if(p1>p2){
        parents[p1] = p2;
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 99999;
    int parents[102];
    int sz = wires.size();
    
    for(int i=0; i<sz; i++){
        for(int j=0; j<=n; j++){
            parents[j] = j;
        }
        
        for(int j=0; j<sz; j++){
            if(i==j)
                continue;
            if(Find(parents, wires[j][0])!=Find(parents, wires[j][1])){
                Union(parents, wires[j][0], wires[j][1]);
            }
        }
        
        for(int j=1; j<=n; j++){
            Find(parents, j);
        }
        
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(parents[j]==1){
                cnt++;
            }
        }
        answer = min(answer, abs(cnt-(n-cnt)));
    }
    return answer;
}