#include <string>
#include <vector>

using namespace std;

int arr[1001] = {0,};

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=1; i<=right; i++){
        int cnt = 0;
        for(int j=1; j<=i; j++){
            if(i%j==0){
                cnt++;
            }
        }
        arr[i] = cnt;
    }
    
    for(int i=left; i<=right; i++){
        if(arr[i]%2==0){
            answer = answer + i;
        }
        else if(arr[i]%2==1){
            answer = answer - i;
        }
    }
    
    return answer;
}