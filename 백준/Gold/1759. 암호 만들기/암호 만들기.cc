#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> code;
vector<string> ans;

bool isVowel(char ch) {
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

void backtrack(int idx, int picked, int vowelCount, int consCount, string cur){
    // base case: L개 골랐을 때
    if(picked == L){
        if(vowelCount >= 1 && consCount >= 2){
            ans.push_back(cur);
        }
        return;
    }

    // idx부터 C-1까지 탐색
    for(int i = idx; i < C; i++){
        char ch = code[i];
        if(isVowel(ch)) {
            // 모음이면 vowelCount+1
            backtrack(i + 1, picked + 1, vowelCount + 1, consCount, cur + ch);
        } else {
            // 자음이면 consCount+1
            backtrack(i + 1, picked + 1, vowelCount, consCount + 1, cur + ch);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;

    code.resize(C);
    for(int i = 0; i < C; i++){
        cin >> code[i];
    }

    // 사전 순으로 만들기 위해 미리 정렬
    sort(code.begin(), code.end());

    // (다음에 볼 인덱스 0, 아직 0개 골랐음, 모음/자음=0, 현재 문자열="")
    backtrack(0, 0, 0, 0, "");

    for(auto &s : ans){
        cout << s << "\n";
    }
    return 0;
}
