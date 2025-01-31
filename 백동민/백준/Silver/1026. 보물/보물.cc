#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> min(n);
    vector<int> max(n);

    for(int i = 0; i < n; i++){
        cin >> min[i];
    }
    for(int i = 0; i < n; i++){
        cin >> max[i];
    }
    sort(min.begin(),min.end(),greater<int>());
    sort(max.begin(),max.end(),less<int>());

    int res = 0;
    for(int i = 0; i < n; i++){
        res += min[i]*max[i];
    }
    cout << res;

    return 0;
}