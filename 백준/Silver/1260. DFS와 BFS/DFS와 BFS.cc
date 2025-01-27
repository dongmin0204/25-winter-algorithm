#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int visited_dfs[1001];
int visited_bfs[1001];

void dfs(int u) {
    visited_dfs[u] = 1;
    cout << u << " ";
    for(int i : adj[u]) {
        if(visited_dfs[i] == 0) {
            dfs(i);
        }
    }
    return;
}

void bfs(int here) {
    queue<int> q;
    q.push(here);
    visited_bfs[here] = 1;
    cout << here << " ";
    while(q.size()) {
        int temp = q.front();
        q.pop();
        for(int i : adj[temp]) {
            if(visited_bfs[i]) continue;
            visited_bfs[i] = visited_bfs[here] + 1;
            cout << i << " ";
            q.push(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, V;
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(V);
    cout << '\n';
    bfs(V);

    return 0;
}