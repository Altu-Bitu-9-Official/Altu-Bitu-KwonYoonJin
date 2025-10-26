#include <iostream>

using namespace std;

typedef struct pos{
    int row;
    char col;
}pos;

bool checkPos(pos p){
    if(p.row<=8 && p.row>=1 && p.col<='H' && p.col>='A'){
        return true;
    }
    return false;
}

pos moveTo(string str, pos p){
    if(str=="R"){
        p.col++;
    }
    else if(str=="L"){
        p.col--;
    }
    else if(str=="T"){
        p.row++;
    }
    else if(str=="B"){
        p.row--;
    }
    else if(str=="RT"){
        p.col++;
        p.row++;
    }
    else if(str=="LT"){
        p.col--;
        p.row++;
    }
    else if(str=="RB"){
        p.col++;
        p.row--;
    }
    else if(str=="LB"){
        p.col--;
        p.row--;
    }
    return p;
}
void chessGame(string move, pos &king, pos &rock){
    pos temp_king = king ; pos temp_rock = rock;
    temp_king = moveTo(move,temp_king);
    if(temp_king.row ==temp_rock.row && temp_king.col == temp_rock.col){ //king 이동 후 rock과 겹치면 rock도 이동
        temp_rock = moveTo(move,temp_rock);
    }
    if(checkPos(temp_rock)&&checkPos(temp_king)){
        king = temp_king; 
        rock = temp_rock;
    }
}


int main(){
    string kingt, rockt, move;
    pos king, rock;
    int n;
    // 입력
    cin >> kingt >> rockt >> n;
    king.col = kingt[0]; king.row = kingt[1]-'0';
    rock.col = rockt[0]; rock.row = rockt[1]-'0';

    // 연산 
    while(n--){
        cin >> move;
        chessGame(move, king, rock);
    }
    // 출력 (마지막 위치)
    cout << king.col << king.row << "\n" << rock.col << rock.row;

    return 0;
}