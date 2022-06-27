#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int sz = s.size();
    
    if(sz%2==0){
        answer = s[(sz/2)-1];
        answer = answer + s[sz/2];
    }
    else if(sz%2==1){
        answer = s[sz/2];
    }
    
    return answer;
}