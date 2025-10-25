#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void spin(vector<deque<int>> &cogwheels, vector<int> spinDirection){
    for(int i=0;i<spinDirection.size();i++){
        if(spinDirection[i]==1){ // 시계 방향
            cogwheels[i].push_front(cogwheels[i].back());
            cogwheels[i].pop_back();
        }
        if(spinDirection[i]==-1){ // 반시계 방향
            cogwheels[i].push_back(cogwheels[i].front());
            cogwheels[i].pop_front();
        }
    }
}

void simul(vector<deque<int>> &cogwheels, int num, int direction){
    int leftCheck = num, rightCheck = num;
    int leftDirect = direction, rightDirect = direction;
    // 왼쪽 톱니바퀴들 회전 저장
    vector<int> spinDirection(cogwheels.size(),0); 
    while(leftCheck-1>=0 &&cogwheels[leftCheck-1][2]!=cogwheels[leftCheck][6]){
            leftDirect*=-1;
            spinDirection[leftCheck-1]=leftDirect;
            leftCheck--;
    }
    // 오른쪽 톱니바퀴들 회전 저장
    while(rightCheck+1<cogwheels.size() &&cogwheels[rightCheck][2]!=cogwheels[rightCheck+1][6]){
            rightDirect*=-1;
            spinDirection[rightCheck+1]=rightDirect;
            rightCheck++;
    }
    // 내 톱니바퀴 회전 저장
    spinDirection[num]=direction;
    // 한 번에 회전
    spin(cogwheels, spinDirection);
}

int main(){
    int t, k, num, direction, count=0;
    string str;
    cin >> t;
    vector<deque<int>> cogwheels(t);
    // 입력
    for(int i=0;i<t;i++){
        cin >> str;
        for(char c : str){
            cogwheels[i].push_back(c-'0');
        }
    }
    
    cin >> k;
    // 연산
    for(int i=0;i<k;i++){
       cin >> num >> direction;
       simul(cogwheels,num-1,direction);
    }
    for(int i=0;i<t;i++){
        if(cogwheels[i][0]==1){
            count++;
        }
    }
    // 출력
    cout << count;
    return 0;
}