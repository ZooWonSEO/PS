#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
풀이: *=11, #=12
*/

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> v = {
        {3,1}, {0,0}, {0,1}, {0,2},
        {1,0}, {1,1}, {1,2}, {2,0}, 
        {2,1}, {2,2}, {2,3}, {3,0}, {3,2}
    };
        
    int left = 11;
    int right = 12;
    
    for(int i=0; i<numbers.size(); i++){

        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer = answer + "L";
            left = numbers[i];
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer = answer + "R";
            right = numbers[i];
        }
        else if(numbers[i]==2 || numbers[i]==5 || numbers[i]==8 || numbers[i]==0){
            int l_cnt = abs(v[left].first-v[numbers[i]].first) + abs(v[left].second-v[numbers[i]].second);
            int r_cnt = abs(v[right].first-v[numbers[i]].first) + abs(v[right].second-v[numbers[i]].second);
            
            if(l_cnt==r_cnt){
                if(hand=="right"){
                    answer = answer + "R";
                    right = numbers[i];
                }
                else if(hand=="left"){
                    answer = answer + "L";
                    left = numbers[i];
                }
            }
            else if(l_cnt>r_cnt){
                answer = answer + "R";
                right = numbers[i];
            }
            else if(l_cnt<r_cnt){
                answer = answer + "L";
                left = numbers[i];
            }
        }
    }
    return answer;
}