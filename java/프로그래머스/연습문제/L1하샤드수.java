class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        
        int number = x;
        int sum = 0;
        
        while(number != 0){
            
            sum = sum + number % 10;
            number = number / 10;
        }
        
        if(x%sum == 0){
            answer = true;
        }
        else {
            answer = false;
        }
        
        return answer;
    }
}