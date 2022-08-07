#include <string>
#include <vector>

/*
int => string : to_string(int idx);
*/

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int idx = -1;
    
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i]=="Kim"){
            idx = i;
            break;
        }
    }
    
    answer = "김서방은 " + to_string(idx) + "에 있다";
    
    return answer;
}