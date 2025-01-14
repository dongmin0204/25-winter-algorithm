#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> josephus(int N, int K) {
    queue<int> circle;
    vector<int> result;

    // Initialize the queue with people from 1 to N
    for (int i = 1; i <= N; ++i) {
        circle.push(i);
    }

    // Simulate the Josephus problem
    while (!circle.empty()) {
        // Rotate the queue K-1 times
        for (int i = 1; i < K; ++i) {
            circle.push(circle.front());
            circle.pop();
        }
        // Remove the K-th person
        result.push_back(circle.front());
        circle.pop();
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> result = josephus(N, K);

    // Print the result in the desired format
    cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">";

    return 0;
}