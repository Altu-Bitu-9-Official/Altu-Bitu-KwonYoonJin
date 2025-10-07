#include <iostream>

using namespace std;

int num;

int doOperation(string str, int x){
    if(str=="add"){
        if(!(num&(1<<x))){
            num = num | (1<<x);
        }
    }
    else if(str=="remove"){
        if(num&(1<<x)){
            num = num & ~(1<<x);
        }
    }
    else if(str=="check"){
        if(num&(1<<x)){ // x 있으면
            return 1;
        }
        else{ // x 없으면
            return 0;
        }
    }
    else if(str=="toggle"){
         if(num&(1<<x)){ // x 있으면 제거
            num = num & ~(1<<x);
        }
        else{ // x 없으면 추가
            num = num | (1<<x);
        }
    }
    else if(str=="all"){
       //num = num | 1; 이러면 0번째 비트만 1이 된다...
       num = (1<<21)-1; // 21번째~2번째 비트를 모두 1로 만들어줘야 함
    }
    else{ // empty
        num = 0; // num =0
    }

    return 0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,x; int result;
    string str;
    num = 0 ;
    //입력
    cin >> m;

    //연산, 출력
    while(m--){
        cin >> str;
        // 처음에 문제를 제대로 읽지 않고 모든 명령어가 str 와 x를 입력 받는다고 생각해
        // x을 입력받지 않는 all, empty 명령어에 의해 입력이 밀리고
        // 출력이 제대로 나오지 않는 문제 발생 -> case 나누기
        if(str=="all"||str=="empty"){
            result = doOperation(str,0);
        }
        else{
            cin >> x;
            result = doOperation(str,x);
        }
        if(str=="check"){
            cout << result << '\n';
        }
    }

    return 0;
}