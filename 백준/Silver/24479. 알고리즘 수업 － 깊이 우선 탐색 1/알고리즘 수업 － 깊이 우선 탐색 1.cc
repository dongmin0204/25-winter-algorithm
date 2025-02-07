#include <bits/stdc++.h>
using namespace std;

int* visited;
int cnt = 1;

void dfs(int x, vector<int>* graph) {
    // 현재 노드 visited 마크하기
    visited[x] = cnt++;

    // 안 들린 곳만 찾아서 재귀적으로 탐색
    for (int i = 0; i < graph[x].size(); i++) {
        int nextNode = graph[x][i];
        if (!(visited[nextNode])) {
            dfs(nextNode, graph);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; // n: 정점의 개수 m: 간선의 개수
    int start; // 탐색 시작 정점
    cin >> n >> m;
    cin >> start;

    vector<int>* graph = new vector<int>[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } //인접테이블 작성

    for(int i = 0; i < n+1; i++){
        sort(graph[i].begin(),graph[i].end());
    }//오름차순 먼저 접근해야함.

    visited = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }

    dfs(start,graph);

    for(int i = 1; i <= n; i++){
        cout << visited[i] << '\n';
    }


    return 0;
}