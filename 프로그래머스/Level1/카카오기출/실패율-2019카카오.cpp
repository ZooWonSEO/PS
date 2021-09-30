#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double fail[502] = {0,};
    int arr[502] = {0,};
    int people = stages.size();
    
    for(int i=0; i<stages.size(); i++){
        arr[stages[i]]++;
    }
    
    vector<double> v;
    for(int i=1; i<=N; i++){
        if(arr[i]==0){
            fail[i] =0;
        }
        else if(arr[i]!=0){
            fail[i] = (double)arr[i]/people;
            people = people-arr[i];
        }
        v.push_back(fail[i]);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=v.size()-1; i>=0; i--){
        double target = v[i];
        for(int j=1; j<=N; j++){
            if(fail[j]==target){
                fail[j] = -1;
                answer.push_back(j);
            }
        }
    }
   
    return answer;
}