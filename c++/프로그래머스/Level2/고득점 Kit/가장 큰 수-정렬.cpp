#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
테케 11번: numbers가 [0,0,0]인 경우 answer가 "000"임 => "0"으로 바꿔야함.
*/

bool comp(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i=0; i<numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++){
        answer= answer + v[i];
    }
    
    if(answer[0]=='0'){
        answer = "0";
    }
    
    return answer;
}