#include <iostream>
#include <vector>

using namespace std;

int getLuckWheel(vector<string> &wheel, int pointer, int n, string str){
    
        // 시계 방향으로 돌린다는 건 인덱스는 거꾸로 -> -
        // <<틀렸습니다 뜨던 원인>>
        // 포인터를 설정하는 경우에서 저의 경우 문제의 의도와 다르게 반대 방향으로
        // 바퀴를 저장하고 출력했는데, 이 과정에서 유도된 식 pointer-n+wheel.size()에서
        // n이 wheel 크기보다 큰 경우 음수의 나머지 연산으로 바로 틀렸습니다가 뜨는 상황이 있었음
        // -> 음수인 경우가 생기지 않게 미리 나머지 연산으로 숫자를 줄여서 오류 해결하였음
        if(n>wheel.size()){
            n %= wheel.size();
        }
        //0. 포인터 설정
        pointer = (pointer-n+wheel.size()) % wheel.size();
        //1. 이미 알파벳 차있는 경우 !로 종료
        if(wheel[pointer]!="?" && wheel[pointer]!=str){ // <중요> 나랑 다른 알파벳인지 확인 필수!!!
            return -1;
        }
        // 2. 비어있는 경우 다른 칸에 동일한 알파벳이 있지는 않은지 검사
        for(int i=0;i<wheel.size();i++){ // <중요> (i==pointer)인 경우는 동일해도 괜찮음!!
           if(wheel[i]==str&&i!=pointer){ // 만약 동일한 알파벳 있으면 !로 종료
            return -1;
           }
        }
        // 무사히 종료하지 않고 여기까지 왔으면 바퀴에 값 입력
        wheel[pointer]=str;
        return pointer;
    

}

int main(){
    int size, k,n;
    string str;
    string result;
    int pointer=0;
    cin >> size >> k;
    vector<string> wheel(size,"?");
    while(k--){
        cin >> n >> str;
        pointer = getLuckWheel(wheel, pointer, n, str);
        if(pointer == -1){ // 행운의 바퀴 없다고 뜨면 바로 프로그램 종료
            cout << "!";
            return 0;
        }
    }
    
    // 현재 위치부터 인덱스 증가 순(시계 방향)으로 바퀴 요소 출력
    int start = pointer;
    do{
        result += wheel[start]; 
        start = (start+1)%wheel.size();
    }while(start!=pointer);

    cout << result;
    return 0;
}