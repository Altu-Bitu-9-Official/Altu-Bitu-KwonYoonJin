#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dr[4] = {-1,0,1,0}; //위 오른 아래 왼
int dc[4]={0,1,0,-1}; // 위 오른 아래 왼

int game(int n, vector<vector<int>> &ar, vector<char> &change){
    //vector<vector<int>> direction(n+1, vector<int>(n+1,0)); 백터(배열)로 방향을 기록해놓는 것은 불확실...
    int time=0, now=1; // now에 위-오른-아래-위를 0123으로 표현
    int headRow=1, headCol=1;
    int tailRow=1, tailCol=1;
    deque<int> direction; //direction.push_back(now); 
    while(true){
        // 방향 전환
        if(change[time]=='L'){ //방향 왼쪽으로 90도
            now = (now-1+4)%4;
        }
        else if(change[time]=='D'){ //방향 오른쪽으로 90도
            now = (now+1)%4;
        }
        direction.push_back(now);
        time++;
        int nextRow = headRow+dr[now];
        int nextCol = headCol+dc[now];
        // 1. 머리 이동 & 충돌 고려
        if(nextRow<1 || nextRow> n|| nextCol<1 || nextCol>n) break; // 벽이면 종료
        if(ar[nextRow][nextCol]==1) break; // 뱀이면 종료
        if(ar[nextRow][nextCol]!=2){ // 사과가 아닌 경우에만 꼬리 움직이기
            ar[tailRow][tailCol]=0; // 꼬리 옮김
            // 꼬리 위치 이동 반영
            tailRow += dr[direction.front()];
            tailCol += dc[direction.front()];
            direction.pop_front();
        }
        ar[nextRow][nextCol]=1; // 머리 움직이기
        headRow=nextRow; headCol=nextCol; // 머리 위치 이동 반영
    }
    return time;
}

int main(){
    int n, k, l, row, col, time;
    char direction;
    cin >> n;
    vector<vector<int>> ar(n+1, vector<int>(n+1));
    ar[1][1]=1; // 초기 뱀 위치
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> row >> col;
        ar[row][col]=2; // 0은 빈 칸, 1은 뱀, 2는 사과
    }
    cin >> l;
    vector<char> change(10001);
    for(int i=0;i<l;i++){
        cin >> time >> direction;
        change[time]=direction;
    }

    cout << game(n, ar, change);

    return 0;
}