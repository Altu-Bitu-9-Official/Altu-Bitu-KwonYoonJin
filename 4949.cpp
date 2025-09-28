#include <iostream>
#include <stack>
#include <string> // getline 함수 사용하려고
using namespace std;

int main(){
    string input;
    stack<char> stack;
    bool check = true;
    while(1){
        getline(cin,input);
        if(input=="."){
            break;
        }
        for(int i=0; input[i]!='.'; i++){
            if(input[i]=='('||input[i]=='['){ // 여는 괄호면 push
                stack.push(input[i]);
            }
            if(input[i]==')'){ // 닫는 괄호면 짝 맞는지 확인 1
                if(stack.empty()){
                    //cout << "no" << '\n';
                    check = false;
                    break; // continue 가 아닌 break (출력 초과)
                }
                if(stack.top()=='('){
                    stack.pop();
                }
                else{ 
                    //cout << "no" << '\n';
                    check = false;
                    while(!stack.empty()){
                        stack.pop(); // stack 은 claer 함수 없음
                    }
                    break;
                }
            }
            if(input[i]==']'){ // 닫는 괄호면 짝 맞는지 확인 2
                if(stack.empty()){
                    //cout << "no" << '\n';
                    check = false;
                    break;
                }
                if(stack.top()=='['){
                    stack.pop();
                }
                else{
                    //cout << "no" << '\n';
                    check = false;
                    while(!stack.empty()){
                        stack.pop(); 
                    }
                    break;
                }
            }
        }
        if(check==true && stack.empty()){ // 문자열 처리 끝났고, 스택 비어있으면 균형 문자열
            cout << "yes" << '\n';
        }
        else{ // 문자열 처리 끝났는데 스택에 뭔가 남아있으면 비균형 문자열 (no 중복 출력 방지를 위한 check)
            cout << "no" << '\n';
            while(!stack.empty()){
                stack.pop(); 
            }
        }
        check = true;
    }
   



    return 0;
}