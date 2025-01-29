#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    pair<int, int> high = {0, 0};
    vector<pair<int,int>> v;
    
    for(int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;
        
        if(!v.empty() && high.second < H){
            high = {L, H};
            v.push_back({L, H});
        } else {
            if(v.empty()){
                high = {L, H};
            }
            v.push_back({L, H});
        }
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    
    stack<pair<int, int>> stk;
    bool hh = false;
    int total = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if( !hh && v[i].second == high.second) {
            hh = true;
            high = {v[i].first, v[i].second};
            if(!stk.empty()) total += (v[i].first - stk.top().first) * stk.top().second;
            stk.push({v[i].first, v[i].second});
            total += stk.top().second;
            // cout << total << '\n';
            continue;
        }
        if(hh) {
            while(stk.top().second < v[i].second) {
                stk.pop();
            } 
            if(high.second == v[i].second) {
                total += (v[i].first - stk.top().first)*stk.top().second;
                // cout << total << '\n';
            }
            stk.push({v[i].first, v[i].second});
        } else {
            if(!stk.empty() && stk.top().second < v[i].second) {
                total += (v[i].first - stk.top().first) * stk.top().second;
                stk.push({v[i].first, v[i].second});
                // cout << total << '\n';
            } else if(stk.empty()) {
                stk.push({v[i].first, v[i].second});
            }
        }
    }
    
    while(!(stk.top().second == high.second)) {
        pair<int, int> temp = stk.top();
        stk.pop();
        total += (temp.first - stk.top().first) * temp.second;
        // cout << total << '\n';
    }
    cout << total;
}