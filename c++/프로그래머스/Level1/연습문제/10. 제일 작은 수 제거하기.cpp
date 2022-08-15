#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size()==1){
        answer.push_back(-1);
    }
    else{
        int mn = 999999999;
        int idx = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<mn){
                mn = arr[i];
                idx = i;
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(i==idx)
                continue;
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}