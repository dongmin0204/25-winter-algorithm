#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<pair<int, int>> stk;
    int arr[N];
    
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        
        
        while(!stk.empty() && num > stk.top().first){
            arr[stk.top().second] = num;
            stk.pop();
        }
        stk.push({num, i});
    }
    
    while (!stk.empty()){
        arr[stk.top().second] = -1;
        stk.pop();
    }
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    
    return 0;
}