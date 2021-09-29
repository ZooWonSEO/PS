#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            cnt =0;
            answer = answer + s[i];
            continue;
        }
        
        if(cnt%2==0){
            answer = answer + (char)toupper(s[i]);
        }
        else if(cnt%2==1){
            answer = answer + (char)tolower(s[i]);
        }
        cnt++;
    }
    
    return answer;
}