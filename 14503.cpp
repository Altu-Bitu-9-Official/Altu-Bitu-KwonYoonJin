#include <iostream>
#include <vector>

using namespace std;

int n,m;
int dr[4] = {-1,0,1,0}; //북동남서
int dc[4] = {0,1,0,-1}; //북동남서

bool can_go_back(int r, int c, int d, vector<vector<int>> &room){
    int back = (d+2)%4; //반대방향
    int newR = r + dr[back];
    int newC = c + dc[back];

    if(newR<0||newR>=n||newC<0||newC>=m){ // 인덱스 범위 넘음
        return false;
    }
    if(room[newR][newC]==1){ // 벽
        return false;
    }
    return true;
}

int room_clean(int r, int c, int d, vector<vector<int>> &room){
    int nowR=r, nowC=c, count=1;
    room[nowR][nowC]=2;
    int nowLook = d;
    bool cleaned;
    while(true){
        cleaned = false;

        for(int i=0;i<4;i++){ //주변 4칸 중 청소되지 않은 빈칸 찾아보기
            nowLook = (nowLook+1)%4;
            int nr = nowR+dr[nowLook];
            int nc = nowC+dc[nowLook];
            if(nr>=0 && nr<n && nc>=0 && nc<m && room[nr][nc]==0){ // 범위 안이고 청소되지 않은 빈칸이면
                nowR=nr; nowC=nc;
                room[nowR][nowC]=2; count++;
                cleaned = true; // cleaned로 청소 표시
                break;
            }
        }   

        if(!cleaned){ // 4방향에 청소 가능한 거 없었음
            if(!can_go_back){ //후진 불가능하면 종료
                break;
            }
            // 후진은 가능하면 후진하기
            int back = (nowLook+2)%4;
            nowR+=dr[back]; nowC+=dc[back];
        }

        
    }

    return count;
}

int main(){
    int r,c,d,temp,clean;
    cin >> n >> m;
    cin >> r >> c >> d;
    // 이차원 백터사용.. 배열 사용하니 크기 처리 넘 어려움
    vector<vector<int>> room(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> room[i][j];
        }
    }

    clean = room_clean(r,c,d,room);
    cout << clean;

    return 0;
}