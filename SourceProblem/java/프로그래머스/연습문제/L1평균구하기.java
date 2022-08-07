class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        int arrLen = arr.length;
        
        for(int i=0; i<arrLen; i++){
            answer = answer + arr[i];
        }
        
        answer = answer / arrLen;
        
        return answer;
    }
}