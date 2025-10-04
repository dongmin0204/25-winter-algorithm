#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> cnt; //이름 1->0되면 통과

    // 참가자 카운트
    for (const auto& p : participant) cnt[p]++;

    // 완주자 차감
    for (const auto& c : completion) cnt[c]--;

    // 남아있는 사람
    for (const auto& kv : cnt) {
        if (kv.second > 0) return kv.first;
    }
    return "";
}