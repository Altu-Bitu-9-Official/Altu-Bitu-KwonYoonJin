#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check_increse(vector<int> ar, int n){
    int len = 0;
    vector<int> dp;
    for(int i=0;i<ar.size();i++){
        
    }


    return len;
}
int main(){
    int n, len=0;
    cin >> n;
    vector<int> ar(n);
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        cin >> ar[i];
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(ar[j]<ar[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    sort(dp.begin(),dp.end());
    cout << dp[dp.size()-1];
    return 0;
}