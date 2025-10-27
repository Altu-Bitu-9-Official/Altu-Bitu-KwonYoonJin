#include <iostream>
#include <deque>

using namespace std;

void checkBell(deque<int> &dodoDeque,deque<int> &dodoGround,deque<int> &suDeque,deque<int> &suGround){
        // dodo가 종 울리는 경우 검사
        if((!dodoGround.empty()&&dodoGround.back()==5)||(!suGround.empty()&&suGround.back()==5)){
            while(!suGround.empty()){
                dodoDeque.push_front(suGround.front());
                suGround.pop_front();
            }
            while(!dodoGround.empty()){
                dodoDeque.push_front(dodoGround.front());
                dodoGround.pop_front();
            }
        }
        //su가 종 올리는 경우 검사
        else if(!dodoGround.empty()&&!suGround.empty()&&(dodoGround.back()+suGround.back()==5)){ 
            while(!dodoGround.empty()){
                suDeque.push_front(dodoGround.front());
                dodoGround.pop_front();
            }
            while(!suGround.empty()){
                suDeque.push_front(suGround.front());
                suGround.pop_front();
            }
        }
}

bool haliGali(deque<int> &myDeque,deque<int> &myGround,deque<int> &yourDeque,deque<int> &yourGround){
        // empty 상태에서 pop하지 않게 방어
        if(myDeque.empty()||yourDeque.empty()){
            return false;
        }
        // 내가 카드 하나 내고 승리 조건 검사
        myGround.push_back(myDeque.back()) ; myDeque.pop_back();
        if(myDeque.empty()) return false; // 내 덱 비어버리면 종료
        return true;
    
}


int main(){
    bool check=true;
    int n,m;
    int tempA, tempB;
    deque<int> dodoDeque;
    deque<int> dodoGround;
    deque<int> suDeque;
    deque<int> suGround;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tempA >> tempB;
        dodoDeque.push_back(tempA);
        suDeque.push_back(tempB);
    }
    bool turn = true;
    while(m--){
        if(turn){
            if(!haliGali(dodoDeque,dodoGround,suDeque,suGround)) break;;
        }
        else{
            if(!haliGali(suDeque,suGround,dodoDeque,dodoGround)) break;
        } 
        checkBell(dodoDeque,dodoGround,suDeque,suGround);
        turn = !turn;
    }

    if(dodoDeque.size()>suDeque.size()){
        cout << "do";
    }
    else if(dodoDeque.size()==suDeque.size()){
        cout << "dosu";
    }
    else if(dodoDeque.size()<suDeque.size()){
        cout << "su";
    }
    


    return 0;
}