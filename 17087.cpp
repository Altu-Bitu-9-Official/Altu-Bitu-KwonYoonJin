#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// 최대공약수(Greatest Common Divisor)를 구하는 함수
int getGcd(int a, int b){
    while(b!=0){
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(){
    int n, s, pos, result;
    cin >> n >> s;
    vector<int> positions;
    while(n--){
        cin >> pos;
        positions.push_back(abs(pos-s)); // 나중에 gcd 구할 때 "위치의 차이" 필요
    }
    result = positions[0];
    for(int i=1; i<positions.size();i++){
        result = getGcd(result,positions[i]);
    }

    cout << result;

    return 0;
}