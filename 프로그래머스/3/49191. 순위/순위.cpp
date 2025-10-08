#include <bits/stdc++.h>
using namespace std;

int bfs(int s, const vector<vector<int>>& graph, int n){
    queue<int> q;
    vector<bool> visited(n,false);
    visited[s] = true;
    q.push(s);
    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if(!visited[v]){
                visited[v] = 1;
                cnt++;
                q.push(v);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> g(n);
    vector<vector<int>> rg(n); //지는 방향의 그래프
    for (auto &e : results) {
        int a = e[0]-1;
        int b = e[1]-1;
        g[a].push_back(b);   // a가 b 이김
        rg[b].push_back(a);  // b 입장에서 지는 쪽으로 반대로 생각
    }
    
    for (int i = 0; i < n; i++) {
        int wins = bfs(i, g, n); //이기는 거 bfs실행
        int losses = bfs(i, rg, n);//질때도 마찬가지로 bfs로 도달해야함
        if (wins + losses == n - 1) answer++;
    }
    return answer;
}