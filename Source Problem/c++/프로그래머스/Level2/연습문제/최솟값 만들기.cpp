#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
풀이: 한쪽은 오름차순, 반대는 내림차순으로 곱해주면 최솟값이 된다.
*/

bool comp(int a, int b){
    return a>b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), comp);
    
    for(int i=0; i<A.size(); i++){
        answer = answer + (A[i]*B[i]);
    }
    
    return answer;
}