#include <iostream>
#include <vector>

using namespace std;

int minMax[] = {1000000000,-1000000000};

void calculate(int idx, int end,vector<int> &nums, vector<int> &operators, vector<int> sequence){
    if(idx==end){
        int answer=nums[0];
        for(int i=0;i<end;i++){
            switch(sequence[i]){
                case 0:
                    answer += nums[i+1];
                    break;
                case 1:
                    answer -= nums[i+1];
                    break;
                case 2:
                    answer *= nums[i+1];
                    break;
                case 3:
                    if((answer>0&&nums[i+1]>0) || (answer<0&&nums[i+1]<0)){
                        answer /= nums[i+1];
                    }
                    else {
                        answer = (abs(answer)/abs(nums[i+1]))*-1;
                    }
                    
                    break;
            } 
        }
        minMax[0]=min(minMax[0],answer);
        minMax[1]=max(minMax[1],answer);
        return;
    }

    for(int i=0;i<4;i++){
        if(operators[i]>0){
            sequence[idx]=i; // 연산자 정함
            operators[i]--; // 연산자 사용 표시 (방문 처리)
            calculate(idx+1, end, nums, operators, sequence);
            operators[i]++; // 재귀함수 끝나고 돌아오면 방문 처리 원상태로 복구해주기
        }
    }

}


int main(){
    int n, temp;
    cin >> n;
    vector<int> sequence(n-1);
    vector<int> nums(n);
    vector<int> operators(4); // 각각 +,-,x,/ 개수
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<4;i++){
        cin >> operators[i];
    }

    calculate(0, n-1, nums, operators, sequence);

    cout << minMax[1] << '\n';
    cout << minMax[0] << '\n';

    return 0;
}