#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int N; // 전체 케이스의 개수
    cin >> N;
    cin.ignore(); // 개행 문자 무시

    for (int i = 1; i <= N; i++) {
        string line;
        getline(cin, line); // 한 줄 입력 받기

        stack<string> words; // 단어를 저장할 스택
        stringstream ss(line);
        string word;

        // 단어를 공백 기준으로 스택에 저장
        while (ss >> word) {
            words.push(word);
        }

        // 출력
        cout << "Case #" << i << ": ";
        bool first = true;
        while (!words.empty()) {
            if (!first) cout << " ";
            cout << words.top();
            words.pop();
            first = false;
        }
        cout << '\n';
    }

    return 0;
}
