#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long tmp = sqrt(n);
    
    if(tmp*tmp != n){
        return -1;
    }
    else{
        return (tmp+1)*(tmp+1);
    }
}