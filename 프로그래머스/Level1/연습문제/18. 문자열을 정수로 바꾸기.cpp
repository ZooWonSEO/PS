#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt = 1;
    
    if(s[0]=='-'){
        for(int i=s.size()-1; i>=1; i--){
            answer = answer + (s[i]-'0')*cnt;
            cnt = cnt*10;
        }
        return -answer;
    }
    else if(s[0]=='+'){
        for(int i=s.size()-1; i>=1; i--){
            answer = answer + (s[i]-'0')*cnt;
            cnt = cnt*10;
        }
        return answer;
    }
    else{
         for(int i=s.size()-1; i>=0; i--){
            answer = answer + (s[i]-'0')*cnt;
            cnt = cnt*10;
        }
        return answer;
    }
}