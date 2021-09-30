#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for(int i=0; i<signs.size(); i++){
        if(signs[i]==true){
            answer = answer + absolutes[i];
        }
        else if(signs[i]==false){
            answer = answer - absolutes[i];
        }
    }
    
    return answer;
}