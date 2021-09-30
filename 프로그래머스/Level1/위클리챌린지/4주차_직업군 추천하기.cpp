#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    string jobs[5] = {"SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"};
    int score[5] = {0,};
    map<string, int> m;
    
    for(int i=0; i<languages.size(); i++){
        m[languages[i]] = preference[i];
    }
    
    for(int i=0; i<table.size(); i++){
        vector<string> v;
        string tmp = "";
        for(int j=0; j<table[i].size(); j++){
            if(table[i][j]==' '){
                v.push_back(tmp);
                tmp = "";
            }
            else{
                tmp = tmp + table[i][j];
            }
        }
        v.push_back(tmp);
        
        for(int j=1; j<v.size(); j++){
            if(m.find(v[j])!=m.end()){
                score[i] = score[i] + (6-j)*m[v[j]];
            }
        }
    }
    
    int mx = -1;
    for(int i=0; i<5; i++){
        if(score[i]>mx){
            mx = score[i];
        }
    }
    
    vector<string> sv;
    for(int i=0; i<5; i++){
        if(score[i]==mx){
            sv.push_back(jobs[i]);
        }
    }
    
    sort(sv.begin(), sv.end());
    
    return sv[0];
}