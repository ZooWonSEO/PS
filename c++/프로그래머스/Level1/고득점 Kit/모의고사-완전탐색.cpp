#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[5] = {1, 2, 3, 4, 5};
    int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[10]  = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int s1=0;
    int s2=0;
    int s3=0;
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==p1[i%5]){
            s1++;
        }
        if(answers[i]==p2[i%8]){
            s2++;
        }
        if(answers[i]==p3[i%10]){
            s3++;
        }
    }
    
    int mx = 0;
    mx = max(s1, max(s2,s3));
    
    if(s1==mx){
        answer.push_back(1);
    }
    if(s2==mx){
        answer.push_back(2);
    }
    if(s3==mx){
        answer.push_back(3);
    }
    
    return answer;
}