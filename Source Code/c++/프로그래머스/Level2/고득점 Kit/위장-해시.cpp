#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    
    map<string, int>::iterator it;
    
    for(it=m.begin(); it!=m.end(); it++){
        answer = answer * (it->second+1);
    }
    
    answer = answer - 1;
    
    return answer;
}