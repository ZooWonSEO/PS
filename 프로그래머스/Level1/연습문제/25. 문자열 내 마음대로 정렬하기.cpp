#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx=0;
bool comp(string a, string b){
    if(a[idx]!=b[idx]){
        return a[idx] < b[idx];
    }
    else{
        return a<b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}