#include <iostream>
#include <vector>
#include <set>

using namespace std;

int cal_max_type(int d, int k,int c, vector<int> &dishes){
    vector<int> count(d+1, 0); // 초밥 "번호"는 1부터
    int maxKind=1;
    int kind=0;
    // 시작점 
    for(int i=0;i<k;i++){
        if(count[dishes[i]]==0){
            // 처음 발견된 초밥(중복 X)
            kind++; // 종류 추가
        }
        count[dishes[i]]++; // 이제 이 초밥 윈도우에 있음 (1개)
    }
    if(count[c]==0){ // 쿠폰 초밥이 겹치지 않으면 +1
        maxKind = kind+1;
    }
    else{ // 쿠폰 초밥 이미 있으면 종류 추가 X
        maxKind = kind;
    }

    // 슬라이딩 윈도우 이동
    for(int i=1;i<dishes.size();i++){
        int nowKind;
        count[dishes[i-1]]--; // 기존 젤 왼쪽 초밥 나가고
        if(count[dishes[i-1]]==0){ // 초밥 나가서 종류 아예 없어졌으면 종류 감소
            kind--;
        }

        int right = (i+k-1)%dishes.size(); // 연결된 형태라 인덱스 넘어가도 이어지게 계산!
        count[dishes[right]]++; // 오른쪽 초밥 하나 추가
        if(count[dishes[right]]==1){ // 초밥이 새 종류면 
            kind++; // 종류 증가
        }

        // 쿠폰 적용
        if(count[c]==0){
            nowKind = kind + 1;
        }
        else{
            nowKind = kind;
        }

        // 현재 윈도우 종류 수가 최대 종류 수보다 크면 갱신
        if(nowKind>=maxKind){
            maxKind=nowKind;
        }
    }
    
    return maxKind;
}

int main(){

    int n,d,k,c, max;
    cin >> n >> d >> k >> c;
    vector<int> dishes(n);
    for(int i=0;i<n;i++){
        cin >> dishes[i];
    }

    max = cal_max_type(d,k,c,dishes);

    cout << max;

    return 0;
}