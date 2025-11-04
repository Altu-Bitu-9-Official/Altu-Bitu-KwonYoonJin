#include <iostream>
#include <vector>

using namespace std;


int calculate_area(int k, vector<pair<int,int>> &posAndLen){
    // 넓이 계산: 큰 직사각형에서 작은 직사각형을 뺄 것
    int maxRow=0, maxCol=0;
    int minRow=0, minCol=0;
    for(int i=0;i<posAndLen.size();i++){
        if(posAndLen[i].first==1 || posAndLen[i].first==2){ //가로 길이
            maxRow = max(maxRow, posAndLen[i].second); // 큰 직사각형 가로 길이는 그냥 제일 긴 가로 길이
        }
        else{ //세로 길이
            maxCol = max(maxCol, posAndLen[i].second);  // 큰 직사각형 세로 길이는 그냥 제일 긴 세로 길이
        }
    }
     for(int i=0;i<posAndLen.size();i++){
        if(posAndLen[i].first==1 || posAndLen[i].first==2){ //가로 길이
            if(posAndLen[(i-1+6)%6].second+posAndLen[(i+1+6)%6].second==maxCol){ // 나에게 이어진 두 변의 방향이 반대라면 작은 직사각형의 변
                minRow = posAndLen[i].second;
            }
        }
        else{ //세로 길이
            if(posAndLen[(i-1+6)%6].second+posAndLen[(i+1+6)%6].second==maxRow){ // 나에게 이어진 두 변의 방향이 반대라면 작은 직사각형의 변
                minCol = posAndLen[i].second;
            }
        }
    }

    return (maxCol*maxRow-minCol*minRow);
}

int main(){
    int k, pos, len, area;
    cin >> k;
    vector<pair<int,int>> posAndLen(6); // push_back 할 거 아니라면 사이즈 정의 필수 (런타임에러)
    for(int i=0;i<6;i++){
        cin >> pos >> len;
        posAndLen[i].first=pos; // pos는 1234가 각각 동서남북
        posAndLen[i].second=len;
    }

    area = calculate_area(k, posAndLen);
    cout << k*area;



    return 0;
}