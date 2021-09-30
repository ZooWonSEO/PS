#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
풀이법 : size()는 계속 변한다. 이점을 유의하자.
*/

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        vector<int> v1;
        vector<int> v2;
        
        while(arr1[i]>0){
            v1.push_back(arr1[i]%2);
            arr1[i] = arr1[i]/2;
        }
        while(arr2[i]>0){
            v2.push_back(arr2[i]%2);
            arr2[i] = arr2[i]/2;
        }
        
        int sz1 = v1.size();
        int sz2 = v2.size();
        
        for(int i=0; i<n-sz1; i++){
            v1.push_back(0);
        }
        for(int i=0; i<n-sz2; i++){
            v2.push_back(0);
        }
        
        string s = "";
        for(int i=n-1; i>=0; i--){
            if(v1[i]==0 && v2[i]==0){
                s = s+" ";
            }
            else if(v1[i]==1 || v2[i]==1){
                s = s+"#";
            }
        }
        answer.push_back(s);
    }
    
    return answer;
}