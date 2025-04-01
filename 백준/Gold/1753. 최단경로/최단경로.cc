#include <bits/stdc++.h>
using namespace std;

const int INF = 999999999; //무한대
int v, e, k; 
vector<pair<int, int>> board[20001]; //인접리스트
int dist[20003]; //거리저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> k;

    // 거리 배열 초기화
    fill(dist, dist + v + 1, INF);

    // 그래프 입력 받기
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        board[u].push_back(make_pair(v,w));
    }

    // 다익스트라 알고리즘
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[k] = 0;
    pq.push(make_pair(0,k)); //bfs처럼 큐에 넣기

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < d) continue; // 이미 처리된거 패스

        for (auto [n, weight] : board[cur]) { //next 노드랑 가중치 
            if (dist[n] > dist[cur] + weight) { //만약에 최소값이 들어온거니까 업데이트
                dist[n] = dist[cur] + weight;
                pq.push(make_pair(dist[n], n));
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
