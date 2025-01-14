#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n,k;
    cin >> n >> k;

    vector<int>vec(n);
    queue<int> q;

    for(int i = 0; i < n; i++){
        q.push(i+1);
    } //요세푸스 수 삽입

    while (!q.empty()) { //q가 빌때까지

        //k번째가 queue.front()이러면 k-1만큰 pop하고 push
        for (int i = 0; i < k-1; i++) {
            q.push(q.front());
            q.pop();
        }

        vec.push_back(q.front()); //이제 k번째 사람을 답안지(vec)에 옮긴다.
        q.pop();
    }


    //출력 코드
    cout << "<";
    for (int i = 0; i < n; ++i) {
        cout << vec[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << ">";



    return 0;
}
