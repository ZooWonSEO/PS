#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
0. 에라토스테네스의 체
*/

int solution(int n) {
    int answer = 0;
    int arr[n+1];
    
    for(int i=0; i<n+1; i++){
        arr[i] = 0;
    }
    
    for(int i=2; i<sqrt(n)+1; i++){
        for(int j=i+i; j<=n; j=j+i){
            if(arr[j]==1)
                continue;
            arr[j]=1;
        }
    }
    
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            answer++;
        }
    }
    
    return answer;
}