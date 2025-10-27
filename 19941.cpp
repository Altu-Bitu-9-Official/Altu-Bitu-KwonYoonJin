#include <iostream>
#include <vector>
using namespace std;

int check(string str, vector<bool> hamburgers, int k){
    int count=0;
    bool flag;
    for(int i=0;i<str.size();i++){
        flag = false;
        if(str[i]=='P'){
            for(int t=k;t>=1;t--){ // 왼쪽 범위에서 제일 먼 부분부터 햄버거 찾기
                if((i-t>=0)&&str[i-t]=='H'&&hamburgers[i-t]){
                    flag = true;
                    count++;
                    hamburgers[i-t]=false;
                    break;
                }
            }
            if(!flag){ // 왼쪽 범위에서 햄버거 못 먹은 경우에만
                for(int t=1;t<=k;t++){
                    if((i+t<str.size())&&str[i+t]=='H'&&hamburgers[i+t]){
                        count++;
                        hamburgers[i+t]=false;
                        break;
                    }
                }
            }
            
           
        }
    }
    return count;
}

int main(){
    int n,k;
    string str;
    vector<bool> hamburgers;
    cin >> n >> k;
    hamburgers.assign(n,false);
    cin >> str;
    // 계산
    for(int i=0;i<str.size();i++){
        if(str[i]=='H'){
            hamburgers[i]=true;
        }
    }
    
    // 출력
    cout << check(str,hamburgers,k);
    return 0;
}