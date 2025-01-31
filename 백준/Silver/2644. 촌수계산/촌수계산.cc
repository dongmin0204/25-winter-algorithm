#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    int start = -1;
    int endP = -1; //출발 -> 도착 거리(촌 수)

    cin >> n;
    cin >> start >> endP;
    cin >> m;

    vector<vector<int>> families(n + 1);

    // 인접 행렬 입력받기
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        families[u].push_back(v);
        families[v].push_back(u);
    }

    queue<int> q; //다음 노드 자료구조
    vector<int> dist(n+1,-1); //bfs를 위한 큐와 배열 준비
    dist[start] = 0;  // 시작 노드는 거리 0
    q.push(start);

    while(!q.empty()){ //dfs로 할라다가 최단 거리 구하는 거라 익숙한 bfs로 ~(직관적임)
        int current = q.front(); q.pop();

        if(current == endP) break; //이미 도착 -> 최단거리 보장 바로 끝

        for(int next : families[current]){
            if(dist[next] < 0){ // 방문하지 않은 노드임
                dist[next] = dist[current]+1;//다음 노드 촌수 업데이트
                q.push(next); //다음 행선 후보니까 q로 간다
            }
        }
    }
        // dist[endP] 출력, 만약 -1이면 연결된 경로가 없음을 의미
        cout << dist[endP] << '\n';
}
