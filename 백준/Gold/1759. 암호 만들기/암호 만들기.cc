#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> code;        // 입력받은 문자들
vector<string> ans;       // 가능한 암호를 저장할 벡터

inline bool checkVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

/* 
// str: 현재 인덳 
// start: 다음에 탐색할 code의 인덱스
// vowel: 지금까지 포함된 모음 수
// cons: 지금까지 포함된 자음 수
// picked: 지금까지 몇 개의 문자를 골랐는지
*/
void bt(const string &str, int start, int vowel, int cons, int picked){
    // start -> 이제 끝 도달
    if (picked == l) {
        // 조건(모음 1개 이상, 자음 2개 이상) 확인
        if (vowel >= 1 && cons >= 2) {
            ans.push_back(str);
        }
        return;
    }

    // start부터 c-1까지 탐색
    for (int i = start; i < c; i++) {
        char ch = code[i];
        if (checkVowel(ch)) {
            // 모음
            bt(str + ch, i + 1, vowel + 1, cons, picked + 1);
        } else {
            // 자음
            bt(str + ch, i + 1, vowel, cons + 1, picked + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;
    code.resize(c);

    // 문자 c개를 공백 구분으로 입력받기
    for(int i = 0; i < c; i++){
        cin >> code[i];
    }

    // 사전 순 출력을 위해 정렬
    sort(code.begin(), code.end());

    // 백트래킹
    bt("", 0, 0, 0, 0);

    // 결과 출력
    for (auto &s : ans){
        cout << s << "\n";
    }

    return 0;
}
