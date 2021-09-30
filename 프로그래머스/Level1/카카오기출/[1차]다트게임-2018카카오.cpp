#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int arr[3] = {0,};
    int cnt = 0;
    
    for(int i=0; i<dartResult.size(); i++){
        
        if(dartResult[i]=='S' || dartResult[i]=='D' || dartResult[i]=='T'){
            
            arr[cnt] = (int)dartResult[i-1]-'0';
            if(dartResult[i-2]>='0' && dartResult[i-2]<='9'){
                arr[cnt] = 10;
            }
            
            if(dartResult[i]=='D'){
                arr[cnt] = arr[cnt]*arr[cnt];
            }
            else if(dartResult[i]=='T'){
                arr[cnt] = arr[cnt]*arr[cnt]*arr[cnt];
            }
            
            
            if(i+1<dartResult.size()){
                if(dartResult[i+1]=='*'){
                    arr[cnt] = arr[cnt]*2;    
                    if(cnt>0){
                        arr[cnt-1] = arr[cnt-1]*2;
                    }
                }
                else if(dartResult[i+1]=='#'){
                    arr[cnt] = arr[cnt]*-1;
                }
            }
            cnt++;
        }
    }
    
    answer = arr[0] + arr[1] + arr[2];
    
    return answer;
}