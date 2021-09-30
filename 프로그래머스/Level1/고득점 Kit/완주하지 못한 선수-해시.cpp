#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(int i=0; i<participant.size(); i++){
        m[participant[i]]++;
    }
    
    for(int i=0; i<completion.size(); i++){
        m[completion[i]]++;
    }
    
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second%2==1){
            answer = it->first;
            break;
        }
    }
    
    return answer;
}