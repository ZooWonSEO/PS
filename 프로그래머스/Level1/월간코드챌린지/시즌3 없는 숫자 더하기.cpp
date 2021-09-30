#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int arr[10] = {0,};
    int answer = 0;
    
    for(int i=0; i<numbers.size(); i++){
        arr[numbers[i]]++;
    }
    
    for(int i=0; i<10; i++){
        if(arr[i]==0){
            answer = answer + i;
        }
    }
    
    return answer;
}