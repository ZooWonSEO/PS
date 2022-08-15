#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 1001;
    int sz = 0;
    
    if(s.size()%2==0){
        sz = s.size()/2;
    }
    else{
        sz = (s.size()/2) + 1;
    }
    
    for(int i=1; i<=sz; i++){
        int cur_cnt = 0;
        int cnt = 1;
        string cur_s = s.substr(0,i);
        string cur_ans = "";
        
        for(int j=i; j<s.size(); j=j+i){
            string tmp = s.substr(j,i);
            if(tmp==cur_s){
                cnt++;
            }
            else{
                cur_cnt = cnt;
                cnt = 1;
                if(cur_cnt>1){
                    cur_ans = cur_ans + to_string(cur_cnt);
                }
                cur_ans = cur_ans + cur_s;
                cur_s = tmp;
            }
        }
        
        if(cnt>1){
            cur_ans = cur_ans + to_string(cnt);
        }
        cur_ans = cur_ans + cur_s;
        int cur_sz = cur_ans.size();
        
        answer = min(answer, cur_sz);
    }
    
    return answer;
}