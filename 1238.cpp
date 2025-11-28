#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ci;

const int INF=101;

int dijikstra_one(int start, int x, vector<vector<ci>> &v){
    vector<int> distance(v.size()+1,INF);
    priority_queue<ci, vector<ci>, greater<>> pq;
    distance[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        int cost = pq.top().first;
        int to = pq.top().second;
        pq.pop();
        if(cost>distance[to]){
            continue;
        }
        for(int i=0;i<v[to].size();i++){
            int nextNode = v[to][i].first;
            int nextCost = v[to][i].second;
            if(distance[nextNode]>cost+nextCost){
                distance[nextNode]=cost+nextCost;
            }
        }
    }

    return distance[x];
}

void dijikstra(int x, vector<vector<ci>> &v, vector<int> &distance){
    priority_queue<ci, vector<ci>, greater<>> pq;
    distance[x]=0;
    pq.push({0,x});

    while(!pq.empty()){
        int cost = pq.top().first;
        int to = pq.top().second;
        pq.pop();
        if(cost>distance[to]){
            continue;
        }
        for(int i=0;i<v[to].size();i++){
            int nextNode = v[to][i].first;
            int nextCost = v[to][i].second;
            if(distance[nextNode]>cost+nextCost){
                distance[nextNode]=cost+nextCost;
            }
        }
    }
}

int main(){
    int n, m, x, a, b, t;
    int max=0;
    cin >> n >> m >> x;
    vector<vector<ci>> v(n+1);
    vector<int> distance_go(n+1,INF); //가는 거리 저장
    vector<int> distance_come(n+1,INF); //오는 거리 저장
    for(int i=0;i<m;i++){
        cin >> a >> b >> t;
        v[a].push_back({b,t});
    }
    for(int i=1;i<=n;i++){
        distance_go[i]= dijikstra_one(i, x, v);
    }
    dijikstra(x, v, distance_come);

    for(int i=1;i<=n;i++){
        if(distance_go[i]+distance_come[i]>max){
            max = distance_go[i]+distance_come[i];
        }
    }
    cout << max;
    return 0;
}