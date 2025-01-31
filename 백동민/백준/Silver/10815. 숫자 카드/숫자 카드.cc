#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >>n;
    vector<int> src(n);
    for(int i = 0; i < n; i++){
        cin >> src[i];   
    }
    sort(src.begin(),src.end());

    cin >> m;
    int input;
    for(int i =0; i < m; i++){
        cin >> input;
        if(binary_search(src.begin(),src.end(),input)){ //이진탐색
            cout << 1 << " ";
        }
        else{
            cout << 0 << " ";
        }
    }



    return 0;
}