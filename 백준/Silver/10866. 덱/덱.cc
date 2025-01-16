#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> dq;
    string command;

    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (command == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (command == "pop_front") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        } else if (command == "pop_back") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        } else if (command == "size") {
            cout << dq.size() << endl;
        } else if (command == "empty") {
            cout << (dq.empty() ? 1 : 0) << endl;
        } else if (command == "front") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.front() << endl;
            }
        } else if (command == "back") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.back() << endl;
            }
        }
    }

    return 0;
}