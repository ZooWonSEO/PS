#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(vector<double> a, vector<double> b){
    if(a[1]==b[1]){
        if(a[2]==b[2]){
            if(a[3]==b[3]){
                return a[0]<b[0];
            }
            else{
                return a[3]>b[3];
            }
        }
        else{
            return a[2]>b[2];
        }
    }
    else{
        return a[1]>b[1];
    }
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<vector<double>> v;
    
    for(int i=0; i<head2head.size(); i++){
        string tmp = head2head[i];
        int win = 0;
        int cnt = 0;
        int over = 0;
        vector<double> v_tmp;
        
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j]=='N')
                continue;
            if(tmp[j]=='W'){
                win++;
                if(weights[i]<weights[j]){
                    over++;
                }
            }
            cnt++;
        }
        
        v_tmp.push_back(i);
        if(cnt==0){
            v_tmp.push_back(0);
        }
        else{
            v_tmp.push_back((double)win/cnt);
        }
        
        v_tmp.push_back(over);
        v_tmp.push_back(weights[i]);
        v.push_back(v_tmp);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i][0]+1);
    }
    return answer;
}