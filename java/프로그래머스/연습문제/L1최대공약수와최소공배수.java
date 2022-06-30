class Solution {
    public long[] solution(long n, long m) {
        long[] answer = new long[2];
        
        answer[0] = gcd(n, m);
        answer[1] = answer[0] * (n/answer[0]) * (m/answer[0]);
        
        return answer;
    }
    
    public long gcd(long a, long b) {
        
        if(b == 0){
            return a;
        }
        else{
            return gcd(b, a%b);
        }
    }
    
}