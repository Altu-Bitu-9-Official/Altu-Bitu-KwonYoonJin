#include <iostream>

using namespace std;


int getYear(int e, int s, int m){
    int year=1;
    while(true){
        // 나머지는 0부터 시작하는데 범위를 넘어서면 1로 갱신된다는 점이 좀 어려웠음
        if(e==15) e=0;
        if(s==28) s=0;
        if(m==19) m=0;
        if(year%15==e && year%28==s && year%19==m){ 
            break;
        }
        year++;
    }

    return year;
}

int main(){
    //입력
    int e,s,m,year; // 1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19
    cin >> e>> s>> m;
    //연산
    year = getYear(e,s,m);
    //출력
    cout << year;
    return 0;
}