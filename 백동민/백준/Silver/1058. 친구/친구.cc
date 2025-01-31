#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> friends(n + 1);

    // 인접 행렬 입력받기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'Y') {
                friends[i].push_back(j);
            }
        }
    }

    int maxFriends = 0;

    for (int i = 1; i <= n; i++) {
        set<int> secondFriends; // 중복 제거 -> set자료구조

        for (int friend1 : friends[i]) {
            secondFriends.insert(friend1);
            for (int friend2 : friends[friend1]) {
                if (friend2 != i) { 
                    secondFriends.insert(friend2);
                }
            }
        }

        maxFriends = max(maxFriends, (int)secondFriends.size());
    }

    cout << maxFriends << '\n';

    return 0;
}
