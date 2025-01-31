#include <bits/stdc++.h>
using namespace std;



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<int,int>> s; //NGE(n),index
    vector<int> result(n);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        result[i] = -1;

        while(!s.empty() && temp > s.top().first){
            result[s.top().second] = temp;
            s.pop();
        }
        s.push(make_pair(temp,i));
    }

    for(int i = 0; i < n; i++){
        cout <<result[i] << ' ';
    }
    return 0;
}