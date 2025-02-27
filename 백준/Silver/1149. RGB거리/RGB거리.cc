#include <bits/stdc++.h>
using namespace std;

struct RGB{
    int r;
    int g;
    int b;
    RGB(int rr=0, int gg=0, int bb=0) : r(rr), g(gg), b(bb) {}
};//rgb 구조체

RGB dp[1001]; 
RGB input[1001];
 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> input[i].r >> input[i].g >> input[i].b;
    }
    dp[0] = RGB(0,0,0);
    input[0] = RGB(0,0,0);

    for(int i = 1; i <= n; i++){
        dp[i].r = min(dp[i-1].g, dp[i-1].b)+ input[i].r;
        dp[i].g = min(dp[i-1].b, dp[i-1].r)+ input[i].g;
        dp[i].b = min(dp[i-1].r, dp[i-1].g)+ input[i].b;
    }

    cout << min({dp[n].r, dp[n].g, dp[n].b}) << '\n';

    return 0;
}