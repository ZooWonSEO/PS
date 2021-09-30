#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
풀이 : 조건을 잘봐야한다. 최소, 최댓값일 경우일지라도, 유일한 값이 아니면 배제하지 않는다.
*/

string solution(vector<vector<int>> scores) {
    string answer = "";
    double std[11] = {0,};
    
    for(int j=0; j<scores.size(); j++){
        int mx = -1;
        int mx_cnt = 0;
        int mn = 101;
        int mn_cnt = 0;
        
        for(int i=0; i<scores[j].size(); i++){
            if(scores[i][j]>=mx){
                if(scores[i][j]==mx){
                    mx_cnt++;
                }
                else{
                    mx = scores[i][j];
                    mx_cnt = 1;
                }
            }
            if(scores[i][j]<=mn){
                if(scores[i][j]==mn){
                    mn_cnt++;
                }
                else{
                    mn = scores[i][j];
                    mn_cnt=1;
                }
            }
            std[j] = std[j] + scores[i][j];
        }
        
        int cnt = scores.size();
        if((scores[j][j]==mx && mx_cnt==1) || (scores[j][j]==mn) && mn_cnt==1){
            std[j] = std[j] - scores[j][j];
            cnt--;
        }
        std[j] = std[j]/cnt;
    }
    
    for(int i=0; i<scores.size(); i++){
        
        cout << std[i] << " ";
        
        if(std[i]>=90){
            answer = answer + "A";
        }
        else if(std[i]>=80 && std[i]<90){
            answer = answer + "B";
        }
        else if(std[i]>=70 && std[i]<80){
            answer = answer + "C";
        }
        else if(std[i]>=50 && std[i]<70){
            answer = answer + "D";
        }
        else if(std[i]<50){
            answer = answer + "F";
        }
    }
    
    return answer;
}