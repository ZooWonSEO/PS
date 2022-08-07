#include <string>
#include <vector>
using namespace std;

// 풀이법: 피보니차수가 굉장히 커지기 때문에 저장할 때 나눗셈을 진행해줘야한다.

long long dp[100002] = {0,};
int solution(int n) {

    dp[1] = 1;
    dp[2] = 1;
    
    if(n>=3){
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] = dp[i]%1234567;
        }
    }
    
    return dp[n];
}