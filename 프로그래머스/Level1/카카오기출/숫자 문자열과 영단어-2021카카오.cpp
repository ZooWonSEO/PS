#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> v;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            v.push_back(s[i]-'0');
        }
        else if(s[i]=='z'){
            v.push_back(0);
            i = i+3;
        }
        else if(s[i]=='o'){
            v.push_back(1);
            i = i+2;
        }
        else if(s[i]=='e'){
            v.push_back(8);
            i = i+4;
        }
        else if(s[i]=='n'){
            v.push_back(9);
            i = i+3;
        }
        else if(s[i]=='t'){
            if(s[i+1]=='w'){
                v.push_back(2);
                i = i+2;
            }
            else if(s[i+1]=='h'){
                v.push_back(3);
                i = i+4;
            }
        }
        else if(s[i]=='f'){
            if(s[i+1]=='o'){
                v.push_back(4);
                i = i+3;
            }
            else if(s[i+1]=='i'){
                v.push_back(5);
                i = i+3;
            }
        }
        else if(s[i]=='s'){
            if(s[i+1]=='i'){
                v.push_back(6);
                i = i+2;
            }
            else if(s[i+1]=='e'){
                v.push_back(7);
                i = i+4;
            }
        }
    }
    
    int cnt=1;
    for(int i=v.size()-1; i>=0; i--){
        answer = answer + v[i]*cnt;
        cnt = cnt*10;
    }
    
    return answer;
}