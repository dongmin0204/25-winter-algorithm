#include <bits/stdc++.h>
using namespace std;
int arr[102][102];
int visited[102][102];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x, int N, int M) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;
            if(arr[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            if(ny == N-1 && nx == M-1) {
                cout << visited[ny][nx];
                return;
            }
            q.push({ny, nx});
        }
        
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    bfs(0, 0, N, M);
    
    
    
    return 0;
}