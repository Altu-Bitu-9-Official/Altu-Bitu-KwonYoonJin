#include <iostream> 
#include <vector>

using namespace std;

void cal_nodes(int node, int parent, vector<vector<int>> &tree, vector<int> &count){
    int cnt = 1;
    for(int child : tree[node]){
        if(child!=parent){
            cnt += cal_nodes(child, node, tree, count);
        }
    }
    count[node] = cnt;
    return cnt;
}


int main(){
    int n, r, q, u, v, node;
    cin >> n >> r >> q;
    vector<vector<int>> tree(n+1,vector<int>(0));
    vector<int> count(n+1,0);
    // 간선 저장
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // 서브트리 노드 수 계산
    cal_nodes(r, 0, graph, count);
    // 출력
    for(int i=0;i<q;i++){
        cin >> node;
        cout << count[node] << '\n';
    }


    return 0;
}