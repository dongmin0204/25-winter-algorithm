#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    
    // tail: 각 길이의 증가 부분 수열의 마지막 원소 값 (최소값)
    // tail_index: tail에 기록된 값이 input에서 몇 번째 인덱스인지 저장
    vector<int> tail, tail_index;
    
    // prev: 각 인덱스 i에 대해, input[i]가 부분 수열에서 연결된 이전 인덱스 저장
    vector<int> prev(n, -1);

    //배열로 풀다가 좀 찾아보면서 3개의 벡터가 필요함을 앍게되었습니다
    
    for (int i = 0; i < n; i++){
        // low_bound로 위치 찾기
        int idx = lower_bound(tail.begin(), tail.end(), input[i]) - tail.begin();
        
        // tail의 길이와 idx가 같다면 최장길이 수열 업데이트
        if (idx == tail.size()){
            tail.push_back(input[i]);
            tail_index.push_back(i);
        } else {
            tail[idx] = input[i];
            tail_index[idx] = i;
        }
        
        // idx가 0보다 크다면 -> tail_index[idx-1]업데이트
        if (idx > 0) {
            prev[i] = tail_index[idx - 1];
        }
    }
    
    // 최장 증가 부분 수열의 길이
    int lis_length = tail.size();
    cout << lis_length << "\n";
    
    // tail_index[lis_length-1]는 최장 수열의 마지막 원소의 인덱스
    int index = tail_index[lis_length - 1];
    vector<int> lis;
    while (index != -1) {
        lis.push_back(input[index]);
        index = prev[index];
    }
    reverse(lis.begin(), lis.end()); //순서가 지금 뒤로부터 넣었으니까 바꾸기
    
    // 하나의 최장 증가 부분 수열 출력
    for (int num : lis) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}
