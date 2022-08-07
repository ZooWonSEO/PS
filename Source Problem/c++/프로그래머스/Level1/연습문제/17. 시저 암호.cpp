#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            answer = answer + s[i];
            continue;
        }
        
        if(s[i]>='a'&&s[i]<='z'){
            int asc = (int)s[i] + n;
            asc = asc - (int)'a';
            asc = asc%26 + (int)'a';
            answer = answer + (char)asc;
        }
        
        if(s[i]>='A'&&s[i]<='Z'){
            int asc = (int)s[i] + n;
            asc = asc - (int)'A';
            asc = asc%26 + (int)'A';
            answer = answer + (char)asc;
        }
    }
    return answer;
}