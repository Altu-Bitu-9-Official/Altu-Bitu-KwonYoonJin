#include <iostream>
#include <vector>

using namespace std;

int is_similar(string str, string temp){
    vector<int> alp1(26,0);
    vector<int> alp2(26,0);
    int count = 0;
    // 각 문자열의 알파벳 개수를 백터에 저장
    for(char c:str){
        alp1[c-'A']++;
    }
    for(char c: temp){
        alp2[c-'A']++;
    }
    // 문자열 길이 같다면 구성이 같거나(차이가 0), 한 문자가 바뀌어 차이가 2개인 경우 존재
    if(str.size()==temp.size()){
        for(int i=0; i<alp1.size();i++){
            count += abs(alp1[i]-alp2[i]);
        }
        if(count==0 || count ==2){
            return 1;
        }
    } 
    // 문자열 길이가 다르다면 하나 빠져서 차이 1이거나 하나가 추가되어 차이가 1인 경우 존재
    else{
        for(int i=0; i<alp1.size();i++){
            count += abs(alp1[i]-alp2[i]);
        }
        if(count==1){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    int count=0; 
    string str, temp;
    // 입력 
    cin >> n;
    cin >> str;
    n--;
    // 연산 
    while(n--){
        cin >> temp;
        count += is_similar(str,temp);
    }
    // 출력
    cout << count;
    return 0;
}