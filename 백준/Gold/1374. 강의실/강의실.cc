#include <bits/stdc++.h>
using namespace std;

struct Lecture {
    int id;
    int start;
    int end;
};

bool compareStart(const Lecture& a, const Lecture& b) {
    return a.start < b.start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<Lecture> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].id >> lectures[i].start >> lectures[i].end;
    }
    
    // 시작 시간 순으로 정렬
    sort(lectures.begin(), lectures.end(), compareStart);
    
    // 우선순위 큐 (최소 힙), 각 강의실의 마지막 강의 종료 시간 저장
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < N; i++) {
        // 현재 강의의 시작 시간보다 일찍 끝나는 강의실이 있는지 확인
        if (!pq.empty() && pq.top() <= lectures[i].start) {
            // 기존 강의실 사용 가능하면 종료 시간 업데이트
            pq.pop();
        }
        // 새로운 강의실 추가 또는 기존 강의실 업데이트
        pq.push(lectures[i].end);
    }
    
    cout << pq.size() << "\n";
    
    return 0;
}