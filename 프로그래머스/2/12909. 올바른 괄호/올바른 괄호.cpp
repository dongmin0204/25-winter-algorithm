#include<string>
#include <stack>
#include <iostream>

using namespace std;

#include <string>
using namespace std;

bool solution(string s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') {
            cnt++;
        }
        else if (c == ')') {
            if (cnt == 0) {
                return false; // ')'가 더 먼저 
            }
            cnt--;
        }
    }
    return cnt == 0; // 모두 짝 맞아야 0
}