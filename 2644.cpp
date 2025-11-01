#include <iostream>
#include <queue>

using namespace std;

int n;
int ar[101][101]={0,};
bool visited[101]={false,};

// bfs로 탐색하면서 배열에 촌수 저장하쟈!!
int chon_cal(int me, int find){
    int temp, distance=1;
    queue<int> q;
    q.push(me); visited[me]=true; 
    // 촌수 저장 배열
    int chon[n+1]={0,};

    while(!q.empty()){
        temp = q.front(); q.pop();
        for(int i=1;i<=n;i++){
            if(!visited[i]&&ar[temp][i]==1){
                visited[i]=true;
                q.push(i);
                chon[i] = chon[temp]+1;
            }
        }
    }

    if(chon[find]==0) return -1;
    else {
        return chon[find];
    }
}

int main(){
    int a,b,m,x,y,result;
    // 입력
    cin >> n;
    cin >> a >> b;
    cin >> m;
    while(m--){
        cin >> x >> y;
        ar[x][y]=1;
        ar[y][x]=1;
    }
    // 계산
    result = chon_cal(a,b);
    // 출력
    cout << result;
    return 0;
}