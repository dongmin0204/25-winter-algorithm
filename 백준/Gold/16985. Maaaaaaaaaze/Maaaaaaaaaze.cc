#include <bits/stdc++.h>
using namespace std;


//좌표
struct pos{
    int first; //X
    int second; //Y
    int height; //H
    pos(int h, int x, int y) : first(x), second(y), height(h) {}
};

//회전 + 횟수 
// 회전을 n번(0~3번) 적용해서 src -> dest 로 넣는 헬퍼 함수
void rotate(const int src[5][5], int dest[5][5], int n){ //소스 변하면 문제 발생함...
    int temp1[5][5], temp2[5][5];

    //src를 temp1에 복사
    memcpy(temp1, src, sizeof(temp1));

    // n번 시계방향 90도 회전
    for(int cnt = 0; cnt < n; cnt++){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                temp2[j][4-i] = temp1[i][j];
            }
        }
        // temp2 -> temp1 로 복사
        memcpy(temp1, temp2, sizeof(temp1));
    }
    // 이를 dest로 복사
    memcpy(dest, temp1, sizeof(temp1));
}


int cube[5][5][5]; // i : 층 위치, j : 큐브의 행, k: 큐브의 열
int dist[5][5][5]; // 거리
int tempcube[5][5][5]; //회전 경우 담는 큐브

int ans = 9999999;//정답지

//이거 보니까 재귀 안쓰면 코드 진짜 길어지겠다...
int bfs(int board[5][5][5]){
    queue<struct pos> q;
    memset(dist, -1, sizeof(dist)); // dist 배열을 0으로 초기화
    int direction[6][3] = { {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1}, {-1,0,0},{1,0,0}  }; // 상하좌우 + z축 위아래

    // 시작점 확인 -> 혹시모름
    if(board[0][0][0] == 0) return -1;

    q.push(pos(0,0,0));
    dist[0][0][0] = 0; //시작점 거리 초기화
    // bfs
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        //도착~
        if(cur.height == 4 && cur.first == 4 && cur.second ==4) return dist[4][4][4];

        for(int d = 0; d < 6; d++){

            int nh = cur.height + direction[d][0];
            int nx = cur.first + direction[d][1];
            int ny = cur.second + direction[d][2];

            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nh < 0 || nh >= 5) continue; // 범위를 벗어나는 경우
            if(dist[nh][nx][ny] >= 0) continue;//이미 들림
            if(board[nh][nx][ny] == 0) continue; 


            dist[nh][nx][ny]  =  dist[cur.height][cur.first][cur.second] + 1;
            q.push(pos(nh,nx,ny)); // 큐에 새로운 위치 추가
            
        }
    }
    return -1; //불가능

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int** cubecase[5]; //큐브 케이스 저장

    //입력
    int temp;
    for(int k = 0; k < 5; k++){ //높이
        for(int i = 0; i < 5; i++){ //세로
            for(int j = 0; j < 5; j++){ //가로

                cin >> temp;
                cube[k][i][j] = temp;
                if(temp == 0){
                    dist[k][i][j] = -1;
                }
            }
        }
    }
    int order[120][5];
    int temparr[5] =  {0,1,2,3,4};
    
    int index = 0;
    do{
        for(int i = 0; i < 5; i++){
            order[index][i] = temparr[i];
        }
        index++;
    }while(next_permutation(temparr,temparr+5));
    //temparr에 순열 적용

    //order에 모든 경우의 삽입완료

    //회전 케이스도 모두 넣기 
    int rotatecase[1024][5];
    index = 0;
    for (int a = 0; a < 4; a++){
        for (int b = 0; b < 4; b++){
            for (int c = 0; c < 4; c++){
                for (int d = 0; d < 4; d++){
                    for (int e = 0; e < 4; e++){
                        rotatecase[index][0] = a;
                        rotatecase[index][1] = b;
                        rotatecase[index][2] = c;
                        rotatecase[index][3] = d;
                        rotatecase[index][4] = e;
                        index++;
                    }
                }
            }
        }
    }
    //너무 하드코딩으로 구현해서 마음이 아프다... 

    for(int p = 0; p < 120; p++){ //층 순열 모든 케이스 
        for(int r = 0; r < 1024; r++){ //회전 중복 순열 모든 케이스 
            for(int l = 0; l < 5; l++){ //각 층마다
                int orderIdx = order[p][l];      
                int rotateCnt = rotatecase[r][l];
                rotate(cube[orderIdx], tempcube[l], rotateCnt);
            }

                int tmp = bfs(tempcube);
                if(tmp != -1){
                    ans = min(ans, tmp); //최소거리 판단
                if(ans == 12) {
                    break; //12면 무조건 최소니까
                }
            }
        }
    }   
    



    if(ans == 9999999) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}