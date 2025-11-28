#include <iostream>
#include <vector>

using namespace std;

int dx[4]={1,0,-1,0}; // 오 위 왼 아래
int dy[4]={0,-1,0,1}; // 오 위 왼 아래
int map[101][101];
void make_dragon_curve(int x, int y, int g, vector<int> &direction){
    while(g--){ //g세대 동안 (g가 0이면 바로 종료)
        int end = direction.size()-1;
        // 마지막 방향-> 처음 방향 순서로 시계방향 90도 해서 디렉션에 저장
        for(int i=end;i>=0;i--){
            //1. 방향 시계방향 90도로 변경
            int tmp = (direction[i]+1)%4;
            //2. 변경한 방향으로 줄 긋기
            x+=dx[tmp]; y+=dy[tmp];
            map[x][y]=1;
            //3. 변경한 방향 저장
            direction.push_back(tmp);
        }
    }
}


int main(){
    int count=0;
    int n, x, y, d, g;
    cin >> n;
    vector<int> direction;
    while(n--){
        direction.clear();
        cin >> x >> y >> d >> g;
        map[x][y]=1;
        // 최소 0세대
        x+=dx[d]; y+=dy[d];
        map[x][y]=1;
        direction.push_back(d);
        // g세대 더 하기
        make_dragon_curve(x, y, g, direction);
    }

    // 맵에 찍어놓은 점 바탕으로 개수 세기?
    for(int x=0;x<100;x++){
        for(int y=0;y<100;y++){
            if(map[x][y]&&map[x][y+1]&&map[x+1][y]&&map[x+1][y+1]){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}