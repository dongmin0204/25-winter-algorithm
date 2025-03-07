#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,c;
    cin >> n >> c;

    vector<int> input(n);
    
    for(int i  = 0; i < n; i++){
        cin >> input[i];
    }
    sort(input.begin(),input.end());

    int start = 1; //시작 최소 거리
    int end = input[n-1] - input[0];//최대거리 (맨 끝 거리)
    int ans = 0;

    while(start <= end){
        int mid = (start + end) / 2;
        
        int cnt = 1;
        int prev = input[0];
        for(int i = 1; i < n; i ++){
            if(input[i] - prev >= mid) {
                cnt++;
                prev = input[i];//현재 좌표 집 - 직전 집 보다 크면
            }
        }

        if(cnt >= c){ //공유기 제한 갯수 미만 사용할 경우, 공유기를 설치하는 거리를 늘리기
            ans = max(ans,mid);
            start = mid +1;
        }
        else{ //공유기 거리 줄이기
             end = mid-1;
        }
    }
    cout << ans;

    return 0;
}