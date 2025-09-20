#include <iostream>
#include <vector>
#include <algorithm> //for sort함수
using namespace std;

bool cmp(const string& a, const string& b){
    int sumA=0; int sumB=0;
    
    for(int i=0; i<a.length();i++){
        if(a[i]<='9'){
            sumA += a[i]-'0';
        }
    }
    for(int i =0; i<b.length();i++){
        if(b[i]<='9'){
            sumB += b[i]-'0';
        }
    }

    if(a.length()!=b.length()){
        return a.length()<b.length();
    }
    else if(sumA != sumB){
        return sumA<sumB;
    }
    else{
       return a<b; // 사전순 비교 부등호로 가능 (인덱스로 하나씩 비교할 필요 x)
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> guitars(n);
    string temp;
    for(int i = 0 ; i< n ; i++){
        cin >> temp;
        guitars[i]=(temp);
    }

    sort(guitars.begin(),guitars.end(),cmp);

    for(int i = 0 ; i< n ; i++){
        cout << guitars[i] << '\n';
    }

    return 0;
}