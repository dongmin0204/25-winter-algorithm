#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;



int board[9][9];
bool visited_virus[9][9] = {false};

int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1}  }; // 상하좌우

int bfs(queue<pair<int,int>>& q_virus,int n ,int m){

    int temp = 0;
    while(!q_virus.empty()){
            auto cur = q_virus.front(); q_virus.pop();
            

            for(int d = 0; d < 4; d++){
                int nx = cur.X + direction[d][0];
                int ny = cur.Y + direction[d][1];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == 1 || visited_virus[nx][ny]) continue; //벽에 막히거나 or 이미 들렸거나

                visited_virus[nx][ny] = true;
                q_virus.push(make_pair(nx, ny));
            }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited_virus[i][j]) temp++;
        }
    }
    
    return temp;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ,m;
    cin >> n >> m;
    queue<pair<int,int>> q_virus;
    vector<pair<int,int>> wall_case; //벽 세울 수 있는 곳 저장
    vector<pair<int,int>> virus_init;
    int room  = 0;; //빈 방 개수

    memset(visited_virus, false, sizeof(visited_virus));//false로 초기화

    //입력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                wall_case.push_back(make_pair(i,j)); //벽 가능 지역
                room++;
            }
            if(board[i][j] == 2){
                virus_init.push_back(make_pair(i,j));//초기 저장
            }
        }
    }

    //모든 벽 가능한 케이스 시도
    int max_safe = 0;

    //조합으로 벽 가능 지역 3개 선택
    //순서가 있는 순열 -> 조합과 일치(확률과 통계)
    for (int i = 0; i < wall_case.size(); i++) {
        for (int j = i + 1; j < wall_case.size(); j++) {
            for (int k = j + 1; k < wall_case.size(); k++) {
                    for(int i = 0; i < 9; i++){
                        for(int j = 0; j < 9; j++){
                            visited_virus[i][j] = false;
                        }
                    }
                    
                    queue<pair<int,int>> q;
                    //초기 -> 큐 삽입
                    for (auto &v : virus_init) {
                        q.push(v);
                        visited_virus[v.X][v.Y] = true;
                    }
                    

                    //바이러스 bfs
                    auto a = wall_case[i];
                    auto b = wall_case[j];
                    auto c = wall_case[k];

                    board[a.X][a.Y] = 1;
                    board[b.X][b.Y] = 1;
                    board[c.X][c.Y] = 1;

                    int ans = bfs(q,n,m);//bfs
                    int safe = room - 3 - ans + (int)virus_init.size(); //추가 벽 제외

                    max_safe = max(safe,max_safe);//전체 넓이 - 벽 - 바이러스 이동 = 안전지대, 안전지대 최대값 -> 바이러스 이동거리 최소

                    board[a.X][a.Y] = 0; //초기화
                    board[b.X][b.Y] = 0; 
                    board[c.X][c.Y] = 0;
            }
        }
    }


    cout << max_safe << '\n';
    

    return 0;
}

