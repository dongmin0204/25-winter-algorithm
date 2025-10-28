#include <bits/stdc++.h>
using namespace std;

struct Robot {
    int r, c;   // 현위치 (0-index)
    int step;   // 다음 목표 인덱스 (routes[i][step])
    bool done;  // 퇴장 여부
};

// 같은 시각에 같은 칸에 2대 이상 있으면 그 칸을 1로 카운트
int count_broken(const vector<Robot>& robots, bool include_finished) {
    map<pair<int,int>, int> cnt;
    
    for (int i = 0; i < robots.size(); i++) {
        if (!include_finished && robots[i].done) continue;
        cnt[ {robots[i].r, robots[i].c} ]++;
    }
    
    int add = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        if (it->second >= 2) ++add;
    return add;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    const int R = routes.size();

   
    for (auto &p : points) { 
        p[0]--; p[1]--; 
    }

    vector<Robot> robots(R);
    for (int i = 0; i < R; i++) {
        int s = routes[i][0] - 1;      // 시작 포인트
        robots[i].r = points[s][0];
        robots[i].c = points[s][1];
        robots[i].step = 1;             // 다음 목표는 routes[i][1]
        robots[i].done = routes[i].size() <= 1; // 경로 길이 1인 케이스
    }

    long long answer = 0;

    // t = 0 
    answer += count_broken(robots, true);

    // 시뮬레이션
    while (true) {
        //한 타임 시작
        for (int i = 0; i < R; ++i) {
            if (robots[i].done) continue;

            if (robots[i].step < (int)routes[i].size()) {
                int tp = routes[i][robots[i].step] - 1;
                if (robots[i].r == points[tp][0] && robots[i].c == points[tp][1]) {
                    robots[i].step++;
                }
            }
            if (robots[i].step >= (int)routes[i].size()) {
                robots[i].done = true; //이번 시각부터 공간에서 제외
            }
        }

        //더 움직일 로봇 없으면 종료
        int active = 0;
        for (int i = 0; i < R; ++i) {
            if (!robots[i].done) active++;
        }
        if (active == 0) break;

        // r->c 순서로 이동
        for (int i = 0; i < R; ++i) {
            
            if (robots[i].done) continue;
            
            int tp = routes[i][robots[i].step] - 1;
            int tr = points[tp][0], tc = points[tp][1];

            if (robots[i].r != tr) { //상하 먼저 한대
                robots[i].r += (robots[i].r < tr ? 1 : -1); //상하 판단
            } else if (robots[i].c != tc) {
                robots[i].c += (robots[i].c < tc ? 1 : -1); //좌우 판단
            }
        }

        // 4이동 직후 겹침 카운트
        answer += count_broken(robots, false);
    }

    return answer;
}
