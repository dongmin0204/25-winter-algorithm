#include <bits/stdc++.h>
using namespace std;
set<int> S;

void calculate(int n, int k, vector<string> v, int depth) {
    if(depth == k) {
        string s;
        for(int i = 0; i < k; i++) {
            s += v[i];
        }
        int number = stoi(s);
        S.insert(number);
        // cout << number << '\n';
        return;
    }
    for(int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        calculate(n, k, v, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<string> v;
    
    for (int i = 0; i < n; i++) {
        string num; 
        cin >> num;
        v.push_back(num);
    }
    vector<string> vv;
    calculate(n, k, v, 0);
    cout << S.size();
}