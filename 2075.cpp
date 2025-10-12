#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp; 
    // 처음엔 n번째로 큰 수니까 큰 수들만 저장하겠다는 생각으로
    // max heap을 사용했는데 이러면 작은 숫자들을 큐에서 빼낼 수가 없는 문제
    // -> min heap을 사용해서 작은 숫자들 주기적으로 빼기 (쓸모 x)
    priority_queue<int, vector<int>,greater<int>> pq;
    cin >> n;
    for(int i=0;i<n*n;i++){
        cin >> temp;
        pq.push(temp);
        if(pq.size()>n){ // 메모리 초과 -> 다 저장하지 말고 큐 크기 5로 유지하자
            pq.pop(); // 가장 작은 원소 빼기
        }
    }

    cout << pq.top();

    return 0;
}