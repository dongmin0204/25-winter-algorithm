#include <bits/stdc++.h>
using namespace std;

stack<char> op; // 연산자

// 연산자 우선순위
inline int prec(char ch) {
    if (ch == '*' || ch == '/') return 2; // 곱셈 나눗셈 우선순위 2
    if (ch == '+' || ch == '-') return 1; // 덧셈 뺄셈 우선순위 1
    return 0; // 나머지
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    vector<char> ans; //답안지

    for (const auto it : input) {
        if (isalpha(it)) {
            ans.push_back(it); //피연사자 처리
        }
        else if (it == '(') {
            op.push(it); // 좌괄호는 스택에 push
        }
        else if (it == ')') {
            // 우괄호가 나오면 여는 괄호가 나올 때까지 스택에서 pop
            while (!op.empty() && op.top() != '(') {
                ans.push_back(op.top());
                op.pop();
            }
            op.pop(); // 여는 괄호 '(' 제거
        }
        else { // 연산자 처리
            while (!op.empty() && prec(op.top()) >= prec(it)) {
                ans.push_back(op.top());
                op.pop();
            }
            op.push(it);
        }
    }

    // 스택에 남아 있는 연산자를 모두 출력
    while (!op.empty()) {
        ans.push_back(op.top());
        op.pop();
    }

    // 후위 표기식 출력
    for (char ch : ans) {
        cout << ch;
    }
    cout << '\n';

    return 0;
}
