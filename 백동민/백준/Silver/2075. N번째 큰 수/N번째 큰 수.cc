#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,input;
    priority_queue<int, vector<int>, greater<>> pq;//삽일할때마다, 가장 큰 값이 top

    cin >> n;
    for (int i = 0; i < n * n; i++) {

        cin >> input;
        pq.push(input);

        if (n < pq.size()) { //해당 for문 실행 시점 제일 큰값 n개만
            pq.pop();//가장 작은 값 버리기
        }
    }
        cout << pq.top() << '\n';
    return 0;
}