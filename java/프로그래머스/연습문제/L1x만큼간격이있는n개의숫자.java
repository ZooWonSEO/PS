/*
1. 배열선언
long[] answer = new long[n];

2. 자료형 :  -10000000 이상, 10000000
long으로 바꿔줘야됨

*/

class Solution {
    public long[] solution(long x, int n) {
        long[] answer = new long[n];
        
        for(int i=0; i<n; i++){
            answer[i] = x * (i+1);  
        }
        
        return answer;
    }
}