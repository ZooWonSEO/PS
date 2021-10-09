#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    
    int sz = 0;
    if(n%2==0){
        sz = n/2;
    }
    else{
        sz = (n+1)/2;
    }
    
    int cnt = 1;
    int total = 0;
    
    for(int i=1; i<sz; i++){
        int total = 0;
        int j = i;
        while(1){
            total = total + j;
            if(total>=n){
                break;
            }
            j++;
        }
        if(total==n){
            cnt++;
        }
    }
    
    return cnt;
}