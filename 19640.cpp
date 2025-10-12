#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Employee{
    int i;
    int d;
    int h;
    int m;
};

struct cmp{ //우선순위 설정 위해 cmp 구조체 안에 operator 구현
    bool operator()(const Employee &parent, const Employee &child){
        if(child.d!=parent.d){ // 근무일수 다르면 큰 사람 먼저
            return parent.d<child.d;
        }
        if(child.h!=parent.h){ // 근무일수 같, 급한 정도 다름
            return parent.h<child.h;
        }
        if(parent.m!=child.m){// 줄 번호 낮은 순
            return parent.m>child.m; 
        }
        return parent.i>child.i;
        
    }
};

int simul(vector<queue<Employee>> &lines, priority_queue<Employee, vector<Employee>,cmp> &pq, int k){
    Employee e;
    int count = 0;
    for(int i=0;i<lines.size();i++){
        if(!lines[i].empty()){ // pop 할 때 꼭 empty 확인
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }
    while(true){
        if(!pq.empty()){
            e = pq.top();
            if(e.i==k){
                break;
            }
            count++;
            pq.pop();
            if(!lines[e.m].empty()){ // pop 할 때 꼭 empty 확인
                pq.push(lines[e.m].front());
                lines[e.m].pop();
            }
            
        }
    }

    return count;
}


int main(){
    // 주의할 점: 괜히 1-based index를 쓰지 말자..
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,d,h;
    int count;
    priority_queue<Employee, vector<Employee>,cmp> pq;
    //입력
    cin >> n >> m >> k;
    vector<queue<Employee>> lines(m);
    //연산
    for(int i=0;i<n;i++){ // 모두 m개로 나눠서 선 줄에 넣음
        Employee e;
        cin >> d >> h;
        e.i=i; e.d=d; e.h=h;
        e.m = i%m; // 몇번째 줄로 갈지 계산: 나머지 연산
        lines[e.m].push(e);
    }
    count = simul(lines, pq, k);
    //출력
   
    cout << count;
    return 0;
}