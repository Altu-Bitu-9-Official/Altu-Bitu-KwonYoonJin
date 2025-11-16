#include <iostream>
#include <vector>

using namespace std;

int max_length(int k, vector<int> &ar){
    int first=0, second=1;
    int length=0;
    // 수의 개수를 저장해놓는 배열
    vector<int> count(200001);

    count[ar[first]]++;
    while(second!=ar.size()){ // second가 끝에 다다를 때까지
        count[ar[second]]++; // 일단 윈도우의 오른쪽을 오른쪽으로 이동
        if(count[ar[second]]>k){  // 근데 중복되는 수가 k개 넘어버리면
            if(length<second-first){ // 멈추고 현재 상태의 길이 계산 (first인덱스부터 second-1 인덱스까지)
                length = second-first;
            }
            while(count[ar[second]]>k){ // 중복되는 수 k개 될 때까지 윈도우의 왼쪽을 오른쪽으로 이동
                count[ar[first]]--;
                first++;
            }
        }
        second++; // 다음에 윈도우의 오른쪽을 오른쪽으로 이동하기 위해 second 증가 
    }
    if(length<second-first){
        length = second-first;
    }
    return length;
}

int main(){
    int n,k, max;
    cin >> n >> k; // 같은 정수 k개 이하
    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    max = max_length(k,ar);
    cout << max;
    return 0;
}