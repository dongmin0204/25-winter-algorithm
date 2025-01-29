#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        int S, B; // S: 병사 수, B: 보고된 사망 구간 수
        cin >> S >> B;
        
        if (S == 0 && B == 0) break;
        
        // 왼쪽과 오른쪽 병사 정보를 저장
        vector<int> left(S + 2), right(S + 2);
        
        for (int i = 1; i <= S; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        
        left[1] = -1;  // 첫 번째 병사는 왼쪽이 없음
        right[S] = -1; // 마지막 병사는 오른쪽이 없음
        
        for (int i = 0; i < B; ++i) {
            int L, R; // L: 사망 구간 시작, R: 사망 구간 끝
            cin >> L >> R;
            
            int new_left = left[L];
            int new_right = right[R];
            
            // 새로운 이웃 관계 설정
            if (new_left != -1) right[new_left] = new_right;
            if (new_right != -1) left[new_right] = new_left;
            
            // 출력
            if (new_left == -1) cout << "* ";
            else cout << new_left << " ";
            
            if (new_right == -1) cout << "*\n";
            else cout << new_right << "\n";
        }
        
        cout << "-\n";
    }
    
    return 0;
}
