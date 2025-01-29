#include <bits/stdc++.h>
using namespace std;

// 두 개의 문자열 숫자를 곱하는 함수
string multiplyStrings(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    // 곱셈 수행
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // 결과를 문자열로 변환
    string ans = "";
    for (int num : result) {
        if (!(ans.empty() && num == 0)) {
            ans.push_back(num + '0');
        }
    }
    return ans.empty() ? "0" : ans;
}

// 문자열 숫자를 정수로 나누는 함수
string divideString(string num, int divisor) {
    string result = "";
    long long temp = 0;

    for (char c : num) {
        temp = temp * 10 + (c - '0');
        result.push_back((temp / divisor) + '0');
        temp %= divisor;
    }

    // 앞에 남은 0 제거
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
}

// 조합 계산 함수
string calculateCombination(int n, int k) {
    string result = "1";

    for (int i = 0; i < k; i++) {
        result = multiplyStrings(result, to_string(n - i));  // 분자 곱하기
        result = divideString(result, i + 1);               // 분모 나누기
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << calculateCombination(n, k) << '\n';
    return 0;
}
