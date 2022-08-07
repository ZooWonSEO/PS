#include <string>
#include <vector>

using namespace std;

string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    string answer = "";
    int cnt = 4;
    
    for(int i=1; i<=a; i++){
        if(i==a){
            cnt = cnt +b;
        }
        else{
            cnt = cnt + months[i];
        }
    }
    
    answer = days[cnt%7];
    
    return answer;
}