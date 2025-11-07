#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible(int length, int people, vector<int> &crackers){
    int count = 0;
    for(int cracker:crackers){
       count+= cracker/length;
    }
    if(count>=people){
        return true;
    }
    return false;
}

int max_length(int people, vector<int> &crackers){
    int left=1, right= crackers[crackers.size()-1]; // 과자의 최소 길이는 1, 최대 길이는 현재 과자 중 제일 긴 거
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(is_possible(mid, people, crackers)){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    if(right<1) return 0;
    return right;
}

int main(){

    int m, n;
    cin >> m >> n;
    vector<int> crackers(n);
    for(int i=0;i<n;i++){
        cin >> crackers[i]; // 이미 오름차순
    }
    sort(crackers.begin(),crackers.end());
    cout << max_length(m, crackers);

    return 0;
}