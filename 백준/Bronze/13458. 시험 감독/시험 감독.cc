#include <bits/stdc++.h>
using namespace std;

int main (void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;

    vector<long long> testPlace(1000011);

    for(int i = 0; i < n; i++){
        cin >> testPlace[i];
    }

    long long b,c;
    cin >> b >> c;

    for(int i = 0; i < n; i++){
        if (testPlace[i] <= b) ans += 1;
        else ans += 1 + (testPlace[i] - b + c - 1) / c; // 올림((x-b)/c)
    }
    cout << ans << "\n";
    return 0;
}