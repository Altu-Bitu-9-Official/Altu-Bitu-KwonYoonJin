#include <iostream>
#include <vector>

using namespace std;

// 오른, 오른 대각선 위, 오른 대각선 아래, 아래
int dx[8] = {1,1,1,0};
int dy[8] = {0,-1,1,1};

int omok(int ar[19][19]){ // 검 1, 흰 2, 빈자리 0
    int winner=0, temp;
    bool check = true;
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(ar[i][j]==0){ //0인 경우는 검사 X
                continue;
            }
            // 승리자 리턴하려고 임시 저장
            winner = ar[i][j];
            // 4방향으로 5개 이어지는지 검사하기
            for(int k=0;k<4;k++){
                check = true;
                if(i+4*dy[k]<19 && i+4*dy[k]>=0 && j+4*dx[k]<19 && j+4*dx[k]>=0){ // 5개 이어도 바둑판 넘지 않는 범위 내에서
                    for(int p=1;p<=4;p++){ // 연속 5개 동일한지 검사
                        if(ar[i][j]!=ar[i+p*dy[k]][j+p*dx[k]]){
                            check = false;
                            break;
                        }
                    }
                    if(!check) continue; // 연속 5개 동일한 경우 아니면 다음 방향 검사하기
                    // 연속 6개가 동일하면 다음 방향 검사하기 1
                    if(i+5*dy[k]<19 && i+5*dy[k]>=0 && j+5*dx[k]<19 && j+5*dx[k]>=0 && ar[i][j]==ar[i+5*dy[k]][j+5*dx[k]]){
                        continue;
                    }
                    // 연속 6개가 동일하면 다음 방향 검사하기 2
                    if(i-dy[k]<19 && i-dy[k]>=0 && j-dx[k]<19 && j-dx[k]>=0 && ar[i][j]==ar[i-dy[k]][j-dx[k]]){ 
                        continue;
                    }
                    // 여기까지 무사히 왔다면 5개 연속한 정상적인 경우인 것
                    cout << winner << '\n' << i+1 << ' '<< j+1 << '\n'; // 0기반 인덱스를 사용했지만 줄 번호는 1부터
                    return 0; // 종료해버리기 위한 리턴
                }
            }
        }
    }
    // 여기까지 리턴하지 않고 와버렸다면 승자가 결정되지 않은 것
    cout << 0;
    return 0;
}

int main(){
    int ar[19][19];
    int result;
    // 입력
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> ar[i][j];
        }
    }
    // 계산 및 출력
    result = omok(ar);
    return 0;
}