#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i]>='A' && new_id[i]<='Z'){
            new_id[i] = (char)tolower(new_id[i]);
        }
    }
    
    string s2 = "";
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i]>='a' && new_id[i]<='z'){
            s2 = s2 + new_id[i];
        }
        else if(new_id[i]>='0' && new_id[i]<='9'){
            s2 = s2 + new_id[i];
        }
        else if(new_id[i]=='-' || new_id[i]=='_' || new_id[i]=='.'){
            s2 = s2 + new_id[i];
        }
    }
    
    string s3 = "";
    for(int i=0; i<s2.size(); i++){
        s3 = s3 + s2[i];
        if(s2[i]=='.'){
            int cnt=0;
            for(int j=i+1; j<s2.size(); j++){
                if(s2[j]!='.')
                    break;
                cnt++;
            }
            i = i+cnt;
        }
    }
    
    if(s3[0]=='.'){
        s3 = s3.substr(1,s3.size());
    }
    if(s3[s3.size()-1]=='.'){
        s3 = s3.substr(0,s3.size()-1);
    }
    
    if(s3.size()==0){
        s3 = s3 + "a";
    }
   
    int sz = s3.size();
    if(sz>=16){
        s3 = s3.substr(0,15);
        if(s3[s3.size()-1]=='.'){
            s3 = s3.substr(0,s3.size()-1);
        }
    }
    
    while(s3.size()<=2){
        s3 = s3 + s3[s3.size()-1];
    }
    
    return s3;
}