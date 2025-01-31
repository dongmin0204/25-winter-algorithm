#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> order(n);
    for (int i = 0; i < n; i++){
        cin >> order[i];
    }

    stack<int> area;
    int l = 1; //번호표
    int idx = 0;   

    while (idx < n) { //순서를 읽는 인덱스가 입력 받은 사이즈 보다 작을 때 까지 

        if (order[idx] == l) {
            l++;
            idx++;
        } 

        else {
            area.push(order[idx]);
            idx++;
        }

        while (!area.empty() && area.top() == l) { //다음 차례가 빈 공간의 탑에 위치할 경우
            area.pop();
            l++;
        }
    }
    if (l == n + 1) {
        cout << "Nice\n";
    } 
    else {
        cout << "Sad\n";
    }

    return 0;
}
