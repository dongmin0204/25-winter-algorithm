#include <string>
#include <vector>
#include <algorithm> // max_element
using namespace std;

// n명을 mid 시간 안에 심사할 수 있는지 확인
bool feasible(const vector<int>& times, int n, long long mid) {
    long long done = 0;
    for (int i = 0; i < times.size(); i++) {
        done += mid / (long long)times[i];
        if (done >= n) return true; // 이미 충분히 처리 가능
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = (long long)(*max_element(times.begin(), times.end())) * n;
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (feasible(times, n, mid)) {
            answer = mid;    // 가능한 경우 → 최소 시간 후보
            right = mid - 1; // 더 작은 시간 탐색
        } else {
            left = mid + 1;  // 불가능 → 더 큰 시간 탐색
        }
    }
    return answer;
}
