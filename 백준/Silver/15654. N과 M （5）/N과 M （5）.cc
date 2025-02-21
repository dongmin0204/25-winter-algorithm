#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> input, code;
vector<bool> visited;

void bt(int level) {
    if(level == m) {
        for(int num : code)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) { // 중복확인
            visited[i] = true;
            code.push_back(input[i]);
            bt(level + 1);
            code.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    input.resize(n);
    visited.resize(n, false);

    for(int i = 0; i < n; i++)
        cin >> input[i];

    sort(input.begin(), input.end()); // 사전순 정렬

    bt(0);

    return 0;
}
