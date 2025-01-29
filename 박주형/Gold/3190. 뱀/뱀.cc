#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int ny = 0, nx = 0;
    int N, K;
    cin >> N >> K;
    int arr[101][101];
    memset(arr, 0, sizeof(arr));
    
    for(int i = 0; i < K; i++) {
        int ay, ax;
        cin >> ay >> ax;
        arr[ay-1][ax-1] = 1;
    }
    
    int L;
    cin >> L;
    queue<pair<int, string>> q;
    
    for(int i = 0; i < L; i++) {
        int X;
        string C;
        cin >> X >> C;
        q.push({X, C});
    }
    
    int i = 0;
    int T = 0;
    queue<pair<int, int>> snake;
    snake.push({0, 0});
    arr[0][0] = 2;
    
    while(true) {
        T++;
        //cout << snake.size() << '\n';
        ny = ny + dy[i];
        nx = nx + dx[i];
        // cout << ny << " " << nx << '\n';
        if(ny < 0 || ny >= N || nx < 0 || nx >= N || arr[ny][nx] == 2) {
            // cout << ny << " " << nx << '\n';
            cout << T;
            break;
        }
        int b = (arr[ny][nx] == 1) ? 0 : 1;
        arr[ny][nx] = 2;
        snake.push({ny, nx});
        
        if(b) {
            // cout << arr[snake.front().first][snake.front().second] << '\n';
            arr[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        
        if(!q.empty() && q.front().first == T) {
            if(q.front().second == "L") {
                if(i == 0) {
                    i = 3;
                } else {
                    i--;
                }
            } else if(q.front().second == "D") {
                if(i == 3) {
                    i = 0;
                } else {
                    i++;
                }
            }
            q.pop();
        }
    }
    
    return 0;
}