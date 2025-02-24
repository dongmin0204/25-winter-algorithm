#include <bits/stdc++.h>
using namespace std;

int dp[1001];
// (1) 1 2 3 5 8 13... 순 (피보나치)
 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    int n; 
    cin >> n;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1]+dp[i-2])%10007;//메모라이제이션 활용
    }

    cout << dp[n];

    return 0;
}