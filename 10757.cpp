#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    string a, b, result;
    int temp, carry = 0; // carry 0으로 초기화 필수 (첫 번째 반복에서 쓰레기 값 x)
    cin >> a >> b;
    int len = a.size()>b.size() ? a.size(): b.size();
    int aIdx = a.size()-1, bIdx = b.size()-1; // 문자열 가장 뒤에서 덧셈 시작
    while(len--){
        if(aIdx>=0 && bIdx>=0){
            temp = (a[aIdx--]-'0')+(b[bIdx--]-'0')+carry; // 일단 일의 자리 수 덧셈 (숫자 변환 필수!!)
            if(temp>=10){
                carry = 1; 
                temp -= 10; // 한자릿수 되게
                st.push(temp);
            }
            else{
                st.push(temp);;
                carry = 0;
            }
        }
        else if(aIdx>=0){
            temp = (a[aIdx--]-'0') + carry;
            if(temp>=10){
                carry = 1; 
                temp -= 10;
                st.push(temp);;
            }
            else{
                carry = 0;
                st.push(temp);;
            }
            
        }
        else {
            temp = (b[bIdx--]-'0')+ carry;
            if(temp>=10){
                carry = 1; 
                temp -= 10;
                st.push(temp);
            }
            else{
                carry = 0;
                st.push(temp);
            }
        }

    }

    if(carry){
        st.push(carry);
    }

    while(!st.empty()){
        cout << st.top() ;
        st.pop();
    }

    return 0;
}