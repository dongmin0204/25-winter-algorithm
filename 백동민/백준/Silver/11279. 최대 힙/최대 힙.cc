#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<unsigned int, vector<unsigned int>, less<unsigned int>> max_heap;

    for(int i = 0; i < n; i++){
        unsigned int temp;
        cin >> temp;
        if(temp != 0){
            max_heap.push(temp);
        }
        else if (!max_heap.empty()) {
            cout << max_heap.top() << "\n";
            max_heap.pop();
        }
        else{
            cout << "0\n";
        }
    }

    return 0;
}
