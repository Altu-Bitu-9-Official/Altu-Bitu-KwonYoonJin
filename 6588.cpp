#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int const MAX = 1000000;

vector<bool> setPrimeNumber(vector<bool> &prime_number){
    prime_number[0]=false; prime_number[1]=false;
    for(int i=2; i<sqrt(MAX);i++){ // Question1 : i<MAX+1 이렇게 조건 설정 시 시간 초과 나는 이유?
        if(!prime_number[i]){ // 이미 false(소수아님) 상태면 패스
            continue;
        }
        for(int j=i*i;j<MAX+1;j+=i){  
            prime_number[j] = false;
        }
    }
    return prime_number;
}

string dividePrimeNumber(int a, vector<bool> &prime_number){
    string str;
    for(int i=3; i<=a/2; i+=2){ // 홀수만 검사하면 더 효과적!
       if(!prime_number[i]){ // 소수 아니면 패스
        continue;
       }
       else if(prime_number[a-i]){ // bool 배열이므로 prime_number[a-prime_number[i]]는 틀림 ㅠㅠ
           str = to_string(a)+" = "+to_string(i)+" + "+to_string(a-i);
           break;
       }
    }
    if(str.empty()){
      str = "Goldbach's conjecture is wrong.";
    }

    return str;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> prime_number(MAX+1,true);
    vector<string> result;
    setPrimeNumber(prime_number);
    int n;
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        result.push_back(dividePrimeNumber(n,prime_number));
    }
    for(string in: result){
        cout << in << '\n';
    }

    return 0;
}