#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n,m;
vector<LL> trees;

bool isPossible(LL height) {
    LL total = 0;
    for (LL tree : trees) {
        if (tree > height) {
            total += tree - height;
        }
    }
    return total >= m;
}

LL BS() {
    LL low = 0, high = *max_element(trees.begin(), trees.end()); //맛있는 stl
    LL result = 0;

    while (low <= high) {
        LL mid = (low + high) / 2;

        if (isPossible(mid)) {
            result = mid;  // 최대한 높은 절단기 찾기 위해 저장
            low = mid + 1;  //탐색 범위(최솟값) 변경
        } 
        else {
            high = mid - 1; //가능하지 못하니까 최댓값 변경
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    trees.resize(n);

    for (LL i = 0; i < n; i++) {
        cin >> trees[i];
    }

    cout << BS() << '\n';
    return 0;
}
