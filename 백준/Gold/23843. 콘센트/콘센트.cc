#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M; 
    cin >> N >> M;
    
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    };
    
    sort(v.begin(), v.end());
    
    // int p = N / (M);
    vector<int> vv(M, 0);
    
    // for (int i = 0; i < M; i++) {
    //     // int q = p*i;
    //     // vv.push_back(v[q]);
    //     // v[q] = 0;
    //     vv[i] = 0;
    // }
    
    priority_queue<int> PQ;
    for(int i = 0; i < N; i++) {
        PQ.push(v[i]);
        // cout << v[i] << '\n';
    }
    
    // int S = N - M;
    for (int i = 0; i < N; i++) {
        
        int num = PQ.top();
        // cout << num << '\n';
        PQ.pop();
        vv[0] += num;
        sort(vv.begin(), vv.end());
    }
    
    // for (auto i : vv) cout << i << " ";
    cout << vv[M-1];
    
    return 0;
}