#include <bits/stdc++.h>
using namespace std;

// 시리얼 번호의 숫자 합을 계산하는 함수
int sum_of_digits(const string& s) {
    int sum = 0;
    for(char c : s){
        if(isdigit(c)){
            sum += c - '0';
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> serial(n);
    for(int i = 0; i < n; ++i){
        cin >> serial[i];
    }
    
    // 사용자 정의 정렬 기준
    sort(serial.begin(), serial.end(), [&](const string& a, const string& b) -> bool {
        // 1. 길이가 짧은 것이 먼저
        if(a.length() != b.length()){
            return a.length() < b.length();
        }
        // 2. 숫자의 합이 작은 것이 먼저
        int sum_a = sum_of_digits(a);
        int sum_b = sum_of_digits(b);
        if(sum_a != sum_b){
            return sum_a < sum_b;
        }
        // 3. 사전 순으로 비교 (숫자가 알파벳보다 작음)
        return a < b;
    });
    
    // 정렬된 시리얼 번호 출력
    for(const auto& s : serial){
        cout << s << '\n';
    }
    
    return 0;
}
