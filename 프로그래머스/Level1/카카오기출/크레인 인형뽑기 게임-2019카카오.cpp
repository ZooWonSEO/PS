#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    stack<int> s;
    
    for(int i=0; i<moves.size(); i++){
        int cur_pos = moves[i]-1;
        for(int j=0; j<board.size(); j++){
            if(board[j][cur_pos]!=0){
                v.push_back(board[j][cur_pos]);
                board[j][cur_pos] = 0;
                break;
            }
        }
    }

    s.push(v[0]);
    for(int i=1; i<v.size(); i++){
        if(!s.empty()){
            if(s.top()==v[i]){
                answer = answer + 2;
                s.pop();
            }
            else{
                s.push(v[i]);
            }
        }
        else{
            s.push(v[i]);
        }
    }
    
    return answer;
}