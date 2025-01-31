#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adject, vector<bool> &visited) {
    visited[node] = true;
    for(auto &neighbor : adject[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adject, visited);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adject(N+1, vector<int>());
    
    // 간선 정보
    for(int i=0; i<M; ++i){
        int u, v;
        cin >> u >> v;
        adject[u].push_back(v);
        adject[v].push_back(u);
    }
    
    vector<bool> visited(N+1, false);
    int cnt = 0;
    
    //bfs 인접행렬 순회
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            dfs(i, adject, visited);
            cnt++;
        }
    }
    
    cout << cnt;
}