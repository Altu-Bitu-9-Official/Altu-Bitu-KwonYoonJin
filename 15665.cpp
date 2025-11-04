#include <iostream>
#include <vector>

#include <set>

using namespace std;

void make_sequence(int idx, int m, set<int> &nums, vector<int> &sequence){
    if(idx == m){
        for(int i=0;i<m;i++){
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }
    //set<int>::iterator iter;
    for(auto iter: nums){
        sequence[idx]=iter;
        make_sequence(idx+1,m,nums,sequence);
    }
}

int main(){
    int n,m, temp;
    cin >> n >> m;
    set<int> nums; // set은 자동 정렬이라 sort사용할 필요 없고 중복 제거됨!
    vector<int> sequence(m);

    for(int i=0;i<n;i++){
        cin >> temp;
        nums.insert(temp);
    }

    make_sequence(0, m, nums, sequence);

    return 0;
}