#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int sz = s.size();
    
    if(sz==4 || sz==6){
        for(int i =0; i<sz; i++){
            if(s[i]>='0' && s[i]<='9')
                continue;
            return false;
        }
        return true;
    }
    return false;
}