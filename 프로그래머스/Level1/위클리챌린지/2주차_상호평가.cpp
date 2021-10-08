/*
풀이 : 조건을 잘봐야한다. 최소, 최댓값일 경우일지라도, 유일한 값이 아니면 배제하지 않는다.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int num = scores.size();
    
    for(int j=0; j<scores.size(); j++){
        int total = 0;
        int min_cnt = 0;
        int max_cnt = 0;
        
        for(int i=0; i<scores[j].size(); i++){
            if(scores[j][j]>scores[i][j]){
                min_cnt++;
            }    
            if(scores[j][j]<scores[i][j]){
                max_cnt++;
            }
            total = total + scores[i][j];
        }
        
        int avg = 0;
        
        if(min_cnt==(num-1) || max_cnt==(num-1)){
            total = total - scores[j][j];
            avg = total / (num-1);
        }
        else{
            avg = total / num;
        }
        
        if(avg>=90){
            answer = answer + "A";
        }
        else if(avg>=80 && avg<90){
            answer = answer + "B";
        }
        else if(avg>=70 && avg<80){
            answer = answer + "C";
        }
        else if(avg>=50 && avg<70){
            answer = answer + "D";
        }
        else if(avg<50){
            answer = answer + "F";
        }
    }
    
    return answer;
}
