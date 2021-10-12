#include <string>
#include <vector>
#include <queue>
using namespace std;

struct comp{
  bool operator()(int a, int b){
      return a > b;
  }   
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, comp> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(1){
        
        if(pq.size()==1){
            if(pq.top()<K){
                answer = -1;
                break;
            }
        }
        
        int num = 0;
        if(!pq.empty()){
            num = pq.top();
            pq.pop();
            if(num>=K){
                break;
            }    
        }
        
        if(!pq.empty()){
            num = num + (2*pq.top());
            pq.pop();
            pq.push(num);
        }
        
        answer ++;
    }
    
    return answer;
}