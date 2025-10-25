#include <iostream>
#include <vector>

using namespace std;


long check_velocity(vector<long> arr){
    long v=0,temp;
    for(int i=arr.size()-1; i>=0;i--){
        temp = arr[i];
        if(temp>v){
            v = temp;
        }
        else{
            // 시간초과 로직
            //while(temp<v){
               // temp+=x;
            //}
            // 시간초과 안 나게 한 번에: 우리가 원하는 건 temp의 배수 중 v보다 큰 애
            // -1을 해줘야 temp+v가 temp로 나누어 떨어질 때의 계산이 정확해짐
            v = ((temp+v-1)/temp)*temp;
        }
    }

    return v;
}

int main(){
    int n;
    long result;
    cin >> n;
    vector<long> arr(n);
    // 입력
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    // 계산
    result = check_velocity(arr);
    // 출력
    cout << result;
    return 0;
}