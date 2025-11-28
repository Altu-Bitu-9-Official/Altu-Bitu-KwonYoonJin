#include <iostream>
#include <vector>

using namespace std;


void floyd_warshall(int n, vector<vector<char>> &v){
    for(int i=1;i<=n;i++){//중간노드
        for(int j=1;j<=n;j++){//시작
            for(int k=1;k<=n;k++){//끝
                if(v[j][i]==v[i][k]&&v[j][i]=='<'){ 
                    v[j][k]='<'; // 대소비교 알게 됨
                }
                else if(v[j][i]==v[i][k]&&v[j][i]=='>'){ 
                    v[j][k]='>'; // 대소비교 알게 됨
                }
            }
        }
    }
}

int main(){
    int n, m, a, b;
    int count=0;
    bool check;
    cin >> n >> m;
    vector<vector<char>> v(n+1,vector<char>(n+1,'X'));
    for(int i=1;i<=n;i++){
        v[i][i]='=';
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a][b]='<';
        v[b][a]='>';
    }
    floyd_warshall(n, v);

    for(int i=1;i<=n;i++){
        check=true;
        for(int j=1;j<=n;j++){
            if(v[i][j]=='X'){
                check=false;
                break;
            }
        }
        if(check) count++;
    }
    cout << count;
    return 0;
}