#include <bits/stdc++.h>
using namespace std;

struct Data {
    int absValue;
    int value;
};

struct Compare {
    bool operator()(const Data& a, const Data& b) {
        if (a.absValue == b.absValue) {
            return a.value > b.value;
        }
        return a.absValue > b.absValue;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; 
    cin >> N;
    priority_queue<Data, vector<Data>, Compare> PQ;
    
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