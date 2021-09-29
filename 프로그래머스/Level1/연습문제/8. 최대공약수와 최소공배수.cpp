#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    if(a<b){
        swap(a,b);
    }
    while(b!=0){
        int tmp = a;
        a = b;
        b = tmp%a;
    }
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd = GCD(n,m);
    int lcm = gcd*(n/gcd)*(m/gcd);
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}