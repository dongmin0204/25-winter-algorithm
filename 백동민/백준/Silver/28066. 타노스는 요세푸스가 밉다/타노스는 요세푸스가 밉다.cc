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

    while (q.size() > 1) { //q에 원소가 하나 남을 때 까지.

        //k번째가 queue.front()이러면 k-1만큰 pop하고 push
        for (int i = 0; i < k-1; i++) {
            q.push(q.front()); //살아남은 원소 
            q.pop();
            if(q.size() > k){
                for(int i = 0; i < k-1; i++){ // 2~k까지 Pop
                    q.pop();
                }
            }
            else{
                while(q.size() > 1){ //k보다 작으면 첫 번째 제외 pop
                    q.pop();
                }
            }
        }
    }


    //출력 코드
    cout << q.front() << '\n';



    return 0;
}