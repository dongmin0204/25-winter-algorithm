#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    
    vector<vector<int>> adject(N+1, vector<int>());
    
    // 간선 정보
    for(int i=0; i<M; ++i){
        int u, v;
        cin >> u >> v;
        adject[u].push_back(v);
        adject[v].push_back(u);
    }
    
    vector<bool> visited(N+1, false);
    queue<pair<int, int>> q; // 노드, 높이
    
    // 1을 큐 삽입 후 방문
    q.push(make_pair(1, 0));
    visited[1] = true;
    
    while(!q.empty()){
        int current = q.front().first;
        int height = q.front().second; 
        q.pop();
        
        //사이가 2 이상이면 skip
        if(height >= 2) continue;
        
        for(auto &neighbor : adject[current]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                cnt++;
                q.push(make_pair(neighbor, height + 1));
            }
        }
    }
    cout << cnt << '\n';
}