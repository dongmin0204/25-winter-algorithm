#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; 
    cin >> N;
    priority_queue<int> PQ;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if(num) {
            PQ.push(num);
        } else {
            if(PQ.empty()) {
                cout << 0 << '\n';
            } else {
                cout << PQ.top() << '\n';
                PQ.pop();
            }
        }
        
    }
    return 0;
}