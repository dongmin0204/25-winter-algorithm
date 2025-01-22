#include <bits/stdc++.h>
using namespace std;
int total = 0;

struct Data {
    int S;
    int T;
    
    bool operator<(const Data& other) const {
        if (S == other.S) {
            return T > other.T;
        }
        return S > other.S;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; 
    cin >> N;
    // vector<int> v;
    priority_queue<Data> PQ;
    
    for(int i = 0; i < N; i++) {
        int C, S, T;
        cin >> C >> S >> T;
        PQ.push({S, T});
    }
    
    priority_queue<int, vector<int>, greater<int>> MH;
    
    while (!PQ.empty()) {
        Data current = PQ.top();
        PQ.pop();
        
        if(!MH.empty() && MH.top() <= current.S) {
            MH.pop();
        }
        
        MH.push(current.T);
    }
    
    cout << MH.size();
    
    // while (!PQ.empty()) {
    //     Data current = PQ.top();
    //     PQ.pop();
    //     cout << current.S << " " << current.T << '\n';
    // }
    return 0;
}