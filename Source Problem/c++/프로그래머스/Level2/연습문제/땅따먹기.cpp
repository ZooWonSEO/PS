#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//풀이: DP

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i=1; i<land.size(); i++){
        for(int j=0; j<land[i].size(); j++){
            
            int tmp = land[i][j];
            
            for(int k=0; k<4; k++){
                if(j==k)
                    continue;
                land[i][j] = max(land[i][j], tmp + land[i-1][k]);
            }
        }
    }
    
    for(int i=0; i<4; i++){
        answer = max(answer, land[land.size()-1][i]);
    }
    
    return answer;
}