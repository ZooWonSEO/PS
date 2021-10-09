#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//풀이법: 순서대로 2개씩 lcm을 구해나간다.

int GCD(int a, int b){
    
    while(b!=0){
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    
    int num = arr[0];
    int lcm = 0;
    for(int i=1; i<arr.size(); i++){
        int gcd = GCD(num, arr[i]);
        lcm = gcd*(num/gcd)*(arr[i]/gcd);
        num = lcm;
    }
    
    answer = lcm;
    
    return answer;
}