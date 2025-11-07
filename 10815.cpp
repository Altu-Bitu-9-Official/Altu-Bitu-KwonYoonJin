#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binary_search(int target, vector<int> &cards){
    int left = 0, right = cards.size()-1;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(cards[mid]==target){
            return 1;
        }
        else if(cards[mid]<target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return 0;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, target;
    cin >> n;
    vector<int> cards(n);
    for(int i=0;i<n;i++){
        cin >> cards[i];
    }
    cin >> m;

    // 이분탐색을 위해서는 정렬 필수
    sort(cards.begin(), cards.end()); 
    
    while(m--){
        cin >> target;
        cout << binary_search(target,cards) << ' ';
    }

    

    return 0;
}