#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
풀이: 자기자신이 lost에 있는 먼저 확인해줄것!!!
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr_lost[33] = {0,};
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<lost.size(); i++){
        arr_lost[lost[i]] = 1;
    }
    
    vector<int> v;
    for(int i=0; i<reserve.size(); i++){
        if(arr_lost[reserve[i]]==1){
            arr_lost[reserve[i]] = 0;
            continue;
        }
        v.push_back(reserve[i]);
    }
    
    for(int i=0; i<v.size(); i++){
        int num = v[i];
        if(arr_lost[num-1]==1){
            arr_lost[num-1] = 0;
            continue;
        }
        if(arr_lost[num+1]==1){
            arr_lost[num+1]=0;
        }
    }
    
    int cnt =0;
    for(int i=1; i<=n; i++){
        if(arr_lost[i]==1){
            cnt++;
        }
    }
    
    answer = n-cnt;
    
    return answer;
}