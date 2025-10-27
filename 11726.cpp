#include <iostream>
#include <vector>

using namespace std;

int make_full(int n){
    vector<long> makeFull(n+1,0);
    makeFull[1]=1;
    makeFull[2]=2;
    for(int i=3;i<=n;i++){
        makeFull[i]=(makeFull[i-1]+makeFull[i-2])%10007;
    }
    return makeFull[n];
}   

int main(){
    int n, result;
    cin >> n;

    result = make_full(n);

    cout << result;

    return 0;
}