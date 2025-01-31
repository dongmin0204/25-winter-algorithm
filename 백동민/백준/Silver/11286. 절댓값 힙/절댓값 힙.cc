#include <bits/stdc++.h>
using namespace std;

struct absCmp {
    int value;
    bool operator<(const absCmp& other)  const{
        return abs(value) == abs(other.value) ? value > other.value : abs(value) > abs(other.value);
    }
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<struct absCmp> pq;

    int n;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        if(input == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top().value << '\n';
                pq.pop();
            }
        }
        else{
            pq.push({input});
        }
    }
    return 0;
}