#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l;
    cin >> k >> l;

    unordered_map<string, list<string>::iterator> sugangMap; // 학번 위치 저장
    list<string> sugangList; // 순서 유지 리스트

    string input;
    for (int i = 0; i < l; i++) {
        cin >> input;

        // 학번 존재 -> 삭제
        if (sugangMap.find(input) != sugangMap.end()) {
            sugangList.erase(sugangMap[input]);
        }

        // 새로 추가
        sugangList.push_back(input);
        sugangMap[input] = --sugangList.end(); //업데이트
    }

    // 출력 
    int cnt = 0;
    for (const string& id : sugangList) {
        if (cnt == k) break;
        cout << id << '\n';
        cnt++;
    }

    return 0;
}
