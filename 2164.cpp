#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    int last = n;
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    // 비어있는 큐에서 pop해서 런타임에러(segfault)나지 않도록 주의
    while(1){
        if(q.size()!=1){ // !q.empty()로 조건 설정 시 다음 if문에서 비어있는 큐에서 pop하는 경우 발생
            q.pop();
        }
        if(q.size()==1){ // 이미 큐에 한 개의 원소만 남았다면 반복할 필요 x, last에 마지막 원소 저장
          last = q.front(); 
          break;
        }
        last = q.front(); q.pop();
        q.push(last);
    }
    cout << last;

    return 0;
    
}