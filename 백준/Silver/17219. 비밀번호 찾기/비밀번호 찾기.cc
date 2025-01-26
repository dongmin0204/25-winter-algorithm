#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, string> Map;
    for(int i = 0; i < N; i++) {
        string ID, Password;
        cin >> ID >> Password;
        Map.insert({ID, Password});
    }
    
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        cout << Map[str] << '\n';
    }
}