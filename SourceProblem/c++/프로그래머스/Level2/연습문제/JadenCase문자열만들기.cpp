#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            
            if(!(tmp[0]>='0' && tmp[0]<='9')){
                tmp[0] = (char)toupper(tmp[0]);
            }
            
            for(int j=1; j<tmp.size(); j++){
                tmp[j] = (char)tolower(tmp[j]);
            }
            
            answer = answer + tmp;
            answer = answer + s[i];
            tmp = "";
        }
        else{
            tmp = tmp + s[i];
        }
    }
    
    if(!(tmp[0]>='0' && tmp[0]<='9')){
        tmp[0] = (char)toupper(tmp[0]);
    }

    for(int j=1; j<tmp.size(); j++){
        tmp[j] = (char)tolower(tmp[j]);
    }
    
    answer = answer + tmp;
    return answer;
}