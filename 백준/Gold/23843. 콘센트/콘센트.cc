#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    priority_queue<int, vector<int>, greater<int>> PQ;

    for (int i = 0; i < M; i++) {
        PQ.push(0); 
    }

    sort(v.rbegin(), v.rend()); 

    for (int time : v) {
        int earliest = PQ.top(); 
        PQ.pop();
        PQ.push(earliest + time); 
    }

    while (PQ.size() > 1) {
        PQ.pop(); 
    }
    cout << PQ.top() << '\n'; 

    return 0;
}
