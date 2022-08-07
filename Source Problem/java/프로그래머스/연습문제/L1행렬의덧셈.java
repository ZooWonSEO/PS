/*
1. 배열의 길이를 가져오는건 length
ex) arr1.length;

*/

class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        
        int row = arr1.length;
        int col = arr1[0].length;
        
        int[][] answer = new int[row][col];
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                answer[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        
        return answer;
    }
}