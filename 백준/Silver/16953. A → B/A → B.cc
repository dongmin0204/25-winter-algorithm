#include <bits/stdc++.h>
using namespace std;

map<string, int> visited; // key값으로 탐색 

string a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    if (a == b) { // 시작 값과 목표 값이 같으면 0
        cout << 0;
        return 0;
    }

    long long int target = stoll(b); // 목표값을 미리 변환

    queue<string> q;
    q.push(a);
    visited[a] = 0; // 시작 노드의 연산 횟수를 0

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        long long int num = stoll(cur);

        for (int i = 0; i < 2; i++) {
            long long int next;
            if (i == 0) {
                next = num * 2;
            } else {
                next = num * 10 + 1;
            }

            if (next > target) continue; // 목표보다 크면 나가

            string nextStr = to_string(next);
            if (visited.find(nextStr) == visited.end()) { // 방문하지 않은 경우에만
                visited[nextStr] = visited[cur] + 1;
                q.push(nextStr);
            }
        }
    }

    if (visited.find(b) != visited.end()) {
        cout << visited[b]+1;
    } else {
        cout << -1;
    }

    return 0;
}
