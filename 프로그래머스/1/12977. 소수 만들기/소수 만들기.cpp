#include <vector>
#include <iostream>
using namespace std;

// 에라토스테네스의 체: is_prime[i]가 1이면 소수, 0이면 합성수
static void prime(vector<char>& is_prime) {
    int n = (int)is_prime.size() - 1;
    if (n < 1) return;
    is_prime[0] = 0;
    if (n >= 1) is_prime[1] = 0;
    for (int p = 2; p * p <= n; ++p) {
        if (!is_prime[p]) continue;
        for (int x = p * p; x <= n; x += p) is_prime[x] = 0;
    }
}

int solution(vector<int> nums) {
    const int n = (int)nums.size();
    if (n < 3) return 0;

    // 가장 큰 3개 합(상한 최소화)
    int t1 = 0, t2 = 0, t3 = 0;
    for (int x : nums) {
        if (x >= t1) { t3 = t2; t2 = t1; t1 = x; }
        else if (x >= t2) { t3 = t2; t2 = x; }
        else if (x > t3) { t3 = x; }
    }
    int max_sum = t1 + t2 + t3;

    vector<char> is_prime(max_sum + 1, 1);
    prime(is_prime);

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int s = nums[i] + nums[j] + nums[k];

                // s >= 6이므로 짝수 합은 소수 불가
                if ((s & 1) == 0) continue; // 비트연산 떄려버려

                if (is_prime[s]) ++answer;
            }
        }
    }
    return answer;
}