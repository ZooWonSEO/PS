#include <string>
#include <vector>

using namespace std;

int dec_to_bin(int num){
    
    int cnt = 0;
    while(num>0){
        if(num%2==1){
            cnt++;
        }
        num = num/2;
    }
    return cnt;
}

int solution(int n) {

    int n_cnt = dec_to_bin(n);
    int num = n+1;
    while(1){
        int cnt = dec_to_bin(num);
        if(n_cnt == cnt)
            break;
        num++;
    }
    
    return num;
}