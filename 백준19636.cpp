#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int initial_weight, initial_basic_eat, T;
    int diet_days, diet_basic, diet_eat, diet_move;
    int diet_weight1, diet_weight2;
    int diet_diff1, diet_diff2;
    cin >> initial_weight >> initial_basic_eat >> T;
    cin >> diet_days >> diet_eat >> diet_move;

    diet_basic = initial_basic_eat;
    diet_weight1 = initial_weight;
    diet_weight2 = initial_weight;

    for(int i = 0 ; i < diet_days ; i++){
        diet_diff2 = diet_eat - (diet_move + initial_basic_eat);
        diet_weight2 += diet_diff2;

         if(diet_weight2 <=0){
            cout << "Danger Diet" << "\n";
            break;
        }
    }

    if(diet_weight2 > 0){
         cout << diet_weight2 << " " << initial_basic_eat << "\n";   
    }

    for(int i = 0 ; i < diet_days ; i++){
        diet_diff1 = diet_eat - (diet_move + diet_basic);
        diet_weight1 += diet_diff1;
        
        if(abs(diet_diff1)>T){
            diet_basic += floor((double)diet_diff1 / 2); // 실수로 형변환 필수..
        }
        if(diet_basic<=0 || diet_weight1 <=0){
            cout << "Danger Diet" << "\n";
            return 0;
        }
    }
        
    cout << diet_weight1 << " " << diet_basic << " ";
    if(diet_basic < initial_basic_eat){
        cout << "YOYO" << '\n';
    }
    else{
         cout << "NO" << '\n';
    }

    return 0;
}