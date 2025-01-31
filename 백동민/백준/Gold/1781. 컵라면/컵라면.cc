#include <bits/stdc++.h>
using namespace std;
#define DEADLINE first
#define RAMEN second


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> works(n); 

    //과제 입력
    for (int i = 0; i < n; i++) {
        cin >> works[i].DEADLINE >> works[i].RAMEN;
    }

    // 데드라인 정렬 -> 일단 데드라인 최소로 정렬해서 1일떄 ,2일때 각각의 최선의 라면의 갯수 파악하기 위함
    sort(works.begin(), works.end());

    priority_queue<int, vector<int>, greater<int>> ramenH; // 최소 힙

    // 과제 그리디 ㄱㄱ
    for (const auto& work : works) { //const auto & -> rvalue 써서 메모리 관리 
        // 큐에 지금 과제 추가
        ramenH.push(work.RAMEN);

        // 데드라인 초과하면 최소 라면을 가진 과제 제거
        if (ramenH.size() > work.DEADLINE) {
            ramenH.pop();
        }
    }

    //이제 선택된 과제의 라면 합
    long int sum = 0;
    while (!ramenH.empty()) {
        sum += ramenH.top();
        ramenH.pop();
    }

    cout << sum << '\n'; // 최대 컵라면 출력
    return 0;
}