#include <iostream>

using namespace std;

bool visited[101];
int ar[101][101];
int n;
//dfs
void dfs(int start){
    for(int i=1;i<=n;i++){
        if(!visited[i]&&ar[start][i]==1){
            visited[i]=true;
            dfs(i);
        }
    }
}

int main(){
    int x, y, m, count=0;
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        ar[x][y]=1;
        ar[y][x]=1;
    }
    // 계산
    dfs(1);
    // 출력
    for(int i=2;i<=n;i++){ //바이러스가 시작되는 컴퓨터인 1은 제외하고!
        if(visited[i]) count++;
    }
    cout << count;

    return 0;
}