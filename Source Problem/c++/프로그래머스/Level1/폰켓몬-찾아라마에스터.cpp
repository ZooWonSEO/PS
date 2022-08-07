#include <vector>
using namespace std;

int arr[200002] = {0,};

int solution(vector<int> nums)
{
    int answer = 0;
    for(int i=1; i<=200000; i++){
        arr[i]=0;
    }
    
    for(int i=0; i<nums.size(); i++){
        arr[nums[i]]++;
    }
    
    for(int i=1; i<=200000; i++){
        if(arr[i]>0){
            answer++;
        }
    }
    
    int sz = nums.size()/2;
    if(answer < sz){
        return answer;
    }
    else {
        return sz;
    }
}