#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    string tmp = "";
    
    for(int i=0; i<s.size(); i++){   
        if(s[i]== ' '){
            int num = stoi(tmp);
            v.push_back(num);
            tmp = "";
        }
        else{
            tmp = tmp + s[i];
        }
    }
    int num = stoi(tmp);
    v.push_back(num);
    
    sort(v.begin(), v.end());
    
    answer = answer + to_string(v[0]);
    answer = answer + ' ';
    answer = answer + to_string(v[v.size()-1]);
    
    return answer;
}