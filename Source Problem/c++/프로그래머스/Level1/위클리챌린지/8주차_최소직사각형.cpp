#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int d1 = 0;
    int d2 = 0;
    
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0]<sizes[i][1]){
            swap(sizes[i][0], sizes[i][1]);
        }
        
        d1 = max(d1, sizes[i][0]);
        d2 = max(d2, sizes[i][1]);
    }
    
    answer = d1*d2;
    
    return answer;
}