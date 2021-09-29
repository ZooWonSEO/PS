#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int tmp = x;
    int total = 0;
    
    while(tmp>0){
        total = total + tmp%10;
        tmp = tmp/10;
    }
    
    if(x%total==0){
        return true;
    }
    else{
        return false;
    }
}