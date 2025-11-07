#include <iostream>
#include <vector>

using namespace std;

bool light_all(int height, int length, vector<int> &lights){
    // 첫 조명 & 왼쪽 벽
    if(lights[0]>height){
        return false;
    }
    // 조명 사이 사이
    for(int i=0;i<lights.size()-1;i++){
        if(lights[i]+2*height<lights[i+1]){ // 조명이 양쪽에서 오니까 조명 커버 범위 x2를 해줘야함!
            return false;
        }
    }
    // 마지막 조명 & 오른쪽 벽
    if(lights[lights.size()-1]+height<length){
        return false;
    }
    return true;
}

int cal_min(int length, vector<int> &lights){
    int left = 1, right = length;
    int mid;
    bool check = false;
    while(left<=right){
        mid = (left+right)/2;
        if(light_all(mid,length,lights)){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return left;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> lights(m);
    for(int i=0;i<m;i++){
        cin >> lights[i]; // 이미 오름차순
    }

    cout << cal_min(n, lights);

    return 0;
}