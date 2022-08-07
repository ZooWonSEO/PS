#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=1; i<phone_book.size(); i++){
        string tmp = phone_book[i-1];
        if(tmp.size()>phone_book[i].size())
            continue;
        
        bool check = true;
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j]!=phone_book[i][j]){
                check = false;
                break;
            }
        }
        if(check==true){
            answer = false;
            break;
        }
    }
    
    return answer;
}