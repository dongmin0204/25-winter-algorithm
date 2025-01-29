#include <bits/stdc++.h>
using namespace std;

struct Data {
    int absValue;
    int value;
    
    bool operator<(const Data& other) const {
        if (absValue == other.absValue) {
            return value > other.value;
        }
        return absValue > other.absValue;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; 
    cin >> N;
    priority_queue<Data> PQ;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if(num) {
            int absValue = abs(num);
            PQ.push({absValue, num});
        } else {
            if(PQ.empty()) {
                cout << 0 << '\n';
            } else {
                cout << PQ.top().value << '\n';
                PQ.pop();
            }
        }
        
    }
    return 0;
}