#include <iostream>
#include <vector>

using namespace std;

void post_order(int left, int right, vector<int> &tree){
    if(left>right) return;

    int root = tree[left];
    int newLeft= left+1;
    for(int i=left+1;i<=right;i++){
        if(tree[i]>root){
            newLeft=i;
            break; // 처음으로 큰 애를 기준으로 오른쪽 서브트리로 분리됨
        }
    }
    post_order(left+1,newLeft-1,tree);
    post_order(newLeft,right,tree);
    cout << root << '\n';
}

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
    ios::sync_with_stdio(false);

    int rootNode, node;
    vector<int> tree;
    while(cin >> node){ // 입력의 수 주어지지 않았을 때 이렇게!!
       tree.push_back(node);
    }
    post_order(0, tree.size()-1, tree);
    return 0;
}