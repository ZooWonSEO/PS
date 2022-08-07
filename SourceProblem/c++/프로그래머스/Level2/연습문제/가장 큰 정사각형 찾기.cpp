#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1002][1002] = {0,};

int solution(vector<vector<int>> board)
{
    int n = board.size()+1;
    int m = board[0].size()+1;
    int answer = 0;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            dp[i+1][j+1] = board[i][j];
        }
    }    
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            
            if(dp[i][j]==0)
                continue;
            
            int mn = 9999;
            mn = min(dp[i][j-1], dp[i-1][j]);
            mn = min(mn, dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j], mn+1);
            
            answer = max(dp[i][j], answer);
        }
    }
    
    answer = answer*answer;
    
    return answer;
}