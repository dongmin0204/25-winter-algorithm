#include <bits/stdc++.h>
using namespace std;

vector<int> dp_list[1001]; //배열 저장 
int dp[1001]; //사이즈 미리 저장
int arr[1001];
int input[1001];
 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    vector<int> temp;//가장 긴 수열 저장 

    for(int i = 0; i < n; i++){
        dp[i] = 1;//1개
        dp_list[i].push_back(input[i]);//수열 살입
        for(int j = 0; j < i; j++){
            if(input[i] > input[j]){
                if(dp[i] < dp[j]+1){ //사이즈가 1개 보다 크면?
                    dp_list[i] = dp_list[j]; //직전 j 값 복사.
                    dp_list[i].push_back(input[i]);
                    dp[i] = dp[j]+1;
                }
            }
        }
        // 현재 부분 수열 업뎃
        if (temp.size() < dp_list[i].size()) {
            temp = dp_list[i];
        }
    }
    // 최장 증가 부분 수열 출력
    cout << temp.size() << '\n';
    for (int num : temp) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}